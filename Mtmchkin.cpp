#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards): m_player(playerName){
  
    m_gameStatus = GameStatus::MidGame;
    m_size = numOfCards;
    m_cards = (Card*)malloc(m_size * sizeof(Card));
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
    m_gameStatus = copyMtmchkin.m_gameStatus;
    m_size = copyMtmchkin.m_size;
    m_currentCard = copyMtmchkin.m_currentCard;
    for(int i = 0; i < m_size; i++){

        m_cards[i] = copyMtmchkin.m_cards[i];
    }

}

void Mtmchkin::playNextCard(){

    if(m_currentCard == m_size){

        m_currentCard = 0;
    }
   
    m_cards[m_currentCard].printInfo();
    m_cards[m_currentCard].applyEncounter(m_player);
    m_player.printInfo();
    m_currentCard+=1;

}

bool Mtmchkin::isOver() const {
    
    if (m_player.getLevel() == 10 || m_player.isKnockedOut()) {

        return true;
    }

    return false;

}

GameStatus Mtmchkin::getGameStatus() const{

    if (isOver()){
        
        if (m_player.getLevel() == 10){ // if the player won

            return GameStatus::Win;
        }

        return GameStatus::Loss; // if the player lost

    }

    return GameStatus::MidGame; // if the game is still running

}