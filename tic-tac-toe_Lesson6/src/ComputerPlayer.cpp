#include "ComputerPlayer.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>

ComputerPlayer::ComputerPlayer(char symbol) : Player("Computer", symbol) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

std::pair<int, int> ComputerPlayer::makeMove(const std::vector<std::vector<char>>& board) {
    auto winMove = findWinningMove(board, getSymbol());
    if (winMove.first != -1) return winMove;

    auto blockMove = findWinningMove(board, 'X');
    if (blockMove.first != -1) return blockMove;

    int row, col;
    do {
        row = std::rand() % 3;
        col = std::rand() % 3;
    } while (board[row][col] != ' ');

    return { row, col };
}

std::pair<int, int> ComputerPlayer::findWinningMove(const std::vector<std::vector<char>>& board, char symbol) const {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == ' ') {
                auto tempBoard = board;
                tempBoard[row][col] = symbol;
                if (checkWin(tempBoard, symbol)) {
                    return { row, col };
                }
            }
        }
    }
    return { -1, -1 };
}
