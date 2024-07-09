#!/bin/bash

# Chemin vers le répertoire du projet
PROJECT_DIR=$(pwd)

# Chemin vers le répertoire build
BUILD_DIR="$PROJECT_DIR/build"

# Si le répertoire build existe, le supprimer
if [ -d "$BUILD_DIR" ]; then
    echo -e "\nSuppression du répertoire build...\n"
    rm -rf "$BUILD_DIR"
    echo -e "\nLe répertoire build a été supprimé.\n"
else
    echo -e "\nLe répertoire build n'existe pas.\n"
fi
