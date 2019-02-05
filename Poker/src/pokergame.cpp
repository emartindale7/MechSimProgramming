

#include "poker.h"


void CardClass::printCard()
{
	switch (m_rank)
	{
		case RANK_2:		std::cout << '2'; break;
		case RANK_3:		std::cout << '3'; break;
		case RANK_4:		std::cout << '4'; break;
		case RANK_5:		std::cout << '5'; break;
		case RANK_6:		std::cout << '6'; break;
		case RANK_7:		std::cout << '7'; break;
		case RANK_8:		std::cout << '8'; break;
		case RANK_9:		std::cout << '9'; break;
		case RANK_10:		std::cout << 'T'; break;
		case RANK_JACK:		std::cout << 'J'; break;
		case RANK_QUEEN:	std::cout << 'Q'; break;
		case RANK_KING:		std::cout << 'K'; break;
		case RANK_ACE:		std::cout << 'A'; break;
	}

	switch (m_suit)
	{
		case SUIT_CLUB:		std::cout << 'C'; break;
		case SUIT_DIAMOND:	std::cout << 'D'; break;
		case SUIT_HEART:	std::cout << 'H'; break;
		case SUIT_SPADE:	std::cout << 'S'; break;
	}
}
int CardClass::getCardValue()
{
	switch (m_rank)
	{
	case RANK_2:		return 2;
	case RANK_3:		return 3;
	case RANK_4:		return 4;
	case RANK_5:		return 5;
	case RANK_6:		return 6;
	case RANK_7:		return 7;
	case RANK_8:		return 8;
	case RANK_9:		return 9;
	case RANK_10:		return 10;
	case RANK_JACK:		return 10;
	case RANK_QUEEN:	return 10;
	case RANK_KING:		return 10;
	case RANK_ACE:		return 11;
	}

	return 0;
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
 	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void swapCard(CardClass &card_a, CardClass &card_b)
{
	CardClass temp = card_a;
	card_a = card_b;
	card_b = temp;
}

DeckClass::DeckClass()
{
		index_t card = 0;

		for (int suit = 0; suit < MAX_SUITS; ++suit)
		for (int rank = 0; rank < MAX_RANKS; ++rank)
		{
			m_deck[card].m_suit = static_cast<CardSuit>(suit);
			m_deck[card].m_rank = static_cast<CardRank>(rank);
			++card;
		}
}

void DeckClass::printDeck()
	{
		for (CardClass card : m_deck)
		{
			card.printCard();
			std::cout << ' ';
		}

		std::cout << '\n';
	}

void DeckClass::shuffleDeck()
{
	// Step through each card in the deck
	for (index_t index = 0; index < 52; ++index)
	{
		// Pick a random card, any card
		index_t swapIndex = getRandomNumber(0, 51);
		// Swap it with the current card
		swapCard(m_deck[index], m_deck[swapIndex]);
	}
}

class BlackJack
{
private:
	bool m_win = false; //boolean to check to see if you won
	int m_playerTotal = 0;
	int m_dealerTotal = 0;
	int m_cardnum = 0;
public:
	DeckClass m_deck;


BlackJack(){m_deck.shuffleDeck();}
char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}
bool getWin(){return m_win;}
void playBlackjack()
{
	// Set up the initial game state

	// Deal the dealer one card
	m_dealerTotal += m_deck.m_deck[m_cardnum].getCardValue();
	m_cardnum++;
	std::cout << "The dealer is showing: " << m_dealerTotal << '\n';

	// Deal the player two cards
	m_playerTotal += m_deck.m_deck[m_cardnum].getCardValue();
	m_cardnum++;
	m_playerTotal += m_deck.m_deck[m_cardnum].getCardValue();
	m_cardnum++;

	// Player goes first
	while (true) // infinite loop (until we break or return)
	{
		std::cout << "You have: " << m_playerTotal << '\n';

		// See if the player has busted
		if (m_playerTotal > 21)
		{
			m_win = false;
			return;
		}

		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		m_playerTotal += m_deck.m_deck[m_cardnum].getCardValue();
		m_cardnum++;
	}

	// If player hasn't busted, dealer goes until he has at least 17 points
	while (m_dealerTotal < 17)
	{
		m_dealerTotal += m_deck.m_deck[m_cardnum].getCardValue();
		m_cardnum++;
		std::cout << "The dealer now has: " << m_dealerTotal << '\n';
	}

	// If dealer busted, player wins
	if (m_dealerTotal > 21)
	{
		m_win = true;
		return;
	}
		m_win = (m_playerTotal > m_dealerTotal);
	return;
}
};

int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	BlackJack blackjackgame;
	blackjackgame.playBlackjack();

	if (blackjackgame.getWin())
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";

	return 0;
}
