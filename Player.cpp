#include "Player.h"


Player::Player(std::string playerName, int playerMaxHP, int playerForce){

    setName(playerName);

    setLevel(START_LEVEL);
    setCoins(START_COINS);

    if(playerForce <= 0){
    
        setForce(DEFAULT_FORCE); // maybe playerForce < 0
    }
    else{
    
        setForce(playerForce);
    }

    if(playerMaxHP <= 0){

        setMaxHP(DEFAULT_HP);
        setHP(DEFAULT_HP);
    }
    else{

        setMaxHP(playerMaxHP);
        setHP(playerMaxHP);
    }
}

void Player::printInfo() const{

    printPlayerInfo(getName().c_str(), getLevel(), getForce(), getHP(), getCoins());

}

void Player::levelUp(){

    // if the player is not in the max level, he can level up one level

    int level = this->getLevel();
    
    if (level < 10){
    
        this->setLevel(level+1);
    }

}

void Player::buff(int force){

    this->setForce(getForce()+force);
}

void Player::heal(int heal){

    // if the player can heal, heal him

    if (heal > 0){

        if (this->getHP() + heal <= getMaxHP()){

            setHP(this->getHP() + heal);
        
        }
    }
}

void Player::damage(int damage){

    // if the player can get damage, damage him
  
    if (damage > 0){

        if (damage >= this->getHP()){

            setHP(0);
        }
        else{
            
            setHP(this->getHP() - damage);
        }
    }

}

bool Player::isKnockedOut() const{ // if the player is knocked out, return true


    if(this->getHP() <= 0){
       
       return true;
    }

    return false;
}

void Player::addCoins(int coins){

    // if the player get coins, add them to his coins

    if (coins > 0){

        this->setCoins(this->getCoins()+coins);

    }

}

bool Player::pay(int payment){

    // if the player can pay, pay the payment and return true, else return false

    if((this->getCoins() - payment) < 0){
        
        return false;
    }

    setCoins((this->getCoins() - payment));

    return true;
}

int Player::getAttackStrength() const{

    // return the attack strength of the player
    return (this->getLevel() + this->getForce());

}

//set and get functions

std::string  Player::getName() const{

    return m_name;
}

int Player::getLevel() const{

    return m_level;
}

int Player::getForce() const{

    return m_force;
}

int Player::getMaxHP() const{

    return m_maxHP;
}

int Player::getHP() const{

    return m_HP;
}

int Player::getCoins() const{

    return m_coins;
}

void Player::setName(std::string newName){

    m_name = newName;
}

void Player::setLevel(int newLevel){

    m_level = newLevel;
}

void Player::setForce(int newForce){

    m_force = newForce;
}

void Player::setMaxHP(int newMaxHP){

    m_maxHP = newMaxHP;
}

void Player::setHP(int newHP){

    m_HP = newHP;
}

void Player::setCoins(int newCoins){

    m_coins = newCoins;
}