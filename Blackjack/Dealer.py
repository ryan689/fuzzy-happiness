from HandHolder import HandHolder


class Dealer(HandHolder):

    def __init__(self):
        super(Dealer, self).__init__('Dealer')

    def __str__(self):
        result = super(Dealer, self).__str__()

        if self.hands:
            result += self.hands[0].__str__(0)

        return result
