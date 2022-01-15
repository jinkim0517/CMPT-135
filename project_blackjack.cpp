// Jin Kim 	301539203
// Advice: Followed BYCICLE website for optimal strategies
// based on the first and second deals. Then, I added some general advice(ie Don't hit when the score is 20)
// Academic honesty statement: I hereby confirm that this is my own work and I have not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).

#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <ctime>
#include <stdio.h>

using namespace std;
const int DECK_SIZE = 52;
const int MAX_HAND = 11;
const int BLACKJACK = 21;
const int DEALER_HIGH = 17;

// Card structure
struct Card {
	string suit;
	string description;
	int rank;
	int value;

	Card() {
		suit = "";
		description = "";
		rank = 0;
		value = 0;
	}
};

// CardArray structure for decks and hands
struct CardArray {
	Card* cards;
	int maxCards;
	int currentCards;

	CardArray() {
		cards = nullptr;
		maxCards = 0;
		currentCards = 0;
	}
};

// Function Prototypes
void getNewDeck(CardArray & deck);
string swap(string card);
void shuffleDeck(CardArray & deck);
void printDeck(const CardArray & deck);
int blackjack(CardArray & deck);
void deal(CardArray & deck, CardArray & hand);
int scoreCheck(CardArray deck);
void printCards(CardArray deck);
void playBlackjack(CardArray & deck);
void aceChange(CardArray & deck);
void advice(CardArray dealerHand, CardArray playerHand);
void refillDeck(CardArray & deck);

int main() {
	CardArray deck1;
	getNewDeck(deck1);
	cout << "DECK:" << endl;
  	printDeck(deck1);
	cout << endl;
	shuffleDeck(deck1);
	cout << "Shuffled DECK:" << endl;
	printDeck(deck1);
	cout << endl;
	
	playBlackjack(deck1);
	return 0;
} 


// Creates new deck (Part 1)
void getNewDeck(CardArray & deck){
	deck.maxCards = DECK_SIZE;
	deck.currentCards = DECK_SIZE;
	deck.cards = new Card[DECK_SIZE];

	// Array of value to assign to variables
	string suit[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
	int value[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int rank[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	
	// Variables to keep track of the number of cards in a set
	int spadeSet = 0;
	int heartSet = 0;
	int diamondSet = 0;
	int clubsSet = 0;

	for(int i = 0; i < DECK_SIZE; i++){
		// Assigns values to the first set
		if(i < 13){
			deck.cards[i].suit = suit[0];
			deck.cards[i].rank = rank[spadeSet];
			spadeSet++;
			if(deck.cards[i].rank == 1){
				deck.cards[i].description = "AS";
				deck.cards[i].value = value[10];
			}
			else if (deck.cards[i].rank > 1 && deck.cards[i].rank < 11){
				deck.cards[i].description = to_string(deck.cards[i].rank) + 'S';
				deck.cards[i].value = deck.cards[i].rank;
			}
			else if (deck.cards[i].rank >= 11){
				if(deck.cards[i].rank == 11){
					deck.cards[i].description = "JS";
					deck.cards[i].value = value[9];
				}
				else if(deck.cards[i].rank == 12){
					deck.cards[i].description = "QS";
					deck.cards[i].value = value[9];
				}
				else if(deck.cards[i].rank == 13){
					deck.cards[i].description = "KS";
					deck.cards[i].value = value[9];
				}
			}
		}
		// Assigns values to the second set
		else if(i >= 13 && i < 26){
			deck.cards[i].suit = suit[1];
			deck.cards[i].rank = rank[heartSet];
			heartSet++;

			if(deck.cards[i].rank == 1){
				deck.cards[i].description = "AH";
				deck.cards[i].value = value[10];
			}
			else if (deck.cards[i].rank > 1 && deck.cards[i].rank < 11){
				deck.cards[i].description = to_string(deck.cards[i].rank) + 'H';
				deck.cards[i].value = deck.cards[i].rank;
			}
			else if (deck.cards[i].rank >= 11){
				if(deck.cards[i].rank == 11){
					deck.cards[i].description = "JH";
					deck.cards[i].value = value[9];
				}
				else if(deck.cards[i].rank == 12){
					deck.cards[i].description = "QH";
					deck.cards[i].value = value[9];
				}
				else if(deck.cards[i].rank == 13){
					deck.cards[i].description = "KH";
					deck.cards[i].value = value[9];
				}
			}
		}
		// Assigns values to the third set
		else if(i >= 26 && i < 39){
			int n = 0;
			deck.cards[i].suit = suit[2];
			deck.cards[i].rank = rank[diamondSet];
			diamondSet++;

			if(deck.cards[i].rank == 1){
				deck.cards[i].description = "AD";
				deck.cards[i].value = value[10];
			}
			else if (deck.cards[i].rank > 1 && deck.cards[i].rank < 11){
				deck.cards[i].description = to_string(deck.cards[i].rank) + 'D';
				deck.cards[i].value = deck.cards[i].rank;
			}
			else if (deck.cards[i].rank >= 11){
				if(deck.cards[i].rank == 11){
					deck.cards[i].description = "JD";
					deck.cards[i].value = value[9];
				}
				else if(deck.cards[i].rank == 12){
					deck.cards[i].description = "QD";
					deck.cards[i].value = value[9];
				}
				else if(deck.cards[i].rank == 13){
					deck.cards[i].description = "KD";
					deck.cards[i].value = value[9];
				}
			}
		}
		// Assigns values to the fourth set
		else if(i >= 39 && i < 52){
			deck.cards[i].suit = suit[3];
			deck.cards[i].rank = rank[clubsSet];
			clubsSet++;

			if(deck.cards[i].rank == 1){
				deck.cards[i].description = "AC";
				deck.cards[i].value = value[10];
			}
			else if (deck.cards[i].rank > 1 && deck.cards[i].rank < 11){
				deck.cards[i].description = to_string(deck.cards[i].rank) + 'C';
				deck.cards[i].value = deck.cards[i].rank;
			}
			else if (deck.cards[i].rank >= 11){
				if(deck.cards[i].rank == 11){
					deck.cards[i].description = "JC";
					deck.cards[i].value = value[9];
				}
				else if(deck.cards[i].rank == 12){
					deck.cards[i].description = "QC";
					deck.cards[i].value = value[9];
				}
				else if(deck.cards[i].rank == 13){
					deck.cards[i].description = "KC";
					deck.cards[i].value = value[9];
				}
			}
		}
	}
}

// Prints all cards in a CardArray variable
void printDeck(const CardArray & deck){
	for(int i = 0; i < DECK_SIZE; i++){
		cout << setw(4) << deck.cards[i].description;
		if(i == 12){
			cout << endl;
		}
		if(i == 25){
			cout << endl;
		}
		if(i == 38){
			cout << endl;
		}
	}
}

// Shuffles a deck
void shuffleDeck(CardArray & deck){
	srand(time(0));
	for(int i = 0; i < DECK_SIZE; i++){
		int roll = rand() % 52;
		Card temp = deck.cards[roll];
		deck.cards[roll] = deck.cards[i];
		deck.cards[i] = temp;
	}
}

// Blackjack game (Part 2 & 3)
int blackjack(CardArray & deck){
	CardArray playerHand;
	CardArray dealerHand;

	playerHand.cards = new Card[MAX_HAND];
	dealerHand.cards = new Card[MAX_HAND];

	playerHand.maxCards = MAX_HAND;
	playerHand.currentCards = 0;

	dealerHand.maxCards = MAX_HAND;
	dealerHand.currentCards = 0;

	// Array of possible statements/remarks to a play
	string remarks[] = {"Dealer is bust, you win!", "Blackjack, you win!", "Game is tied", "Double bust, the game is tied!", "You lose!", "You win!"};

	// Refills deck if cards run out
	refillDeck(deck);

	cout << "Deal First Card" << endl;
	cout << "---------------" << endl;

	// Deals first card
	deal(deck, playerHand);
	refillDeck(deck);
	deal(deck, dealerHand);

	cout << "+Player+:";
	printCards(playerHand);
	cout << endl;
	cout << "*Dealer*:";
	printCards(dealerHand);
	cout << endl;

	cout << endl << "Deal Second Card" << endl;
	cout << "---------------" << endl;

	refillDeck(deck);

	// Deals second card but hides the dealer's second card
	deal(deck, playerHand);
	refillDeck(deck);
	deal(deck, dealerHand); 

	cout << "+Player+:";
	printCards(playerHand);
	cout << endl;
	cout << "*Dealer*:";
	cout << setw(4) << dealerHand.cards[0].description << setw(4) << "??";
	cout << endl;

	int result = 0;

	// Changes aces if intial deal results in a bust
	aceChange(playerHand);
	// Checks for a bust or blackjack off of initial deal
	if (scoreCheck(playerHand) == BLACKJACK){
		cout << endl << "Dealing to the dealer" << endl;
		cout << "---------------------" << endl;
		cout << "*Dealer*:";
		printCards(dealerHand);
		cout << endl;

		if (scoreCheck(dealerHand) == BLACKJACK){
			cout << remarks[2] << endl;
			result = 0;
		}
		else{
			cout << remarks[1] << endl;
			result = 1;
		}
	}
	else if (scoreCheck(playerHand) > BLACKJACK){
		cout << "*Dealer*:";
		printCards(dealerHand);
		cout << endl;
		if (scoreCheck(dealerHand) > BLACKJACK){
			// Changes ace values if dealer is bust
			aceChange(dealerHand);
			if (scoreCheck(dealerHand) > BLACKJACK){
				cout << remarks[3] << endl;
				result = 0;
				delete[] dealerHand.cards;
				delete[] playerHand.cards;
			}
		}
		else{
			cout << remarks[4] << endl;
			result = -1;
			delete[] dealerHand.cards;
			delete[] playerHand.cards;
		}
	}
	else{
		advice(dealerHand, playerHand);
		// Hit or stand input
		char decision;
		cout << "Enter h to hit or s to stand: ";
		cin >> decision;
		// Error handling
		while(cin.fail()){
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "error" << endl;
			cout << "Enter h to hit or s to stand: ";
			cin >> decision;
		}
		while(decision != 'h' && decision != 's'){
			cout << "error" << endl;
			cout << "Enter h to hit or s to stand: ";
			cin >> decision;
		}

		while (decision == 'h'){
			// Refills deck if cards run out
			refillDeck(deck);
			deal(deck, playerHand);
			cout << "+Player+:";
			printCards(playerHand);
			cout << endl;

			// If the score is above 21, change aces from 1 to 11
			aceChange(playerHand);

			if (scoreCheck(playerHand) > BLACKJACK){
				decision = 's';
			}
			else{
				advice(dealerHand, playerHand);
				cout << "Enter h to hit or s to stand: ";
				cin >> decision;
				// Error handling
				while(cin.fail()){
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "error" << endl;
					cout << "Enter h to hit or s to stand: ";
					cin >> decision;
				}

				while(decision != 'h' && decision != 's'){
					cout << "error" << endl;
					cout << "Enter h to hit or s to stand: ";
					cin >> decision;
				}
			}
		}

		// Reveal dealers second card and deal until score is greater than 16
		cout << endl << "Dealing to the dealer" << endl;
		cout << "---------------------" << endl;
		cout << "*Dealer*:";
		printCards(dealerHand);
		cout << endl;
		// Refills deck if cards run out
		refillDeck(deck);

		// Deals to dealer if player is not bust
		if(scoreCheck(playerHand) <= BLACKJACK){
			while (scoreCheck(dealerHand) < DEALER_HIGH){
				deal(deck, dealerHand);
				cout << "*Dealer*:";
				printCards(dealerHand);
				cout << endl;
				if(scoreCheck(dealerHand) > BLACKJACK){
					aceChange(dealerHand);
				}
				// Refills deck if cards run out
				if(deck.currentCards == 0){
					CardArray deck2;
					getNewDeck(deck2);
					shuffleDeck(deck2);
					deck = deck2;
				}
			}
		}
		else{
			// Changes any ace values to try and reduce score to below 21
			aceChange(dealerHand);
		}

		aceChange(playerHand);

		// Print scores
		cout << endl;
		cout << "Player Score: " << scoreCheck(playerHand) << endl;
		cout << "Dealer Score: " << scoreCheck(dealerHand) << endl;

		// Print remarks for specific win/lose scenarios using array above
		// Sets result variable to the corresponding outcome (1 = win, 0 = tie, -1 = lose)
		if(scoreCheck(playerHand) > scoreCheck(dealerHand)){
			if(scoreCheck(playerHand) < BLACKJACK){
				cout << remarks[5];
				result = 1;
				delete[] dealerHand.cards;
				delete[] playerHand.cards;
			}
			else if(scoreCheck(playerHand) > BLACKJACK && scoreCheck(dealerHand) > BLACKJACK){
				cout << remarks[3];
				result = 0;
				delete[] dealerHand.cards;
				delete[] playerHand.cards;
			}
			else if(scoreCheck(playerHand) == BLACKJACK){
				cout << remarks[1];
				result = 1;
				delete[] dealerHand.cards;
				delete[] playerHand.cards;
			}
			else if(scoreCheck(playerHand) > BLACKJACK){
				cout << remarks[4];
				result = -1;
				delete[] dealerHand.cards;
				delete[] playerHand.cards;
			}
		}
		else if(scoreCheck(playerHand) < scoreCheck(dealerHand)){
			if(scoreCheck(playerHand) < BLACKJACK && scoreCheck(dealerHand) < BLACKJACK){
				cout << remarks[4];
				result = -1;
				delete[] dealerHand.cards;
				delete[] playerHand.cards;
			}
			else if(scoreCheck(playerHand) > BLACKJACK && scoreCheck(dealerHand) > BLACKJACK){
				cout << remarks[3];
				result = 0;
				delete[] dealerHand.cards;
				delete[] playerHand.cards;
			}
			else if(scoreCheck(playerHand) < BLACKJACK && scoreCheck(dealerHand) > BLACKJACK){
				cout << remarks[0];
				result = 1;
				delete[] dealerHand.cards;
				delete[] playerHand.cards;
			}
			else if(scoreCheck(dealerHand) == BLACKJACK){
				cout << remarks[4];
				result = -1;
				delete[] dealerHand.cards;
				delete[] playerHand.cards;
			}
			else if(scoreCheck(playerHand) == BLACKJACK){
				cout << remarks[1];
				result = 1;
				delete[] dealerHand.cards;
				delete[] playerHand.cards;
			}
		}
		else if(scoreCheck(playerHand) == scoreCheck(dealerHand)){
			cout << remarks[2];
			result = 0;
			delete[] dealerHand.cards;
			delete[] playerHand.cards;
		}
	}
	return result;
}

// Function to play multiple games and track wins, losses, and ties (Part 3)
void playBlackjack(CardArray & deck){
	cout << "BLACKJACK" << endl;
	cout << "---------" << endl;

	char decision;
	cout << "Do you want to play black jack? (y to play): ";
	cin >> decision;

	// Error handling
	while(cin.fail()){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "error" << endl;
		cout << "Do you want to play black jack? (y to play): ";
		cin >> decision;
		
	}

	int wins = 0;
	int losses = 0;
	int ties = 0;
	int rounds = 0;

	while(decision == 'y'){
		rounds++;
		int result = blackjack(deck);
		if(result == 1){
			wins++;
		}
		else if(result == -1){
			losses++;
		}
		else if(result == 0){
			ties++;
		}
		cout << endl << "_________________________" << endl;
		cout << "Do you want to play another round of Blackjack? (y to play): ";
		cin >> decision;

		// Error handling
		while(cin.fail()){
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "error" << endl;
			cout << "Do you want to play black jack? (y to play): ";
			cin >> decision;
		}
	}

	// Prints data collected
	cout << "Thanks for playing! You played " << rounds << " rounds, and your record was: " << endl;
	cout << setw(4) << "Wins: " << setw(6) << wins << endl;
	cout << setw(4) << "Losses: " << setw(4) << losses << endl;
	cout << setw(4) << "Ties: " << setw(6) << ties << endl;
	delete[] deck.cards;
}

// Deals cards to a hand from a deck
void deal(CardArray & deck, CardArray & hand){ // Says to use constant but doesnt work if u do
	hand.cards[hand.currentCards] = deck.cards[deck.currentCards - 1];
	deck.currentCards--;
	hand.currentCards++;
}

// Tallies scores of a hand using values
int scoreCheck(CardArray deck){
	int score = 0;
	for(int i = 0; i <= deck.currentCards; i++){
		score += deck.cards[i].value;
	}
	return score;
}

// Prints all cards of a hand (Does not have same formatting as printDeck)
void printCards(CardArray deck){
	for(int i = 0; i < deck.maxCards; i++){
		cout << setw(4) << deck.cards[i].description;
	}
}

// Checks for any aces and changes value of an ace card from 11 to 1
// if the score exceeds 21 because of it
void aceChange(CardArray & deck){
	for(int i = 0; i < deck.currentCards; i++){
		if(scoreCheck(deck) > BLACKJACK){
			if(deck.cards[i].value == 11){
				deck.cards[i].value = 1;
			}
		}
	}
}

// Prints advice based on different scenarios from Bycicle website
void advice(CardArray dealerHand, CardArray playerHand){
	// Categories for card values
	int goodHigh = 11;
	int goodLow = 7;
	int poorHigh = 6;
	int poorLow = 4;
	int fairHigh = 3;
	int fairLow = 2;

	int reasonableHigh = 17;

	if(playerHand.currentCards == 2){
		if(scoreCheck(playerHand) < reasonableHigh){
			if(dealerHand.cards[0].value >= goodLow && dealerHand.cards[0].value <= goodHigh){
				cout << "\n*Hint*: You should keep drawing until your score is above 17, because the dealer has a high chance of ending with a high score!\n" << endl;
			}
			else if(dealerHand.cards[0].value >= poorLow && dealerHand.cards[0].value <= poorHigh){
				cout << "\n*Hint*: You should only draw until your score is 12 or higher, because the dealer will likely draw three cards total, and will most likely bust!\n" << endl;
			}
			else if(dealerHand.cards[0].value >= fairLow && dealerHand.cards[0].value <= fairHigh){
				cout << "\n*Hint*: You should only draw until your score is 13 or higher, because you can gain a high score without a high chance of bust!\n" << endl;
			}
			else if(playerHand.cards[0].rank == 1 || playerHand.cards[1].rank == 1){
				cout << "\n*Hint*: You have a Soft Hand! Keep hitting until you reach a score of 18, because your ace will be counted as a 1 if you will bust!\n" << endl;
			}
		}
		if(scoreCheck(playerHand) >= reasonableHigh){
			cout << "\n*Hint*: You're close to 21! You should stand, because you have a high chance of bust if you hit.\n" << endl;
		}
	}
	else if(scoreCheck(playerHand) >= reasonableHigh){
		cout << "\n*Hint*: You're close to 21! You should stand, because you have a high chance of bust if you hit.\n" << endl;
	}
}

// Refills a deck by creating a new one and assigning its value to it
void refillDeck(CardArray & deck){
	if(deck.currentCards == 0){
		CardArray newDeck;
		getNewDeck(newDeck);
		shuffleDeck(newDeck);
		deck = newDeck;
	}
}