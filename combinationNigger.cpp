#include "combination.h"

// TODO: Implement here the methods of Combination and all derived classes

Combination::Combination(){

}

Combination::Combination(Card** cards, CombinationType type, int numberOfCards){
    this->cards = cards;
    this->type = type;
    this->numberOfCards = numberOfCards;
}

