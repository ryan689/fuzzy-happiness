/* 
 * File:   Deck.h
 * Author: RyansMacbookPro
 *
 * Created on July 14, 2014, 10:44 AM
 */
#ifndef DECK_H
#define	DECK_H

#include "Card.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iterator>
using namespace std;

struct Game
{
    int score; // score in this game
    int place;
    int opponents; // number of opponents in this game
    int opps_points; // total points scored by opponents in this game
};

struct Kingdom
{
    vector <string> cards;
    int PC; // (platinum and colony) 1 if always yes, 2 if always no, or 3 if decide each time
    int shelter; // (shelters) 1 if always yes, 2 if always no, or 3 if decide each time
    string notes; // notes on this kingdom
};

class Player
{
public:
    string name;
    int score; // score in most recent game
    int place;
    bool active; // whether the player is active for this game
    
    vector <Game> history; // contains play history of all games played
    
    void print(int last);
};

class Spec
{
public:
    string id; // what this is specifying
    float value;
};

class Deck
{
public:
    Deck();
    ~Deck();
    void print_deck();
    void print_specs();
    void print_uses();
    void print_rankings();
    void print_blacklist();
    void print_whitelist();
    void previous_kingdom();
    void print_saved_kingdoms();
    void save_previous_kingdom();
    void play_saved_kingdom();
    void print_kingdom(bool last, int PC, int shelter); // parameter asks whether to print the supply cards
    void adjust_usage();
    void adjust_rankings();
    void manage_blacklist();
    void manage_whitelist();
    void select_kingdom();
    bool replace_card(string card);
    void process_score();
    void print_players(bool only_active, int last); // parameter asks whether to print non-active players
    void erase_player_data();
    string tokenize(string &token, char delim);
    Spec read_spec(ifstream &din, string junk, string id);
    float get_spec(string id);
    
private:
    vector <Card> full_deck; // all Dominion cards
    vector <Card> game_deck; // only Dominion cards turned on in specs doc
    vector <Spec> specs;
    vector <Player> players;
    vector <Card> kingdom; // the set of 10 cards chosen to play a game with
    vector <Kingdom> saved_kingdoms;
    
    // stores information about kingdom
    float cards_count, actions_count, buys_count, coins_count, trashers_count;
    float cost1_count, cost2_count, cost3_count, cost4_count, cost5_count;
    float cost6_count, cost7_count, attacks_count, potion_count, duration_count;
    float treasure_count, victory_count, speed_count, reserve_count, event_count;
    float action3_count, action4_count, action5_count, action6_count, action7_count;
    float action2_count2, action2_count3, action2_count4, action2_count5, action2_count6;
    float castle_count, intrigue_count, seaside_count, alchemy_count, prosperity_count;
    float cornucopia_count, hinterlands_count, dark_ages_count, guilds_count, adventures_count;
    bool CP, shelters;
    string reason; // reason kingdom failed test
    
    void reset_uses();
    void reset_rankings();
    
    string generate_card();
    bool add_to_kingdom(string card);
    bool remove_from_kingdom(string card);
    bool check_kingdom(); // check that kingdom meets specs
    bool kingdom_contains(string card);
    bool kingdom_contains_all(vector <string> cards);
    bool kingdom_contains_none(vector <string> cards);
    bool kingdom_contains(int min, vector <string> cards);
    bool kingdom_contains(string card, int& pos);
    bool kingdom_contains_set(string set);
    int position_of(string card); // returns position of card in deck
    void sort_kingdom();
    void swap_cards(Card& card1, Card& card2);
    string compare_strings(string string1, string string2, int pos); // returns which is first alphabetically
};

#endif	/* DECK_H */

