
#ifndef EX2_Player_H
#define EX2_Player_H

#include <string>
#include <iostream>
#include "Player.h"
#include "utilities.h"
#define START_LEVEL 1
#define START_COINS 0
#define DEFAULT_FORCE 5
#define DEFAULT_HP 100

//enum class Player {Battle, Buff, Heal, Treasure}; 

class Player {

private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;


public:
    Player(std::string playerName, int PlayerMaxHP = DEFAULT_HP, int PlayerForce = DEFAULT_FORCE);
    ~Player() = default;
    Player& operator=(const Player& other) = default;
    Player(const Player&) = default; 
    void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int add);
    void heal(int add);
    void damage(int less);
    bool isKnockedOut() const;
    void addCoins(int add);
    bool pay(int credit);
    int getAttackStrength()const;
    std::string  getName() const;
    int getForce() const;
    int getMaxHP() const;
    int getHP() const;
    int getCoins() const;
    void setName(std::string newName);
    void setLevel(int newLevel);
    void setForce(int newForce);
    void setMaxHP(int newMaxHP);
    void setHP(int newHP);
    void setCoins(int newCoins);

};

#endif //EX2_Player_H