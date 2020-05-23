#include "combination.h"

// TODO: Implement here the methods of Combination and all derived classes

Combination::Combination(){} // an empty constructor


Combination::Combination(Card** cards, CombinationType type, int numberOfCards){ // set stuff
    this->cards = cards;
    this->type = type;
    this->numberOfCards = numberOfCards;
}


Combination::~Combination(){ // delete the Card*[] 
    delete[] cards;
}


bool Combination::containsCard(Card* card)
{
    for (int i = 0; i < numberOfCards; i++)
    {
        if (cards[i]->equals(card)) return true; // card is contained in comb
    }
    return false; // card not contained in comb
}


CombinationType Combination::getType()
{
    return type;
}


bool Combination::hasType(CombinationType type)
{
    return this->type == type;
}


int Combination::getValue()
{
    return value;
}


int Combination::getNumberOfCards()
{
    return numberOfCards;
}


bool Combination::equals(Combination* otherCombination)
{
    if (numberOfCards != otherCombination -> getNumberOfCards() || type != otherCombination-> getType() ) return false; // number of cards or type are different
    for (int i = 0; i < numberOfCards; i++)
    {
        if (containsCard(otherCombination ->cards[i]) == false) return false; // card of othercomb is not in comb
    }
    return true; // combs match
}


Single::Single(Card* card){
  cards = new Card*(card);
  type = SINGLE ;
  numberOfCards = 1;
  value = card->getValue();
}


Pair::Pair(Card* card1, Card* card2){
  cards = new Card*[2];
  cards[0] = card1;
  cards[1] = card2;

  type = PAIR;
  numberOfCards = 2;
  value = card1->getValue();
}


ThreeOfAKind::ThreeOfAKind(Card* card1, Card* card2, Card* card3){
  cards = new Card*[3];
  cards[0] = card1;
  cards[1] = card2;
  cards[2] = card3;

  type = THREEOFAKIND;
  numberOfCards = 3;
  value = card1->getValue();
}


Stairs::Stairs(Card** cards, int numberOfCards):Combination(cards, STAIRS, numberOfCards){
    value = cards[numberOfCards-1]->getValue();
}


FullHouse::FullHouse(ThreeOfAKind* combination1, Pair* combination2){
  cards = new Card*[5];

  cards[0] = combination1->getCard(0);
  cards[1] = combination1->getCard(1);
  cards[2] = combination1->getCard(2);

  cards[3] = combination2->getCard(0);
  cards[4] = combination2->getCard(1);

  type = FULLHOUSE;
  numberOfCards = 5;
  value = 10*(combination1->getValue()) + combination2->getValue();

}


Straight::Straight(Card** cards, int numberOfCards):Combination(cards, STRAIGHT, numberOfCards){
  value = cards[numberOfCards-1]->getValue();
}


bool Straight::cardsHaveTheSameSuit(){
  for( int i = 1; i < getNumberOfCards(); i++){
    if(cards[0]->getSuit() != cards[i]->getSuit())
        return false;
  }
  return true;
}


FourOfAKind::FourOfAKind(Card* card1, Card* card2, Card* card3, Card* card4){
  cards = new Card*[4];
  cards[0] = card1;
  cards[1] = card2;
  cards[2] = card3;
  cards[3] = card4;

  type = FOUROFAKIND;
  numberOfCards = 4;
  value = card1->getValue();
}


StraightFlush::StraightFlush(Straight* combination){
  cards = new Card*[combination->getNumberOfCards()];
  for(int i = 0; i < combination->getNumberOfCards(); i++){
    cards[i] = combination->getCard(i);
  }
  
  value = combination->getCard(combination->getNumberOfCards()-1)->getValue();
  numberOfCards = combination->getNumberOfCards();
  type = STRAIGHTFLUSH;
}