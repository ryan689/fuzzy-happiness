class Card:

    def __init__(self, rank, suit):
        self.rank = rank
        self.suit = suit

    def value(self):
        """
        :return: value of the card in the game of Blackjack
        """
        if self.rank == 'Ace':
            return 11
        elif self.rank == 'King' or self.rank == 'Queen' or self.rank == 'Jack':
            return 10
        else:
            return self.rank

    def __str__(self):
        return f'{self.rank} of {self.suit}'
