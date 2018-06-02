from Deck import Deck
from Player import Player
from Hand import Hand


def get_player_names():
    print("Enter each player's name, or 'end' to stop entering names")
    names = []
    while True:
        name = input(f"Player {len(names) + 1}'s name: ")
        if name.isalpha():
            if name.lower() == 'end':
                break
            else:
                names.append(name.split()[0].capitalize())
        else:
            print('Please do not use numbers or spaces for the name.\n')
    return names


def get_player_bankroll(name):
    file = open('bankrolls.txt', 'r')
    lines = file.readlines()
    for line in lines:
        name_from_file, chips = tuple(line.split())
        if name == name_from_file:
            file.close()
            return False, int(chips)
    else:
        file.close()
        return True, 1000


def get_bet(name, chips):
    while True:
        try:
            bet = int(input(f'{name}, how much would you like to bet? '))
        except ValueError:
            print('Please enter a number\n')
        else:
            if bet > chips:
                print(f'This bet exceeds your current bankroll of {chips} chips. Please enter a lower bet.\n')
            elif bet < 0:
                print('You must bid at least 0 chips.')
            else:
                return bet


def get_valid_moves(hand):
    valid_moves = ['Hit', 'Stand', 'Double']
    if hand.split_is_valid():
        valid_moves.append('Split')
    if hand.surrender_is_valid():
        valid_moves.append('Surrender')
    return valid_moves


def get_player_move_from_valid_moves(valid_moves):
    # ask for player's move (hit, stand, double, split, surrender)
    while True:
        for index, valid_move in enumerate(valid_moves):
            print(f'{index+1} - {valid_move}')
        try:
            chosen_move_number = int(input()) - 1
        except ValueError:
            print('Please enter a valid move number')
        else:
            if chosen_move_number in range(len(valid_moves)):
                return valid_moves[chosen_move_number]
            else:
                print('Please enter a valid move number')


def add_2card_hand_to(player):
    # deal 2 cards to the player
    player_hand = Hand()
    for _ in range(2):
        card = deck.deal_card()
        player_hand.add_card(card)
    player.add_hand(player_hand)


# welcome
print('\nWelcome To Python Blackjack!\n')
deck = Deck()
deck.shuffle()
players = []


# set up players
names = get_player_names()
for name in names:
    players.append(Player(name))

for player in players:
    new_player, player.chips = get_player_bankroll(player.name)
    if new_player:
        print(f'Welcome {player.name}! Please accept these 1000 chips to begin.\n')
    else:
        print(f'Welcome back, {player.name}! Your previous bankroll of {player.chips} chips has been loaded.\n')


# ask for bets
for player in players:
    player_bet = get_bet(player.name, player.chips)
    player.set_bet(player_bet)

# deal 2 cards to each player, including dealer
for player in players:
    add_2card_hand_to(player)
dealer = Player('Dealer')
add_2card_hand_to(dealer)

for player in players:
    print(player)
print(dealer)

# check for blackjacks
for player in players:
    if player.has_blackjack() and not dealer.has_blackjack():
        print(f'{player.name} has a blackjack! You win a 3:2 payout of {player.bet * 1.5} chips.\n')
        player.set_finished(True)


if dealer.has_blackjack():
    print(dealer.hand)
    print('Dealer has blackjack!')
else:
    print(dealer)

    # allow players to play their hands
    all_finished = False
    while not all_finished:
        for player in players:
            for hand in player.hands:
                if not hand.finished:
                    print(player.name + '\n' + player.hand)
                    move = get_player_move_from_valid_moves(get_valid_moves(hand))

                    if move == 'Hit':
                        card = deck.deal_card()
                        hand.add_card(card)
                        print(hand)

                    elif move == 'Stand':
                        hand.set_finished(True)

                    elif move == 'Double':
                        # hit with one more card and double bet
                        card = deck.deal_card()
                        hand.add_card(card)
                        print(f'Doubling bet to {player.bet*2}...')
                        player.bet *= 2
                        hand.set_finished(True)
                        print(hand)

                    elif move == 'Split':
                        print('Splitting hand')
                        # create new hand
                        new_hand = Hand(split=True)
                        hand.set_split(True)

                        # split cards between the two hands
                        card = hand.remove_card(0)
                        new_hand.add_card(card)

                        # deal additional card to each hand
                        hand.add_card(deck.deal_card())
                        new_hand.add_card(deck.deal_card())

                        # give new hand to player
                        player.add_hand(new_hand)

                    elif move == 'Surrender':
                        print(f'{player.name} has surrendered this hand. You lose half your original bet')
                        hand.set_finished(True)

                    # check if hand busted
                    if hand.is_busted():
                        print(f'{player.name}, you have busted!')
                        hand.set_finished(True)

        all_finished = True
        for player in players:
            if player.has_active_hand():
                all_finished = False

    # resolve dealers hand
    all_players_busted = True
    for player in players:
        if not player.has_nonbusted_hand():
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
    elif player.has_blackjack() and not dealer.has_blackjack():
        bankroll_changes[player.name] = int(1.5 * player.bet)
    elif dealer.has_blackjack() and not player.has_blackjack():
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
