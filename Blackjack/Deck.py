from random import shuffle
from Card import Card
from itertools import product


class Deck:

    def __init__(self):
        # fill deck with 52 cards
        self.cards = []

        ranks = list(range(2, 11))
        ranks.extend(['Jack', 'Queen', 'King', 'Ace'])
        suits = ['Clubs', 'Diamonds', 'Hearts', 'Spades']

        for rank, suit in product(ranks, suits):
            self.cards.append(Card(rank, suit))

    def shuffle(self):
        """
        Shuffles the cards in the deck
        """
        shuffle(self.cards)

    def deal_card(self):
        """
        Deals top card of the deck
        """
        return self.cards.pop()

    def __str__(self):
        deck_string = '\n'
        for card in self.cards:
            deck_string += str(card) + '\n'

        return deck_string
