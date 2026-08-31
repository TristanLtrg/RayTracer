# 👨🏻‍💻 Projet

☀️ **Raytracer** est un projet du module OOP (object oriented programming) de deuxième année dans lequel nous faisons un programme qui permet de générer des images digitales réalistes à l'aide de la simulation de la lumière sur des objets.

# 🔧 Usage

`./raytracer` + `.fichier de config`

# 📂 Documentation

[Créer un fichier de configuration](#⚙️-fichier-de-configuration) | [Ajouter une forme](#➕-ajouter-une-forme-au-projet)

---

## ⚙️ Fichier de Configuration :


_Comment créer un fichier de configuration ?_

[Camera](#camera) | [Primitives](#primitives) | [Materials](#materials) | [Lights](#lights)

---

### 🎥 Camera

La configuration de la caméra détermine où et comment vous visualisez la scène.

#### Paramètres possibles:

- **résolution:** définit la largeur et la hauteur de l'image en pixels.
- **position:** les coordonées (x, y, z) de la caméra dans l'espace.
- **rotation:** orientation de la caméra autour des axes x, y, z(en degrés).
- **fov:** champ de vision de la caméra en degrés (Field of View).


**Exemple:**
```cfg
camera : {
    resolution : { width : 1920; height : 1080; };
    position : { x : 0.0; y : 0.0; z : 0.0; };
    rotation : { x : 0.0; y : 0.0; z : 0.0; };
    fov : 70.0;
};
```

---

### 📐 Primitives

Définissez les objets de votre scène en utilisant différentes formes géométriques.

#### Types de formes

1. **Spheres**
    - **x, y, z:** Position de la sphere.
    - **r:** Rayon de la sphere.
2. **Cylinders**
    - **x, y, z:** Position de la base du cylindre.
    - **r:** Rayon du cylindre.
    - **h:** hauteur du cylindre.
3. **Cone**
    - **x, y, z:** Position de la base du cone.
    - **r:** Rayon du cone.
    - **h:** hauteur du cone.
4. **Hourglass ou sablier**
    - **x, y, z:** Position de la base du sablier.
    - **r:** Rayon du sablier.
    - **h:** hauteur du sablier.

**Exemple:**
```cfg
primitives : {
    spheres : (
        { x = 150.0; y = -75.0; z = 40.0; r = 25.0; }
    );
    cylinders : (
        { x = -50.0; y = 50.0; z = 75.0; r = 10.0; h = 50.0; }
    );
};
```

---

### 🧱 Materials

Chaque forme doit avoir un matériau qui définit comment elle interagit avec la lumière.

#### Paramètres possibles:

- **ambient:** Intensité de la lumière ambiante.
- **diffuse_light:** Intensité de la lumière diffuse.
- **speculare_light:** Intensité de la lumière spéculaire.
- **shiny:** Niveau de brillance.
- **color:** Couleur de l'objet en RGB. (RVB en français)

**Exemple:**
```cfg
materials : {
    objects : (
        { ambient : 0.5; diffuse_light : 0.7; specular_light : 0.5; shiny : 0.5; color = { r = 255; g = 255; b = 255; }; }
    );
};
```

---

### 💡 Lights

Configurez différentes sources de lumière pour éclairer votre scène.

#### Types de lumières:

1. **Point Lights:**
    - **position:** Emplacement de la source lumineuse.
    - **Color:** Couleur de la lumière.
2. **Directional Lights:**
    - **new_direction:** Direction de la lumière.
    - **color:** Couleur de la lumière émise.
    - **intensity:** Intensité de la lumière.
3. **Ambient Lights:**
    - **color:** Couleur de la lumière ambiante qui affecte l'ensemble de la scène.

**Exemple:**
```cfg
lights : {
    point_lights : (
        { position : { x = 0.0; y = 100.0; z = 100.0; }; Color = { r = 255; g = 255; b = 255; }; }
    );
    directional_lights : (
        { new_direction : { x = 0.5; y = -0.4; z = 0.6; }; color = { r = 255; g = 215; b = 0; }; intensity = 0.8 }
    );
    ambient_lights : (
        { color = { r = 250; g = 250; b = 250; }; }
    );
};
```

---

## ➕ Ajouter une forme au projet :

Lors de l'ajout d'une nouvelle forme plusieurs fichiers sont à modifier:

1. **Ajouter la structure de la forme et un vector de cette structure dans: ParseConfig.hpp**

    _l'ajout du vector de la structure sert au fait qu'on peut avoir plusieurs fois la même forme_

    **Exemple:**

    ```h
    struct Cylinder_t {
                    Math::Vector3D cylinder_pos;
                    double radius;
                    double height;
                };
                std::vector<Cylinder_t> cylinders;
    ```

2. **Ajouter le fichier .hpp dans include/ et .cpp dans /src/objet**

3. **Ajouter le parsing et le set(dans la fonction setPrimitives) de votre object dans: src/object/ParsePrimitives.cpp**

    **Exemple:**
    ```cpp
    //Parsing

    void Config::parsespheres(const std::string& file)
        {
            libconfig::Config cfg;
            cfg.readFile(file.c_str());
            const libconfig::Setting& primitives = cfg.lookup("primitives");

            try {
                const libconfig::Setting& spheresSetting = primitives.lookup("spheres");
                for (int i = 0; i < spheresSetting.getLength(); i++) {
                    const libconfig::Setting& sphereSetting = spheresSetting[i];
                    Sphere_t newSphere;
                    newSphere.sphere_pos.x = sphereSetting.lookup("x");
                    newSphere.sphere_pos.y = sphereSetting.lookup("y");
                    newSphere.sphere_pos.z = sphereSetting.lookup("z");
                    newSphere.radius = sphereSetting.lookup("r");
                    spheres.push_back(newSphere);
                }
            } catch (const libconfig::SettingNotFoundException&) {
            }
        }

    //Set

    for (const auto& sphere : spheres) {
        auto s = std::make_shared<Sphere>(sphere.sphere_pos, sphere.radius);
        primitives.push_back(s);
    }

    ```

4. **Ajouter le prototype de votre fonction de parsing dans le fichier: ParseConfig.hpp**

    **Exemple:**
    ```h
    void parsespheres(const std::string& file);
    ```


# 🫂 Groupe "ukudansa kwemoto"

- **Tristan Darodes de Tailly** - tristan.darodes-de-tailly@epitech.eu | [LinkedIn](https://www.linkedin.com/in/tristan-darodes-de-tailly-677aa0239/)
- **Tristan Leturgie** - tristan.leturgie@epitech.eu | [LinkedIn](https://www.linkedin.com/in/tristanleturgie/)
- **Come Le Masne De Chermont** - come.le-masne-de-chermont@epitech.eu | [LinkedIn](https://www.linkedin.com/in/come-le-masne-de-chermont/)
- **Stanislas Vaudois** - stanislas.vaudois@epitech.eu | [LinkedIn](https://www.linkedin.com/in/stanislas-vaudois/)
