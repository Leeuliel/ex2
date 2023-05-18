#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards): m_player(playerName,DEFAULT_HP,DEFAULT_FORCE){
  
    m_gameStatus = GameStatus::MidGame;
    m_size = numOfCards;
    m_cards = new Card[m_size];
    for (int i = 0; i < m_size; i++){

        m_cards[i] = cardsArray[i];
    
    }
    m_currentCard = 0;
}

Mtmchkin::~Mtmchkin(){

    delete[]  m_cards;

}

Mtmchkin::Mtmchkin(const Mtmchkin& copyMtmchkin): 
m_player(copyMtmchkin.m_player), m_cards(new Card[copyMtmchkin.m_size])
{
    setGameStatus(copyMtmchkin.m_gameStatus);
    setNumCard(copyMtmchkin.m_size);
    setCurrentCard(copyMtmchkin.m_currentCard);
    for(int i = 0; i < m_size; i++){

        m_cards[i] = copyMtmchkin.m_cards[i];
    }

}

void Mtmchkin::playNextCard(){

    if(getCurrentCard() == getNumCard()){

        setCurrentCard(0);
    }
   
    getCards()[getCurrentCard()].printInfo();
    getCards()[getCurrentCard()].applyEncounter(m_player);
    getPlayer().printInfo();
    setCurrentCard(getCurrentCard()+1);

}

bool Mtmchkin::isOver() const {
    
    if (getPlayer().getLevel() == 10 || getPlayer().isKnockedOut()) {

        return true;
    }

    return false;

}

GameStatus Mtmchkin::getGameStatus() const{

    if (isOver()){
        
        if (getPlayer().getLevel() == 10){ // if the player won

            return GameStatus::Win;
        }

        return GameStatus::Loss; // if the player lost

    }

    return GameStatus::MidGame; // if the game is still running
}

//get set functions

Player Mtmchkin::getPlayer() const{

    return m_player;
}

Card* Mtmchkin::getCards() const{

    return m_cards;
}
int Mtmchkin::getNumCard() const{

    return m_size;
}
int Mtmchkin::getCurrentCard() const{

    return m_currentCard;
}
void Mtmchkin::setGameStatus(GameStatus status){

    m_gameStatus = status;
}
void Mtmchkin::setCurrentCard(int index){

    m_currentCard = index;
}
void Mtmchkin::setNumCard(int num){

    m_size = num;
}