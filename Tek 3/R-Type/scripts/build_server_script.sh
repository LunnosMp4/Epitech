#!/bin/bash
echo "Script de build pour r-type_server"

# Naviguer dans le dossier Server
cd ..
cd Server
if [ $? -ne 0 ]; then
    echo "Error, end of build"
    exit 1
fi

# Suppression du dossier build si existant
if [ -d build ]; then
    echo "Suppression du dossier build existant..."
    rm -rf build
    if [ $? -ne 0 ]; then
        echo "Error, end of build"
        exit 1
    fi
fi

# Installation des dépendances avec Conan dans le dossier courant (Server)
echo "Installation des dependances dans le dossier Server..."
conan install . --output-folder=build --build=missing
if [ $? -ne 0 ]; then
    echo "Error, end of build"
    exit 1
fi

# Création et navigation dans le dossier build
if [ ! -d build ]; then
    mkdir build
fi
cd build
if [ $? -ne 0 ]; then
    echo "Error, end of build"
    exit 1
fi

# Exécution de CMake avec le fichier toolchain de Conan depuis Server/build
echo "Configuration de CMake depuis Server/build..."
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
if [ $? -ne 0 ]; then
    echo "Error, end of build"
    exit 1
fi

# Compilation du projet depuis Server/build
echo "Compilation du projet depuis Server/build..."
cmake --build . --config Release
if [ $? -ne 0 ]; then
    echo "Error, end of build"
    exit 1
fi

echo "Build done"
exit 0
