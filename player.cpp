
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
    if(last->getType() == FOUROFAKIND && current->getType() == FOUROFAKIND) return current->getValue() > last->getValue(); // FOAK on FOAK
    
    else if( (current->getType() == STRAIGHTFLUSH) && (last->getType() == FOUROFAKIND) ) return true; // SF ON FOAK
    
    else if(current->getType() == STRAIGHTFLUSH && last->getType() == STRAIGHTFLUSH){ // SF on SF
        
        if(current->getNumberOfCards() > last->getNumberOfCards()) return true; // current has more cards 
        
        else if( (current->getNumberOfCards() == last->getNumberOfCards()) 
                && (current->getValue() > last->getValue()) ) return true; // equal length but current is higher

        else return false; // then current is shorter
    }
    
    else if( current->getType() == STRAIGHTFLUSH || current->getType() == FOUROFAKIND
             && last->getType() != FOUROFAKIND && last->getType() != STRAIGHTFLUSH ) return true; // bomb on NOT bomb
    
    return (current->getType() == last->getType())                          // same type 
            && (current->getNumberOfCards() == last->getNumberOfCards())    // equal length (for stairs and straights)
            && (current->getValue() > last->getValue());                    // current is higher
}