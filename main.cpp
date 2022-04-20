//Author -> Ahdeyy
//Date -> 17/04/22
//Note -> my try at a football simulation the results are currently entirely randomized

#include "match.h"


int main() 
{

	int away_goals = 0;
	int home_goals = 0;
	int time = 0;
	team home = team("fc", "manchester", "of united");
	team away = team("fc", "athletic", "bilbao");
	
	match sky = match();

	
	sky.show_squads();
	std::cout << "KICK OFF\n\n";
	sky.play();
	sky.stats();

	return 0;
}
