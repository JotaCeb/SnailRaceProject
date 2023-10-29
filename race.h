#if !defined(_RACE_H_)
#define _RACE_H_

#include <sstream>
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

		static const int SCREEN_NUM_OF_ELEMENTS = 16;

		std::string message_template[SCREEN_NUM_OF_ELEMENTS]=
		{
		"----------------------------------------------------------------------",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
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

		std::string countdown_3[SCREEN_NUM_OF_ELEMENTS]=
		{
		"----------------------------------------------------------------------",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"|                            ________                                |",
		"|                            \\_____  \\                               |",
		"|                              _(__  <                               |",
		"|                             /       \\                              |",
		"|                            /______  /                              |",
		"|                            	    \\/                               |",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"----------------------------------------------------------------------"};

		std::string countdown_2[SCREEN_NUM_OF_ELEMENTS]=
		{
		"----------------------------------------------------------------------",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"|                            ________                                |",
		"|                            \\_____  \\                               |",
		"|                             /  ____/                               |",
		"|                            /       \\                               |",
		"|                            \\_______ \\                              |",
		"|                                    \\/                              |",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"----------------------------------------------------------------------"};

		
		std::string countdown_1[SCREEN_NUM_OF_ELEMENTS]=
		{
		"----------------------------------------------------------------------",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"|                              ____                                  |",
		"|                             /_   |                                 |",
		"|                              |   |                                 |",
		"|                              |   |                                 |",
		"|                             _|   |_                                |",
		"|                            /_______\\                               |",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"|                                                                    |",
		"----------------------------------------------------------------------"};

	    std::ostringstream big_number1_, big_number2_, big_number3_;
	
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

		void countdown();

	public:
		Crace(Crandom& crandom, int snails_number, std::size_t steps_of_speedway);
		void update_race_window();
		std::vector<int> get_top3();

		friend int* update_position_panel(int num_snails, std::size_t position_values[20]);

};

int* update_position_panel(int num_snails, std::size_t position_values[20]);

#endif

