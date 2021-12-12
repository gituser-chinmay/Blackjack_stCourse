#include <iostream>
#include <cstdlib>
using namespace std;

class Deck {
    const int NUM_CARDS = 52;
    const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

    public:
        void shuffle(int cards[]) 
        {
            //A random shuffling of cards by using the rand function is done, the rand function is seeded using srand in main.
	        for(int i= NUM_CARDS-1; i>0; i--){
	    	    int temp;
	    	    int j = rand()%(i+1);
	    	    temp = cards[i];
	    	    cards[i]=cards[j];
	    	    cards[j]= temp; 
	        }
        }
        int cardValue(int id)
        {
        	int val = id%13;
        	return value[val];
        }
        //This function is used to return the sum of a dealt hand.
        //All value cards have their own respective values, where as all face cards have a value of 10.
        //The ace card can have a value of either 1 or 11 depending on the player.
        //This game uses whichever value of ace brings the player's total closest to 21 
        int getBestScore(int hand[], int numCards)
        {
        	int sum = 0;
        	bool addedAce = false;
        	int AcesAdded = 0;
        
        	for(int i=0; i<numCards; i++){
        		if((hand[i]%13==12)&&(sum+11>21))
        			sum++;
        		else
        			sum+=value[hand[i]%13];
        
        		if (hand[i]%13 == 12){
        			addedAce = true;
        			AcesAdded++;
        		}
        	}
        
        	if(addedAce&&sum>21){
        		sum = 0;
        		for(int i=0; i<numCards; i++){
        			if(hand[i]%13==12)
        				sum++;
        			else
        				sum+=value[hand[i]%13];
        		}
        	}
        
        	return sum;
        }
        //Returns the private variable NUM_CARDS
        int getNumCards()
        {
            return NUM_CARDS;
        }
};