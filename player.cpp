
#include "player.h"

int Player::countBucketPoints(){
    int points = 0;
    for(int i = 0; i != bucketSize; i++){                   // loop over the bucket, accumulating the points
            if(bucket[i]->getValue() == 5){points+=5;}
            else if(bucket[i]->getValue() == 10){points+=10;}
            else if(bucket[i]->getValue() == 13){points+=10;}
            else if(bucket[i]->getSuit() == PHOENIX){points-=25;}
            else if(bucket[i]->getSuit() == DRAGON){points+=25;}
    }
    return points;
}


bool Player::combinationCanBePlayed(Combination *current, Combination *last){
    if(last->getType() == FOUROFAKIND && current->getType() == FOUROFAKIND) return current->getValue() > last->getValue(); // Four Of A Kind VS Four Of A Kind,
                                                                                                                           // the higher value wins 
    else if( (current->getType() == STRAIGHTFLUSH) && (last->getType() == FOUROFAKIND) ) return true; // Straight Flush VS Four Of A Kind, Straight Flush wins 
    
    else if( (current->getType() == STRAIGHTFLUSH) && (last->getType() == STRAIGHTFLUSH) ){ // Straight Flush VS Straight Flush then we examine further:
        
        if(current->getNumberOfCards() > last->getNumberOfCards()) return true; // current is lengthier and wins
        
        else if( (current->getNumberOfCards() == last->getNumberOfCards()) 
                && (current->getValue() > last->getValue()) ) return true; // if they have equal length: current needs higher value

        else return false; // then current is shorter and thus can't be played
    }
    
    else if( ( (current->getType() == STRAIGHTFLUSH) || (current->getType() == FOUROFAKIND) )
            && ( (last->getType() != FOUROFAKIND) && (last->getType() != STRAIGHTFLUSH) ) ) return true; // current is a BOMB, last isn't
    
    return (current->getType() == last->getType())                          // same type 
            && (current->getNumberOfCards() == last->getNumberOfCards())    // equal length (for stairs and straights)
            && (current->getValue() > last->getValue());                    // current is higher
}