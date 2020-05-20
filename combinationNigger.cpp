#include "combination.h"

// TODO: Implement here the methods of Combination and all derived classes

Combination::Combination(){

}

Combination::Combination(Card** cards, CombinationType type, int numberOfCards){
    this->cards = cards;
    this->type = type;
    this->numberOfCards = numberOfCards;
}

Combination::~Combination(){
    delete[] cards;
}

Pair::Pair(Card* card1, Card* card2) : Combination::Combination(cards, PAIR, 2){
  Card **cards = new Card*[2];
  cards[0] = card1;
  cards[1] = card2;
}
