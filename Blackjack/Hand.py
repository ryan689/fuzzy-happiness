class Hand():

    def __init__(self, split=False):
        self.cards = []
        self.split = split
        self.surrendered = False
        self.finished = False

    def add_card(self, card):
        self.cards.append(card)

    def remove_card(self):
        return self.cards.pop()

    def hand_value(self):
        total_hand_value = 0
        aces = 0

        # add up the values of the card in hand
        for card in self.cards:
            total_hand_value += card.value()
            if card.rank == 'Ace':
                aces += 1

        # allow aces to be 1, instead of 11, if the hand value is over 21
        for _ in range(aces):
            if total_hand_value > 21:
                total_hand_value -= 10

        return total_hand_value

    def has_blackjack(self):
        return len(self.cards) == 2 and self.hand_value() == 21

    def is_busted(self):
        return self.hand_value() > 21

    def set_split(self, split):
        self.split = split

    def set_finished(self, finished):
        self.finished = finished

    def is_finished_playing(self):
        return self.finished

    def surrender_is_valid(self):
        return len(self.cards) == 2 and not self.split

    def split_is_valid(self):
        return len(self.cards) == 2 and self.cards[0].value == self.cards[1].value

    def __str__(self):
        hand = f'{self.cards}\'s hand:\n------------\n'
        for card in self.cards:
            hand += str(card) + '\n'

        return hand + '\n'
