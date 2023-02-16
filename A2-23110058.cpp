#include <iostream>
#include <string>
#include<stdlib.h>
#include <time.h>
#include <array>
using namespace std;
const int TOTAL_CARDS = 52;
string SUITS[4] = { "D", "H", "C", "S" }; //diamond, heart, club, spade
string RANK[13] = { "A", "2", "3", "4", "5", "6", "7","8", "9", "T", "J", "Q", "K" };

//CARD STRUCT HERE
struct Card {
	string suit;
	string rank;
	string color;
	Card();
	Card(string suit, string rank);
	void setcolor();
};
Card::Card(string s, string r) {
	suit = s;
	rank = r;
}

Card::Card() {
	suit = "";
	rank = "";
}

void Card::setcolor() {
	if (suit == "D" or suit == "H") {
		color = "red";
	}
	else {
		color = "black";
	}

}

//CARD DECK HERE
struct CardDeck {
	Card* deck;
	CardDeck();
	void create_deck();
	void shuffle_deck();
};

CardDeck::CardDeck() {
	deck = new Card[TOTAL_CARDS];
}

void CardDeck::create_deck() {
	int switch_suit = 0;
	int current_card_num = 0;
	string suit;
	string rank;
	for (int i = 0; i < TOTAL_CARDS; i++) {
		suit = SUITS[switch_suit];
		rank = RANK[current_card_num];
		Card c = Card(suit, rank);
		c.setcolor();
		deck[i] = c;
		//cout <<suit <<rank << endl;
		if (current_card_num == 12) {
			switch_suit++;
			current_card_num = 0;
		}
		else {
			current_card_num++;
		}
	}
	// for (int k = 0; k < TOTAL_CARDS; k++) {
	 //	cout <<deck[k].suit << deck[k].rank << endl;

   //}
}

void CardDeck::shuffle_deck() {
	srand(time(NULL));
	for (int i = TOTAL_CARDS - 1; i > 0; i--) {
		int r = rand() % (i + 1);
		Card temp = deck[i];
		Card temp2 = deck[r];
		deck[i] = temp2;
		deck[r] = temp;

	}
}
struct Tableu {
	Tableu();
	int size;
	Card* cards;
	void resize(int o, int n);
};

Tableu::Tableu() {
	cards = new Card[7];
	size = 7;
}

void Tableu::resize(int o, int n) {
	int t = 0;
	size = n;
	if (n > o) {
		t = n;
		n = o;
		o = t;
	}
	Card* temp = new Card[size];
	for (int i = 0; i < n; i++) {
		temp[i] = cards[i];
	}
	cards = temp;
}


struct Game {
	Game();
	Card* free_cells;
	Card* home_slot1;
	int slot_one_size;
	Card* home_slot2;
	int slot_two_size;
	Card* home_slot3;
	int slot_three_size;
	Card* home_slot4;
	int slot_four_size;
	int occupied_free_slots;
	int occupied_home_slots;
	Tableu one;
	Tableu two;
	Tableu three;
	Tableu four;
	Tableu five;
	Tableu six;
	Tableu seven;
	Tableu eight;
	void printgame();
	void remove_top_card(int s);
	void add_card(Card c, int s);
	bool legal_move(int type, int source, int dest);
	Tableu return_tableu(int n);

};

Game::Game() {
	CardDeck d;
	d.create_deck();
	d.shuffle_deck();
	free_cells = new Card[4];
	occupied_free_slots = 0;
	home_slot1 = new Card[13];
	home_slot2 = new Card[13];
	home_slot3 = new Card[13];
	home_slot4 = new Card[13];
	slot_one_size = 0;
	slot_two_size = 0;
	slot_three_size = 0;
	slot_four_size = 0;
	occupied_home_slots = 0;
	d.shuffle_deck();
	int i = 0;
	five.resize(7, 6);
	six.resize(7, 6);
	seven.resize(7, 6);
	eight.resize(7, 6);
	for (int index = 0; index < 7; index++) {
		one.cards[index] = d.deck[i];
		cout << d.deck[i].suit << d.deck[i].rank << endl;
		two.cards[index] = d.deck[i + 1];
		cout << d.deck[i + 1].suit << d.deck[i + 1].rank << endl;
		three.cards[index] = d.deck[i + 2];
		cout << d.deck[i + 2].suit << d.deck[i + 2].rank << endl;
		four.cards[index] = d.deck[i + 3];
		cout << d.deck[i + 3].suit << d.deck[i + 3].rank << endl;
		i = i + 4;
	}
	for (int index = 0; index < 6; index++) {
		five.cards[index] = d.deck[i];
		six.cards[index] = d.deck[i + 1];
		seven.cards[index] = d.deck[i + 2];
		eight.cards[index] = d.deck[i + 3];
		i = i + 4;
	}


}
void Game::add_card(Card c, int col) {
	if (col == 1) {
		int temp_size;
		temp_size = one.size + 1;
		one.resize(one.size, temp_size);
		temp_size--;
		one.cards[temp_size] = c;
	}
	else if (col == 2) {
		int temp_size;
		temp_size = two.size + 1;
		two.resize(two.size, temp_size);
		temp_size--;
		two.cards[temp_size] = c;
	}
	else if (col == 3) {
		int temp_size;
		temp_size = three.size + 1;
		three.resize(three.size, temp_size);
		temp_size--;
		three.cards[temp_size] = c;
	}
	else if (col == 4) {
		int temp_size;
		temp_size = four.size + 1;
		four.resize(four.size, temp_size);
		temp_size--;
		four.cards[temp_size] = c;
	}
	else if (col == 5) {
		int temp_size;
		temp_size = five.size + 1;
		five.resize(five.size, temp_size);
		temp_size--;
		five.cards[temp_size] = c;
	}
	else if (col == 6) {
		int temp_size;
		temp_size = six.size + 1;
		six.resize(six.size, temp_size);
		temp_size--;
		six.cards[temp_size] = c;
	}
	else if (col == 7) {
		int temp_size;
		temp_size = seven.size + 1;
		seven.resize(seven.size, temp_size);
		temp_size--;
		seven.cards[temp_size] = c;
	}
	else {
		int temp_size;
		temp_size = eight.size + 1;
		eight.resize(eight.size, temp_size);
		temp_size--;
		eight.cards[temp_size] = c;
	}
}
void Game::remove_top_card(int col) {
	if (col == 1) {
		int temp_size;
		temp_size = one.size - 1;
		one.resize(one.size, temp_size);
	}
	else if (col == 2) {
		int temp_size;
		temp_size = two.size - 1;
		two.resize(two.size, temp_size);
	}
	else if (col == 3) {
		int temp_size;
		temp_size = three.size - 1;
		three.resize(three.size, temp_size);
	}
	else if (col == 4) {
		int temp_size;
		temp_size = four.size - 1;
		four.resize(four.size, temp_size);
	}
	else if (col == 5) {
		int temp_size;
		temp_size = five.size - 1;
		five.resize(five.size, temp_size);
	}
	else if (col == 6) {
		int temp_size;
		temp_size = six.size - 1;
		six.resize(six.size, temp_size);
	}
	else if (col == 7) {
		int temp_size;
		temp_size = seven.size - 1;
		seven.resize(seven.size, temp_size);
	}
	else if (col == 8) {
		int temp_size;
		temp_size = eight.size - 1;
		eight.resize(eight.size, temp_size);
	}
}
void Game::printgame() {
	//printing free cells
	cout << "FREE CELLS" << endl;
	cout << "----------------------------------------------------" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "|     " << free_cells[i].suit << free_cells[i].rank << "      ";

	}
	cout << endl;
	cout << "----------------------------------------------------" << endl;
	//printing home 
	cout << "          ";
	cout << "HOME CELLS" << endl;
	for (int i = 0; i < 13; i++) {
		cout << "|      " << home_slot1[i].suit << home_slot1[i].rank << "|    ";
		cout << "     " << home_slot2[i].suit << home_slot2[i].rank << "|    ";
		cout << "     " << home_slot3[i].suit << home_slot3[i].rank << "|    ";
		cout << "   " << home_slot4[i].suit << home_slot4[i].rank << "|    ";
		cout << endl;
	}
	cout << endl << "---------------------------------------------------" << endl << endl << endl;
	//printing tableus
	cout << one.size << endl;
	cout << two.size << endl;
	cout << three.size << endl;
	cout << four.size << endl;
	cout << five.size << endl;
	cout << six.size << endl;
	cout << seven.size << endl;
	cout << eight.size << endl;
	int max = 0;
	int arr[8] = { one.size, two.size, three.size, four.size, five.size, six.size, seven.size, eight.size };
	max = arr[0];
	for (int el = 0; el < 8; el++) {
		if (arr[el] > max) {
			max = arr[el];
		}
	}
	for (int i = 0; i < max; i++) {
		cout << "--------------------------------------------------------------" << endl;
		if (one.size >= i + 1) {
			cout << "|" << one.cards[i].suit << one.cards[i].rank << "      |";
		}
		else {
			cout << "|        |";
		}
		if (two.size >= i + 1) {
			cout << "|" << two.cards[i].suit << two.cards[i].rank << "      |";
		}
		else {
			cout << "|        |";
		}
		if (three.size >= i + 1) {
			cout << "|" << three.cards[i].suit << three.cards[i].rank << "      |";
		}
		else {
			cout << "|        |";
		}
		if (four.size >= i + 1) {
			cout << "|" << four.cards[i].suit << four.cards[i].rank << "      |";
		}
		else {
			cout << "|        |";
		}
		if (five.size >= i + 1) {
			cout << "|" << five.cards[i].suit << five.cards[i].rank << "      |";
		}
		else {
			cout << "|        |";
		}
		if (six.size >= i + 1) {
			cout << "|" << six.cards[i].suit << six.cards[i].rank << "      |";
		}
		else {
			cout << "|        |";
		}
		if (seven.size >= i + 1) {
			cout << "|" << seven.cards[i].suit << seven.cards[i].rank << "      |";
		}
		else {
			cout << "|        |";
		}
		if (eight.size >= i + 1) {
			cout << "|" << eight.cards[i].suit << eight.cards[i].rank << "        |";
		}
		else {
			cout << "|        |";
		}
		cout << endl;
	}

}

Tableu Game::return_tableu(int col) {
	if (col == 1) {
		return one;
	}
	else if (col == 2) {
		return two;
	}
	else if (col == 3) {
		return three;
	}
	else if (col == 4) {
		return four;
	}
	else if (col == 5) {
		return five;
	}
	else if (col == 6) {
		return six;
	}
	else if (col == 7) {
		return seven;
	}
	else {
		return eight;
	}
}



//MAIN FUNCTION HERE
int main() {
	Game game;
	while (1) {
		game.printgame();
		int option;
		if (game.slot_one_size == 13 && game.slot_two_size == 13 && game.slot_three_size == 13 && game.slot_four_size == 13) {
			cout << "You won!";
		}
		cout << "Enter 1 for column to column move: " << endl;
		cout << "Enter 2 for column to free-cell move: " << endl;
		cout << "Enter 3 for free-cell to column move: " << endl;
		cout << "Enter 4 for column to home move: " << endl;
		cout << "Enter 5 for free-cell to home move: " << endl;
		cin >> option;
		if (option == 1) {
			int source, destination, cards;
			cout << "Enter the column number as source:" << endl;
			cin >> source;
			cout << "Enter the column number as destination" << endl;
			cin >> destination;
			//	cout << "Enter the number of cards to be moved"<<endl;
			//	cin >> cards;
			Tableu s = game.return_tableu(source);
			Tableu d = game.return_tableu(destination);
			int source_rank, dest_rank;
			Card src = s.cards[s.size - 1];
			Card dst = d.cards[d.size - 1];
			cout << src.suit << src.rank << endl;
			cout << dst.suit << dst.rank << endl;
			for (int k = 0; k < 13; k++) {
				if (src.rank == RANK[k]) {
					source_rank = k + 1;
				}
				if (dst.rank == RANK[k]) {
					dest_rank = k + 1;
				}
			}
			if (source_rank == dest_rank - 1) {  //immediate descendant
				if (src.color != dst.color) { //alternating color
					game.remove_top_card(source);
					game.add_card(src, destination);
				}
			}
			else {
				cout << "illegal move";
			}
		}
		else if (option == 2) {
			int source, destination, cards;
			cout << "Enter the column number as source:" << endl;
			cin >> source;
			Tableu s = game.return_tableu(source);
			Card src = s.cards[(s.size) - 1];
			if (game.occupied_free_slots == 4 || src.rank == "A") {
				cout << "Illegal move" << endl;
			}
			else {
				game.free_cells[game.occupied_free_slots] = src;
				game.occupied_free_slots = game.occupied_free_slots + 1;
				game.remove_top_card(source);
			}

		}
		else if (option == 3) {
			int source, destination, cards;
			cout << "Enter the column number from free cells as source:" << endl;
			cin >> source;
			cout << "Enter the column number from tableu as destination:" << endl;
			cin >> destination;
			Card src = game.free_cells[source - 1];
			Tableu dest = game.return_tableu(destination);
			Card dst = dest.cards[dest.size - 1];
			int source_rank, dest_rank;
			for (int k = 0; k < 13; k++) {
				if (src.rank == RANK[k]) {
					source_rank = k + 1;
				}
				if (dst.rank == RANK[k]) {
					dest_rank = k + 1;
				}
			}
			if (source_rank == dest_rank - 1) {  //immediate descendant
				if (src.color != dst.color) { //alternating color
					//remove card from free cells
					Card* temp = new Card[4];
					for (int j = 0; j < game.occupied_free_slots; j++) {
						Card k;
						k = game.free_cells[j];
						if (k.rank != src.rank && k.suit != src.suit) {
							temp[j] = game.free_cells[j];
						}
					}
					game.free_cells = temp;
					game.occupied_free_slots = game.occupied_free_slots - 1;
					//add card to tableu
					game.add_card(src, destination);
				}
			}
			else {
				cout << "illegal move";
			}

		}
		else if (option == 4) {
			int source, destination, cards;
			cout << "Enter the column number from tableu cells as source:" << endl;
			cin >> source;
			cout << "Enter the column number from home as destination:" << endl;
			cin >> destination;
			Tableu s = game.return_tableu(source);
			Card src = s.cards[(s.size) - 1];
			int source_rank;
			int dest_rank;
			if (destination == 1) {
				if (game.slot_one_size == 0 && src.rank == "A") {
					game.home_slot1[0] = src;
					game.slot_one_size++;
					game.remove_top_card(source);
				}
				else if (game.home_slot1[game.slot_one_size - 1].suit == src.suit) {
					for (int k = 0; k < 13; k++) {
						if (src.rank == RANK[k]) {
							source_rank = k + 1;
						}
						if (game.home_slot1[game.slot_one_size - 1].rank == RANK[k]) {
							dest_rank = k + 1;
						}
					}
					if (source_rank == dest_rank + 1) {
						game.home_slot1[game.slot_one_size] = src;
						game.slot_one_size++;
						game.remove_top_card(source);
					}
				}
				else {
					cout << "illegal move";
				}
			}
			else if (destination == 2) {
				if (game.slot_two_size == 0 && src.rank == "A") {
					game.home_slot2[0] = src;
					game.slot_two_size++;
					game.remove_top_card(source);
				}
				else if (game.home_slot2[game.slot_two_size - 1].suit == src.suit) {
					for (int k = 0; k < 13; k++) {
						if (src.rank == RANK[k]) {
							source_rank = k + 1;
						}
						if ((game.home_slot2[game.slot_two_size - 1].rank) == RANK[k]) {
							dest_rank = k + 1;
						}
					}
					if (source_rank == dest_rank + 1) {
						game.home_slot2[game.slot_two_size] = src;
						game.slot_two_size++;
						game.remove_top_card(source);
					}
				}
				else {
					cout << "illegal move";
				}
			}
			else if (destination == 3) {
				if (game.slot_three_size == 0 && src.rank == "A") {
					game.home_slot3[0] = src;
					game.slot_three_size++;
					game.remove_top_card(source);
				}
				else if (game.home_slot3[game.slot_three_size - 1].suit == src.suit) {
					for (int k = 0; k < 13; k++) {
						if (src.rank == RANK[k]) {
							source_rank = k + 1;
						}
						if ((game.home_slot3[game.slot_three_size - 1].rank) == RANK[k]) {
							dest_rank = k + 1;
						}
					}
					if (source_rank == dest_rank + 1) {
						game.home_slot3[game.slot_three_size] = src;
						game.slot_three_size++;
						game.remove_top_card(source);
					}
				}
				else {
					cout << "illegal move";
				}
			}
			else if (destination == 4) {
				if (game.slot_four_size == 0 && src.rank == "A") {
					game.home_slot4[0] = src;
					game.slot_four_size++;
					game.remove_top_card(source);
				}
				else if (game.home_slot4[game.slot_four_size - 1].suit == src.suit) {
					for (int k = 0; k < 13; k++) {
						if (src.rank == RANK[k]) {
							source_rank = k + 1;
						}
						if ((game.home_slot4[game.slot_four_size - 1].rank) == RANK[k]) {
							dest_rank = k + 1;
						}
					}
					if (source_rank == dest_rank + 1) {
						game.home_slot4[game.slot_four_size] = src;
						game.slot_four_size++;
						game.remove_top_card(source);
					}
				}
				else {
					cout << "illegal move";
				}
			}
		}
		else if (option == 5) {
			int source, destination, cards;
			cout << "Enter the column number from free cells as source:" << endl;
			cin >> source;
			cout << "Enter the column number from home as destination:" << endl;
			cin >> destination;
			Card src = game.free_cells[source - 1];
			int source_rank;
			int dest_rank;
			if (destination == 1) {
				if (game.slot_one_size == 0 && src.rank == "A") {
					game.home_slot1[0] = src;
					game.slot_one_size++;
					Card* temp = new Card[4];
					for (int j = 0; j < game.occupied_free_slots; j++) {
						Card k;
						k = game.free_cells[j];
						//dont add back in temp what you want to remove
						if (k.rank != src.rank && k.suit != src.suit) {
							temp[j] = game.free_cells[j];
						}
					}
					game.free_cells = temp;
					game.occupied_free_slots = game.occupied_free_slots - 1;
				}
				else if (game.home_slot1[game.slot_one_size - 1].suit == src.suit) {
					for (int k = 0; k < 13; k++) {
						if (src.rank == RANK[k]) {
							source_rank = k + 1;
						}
						if (game.home_slot1[game.slot_one_size - 1].rank == RANK[k]) {
							dest_rank = k + 1;
						}
					}
					if (source_rank == dest_rank + 1) {
						game.home_slot1[game.slot_one_size] = src;
						game.slot_one_size++;
						Card* temp = new Card[4];
						for (int j = 0; j < game.occupied_free_slots; j++) {
							Card k;
							k = game.free_cells[j];
							//dont add back in temp what you want to remove
							if (k.rank != src.rank && k.suit != src.suit) {
								temp[j] = game.free_cells[j];
							}
						}
						game.free_cells = temp;
						game.occupied_free_slots = game.occupied_free_slots - 1;
					}
				}
				else {
					cout << "illegal move";
				}
			}
			else if (destination == 2) {
				if (game.slot_two_size == 0 && src.rank == "A") {
					game.home_slot2[0] = src;
					game.slot_two_size++;
					Card* temp = new Card[4];
					for (int j = 0; j < game.occupied_free_slots; j++) {
						Card k;
						k = game.free_cells[j];
						//dont add back in temp what you want to remove
						if (k.rank != src.rank && k.suit != src.suit) {
							temp[j] = game.free_cells[j];
						}
					}
					game.free_cells = temp;
					game.occupied_free_slots = game.occupied_free_slots - 1;
				}
				else if (game.home_slot2[game.slot_two_size - 1].suit == src.suit) {
					for (int k = 0; k < 13; k++) {
						if (src.rank == RANK[k]) {
							source_rank = k + 1;
						}
						if ((game.home_slot2[game.slot_two_size - 1].rank) == RANK[k]) {
							dest_rank = k + 1;
						}
					}
					if (source_rank == dest_rank + 1) {
						game.home_slot2[game.slot_two_size] = src;
						game.slot_two_size++;
						Card* temp = new Card[4];
						for (int j = 0; j < game.occupied_free_slots; j++) {
							Card k;
							k = game.free_cells[j];
							//dont add back in temp what you want to remove
							if (k.rank != src.rank && k.suit != src.suit) {
								temp[j] = game.free_cells[j];
							}
						}
						game.free_cells = temp;
						game.occupied_free_slots = game.occupied_free_slots - 1;
					}
				}
				else {
					cout << "illegal move";
				}
			}
			else if (destination == 3) {
				if (game.slot_three_size == 0 && src.rank == "A") {
					game.home_slot3[0] = src;
					game.slot_three_size++;
					Card* temp = new Card[4];
					for (int j = 0; j < game.occupied_free_slots; j++) {
						Card k;
						k = game.free_cells[j];
						//dont add back in temp what you want to remove
						if (k.rank != src.rank && k.suit != src.suit) {
							temp[j] = game.free_cells[j];
						}
					}
					game.free_cells = temp;
					game.occupied_free_slots = game.occupied_free_slots - 1;
				}
				else if (game.home_slot3[game.slot_three_size - 1].suit == src.suit) {
					for (int k = 0; k < 13; k++) {
						if (src.rank == RANK[k]) {
							source_rank = k + 1;
						}
						if ((game.home_slot3[game.slot_three_size - 1].rank) == RANK[k]) {
							dest_rank = k + 1;
						}
					}
					if (source_rank == dest_rank + 1) {
						game.home_slot3[game.slot_three_size] = src;
						game.slot_three_size++;
						Card* temp = new Card[4];
						for (int j = 0; j < game.occupied_free_slots; j++) {
							Card k;
							k = game.free_cells[j];
							//dont add back in temp what you want to remove
							if (k.rank != src.rank && k.suit != src.suit) {
								temp[j] = game.free_cells[j];
							}
						}
						game.free_cells = temp;
						game.occupied_free_slots = game.occupied_free_slots - 1;
					}
				}
				else {
					cout << "illegal move";
				}
			}
			else if (destination == 4) {
				if (game.slot_four_size == 0 && src.rank == "A") {
					game.home_slot4[0] = src;
					game.slot_four_size++;
					Card* temp = new Card[4];
					for (int j = 0; j < game.occupied_free_slots; j++) {
						Card k;
						k = game.free_cells[j];
						//dont add back in temp what you want to remove
						if (k.rank != src.rank && k.suit != src.suit) {
							temp[j] = game.free_cells[j];
						}
					}
					game.free_cells = temp;
					game.occupied_free_slots = game.occupied_free_slots - 1;
				}
				else if (game.home_slot4[game.slot_four_size - 1].suit == src.suit) {
					for (int k = 0; k < 13; k++) {
						if (src.rank == RANK[k]) {
							source_rank = k + 1;
						}
						if ((game.home_slot4[game.slot_four_size - 1].rank) == RANK[k]) {
							dest_rank = k + 1;
						}
					}
					if (source_rank == dest_rank + 1) {
						game.home_slot4[game.slot_four_size] = src;
						game.slot_four_size++;
						Card* temp = new Card[4];
						for (int j = 0; j < game.occupied_free_slots; j++) {
							Card k;
							k = game.free_cells[j];
							//dont add back in temp what you want to remove
							if (k.rank != src.rank && k.suit != src.suit) {
								temp[j] = game.free_cells[j];
							}
						}
						game.free_cells = temp;
						game.occupied_free_slots = game.occupied_free_slots - 1;
					}
				}
				else {
					cout << "illegal move";
				}
			}
		}
	}

	return 0;
}