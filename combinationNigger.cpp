#include "combination.h"

// TODO: Implement here the methods of Combination and all derived classes

Combination::Combination(){}


Combination::Combination(Card** cards, CombinationType type, int numberOfCards){
    this->cards = cards;
    this->type = type;
    this->numberOfCards = numberOfCards;
    if(type != FULLHOUSE){ value = cards[numberOfCards - 1]->getValue(); }
    else{ value = cards[0]->getValue() * 10 + cards[4]->getValue(); }
}


Combination::~Combination(){
    delete[] cards;
}