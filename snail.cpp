#include <iostream>
#include <string>
#include <thread>
#include <future>
#include <mutex>
#include <Windows.h>
#include <fcntl.h>  // Just for º character
#include <io.h>     // Just for º character
#include "snail.h"
#include "random.h"

using namespace std;

Csnail::Csnail(Crandom& crandom, int participant_number, size_t maximum_advances, int max_number_of_participants) 
: participant_number_(participant_number), maximum_advances_(maximum_advances), max_number_of_participants_(max_number_of_participants)
{
    crandom_ = crandom;
    position_ = 0;

    {
        unique_lock<mutex> local_mutex_csnail (snail_mutex);
        snail_running << "";
    }
    motor_ = async(&Csnail::get_random_position, this);
}

void Csnail::get_random_position()
{
    size_t advance;
    int random_time;
    while (position_ < maximum_advances_)
    {
        advance = crandom_.get_random_position();
        position_ = position_ + advance;
        random_time = int(crandom_.get_random_time());
        save_str_position();
        this_thread::sleep_for(chrono::milliseconds(200 + random_time));    
    }
}

void Csnail::save_str_position()
{
    unique_lock<mutex> local_mutex_csnail (snail_mutex);

    // Put an empty string and cleaning flags
    snail_running.str("");
    snail_running.clear();
    
    // Current advances (' ')
    basic_move_x_ = string(position_, ' ');
    
    // Current snail with its current advances (' ')
    // Top part of the snail
    snail_running << basic_move_x_ + " ---   ";
    
    // The next 4 lines are only for to show correctly the ext. ASCII char º
    _setmode(_fileno(stdout), _O_U16TEXT);
    snail_running << char(167);             // º
    _setmode(_fileno(stdout), _O_TEXT);
    cout.clear();
    
    snail_running << endl << basic_move_x_ 
    << "/ " << to_string(participant_number_) << " " ;

    // This is for the snail wake
    if(position_ > 2 && (int(position_) % 2 == 0))
    {
        basic_move_x_.pop_back();basic_move_x_.pop_back();basic_move_x_.pop_back();
        snail_running << "\\ /" << endl << basic_move_x_ << ".. -----'";
    }
    else if(position_ > 1)
    {
        basic_move_x_.pop_back();basic_move_x_.pop_back();
        snail_running << "\\ /" << endl << basic_move_x_ << ". -----'";
    }
    else
        snail_running << "\\ /" << endl << basic_move_x_ << "-----'";

    if(position_ > maximum_advances_)
    {
        //Here the snail arrive to goal
        promise_.set_value(1);
    }
}

void Csnail::shout()
{
    // Beep(Hz, during(ms)) - 20Hz is notable from one snail number to the next
    Beep(500 + participant_number_*20, BEEP_MILISECONDS);
} 
