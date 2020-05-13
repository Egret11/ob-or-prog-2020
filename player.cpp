#include "player.h"

bool Player::combinationCanBePlayed(Combination *current, Combination *last){
    if(last->getType() == FOUROFAKIND && current->getType() == FOUROFAKIND){
    return current->getValue() > last->getValue();
    }
    else if(current->getType() == STRAIGHTFLUSH && last->getType() == FOUROFAKIND){
        return true;
    }
    else if((current->getType() == STRAIGHTFLUSH || current->getType() == FOUROFAKIND) && (last->getType() != FOUROFAKIND || last->getType() != STRAIGHTFLUSH) ){
        return true;
    } 
    else
    return (current->getType() == last->getType() && current->getNumberOfCards() == last->getNumberOfCards() && current->getValue() > last->getValue());  
}

// TODO: Implement here the methods combinationCanBePlayed and countBucketPoints of Player
// Do not implement any other methods of Player as these are already implemented in file playercombinations.cpp
