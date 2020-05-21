
#include "player.h"

int Player::countBucketPoints(){
    int points = 0;
    for(int i = 0; i != bucketSize; i++){
        for(int j = 0; j != bucketSize; j++){
            if(bucket[i][j].getValue() == 5){points+=5;}
            else if(bucket[i][j].getValue() == 10){points+=10;}
            else if(bucket[i][j].getValue() == 13){points+=10;}
            else if(bucket[i][j].getSuit() == PHOENIX){points-=25;}
            else if(bucket[i][j].getSuit() == DRAGON){points+=25;}
        }
    }
    return points;
}


bool Player::combinationCanBePlayed(Combination *current, Combination *last){
    if(last->getType() == FOUROFAKIND && current->getType() == FOUROFAKIND){
    return current->getValue() > last->getValue();
    }
    else if(current->getType() == STRAIGHTFLUSH && last->getType() == FOUROFAKIND){
        return true;
    }
    else if(current->getType() == STRAIGHTFLUSH && last->getType() == STRAIGHTFLUSH){
        if(current->getNumberOfCards() >= last->getNumberOfCards()) {return true;}
        else if(current->getValue() > last->getValue() && current->getNumberOfCards() == last->getNumberOfCards()){return true;} 
    }
    else if((current->getType() == STRAIGHTFLUSH || current->getType() == FOUROFAKIND) && (last->getType() != FOUROFAKIND || last->getType() != STRAIGHTFLUSH) ){
        return true;
    } 
    else
    return (current->getType() == last->getType() && current->getNumberOfCards() == last->getNumberOfCards() && current->getValue() > last->getValue());  
}

// TODO: Implement here the methods combinationCanBePlayed and countBucketPoints of Player
// Do not implement any other methods of Player as these are already implemented in file playercombinations.cpp


