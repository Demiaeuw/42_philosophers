#!/bin/bash

# Chemin vers le répertoire du projet
PROJECT_DIR=$(pwd)

# Chemin vers le répertoire build
BUILD_DIR="$PROJECT_DIR/build"

# Si le répertoire build existe, le supprimer
if [ -d "$BUILD_DIR" ]; then
    echo -e "\nSuppression du répertoire build...\n"
    rm -rf "$BUILD_DIR"
fi

# Créer le répertoire build
echo -e "\nCréation du répertoire build...\n"
mkdir "$BUILD_DIR"

# Aller dans le répertoire build
cd "$BUILD_DIR"

# Configurer le projet avec CMake
echo -e "\nConfiguration du projet avec CMake...\n"
cmake ..

# Compiler le projet
echo -e "\nCompilation du projet...\n"
make

# Validation de la création de Build
echo -e "\nBuild terminé avec succès.\n"

# À la fin, rester dans le répertoire build
exec $SHELL
