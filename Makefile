##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC = g++

CPPFLAGS = -std=c++20 -Iinclude -lm

LDFLAGS = -lconfig++

SRC = src/main.cpp 					\
	src/HandleColor.cpp 			\
	src/parsing/ParseLights.cpp 	\
	src/parsing/ParseMaterials.cpp 	\
	src/parsing/ParsePrimitives.cpp \
	src/AllMaterials.cpp 			\
	src/Vector3D.cpp 				\
	src/camera/Screen.cpp 			\
	src/camera/Camera.cpp 			\
	src/lights/Diffuse.cpp 			\
	src/lights/DirecLight.cpp 		\
	src/lights/PLight.cpp 			\
	src/lights/Ambient.cpp 			\
	src/object/Cylinder.cpp 		\
	src/object/Sphere.cpp 			\
	src/object/Cone.cpp             \
	src/object/Hourglass.cpp		\
	src/object/Plane.cpp		\
	src/object/Triangle.cpp

OBJ = $(SRC:.cpp=.o)

NAME = raytracer

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all