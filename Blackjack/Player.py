from HandHolder import HandHolder


class Player(HandHolder):

    def __init__(self, name):
        super(Player, self).__init__(name)
        self.chips = 0
        self.bet = 0

    def set_chips(self, chips):
        self.chips = chips

    def set_bet(self, bet):
        if self.chips >= bet:
            self.bet = bet

    def __str__(self):
        result = super(Player, self).__str__()
        for index, hand in enumerate(self.hands):
            result += 'Hand ' + str(index + 1) + ':\n' + hand.__str__(len(hand))

        return result
