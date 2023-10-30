#include <iostream>
#include <memory>
#include <string>
#include "race.h"
#include "random.h"
#include "gui.h"

using namespace std;

const int SCREEN_NUM_OF_ELEMENTS = 16;

string message_template[SCREEN_NUM_OF_ELEMENTS]=
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
"|                                                                    |",
"|                                                                    |",
"----------------------------------------------------------------------"};

 string repeat_question=
{
"|                         Repeat(R) the race                         |"};

 string start_question=
{
"|                         Start(S) a new game                        |"};

 string exit_question=
{
"|                         Exit(E) the game                           |"};


int main()
{
    size_t MIN_STEP = 0;

    size_t SPEEDWAY_LENGTH = 60;

    int MIN_TIME_UNTIL_STEP = 0;
    int MAX_TIME_UNTIL_STEP = 600;

    string input_key ="S";

    size_t number_of_snails;
    size_t max_positions_per_step;

    while(!(input_key != "E" ^ input_key != "e"))
    {
        if(input_key == "S" || input_key =="s")
        {
            FirstScreen fs1;
            SecondScreen ss1;

            number_of_snails = size_t(ss1.get_number_of_snails());
            max_positions_per_step = size_t(ss1.get_max_positions_per_step());
        }

        // Repeat(press "R" or "r") implies the use of the previous conditional attributes
        if(input_key == "S" || input_key =="s" || input_key == "R" || input_key =="r")
        {
            //All the necessary things for the race are here
            Crandom crandom1(MIN_STEP, max_positions_per_step, MIN_TIME_UNTIL_STEP, MAX_TIME_UNTIL_STEP);
            Crace carrera1(crandom1, number_of_snails, SPEEDWAY_LENGTH);
            PanelWinners pwin1(carrera1.get_top3()[0], carrera1.get_top3()[1], carrera1.get_top3()[2]);
        }

        // Final questions
        for(size_t aux = 0; aux<SCREEN_NUM_OF_ELEMENTS; aux++)
        {
            if(aux == 9)
                cout << repeat_question << endl;
            else if(aux == 10)
                cout << start_question << endl;
            else if(aux == 11)
                cout << exit_question << endl;
            else
                cout << message_template[aux] << endl;
        }
        
        cin >> input_key;
        cin.clear();
        cin.sync();
    }

	return 0;
}

