#include "race.h"
#include "random.h"
#include "gui.h"

using namespace std;

int main()
{

    FirstScreen fs1;
    SecondScreen ss1;

    size_t number_of_snails = size_t(ss1.get_number_of_snails());
    size_t max_positions_per_step = size_t(ss1.get_max_positions_per_step());

    size_t MIN_STEP = 0;

    size_t SPEEDWAY_LENGTH = 60;

    int MIN_TIME_UNTIL_STEP = 0;
    int MAX_TIME_UNTIL_STEP = 600;

    Crandom crandom1(MIN_STEP, max_positions_per_step, MIN_TIME_UNTIL_STEP, MAX_TIME_UNTIL_STEP);

	Crace carrera1(crandom1, number_of_snails, SPEEDWAY_LENGTH);

	return 0;
}

