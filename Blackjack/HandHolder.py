from Hand import Hand


class HandHolder:

    def __init__(self, name):
        self.name = name
        self.hands = []

    def add_hand(self, hand=Hand()):
        self.hands.append(hand)

    def has_blackjack(self):
        for hand in self.hands:
            if hand.is_blackjack():
                return True
        return False

    def has_active_hand(self):
        for hand in self.hands:
            if not hand.finished:
                return True
        return False

    def has_non_busted_hand(self):
        for hand in self.hands:
            if not hand.is_busted():
                return True
        return False

    def __len__(self):
        return len(self.hands)

    def __str__(self):
        return self.name + '\n---------\n'
