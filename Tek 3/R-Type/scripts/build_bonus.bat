@echo off
echo Script de build pour f-plane-client

REM Naviguer dans le dossier Bonus
cd ..
cd Bonus
if %ERRORLEVEL% neq 0 (
    echo Error, end of build
    exit /b 1
)

REM Suppression du dossier build si existant
if exist build (
    echo Suppression du dossier build existant...
    rmdir /s /q build
    if %ERRORLEVEL% neq 0 (
        echo Error, end of build
        exit /b 1
    )
)

REM Installation des dépendances avec Conan dans le dossier courant (Bonus)
echo Installation des dependances dans le dossier Bonus...
conan install . --output-folder=build --build=missing
if %ERRORLEVEL% neq 0 (
    echo Error, end of build
    exit /b 1
)

REM Création et navigation dans le dossier build
if not exist build mkdir build
cd build
if %ERRORLEVEL% neq 0 (
    echo Error, end of build
    exit /b 1
)

REM Exécution de CMake avec le fichier toolchain de Conan depuis Bonus/build
echo Configuration de CMake depuis Bonus/build...
cmake .. -G "Visual Studio 17 2022" -A x64 -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
if %ERRORLEVEL% neq 0 (
    echo Error, end of build
    exit /b 1
)

REM Compilation du projet depuis Bonus/build
echo Compilation du projet depuis Bonus/build...
cmake --build . --config Release
if %ERRORLEVEL% neq 0 (
    echo Error, end of build
    exit /b 1
)

echo Build done
exit /b 0
