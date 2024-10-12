#include "Player.h"
#include <iostream>
Player::Player(const std::string& name, char symbol) : name(name), symbol(symbol) {}

char Player::getSymbol() const {
    return symbol;
}

std::string Player::getName() const {
    return name;
}

std::pair<int, int> Player::getMove() const {
    int row, col;
    std::cout << "Введите свой ход (строка и столбец): ";
    std::cin >> row >> col;
    return { row, col };
}
