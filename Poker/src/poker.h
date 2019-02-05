/*
 * pokergame.h
 *
 *  Created on: Feb 5, 2019
 *      Author: emartindale
 */

#ifndef SRC_POKER_H_
#define SRC_POKER_H_



#include <iostream>
#include <array>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
#include <array>

enum CardSuit
{
	SUIT_CLUB,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPADE,
	MAX_SUITS
};

enum CardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANKS
};

class CardClass
{
public:
	CardRank m_rank;
	CardSuit m_suit;
	void printCard();
	int getCardValue();
};

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max);
void swapCard(CardClass &card_a, CardClass &card_b);

class DeckClass
{
public:
	std::array<CardClass, 52> m_deck;
	using index_t = std::array<CardClass, 52>::size_type;
	DeckClass();
	void printDeck();
	void shuffleDeck();
};



#endif /* SRC_POKER_H_ */
