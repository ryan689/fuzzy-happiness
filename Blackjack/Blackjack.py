import random


class Card(object):

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
        return '{} of {}'.format(self.rank, self.suit)


class Deck(object):

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
        random.shuffle(self.deck)

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


class PlayerHand(object):

    def __init__(self, name, bet, split=False, surrendered=False):
        self.name = name
        self.bet = bet
        self.hand = []
        self.split = split
        self.surrendered = surrendered

    def add_card(self, card):
        self.hand.append(card)

    def remove_card(self, card_number):
        if card_number < len(self.hand):
            return self.hand.pop(card_number)

    def hand_value(self):
        total_hand_value = 0
        aces = 0

        # add up the values of the card in hand
        for card in self.hand:
            total_hand_value += card.value()
            if card.rank == 'Ace':
                aces += 1

        # allow aces to be 1, instead of 11, if the hand value is over 21
        for _ in range(aces):
            if total_hand_value > 21:
                total_hand_value -= 10

        return total_hand_value

    def is_busted(self):
        return self.hand_value() > 21

    def set_surrendered(self, surrendered):
        self.surrendered = surrendered

    def set_split(self, split):
        self.split = split

    def is_split(self):
        """
        :return: True if hand has resulted from a split, False if hand is original hand dealt
        """
        return self.split

    def has_surrendered(self):
        return self.surrendered

    def has_blackjack(self):
        if len(self.hand) != 2:
            return False
        else:
            return self.hand_value() == 21

    def __str__(self):
        hand = "{}'s hand:\n------------\n".format(self.name)
        for card in self.hand:
            hand += str(card) + '\n'

        return hand + '\n'


# welcome
print('\nWelcome To Python Blackjack!\n')
dealer_deck = Deck()
dealer_deck.shuffle()
players = []


# get player's names
print("Enter each player's name, or 'end' to stop entering names")
player_names = []
while True:
    player_name = input("Player {}'s name: ".format(len(player_names) + 1))
    if player_name.lower() == 'end':
        break
    else:
        player_names.append(player_name)


# open file to access bankroll for each player playing
file = open('bankrolls.txt', 'r')
lines = file.readlines()
player_bankrolls = {}
print()
for name in player_names:
    for line in lines:
        bankroll_data = line.split()
        # search for player's name in file
        if name == bankroll_data[0]:
            # read how many chips this player has
            print('Welcome back, {}! Your previous bankroll of {} chips is loaded.'.format(name, bankroll_data[1]))
            player_bankrolls[name] = int(bankroll_data[1])
            break
    else:
        # initialize new player with 1000 chips
        print('Hello, {}! You have been given 1000 chips to start. Good luck!'.format(name))
        player_bankrolls[name] = 1000

file.close()


# ask for bets
print()
while len(players) < len(player_names):
    while True:
        try:
            bet = int(input('{}, how much would you like to bet? '.format(player_names[len(players)])))
        except ValueError:
            print('Please enter a number\n')
        else:
            if bet > player_bankrolls[player_names[len(players)]]:
                print('This bet exceeds your current bankroll of {} chips. Please enter a lower bet.\n'.format
                      (player_bankrolls[player_names[len(players)]]))
            elif bet < 1:
                print('You must bid at least 1 chip')
            else:
                player = PlayerHand(player_names[len(players)], bet)
                players.append(player)
                break


# deal 2 cards to each player, including the dealer
for _ in range(2):
    for player in players:
        card = dealer_deck.deal_card()
        player.add_card(card)

dealer_hand = PlayerHand('Dealer', 0)
for _ in range(2):
    card = dealer_deck.deal_card()
    dealer_hand.add_card(card)

# check for blackjacks
players_finished = []
for index in range(len(players)):
    current_player = players[index]
    if current_player.has_blackjack() and not dealer_hand.has_blackjack():
        print('{} has a blackjack! You win a 3:2 payout of {} chips.\n'.format
              (current_player.name, int(current_player.bet * 1.5)))
        players_finished.append(index)

if not dealer_hand.has_blackjack():
    print("\nDealer's upcard:\n------------")
    print(dealer_hand.hand[0])
else:
    print(dealer_hand)
    print('Dealer has blackjack!')

if not dealer_hand.has_blackjack():
    # allow players to play their hands
    print('\n')
    for index in range(len(players)):
        current_player = players[index]

    while len(players_finished) < len(players):
        for index in range(len(players)):
            if index not in players_finished:
                current_player = players[index]

                # show player hand
                print(current_player)

                # determine which moves are valid
                valid_moves = [(1, 'Hit'), (2, 'Stand'), (3, 'Double')]
                if len(current_player.hand) == 2 and current_player.hand[0].value() == current_player.hand[1].value():
                    valid_moves.append((len(valid_moves) + 1, 'Split'))
                if len(current_player.hand) == 2 and not current_player.is_split():
                    valid_moves.append((len(valid_moves) + 1, 'Surrender'))

                # ask for player's move (hit, stand, double, split, surrender)
                chosen_move = 0
                while True:
                    for valid_move in valid_moves:
                        print('{} - {}'.format(valid_move[0], valid_move[1]))
                    try:
                        chosen_move = int(input(''))
                    except ValueError:
                        print('Please enter a valid move number')
                    else:
                        if chosen_move in [valid_move[0] for valid_move in valid_moves]:
                            break
                        else:
                            print('Please enter a valid move number')

                for valid_move in valid_moves:
                    if valid_move[0] == chosen_move and valid_move[1] == 'Hit':
                        # if player chose to be hit, then deal a card
                        card = dealer_deck.deal_card()
                        current_player.add_card(card)
                        print(current_player)

                    elif valid_move[0] == chosen_move and valid_move[1] == 'Stand':
                        # player is finished taking cards
                        players_finished.append(index)

                    elif valid_move[0] == chosen_move and valid_move[1] == 'Double':
                        # hit with one more card and double bet
                        card = dealer_deck.deal_card()
                        current_player.add_card(card)
                        print('Doubling bet to {}...'.format(current_player.bet * 2))
                        current_player.bet *= 2
                        players_finished.append(index)
                        print(current_player)

                    elif valid_move[0] == chosen_move and valid_move[1] == 'Split':
                        if current_player:
                            # create new player
                            split_player = PlayerHand(current_player.name + ' - Hand 2', current_player.bet, True)
                            current_player.set_split(True)
                            current_player.name += ' - Hand 1'

                            # split cards between the two hands
                            card = current_player.remove_card(0)
                            split_player.add_card(card)

                            # deal additional card to each hand
                            card = dealer_deck.deal_card()
                            current_player.add_card(card)

                            card = dealer_deck.deal_card()
                            split_player.add_card(card)

                            # add player
                            players.append(split_player)

                    elif valid_move[0] == chosen_move and valid_move[1] == 'Surrender':
                        print('{} has surrendered. You lose half your original bet, '
                              '{} chips'.format(current_player.name, int(current_player.bet * 0.5)))
                        current_player.set_surrendered(True)
                        players_finished.append(index)

                # check if player busted
                if current_player.is_busted():
                    print('{}, you have busted!'.format(current_player.name))
                    players_finished.append(index)

    # resolve dealers hand
    all_players_busted = True
    for player in players:
        if not player.is_busted():
            all_players_busted = False
            break

    if not all_players_busted:
        print('\nDealer will now resolve...')
        print(dealer_hand)
        while dealer_hand.hand_value() < 17:
            card = dealer_deck.deal_card()
            dealer_hand.add_card(card)
            print(dealer_hand)


# show results
print("Dealer's score: {}".format(dealer_hand.hand_value()))
bankroll_changes = {}
for player in players:
    print("\n\n{}'s results:".format(player.name))
    print('\tHand value: {}'.format(player.hand_value()))

    if player.has_surrendered():
        print('\t{} surrendered, losing {} chips'.format(player.name, int(player.bet * 0.5)))
        bankroll_changes[player.name] = -int(player.bet * 0.5)
    elif player.has_blackjack() and not dealer_hand.has_blackjack():
        bankroll_changes[player.name] = int(1.5 * player.bet)
    elif dealer_hand.has_blackjack() and not player.has_blackjack():
        print('\tDealer has blackjack. You lose {} chips'.format(player.bet))
        bankroll_changes[player.name] = -player.bet
    elif player.is_busted():
        print('\t{} has busted. You lose {} chips.'.format(player.name, player.bet))
        bankroll_changes[player.name] = -player.bet
    elif dealer_hand.is_busted():
        print('\tDealer has busted! {} wins {} chips'.format(player.name, player.bet))
        bankroll_changes[player.name] = player.bet
    elif player.hand_value() > dealer_hand.hand_value():
        print('\t{} has won {} chips.'.format(player.name, player.bet))
        bankroll_changes[player.name] = player.bet
    elif player.hand_value() == dealer_hand.hand_value():
        print('\t{} has tied. Your {} chips are returned to you.'.format(player.name, player.bet))
        bankroll_changes[player.name] = 0
    elif player.hand_value() < dealer_hand.hand_value():
        print('\t{} has lost {} chips.'.format(player.name, player.bet))
        bankroll_changes[player.name] = -player.bet

# save bankroll results
read_file = open('bankrolls.txt', 'r')
lines = read_file.readlines()
player_bankrolls = {}
for line in lines:
    player_record = line.split()
    player_bankrolls[player_record[0]] = int(player_record[1])
read_file.close()

for key in bankroll_changes.keys():
    try:
        player_bankrolls[key] += bankroll_changes[key]
    except KeyError:
        player_bankrolls[key] = 1000 + bankroll_changes[key]

write_file = open('bankrolls.txt', 'w')
counter = 0
for key in player_bankrolls.keys():
    write_file.write('{} {}'.format(key, player_bankrolls[key]))
    counter += 1
    if counter < len(player_bankrolls):
        write_file.write('\n')
write_file.close()
