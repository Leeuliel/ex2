#include "Mtmchkin.h"





bool Mtmchkin::isOver() const {
    
    if (this->player.getLevel() == 10 || this->player.isKnockedOut()) {

        return true;
    }

    return false;

}

GameStatus Mtmchkin::getGameStatus() const{

    if (this->isOver()){
        
        if (this->player.getLevel() == 10){ // if the player won

            return GameStatus::Win;
        }

        return GameStatus::Loss; // if the player lost

    }

    return GameStatus::MidGame; // if the game is still running

}