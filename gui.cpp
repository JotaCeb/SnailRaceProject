#include<iostream>
#include <sstream>
#include <thread>
#include<conio.h>
#include<vector>
#include<string>
#include <chrono>
#include"gui.h"

using namespace std;
using namespace std::chrono;

vector<string> v_string_builder(vector<string>& aux_v_str, string strings_10[], int number_of_elements);

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

PanelWinners::PanelWinners(int first, int second, int third) : first_(first), second_(second), third_(third)
{
    vector<string> v_string;
    auto elmts = NUMBER_OF_ELEMENTS;

    // First kind of numbers from 0 to 9
    all_panel_winners.push_back(v_string_builder(v_string, str_number_0_, elmts)); v_string.clear(); // 0
    all_panel_winners.push_back(v_string_builder(v_string, str_number_1_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_2_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_3_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_4_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_5_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_6_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_7_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_8_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_9_, elmts)); v_string.clear();

    // Second kind of numbers from 0 to 9
    all_panel_winners.push_back(v_string_builder(v_string, str_number_0_view2_, elmts)); v_string.clear(); // 10
    all_panel_winners.push_back(v_string_builder(v_string, str_number_1_view2_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_2_view2_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_3_view2_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_4_view2_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_5_view2_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_6_view2_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_7_view2_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_8_view2_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_number_9_view2_, elmts)); v_string.clear();

    // Space
    all_panel_winners.push_back(v_string_builder(v_string, str_space_, elmts)); v_string.clear(); // 20

    // First kind of panel winners
    all_panel_winners.push_back(v_string_builder(v_string, str_panel_result_winner_, elmts)); v_string.clear(); // 21
    all_panel_winners.push_back(v_string_builder(v_string, str_panel_result_second_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_panel_result_third_, elmts)); v_string.clear();

    // Second kind of panel winners
    all_panel_winners.push_back(v_string_builder(v_string, str_panel_result_winner_view2_, elmts)); v_string.clear(); // 24
    all_panel_winners.push_back(v_string_builder(v_string, str_panel_result_second_view2_, elmts)); v_string.clear();
    all_panel_winners.push_back(v_string_builder(v_string, str_panel_result_third_view2_, elmts)); v_string.clear();

    auto first_digit1 = first / 10; auto second_digit1 = second / 10; auto third_digit1 = third / 10;
    auto first_digit2 = first % 10; auto second_digit2 = second % 10; auto third_digit2 = third % 10;

    auto first_digit1_view2 = first_digit1 + 10; auto second_digit1_view2 = second_digit1 + 10;
    auto first_digit2_view2 = first_digit2 + 10; auto second_digit2_view2 = second_digit2 + 10;
         
    auto third_digit1_view2 = third_digit1 + 10;
    auto third_digit2_view2 = third_digit2 + 10;

    string all_panel_message = "";

    // First view of the winners stored in an ostringstream
    for(int i = 0; i<NUMBER_OF_ELEMENTS; i++)
        output_panel_ << all_panel_winners.at(21)[i] 
        << (first_digit1 == 0 ? "" : all_panel_winners.at(first_digit1)[i]) 
        << all_panel_winners.at(first_digit2)[i] << endl;

    for(int i = 0; i<NUMBER_OF_ELEMENTS; i++)
        output_panel_ << all_panel_winners.at(20)[i] << all_panel_winners.at(22)[i] 
        << (second_digit1 == 0 ? "" : all_panel_winners.at(second_digit1)[i]) 
        << all_panel_winners.at(second_digit2)[i] << endl;
    
    for(int i = 0; i<NUMBER_OF_ELEMENTS; i++)
        output_panel_ << all_panel_winners.at(20)[i] << all_panel_winners.at(23)[i] 
        << (third_digit1 == 0 ? "" : all_panel_winners.at(third_digit1)[i]) 
        << all_panel_winners.at(third_digit2)[i] << endl;

    // Second view of the winners stored in an ostringstream
    for(int i = 0; i<NUMBER_OF_ELEMENTS; i++)
        output_panel_view2_ << all_panel_winners.at(24)[i] 
        << (first_digit1_view2 == 10 ? "" : all_panel_winners.at(first_digit1_view2)[i]) 
        << all_panel_winners.at(first_digit2_view2)[i] << endl;

    for(int i = 0; i<NUMBER_OF_ELEMENTS; i++)
        output_panel_view2_ << all_panel_winners.at(20)[i] << all_panel_winners.at(25)[i] 
        << (second_digit1_view2 == 10 ? "" : all_panel_winners.at(second_digit1_view2)[i]) 
        << all_panel_winners.at(second_digit2_view2)[i] << endl;
    
    for(int i = 0; i<NUMBER_OF_ELEMENTS; i++)
        output_panel_view2_ << all_panel_winners.at(20)[i] << all_panel_winners.at(26)[i] 
        << (third_digit1_view2 == 10 ? "" : all_panel_winners.at(third_digit1_view2)[i]) 
        << all_panel_winners.at(third_digit2_view2)[i] << endl;

    show_the_winners();
}

void PanelWinners::show_the_winners()
{
    int j = 0;

    while(j++ < 5)
    {
        cout << output_panel_.str();
        this_thread::sleep_for(chrono::milliseconds(1000));
        system("cls");
        
        cout << output_panel_view2_.str();
        this_thread::sleep_for(chrono::milliseconds(1000));
        system("cls");
    }
}

vector<string> v_string_builder(vector<string>& aux_v_str, string strings_10[], int number_of_elements)
{
    for(int i = 0; i < number_of_elements; i++)aux_v_str.push_back(strings_10[i]);
    return aux_v_str;
}
