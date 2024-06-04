# N-Ty.pe Project

## Description

N-Type is a shoot'em up game inspired by the famous R-Type, but with a three-dimensional visual approach. The player controls a spaceship in a futuristic universe infested with extraterrestrial enemies. Although the game uses 3D graphics, the player's movement is limited to two dimensions, creating an immersive 2D platform experience.

## Conan & CMake Installation

Before starting the installation of the client part of N-Type, ensure that you have both Conan and CMake installed on your machine.

### Installing Conan

To install Conan, follow these steps:

1. **For Windows**:
   - Open a command prompt and run:
     ```bash
     pip install conan
     ```
   - If you do not have pip installed, you can get it by installing Python from [python.org](https://www.python.org/).

2. **For macOS and Linux**:
   - Open a terminal and run:
     ```bash
     pip install conan
     ```
   - If pip is not installed, you can typically install it with your system's package manager (like `apt` for Ubuntu or `brew` for macOS).

### Installing CMake

To install CMake, follow these steps:

1. **For Windows**:
   - Download the installer from the [CMake website](https://cmake.org/download/).
   - Run the installer and follow the on-screen instructions.

2. **For macOS**:
   - The easiest way is to use Homebrew. If you have Homebrew installed, just open a terminal and run:
     ```bash
     brew install cmake
     ```

3. **For Linux**:
   - Most Linux distributions have CMake in their repositories. You can install it using your package manager. For example, on Ubuntu, you would open a terminal and run:
     ```bash
     sudo apt-get install cmake
     ```

## Client Installation

The installation process for the client part of N-Type is streamlined through a script. Below are the detailed steps that the script follows. Note that script files are provided in the `scripts` folder to build the client side.

### Build with scripts

1. **Navigate to the Scripts Folder**: Start by navigating to the Scripts directory. This is where the build scripts are located.
    ```bash
    cd scripts
    ```

2. **Execute the Script**: The script will automate the entire build process.
    - **For Windows**:
      Open a command prompt and run:
      ```batch
      .\build_client_script.bat
      ```

    - **For Linux**:
      Open a terminal and run:
      ```bash
      ./build_client_script.sh
      ```

Make sure that the script files (`build_client_script.bat` for Windows and `build_client_script.sh` for Linux) are present in the `scripts` directory. Also, ensure that the scripts have the appropriate permissions to be executed, especially on Linux, where you might need to run `chmod +x build_client_script.sh` to make it executable.

### Detailed Installation Steps

1. **Navigate to the Client Folder**: Start by navigating to the Client directory.
    ```batch
    cd Client
    ```

2. **Optional: Detect and Update Conan Profile** (Only before the first build):
    This is an optional step, not included in the script, to be performed only once before the first build. It updates the Conan profile.
    ```bash
    conan profile detect --force
    ```
    *Note: If an error occurs in subsequent steps, it might be because the project compiles with C++14 instead of C++17. In this case, navigate to your user directory, find the `.conan2` folder, go to the `profiles` folder, open the `default` file, and change `compiler.cppstd=14` to `compiler.cppstd=17`*.

3. **Install Dependencies with Conan**: Dependencies are installed using Conan in the current directory (Client).
    ```batch
    conan install . --output-folder=build --build=missing
    ```

4. **Create and Navigate to the Build Directory**: A new build directory is created and then navigated into.
    ```batch
    cd build
    ```

5. **Compile the Project**: Finally, the project is compiled from the `Client/build` directory.
    ```batch
    cmake --build . --config Release
    ```

At the end of this process, if no errors occur, the build is considered complete. The script ensures that each step is carried out successfully before moving on to the next.

## Start Client

After successfully building the client part of the N-Type game, you can start the client application using the following steps:

### Starting the Client

Once the build process is complete, the executable for the N-Type client will be located in the `Client/build/Release` directory. To start the client, follow these instructions:

1. **Navigate to the Release Folder**:
   First, navigate to the `Release` directory within the `Client/build` directory.
    ```
    cd Client/build/Release
    ```

2. **Execute the Client Application**:
    - **For Windows**:
      Open a command prompt and run the following command to start the client:
      ```
      .\r-type_client.exe
      ```
    - **For Linux**:
      Open a terminal and run the following command to start the client and make it executable:
      ```
      chmod +x r-type_client
      ./r-type_client
      ```

## Server Installation

The installation process for the server part of N-Type is streamlined through a script. Below are the detailed steps that the script follows. Note that script files are provided in the `scripts` folder to build the server side.

### Build with scripts

1. **Navigate to the Scripts Folder**: Start by navigating to the Scripts directory. This is where the build scripts are located.
    ```bash
    cd scripts
    ```

2. **Execute the Script**: The script will automate the entire build process.
    - **For Windows**:
      Open a command prompt and run:
      ```batch
      .\build_server_script.bat
      ```

    - **For Linux**:
      Open a terminal and run:
      ```bash
      ./build_server_script.sh
      ```

Make sure that the script files (`build_server_script.bat` for Windows and `build_server_script.sh` for Linux) are present in the `scripts` directory. Also, ensure that the scripts have the appropriate permissions to be executed, especially on Linux, where you might need to run `chmod +x build_server_script.sh` to make it executable.

### Detailed Installation Steps

1. **Navigate to the Server Folder**: Start by navigating to the Server directory.
    ```batch
    cd Server
    ```

2. **Optional: Detect and Update Conan Profile** (Only before the first build):
    This is an optional step, not included in the script, to be performed only once before the first build. It updates the Conan profile.
    ```bash
    conan profile detect --force
    ```
    *Note: If an error occurs in subsequent steps, it might be because the project compiles with C++14 instead of C++17. In this case, navigate to your user directory, find the `.conan2` folder, go to the `profiles` folder, open the `default` file, and change `compiler.cppstd=14` to `compiler.cppstd=17`*.

3. **Install Dependencies with Conan**: Dependencies are installed using Conan in the current directory (Server).
    ```batch
    conan install . --output-folder=build --build=missing
    ```

4. **Create and Navigate to the Build Directory**: A new build directory is created and then navigated into.
    ```batch
    cd build
    ```

5. **Compile the Project**: Finally, the project is compiled from the `Server/build` directory.
    ```batch
    cmake --build . --config Release
    ```

At the end of this process, if no errors occur, the build is considered complete. The script ensures that each step is carried out successfully before moving on to the next.

## Start Server

After successfully building the server part of the N-Type game, you can start the server application using the following steps:

### Starting the Server

Once the build process is complete, the executable for the N-Type server will be located in the `Server/build/Release` directory. To start the server, follow these instructions:

1. **Navigate to the Release Folder**:
   First, navigate to the `Release` directory within the `Server/build` directory.
    ```
    cd Server/build/Release
    ```

2. **Execute the Server Application**:
    - **For Windows**:
      Open a command prompt and run the following command to start the server:
      ```
      .\r-type_server.exe
      ```
    - **For Linux**:
      Open a terminal and run the following command to start the server and make it executable:
      ```
      chmod +x r-type_server
      ./r-type_server
      ```