#include <iostream>
#include "race.h"
#include "random.h"
#include "gui.h"

using namespace std;

const int SCREEN_NUM_OF_ELEMENTS = 16;

 std::string repeat_question[SCREEN_NUM_OF_ELEMENTS]=
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
"|            Do you want to repeat the race? (Y/other)               |",
"|                                                                    |",
"|                                                                    |",
"|                                                                    |",
"|                                                                    |",
"----------------------------------------------------------------------"};

int main()
{
    size_t MIN_STEP = 0;

    size_t SPEEDWAY_LENGTH = 10;

    int MIN_TIME_UNTIL_STEP = 0;
    int MAX_TIME_UNTIL_STEP = 600;

    string yes_no ="Y";

    FirstScreen fs1;
    SecondScreen ss1;

    const int NUMBER_OF_ELEMENTS = 16;

    while(yes_no == "Y" || yes_no == "y")
    {
        size_t number_of_snails = size_t(ss1.get_number_of_snails());
        size_t max_positions_per_step = size_t(ss1.get_max_positions_per_step());

        Crandom crandom1(MIN_STEP, max_positions_per_step, MIN_TIME_UNTIL_STEP, MAX_TIME_UNTIL_STEP);

        Crace carrera1(crandom1, number_of_snails, SPEEDWAY_LENGTH);

        PanelWinners pwin1(carrera1.get_top3()[0], carrera1.get_top3()[1], carrera1.get_top3()[2]);

        for(size_t aux = 0; aux<SCREEN_NUM_OF_ELEMENTS; aux++)
            cout << repeat_question[aux] << endl;

        std::cin >> yes_no;
        std::cin.clear();
        std::cin.sync();
    }

	return 0;
}

