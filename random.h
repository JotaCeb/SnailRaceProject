#if !defined(_RANDOM_H_)
#define _RANDOM_H_

#include <mutex>
#include <random>

class Crandom
{
    private:
        std::size_t min_position_advance_;
        std::size_t max_position_advance_;
        int min_time_;
        int max_time_; 

        std::mutex random_mutex_;
        
    public:
        
        Crandom(std::size_t min, std::size_t max, int min_time, int max_time)
        : min_position_advance_(min), max_position_advance_(max), min_time_(min_time), max_time_(max_time){}
        Crandom() = default;
        
        std::size_t get_random_position();
        int get_random_time();

        Crandom& operator=(const Crandom&);

        std::size_t get_max_position_advance(){return max_position_advance_;}

};
#endif
