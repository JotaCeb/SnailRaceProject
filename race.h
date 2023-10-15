#if !defined(_RACE_H_)
#define _RACE_H_

#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <sstream>
#include "snail.h"
#include "random.h"

class Crace
{
	private:
    	std::ostringstream race_output_;

    	std::string panel_position_;
		std::string str_position1_ = "POSITION 1: ";
		std::string str_position2_ = "POSITION 2: ";
		std::string str_position3_ = "POSITION 3: ";

		int position1_;
		int position2_;
		int position3_;

		int snails_number_;
		std::size_t steps_of_speedway_;

		std::vector<std::unique_ptr<Csnail>> snails_;
        std::string street_;

		std::size_t goal_;
		std::size_t max_positions_per_step_;

	public:
		Crace(Crandom& crandom, int snails_number, std::size_t steps_of_speedway);
		void update_race_window();
		std::vector<int> get_top3();

		friend int* update_position_panel(int num_snails, std::size_t position_values[20]);

};

int* update_position_panel(int num_snails, std::size_t position_values[20]);

#endif

