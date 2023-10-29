#include <iostream>
#include "race.h"
#include "random.h"
#include "gui.h"

using namespace std;

const int SCREEN_NUM_OF_ELEMENTS = 16;
const int START_SCREEN_NUM_OF_ELEMENTS = 13;

 std::string message_template[START_SCREEN_NUM_OF_ELEMENTS]=
{
"----------------------------------------------------------------------",
"|    ____                    _   _     ____                          |",
"|   / ___|   _ __     __ _  (_) | |   |  _ \\    __ _    ___    ___   |",
"|   \\___ \\  | '_ \\   / _` | | | | |   | |_) |  / _` |  / __|  / _ \\  |",
"|    ___) | | | | | | (_| | | | | |   |  _ <  | (_| | | (__  |  __/  |",
"|   |____/  |_| |_|  \\__,_| |_| |_|   |_| \\_\\  \\__,_|  \\___|  \\___|  |",
"|                                                                    |",
"|                                                                    |",
"|                                                                    |",
"|                                                                    |",
"|                                                                    |",
"|                                                                    |",
"|                                                                    |",
"----------------------------------------------------------------------"};

 std::string repeat_question[1]=
{
"|                       Repeat(R) the race                           |",};

 std::string start_question[1]=
{
"|                       Start(S) a new game                          |",};

 std::string exit_question[1]=
{
"|                          Exit(S) the game                          |",};


int main()
{
    size_t MIN_STEP = 0;

    size_t SPEEDWAY_LENGTH = 10;

    int MIN_TIME_UNTIL_STEP = 0;
    int MAX_TIME_UNTIL_STEP = 600;

    string input_key ="Y";

    FirstScreen fs1;
    SecondScreen ss1;

    const int NUMBER_OF_ELEMENTS = 16;

    while(input_key == "Y" || input_key == "y")
    {
        size_t number_of_snails = size_t(ss1.get_number_of_snails());
        size_t max_positions_per_step = size_t(ss1.get_max_positions_per_step());

        Crandom crandom1(MIN_STEP, max_positions_per_step, MIN_TIME_UNTIL_STEP, MAX_TIME_UNTIL_STEP);

        Crace carrera1(crandom1, number_of_snails, SPEEDWAY_LENGTH);

        // PanelWinners pwin1(carrera1.get_top3()[0], carrera1.get_top3()[1], carrera1.get_top3()[2]);

        for(size_t aux = 0; aux<SCREEN_NUM_OF_ELEMENTS; aux++)
        {
            cout << repeat_question[aux] << endl;
        }

        std::cin >> input_key;
        std::cin.clear();
        std::cin.sync();
    }

	return 0;
}

