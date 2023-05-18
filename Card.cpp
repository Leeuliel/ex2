#include "Card.h"


Card::Card(CardType type, const CardStats& stats): m_effect(type), m_stats(stats) {

    // initialize the members of the class from the initializer list
    // nothing to do here
    m_effect = type;
    m_stats = stats;

}

void Card::printInfo() const{ // the constr after the function name mean that the function is const and can't change the object
    
    switch (this->m_effect) {

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

    switch (this->m_effect) {

        case CardType::Battle:
            
            if (player.getAttackStrength() >= this->m_stats.force) {

                player.levelUp();
                player.addCoins(this->m_stats.loot);
                printBattleResult(true);
            }
            else {
                player.damage(this->m_stats.hpLossOnDefeat);
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