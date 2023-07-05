/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Snake.cpp
*/

#include "./Snake.hpp"

void Snake::init(IGraphical *graphics, std::string playerName) {
    _graphical = graphics;

    _playerName = playerName;
    loadHighScores();

    if (_firstStart)
        start();
}

void Snake::start() {
    srand(time(nullptr));

    s[0].x = 10;
    s[0].y = 10;

    generateFruit();
    _firstStart = false;
}

void Snake::update() {
    if (_state == GameState::RUNNING) {
        updateSnake();
        _currentScore = num - 4;

        if (checkCollision()) {
            _state = GameState::GAME_OVER;
            updateHighScore();
        }
    }
}

void Snake::handleInput(Input input) {
    if (input == Input::Z && dir != 2)
        dir = 0;
    if (input == Input::D && dir != 3)
        dir = 1;
    if (input == Input::S && dir != 0)
        dir = 2;
    if (input == Input::Q && dir != 1)
        dir = 3;
    if (input == Input::SPACE) {
        _state = GameState::RUNNING;
        _currentScore = 0;
        num = 4;
        dir = 1;
        for (int i = 1; i < num; i++) {
            s[i].x = 10;
            s[i].y = 10;
        }
        start();
    }
    if (input == Input::BACKSPACE)
        _state = GameState::GAME_OVER;
}

void Snake::render() {
    _graphical->drawRectangle(Vector2f(START_WIN_X - Size, START_WIN_Y - Size), Vector2f(WIN_X + Size + (Size * 2), WIN_X + Size + (Size * 2)), Color::WHITE);
    for (int i = 0; i < num; i++) {
        _graphical->drawRectangle(Vector2f(s[i].x * Size + START_WIN_X, s[i].y * Size + START_WIN_Y), Vector2f(20, 20), Color::GREEN);
        _graphical->drawRectangle(Vector2f(s[0].x * Size + START_WIN_X, s[0].y * Size + START_WIN_Y), Vector2f(20, 20), Color::BLUE);
    }

    _graphical->drawText(Vector2f(START_WIN_X + 500, START_WIN_Y + 100), "High Scores :", 16, Color::WHITE);
    int i = 0;
    for (auto& entry : _highScores) {
        _graphical->drawText(Vector2f(START_WIN_X + 500, START_WIN_Y + 150 + (i * 20)), entry.first + " : " + std::to_string(entry.second), 16, Color::WHITE);
        i++;
    }

    _graphical->drawText(Vector2f(START_WIN_X + 150, START_WIN_Y - 100), "Current Score : " + std::to_string(_currentScore), 18, Color::WHITE);
    _graphical->drawRectangle(Vector2f(f.x * Size + START_WIN_X, f.y * Size + START_WIN_Y), Vector2f(20, 20), Color::RED);
}

void Snake::generateFruit() {
    f.x = rand() % Size;
    f.y = rand() % Size;
}

void Snake::updateSnake() {
    for (int i = num - 1; i > 0; --i) {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }

    if (dir == 0) s[0].y -= 1;
    if (dir == 1) s[0].x += 1;
    if (dir == 2) s[0].y += 1;
    if (dir == 3) s[0].x -= 1;

    if ((s[0].x == f.x) && (s[0].y == f.y)) {
        num++;
        generateFruit();
    }
    delay(100);
}

bool Snake::checkCollision() {
    if (s[0].x > Size || s[0].x < 0 || s[0].y > Size || s[0].y < 0)
        return true;

    for (int i = 1; i < num; i++) {
        if (s[0].x == s[i].x && s[0].y == s[i].y) {
            return true;
        }
    }

    return false;
}

void Snake::delay(int milliseconds) {
    auto start_time = std::chrono::high_resolution_clock::now();

    while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start_time).count() < milliseconds) {}
}

////////// Leaderboard //////////

void Snake::saveHighScores() {
    std::ofstream file(SNAKE_HIGHSCORES_FILE);

    if (file.is_open()) {
        for (auto& entry : _highScores) {
            file << entry.first << " " << entry.second << std::endl;
        }

        file.close();
    }
}

void Snake::loadHighScores() {
    std::ifstream file(SNAKE_HIGHSCORES_FILE);

    if (file.is_open()) {
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
        saveHighScores();
    }

    if (_highScores.find(_playerName) != _highScores.end()) {
        _highScore = _highScores[_playerName];
    }
}

void Snake::updateHighScore() {
    if (_currentScore > _highScore) {
        _highScore = _currentScore;
        _highScores[_playerName] = _highScore;
        saveHighScores();
    }
}
