#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include <vector>

class ComputerPlayer : public Player {
public:
    ComputerPlayer(char symbol);
    std::pair<int, int> makeMove(const std::vector<std::vector<char>>& board);

private:
    std::pair<int, int> findWinningMove(const std::vector<std::vector<char>>& board, char symbol) const;
};

#endif // COMPUTERPLAYER_H
