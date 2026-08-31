/*
** EPITECH PROJECT, 2024
** RT
** File description:
** main_test
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>
#include <thread>
#include "RaytracingFunctions.hpp"
#include "ParseConfig.hpp"
#include "Camera.hpp"
#include "IPrimitives.hpp"
#include "AllMaterials.hpp"
#include "IAllTypeLights.hpp"
#include "Vector3D.hpp"
#include "HandleColor.hpp"

void initializeRenderingContext(char **argv, const char* configFilePath, RayTracer::Camera& camera, RayTracer::Config& config)
{
    RayTracer::error_handling(2, argv);
    camera.getCam(configFilePath);
    config.set(configFilePath);
    config.getMaterials(configFilePath);
    config.getLights(configFilePath);
    config.setPrimitives();
    camera.setCamera();
    config.setLights();
    config.setMaterials();
}

std::pair<double, double> calculatePixelCoordinates(int x, int y, int width, int height)
{
    double u = (x + 1.0) / width;
    double v = (-y + 1.0) / height;

    return {u, v};
}

RayTracer::Color renderPixel(const RayTracer::Camera& cam, const RayTracer::Config& config, int x, int y)
{
    auto [u, v] = calculatePixelCoordinates(x, y, cam.screen_width, cam.screen_height);
    RayTracer::Ray ray = cam.getRay(u, v);
    int obj_number = distanceObj(ray, config.primitives);

    if (obj_number != -42) {
        Math::Vector3D position = ray.at(config.primitives[obj_number]->distance);
        Math::Vector3D normal = config.primitives[obj_number]->getNormalize(position);
        return RayTracer::Phong(*config.material[obj_number], ray.new_direction, normal, position, config.lights);
    }
    return RayTracer::Color(0, 0, 0);
}

void outputPixel(std::ofstream& output, const RayTracer::Color& color)
{
    RayTracer::Color outputColor = color;

    outputColor.toRGB();
    output << static_cast<uint8_t>(outputColor.r)
           << static_cast<uint8_t>(outputColor.g)
           << static_cast<uint8_t>(outputColor.b);
}

void writeOutput(std::ofstream& output, RayTracer::Camera& camera, const std::vector<RayTracer::Color>& pixels)
{
    output << "P6\n" << camera.screen_width << " " << camera.screen_height << "\n255\n";
    for (const auto& color : pixels) {
        output << static_cast<char>(std::min(255, static_cast<int>(color.r * 255)))
               << static_cast<char>(std::min(255, static_cast<int>(color.g * 255)))
               << static_cast<char>(std::min(255, static_cast<int>(color.b * 255)));
    }
}

static void renderPart(RayTracer::Camera& camera, RayTracer::Config& config, std::vector<RayTracer::Color>& pixels, int startRow, int endRow)
{
    for (int y = startRow; y < endRow; ++y) {
        for (int x = 0; x < camera.screen_width; ++x) {
            RayTracer::Color pixelColor = renderPixel(camera, config, x, y);
            pixels[y * camera.screen_width + x] = pixelColor;
        }
    }
}

void renderScene(RayTracer::Camera& camera, RayTracer::Config& config, std::ofstream& output) {
    std::vector<RayTracer::Color> pixels(camera.screen_width * camera.screen_height);
    int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    int rowsPerThread = camera.screen_height / numThreads;
    int startRow;
    int endRow;

    for (int i = 0; i < numThreads; ++i) {
        startRow = i * rowsPerThread;
        if (i + 1 == numThreads)
            endRow = camera.screen_height;
        else
            endRow = startRow + rowsPerThread;
        threads.emplace_back([=, &camera, &config, &pixels](){
            renderPart(camera, config, pixels, startRow, endRow);
        });
    }
    for (int i = 0; i < threads.size(); i++)
        threads[i].join();
    writeOutput(output, camera, pixels);
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <SCENE_FILE>" << std::endl;
        return 84;
    }
    RayTracer::Camera camera;
    RayTracer::Config config;
    std::string outputFile = "result/res_scene.ppm";
    initializeRenderingContext(argv, argv[1], camera, config);
    std::ofstream fout(outputFile, std::ios::binary);
    if (!fout.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 84;
    }
    renderScene(camera, config, fout);
    fout.close();
    return 0;
}
