/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Pacman.cpp
*/

#include "./Nibbler.hpp"

void Nibbler::init(IGraphical *graphics, std::string playerName) {
    _graphical = graphics;

    _playerName = playerName;
    loadHighScores();

    if (_firstStart)
        start();
}

void Nibbler::start() {
    srand(time(nullptr));
    map = readMapNibbler(MAP_1);

    s[0].x = 10;
    s[0].y = 10;

    generateFruit();
    _level = 0;
    _firstStart = false;
}

void Nibbler::respawnSnake() {
    num = 4;
    s[0].x = 10;
    s[0].y = 10;
    dir = 0;
    for (int i = 1; i < num; i++) {
        s[i].x = 10;
        s[i].y = 11;
    }
}

void Nibbler::update() {
    if (_state == GameState::RUNNING) {
        _currentScore = _level;

        if (checkCollision()) {
            _state = GameState::GAME_OVER;
            updateHighScore();
            return;
        }
        updateNibbler();
    }
}

void Nibbler::handleInput(Input input) {
    if (input == Input::Z && dir != 2 && map[s[0].y - 1][s[0].x] != WALL)
        dir = 0;
    if (input == Input::D && dir != 3 && map[s[0].y][s[0].x + 1] != WALL)
        dir = 1;
    if (input == Input::S && dir != 0 && map[s[0].y + 1][s[0].x] != WALL)
        dir = 2;
    if (input == Input::Q && dir != 1 && map[s[0].y][s[0].x - 1] != WALL)
        dir = 3;
    if (input == Input::SPACE) {
        _state = GameState::RUNNING;
        _currentScore = 0;
        num = 4;
        respawnSnake();
        start();
    }
    if (input == Input::BACKSPACE)
        _state = GameState::GAME_OVER;
}

std::vector<std::vector<char>> Nibbler::readMapNibbler(std::string fileName) {
    std::ifstream file(fileName);
    std::vector<std::vector<char>> map;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        map.push_back(row);
    }

    return map;
}

void Nibbler::render() {
    int Mx = 0;
    int My = 0;
    int i = 0;
    for (auto& row : map) {
        for (auto& c : row) {
            if (c == WALL) {
                _graphical->drawRectangle(Vector2f(START_WIN_X + Mx, START_WIN_Y + My), Vector2f(Size, Size), Color::WHITE);
            }
            if (c == EMPTY) {
                _graphical->drawRectangle(Vector2f(START_WIN_X + Mx, START_WIN_Y + My), Vector2f(Size, Size), Color::BLACK);
            }
            Mx += Size;
        }
        Mx = 0;
        My += Size;
    }

    for (int i = 0; i < num; i++) {
        _graphical->drawRectangle(Vector2f(s[i].x * Size + START_WIN_X, s[i].y * Size + START_WIN_Y), Vector2f(20, 20), Color::RED);
        _graphical->drawRectangle(Vector2f(s[0].x * Size + START_WIN_X, s[0].y * Size + START_WIN_Y), Vector2f(20, 20), Color::BLUE);
    }

    _graphical->drawText(Vector2f(START_WIN_X + 500, START_WIN_Y + 100), "High Scores :", 14, Color::WHITE);
    for (auto& entry : _highScores) {
        _graphical->drawText(Vector2f(START_WIN_X + 500, START_WIN_Y + 150 + (i * 20)), entry.first + " : " + std::to_string(entry.second), 14, Color::WHITE);
        i++;
    }

    _graphical->drawText(Vector2f(START_WIN_X + 150, START_WIN_Y - 100), "Current Score : " + std::to_string(_currentScore), 18, Color::WHITE);
    for (int i = 0; i < _nbFruit; i++)
        _graphical->drawRectangle(Vector2f(f[i].x * Size + START_WIN_X, f[i].y * Size + START_WIN_Y), Vector2f(20, 20), Color::MAGENTA);
    _graphical->drawRectangle(Vector2f(START_WIN_X, START_WIN_Y), Vector2f(20, 20), Color::WHITE);

    if (_state == GameState::WIN) {
        _graphical->drawText(Vector2f(START_WIN_X + 170, START_WIN_Y + 480), "You Win !", 20, Color::WHITE);
        _graphical->drawText(Vector2f(START_WIN_X + 70, START_WIN_Y + 510), "Press Backspace to go back to menu", 16, Color::WHITE);
    }
}

void Nibbler::generateFruit() {
    std::srand(std::time(nullptr));
    int numFruit = _nbFruit;
    int rows = map.size();
    int cols = map[0].size();

    while (numFruit > 0) {
        int row = std::rand() % rows;
        int col = std::rand() % cols;
        if (map[row][col] == EMPTY) {
            f[numFruit].x = col;
            f[numFruit].y = row;
            numFruit--;
        }
    }
}

void Nibbler::changeMap() {
    if (_level == 0) {
        map.clear();
        map = readMapNibbler(MAP_2);
        generateFruit();
        _level = 1;
        respawnSnake();
    } else if (_level == 1) {
        map.clear();
        map = readMapNibbler(MAP_3);
        generateFruit();
        _level = 2;
        respawnSnake();
    } else if (_level == 2) {
        _state = GameState::WIN;
    }
}

void Nibbler::updateNibbler() {
    for (int i = num - 1; i > 0; --i) {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }

    if (dir == 0) s[0].y -= 1;
    if (dir == 1) s[0].x += 1;
    if (dir == 2) s[0].y += 1;
    if (dir == 3) s[0].x -= 1;

    for (int i = 0; i < _nbFruit; i++) {
        if ((s[0].x == f[i].x) && (s[0].y == f[i].y)) {
            f[i].x = -100;
            f[i].y = -100;
            num++;
        }
    }
    delay(150);

    for (int i = 1; i < _nbFruit; i++) {
        if (f[i].x != -100 && f[i].y != -100) {
            return;
        }
    }

    changeMap();
}

bool Nibbler::checkCollision() {
    if (s[0].x > Size + 1 || s[0].x < 0 || s[0].y > Size + 1 || s[0].y < 0) {
        s[0].x = 10;
        s[0].y = 10;
        dir = 0;
        for (int i = 1; i < num; i++) {
            s[i].x = 10;
            s[i].y = 11;
        }
    }


    for (int i = 1; i < num; i++) {
        if (s[0].x == s[i].x && s[0].y == s[i].y) {
            return true;
        }
    }

    // Coming from the left
    if (map[s[0].y][s[0].x + 1] == WALL && dir == 1) {
        if (map[s[0].y - 1][s[0].x] == WALL)
            dir = 2;
        else
            dir = 0;
        updateNibbler();
    }

    // Coming from the right
    if (map[s[0].y][s[0].x - 1] == WALL && dir == 3) {
        if (map[s[0].y + 1][s[0].x] == WALL)
            dir = 0;
        else
            dir = 2;
        updateNibbler();
    }

    // Coming from the top
    if (map[s[0].y + 1][s[0].x] == WALL && dir == 2) {
        if (map[s[0].y][s[0].x - 1] == WALL)
            dir = 1;
        else
            dir = 3;
        updateNibbler();
    }

    // Coming from the bottom
    if (map[s[0].y - 1][s[0].x] == WALL && dir == 0) {
        if (map[s[0].y][s[0].x + 1] == WALL)
            dir = 3;
        else
            dir = 1;
        updateNibbler();
    }

    return false;
}

////////// Leaderboard //////////

void Nibbler::saveHighScores() {
    std::ofstream file(NIBBLER_HIGHSCORES_FILE);

    if (file.is_open()) {
        // Write the high scores to the file
        for (auto& entry : _highScores) {
            file << entry.first << " " << entry.second << std::endl;
        }

        file.close();
    }
}

void Nibbler::loadHighScores() {
    std::ifstream file(NIBBLER_HIGHSCORES_FILE);

    if (file.is_open()) {
        // Read the high scores from the file
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string playerName;
            unsigned int highScore;
            ss >> playerName >> highScore;
            _highScores[playerName] = highScore;
        }

        file.close();
    }
    else {
        // If the file does not exist, create it with empty high scores
        saveHighScores();
    }

    // Load the high score for the current player
    if (_highScores.find(_playerName) != _highScores.end()) {
        _highScore = _highScores[_playerName];
    }
}

void Nibbler::updateHighScore() {
    // Update the high score for the current player
    if (_currentScore > _highScore) {
        _highScore = _currentScore;
        _highScores[_playerName] = _highScore;
        saveHighScores();
    }
}

void Nibbler::delay(int milliseconds) {
    auto start_time = std::chrono::high_resolution_clock::now();

    while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start_time).count() < milliseconds) {}
}
