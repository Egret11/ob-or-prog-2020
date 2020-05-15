#include "combination.h"

// TODO: Implement here the methods of Combination and all derived classes
Single::Single(Card* card){
  cards = new Card[1];
  cards[0] = card;
  Combination(cards, SINGLE, 1);
}



Pair::Pair(Card* card1, Card* card2){
  cards = new Card[2];
  cards[0] = card1;
  cards[1] = card2;
  Combination(cards, PAIR, 2);
}


ThreeOfAKind::ThreeOfAKind(Card* card1, Card* card2, Card* card3){
  cards = new Card[3];
  cards[0] = card1;
  cards[1] = card2;
  cards[2] = card3;
  Combination(cards, THREEOFAKIND, 3);
}



Stairs::Stairs(Card** cards, int numberOfCards){
    Combination(cards, STAIRS, numberOfCards)
}


FullHouse::FullHouse(ThreeOfAKind* combination1, Pair* combination2){
  cards = new Card[5];

  cards[0] = combination1[0];
  cards[1] = combination1[1];
  cards[2] = combination1[2];

  cards[3] = combination2[0];
  cards[4] = combination2[1];

  Combination(cards,FULLHOUSE,5)
}


//
Straight::Straight(Card** cards, int numberOfCards){
  Combination(cards, STRAIGHT, numberOfCards);
}



bool Straight::cardsHaveTheSameSuit(){
  for( int i = 0; i < getNumberOfCards() - 1 ; i++ ){
    if(cards[i].getSuit() != cards[i+1].getSuit())
        return false;
  }
  return true;
}



FourOfAKind::FourOfAKind(Card* card1, Card* card2, Card* card3, Card* card4){
  cards = new Card[4];
  cards[0] = card1;
  cards[1] = card2;
  cards[2] = card3;
  cards[3] = card4;

  Combination( cards, FOUROFAKIND, 4);
}



StraightFlush::StraightFlush(Straight* combination){
 Combination( combination, STRAIGHT, getNumberOfCards());
}
