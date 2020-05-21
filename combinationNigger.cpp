#include "combination.h"

// TODO: Implement here the methods of Combination and all derived classes

Combination::Combination(){}


Combination::Combination(Card** cards, CombinationType type, int numberOfCards){
    this->cards = cards;
    this->type = type;
    this->numberOfCards = numberOfCards;
}


Combination::~Combination(){
    delete[] cards;
}

Straight::Straight(Card** cards, int numberOfCards):Combination(cards, STRAIGHT, numberOfCards){}

bool Straight::cardsHaveTheSameSuit(){
  for( int i = 1; i < getNumberOfCards(); i ++){
    if(cards[0]->getSuit() != cards[i]->getSuit())
        return false;
  }
  return true;
}

StraightFlush::StraightFlush(Straight* combination){
    cards = new Card*[combination->getNumberOfCards()];
    for(int i = 0; i < combination->getNumberOfCards(); i ++){
        cards[i] = combination->getCard(i);
    }
    value = combination->getCard(combination->getNumberOfCards() - 1)->getValue();
    numberOfCards = combination->getNumberOfCards();
    type = STRAIGHTFLUSH;
}

