#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(const std::string& name, char symbol);
    char getSymbol() const;
    std::string getName() const;
    std::pair<int, int> getMove() const;

private:
    std::string name;
    char symbol;
};

#endif // PLAYER_H
