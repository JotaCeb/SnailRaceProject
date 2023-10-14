#if !defined(_SNAIL_H_)
#define _SNAIL_H_

#include <sstream>
#include <string>
#include <future>
#include <mutex>
#include "random.h"

class Csnail
{
    private:
        int participant_number_;
        std::size_t position_;
        std::size_t maximum_advances_;
        int max_number_of_participants_;

        std::string basic_move_x_;
        Crandom crandom_;

        std::future<std::size_t> future_;
        std::promise<std::size_t> promise_;

        std::future<void> motor_;

        static const int BEEP_MILISECONDS = 200;

    public:
        Csnail(Crandom& crandom, int participant_number, std::size_t maximum_advances, int max_number_of_participants);
        void get_random_position();
        void shout();
        void save_str_position();
        
        std::size_t get_position (){return position_;}
        
        std::ostringstream snail_running;
        std::mutex snail_mutex;
        
};
#endif