#include<iostream>
#include<conio.h>
#include<string>
#include"gui.h"

using namespace std;

FirstScreen::FirstScreen()
{
    task_first_screen();
}

void FirstScreen::task_first_screen()
{
    // Needed for to change the two kind of representations of the snail
    bool toogle_flag = false;
    
    string enter = "";
    char ch_input;
    cout.clear();
    cin.sync();
    
    while(ch_input != '\r')
    {
        // Enter whatever no <Enter> key and the snails will move
        system("cls");
        if(toogle_flag == false)
        {
            toogle_flag = true;
            for(size_t aux = 0; aux<SCREEN_NUM_OF_ELEMENTS; aux++)
                cout << str_first_screen1[aux] << endl;
        }
        else
        {
            toogle_flag = false;
            for(size_t aux = 0; aux<SCREEN_NUM_OF_ELEMENTS; aux++)
                cout << str_first_screen2[aux] << endl;
        }
        ch_input = getch();
    }
}

SecondScreen::SecondScreen()
{
    number_of_snails_ = 0;
    max_positions_per_step = 0;

    task_second_screen();
}

void SecondScreen::task_second_screen()
{
    system("cls");

    // Limits of the number of snails
    while (number_of_snails_ < 2 || number_of_snails_ > 20)
    {
        for(size_t aux = 0; aux<SCREEN_NUM_OF_ELEMENTS; aux++)
            cout << str_second_screen1[aux] << endl;

        // Input for the race
        cin >> number_of_snails_;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        system("cls");
    }

    // Limits of positions per step
    while (max_positions_per_step < 2 || max_positions_per_step > 10)
    {
        for(size_t aux = 0; aux<SCREEN_NUM_OF_ELEMENTS; aux++)
            cout << str_second_screen2[aux] << endl;

        // Other input for the race
        cin >> max_positions_per_step;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        system("cls");
    }
}