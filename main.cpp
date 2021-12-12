#include <iostream>
#include <cstdlib>
#include "Deck.h"
#include "Gameplay.h"

const int seed = 4;                                 

int main() {
    /*rand() generates same sequence each time if srand() is not called with a seed value
    To get different sequence of shuffled cards on each playthrough, srand is used here */
    srand(seed);

    Deck deck;
    Gameplay game;
    int cards[52];
    int dhand[9];
    int phand[9];    

    bool repeat = true;

    while(repeat){
  	    char choice;
  	    int phandsize = 2, dhandsize = 2;

  	    for(int i=0; i<deck.getNumCards();i++){
            //A "deck" of 52 cards (or numbers) initialised
  	    	cards[i]=i;
  	    }

  	    deck.shuffle(cards);

        //Inititally, the dealer and player are dealt 2 cards
  	    for(int i=0; i<2; i++){
  	    	phand[i] = cards[2*i];          //Simple mathematical expression to deal different cards to dealer and player
  	    	dhand[i] = cards[2*i+1];
  	    }

        //In the game, one of the dealer's card's is dealt face-down, while both the cards of the player are face-up
  	    cout << "Dealer: " << "? " ; 
  	    game.printCard(dhand[1]);
  	    cout << endl;
  	    cout << "Player: "; 
  	    game.printHand(phand,phandsize);

        //In case either of the scores exceed 21, that player is bust so that condition must be checked beforehand
        while(deck.getBestScore(phand,phandsize)<21){
  		    cout << "Type 'h' to hit and 's' to stay: ";
  		    cin >> choice;

  		    if(choice == 'h'){
                //The next card from the deck is dealt and the handsize is increased by 1 
  		    	phand[phandsize] = cards[2+phandsize];
  		    	phandsize++;
  		    	cout << "Player: ";
  		    	game.printHand(phand,phandsize);
    
  		    }
  		    else 
  		    	break;
  	    }

        //This conditional checks for the player's status in the game
        if(deck.getBestScore(phand,phandsize)>21){
  			cout << "Player Busts!\n" << "Lose ";
  			cout << deck.getBestScore(phand,phandsize) << " "; 
  			cout << deck.getBestScore(dhand,dhandsize) << endl;
  		}

  		else if(deck.getBestScore(phand,phandsize<=21)){
            //If dealer's score is below 17, he is required to take a card, with no option of staying.
            //Foloowing block deals a card to dealer
  			while(deck.getBestScore(dhand,dhandsize)<17){
  				dhand[dhandsize] = cards[dhandsize+phandsize];
  				dhandsize++;
  			}

  			cout << "Dealer: "; 
  			game.printHand(dhand,dhandsize);
  			cout << endl;

            //This conditional checks the dealer's status in the game
            if(deck.getBestScore(dhand,dhandsize)>21){
  				cout << "Dealer Busts!\n";
  				cout << "Win " << deck.getBestScore(phand,phandsize); 
  				cout << " " << deck.getBestScore(dhand,dhandsize);
  			}

            //Final condtional to check if the dealer or player has a better hand
  			else{
  				if(deck.getBestScore(phand,phandsize)>deck.getBestScore(dhand,dhandsize)){
  					cout << "Win " << deck.getBestScore(phand,phandsize); 
  					cout << " " << deck.getBestScore(dhand,dhandsize) << endl;
  				}

  				else if(deck.getBestScore(phand,phandsize)<deck.getBestScore(dhand,dhandsize)){
  					cout << "Lose " << deck.getBestScore(phand,phandsize); 
  					cout << " " << deck.getBestScore(dhand,dhandsize) << endl;
  				}

  				else{
  					cout << "Tie " << deck.getBestScore(phand,phandsize); 
  					cout << " " << deck.getBestScore(dhand,dhandsize) << endl;
  				}
  			}
        }
        cout << "\n";
		cout << "Play Again? y/n: ";
		cin >> choice;

		if(choice == 'y')
			repeat = true;
		
		else{
			repeat = false;
			break;
		}
    }
}