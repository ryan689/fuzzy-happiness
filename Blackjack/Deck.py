from random import shuffle
from Card import Card


class Deck():

    def __init__(self):
        # fill deck with 52 cards
        self.deck = []

        # Clubs
        for rank in range(2, 11):
            self.deck.append(Card(rank, 'Clubs'))

        self.deck.append(Card('Jack', 'Clubs'))
        self.deck.append(Card('Queen', 'Clubs'))
        self.deck.append(Card('King', 'Clubs'))
        self.deck.append(Card('Ace', 'Clubs'))

        # Diamonds
        for rank in range(2, 11):
            self.deck.append(Card(rank, 'Diamonds'))

        self.deck.append(Card('Jack', 'Diamonds'))
        self.deck.append(Card('Queen', 'Diamonds'))
        self.deck.append(Card('King', 'Diamonds'))
        self.deck.append(Card('Ace', 'Diamonds'))

        # Hearts
        for rank in range(2, 11):
            self.deck.append(Card(rank, 'Hearts'))

        self.deck.append(Card('Jack', 'Hearts'))
        self.deck.append(Card('Queen', 'Hearts'))
        self.deck.append(Card('King', 'Hearts'))
        self.deck.append(Card('Ace', 'Hearts'))

        # Spades
        for rank in range(2, 11):
            self.deck.append(Card(rank, 'Spades'))

        self.deck.append(Card('Jack', 'Spades'))
        self.deck.append(Card('Queen', 'Spades'))
        self.deck.append(Card('King', 'Spades'))
        self.deck.append(Card('Ace', 'Spades'))

    def shuffle(self):
        """
        Shuffles the cards in the deck
        """
        shuffle(self.deck)

    def deal_card(self):
        """
        Deals top card of the deck
        """
        return self.deck.pop()

    def __str__(self):
        deck_string = '\n'
        for card in self.deck:
            deck_string += str(card) + '\n'

        return deck_string
