#include <iostream>
#include <mutex>
#include <Windows.h>
#include "random.h"

using namespace std;

size_t Crandom::get_random_position()
{
    unique_lock<mutex> mutex_position_local (random_mutex_);

    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    QueryPerformanceCounter(&li);

    int crazy_position = li.QuadPart;
    int ran = abs(crazy_position);
    ran = ran % max_position_advance_;

    return (ran < min_position_advance_ || ran > max_position_advance_) ? get_random_position() : ran;
}

// Get a random step time in function of time
int Crandom::get_random_time()
{
    unique_lock<mutex> mutex_time_local (random_mutex_);

    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    QueryPerformanceCounter(&li);

    int anytime = li.QuadPart;
    int ran = abs(anytime);
    ran = ran % max_time_;

    return (ran < min_time_ || ran > max_time_) ? get_random_time() : ran;
    
}

// Copy all the Crandom instantiation in the new crandom instantiation
Crandom& Crandom::operator=(const Crandom& cran)
{
    min_position_advance_ = cran.min_position_advance_;
    max_position_advance_ = cran.max_position_advance_;
    min_time_ = cran.min_time_;
    max_time_ = cran.max_time_; 

    return (*this);
}