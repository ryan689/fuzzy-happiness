#include <iostream>
#include <fstream>
#include "Deck.h"

using namespace std;

int main()
{
    Deck Dominion;
    int response;
    string card;
    bool done = false;

    // ask for purpose
    cout << "What would you like me to do?\n" <<
            "1 - Choose cards\t2 - Adjust card rankings\n" <<
            "3 - Adjust usage\t4 - Manage blacklist\n" <<
            "5 - Manage whitelist\t6 - Player data\n" <<
            "7 - Saved kingdoms\t8 - Print deck\n";
    cin >> response;
    cout << endl;
    
    // respond with appropriate action
    switch (response)
    {
        case 1:
            Dominion.select_kingdom();
            Dominion.print_kingdom(false, 3, 3);
            do
            {
                cout << "\nIs this kingdom acceptable? If yes, enter \"yes\".\n" <<
                        "If no, enter the name of one of these cards and I will replace it.\n";
                cin >> card;
                cout << endl;
                if (card == "yes" || card == "Yes")
                    done = true;
                else
                {
                    Dominion.replace_card(card);
                    Dominion.print_kingdom(false, 3, 3);
                }
            } while (!done);
            cout << "Enjoy your game!\n";
            Dominion.print_kingdom(true, 3, 3);
            break;
        case 2:
            Dominion.print_rankings();
            Dominion.adjust_rankings();
            break;
        case 3:
            Dominion.print_uses();
            Dominion.adjust_usage();
            break;
        case 4:
            Dominion.manage_blacklist();
            break;
        case 5:
            Dominion.manage_whitelist();
            break;
        case 6:
            do
            {
                cout << "\n1 - Input scores\t2 - Print player list" <<
                        "\n3 - Erase player data\t4 - Save and quit\n";
                cin >> response;
                switch(response)
                {
                    case 1:
                        Dominion.process_score();
                        break;
                    case 2:
                        cout << "\n1 - All games played\t2 - Last 5 games" <<
                                "\n3 - Last 10 games\t4 - Enter number of games\n";
                        cin >> response;
                        switch(response)
                        {
                            case 1:
                                Dominion.print_players(false, 0);
                                break;
                            case 2:
                                Dominion.print_players(false, 5);
                                break;
                            case 3:
                                Dominion.print_players(false, 10);
                                break;
                            case 4:
                                cout << "Enter the number of games for which you'd like to see data: ";
                                cin >> response;
                                Dominion.print_players(false, response);
                                break;
                            default:
                                cout << "Input not read.\n";
                                break;
                        }
                        break;
                    case 3:
                        cout << "Are you sure you wish to erase all player data? " <<
                                "All scores and averages will be lost.\nThis " <<
                                "cannot be undone.\n1 - yes\t2 - no\n";
                        cin >> response;
                        switch(response)
                        {
                            case 1:
                                Dominion.erase_player_data();
                                break;
                            case 2:
                                cout << "Player data not erased.\n\n";
                                break;
                            default:
                                cout << "Input not read.\n";
                                break;
                        }
                        break;
                    case 4:
                        done = true;
                        break;
                    default:
                        cout << "Input not read.\n";
                        break;
                }
            } while (!done);
            break;
        case 7:
            do
            {
                cout << "\n1 - View saved kingdoms\t2 - View last kingdom" <<
                        "\n3 - Play saved kingdom\t4 - Save and quit\n";
                cin >> response;
                switch (response)
                {
                    case 1:
                        Dominion.print_saved_kingdoms();
                        break;
                    case 2:
                        Dominion.previous_kingdom();
                        done = true;
                        break;
                    case 3:
                        Dominion.play_saved_kingdom();
                        done = true;
                        break;
                    case 4:
                        done = true;
                        break;
                    default:
                        cout << "Input not read.\n";
                        done = true;
                        break;
                }
            } while (!done);
            break;
        case 8:
            Dominion.print_deck();
            break;
        default:
            cout << "Input not read.\n";
            break;
    }
    
    return 0;
}
