#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "Player.h"
#include "ComputerPlayer.h"

bool checkWin(const std::vector<std::vector<char>>& board, char symbol);

class Game {
public:
    Game();
    void play();

private:
    std::vector<std::vector<char>> board;
    Player humanPlayer;
    ComputerPlayer computerPlayer;
    bool isGameOver;

    void printBoard() const;
    bool checkTie() const;
    void playerMove();
    void computerMove();
};

#endif // GAME_H
