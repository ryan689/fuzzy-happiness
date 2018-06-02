from Hand import Hand


class Player():

    def __init__(self, name):
        self.name = name
        self.chips = 0
        self.bet = 0
        self.hands = []

    def add_hand(self, hand=Hand()):
        self.hands.append(hand)

    def has_active_hand(self):
        for hand in self.hands:
            if not hand.finished:
                return True
        return False

    def has_nonbusted_hand(self):
        for hand in self.hands:
            if not hand.is_busted():
                return True
        return False

    def set_chips(self, chips):
        self.chips = chips

    def set_bet(self, bet):
        if self.chips >= bet:
            self.bet = bet

    def __str__(self):
        return self.name
