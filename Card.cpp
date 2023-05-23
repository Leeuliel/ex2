#include "Card.h"


Card::Card(CardType type, const CardStats& stats): m_effect(type), m_stats(stats) {

    // initialize the card from the init list
    // nothing to do here
}

void Card::printInfo() const{ // the constr after the function name mean that the function is const and can't change the object
    
    switch (this->m_effect) { // following the ex2 rules, printing the card info according to the type of the card

        case CardType::Battle:
		
            printBattleCardInfo(this->m_stats);
            break;
        case CardType::Buff:
		
            printBuffCardInfo(this->m_stats);
            break;
        case CardType::Heal:
		
            printHealCardInfo(this->m_stats);
            break;
        case CardType::Treasure:
		
            printTreasureCardInfo(this->m_stats);
            break;
        default:
            break;
			
    }

}

void Card::applyEncounter(Player& player) const { // this function is const, can't change the object

    switch (this->m_effect) { // following the ex2 rules, applying the card effect according to the type of the card

        case CardType::Battle: // if the card is a battle card
            
            if (player.getAttackStrength() >= this->m_stats.force) {

                player.levelUp();
                player.addCoins(this->m_stats.loot); // add this card loot
                printBattleResult(true); 
            }
            else { // the player lost the battle
				
                player.damage(this->m_stats.hpLossOnDefeat); // the player lost the battle, so he lost hp
                printBattleResult(false);
            }
            break;

        case CardType::Buff:
            
            if (player.pay(this->m_stats.cost)) {

                player.buff(this->m_stats.buff);
            }
            break;

        case CardType::Heal:
            
            if (player.pay(this->m_stats.cost)) {
                
                player.heal(this->m_stats.heal);
            }
            break;

        case CardType::Treasure:
            
            player.addCoins(this->m_stats.loot);
            break;

        default:
            break;
    }

}