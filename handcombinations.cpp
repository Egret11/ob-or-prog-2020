#include "hand.h"
// TODO: Implement here the method createAllCombinations of Hand

void Hand::createAllCombinations(){ 
    for(int startingIndex = 0; startingIndex < currentNumberOfCards; startingIndex ++){ // loop over the hand
        Combination SINGLE = Combination(); // create a "SINGLE" combination object for each of the cards
        SINGLE.addCard(cards[startingIndex]);
        allCombinations[allCombinationsSize ++] = SINGLE;  // save it in allCombinations array
        for(int loopingIndex = startingIndex + 1; loopingIndex < currentNumberOfCards; loopingIndex ++){ // loop over the cards after it to check for doubles
            if(cards[startingIndex].getValue() == cards[loopingIndex].getValue()){
                Combination PAIR = Combination(); // if a double is found create "PAIR" object 
                PAIR.addCard(cards[startingIndex]);
                PAIR.addCard(cards[loopingIndex]);  // add both cards
                allCombinations[allCombinationsSize++] = PAIR; // save it in allCombinations array
            }
        }
    }
}