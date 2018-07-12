
#include "Deck.h"

Deck::Deck() {
    // Open input file
    string filename = "Kingdom Specifications.txt";
    ifstream din;
    din.open(filename.c_str());
    if (din.fail()) {
        // couldn't find file
        cout << "couldn't find file\n";
        return;
    }
    specs.clear();
    // Read into specs vector

    specs.push_back(read_spec(din, "Players:", "Number of Players"));
    specs.push_back(read_spec(din, "Rating:", "Speed Rating"));
    specs.push_back(read_spec(din, "by:", "Sorting Method"));

    specs.push_back(read_spec(din, "Castle:", "Allow Castle cards"));
    specs.push_back(read_spec(din, "Intrigue:", "Allow Intrigue cards"));
    specs.push_back(read_spec(din, "Seaside:", "Allow Seaside cards"));
    specs.push_back(read_spec(din, "Alchemy:", "Allow Alchemy cards"));
    specs.push_back(read_spec(din, "Prosperity:", "Allow Prosperity cards"));
    specs.push_back(read_spec(din, "Cornucopia:", "Allow Cornucopia cards"));
    specs.push_back(read_spec(din, "Hinterlands:", "Allow Hinterlands cards"));
    specs.push_back(read_spec(din, "Dark_Ages:", "Allow Dark Ages cards"));
    specs.push_back(read_spec(din, "Guilds:", "Allow Guilds cards"));
    specs.push_back(read_spec(din, "Adventures:", "Allow Adventures cards"));
    specs.push_back(read_spec(din, "Black_Market:", "Allow Black Market"));
    specs.push_back(read_spec(din, "Envoy:", "Allow Envoy"));
    specs.push_back(read_spec(din, "Governor:", "Allow Governor"));
    specs.push_back(read_spec(din, "Prince:", "Allow Prince"));
    specs.push_back(read_spec(din, "Stash:", "Allow Stash"));
    specs.push_back(read_spec(din, "Walled_Village:", "Allow Walled Village"));

    specs.push_back(read_spec(din, "between", "Lower bound for Castle cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Castle cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Intrigue cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Intrigue cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Seaside cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Seaside cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Alchemy cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Alchemy cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Prosperity cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Prosperity cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Cornucopia cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Cornucopia cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Hinterlands cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Hinterlands cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Dark Ages cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Dark Ages cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Guilds cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Guilds cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Adventures cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Adventures cards"));

    specs.push_back(read_spec(din, "between", "Lower bound for +cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for +cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for +actions"));
    specs.push_back(read_spec(din, "and", "Upper bound for +actions"));
    specs.push_back(read_spec(din, "card:", "Require a +2 actions card"));
    specs.push_back(read_spec(din, "between", "Lower bound for +buys"));
    specs.push_back(read_spec(din, "and", "Upper bound for +buys"));
    specs.push_back(read_spec(din, "between", "Lower bound for +coins"));
    specs.push_back(read_spec(din, "and", "Upper bound for +coins"));
    specs.push_back(read_spec(din, "between", "Lower bound for attack cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for attack cards"));
    specs.push_back(read_spec(din, "attacks:", "Require an appropriate reaction for all attacks"));
    specs.push_back(read_spec(din, "between", "Lower bound for Trasher cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Trasher cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Duration cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Duration cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Treasure cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Treasure cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Victory cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Victory cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Reserve cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Reserve cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for Event cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for Event cards"));

    specs.push_back(read_spec(din, "between", "Lower bound for 1 cost cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for 1 cost cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for 2 cost cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for 2 cost cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for 3 cost cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for 3 cost cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for 4 cost cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for 4 cost cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for 5 cost cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for 5 cost cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for 6 cost cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for 6 cost cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for 7 cost cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for 7 cost cards"));
    specs.push_back(read_spec(din, "between", "Lower bound for potion cost cards"));
    specs.push_back(read_spec(din, "and", "Upper bound for potion cost cards"));
    specs.push_back(read_spec(din, "card:", "Prevent having exactly one potion cost card"));
    specs.push_back(read_spec(din, "discarded:", "Tunnel is useful"));
    specs.push_back(read_spec(din, "it:", "Scout is useful"));
    specs.push_back(read_spec(din, "trasher:", "On-trash abilities cards are useful"));
    specs.push_back(read_spec(din, "attacks:", "Prevent useless reactions"));
    specs.push_back(read_spec(din, "+buy:", "Contraband is useful"));
    specs.push_back(read_spec(din, "card:", "Rats is useful"));
    specs.push_back(read_spec(din, "5:", "Feast and Altar are useful"));
    specs.push_back(read_spec(din, "Woodcutter:", "Redundant: Messenger, Nomad Camp, and Woodcutter"));
    specs.push_back(read_spec(din, "attacks:", "Squire is useful"));
    specs.push_back(read_spec(din, "Merchant:", "Redundant: Chapel, Loan, Moneylender, and Spice Merchant"));
    specs.push_back(read_spec(din, "Workshop:", "Redundant: Armory, Ironworks, Talisman, and Workshop"));
    specs.push_back(read_spec(din, "Thief:", "Redundant: Noble Brigand, Pirate Ship, and Thief"));
    specs.push_back(read_spec(din, "Remodel:", "Redundant: Expand and Remodel"));
    specs.push_back(read_spec(din, "Mandarin:", "Redundant: Count and Mandarin"));
    specs.push_back(read_spec(din, "Chamber:", "Redundant: Reaction cards"));
    specs.push_back(read_spec(din, "Smithy:", "Redundant: Hunting Grounds and Smithy"));
    specs.push_back(read_spec(din, "attacks:", "Urchin is useful"));
    specs.push_back(read_spec(din, "more:", "Quarry is useful"));
    specs.push_back(read_spec(din, "+buy:", "Nomad Camp/Woodcutter is useful"));
    specs.push_back(read_spec(din, "attack:", "Market Square is useful"));
    specs.push_back(read_spec(din, "Room:", "Redundant: Procession and Throne Room"));
    specs.push_back(read_spec(din, "Taxman:", "Redundant: Mine and Taxman"));
    specs.push_back(read_spec(din, "actions:", "Conspirator is useful"));
    specs.push_back(read_spec(din, "6:", "Procession is useful"));
    specs.push_back(read_spec(din, "cards:", "Redundant: Same cost trashers"));
    specs.push_back(read_spec(din, "card:", "Redundant: Hand size reducing attack card"));
    specs.push_back(read_spec(din, "cost:", "Redundant: Similar cost +2 actions cards"));
    specs.push_back(read_spec(din, "Spy:", "Redundant: Deck spying attacks"));
    specs.push_back(read_spec(din, "Vault:", "Redundant: Discard for coin cards"));
    specs.push_back(read_spec(din, "Witch:", "Redundant: Curse giving attacks"));
    specs.push_back(read_spec(din, "Scavenger:", "Redundant: Chancellor and Scavenger"));
    specs.push_back(read_spec(din, "Laboratory:", "Redundant: Hunting Party and Laboratory"));
    specs.push_back(read_spec(din, "4:", "Band of Misfits is useful"));
    specs.push_back(read_spec(din, "Graverobber:", "Redundant: Expand and Graverobber"));
    specs.push_back(read_spec(din, "4:", "Prince is useful"));
    specs.push_back(read_spec(din, "5:", "University is useful"));
    specs.push_back(read_spec(din, "Poor_House:", "Annoying: Develop and Poor House"));
    specs.push_back(read_spec(din, "Envoy:", "Redundant: Advisor and Envoy"));

    din.close();


    // Open input file
    filename = "Dominion cards.txt";
    din.open(filename.c_str());
    if (din.fail()) {
        // couldn't find file
        return;
    }

    // Read into vector
    string name, type, set;
    int rank, uses, setup, blacklisted, whitelisted, speed, previous;
    float cost, cards, actions, buys, coins, trasher;

    while (!din.eof()) {
        Card card;
        din >> name;
        card.name = name;
        din >> cost;
        card.cost = cost;
        din >> rank;
        card.rank = rank;
        din >> uses;
        card.uses = uses;
        din >> cards;
        card.cards = cards;
        din >> actions;
        card.actions = actions;
        din >> buys;
        card.buys = buys;
        din >> coins;
        card.coins = coins;
        din >> type;
        card.type = type;
        din >> trasher;
        card.trasher = trasher;

        din >> setup;
        if (setup == 1)
            card.setup = true;
        else
            card.setup = false;

        din >> blacklisted;
        if (blacklisted == 1)
            card.blacklisted = true;
        else
            card.blacklisted = false;

        din >> whitelisted;
        if (whitelisted == 1)
            card.whitelisted = true;
        else
            card.whitelisted = false;

        din >> speed;
        card.speed = speed;

        din >> previous;
        if (previous == 1)
            card.previous = true;
        else
            card.previous = false;

        din >> set;
        card.set = set;
        card.whitelisted_helper = false;
        card.bane = false;
        full_deck.push_back(card);

        if (!card.blacklisted && !card.previous &&
                (card.set != "Castle" || get_spec("Allow Castle cards") == 1) &&
                (card.set != "Intrigue" || get_spec("Allow Intrigue cards") == 1) &&
                (card.set != "Seaside" || get_spec("Allow Seaside cards") == 1) &&
                (card.set != "Alchemy" || get_spec("Allow Alchemy cards") == 1) &&
                (card.set != "Prosperity" || get_spec("Allow Prosperity cards") == 1) &&
                (card.set != "Cornucopia" || get_spec("Allow Cornucopia cards") == 1) &&
                (card.set != "Hinterlands" || get_spec("Allow Hinterlands cards") == 1) &&
                (card.set != "Dark_Ages" || get_spec("Allow Dark Ages cards") == 1) &&
                (card.set != "Guilds" || get_spec("Allow Guilds cards") == 1) &&
                (card.set != "Adventures" || get_spec("Allow Adventures cards") == 1) &&
                (card.name != "Black_Market" || get_spec("Allow Black Market") == 1) &&
                (card.name != "Envoy" || get_spec("Allow Envoy") == 1) &&
                (card.name != "Governor" || get_spec("Allow Governor") == 1) &&
                (card.name != "Prince" || get_spec("Allow Prince") == 1) &&
                (card.name != "Stash" || get_spec("Allow Stash") == 1) &&
                (card.name != "Walled_Village" || get_spec("Allow Walled Village") == 1))
            game_deck.push_back(card);
    }

    din.close();

    // Read from game data file
    string inName = "Player game data.txt";
    string sypult; // Beka!
    ifstream inStrm(inName.c_str());
    if (!inStrm) {
        cout << "There was a problem opening file " <<
                inName << " for reading." << endl;
    }

    while (!inStrm.eof()) {
        getline(inStrm, sypult);
        Player p;
        p.name = tokenize(sypult, ' ');
        while (sypult != "") {
            Game game;
            string data = tokenize(sypult, ' ');
            stringstream convert1(data);
            if (!(convert1 >> game.score))
                game.score = 0;

            data = tokenize(sypult, ' ');
            stringstream convert2(data);
            if (!(convert2 >> game.place))
                game.place = 0;

            data = tokenize(sypult, ' ');
            stringstream convert3(data);
            if (!(convert3 >> game.opponents))
                game.opponents = 0;

            data = tokenize(sypult, ' ');
            stringstream convert4(data);
            if (!(convert4 >> game.opps_points))
                game.opps_points = 0;

            p.history.push_back(game);
        }
        if (p.name != "")
            players.push_back(p);
    }

    // Open input file
    filename = "Saved Kingdoms.txt";
    din.open(filename.c_str());
    if (din.fail()) {
        // couldn't find file
        return;
    }
    string line;
    string card;
    int PC, shelter;
    saved_kingdoms.clear();

    while (!din.eof()) {
        Kingdom k;
        getline(din, line);
        while (line != "") {
            card = tokenize(line, ' ');
            k.cards.push_back(card);
        }
        getline(din, line);
        while (line != "") {
            card = tokenize(line, ' ');
            k.cards.push_back(card);
        }
        din >> PC;
        k.PC = PC;
        din >> shelter;
        k.shelter = shelter;

        ws(din);
        k.notes = "";
        getline(din, line);

        while (line != "End of Kingdom" && line != "") {
            if (line != "End of Kingdom")
                k.notes += line;
            getline(din, line);
            if (line != "End of Kingdom")
                k.notes += "\n";
        }

        if (k.cards.size() > 5)
            saved_kingdoms.push_back(k);
    }
}

Deck::~Deck() {
    // mark all cards in kingdom as being in last kingdom
    for (int i = 0; i < kingdom.size(); i++)
        full_deck.at(position_of(kingdom.at(i).name)).previous = true;

    // Open first output file
    string filename = "Dominion cards.txt";
    ofstream dout;
    dout.open(filename.c_str());
    if (dout.fail()) {
        // couldn't find file
        return;
    }

    // Read from vector, edit file
    int size = full_deck.size();
    for (int i = 0; i < size - 1; i++) {
        Card* card = &full_deck.at(i);
        dout << card->name << " ";
        dout << card->cost << " ";
        dout << card->rank << " ";
        dout << card->uses << " ";
        dout << card->cards << " ";
        dout << card->actions << " ";
        dout << card->buys << " ";
        dout << card->coins << " ";
        dout << card->type << " ";
        dout << card->trasher << " ";
        if (card->setup)
            dout << "1 ";
        else
            dout << "0 ";

        if (card->blacklisted)
            dout << "1 ";
        else
            dout << "0 ";
        if (card->whitelisted)
            dout << "1 ";
        else
            dout << "0 ";
        dout << card->speed << " ";
        if (card->previous)
            dout << "1 ";
        else
            dout << "0 ";
        dout << card->set << endl;
    }

    dout << full_deck.at(size - 1).name << " ";
    dout << full_deck.at(size - 1).cost << " ";
    dout << full_deck.at(size - 1).rank << " ";
    dout << full_deck.at(size - 1).uses << " ";
    dout << full_deck.at(size - 1).cards << " ";
    dout << full_deck.at(size - 1).actions << " ";
    dout << full_deck.at(size - 1).buys << " ";
    dout << full_deck.at(size - 1).coins << " ";
    dout << full_deck.at(size - 1).type << " ";
    dout << full_deck.at(size - 1).trasher << " ";
    if (full_deck.at(size - 1).setup)
        dout << "1 ";
    else
        dout << "0 ";

    if (full_deck.at(size - 1).blacklisted)
        dout << "1 ";
    else
        dout << "0 ";
    if (full_deck.at(size - 1).whitelisted)
        dout << "1 ";
    else
        dout << "0 ";
    dout << full_deck.at(size - 1).speed << " ";
    if (full_deck.at(size - 1).previous)
        dout << "1 ";
    else
        dout << "0 ";
    dout << full_deck.at(size - 1).set;

    dout.close();

    // Open second output file
    filename = "Player game data.txt";
    dout.open(filename.c_str());
    if (dout.fail()) {
        // couldn't find file
        return;
    }

    for (int i = 0; i < players.size(); i++) {
        Player* player = &players.at(i);
        dout << player->name << " ";
        for (int j = 0; j < player->history.size(); j++) {
            dout << player->history.at(j).score << " ";
            dout << player->history.at(j).place << " ";
            dout << player->history.at(j).opponents << " ";
            dout << player->history.at(j).opps_points << " ";
        }
        if (i + 1 != players.size())
            dout << "\n";
    }

    dout.close();

    // Open third kingdoms output file
    filename = "Saved Kingdoms.txt";
    dout.open(filename.c_str());
    if (dout.fail()) {
        // couldn't find file
        return;
    }

    if (!saved_kingdoms.empty()) {
        size = saved_kingdoms.size();
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < saved_kingdoms.at(i).cards.size() / 2; j++)
                dout << saved_kingdoms.at(i).cards.at(j) << " ";

            dout << endl;
            for (int j = saved_kingdoms.at(i).cards.size() / 2; j < saved_kingdoms.at(i).cards.size(); j++)
                dout << saved_kingdoms.at(i).cards.at(j) << " ";

            dout << endl << saved_kingdoms.at(i).PC << " " << saved_kingdoms.at(i).shelter << endl <<
                    saved_kingdoms.at(i).notes << endl;
            dout << "End of Kingdom\n";
        }

        for (int j = 0; j < saved_kingdoms.at(size - 1).cards.size() / 2; j++)
            dout << saved_kingdoms.at(size - 1).cards.at(j) << " ";

        dout << endl;
        for (int j = saved_kingdoms.at(size - 1).cards.size() / 2; j < saved_kingdoms.at(size - 1).cards.size(); j++)
            dout << saved_kingdoms.at(size - 1).cards.at(j) << " ";

        dout << endl << saved_kingdoms.at(size - 1).PC << " " << saved_kingdoms.at(size - 1).shelter << endl <<
                saved_kingdoms.at(size - 1).notes << endl;
        dout << "End of Kingdom";
    }
}

void Deck::print_deck() {
    cout << endl;
    for (Card c : full_deck)
        c.print();
}

void Deck::print_specs() {
    cout << endl;
    for (int i = 0; i < specs.size(); i++) {
        cout << specs.at(i).id << ": " << specs.at(i).value << endl;
    }
}

void Deck::print_uses() {
    bool empty = true;
    int total_uses = 0;
    int young_witches = 0;
    for (int i = 0; i < full_deck.size(); i++) {
        total_uses += full_deck.at(i).uses;
        if (full_deck.at(i).uses != 0)
            empty = false;
        if (full_deck.at(i).name == "Young_Witch")
            young_witches = full_deck.at(i).uses;
    }
    if (empty)
        cout << "\nNo cards have been used yet.\n";
    else {
        cout << "\nUses of cards in deck:\n";
        for (int i = 0; i < full_deck.size(); i++) {
            if (full_deck.at(i).uses != 0)
                cout << "\t" << full_deck.at(i).name << ": " << full_deck.at(i).uses << "\n";
        }
    }
    cout << "Total games played: " << (total_uses - young_witches) / 10 << endl << endl;
}

void Deck::print_rankings() {
    bool above_avg = false;
    bool below_avg = false;
    for (int i = 0; !above_avg && i < full_deck.size(); i++) {
        if (full_deck.at(i).rank > 0)
            above_avg = true;
    }
    for (int i = 0; !below_avg && i < full_deck.size(); i++) {
        if (full_deck.at(i).rank < 0)
            below_avg = true;
    }

    cout << "\nCurrent Rankings:\n";

    cout << "\tCards above avg rank:\n";
    if (above_avg) {
        for (int i = 0; i < full_deck.size(); i++) {
            if (full_deck.at(i).rank > 0) {
                cout << "\t\t\t" << full_deck.at(i).name <<
                        " +" << full_deck.at(i).rank << endl;
            }
        }
    } else {
        cout << "\t\t\tNone\n";
    }

    cout << "\tCards below avg rank:\n";
    if (below_avg) {
        for (int i = 0; i < full_deck.size(); i++) {
            if (full_deck.at(i).rank < 0) {
                cout << "\t\t\t" << full_deck.at(i).name <<
                        " " << full_deck.at(i).rank << endl;
            }
        }
    } else {
        cout << "\t\t\tNone\n";
    }
    cout << "\n\tAll other cards are avg rank.\n\n";
}

void Deck::print_blacklist() {
    bool empty = true;
    for (int i = 0; i < full_deck.size(); i++) {
        if (full_deck.at(i).blacklisted)
            empty = false;
    }

    if (empty)
        cout << "\nBlacklist is currently empty.\n\n";
    else {
        cout << "\nCurrent Blacklist:\n";
        for (int i = 0; i < full_deck.size(); i++) {
            if (full_deck.at(i).blacklisted)
                cout << "\t" << full_deck.at(i).name << "\n";
        }
        cout << endl;
    }
}

void Deck::print_whitelist() {
    bool empty = true;
    for (int i = 0; i < full_deck.size(); i++) {
        if (full_deck.at(i).whitelisted)
            empty = false;
    }

    if (empty)
        cout << "\nWhitelist is currently empty.\n\n";
    else {
        cout << "\nCurrent Whitelist:\n";
        for (int i = 0; i < full_deck.size(); i++) {
            if (full_deck.at(i).whitelisted)
                cout << "\t" << full_deck.at(i).name << "\n";
        }
        cout << endl;
    }
}

void Deck::previous_kingdom() {
    bool okay = false;
    for (int i = 0; i < full_deck.size(); i++) {
        if (full_deck.at(i).previous)
            okay = true;
    }

    if (!okay)
        cout << "There is no previous kingdom.\n";
    else {
        int responseA = 0;
        int responseB = 0;
        string note;
        cout << "Previous Kingdom:\n";
        for (int i = 0; i < full_deck.size(); i++) {
            if (full_deck.at(i).previous)
                cout << "\t" << full_deck.at(i).name << endl;
        }
        do {
            cout << "1 - Save kingdom\t2 - I didn't actually use this kingdom\n" <<
                    "3 - Save and quit\n";
            cin >> responseA;
            switch (responseA) {
                case 1:
                {
                    Kingdom k;
                    for (int i = 0; i < full_deck.size(); i++) {
                        if (full_deck.at(i).previous)
                            k.cards.push_back(full_deck.at(i).name);
                    }

                    do {
                        cout << "\nHow do you want to handle the inclusion of Platinum and\n" <<
                                "Colony supply cards with this kingdom?\n\n" <<
                                "1 - Always use Platinum and Colony\n" <<
                                "2 - Never use Platinum and Colony\n" <<
                                "3 - Include Platinum and Colony randomly, as normal\n";
                        cin >> responseB;
                        if (responseB != 1 && responseB != 2 && responseB != 3)
                            cout << "Input not read. Please try again.\n\n";
                    } while (responseB != 1 && responseB != 2 && responseB != 3);
                    k.PC = responseB;

                    responseB = 0;
                    do {
                        cout << "\nHow do you want to handle the inclusion of\n" <<
                                "Shelter cards with this kingdom?\n\n" <<
                                "1 - Always use Shelters\n" <<
                                "2 - Never use Shelters\n" <<
                                "3 - Include Shelters randomly, as normal\n";
                        cin >> responseB;
                        if (responseB != 1 && responseB != 2 && responseB != 3)
                            cout << "Input not read. Please try again.\n\n";
                    } while (responseB != 1 && responseB != 2 && responseB != 3);
                    k.shelter = responseB;

                    cout << "\nNow enter any notes you want to save on this kingdom, then press enter.\n" <<
                            "(Title of the kingdom, description of the kingdom, etc.)\n";
                    ws(cin);
                    getline(cin, note);
                    k.notes = "";
                    if (note == "")
                        k.notes = "None";
                    else {
                        while (note != "") {
                            for (int i = 0; note != "" && i < 12; i++) {
                                k.notes += tokenize(note, ' ');
                                k.notes += ' ';
                            }
                            if (note != "")
                                k.notes += "\n";
                        }
                    }
                    saved_kingdoms.push_back(k);

                    cout << "\nPrevious kingdom was saved.\nSaved Kingdom #" <<
                            saved_kingdoms.size() << ":" << endl;
                    for (int i = 0; i < full_deck.size(); i++) {
                        if (full_deck.at(i).previous)
                            cout << "\t" << full_deck.at(i).name << endl;
                    }
                    cout << "Notes: " << saved_kingdoms.at(saved_kingdoms.size() - 1).notes << endl;
                }
                    break;
                case 2:
                {
                    // Take away uses for previous
                    for (int i = 0; i < full_deck.size(); i++) {
                        if (full_deck.at(i).previous)
                            full_deck.at(i).uses--;
                        full_deck.at(i).previous = false;
                    }
                    cout << "Use count decremented for each card in the previous kingdom.\n";
                }
                    break;
                case 3:
                {
                }
                    break;

            }
        } while (responseA != 1 && responseA != 2 && responseA != 3);
    }
}

void Deck::print_saved_kingdoms() {
    if (saved_kingdoms.empty())
        cout << "There are no kingdoms saved.\n";
    else {
        cout << "Saved Kingdoms:\n";
        for (int i = 0; i < saved_kingdoms.size(); i++) {
            cout << "\nKingdom " << i + 1 << ":\n";
            for (int j = 0; j < saved_kingdoms.at(i).cards.size(); j++)
                cout << "\t" << saved_kingdoms.at(i).cards.at(j) << endl;
            cout << "\nNotes: " << saved_kingdoms.at(i).notes << endl;
        }
    }
}

void Deck::play_saved_kingdom() {
    if (saved_kingdoms.empty())
        cout << "There are no kingdoms saved.\n";
    else {
        int response = 0;
        print_saved_kingdoms();
        do {
            cout << "\nEnter the number for which kingdom " <<
                    "you would like to play:";
            cin >> response;
            if (response < 0 || response > saved_kingdoms.size())
                cout << "There is no kingdom with that index number.\n" <<
                    "Please try again.\n";
        } while (response < 0 || response > saved_kingdoms.size());

        kingdom.clear();
        for (int i = 0; i < saved_kingdoms.at(response - 1).cards.size(); i++)
            add_to_kingdom(saved_kingdoms.at(response - 1).cards.at(i));

        cout << "\nSaved Kingdom #" << response << ":" << endl;
        print_kingdom(true, saved_kingdoms.at(response - 1).PC, saved_kingdoms.at(response - 1).shelter);
    }
}

void Deck::adjust_usage() {
    int response;
    string card;
    Card* chosen;
    bool done = false;

    do {
        cout << "\n1 - Add a use\t2 - Subtract a use" <<
                "\n3 - Print uses\t4 - Reset uses" <<
                "\n5 - Save and quit\n";
        cin >> response;
        cout << endl;
        switch (response) {
            case 1:
                chosen = NULL;
                cout << "Is there a card you used without telling me?\n(Be sure to " <<
                        "spell the name correctly, using underscore for any spaces)\n";
                cin >> card;
                cout << endl;
                for (int i = 0; i < full_deck.size(); i++) {
                    if (full_deck.at(i).name == card)
                        chosen = &full_deck.at(i);
                }
                if (chosen == NULL)
                    cout << "I'm sorry, the deck does not contain a card named \"" << card << "\".\n\n";
                else {
                    chosen->uses++;
                    cout << "I have added one use to the use count of the card " << chosen->name << ".\n\n";
                }
                break;
            case 2:
                chosen = NULL;
                cout << "Is there a card I picked for you that you did not use?\n(Be sure to " <<
                        "spell the name correctly, using underscore for any spaces)\n";
                cin >> card;
                cout << endl;
                for (int i = 0; i < full_deck.size(); i++) {
                    if (full_deck.at(i).name == card)
                        chosen = &full_deck.at(i);
                }
                if (chosen == NULL)
                    cout << "I'm sorry, the deck does not contain a card named \"" << card << "\".\n\n";
                else {
                    chosen->uses--;
                    if (chosen->uses < 0) {
                        chosen->uses = 0;
                        cout << chosen->name << " has never been used. The use count of this card is 0.\n\n";
                    } else {
                        cout << "I have subtracted one use to the use count of the card " << chosen->name << ".\n\n";
                    }
                }
                break;
            case 3:
                print_uses();
                break;
            case 4:
                reset_uses();
                break;
            case 5:
                done = true;
                break;
            default:
                cout << "Input not read. Try again.\n";
                break;
        }
    } while (!done);
}

void Deck::adjust_rankings() {
    int response;
    string card;
    Card* chosen;
    bool done = false;

    do {
        cout << "\n1 - Upvote a card\t2 - Downvote a card" <<
                "\n3 - Print rankings\t4 - Reset rankings" <<
                "\n5 - Save and quit\n";
        cin >> response;
        cout << endl;
        switch (response) {
            case 1:
                chosen = NULL;
                cout << "\nWhat card would you like to see me use MORE often?\n(Be sure " <<
                        "to spell the name correctly, using underscore for any spaces)\n";
                cin >> card;
                cout << endl;
                for (int i = 0; i < full_deck.size(); i++) {
                    if (full_deck.at(i).name == card)
                        chosen = &full_deck.at(i);
                }
                if (chosen == NULL)
                    cout << "I'm sorry, the deck does not contain a card named \"" << card << "\".\n";
                else {
                    chosen->rank++;
                    if (chosen->rank > 5) {
                        chosen->rank = 5;
                        cout << chosen->name << " already has the highest ranking possible (+5).\n";
                    } else {
                        cout << "Good choice. I will use the card " << chosen->name <<
                                " a bit more often in the future.\n";
                    }
                }
                break;
            case 2:
                chosen = NULL;
                cout << "\nWhat card would you like to see me use LESS often?\n(Be sure " <<
                        "to spell the name correctly, using underscore for any spaces)\n";
                cin >> card;
                cout << endl;
                for (int i = 0; i < full_deck.size(); i++) {
                    if (full_deck.at(i).name == card)
                        chosen = &full_deck.at(i);
                }
                if (chosen == NULL)
                    cout << "I'm sorry, the deck does not contain a card named \"" << card << "\".\n";
                else {
                    chosen->rank--;
                    if (chosen->rank < -5) {
                        chosen->rank = -5;
                        int answer;
                        cout << chosen->name << " already has the lowest ranking possible (-5).\n" << 
                                "Would you like to blacklist it? (1 for yes, 0 for no): ";
                        cin >> answer;
                        if (answer == 1) {
                            chosen->blacklisted = true;
                            cout << chosen->name << " has been blacklisted. Goodbye for now, " << chosen->name << "!\n";
                        }
                    }
                    cout << "I see. I will use the card " << chosen->name <<
                            " a bit less often in the future.\n";
                }
                break;
            case 3:
                print_rankings();
                break;
            case 4:
                reset_rankings();
                break;
            case 5:
                done = true;
                break;
            default:
                cout << "Error.\n";
                break;
        }
    } while (!done);
}

void Deck::manage_blacklist() {
    int response;
    string card;
    Card* chosen;
    bool done = false;

    do {
        print_blacklist();
        cout << "1 - Add a card\t2 - Remove a card\n" <<
                "3 - Save and quit\n";
        cin >> response;
        cout << endl;
        switch (response) {
            case 1:
                chosen = NULL;
                cout << "Is there a card you would like to add to the blacklist?\n" <<
                        "Blacklisted cards will not appear in the kingdom sets I " <<
                        "prepare.\n(Be sure to spell the name correctly, using " <<
                        "underscore for any spaces)\n";
                cin >> card;
                cout << endl;
                for (int i = 0; i < full_deck.size(); i++) {
                    if (full_deck.at(i).name == card)
                        chosen = &full_deck.at(i);
                }
                if (chosen == NULL)
                    cout << "I'm sorry, the deck does not contain a card named \"" << card << "\".\n\n";
                else if (chosen->blacklisted)
                    cout << chosen->name << " is already on the blacklist.\n\n";
                else {
                    chosen->blacklisted = true;
                    cout << chosen->name << " has been added to the blacklist. Farewell, " << chosen->name << ".\n\n";
                }
                break;
            case 2:
                chosen = NULL;
                cout << "Is there a card you would like to remove from the blacklist?\n";
                cin >> card;
                cout << endl;
                for (int i = 0; i < full_deck.size(); i++) {
                    if (full_deck.at(i).name == card)
                        chosen = &full_deck.at(i);
                }
                if (chosen == NULL)
                    cout << "I'm sorry, the blacklist does not contain a card named \"" << card << "\".\n\n";
                else {
                    if (!chosen->blacklisted)
                        cout << chosen->name << " was not on the blacklist.\n";
                    else {
                        chosen->blacklisted = false;
                        cout << chosen->name << " has been removed from the blacklist.\n";
                    }
                }
                break;
            case 3:
                done = true;
                print_blacklist();
                break;
            default:
                break;
        }
    } while (!done);
}

void Deck::manage_whitelist() {
    int response;
    string card;
    Card* chosen;
    bool done = false;

    do {
        print_whitelist();
        cout << "1 - Add a card\t2 - Remove a card\n" <<
                "3 - Save and quit\n";
        cin >> response;
        cout << endl;
        switch (response) {
            case 1:
                chosen = NULL;
                cout << "Is there a card you would like to add to the whitelist?\n" <<
                        "Whitelisted cards will appear in the next kingdom set I " <<
                        "prepare, then will be taken off the whitelist.\n" <<
                        "(Be sure to spell the name correctly, using " <<
                        "underscore for any spaces)\n";
                cin >> card;
                cout << endl;
                for (int i = 0; i < full_deck.size(); i++) {
                    if (full_deck.at(i).name == card)
                        chosen = &full_deck.at(i);
                }
                if (chosen == NULL)
                    cout << "I'm sorry, the deck does not contain a card named \"" << card << "\".\n\n";
                else if (chosen->whitelisted)
                    cout << chosen->name << " is already on the whitelist.\n\n";
                else {
                    chosen->whitelisted = true;
                    cout << chosen->name << " has been added to the whitelist. See you soon, " << chosen->name << ".\n\n";
                }
                break;
            case 2:
                chosen = NULL;
                cout << "Is there a card you would like to remove from the whitelist?\n";
                cin >> card;
                cout << endl;
                for (int i = 0; i < full_deck.size(); i++) {
                    if (full_deck.at(i).name == card)
                        chosen = &full_deck.at(i);
                }
                if (chosen == NULL)
                    cout << "I'm sorry, the whitelist does not contain a card named \"" << card << "\".\n\n";
                else {
                    if (!chosen->whitelisted)
                        cout << chosen->name << " was not on the whitelist.\n";
                    else {
                        chosen->whitelisted = false;
                        cout << chosen->name << " has been removed from the whitelist.\n";
                    }
                }
                break;
            case 3:
                done = true;
                print_whitelist();
                break;
            default:
                break;
        }
    } while (!done);
}

void Deck::print_kingdom(bool last, int PC, int shelter) {
    cout << "\nKingdom:\n";
    sort_kingdom();

    bool setup = false;
    for (int i = 0; i < kingdom.size(); i++) {
        if (kingdom.at(i).setup)
            setup = true;
    }

    switch ((int) get_spec("Sorting Method")) {
        case 1:
            for (int i = 0; i < kingdom.size(); i++) {
                if (kingdom.at(i).type == "Action-Attack")
                    cout << "A ";
                if (full_deck.at(position_of(kingdom.at(i).name)).bane)
                    cout << "Bane: ";

                cout << "\t" << (int) kingdom.at(i).cost;

                if ((int) (kingdom.at(i).cost * 2) % 2 == 1)
                    cout << "P";
                cout << " " << kingdom.at(i).name;
                if (kingdom.at(i).setup)
                    cout << " *";
                cout << endl;
            }
            break;
        case 2:
            for (int i = 0; i < kingdom.size(); i++) {
                if (full_deck.at(position_of(kingdom.at(i).name)).bane)
                    cout << "Bane: ";
                cout << "\t" << kingdom.at(i).name << " " <<
                        (int) kingdom.at(i).cost;
                if ((int) (kingdom.at(i).cost * 2) % 2 == 1)
                    cout << "P";
                if (kingdom.at(i).setup)
                    cout << " *";
                cout << endl;
            }
            break;
        case 3:

            int i = 0;
            if (kingdom_contains_set("Castle")) {
                cout << "\tCastle:\n";
                while (i < kingdom.size() && kingdom.at(i).set == "Castle") {
                    if (full_deck.at(position_of(kingdom.at(i).name)).bane)
                        cout << "\tBane: ";
                    cout << "\t\t" << kingdom.at(i).name << " " <<
                            kingdom.at(i).cost;
                    if (kingdom.at(i).setup)
                        cout << " *";
                    i++;
                    cout << endl;
                }
            }

            if (kingdom_contains_set("Intrigue")) {
                cout << "\tIntrigue:\n";
                while (i < kingdom.size() && kingdom.at(i).set == "Intrigue") {
                    if (full_deck.at(position_of(kingdom.at(i).name)).bane)
                        cout << "\tBane: ";
                    cout << "\t\t" << kingdom.at(i).name << " " <<
                            kingdom.at(i).cost;
                    if (kingdom.at(i).setup)
                        cout << " *";
                    i++;
                    cout << endl;
                }
            }

            if (kingdom_contains_set("Seaside")) {
                cout << "\tSeaside:\n";
                while (i < kingdom.size() && kingdom.at(i).set == "Seaside") {
                    if (full_deck.at(position_of(kingdom.at(i).name)).bane)
                        cout << "\tBane: ";
                    cout << "\t\t" << kingdom.at(i).name << " " <<
                            kingdom.at(i).cost;
                    if (kingdom.at(i).setup)
                        cout << " *";
                    i++;
                    cout << endl;
                }
            }

            if (kingdom_contains_set("Alchemy")) {
                cout << "\tAlchemy:\n";
                while (i < kingdom.size() && kingdom.at(i).set == "Alchemy") {
                    if (full_deck.at(position_of(kingdom.at(i).name)).bane)
                        cout << "\tBane: ";
                    cout << "\t\t" << kingdom.at(i).name << " " <<
                            (int) kingdom.at(i).cost;
                    if ((int) (kingdom.at(i).cost * 2) % 2 == 1)
                        cout << "P";
                    if (kingdom.at(i).setup)
                        cout << " *";
                    i++;
                    cout << endl;
                }
            }

            if (kingdom_contains_set("Prosperity")) {
                cout << "\tProsperity:\n";
                while (i < kingdom.size() && kingdom.at(i).set == "Prosperity") {
                    if (full_deck.at(position_of(kingdom.at(i).name)).bane)
                        cout << "\tBane: ";
                    cout << "\t\t" << kingdom.at(i).name << " " <<
                            kingdom.at(i).cost;
                    if (kingdom.at(i).setup)
                        cout << " *";
                    i++;
                    cout << endl;
                }
            }

            if (kingdom_contains_set("Cornucopia")) {
                cout << "\tCornucopia:\n";
                while (i < kingdom.size() && kingdom.at(i).set == "Cornucopia") {
                    if (full_deck.at(position_of(kingdom.at(i).name)).bane)
                        cout << "\tBane: ";
                    cout << "\t\t" << kingdom.at(i).name << " " <<
                            kingdom.at(i).cost;
                    if (kingdom.at(i).setup)
                        cout << " *";
                    i++;
                    cout << endl;
                }
            }

            if (kingdom_contains_set("Hinterlands")) {
                cout << "\tHinterlands:\n";
                while (i < kingdom.size() && kingdom.at(i).set == "Hinterlands") {
                    if (full_deck.at(position_of(kingdom.at(i).name)).bane)
                        cout << "\tBane: ";
                    cout << "\t\t" << kingdom.at(i).name << " " <<
                            kingdom.at(i).cost;
                    if (kingdom.at(i).setup)
                        cout << " *";
                    i++;
                    cout << endl;
                }
            }

            if (kingdom_contains_set("Dark_Ages")) {
                cout << "\tDark_Ages:\n";
                while (i < kingdom.size() && kingdom.at(i).set == "Dark_Ages") {
                    if (full_deck.at(position_of(kingdom.at(i).name)).bane)
                        cout << "\tBane: ";
                    cout << "\t\t" << kingdom.at(i).name << " " <<
                            kingdom.at(i).cost;
                    if (kingdom.at(i).setup)
                        cout << " *";
                    i++;
                    cout << endl;
                }
            }

            if (kingdom_contains_set("Guilds")) {
                cout << "\tGuilds:\n";
                while (i < kingdom.size() && kingdom.at(i).set == "Guilds") {
                    if (full_deck.at(position_of(kingdom.at(i).name)).bane)
                        cout << "\tBane: ";
                    cout << "\t\t" << kingdom.at(i).name << " " <<
                            kingdom.at(i).cost;
                    if (kingdom.at(i).setup)
                        cout << " *";
                    i++;
                    cout << endl;
                }
            }

            if (kingdom_contains_set("Promotional")) {
                cout << "\tPromotional:\n";
                while (i < kingdom.size() && kingdom.at(i).set == "Promotional") {
                    if (full_deck.at(position_of(kingdom.at(i).name)).bane)
                        cout << "\tBane: ";
                    cout << "\t\t" << kingdom.at(i).name << " " <<
                            kingdom.at(i).cost;
                    if (kingdom.at(i).setup)
                        cout << " *";
                    i++;
                    cout << endl;
                }
            }

            if (setup)
                cout << "\n* requires special setup\n";

            break;
            //      default:
            //          cout << "Sort spec not read.\n";
            //          break;

    }

    if (last) // print supply
    {
        // determine how many of each supply card is necessary
        int estates, duchies, provinces, colonies, curses;
        int coppers, silvers, golds;
        int players = get_spec("Number of Players");
        bool error = false;
        bool potions = false;

        switch (players) {
            case 2:
                estates = 8;
                provinces = 8;
                curses = 10;
                coppers = 60;
                silvers = 40;
                golds = 30;
                break;
            case 3:
                estates = 12;
                provinces = 12;
                curses = 20;
                coppers = 60;
                silvers = 40;
                golds = 30;
                break;
            case 4:
                estates = 12;
                provinces = 12;
                curses = 30;
                coppers = 60;
                silvers = 40;
                golds = 30;
                break;
            case 5:
                estates = 12;
                provinces = 15;
                curses = 40;
                coppers = 120;
                silvers = 80;
                golds = 60;
                break;
            case 6:
                estates = 12;
                provinces = 18;
                curses = 50;
                coppers = 120;
                silvers = 80;
                golds = 60;
                break;
            default:
                error = true;
                break;
        }
        if (error)
            cout << "Invalid player count. Check Kingdom Specifications.\n";
        else {
            duchies = estates;
            colonies = estates;

            switch (PC) {
                case 1:
                    CP = true;
                    break;
                case 2:
                    CP = false;
                    break;
                case 3:
                    // decide whether to use platinums, colonies, and shelters
                    switch (rand() % 5) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        {
                            float costs = 0;
                            for (int i = 0; i < kingdom.size(); i++) {
                                string type = kingdom.at(i).type;
                                if (int(kingdom.at(i).cost * 2.0) % 2 == 1)
                                    costs += 1;
                                if (type == "Action-Attack" || type == "Action-Attack-Duration" ||
                                        type == "Treasure-Attack")
                                    costs += kingdom.at(i).cost * 0.5;
                                else
                                    costs += kingdom.at(i).cost;
                            }
                            if (kingdom_contains("Peddler"))
                                costs -= 4;

                            if (costs >= 39.5)
                                CP = true;
                            else if (costs <= 34)
                                CP = false;
                            else {
                                Card card = kingdom.at(rand() % kingdom.size());
                                if (card.set == "Prosperity")
                                    CP = true;
                            }
                        }
                            break;
                        case 4:
                            Card card = kingdom.at(rand() % kingdom.size());
                            if (card.set == "Prosperity")
                                CP = true;
                            break;
                    }

                    break;
            }

            switch (shelter) {
                case 1:
                    shelters = true;
                    break;
                case 2:
                    shelters = false;
                    break;
                case 3:
                    if (!kingdom_contains("Baron")) {
                        Card card = kingdom.at(rand() % kingdom.size());
                        if (card.set == "Dark_Ages")
                            shelters = true;
                    }
            }

            if (!shelters)
                estates += 3 * players;

            cout << "Supply cards for " << players << " players:\n\tEstates: " << estates << "\tDuchies: " <<
                    duchies << "\tProvinces: " << provinces;
            if (CP)
                cout << "\tColonies: " << colonies;

            cout << "\tCurses: " << curses << "\n\tCoppers: " << coppers <<
                    "\tSilvers: " << silvers << "\tGolds: " << golds;

            // see if potions are needed
            for (int i = 0; i < kingdom.size(); i++) {
                if ((int) (kingdom.at(i).cost * 2) % 2 == 1)
                    potions = true;
            }
            if (potions)
                cout << "\tPotions: 16";

            if (CP)
                cout << "\tPlatinums: 12";

            if (shelters) {
                cout << "\n\tNecropolis: " << players << "\tOvergrown_Estate: " <<
                        players << "\tHovel: " << players;
            }
            cout << endl;

            string first_type[] = {"Cultist", "Death_Cart", "Marauder", "Bandit_Camp", "Pillage", "Tournament", "Hermit", "Urchin"};
            vector <string> First_Type(begin(first_type), end(first_type));
            if (kingdom_contains(1, First_Type)) {
                if (kingdom_contains("Cultist") || kingdom_contains("Death_Cart") || kingdom_contains("Marauder"))
                    cout << "\tRuins: " << curses;

                if (kingdom_contains("Bandit_Camp") || kingdom_contains("Marauder") || kingdom_contains("Pillage"))
                    cout << "\tSpoils: 15";

                if (kingdom_contains("Tournament"))
                    cout << "\tPrizes: 5";

                if (kingdom_contains("Hermit"))
                    cout << "\tMadman: 10";

                if (kingdom_contains("Urchin"))
                    cout << "\tMercenary: 10";
                cout << endl;
            }

            string second_type[] = {"Bishop", "Monument", "Goons"};
            vector <string> SecondType(begin(second_type), end(second_type));
            if (reserve_count > 0 || kingdom_contains(1, SecondType)) {
                if (kingdom_contains("Bishop") || kingdom_contains("Monument") || kingdom_contains("Goons"))
                    cout << "VP tokens and mats";
                if (kingdom_contains("Pirate_Ship"))
                    cout << "\tCoin tokens and Pirate Ship mats";
                if (kingdom_contains("Island"))
                    cout << "\tIsland mats";
                if (kingdom_contains("Native_Village"))
                    cout << "\tNative Village mats";
                if (kingdom_contains("Trade_Route"))
                    cout << "\tCoin tokens and Trade Route mat";
                if (kingdom_contains("Baker") || kingdom_contains("Butcher") || kingdom_contains("Candlestick_Maker") ||
                        kingdom_contains("Merchant_Guild"))
                    cout << "\tCoin tokens";
                if (kingdom_contains("Embargo"))
                    cout << "\tEmbargo tokens";
                if (kingdom_contains("Black_Market"))
                    cout << "\tBlack Market deck";
                if (reserve_count > 0 || kingdom_contains("Miser"))
                    cout << "\tTavern Mats";

                cout << endl;
            }

            string third_type[] = {""};
            vector <string> ThirdType(begin(third_type), end(third_type));
            if (kingdom_contains(1, ThirdType)) {
                if (kingdom_contains("Bridge_Troll"))
                    cout << "-Coin tokens";
                if (kingdom_contains("Giant"))
                    cout << "\tJourney tokens";
                cout << endl;
            }

            string fourth_type[] = {""};
            vector <string> FourthType(begin(fourth_type), end(fourth_type));
            if (kingdom_contains(1, FourthType)) {

            }

            if (kingdom_contains("Page"))
                cout << "Treasure Hunter: 5\tWarrior: 5\tHero: 5\tChampion: 5\n";
            if (kingdom_contains("Peasant")) {
                cout << "Soldier: 5\tFugitive: 5\tDisciple: 5\tTeacher: 5\n" <<
                        "+1 card tokens, +1 action tokens, +1 buy tokens, +1 coin tokens\n";

            }
            if (players == 2) {
                for (int i = 0; i < kingdom.size(); i++) {
                    if (kingdom.at(i).type == "Victory" || kingdom.at(i).type == "Action-Victory" ||
                            kingdom.at(i).type == "Treasure-Victory" || kingdom.at(i).type == "Victory-Reaction")
                        cout << "Only include 8 copies of " << kingdom.at(i).name << endl;
                }
            }
        }
    }
}

void Deck::sort_kingdom() {
    vector <int> numbers;
    int cards;

    switch ((int) get_spec("Sorting Method")) {
        case 1:
        {
            numbers.clear();
            cards = 0;

            // sort cost 0P first
            for (int i = cards; i < kingdom.size(); i++) {
                if (kingdom.at(i).cost == 0.5)
                    numbers.push_back(i);
            }

            if (!numbers.empty()) {
                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize cost 0P cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
            }

            cards += numbers.size();
            numbers.clear();


            // sort cost 1 next
            for (int i = cards; i < kingdom.size(); i++) {
                if (kingdom.at(i).cost == 1)
                    numbers.push_back(i);
            }

            if (!numbers.empty()) {
                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize cost 1 cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
            }

            cards += numbers.size();
            numbers.clear();


            // sort cost 2 next
            for (int i = cards; i < kingdom.size(); i++) {
                if (kingdom.at(i).cost == 2)
                    numbers.push_back(i);
            }

            if (!numbers.empty()) {
                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize cost 2 cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
            }

            cards += numbers.size();
            numbers.clear();


            // sort cost 2P next
            for (int i = cards; i < kingdom.size(); i++) {
                if (kingdom.at(i).cost == 2.5)
                    numbers.push_back(i);
            }

            if (!numbers.empty()) {
                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize cost 0 cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
            }

            cards += numbers.size();
            numbers.clear();


            // sort cost 3 next
            for (int i = cards; i < kingdom.size(); i++) {
                if (kingdom.at(i).cost == 3)
                    numbers.push_back(i);
            }

            if (!numbers.empty()) {
                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize cost 3 cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
            }

            cards += numbers.size();
            numbers.clear();


            // sort cost 3P next
            for (int i = cards; i < kingdom.size(); i++) {
                if (kingdom.at(i).cost == 3.5)
                    numbers.push_back(i);
            }

            if (!numbers.empty()) {
                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize cost 3P cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
            }

            cards += numbers.size();
            numbers.clear();


            // sort cost 4 next
            for (int i = cards; i < kingdom.size(); i++) {
                if (kingdom.at(i).cost == 4)
                    numbers.push_back(i);
            }

            if (!numbers.empty()) {
                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize cost 4 cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
            }

            cards += numbers.size();
            numbers.clear();


            // sort cost 4P next
            for (int i = cards; i < kingdom.size(); i++) {
                if (kingdom.at(i).cost == 4.5)
                    numbers.push_back(i);
            }

            if (!numbers.empty()) {
                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize cost 4P cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
            }

            cards += numbers.size();
            numbers.clear();


            // sort cost 5 next
            for (int i = cards; i < kingdom.size(); i++) {
                if (kingdom.at(i).cost == 5)
                    numbers.push_back(i);
            }

            if (!numbers.empty()) {
                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize cost 5 cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
            }

            cards += numbers.size();
            numbers.clear();


            // sort cost 6 next
            for (int i = cards; i < kingdom.size(); i++) {
                if (kingdom.at(i).cost == 6)
                    numbers.push_back(i);
            }

            if (!numbers.empty()) {
                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize cost 6 cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
            }

            cards += numbers.size();
            numbers.clear();


            // sort cost 6P next
            for (int i = cards; i < kingdom.size(); i++) {
                if (kingdom.at(i).cost == 6.5)
                    numbers.push_back(i);
            }

            if (!numbers.empty()) {
                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize cost 6P cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
            }

            cards += numbers.size();
            numbers.clear();


            // sort cost 7 next
            for (int i = cards; i < kingdom.size(); i++) {
                if (kingdom.at(i).cost == 7)
                    numbers.push_back(i);
            }

            if (!numbers.empty()) {
                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize cost 7 cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
            }

            cards += numbers.size();
            numbers.clear();


            // sort cost 8 next
            for (int i = 0; i < kingdom.size(); i++) {
                if (kingdom.at(i).cost == 8)
                    numbers.push_back(i);
            }

            if (!numbers.empty()) {
                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize cost 8 cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
            }

            cards += numbers.size();
            numbers.clear();
        }
            break;

        case 2:
            for (int j = 0; j < kingdom.size() - 1; j++) {
                for (int i = 0; i < kingdom.size() - 1; i++) {
                    if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                        swap_cards(kingdom.at(i), kingdom.at(i + 1));
                }
            }
            break;

        case 3:
            numbers.clear();
            cards = 0;

            // sort Castle at front
            if (kingdom_contains_set("Castle")) {
                for (int i = 0; i < kingdom.size(); i++) {
                    if (kingdom.at(i).set == "Castle")
                        numbers.push_back(i);
                }

                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize Castle cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
                cards += numbers.size();
                numbers.clear();
            }

            // sort Intrigue next
            if (kingdom_contains_set("Intrigue")) {
                for (int i = 0; i < kingdom.size(); i++) {
                    if (kingdom.at(i).set == "Intrigue")
                        numbers.push_back(i);
                }

                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize Intrigue cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
                cards += numbers.size();
                numbers.clear();
            }

            // sort Seaside next
            if (kingdom_contains_set("Seaside")) {
                for (int i = 0; i < kingdom.size(); i++) {
                    if (kingdom.at(i).set == "Seaside")
                        numbers.push_back(i);
                }

                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize Seaside cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
                cards += numbers.size();
                numbers.clear();
            }

            // sort Alchemy next
            if (kingdom_contains_set("Alchemy")) {
                for (int i = 0; i < kingdom.size(); i++) {
                    if (kingdom.at(i).set == "Alchemy")
                        numbers.push_back(i);
                }

                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize Alchemy cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
                cards += numbers.size();
                numbers.clear();
            }

            // sort Prosperity next
            if (kingdom_contains_set("Prosperity")) {
                for (int i = 0; i < kingdom.size(); i++) {
                    if (kingdom.at(i).set == "Prosperity")
                        numbers.push_back(i);
                }

                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize Prosperity cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
                cards += numbers.size();
                numbers.clear();
            }

            // sort Cornucopia next
            if (kingdom_contains_set("Cornucopia")) {
                for (int i = 0; i < kingdom.size(); i++) {
                    if (kingdom.at(i).set == "Cornucopia")
                        numbers.push_back(i);
                }

                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize Cornucopia cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
                cards += numbers.size();
                numbers.clear();
            }

            // sort Hinterlands next
            if (kingdom_contains_set("Hinterlands")) {
                for (int i = 0; i < kingdom.size(); i++) {
                    if (kingdom.at(i).set == "Hinterlands")
                        numbers.push_back(i);
                }

                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize Hinterlands cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
                cards += numbers.size();
                numbers.clear();
            }

            // sort Dark_Ages next
            if (kingdom_contains_set("Dark_Ages")) {
                for (int i = 0; i < kingdom.size(); i++) {
                    if (kingdom.at(i).set == "Dark_Ages")
                        numbers.push_back(i);
                }

                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize Dark_Ages cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
                cards += numbers.size();
                numbers.clear();
            }

            // sort Guilds next
            if (kingdom_contains_set("Guilds")) {
                for (int i = 0; i < kingdom.size(); i++) {
                    if (kingdom.at(i).set == "Guilds")
                        numbers.push_back(i);
                }

                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize Guilds cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
                cards += numbers.size();
                numbers.clear();
            }

            // sort Promotional next
            if (kingdom_contains_set("Promotional")) {
                for (int i = 0; i < kingdom.size(); i++) {
                    if (kingdom.at(i).set == "Promotional")
                        numbers.push_back(i);
                }

                int k = 0;
                while (k < numbers.size() && cards + k < kingdom.size()) {
                    swap_cards(kingdom.at(numbers.at(k)), kingdom.at(cards + k));
                    k++;
                }

                // alphabetize Promotional cards
                for (int j = cards; j < cards + numbers.size() - 1; j++) {
                    for (int i = cards; i < cards + numbers.size() - 1; i++) {
                        if (compare_strings(kingdom.at(i).name, kingdom.at(i + 1).name, 0) == kingdom.at(i + 1).name)
                            swap_cards(kingdom.at(i), kingdom.at(i + 1));
                    }
                }
                cards += numbers.size();
                numbers.clear();
            }
            break;

        default:
            cout << "Sort spec not read.\n";
            exit(EXIT_FAILURE);
            break;
    }
}

void Deck::swap_cards(Card& card1, Card& card2) {
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}

string Deck::compare_strings(string string1, string string2, int pos) {
    if (string1[pos] < string2[pos])
        return string1;
    else if (string2[pos] < string1[pos])
        return string2;
    else if (pos + 1 < string1.length() && pos + 1 < string2.length())
        return compare_strings(string1, string2, pos + 1);
    else if (pos + 1 < string2.length())
        return string1;
    else
        return string2;
}

void Deck::reset_uses() {
    cout << "Are you sure you wish to reset use count for all Dominion cards?\n" <<
            "(1 for yes, 0 for no)\n";
    int response;
    cin >> response;
    cout << endl;

    switch (response) {
        case 0:
            cout << "Use count NOT reset.\n";
            break;
        case 1:
            for (int i = 0; i < full_deck.size(); i++)
                full_deck.at(i).uses = 0;
            cout << "Use count for all Dominion cards has been reset.\n";
            break;
        default:
            break;
    }
}

void Deck::reset_rankings() {
    cout << "Are you sure you wish to reset rankings for all Dominion cards?\n" <<
            "(1 for yes, 0 for no)\n";
    int response;
    cin >> response;
    cout << endl;

    switch (response) {
        case 0:
            cout << "Rankings not reset.\n";
            break;
        case 1:
            for (int i = 0; i < full_deck.size(); i++)
                full_deck.at(i).rank = 0;
            cout << "Rankings for all Dominion cards have been reset.\n";
            break;
        default:
            break;
    }
}

void Deck::erase_player_data() {
    // Open output file
    string filename = "Dominion cards.txt";
    ofstream dout;
    dout.open(filename.c_str());
    if (dout.fail()) {
        // couldn't find file
        return;
    }
    dout << "";
    dout.close();

    // Open output file
    filename = "Player game data.txt";
    dout.open(filename.c_str());
    if (dout.fail()) {
        // couldn't find file
        return;
    }
    dout << "";
    dout.close();

    players.clear();

    cout << "All player data cleared.\n";
}

string Deck::tokenize(string &token, char delim) {
    string piece = "";
    int i = 0;

    while (i < token.size() && token[i] != delim)
        i++;

    if (i > 0)
        piece = token.substr(0, i);

    if (i < token.size())
        token = token.substr(i + 1, token.size());
    else
        token = token.substr(i, token.size());
    return piece;
}

void Deck::select_kingdom() {
    int attempts = 1;
    srand(time(NULL));
    bool already;

    do {
        // reset stuff if needed
        if (!kingdom.empty()) {
            for (int i = 0; i < kingdom.size(); i++) {
                full_deck.at(position_of(kingdom.at(i).name)).bane = false;
            }
            kingdom.clear();
        }

        castle_count = 0;
        intrigue_count = 0;
        seaside_count = 0;
        alchemy_count = 0;
        prosperity_count = 0;
        cornucopia_count = 0;
        hinterlands_count = 0;
        dark_ages_count = 0;
        guilds_count = 0;
        adventures_count = 0;
        cards_count = 0;
        actions_count = 0;
        buys_count = 0;
        coins_count = 0;
        attacks_count = 0;
        trashers_count = 0;
        duration_count = 0;
        treasure_count = 0;
        victory_count = 0;
        reserve_count = 0;
        event_count = 0;
        speed_count = 0;
        action3_count = 0;
        action4_count = 0;
        action5_count = 0;
        action6_count = 0;
        action7_count = 0;
        action2_count2 = 0;
        action2_count3 = 0;
        action2_count4 = 0;
        action2_count5 = 0;
        action2_count6 = 0;
        cost1_count = 0;
        cost2_count = 0;
        cost3_count = 0;
        cost4_count = 0;
        cost5_count = 0;
        cost6_count = 0;
        cost7_count = 0;
        potion_count = 0;
        CP = false;
        shelters = false;
        reason = "";

        for (int i = 0; i < full_deck.size(); i++) {
            if (full_deck.at(i).whitelisted_helper || full_deck.at(i).whitelisted) {
                full_deck.at(i).whitelisted = true;
                full_deck.at(i).whitelisted_helper = true;
            }
        }

        bool done = false;
        do {
            // search for whitelisted cards
            Card* chosen = NULL;
            for (int i = full_deck.size() - 1; i >= 0; i--) {
                if (full_deck.at(i).whitelisted)
                    chosen = &full_deck.at(i);
            }

            if (chosen != NULL) {
                chosen->whitelisted = false;
                add_to_kingdom(chosen->name);
            } else
                done = true;
        } while (!done && kingdom.size() < 10);

        already = false;

        if (attempts <= 10) {
            cout << "Attempt #" << attempts << "\n";
            already = true;
        } else if (attempts > 10 && attempts <= 100 && attempts % 10 == 0) {
            cout << "Attempt #" << attempts << "\n";
            already = true;
        } else if (attempts > 100 && attempts <= 1000 && attempts % 100 == 0) {
            cout << "Attempt #" << attempts << "\n";
            already = true;
        } else if (attempts > 1000 && attempts <= 100000 && attempts % 1000 == 0) {
            cout << "Attempt #" << attempts << "\n";
            already = true;
        } else if (attempts % 10000 == 0) {
            cout << "Attempt #" << attempts << "\n";
            already = true;
        }
        attempts++;

        /* choose 10 cards from deck, based on
         rank and uses */

        while (kingdom.size() < 10) {
            string card = generate_card();
            add_to_kingdom(card);
        }
        // (below) filter for overall kingdom
    } while (!check_kingdom());

    // print successful attempt # if it has not already been printed
    if (!already)
        cout << "Attempt #" << attempts << "\n";

    // increment use count for cards in this kingdom
    for (int i = 0; i < kingdom.size(); i++) {
        full_deck.at(position_of(kingdom.at(i).name)).uses++;
    }
    
    for (int i = 0; i < full_deck.size(); i++)
        full_deck.at(i).previous = false;
}

bool Deck::replace_card(string card) {
    if (remove_from_kingdom(card)) // if card exists
    {
        string replacement = generate_card();
        add_to_kingdom(replacement);

        if (check_kingdom())
            return true;
        else
            return replace_card(replacement);
    } else
        return false;
}

string Deck::generate_card() {
    int rand1, rand2, rand3, rand4, rand5;
    int size = game_deck.size();
    Card* chosen;

    // choose 4 random cards
    rand1 = rand() % size;
    rand2 = rand() % size;
    rand3 = rand() % size;
    rand4 = rand() % size;
    rand5 = rand() % size;

    // make variables for brevity's sake
    int card1_score = ((-1 * game_deck.at(rand1).rank) + 5) * game_deck.at(rand1).uses;
    int card2_score = ((-1 * game_deck.at(rand2).rank) + 5) * game_deck.at(rand2).uses;
    int card3_score = ((-1 * game_deck.at(rand3).rank) + 5) * game_deck.at(rand3).uses;
    int card4_score = ((-1 * game_deck.at(rand4).rank) + 5) * game_deck.at(rand4).uses;
    int card5_score = ((-1 * game_deck.at(rand5).rank) + 5) * game_deck.at(rand5).uses;

    // find most appropriate of these 5 random cards (smallest "score")
    if ((card1_score <= card2_score) && (card1_score <= card3_score) &&
            (card1_score <= card4_score) && (card1_score <= card5_score))
        chosen = &game_deck.at(rand1);
    else if ((card2_score <= card3_score) && (card2_score <= card4_score) &&
            (card2_score <= card5_score))
        chosen = &game_deck.at(rand2);
    else if ((card3_score <= card4_score) && (card3_score <= card5_score))
        chosen = &game_deck.at(rand3);
    else if (card4_score <= card5_score)
        chosen = &game_deck.at(rand4);
    else
        chosen = &game_deck.at(rand5);

    if (kingdom_contains(chosen->name)) // if already in kingdom
        return generate_card();
    else
        return chosen->name;
}

bool Deck::add_to_kingdom(string card) {
    Card* chosen = NULL;
    int pos = position_of(card);

    if (pos != -1)
        chosen = &full_deck.at(pos);

    // add card to kingdom
    if (chosen == NULL) {
        cout << card << " not found in deck.\n";
        return false;
    } else {
        kingdom.push_back(*chosen);
        cards_count += chosen->cards;
        actions_count += chosen->actions;
        buys_count += chosen->buys;
        coins_count += chosen->coins;
        trashers_count += chosen->trasher;
        speed_count += chosen->speed;

        string type = chosen->type;
        if (type == "Action-Attack" || type == "Action-Attack-Duration" || type == "Treasure-Attack")
            attacks_count++;
        if (type == "Action-Duration" || type == "Action-Attack-Duration" || type == "Action-Duration-Reaction")
            duration_count++;
        if (type == "Treasure" || type == "Treasure-Attack" || type == "Treasure-Victory" ||
                type == "Treasure-Reaction" || type == "Treasure-Reserve")
            treasure_count++;
        if (type == "Victory" || type == "Treasure-Victory" ||
                type == "Victory-Reaction" || type == "Action-Victory" || type == "Action-Reserve-Victory")
            victory_count++;
        if (type == "Action-Reserve" || type == "Action-Reserve-Victory" || type == "Treasure-Reserve")
            reserve_count++;
        if (type == "Event")
            event_count++;
        if ((int) (chosen->cost * 2) % 2 == 1)
            potion_count++;

        switch ((int) chosen->cost) {
            case 1:
                cost1_count++;
                break;
            case 2:
                cost2_count++;
                if (chosen->actions >= 2)
                    action2_count2++;
                break;
            case 3:
                cost3_count++;
                if (type == "Action" || type == "Action-Attack" ||
                        type == "Action-Duration" || type == "Action-Attack-Duration" ||
                        type == "Action-Duration-Reaction" || type == "Action-Reserve-Victory" ||
                        type == "Action-Victory" || type == "Action-Reserve" ||
                        type == "Action-Traveller")
                    action3_count++;
                if (chosen->actions >= 2)
                    action2_count3++;
                break;
            case 4:
                cost4_count++;
                if (type == "Action" || type == "Action-Attack" ||
                        type == "Action-Duration" || type == "Action-Attack-Duration" ||
                        type == "Action-Duration-Reaction" || type == "Action-Reserve-Victory" ||
                        type == "Action-Victory" || type == "Action-Reserve" ||
                        type == "Action-Traveller")
                    action4_count++;
                if (chosen->actions >= 2)
                    action2_count4++;
                break;
            case 5:
                cost5_count++;
                if (type == "Action" || type == "Action-Attack" ||
                        type == "Action-Duration" || type == "Action-Attack-Duration" ||
                        type == "Action-Duration-Reaction" || type == "Action-Reserve-Victory" ||
                        type == "Action-Victory" || type == "Action-Reserve" ||
                        type == "Action-Traveller")
                    action5_count++;
                if (chosen->actions >= 2)
                    action2_count5++;
                break;
            case 6:
                cost6_count++;
                if (type == "Action" || type == "Action-Attack" ||
                        type == "Action-Duration" || type == "Action-Attack-Duration" ||
                        type == "Action-Duration-Reaction" || type == "Action-Reserve-Victory" ||
                        type == "Action-Victory" || type == "Action-Reserve" ||
                        type == "Action-Traveller")
                    action6_count++;
                if (chosen->actions >= 2)
                    action2_count6++;
                break;
            case 7:
                cost7_count++;
                if (type == "Action" || type == "Action-Attack" ||
                        type == "Action-Duration" || type == "Action-Attack-Duration" ||
                        type == "Action-Duration-Reaction" || type == "Action-Reserve-Victory" ||
                        type == "Action-Victory" || type == "Action-Reserve" ||
                        type == "Action-Traveller")
                    action7_count++;
                break;
            default:
                break;
        }

        if (chosen->set == "Castle")
            castle_count++;
        else if (chosen->set == "Intrigue")
            intrigue_count++;
        else if (chosen->set == "Seaside")
            seaside_count++;
        else if (chosen->set == "Alchemy")
            alchemy_count++;
        else if (chosen->set == "Prosperity")
            prosperity_count++;
        else if (chosen->set == "Cornucopia")
            cornucopia_count++;
        else if (chosen->set == "Hinterlands")
            hinterlands_count++;
        else if (chosen->set == "Dark_Ages")
            dark_ages_count++;
        else if (chosen->set == "Guilds")
            guilds_count++;
        else if (chosen->set == "Adventures")
            adventures_count++;
    }
    return true;
}

bool Deck::remove_from_kingdom(string card) {
    int k; // place of card in kingdom
    int d; // place of card in deck

    if (!kingdom_contains(card, k)) {
        cout << card << " not found in kingdom.\n";
        return false;
    } else {
        d = position_of(card);
        // remove
        kingdom.erase(kingdom.begin() + k);
        cards_count -= full_deck.at(d).cards;
        actions_count -= full_deck.at(d).actions;
        buys_count -= full_deck.at(d).buys;
        coins_count -= full_deck.at(d).coins;
        trashers_count -= full_deck.at(d).trasher;
        speed_count -= full_deck.at(d).speed;

        string type = full_deck.at(d).type;
        if (type == "Action-Attack" || type == "Action-Attack-Duration" || type == "Treasure-Attack")
            attacks_count--;

        if (type == "Action-Duration" || type == "Action-Attack-Duration" || type == "Action-Duration-Reaction")
            duration_count--;

        if (type == "Treasure" || type == "Treasure-Attack" || type == "Treasure-Victory" ||
                type == "Treasure-Reaction" || type == "Treasure-Reserve")
            treasure_count--;

        if (type == "Victory" || type == "Treasure-Victory" ||
                type == "Victory-Reaction" || type == "Action-Victory" || type == "Action-Reserve-Victory")
            victory_count--;

        if (type == "Action-Reserve" || type == "Action-Reserve-Victory" || type == "Treasure-Reserve")
            reserve_count--;

        if ((int) (full_deck.at(d).cost * 2) % 2 == 1)
            potion_count--;

        switch ((int) full_deck.at(d).cost) {
            case 1:
                cost1_count--;
                break;
            case 2:
                cost2_count--;
                if (full_deck.at(d).actions >= 2)
                    action2_count2--;
                break;
            case 3:
                cost3_count--;
                if (type == "Action" || type == "Action-Attack" ||
                        type == "Action-Duration" || type == "Action-Attack-Duration" ||
                        type == "Action-Duration-Reaction" || type == "Action-Reserve-Victory" ||
                        type == "Action-Victory" || type == "Action-Reserve" ||
                        type == "Action-Traveller")
                    action3_count--;
                if (full_deck.at(d).actions >= 2)
                    action2_count3--;
                break;
            case 4:
                cost4_count--;
                if (type == "Action" || type == "Action-Attack" ||
                        type == "Action-Duration" || type == "Action-Attack-Duration" ||
                        type == "Action-Duration-Reaction" || type == "Action-Reserve-Victory" ||
                        type == "Action-Victory" || type == "Action-Reserve" ||
                        type == "Action-Traveller")
                    action4_count--;
                if (full_deck.at(d).actions >= 2)
                    action2_count4--;
                break;
            case 5:
                cost5_count--;
                if (type == "Action" || type == "Action-Attack" ||
                        type == "Action-Duration" || type == "Action-Attack-Duration" ||
                        type == "Action-Duration-Reaction" || type == "Action-Reserve-Victory" ||
                        type == "Action-Victory" || type == "Action-Reserve" ||
                        type == "Action-Traveller")
                    action5_count--;
                if (full_deck.at(d).actions >= 2)
                    action2_count5--;
                break;
            case 6:
                cost6_count--;
                if (type == "Action" || type == "Action-Attack" ||
                        type == "Action-Duration" || type == "Action-Attack-Duration" ||
                        type == "Action-Duration-Reaction" || type == "Action-Reserve-Victory" ||
                        type == "Action-Victory" || type == "Action-Reserve" ||
                        type == "Action-Traveller")
                    action6_count--;
                if (full_deck.at(d).actions >= 2)
                    action2_count6--;
                break;
            case 7:
                cost7_count--;
                if (type == "Action" || type == "Action-Attack" ||
                        type == "Action-Duration" || type == "Action-Attack-Duration" ||
                        type == "Action-Duration-Reaction" || type == "Action-Reserve-Victory" ||
                        type == "Action-Victory" || type == "Action-Reserve" ||
                        type == "Action-Traveller")
                    action7_count--;
                break;
            default:
                break;
        }
        if (full_deck.at(d).set == "Castle")
            castle_count--;
        else if (full_deck.at(d).set == "Intrigue")
            intrigue_count--;
        else if (full_deck.at(d).set == "Seaside")
            seaside_count--;
        else if (full_deck.at(d).set == "Alchemy")
            alchemy_count--;
        else if (full_deck.at(d).set == "Prosperity")
            prosperity_count--;
        else if (full_deck.at(d).set == "Cornucopia")
            cornucopia_count--;
        else if (full_deck.at(d).set == "Hinterlands")
            hinterlands_count--;
        else if (full_deck.at(d).set == "Dark_Ages")
            dark_ages_count--;
        else if (full_deck.at(d).set == "Adventures")
            adventures_count--;
    }
    return true;
}

bool Deck::check_kingdom() {
    if (kingdom_contains("Young_Witch")) {
        // select bane card
        Card* chosen;
        string card;
        do {
            card = generate_card();
            chosen = &full_deck.at(position_of(card));
        }        while (chosen->cost != 2.0 && chosen->cost != 3.0);

        chosen->bane = true;

        // add it to kingdom
        add_to_kingdom(card);
    }
    for (int i = 0; i < event_count; i++) {
        string card = generate_card();
        add_to_kingdom(card);
    }

    switch ((int) get_spec("Speed Rating")) {
        case 0:
            break;
        case 1:
            for (int i = 0; i < kingdom.size(); i++) {
                if (kingdom.at(i).speed >= 11) {
                    reason = "too fast";
                    return false;
                }
            }
            if (speed_count > 70) {
                reason = "too fast";
                return false;
            }
            break;
        case 2:
            if (speed_count < 65 || speed_count > 95) {
                reason = "too slow or too fast";
                return false;
            }
            break;
        case 3:
            for (int i = 0; i < kingdom.size(); i++) {
                if (kingdom.at(i).speed <= 6) {
                    reason = "too slow";
                    return false;
                }
            }
            if (speed_count < 87) {
                reason = "too slow";
                return false;
            }
            break;
        default:
            cout << "Speed Rating not read.\n";
            break;
    }

    // check for incorrect number of card types
    if (castle_count < get_spec("Lower bound for Castle cards")) {
        reason = "too few castle cards";
        return false;
    }
    if (castle_count > get_spec("Upper bound for Castle cards")) {
        reason = "too many castle cards";
        return false;
    }
    if (intrigue_count < get_spec("Lower bound for Intrigue cards")) {
        reason = "too few intrigue cards";
        return false;
    }
    if (intrigue_count > get_spec("Upper bound for Intrigue cards")) {
        reason = "too many intrigue cards";
        return false;
    }
    if (seaside_count < get_spec("Lower bound for Seaside cards")) {
        reason = "too few seaside cards";
        return false;
    }
    if (seaside_count > get_spec("Upper bound for Seaside cards")) {
        reason = "too many seaside cards";
        return false;
    }
    if (alchemy_count < get_spec("Lower bound for Alchemy cards")) {
        reason = "too few alchemy cards";
        return false;
    }
    if (alchemy_count > get_spec("Upper bound for Alchemy cards")) {
        reason = "too many alchemy cards";
        return false;
    }
    if (prosperity_count < get_spec("Lower bound for Prosperity cards")) {
        reason = "too few prosperity cards";
        return false;
    }
    if (prosperity_count > get_spec("Upper bound for Prosperity cards")) {
        reason = "too many prosperity cards";
        return false;
    }
    if (cornucopia_count < get_spec("Lower bound for Cornucopia cards")) {
        reason = "too few cornucopia cards";
        return false;
    }
    if (cornucopia_count > get_spec("Upper bound for Cornucopia cards")) {
        reason = "too many cornucopia cards";
        return false;
    }
    if (hinterlands_count < get_spec("Lower bound for Hinterlands cards")) {
        reason = "too few hinterlands cards";
        return false;
    }
    if (hinterlands_count > get_spec("Upper bound for Hinterlands cards")) {
        reason = "too many hinterlands cards";
        return false;
    }
    if (dark_ages_count < get_spec("Lower bound for Dark Ages cards")) {
        reason = "too few dark ages cards";
        return false;
    }
    if (dark_ages_count > get_spec("Upper bound for Dark Ages cards")) {
        reason = "too many dark ages cards";
        return false;
    }
    if (guilds_count < get_spec("Lower bound for Guilds cards")) {
        reason = "too few guilds cards";
        return false;
    }
    if (guilds_count > get_spec("Upper bound for Guilds cards")) {
        reason = "too many guilds cards";
        return false;
    }
    if (adventures_count < get_spec("Lower bound for Adventures cards")) {
        reason = "too few adventures cards";
        return false;
    }
    if (adventures_count > get_spec("Upper bound for Adventures cards")) {
        reason = "too many adventures cards";
        return false;
    }

    if (cards_count < get_spec("Lower bound for +cards")) {
        reason = "too few +cards";
        return false;
    }
    if (cards_count > get_spec("Upper bound for +cards")) {
        reason = "too many +cards";
        return false;
    }

    if (actions_count < get_spec("Lower bound for +actions")) {
        reason = "too few +actions";
        return false;
    }
    if (actions_count > get_spec("Upper bound for +actions")) {
        reason = "too many +actions";
        return false;
    }

    if (buys_count < get_spec("Lower bound for +buys")) {
        reason = "too few +buys";
        return false;
    }
    if (buys_count > get_spec("Upper bound for +buys")) {
        reason = "too many +buys";
        return false;
    }

    if (coins_count < get_spec("Lower bound for +coins")) {
        reason = "too few +coins";
        return false;
    }
    if (coins_count > get_spec("Upper bound for +coins")) {
        reason = "too many +coins";
        return false;
    }


    if (attacks_count < get_spec("Lower bound for attack cards")) {
        reason = "too few attacks";
        return false;
    }
    if (attacks_count > get_spec("Upper bound for attack cards")) {
        reason = "too many attacks";
        return false;
    }

    if (trashers_count < get_spec("Lower bound for Trasher cards")) {
        reason = "too few trashers";
        return false;
    }
    if (trashers_count > get_spec("Upper bound for Trasher cards")) {
        reason = "too many trashers";
        return false;
    }

    if (duration_count < get_spec("Lower bound for Duration cards")) {
        reason = "too few duration cards";
        return false;
    }
    if (duration_count > get_spec("Upper bound for Duration cards")) {
        reason = "too many duration cards";
        return false;
    }

    if (treasure_count < get_spec("Lower bound for Treasure cards")) {
        reason = "too few treasure cards";
        return false;
    }
    if (treasure_count > get_spec("Upper bound for Treasure cards")) {
        reason = "too many treasure cards";
        return false;
    }

    if (victory_count < get_spec("Lower bound for Victory cards")) {
        reason = "too few victory cards";
        return false;
    }
    if (victory_count > get_spec("Upper bound for Victory cards")) {
        reason = "too many victory cards";
        return false;
    }

    if (reserve_count < get_spec("Lower bound for Reserve cards")) {
        reason = "too few reserve cards";
        return false;
    }
    if (reserve_count > get_spec("Upper bound for Reserve cards")) {
        reason = "too many reserve cards";
        return false;
    }
    
    if (event_count < get_spec("Lower bound for Event cards")) {
        reason = "too few event cards";
        return false;
    }
    if (event_count > get_spec("Upper bound for Event cards")) {
        reason = "too many event cards";
        return false;
    }

    if (cost1_count < get_spec("Lower bound for 1 cost cards")) {
        reason = "too few cost 1 cards";
        return false;
    }
    if (cost1_count > get_spec("Upper bound for 1 cost cards")) {
        reason = "too many cost 1 cards";
        return false;
    }

    if (cost2_count < get_spec("Lower bound for 2 cost cards")) {
        reason = "too few cost 2 cards";
        return false;
    }
    if (cost2_count > get_spec("Upper bound for 2 cost cards")) {
        reason = "too many cost 2 cards";
        return false;
    }

    if (cost3_count < get_spec("Lower bound for 3 cost cards")) {
        reason = "too few cost 3 cards";
        return false;
    }
    if (cost3_count > get_spec("Upper bound for 3 cost cards")) {
        reason = "too many cost 3 cards";
        return false;
    }

    if (cost4_count < get_spec("Lower bound for 4 cost cards")) {
        reason = "too few cost 4 cards";
        return false;
    }
    if (cost4_count > get_spec("Upper bound for 4 cost cards")) {
        reason = "too many cost 4 cards";
        return false;
    }
    if (cost5_count < get_spec("Lower bound for 5 cost cards")) {
        reason = "too few cost 5 cards";
        return false;
    }
    if (cost5_count > get_spec("Upper bound for 5 cost cards")) {
        reason = "too many cost 5 cards";
        return false;
    }

    if (cost6_count < get_spec("Lower bound for 6 cost cards")) {
        reason = "too few cost 6 cards";
        return false;
    }
    if (cost6_count > get_spec("Upper bound for 6 cost cards")) {
        reason = "too many cost 6 cards";
        return false;
    }
    if (cost7_count < get_spec("Lower bound for 7 cost cards")) {
        reason = "too few cost 7 cards";
        return false;
    }
    if (cost7_count > get_spec("Upper bound for 7 cost cards")) {
        reason = "too many cost 7 cards";
        return false;
    }

    if (potion_count < get_spec("Lower bound for potion cost cards")) {
        reason = "too few potion cost cards";
        return false;
    }
    if (potion_count > get_spec("Upper bound for potion cost cards")) {
        reason = "too many potion cost cards";
        return false;
    }

    if (potion_count == 1 && get_spec("Prevent having exactly one potion cost card") == 1) {
        reason = "exactly one potion cost card";
        return false;
    }

    // check for +2 actions card
    if (get_spec("Require a +2 actions card") == 1) {
        bool hasPlus2Actions = false;
        for (Card c : kingdom) {
            if (c.actions >= 2)
                hasPlus2Actions = true;
        }
        if (!hasPlus2Actions) {
            reason = "no +2 actions";
            return false;
        }
    }

    // check for tunnel relevance
    if (get_spec("Tunnel is useful") == 1 && kingdom_contains("Tunnel")) {
        string tunnel_cards[] = {"Cartographer", "Catacombs", "Cellar", "Count", "Doctor",
            "Embassy", "Farming_Village", "Golem", "Goons", "Hamlet", "Harvest", "Horse_Traders",
            "Hunting_Party", "Inn", "Ironmonger", "Jester", "Journeyman", "Knights", "Lookout",
            "Margrave", "Militia", "Minion", "Noble_Brigand", "Oasis", "Oracle", "Pirate_Ship",
            "Rebuild", "Rogue", "Sea_Hag", "Secret_Chamber", "Spy", "Storeroom", "Tactician",
            "Thief", "Torturer", "Tribute", "Urchin", "Vault", "Venture", "Wandering_Minstrel",
            "Warehouse", "Young_Witch"};
        vector <string> tunnelCards(begin(tunnel_cards), end(tunnel_cards));
        if (kingdom_contains_none(tunnelCards)) {
            reason = "Tunnel is irrelevant";
            return false;
        }
    }

    // check for scout relevance
    if (get_spec("Scout is useful") == 1 && kingdom_contains("Scout")) {
        string scout_cards[] = {"Baron", "Crossroads", "Explorer", "Great_Hall", "Harem",
            "Island", "Mystic", "Nobles", "Tournament", "Wishing_Well"};
        vector <string> scoutCards(begin(scout_cards), end(scout_cards));
        if (kingdom_contains_none(scoutCards)) {
            reason = "Scout is irrelevant";
            return false;
        }
    }

    // check for cards with on trashing ability
    if (get_spec("On-trash abilities cards are useful") == 1) {
        string on_trash_cards[] = {"Catacombs", "Cultist", "Feodum", "Fortress",
            "Hunting_Grounds", "Rats", "Squire"};
        vector <string> onTrashCards(begin(on_trash_cards), end(on_trash_cards));
        string trashing_attacks[] = {"Knights", "Noble_Brigand", "Pirate_Ship",
            "Thief", "Rogue", "Saboteur", "Swindler"};
        vector <string> trashingAttacks(begin(trashing_attacks), end(trashing_attacks));
        if (kingdom_contains(1, onTrashCards) && kingdom_contains_none(trashingAttacks) &&
                trashers_count < 1) {
            reason = "no trasher with on-trash ability card";
            return false;
        }
    }

    if (get_spec("Redundant: Armory, Ironworks, Talisman, and Workshop")) {
        // check for multiple gainers
        string gainers[] = {"Armory", "Ironworks", "Talisman", "Workshop"};
        vector <string> Gainers(begin(gainers), end(gainers));
        if (kingdom_contains(2, Gainers)) {
            reason = "two or more of Armory, Ironworks, Talisman, Workshop";
            return false;
        }
    }

    if (get_spec("Redundant: Noble Brigand, Pirate Ship, and Thief") == 1) {
        // check for multiple treasure attacks
        string treasure_attacks[] = {"Noble_Brigand", "Pirate_Ship", "Thief"};
        vector <string> treasureAttacks(begin(treasure_attacks), end(treasure_attacks));
        if (kingdom_contains(2, treasureAttacks)) {
            reason = "two or more of Noble Brigand, Pirate Ship, Thief";
            return false;
        }
    }

    if (get_spec("Redundant: Chapel, Loan, Moneylender, and Spice Merchant")) {
        // check for multiple treasure trashers
        string treasure_trashers[] = {"Chapel", "Moneylender", "Loan", "Spice_Merchant"};
        vector <string> treasureTrashers(begin(treasure_trashers), end(treasure_trashers));
        if (kingdom_contains(2, treasureTrashers)) {
            reason = "two or more of Chapel, Moneylender, Loan, Spice Merchant";
            return false;
        }
    }

    // check for rats relevance
    if (get_spec("Rats is useful") == 1 && kingdom_contains("Rats")) {
        string rats_cards[] = {"Apprentice", "Bishop", "Butcher", "Develop", "Expand",
            "Forge", "Graverobber", "Remake", "Remodel", "Salvager", "Stonemason", "Trader",
            "Upgrade"};
        vector <string> ratsCards(begin(rats_cards), end(rats_cards));
        if (kingdom_contains_none(ratsCards)) {
            reason = "Rats is irrelevant";
            return false;
        }
    }

    // check for multiple reaction cards
    if (get_spec("Redundant: Reaction cards") == 1) {
        string duplicates[] = {"Beggar", "Horse_Traders", "Lighthouse", "Moat", "Secret_Chamber"};
        vector <string> Duplicates(begin(duplicates), end(duplicates));
        if (kingdom_contains(2, Duplicates)) {
            reason = "two or more of Beggar, Horse Traders, Lighthouse, Moat, Secret Chamber";
            return false;
        }
    }

    // check for quarry relevance
    if (get_spec("Quarry is useful") == 1 && kingdom_contains("Quarry") &&
            (action6_count + action7_count < 1 || action5_count + action6_count + action7_count < 3)) {
        reason = "Quarry is irrelevant";
        return false;
    }

    // check for market_square relevance
    if (get_spec("Market Square is useful") == 1 && kingdom_contains("Market_Square") && trashers_count == 0) {
        string trashing_attacks[] = {"Knights", "Noble_Brigand", "Pirate_Ship", "Rogue",
            "Saboteur", "Swindler", "Thief"};
        vector <string> trashingAttacks(begin(trashing_attacks), end(trashing_attacks));
        if (kingdom_contains_none(trashingAttacks)) {
            reason = "Market Square is irrelevant";
            return false;
        }
    }

    // check for procession relevance
    if (get_spec("Procession is useful") == 1 && kingdom_contains("Procession") &&
            (action3_count < 1 || action4_count < 2 || action5_count < 1 || action6_count < 1)) {
        reason = "Procession is irrelevant";
        return false;
    }

    if (get_spec("Redundant: Deck spying attacks") == 1) {
        // check for multiple deck spying attacks
        string duplicates[] = {"Oracle", "Scrying_Pool", "Spy"};
        vector <string> Duplicates(begin(duplicates), end(duplicates));
        if (kingdom_contains(2, Duplicates)) {
            reason = "two or more of Oracle, Scrying Pool, Spy";
            return false;
        }
    }

    if (get_spec("Redundant: Discard for coin cards") == 1) {
        // check for multiple discard for coin
        string duplicates[] = {"Secret_Chamber", "Storeroom", "Vault"};
        vector <string> Duplicates(begin(duplicates), end(duplicates));
        if (kingdom_contains(2, Duplicates)) {
            reason = "two or more of Secret Chamber, Storeroom, Vault";
            return false;
        }
    }

    if (get_spec("Redundant: Curse giving attacks") == 1) {
        // check for multiple cursers
        string duplicates[] = {"Giant", "Familiar", "Mountebank", "Sea_Hag", "Soothsayer", "Swamp_Hag", "Witch", "Young_Witch"};
        vector <string> Duplicates(begin(duplicates), end(duplicates));
        if (kingdom_contains(2, Duplicates)) {
            reason = "two or more of Familiar, Mountebank, Sea Hag, Witch, Young Witch";
            return false;
        }
    }

    if (get_spec("Prince is useful") == 1 && kingdom_contains("Prince") && action4_count < 3) {
        reason = "Prince is irrelevant";
        return false;
    }

    if (get_spec("University is useful") == 1 && kingdom_contains("University") && action5_count < 3) {
        reason = "University is irrelevant";
        return false;
    }

    if (get_spec("Redundant: Similar cost +2 actions cards") == 1 && ((action2_count2 > 0 && action2_count3 > 0) || (action2_count3 > 0 && action2_count4 > 0) ||
            (action2_count3 > 0 && action2_count5 > 0) || (action2_count4 > 0 && action2_count5 > 0) ||
            (action2_count5 > 0 && action2_count6 > 0))) {
        reason = "multiple +2 action cards of similar cost";
        return false;
    }

    if (get_spec("Require an appropriate reaction for all attacks") == 1) {
        if (attacks_count != 0) {
            // check for no reaction to junk-giving attacks
            string junk_attacks[] = {"Ambassador", "Cultist", "Familiar", "Marauder",
                "Jester", "Mountebank", "Sea_Hag", "Witch", "Soothsayer"};
            vector <string> junkAttacks(begin(junk_attacks), end(junk_attacks));
            string reactions1[] = {"Lighthouse", "Moat", "Trader", "Watchtower"};
            vector <string> Reactions1(begin(reactions1), end(reactions1));
            if (kingdom_contains(1, junkAttacks) && kingdom_contains_none(Reactions1)) {
                reason = "no reaction for junk-giving attack";
                return false;
            }

            // check for no reaction to specific card discard attacks
            string discard_attacks1[] = {"Bureaucrat", "Cutpurse", "Taxman"};
            vector <string> discardAttacks1(begin(discard_attacks1), end(discard_attacks1));
            string reactions2[] = {"Horse_Traders", "Lighthouse", "Moat",
                "Secret_Chamber", "Watchtower"};
            vector <string> Reactions2(begin(reactions2), end(reactions2));
            if (kingdom_contains(1, discardAttacks1) && kingdom_contains_none(Reactions2)) {
                reason = "no reaction for Bureaucrat/Cutpurse/Taxman";
                return false;
            }

            // check for no reaction to Fortune Teller
            if (kingdom_contains("Fortune_Teller")) {
                string reactions[] = {"Farming_Village", "Lighthouse", "Moat", "Secret_Chamber"};
                vector <string> Reactions(begin(reactions), end(reactions));
                if (kingdom_contains_none(Reactions)) {
                    reason = "no reaction for Fortune Teller";
                    return false;
                }
            }

            // check for no reaction to Ghost Ship
            if (kingdom_contains("Ghost_Ship")) {
                string reactions[] = {"Beggar", "Horse_Traders", "Library",
                    "Lighthouse", "Moat", "Secret_Chamber", "Watchtower"};
                vector <string> Reactions(begin(reactions), end(reactions));
                if (kingdom_contains_none(Reactions)) {
                    reason = "no reaction for Ghost Ship";
                    return false;
                }
            }

            // check for no reaction to trashing attacks
            string trashing_attacks[] = {"Knights", "Noble_Brigand", "Pirate_Ship",
                "Thief", "Rogue", "Swindler"};
            vector <string> trashingAttacks(begin(trashing_attacks), end(trashing_attacks));
            string reactions3[] = {"Beggar", "Lighthouse", "Market_Square",
                "Moat", "Secret_Chamber"};
            vector <string> Reactions3(begin(reactions3), end(reactions3));
            if (kingdom_contains(1, trashingAttacks) && kingdom_contains_none(Reactions3)) {
                reason = "no reaction for trashing attack";
                return false;
            }

            // check for no reaction to heavy discard attacks
            string discard_attacks2[] = {"Goons", "Margrave", "Militia"};
            vector <string> discardAttacks2(begin(discard_attacks2), end(discard_attacks2));
            string reactions4[] = {"Beggar", "Horse_Traders", "Library",
                "Lighthouse", "Moat", "Tunnel", "Watchtower"};
            vector <string> Reactions4(begin(reactions4), end(reactions4));
            if (kingdom_contains(1, discardAttacks2) && kingdom_contains_none(Reactions4)) {
                reason = "no reaction for Goons, Margrave, Militia";
                return false;
            }

            // check for no reaction to light discard attacks
            string discard_attacks3[] = {"Minion", "Urchin"};
            vector <string> discardAttacks3(begin(discard_attacks3), end(discard_attacks3));
            string reactions5[] = {"Beggar", "Horse_Traders", "Lighthouse",
                "Moat", "Secret_Chamber", "Tunnel", "Watchtower"};
            vector <string> Reactions5(begin(reactions5), end(reactions5));
            if (kingdom_contains(1, discardAttacks3) && kingdom_contains_none(Reactions5)) {
                reason = "no reaction for Minion, Urchin";
                return false;
            }

            // check for no reaction to deck spying attacks
            string spying_attacks[] = {"Oracle", "Scrying_Pool", "Spy"};
            vector <string> spyingAttacks(begin(spying_attacks), end(spying_attacks));
            string reactions6[] = {"Beggar", "Lighthouse", "Moat", "Secret_Chamber"};
            vector <string> Reactions6(begin(reactions6), end(reactions6));
            if (kingdom_contains(1, spyingAttacks) && kingdom_contains_none(Reactions6)) {
                reason = "no reaction for Oracle, Scrying Pool, Spy";
                return false;
            }

            // check for no reaction to Pillage
            if (kingdom_contains("Pillage")) {
                string reactions[] = {"Beggar", "Horse_Traders", "Lighthouse",
                    "Moat", "Secret_Chamber", "Watchtower"};
                vector <string> Reactions(begin(reactions), end(reactions));
                if (kingdom_contains_none(Reactions))
                    reason = "no reaction for Pillage";
                return false;
            }

            // check for no reaction to Rabble
            if (kingdom_contains("Rabble")) {
                string reactions[] = {"Lighthouse", "Moat", "Secret_Chamber"};
                vector <string> Reactions(begin(reactions), end(reactions));
                if (kingdom_contains_none(Reactions)) {
                    reason = "no reaction for Rabble";
                    return false;
                }
            }

            // check for no reaction to Saboteur
            if (kingdom_contains("Saboteur")) {
                string reactions[] = {"Beggar", "Lighthouse", "Market_Square", "Moat"};
                vector <string> Reactions(begin(reactions), end(reactions));
                if (kingdom_contains_none(Reactions)) {
                    reason = "no reaction for Saboteur";
                    return false;
                }
            }

            // check for no reaction to Torturer
            if (kingdom_contains("Torturer")) {
                string reactions[] = {"Horse_Traders", "Lighthouse", "Moat",
                    "Secret_Chamber", "Trader", "Tunnel", "Watchtower"};
                vector <string> Reactions(begin(reactions), end(reactions));
                if (kingdom_contains_none(Reactions)) {
                    reason = "no reaction for Torturer";
                    return false;
                }
            }
        }
    }

    if (get_spec("Redundant: Same cost trashers") == 1) {
        // check for multiple trashers of same cost
        int trasher2, trasher3, trasher4, trasher5, trasher6, trasher7 = 0;
        for (int i = 0; i < kingdom.size(); i++) {
            if (kingdom.at(i).trasher > 0 || kingdom.at(i).name == "Ambassador") {
                switch ((int) kingdom.at(i).cost) {
                    case 2:
                        trasher2++;
                        break;
                    case 3:
                        trasher3++;
                        break;
                    case 4:
                        trasher4++;
                        break;
                    case 5:
                        trasher5++;
                        break;
                    case 6:
                        trasher6++;
                        break;
                    case 7:
                        trasher7++;
                        break;
                    default:
                        break;
                }
            }
        }
        if (trasher2 >= 2 || trasher3 >= 2 || trasher4 >= 2 || trasher5 >= 2 || trasher6 >= 2 || trasher7 >= 2) {
            reason = "two or more trashers of same cost";
            return false;
        }
    }

    if (get_spec("Redundant: Hand size reducing attack card") == 1) {
        // check for multiple discard attacks
        string duplicates[] = {"Goons", "Margrave", "Militia",
            "Minion", "Pillage", "Taxman", "Urchin"};
        vector <string> Duplicates(begin(duplicates), end(duplicates));
        if (kingdom_contains(2, Duplicates)) {
            reason = "two or more discard attacks";
            return false;
        }
    }

    if (get_spec("Prevent useless reactions") == 1 && attacks_count == 0) {
        // check for a reaction card and no attacks
        string reactions[] = {"Beggar", "Horse_Traders", "Lighthouse",
            "Moat", "Secret_Chamber"};
        vector <string> Reactions(begin(reactions), end(reactions));
        if (kingdom_contains(1, Reactions)) {
            reason = "irrelevant reaction card";
            return false;
        }
    }

    if (get_spec("Contraband is useful") == 1 && kingdom_contains("Contraband") && buys_count != 1) {
        reason = "Contraband is irrelevant";
        return false;
    }

    if (get_spec("Redundant: Messenger, Nomad Camp, and Woodcutter") == 1) {
        // check for multiple of these cards
        string onebuytwocards[] = {"Messenger", "Nomad_Camp", "Woodcutter"};
        vector <string> Onebuytwocards(begin(onebuytwocards), end(onebuytwocards));
        if (kingdom_contains(2, Onebuytwocards)) {
            reason = "both Nomad Camp and Woodcutter";
            return false;
        }
    }

    if (get_spec("Squire is useful") == 1 && kingdom_contains("Squire") && attacks_count == 0) {
        reason = "Squire with no attack cards";
        return false;
    }

    if (get_spec("Feast and Altar are useful") == 1 && (kingdom_contains("Feast") ||
            kingdom_contains("Altar")) && cost5_count < 3) {
        reason = "Feast/Altar is irrelevant";
        return false;
    }

    if (get_spec("Redundant: Expand and Remodel") == 1 && kingdom_contains("Expand") && kingdom_contains("Remodel")) {
        reason = "both Expand and Remodel";
        return false;
    }

    if (get_spec("Redundant: Count and Mandarin") == 1 && kingdom_contains("Count") && kingdom_contains("Mandarin")) {
        reason = "both Count and Mandarin";
        return false;
    }

    if (get_spec("Redundant: Hunting Grounds and Smithy") == 1 && kingdom_contains("Hunting_Grounds") && kingdom_contains("Smithy")) {
        reason = "both Hunting Grounds and Smithy";
        return false;
    }

    if (get_spec("Nomad Camp/Woodcutter is useful") == 1 && (kingdom_contains("Nomad_Camp") || kingdom_contains("Woodcutter")) &&
            buys_count != 1) {
        reason = "Nomad Camp/Woodcutter is irrelevant";
        return false;
    }

    if (get_spec("Redundant: Procession and Throne Room") == 1 && kingdom_contains("Procession") && kingdom_contains("Throne_Room")) {
        reason = "both Procession and Throne Room";
        return false;
    }

    if (get_spec("Redundant: Mine and Taxman") == 1 && kingdom_contains("Mine") && kingdom_contains("Taxman")) {
        reason = "both Mine and Taxman";
        return false;
    }

    if (get_spec("Conspirator is useful") == 1 && kingdom_contains("Conspirator") && actions_count < 4) {
        reason = "Conspirator is irrelevant";
        return false;
    }

    if (get_spec("Redundant: Chancellor and Scavenger") == 1 && kingdom_contains("Chancellor") && kingdom_contains("Scavenger")) {
        reason = "both Chancellor and Scavenger";
        return false;
    }

    if (get_spec("Redundant: Hunting Party and Laboratory") == 1 && kingdom_contains("Hunting_Party") && kingdom_contains("Laboratory")) {
        reason = "both Hunting Party and Laboratory";
        return false;
    }

    if (get_spec("Band of Misfits is useful") == 1 && kingdom_contains("Band_of_Misfits") &&
            action3_count + action4_count < 4) {
        reason = "Band of Misfits is irrelevant";
        return false;
    }

    if (get_spec("Redundant: Expand and Graverobber") == 1 && kingdom_contains("Expand") && kingdom_contains("Graverobber")) {
        reason = "both Expand and Graverobber";
        return false;
    }

    if (get_spec("Annoying: Develop and Poor House") == 1 && kingdom_contains("Develop") && kingdom_contains("Poor_House")) {
        reason = "both Develop and Poor House";
        return false;
    }

    if (get_spec("Redundant: Advisor and Envoy") == 1 && kingdom_contains("Advisor") && kingdom_contains("Envoy")) {
        reason = "both Advisor and Envoy";
        return false;
    }


    // add appropriate number of event cards
    int lower_bound = get_spec("Lower bound for Event cards");
    int upper_bound = get_spec("Upper bound for Event cards");
    int num_events;

    if (lower_bound != upper_bound)
        num_events = get_spec("Lower bound for Event cards") + (rand() % (int) (get_spec("Upper bound for Event cards") - get_spec("Lower bound for Event cards")));
    else
        num_events = lower_bound;

    for (int i = 0; i < num_events; i++) {

    }
    return true;
}

bool Deck::kingdom_contains(string card) {
    for (int i = 0; i < kingdom.size(); i++) {
        if (kingdom.at(i).name == card)
            return true;
    }
    return false;
}

bool Deck::kingdom_contains(string card, int& pos) {
    for (int i = 0; i < kingdom.size(); i++) {
        if (kingdom.at(i).name == card) {
            pos = i;
            return true;
        }
    }
    pos = -1;
    return false;
}

bool Deck::kingdom_contains_all(vector <string> cards) {
    /* returns true if kingdom contains all
       the cards in cards */
    for (string card : cards) {
        if (!kingdom_contains(card))
            return false;
    }
    return true;
}

bool Deck::kingdom_contains_none(vector <string> cards) {
    for (string card : cards) {
        if (kingdom_contains(card))
            return false;
    }
    return true;
}

bool Deck::kingdom_contains(int min, vector <string> cards) {
    /* returns true if kingdom contains at
    least min of the cards in cards array */
    int count = 0;
    for (string card : cards) {
        if (kingdom_contains(card))
            count++;
    }
    if (count >= min)
        return true;
    else
        return false;
}

bool Deck::kingdom_contains_set(string set) {
    for (int i = 0; i < kingdom.size(); i++) {
        if (kingdom.at(i).set == set)
            return true;
    }
    return false;
}

int Deck::position_of(string card) {
    for (int i = 0; i < full_deck.size(); i++) {
        if (full_deck.at(i).name == card)
            return i;
    }
    return -1;
}

void Deck::process_score() {
    int num_players;
    string name;
    bool found;
    int score;

    // get number of players
    do {
        cout << "How many players played this game?\n";
        cin >> num_players;
        if (num_players < 2 || num_players > 6)
            cout << "Invalid number of players. Please try again.\n";
    } while (num_players < 2 || num_players > 6);

    // get name of first player
    cout << "\nEnter the name of the first player: ";
    cin >> name;
    found = false;
    for (int i = 0; i < players.size(); i++) {
        if (players.at(i).name == name) {
            found = true;
            players.at(i).active = true;
            Game game;
            game.opponents = 0;
            game.opps_points = 0;
            game.place = 0;
            game.score = 0;
            players.at(i).history.push_back(game);
        }
    }
    if (!found) {
        Player player;
        player.name = name;
        player.history.clear();
        Game game;
        game.opponents = 0;
        game.opps_points = 0;
        game.place = 0;
        game.score = 0;
        player.history.push_back(game);
        player.active = true;
        player.score = 0;
        player.place = 0;
        players.push_back(player);

        cout << "New player " << name << " added to player list.\n";
    }

    // get name of remaining players
    for (int i = 0; i < num_players - 1; i++) {
        cout << "Enter the name of the next player: ";
        cin >> name;
        found = false;
        for (int i = 0; i < players.size(); i++) {
            if (players.at(i).name == name) {
                found = true;
                players.at(i).active = true;
                Game game;
                game.opponents = 0;
                game.opps_points = 0;
                game.place = 0;
                game.score = 0;
                players.at(i).history.push_back(game);
            }
        }
        if (!found) {
            Player player;
            player.name = name;
            player.history.clear();
            Game game;
            game.opponents = 0;
            game.opps_points = 0;
            game.place = 0;
            game.score = 0;
            player.history.push_back(game);
            player.active = true;
            player.score = 0;
            player.place = 0;
            players.push_back(player);

            cout << "New player " << name << " added to player list.\n";
        }
    }

    // get scores
    cout << endl;
    for (int i = 0; i < players.size(); i++) {
        if (players.at(i).active) {
            Player* player = &players.at(i);
            cout << "How many points did " << player->name << " score?\n";
            cin >> score;
            player->score = score;

            player->history.at(player->history.size() - 1).score = score;
            player->history.at(player->history.size() - 1).opponents = num_players - 1;
        }
    }

    // adjust scores information
    for (int i = 0; i < players.size(); i++) {
        if (players.at(i).active) {
            Player* player = &players.at(i);
            int total = 0; // total score of other players in this game
            for (int j = 0; j < players.size(); j++) {
                if (players.at(j).active && i != j)
                    total += players.at(j).score;
            }
            player->history.at(player->history.size() - 1).opps_points = total;
        }
    }

    // find out what place each player is
    bool done = false;
    bool tie = false;

    for (int i = 0; i < num_players && !done; i++) {
        // find maximum score
        int maximum = 0;
        for (int i = 0; i < players.size() && !done; i++) {
            if (players.at(i).score > 0) {
                maximum = players.at(i).score;
                done = true;
            }
        }
        done = false;

        for (int i = 1; i < players.size(); i++) {
            if (players.at(i).active && maximum < players.at(i).score)
                maximum = players.at(i).score;
        }

        // erase maximum score from consideration and assign place
        for (int j = 0; j < players.size(); j++) {
            if (players.at(j).score == maximum) {
                players.at(j).score = -1;
                players.at(j).place = i + 1;
                players.at(j).history.at(players.at(j).history.size() - 1).place = i + 1;
            }
        }

        done = true;
        for (int j = 0; j < players.size(); j++) {
            if (players.at(j).active && players.at(j).place == 0)
                done = false;
        }
    }

    cout << "\nFirst place: ";
    for (int i = 0; i < players.size(); i++) {
        if (players.at(i).place == 1) {
            cout << players.at(i).name << " " <<
                    players.at(i).history.at(players.at(i).history.size() - 1).score << " ";
        }
    }

    cout << "\nSecond place: ";
    for (int i = 0; i < players.size(); i++) {
        if (players.at(i).place == 2) {
            cout << players.at(i).name << " " <<
                    players.at(i).history.at(players.at(i).history.size() - 1).score << " ";
        }
    }

    if (num_players >= 3) {
        cout << "\nThird place: ";
        for (int i = 0; i < players.size(); i++) {
            if (players.at(i).place == 3) {
                cout << players.at(i).name << " " <<
                        players.at(i).history.at(players.at(i).history.size() - 1).score << " ";
            }
        }
    }

    if (num_players >= 4) {
        cout << "\nFourth place: ";
        for (int i = 0; i < players.size(); i++) {
            if (players.at(i).place == 4) {
                cout << players.at(i).name << " " <<
                        players.at(i).history.at(players.at(i).history.size() - 1).score << " ";
            }
        }
    }

    if (num_players >= 5) {
        cout << "\nFifth place: ";
        for (int i = 0; i < players.size(); i++) {
            if (players.at(i).place == 5) {
                cout << players.at(i).name << " " <<
                        players.at(i).history.at(players.at(i).history.size() - 1).score << " ";
            }
        }
    }

    if (num_players >= 6) {
        cout << "\nSixth place: ";
        for (int i = 0; i < players.size(); i++) {
            if (players.at(i).place == 6) {
                cout << players.at(i).name << " " <<
                        players.at(i).history.at(players.at(i).history.size() - 1).score << " ";
            }
        }
    }
    cout << endl;
    for (int i = 0; i < players.size(); i++) {
        if (players.at(i).place == 1)
            cout << "\nCongrats, " << players.at(i).name << "! Booyah.\n";
    }
    print_players(true, 10);

    for (int i = 0; i < players.size(); i++) {
        players.at(i).place = 0;
        players.at(i).score = 0;
        players.at(i).active = false;
    }
}

void Player::print(int last) {
    if (last < history.size()) {
        if (last == 0)
            last = history.size();
    } else
        last = history.size();

    int places[7];
    for (int i = 0; i < 7; i++)
        places[i] = 0;
    float points = 0;
    float opponents = 0;
    float opps_points = 0;
    float avg_percent = 0;
    for (int i = history.size() - last; i < history.size(); i++) {
        points += history.at(i).score;
        opponents += history.at(i).opponents;
        opps_points += history.at(i).opps_points;

        avg_percent += (float) history.at(i).score / (((float) history.at(i).opps_points +
                (float) history.at(i).score) / ((float) history.at(i).opponents + 1));

        switch (history.at(i).place) {
            case 1:
                places[1]++;
                break;
            case 2:
                places[2]++;
                break;
            case 3:
                places[3]++;
                break;
            case 4:
                places[4]++;
                break;
            case 5:
                places[5]++;
                break;
            case 6:
                places[6]++;
                break;
        }
    }
    float avg_net_score = (points / (float) last - opps_points / opponents);
    avg_percent /= (float) last;

    cout << "\n" << name << ":";

    if (last == history.size())
        cout << "\n\tGames played: " << last;
    else
        cout << "\nData for last " << last << " games:";

    cout << "\n\tTotal points scored: " << (int) points;
    cout << "\n\tAverage score: " << fixed << setprecision(1) << points / (float) last;

    cout << "\n\tAverage net score: ";
    if (avg_net_score >= 0)
        cout << "+";
    cout << avg_net_score;

    cout << "\n\tAverage net percent: ";
    if (avg_percent >= 1)
        cout << "+";
    cout << 100 * (avg_percent - 1.0) << "%";

    if (places[1] > 0)
        cout << "\n\tFirst place count: " << places[1] << " (" << (int) ((100.0 * (float) places[1] / (float) last) + 0.5) << "%)";
    if (places[2] > 0)
        cout << "\n\tSecond place count: " << places[2] << " (" << (int) ((100.0 * (float) places[2] / (float) last) + 0.5) << "%)";
    if (places[3] > 0)
        cout << "\n\tThird place count: " << places[3] << " (" << (int) ((100.0 * (float) places[3] / (float) last) + 0.5) << "%)";
    if (places[4] > 0)
        cout << "\n\tFourth place count: " << places[4] << " (" << (int) ((100.0 * (float) places[4] / (float) last) + 0.5) << "%)";
    if (places[5] > 0)
        cout << "\n\tFifth place count: " << places[5] << " (" << (int) ((100.0 * (float) places[5] / (float) last) + 0.5) << "%)";
    if (places[6] > 0)
        cout << "\n\tSixth place count: " << places[6] << " (" << (int) ((100.0 * (float) places[6] / (float) last) + 0.5) << "%)";
    cout << endl;
}

void Deck::print_players(bool only_active, int last) {
    cout << "\n";
    for (Player p : players) {
        if (!only_active || p.active)
            p.print(last);
    }
}

Spec Deck::read_spec(ifstream &din, string junk, string id) {
    string word;
    float spec;

    // read the spec
    din >> word;
    while (word != junk)
        din >> word;
    din >> spec;

    // store in return variable
    Spec s;
    s.id = id;
    s.value = spec;
    return s;
}

float Deck::get_spec(string id) {
    // returns value of spec with identifier "id"
    for (int i = 0; i < specs.size(); i++) {
        if (specs.at(i).id == id)
            return specs.at(i).value;
    }
    cout << "Id \"" << id << "\" not read" << endl;
    return -1;
}