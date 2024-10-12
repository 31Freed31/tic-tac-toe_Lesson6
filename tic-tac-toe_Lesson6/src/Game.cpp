#include "Game.h"
#include <iostream>

Game::Game() : humanPlayer("Player", 'X'), computerPlayer('O'), isGameOver(false) {
    board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
}

void Game::play() {
    while (!isGameOver) {
        printBoard();
        playerMove();
        if (checkWin(board, humanPlayer.getSymbol())) {
            printBoard();
            std::cout << humanPlayer.getName() << " выиграл!\n";
            isGameOver = true;
            return;
        }
        if (checkTie()) {
            printBoard();
            std::cout << "Ничья!\n";
            isGameOver = true;
            return;
        }

        computerMove();
        if (checkWin(board, computerPlayer.getSymbol())) {
            printBoard();
            std::cout << "Компьютер выиграл!\n";
            isGameOver = true;
            return;
        }
        if (checkTie()) {
            printBoard();
            std::cout << "Ничья!\n";
            isGameOver = true;
        }
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char symbol) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) return true;
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) return true;
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return true;

    return false;
}

void Game::printBoard() const {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}

bool Game::checkTie() const {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

void Game::playerMove() {
    int row, col;
    do {
        std::cout << "Введите свой ход (строка и столбец): ";
        std::cin >> row >> col;
    } while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ');

    board[row][col] = humanPlayer.getSymbol();
}

void Game::computerMove() {
    std::pair<int, int> move = computerPlayer.makeMove(board);
    int row = move.first;
    int col = move.second;
    board[row][col] = computerPlayer.getSymbol();
    std::cout << "Компьютер сделал ход: " << row << ", " << col << std::endl;
}
