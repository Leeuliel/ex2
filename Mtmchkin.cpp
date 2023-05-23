#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards): m_player(playerName ,DEFAULT_HP ,DEFAULT_FORCE){
  
    // set the other fields
    this->m_gameStatus = GameStatus::MidGame;
    this->m_size = numOfCards;
    this->m_cards = new Card[m_size];
	
    // copy the cards from the array to the new array
    // every card object is not dinamiclly allocated so we can copy it with the default copy c'tor of the Card class
    for (int i = 0; i < m_size; i++){

        this->m_cards[i] = cardsArray[i];
    }
	
    this->m_currentCard = 0;
}

Mtmchkin::~Mtmchkin(){

    delete[]  m_cards;
}


// player is not dinamiclly allocated so we can copy it with the default copy c'tor from the initialization list
// make a new array of cards and copy the cards from the other Mtmchkin - 
// we initialize an empty array of cards in size of the other Mtmchkin and then copy the cards from the other Mtmchkin
// (the copy will happen in the for loop) and not from the initialization list
Mtmchkin::Mtmchkin(const Mtmchkin& copyMtmchkin):
m_player(copyMtmchkin.m_player), m_cards(new Card[copyMtmchkin.getCardNumber()]) 
{
    
    // set the other fields
    this->setGameStatus(copyMtmchkin.getGameStatus());
    this->setNumCard(copyMtmchkin.getCardNumber());
    this->setCurrentCard(copyMtmchkin.getCurrentCard());

    // copy the cards from the other Mtmchkin
    // every card object is not dinamiclly allocated so we can copy it with the default copy c'tor of the Card class

    for(int i = 0; i < m_size; i++){

        m_cards[i] = copyMtmchkin.m_cards[i];
    }

}

void Mtmchkin::playNextCard(){ 

    // this function play the next card in the array of cards

    if (this->getCurrentCard() == this->getCardNumber()){

        setCurrentCard(0);
    }
   
    this->getCards()[this->getCurrentCard()].printInfo();
    this->getCards()[this->getCurrentCard()].applyEncounter(this->m_player);
    this->getPlayer().printInfo();
    this->setCurrentCard(this->getCurrentCard() + 1);

}

bool Mtmchkin::isOver() const { // this function check if the game is over
    
    if (this->getPlayer().getLevel() == 10 || this->getPlayer().isKnockedOut()) {

        return true;
    }

    return false;

}

GameStatus Mtmchkin::getGameStatus() const{

    if (this->isOver()){
        
        if (getPlayer().getLevel() == 10){ // if the player won

            return GameStatus::Win;
        }

        return GameStatus::Loss; // if the player lost

    }

    return GameStatus::MidGame; // if the game is still running
}

//get and set functions

Player Mtmchkin::getPlayer() const{

    return m_player;
}

Card* Mtmchkin::getCards() const{

    return m_cards;
}
int Mtmchkin::getCardNumber() const{

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