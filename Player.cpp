#include "Player.h"


Player::Player(std::string rname, int rmaxHP = 100, int rforce = 5){

setName(rname);
setLevel(START_LEVEL);
setCoins(START_COINS);

if(rforce < 0){
    
    setForce(DEFAULT_FORCE);
}
else{
    
    setForce(rforce);
}
if(rmaxHP <= 0){

    setMaxHP(DEFAULT_HP);
    setHP(DEFAULT_HP);
}
else{

   setMaxHP(rmaxHP);
   setHP(rmaxHP);
}
}

Player::~Player(){}

Player::Player(const Player& copyPlayer){

    m_name = copyPlayer.m_name;
    m_level = copyPlayer.m_level;
    m_force = copyPlayer.m_force;
    m_maxHP = copyPlayer.m_maxHP;
    m_HP = copyPlayer.m_HP;
    m_coins = copyPlayer.m_coins;

}

void Player::printInfo() const{

printPlayerInfo(getName().c_str(), getLevel(), getForce(), getHP(), getCoins());

}

void Player::levelUp(){
 
 if(getLevel() < 10){
    
    setLevel(getLevel()+1);
 }
}


void Player::buff(int add){

    setForce(getForce()+add);
}

void Player::heal(int add){

    if(add > 0){

        if(getHP() + add <= getMaxHP()){

        setHP(getHP()+add);
        
        }
    }
}
void Player::damage(int less){
  
   if(less > 0){

        if(less > getMaxHP()){

            setHP(0);
        }
        else{
            
             setHP(getHP()-less);
        }
    }

}
bool Player::isKnockedOut() const{

    if(getHP() == 0){
       
       return true;
    }

    return false;
}

void Player::addCoins(int add){

   setCoins(getCoins()+add);

}

bool Player::pay(int credit){

    if(getCoins() - credit < 0){
        
        return false;
    }

    setCoins(getCoins()-credit);
    return true;
}

int Player::getAttackStrength() const{

return (getLevel() + getForce());

}

//set and get function

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