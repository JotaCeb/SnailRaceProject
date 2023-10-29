#include <iostream>
#include <string>
#include <thread>
#include <conio.h>
#include <mutex>
#include "race.h"
#include "random.h"

using namespace std;

Crace::Crace(Crandom& crandom, int snails_number, size_t steps_of_speedway) 
: snails_number_(snails_number), steps_of_speedway_(steps_of_speedway)
{
    // Big numbers for countdown creation
    for(int i = 0; i < SCREEN_NUM_OF_ELEMENTS; i++)
    {
        big_number1_ << countdown_1[i] << endl;
        big_number2_ << countdown_2[i] << endl;
        big_number3_ << countdown_3[i] << endl;
    }
    
    // Lenght of snail is added to the length of the street (8)
    street_ = string(steps_of_speedway_ + size_t(8), '=');
    goal_ = 0;

	position1_ = position2_ = position3_ = 0;

    // It is supposed the 3 string of the position panel have the same length
    size_t panel_position_margin = size(str_position1_)/2;
    size_t local_panel_position = size(street_)/2 - panel_position_margin;
    local_panel_position < 1 ? panel_position_ = "" : panel_position_ = string(size_t(local_panel_position), ' ');

    max_positions_per_step_ = crandom.get_max_position_advance();

    countdown();
    
    // Throw the snails over the speedway
    for(int i = 0; i < snails_number_; i++)
        snails_.emplace_back(new Csnail(crandom, i, steps_of_speedway_, snails_number_));

    update_race_window();
}

void Crace::countdown()
{
    system("cls");

    cout << big_number3_.str();
    this_thread::sleep_for(chrono::milliseconds(3000));
    system("cls");

    cout << big_number2_.str();
    this_thread::sleep_for(chrono::milliseconds(3000));
    system("cls");

    cout << big_number1_.str();
    this_thread::sleep_for(chrono::milliseconds(3000));
    system("cls");
}

void Crace::update_race_window()
{
    int i = 0;
    bool first_update = true;

    // All the positions of the race
    size_t current_positions[20];
    for(int i = 0; i < 20; i++) current_positions[i] = 0;

    int* top3 = update_position_panel(snails_number_, current_positions);
    
    thread race_updater([&](){
        while(goal_ < steps_of_speedway_)
        {        
            system("cls");
            cout << race_output_.str();

            // First snail can shout in the second panel update
            if (first_update == false) snails_.at(top3[0]).get()->shout();
            if(first_update == true) first_update = false; 

            // Put an empty string and cleaning flags
            race_output_.str("");
            race_output_.clear();
            
            //Double line on top
            race_output_ << street_ << endl;

            for(i = 0; i < snails_number_; i++)
            {   
                //scoped_lock is recursive
                scoped_lock<mutex> local_race_mutex(snails_.at(i).get()->snail_mutex);

                race_output_ << street_ << endl << (snails_.at(i).get()->snail_running).str() << endl;
                current_positions[i] = snails_.at(i).get()->get_position();

                if(current_positions[i] > goal_ && current_positions[i] > max_positions_per_step_)
                // Max positions per step is substracted in the goal (thus, snail arrive the end of speedway)
                    goal_ = snails_.at(i).get()->get_position();
            }

            top3 = update_position_panel(snails_number_, current_positions);

            // Double line on speedway down
            race_output_ << street_ << endl; race_output_ << street_ << endl;

            // This is the position panel
            race_output_ << panel_position_ << "POSITION 1: " << top3[0] << "\n";
            race_output_ << panel_position_ << "POSITION 2: " << top3[1] << "\n";
            if(snails_number_ > 2){race_output_ << panel_position_ << "POSITION 3: " << top3[2] << "\n";}
            race_output_ << street_ << endl; race_output_ << street_ << endl;

            // Time until a new refresh
            this_thread::sleep_for(chrono::milliseconds(400));

            if(goal_ >= steps_of_speedway_)
            {
                // This is the last step, necessary for snail winner is showed      
                system("cls");
                cout << race_output_.str();
                this_thread::sleep_for(chrono::milliseconds(4000));
                system("cls");
                position1_ = top3[0]; position2_ = top3[1]; position3_ = top3[2];
            }
        }
    });
    
    race_updater.join();
}

vector<int> Crace::get_top3()
{
    vector<int> v_local;
    v_local.push_back(position1_);
    v_local.push_back(position2_);
    v_local.push_back(position3_);
    return v_local;
}


// Get the 1st, 2nd and 3rd positions
int* update_position_panel(int num_snails, size_t position_values[20])
{
    size_t most_advanced_step = 0;
    size_t sort_position_values[20];

    int* top3_positions;

    // Snail number position
    top3_positions = new (int[3]);
    // 3,4,5 for the steps
    top3_positions = new (int[3]);

    for(auto i = 0; i < num_snails; i++)
    {
       sort_position_values[i] = 0;
    }

    for(auto i = 0; i < num_snails; i++)
    {
        if(sort_position_values[0] < position_values[i])
        {
            if(sort_position_values[1] < sort_position_values[0])
            {
                if(sort_position_values[2] < sort_position_values[1])
                {
                    sort_position_values[2] = sort_position_values[1];
                    top3_positions[2] = top3_positions[1];
                }
                sort_position_values[1] = sort_position_values[0];
                top3_positions[1] = top3_positions[0];
            }

            sort_position_values[0] = position_values[i];
            top3_positions[0] = i;
        }
        else if(sort_position_values[1] < position_values[i])
        {
            if(sort_position_values[2] < sort_position_values[1])
            {
                sort_position_values[2] = sort_position_values[1];
                top3_positions[2] = top3_positions[1];
            }
            sort_position_values[1] = position_values[i];
            top3_positions[1] = i;
        }
        else if(sort_position_values[2] < position_values[i])
        {
            sort_position_values[2] = position_values[i];
            top3_positions[2] = i;
        }
    }

    top3_positions[3] = sort_position_values[0];
    top3_positions[4] = sort_position_values[1];
    top3_positions[5] = sort_position_values[2];

    return top3_positions;
}
