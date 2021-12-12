#include <iostream>
#include <cstdlib>

using namespace std;

class Gameplay {
    public:
        void printCard(int id)
        {
            //This switch statement is used to return cards depending on the id passed.
            //Since there can be 4 cards of the same value but different suite, each number lesser than 13 denotes a different suite.
            //So if an id of 28 is passed, it denotes that the card 2 of Diamonds must be returned.
        	switch(id%13){
        		case 0: 
        			cout << "2-";
        			break;
        		case 1: 
        			cout << "3-";
        			break;
        		case 2: 
        			cout << "4-";
        			break;
        		case 3: 
        			cout << "5-";
        			break;
        		case 4: 
        			cout << "6-";
        			break;
        		case 5: 
        			cout << "7-";
        			break;
        		case 6: 
        			cout << "8-";
        			break;
        		case 7: 
        			cout << "9-";
        			break;
        		case 8: 
        			cout << "10-";
        			break;
        		case 9: 
        			cout << "J-";
        			break;
        		case 10: 
        			cout << "Q-";
        			break;
        		case 11: 
        			cout << "K-";
        			break;
        		case 12: 
        			cout << "A-";
        			break;
        		default: break;
        	}

            //This switch statement is used to determine the suite of card, the values starting from Heart to Clubs.
        	switch(id/13){
        		case 0: 
        			cout << "H";
        			break;
        		case 1: 
        			cout << "S";
        			break;
        		case 2: 
        			cout << "D";
        			break;
        		case 3: 
        			cout << "C";
        			break;
        		default: break;
        	}

        	cout << " ";
        }
        //The hand as well as the number of cards in hand is passed as input and the cards in hand are displayed in output
        void printHand(int hand[], int numCards)
        {
         	for(int i=0; i<numCards; i++){
         		printCard(hand[i]);
         		cout << " ";
         	}

         	cout << "\n";
        }
};