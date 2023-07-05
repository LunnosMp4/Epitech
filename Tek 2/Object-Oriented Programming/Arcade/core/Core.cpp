/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"

using namespace Arcade;

/**
 * @brief Init Core of the Arcade
 *
 * @param libPath Default library path to use
 */
Core::Core(const std::string &libPath) {

    std::cout << "Enter your name: ";
    std::cin >> _playerName;
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid name" << std::endl;
        exit(84);
    }

    _handle_game = nullptr;
    _handle_graphical = nullptr;
    _dl = DLLoader();

    LibList libList;
    for (auto &it : libList.graphics) {
        if (it == libPath) {
            displayMenu(libPath);
        }
    }
    std::cerr << "Error: Invalid library - Please use a graphical library" << std::endl;
    exit(84);
}

/**
 * @brief Destroy the Core object
 *
 */
Core::~Core() {
    if (_handle_game)
        _dl.closeLib(_handle_game);
    if (_handle_graphical)
        _dl.closeLib(_handle_graphical);
}

/**
 * @brief Set the Game Lib object
 *
 * @param gamePath Path to the game library
 */
void Core::setGameLib(const std::string &gamePath) {
    _handle_game = _dl.loadLib(gamePath);
    _game = _dl.getSymbol<IGame>(_handle_game, "entryPoint");
}

/**
 * @brief Set the Graphical Lib object
 *
 * @param graphicalPath Path to the graphical library
 */
void Core::setGraphicalLib(const std::string &graphicalPath) {
    _handle_graphical = _dl.loadLib(graphicalPath);
    _graphical = _dl.getSymbol<IGraphical>(_handle_graphical, "entryPoint");
}

/**
 * @brief Load dynamic libraries and display the menu
 *
 * @param path Path to the library
 */
void *DLLoader::loadLib(const std::string &path) {
    auto it = _loaded_libs.find(path);
    if (it != _loaded_libs.end()) {
        return it->second;
    }
    void* handle = dlopen(path.c_str(), RTLD_LAZY);
    try {
        if (handle == nullptr)
            throw DLErrorException();
    } catch (DLErrorException &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    _loaded_libs[path] = handle;
    return handle;
}

/**
 * @brief Close the library
 *
 * @param handle Handle to the library
 */
void DLLoader::closeLib(void *handle) {
    try {
        if (handle == nullptr)
            throw DLErrorException();
        if (dlclose(handle) != 0)
            throw DLErrorException();
    } catch (DLErrorException &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

template<typename Type>
/**
 * @brief Get the Symbol object (function)
 *
 * @param handle Handle to the library
 * @param sym Symbol to get (function)
 * @return Type*
 */
Type *DLLoader::getSymbol(void *handle, const std::string &sym) {
    Type * (*entry)();
    entry = reinterpret_cast<Type  *(*)()>(dlsym(handle, sym.c_str()));
    Type *symPtr = entry();
    try {
        if (symPtr == nullptr)
            throw DLErrorException();
    } catch (DLErrorException &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    return symPtr;
}

/**
 * @brief Find all the libraries in the lib folder
 *
 * @param games Vector of games
 * @param graphics Vector of graphical libraries
 */
void Core::findLibs(std::vector<std::string> &games, std::vector<std::string> &graphics) {
    std::filesystem::path path = "lib/";
    LibList libList;

    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        std::string filePath = entry.path().string();
        if (std::find(libList.games.begin(), libList.games.end(), filePath) != libList.games.end())
            games.push_back(filePath);
        else if (std::find(libList.graphics.begin(), libList.graphics.end(), filePath) != libList.graphics.end())
            graphics.push_back(filePath);
    }
}


/**
 * @brief Launch the game selected
 *
 * @param isGame Is the player in the game selection
 * @param games Vector of games
 * @param graphics Vector of graphical libraries
 */
void Core::launchGame(bool isGame, std::vector<std::string> games, std::vector<std::string> graphics) {
    if (isGame && !_isInGame) {
        setGameLib(games[_selectedGameIndex]);
        isGame = false;
        _isInGame = true;
        _game->setState(GameState::RUNNING);
        _game->init(_graphical, _playerName);
        _gameStarted = true;
    } else {
        _graphical->destroyWindow();
        setGraphicalLib(graphics[_selectedGraphicsIndex]);
        _graphical->createWindow(WIDTH, HEIGHT, TITLE);
        if (_gameStarted)
            _game->init(_graphical, _playerName);
    }
}

/**
 * @brief Switch between the graphical libraries
 *
 * @param graphics Vector of graphical libraries
 * @param Direction Direction of the switch (Previous or next)
 */
void Core::switchLibs(std::vector<std::string> graphics, bool Direction) {
    _graphical->destroyWindow();
    if (Direction)
        _selectedGraphicsIndex = (_selectedGraphicsIndex + 1) % graphics.size();
    else
        _selectedGraphicsIndex = (_selectedGraphicsIndex + graphics.size() - 1) % graphics.size();
    setGraphicalLib(graphics[_selectedGraphicsIndex]);
    _graphical->createWindow(WIDTH, HEIGHT, TITLE);
    _game->init(_graphical, _playerName);
}


/**
 * @brief Get Inout of player for the Menu
 *
 * @param games Vector of games
 * @param graphics Vector of graphical libraries
 * @param isGame Is the player in the game selection
 */
Input Core::getInputs(std::vector<std::string> games, std::vector<std::string> graphics, bool &isGame) {
    Input input = _graphical->getInput();

    if (input == Input::ESCAPE) {
        _graphical->destroyWindow();
        exit(0);
    }

    if (input == Input::UP && isGame)
        _selectedGameIndex = (_selectedGameIndex + 1) % games.size();
    else if (input == Input::DOWN && isGame)
        _selectedGameIndex = (_selectedGameIndex + games.size() - 1) % games.size();
    else if (input == Input::UP && !isGame)
        _selectedGraphicsIndex = (_selectedGraphicsIndex + graphics.size() - 1) % graphics.size();
    else if (input == Input::DOWN && !isGame)
        _selectedGraphicsIndex = (_selectedGraphicsIndex + 1) % graphics.size();
    else if (input == Input::LEFT)
        isGame = !isGame;
    else if (input == Input::RIGHT)
        isGame = !isGame;
    else if (input == Input::ENTER)
        launchGame(isGame, games, graphics);
    else if (input == Input::A && _gameStarted)
        switchLibs(graphics, false);
    else if (input == Input::E && _gameStarted)
        switchLibs(graphics, true);

    return input;
}

/**
 * @brief Draw the Text Menu
 *
 * @param games Vector of games
 * @param graphics Vector of graphical libraries
 * @param isGame Is the player in the game selection
 */
void Core::drawTextMenu(std::vector<std::string> games, std::vector<std::string> graphics, bool isGame) {
    /* Games Categorie */
    if (!_isInGame && !_gameStarted) {
        _graphical->drawText(Vector2f(X_MIDDLE, Y_MIDDLE - 20), "Games:", 16, Color::WHITE);
        for (std::size_t i = 0; i < games.size(); i++) {
            if ((int) i == _selectedGameIndex)
                _graphical->drawText(Vector2f(X_MIDDLE, Y_MIDDLE + ((i * 20) + 20)), games[i], 16, Color::CYAN);
            else
                _graphical->drawText(Vector2f(X_MIDDLE, Y_MIDDLE + ((i * 20) + 20)), games[i], 16, Color::WHITE);
        }
    }

    /* User */
    _graphical->drawText(Vector2f(30, 30), "Logged as: " + _playerName, 16, Color::WHITE);

    /* Graphical Categorie */
    _graphical->drawText(Vector2f(30, Y_MIDDLE - 20), "Graphics:", 16, Color::WHITE);
    for (std::size_t i = 0; i < graphics.size(); i++) {
        if ((int) i == _selectedGraphicsIndex)
            _graphical->drawText(Vector2f(30, Y_MIDDLE + ((i * 20) + 20)), graphics[i], 16, Color::CYAN);
        else
            _graphical->drawText(Vector2f(30, Y_MIDDLE + ((i * 20) + 20)), graphics[i], 16, Color::WHITE);
    }

    /* LibSelected */
    if (isGame && !_isInGame)
        _graphical->drawText(Vector2f(X_MIDDLE - 20, Y_MIDDLE + ((_selectedGameIndex * 20) + 20)), ">", 16, Color::WHITE);
    else
        _graphical->drawText(Vector2f(30 - 20, Y_MIDDLE + ((_selectedGraphicsIndex * 20) + 20)), ">", 16, Color::WHITE);
}

/**
 * @brief Call IGame functions to handle the game
 *
 * @param input Input of the player
 */
void Core::gameLoop(Input input) {
    if (_game != nullptr && _gameStarted) {
        _game->handleInput(input);
        _game->update();
        _game->render();
        if (_game->getState() == GameState::GAME_OVER) {
            _isInGame = false;
            _gameStarted = false;
        }
    }
}

/**
 * @brief Display the Menu
 *
 * @param libPath Path of the graphical library
 */
void Core::displayMenu(const std::string libPath) {

    std::vector<std::string> games;
    std::vector<std::string> graphics;
    bool isGame = true;

    findLibs(games, graphics);
    setGraphicalLib(libPath);
    _graphical->createWindow(WIDTH, HEIGHT, TITLE);
    while (_graphical->isOpen()) {
        _graphical->clear();
        _graphical->drawRectangle(Vector2f(-50, -50), Vector2f(WIDTH + 100, HEIGHT + 100), Color::TRANSPARENT);
        _graphical->drawSprite(Vector2f(-50, 0), BACKGROUND_PATH);
        Input input = getInputs(games, graphics, isGame);
        drawTextMenu(games, graphics, isGame);
        gameLoop(input);
        _graphical->display();
    }
}
