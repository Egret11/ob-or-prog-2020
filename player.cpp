#include "player.h"
#include <ctime>


Player::Player(int idx){
    index = idx;
    bucketSize = 0;
    status = "HASNTPLAYED"; 
    if(idx == 0){
        name = "Player1";
    }
    if(idx == 1){
        name = "Player2";
    }
    if(idx == 2){
        name = "Player3";
    }
    if(idx == 3){
        name = "Player4";
    }
}

void Player::setStatus(string newStatus = "HASNTPLAYED"){
    status = newStatus;
}

bool Player::hasStatus(string checkStatus){
    return (status == checkStatus);
}

string Player::getName(){
    return name;
}

bool Player::hasNoCardsLeft(){
    return (hand.getCardCount() == 0);
}

bool Player::hasMahJong(){
    for(int n = 0; n < 14; n++){
        if(hand.getCard(n).getSuit() == "MAHJONG"){return true;}
    }
    return false;
}

bool Player::decidePlay(){
    srand(time(NULL));
    return (rand()%2);
}



// TODO: Implement here the methods of Player
// Do not implement the methods addCardToHand, removeCardFromHand, addCardsToBucket
// createHandCombinations, findNumberOfPlayableCombinations, playAnyCombination, play
// These are already implemented in file playercombinations.cpp
// Implement the rest of the methods of Player
