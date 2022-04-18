//Author -> Ahdeyy
//Date -> 17/04/22
//Note -> my try at a football simulation the results are currently entirely randomized

//#include <random>
#include <iostream>
#include <stdio.h>
#include "match_events.h"
#include "team.h"

#define HALF_TIME 45
#define FULL_TIME 90


enum teams
{
	HOME = 1,
	AWAY = 2
};

teams disposses(teams in_possesion);

int main() 
{
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(1, 100);


	int away_goals = 0;
	int home_goals = 0;
	int time = 0;
	team home = team("fc", "manchester", "of united");
	team away = team("fc", "athletic", "bilbao");
	teams in_possesion = HOME;
	events current_event = PASS;

	std::cout << "KICK OFF\n";
	std::cout << "\n HOME TEAM XI\n";
	home.display_players();
	std::cout << "\n AWAY TEAM XI\n";
	away.display_players();

	while (time <= FULL_TIME)
	{


		current_event = match_events::new_event(current_event, uniform_dist(e1));

		if (current_event == PASS)
		{
			if (in_possesion == HOME)
			{
				std::cout << time << "' HOME TEAM PASSES\n";
			}
			else if (in_possesion == AWAY)
			{
				std::cout << time << "' AWAY TEAM PASSES\n";
			}
		}
		else if (current_event == CROSS)
		{
			if (in_possesion == HOME)
			{
				std::cout << time << "' HOME TEAM CROSSES\n";
			}
			else if (in_possesion == AWAY)
			{
				std::cout << time << "' AWAY TEAM CROSSES\n";
			}
		}
		else if (current_event == CORNER)
		{
			if (in_possesion == HOME)
			{
				std::cout << time << "' HOME TEAM GETS A CORNER KICK\n";
			}
			else if (in_possesion == AWAY)
			{
				std::cout << time << "' AWAY TEAM GETS A CORNER KICK\n";
			}
		}
		else if (current_event == FREE_KICK)
		{
			if (in_possesion == HOME)
			{
				std::cout << time << "' HOME TEAM GETS A FREE KICK\n";
			}
			else if (in_possesion == AWAY)
			{
				std::cout << time << "' AWAY TEAM GETS A FREE KICK\n";
			}
		}
		else if (current_event == PENALTY)
		{
			if (in_possesion == HOME)
			{
				std::cout << time << "' HOME TEAM GETS A PENALTY KICK\n";
			}
			else if (in_possesion == AWAY)
			{
				std::cout << time << "' AWAY TEAM GETS A PENALTY KICK\n";
			}
		}
		else if (current_event == INTERCEPT)
		{
			if (in_possesion == HOME)
			{
				std::cout << time << "' AWAY TEAM INTERCEPTS\n";
			}
			else if (in_possesion == AWAY)
			{
				std::cout << time << "' HOME TEAM INTERCEPTS\n";
			}
			in_possesion = disposses(in_possesion);
		}
		else if (current_event == SKILL)
		{
			if (in_possesion == HOME)
			{
				std::cout << time << "' HOME TEAM PERFORMS A SKILL!!!\n";
			}
			else if (in_possesion == AWAY)
			{
				std::cout << time << "' AWAY TEAM PERFORMS A SKILL!!!\n";
			}
		}
		else if (current_event == TACKLE)
		{
			if (in_possesion == HOME)
			{
				std::cout << time << "' AWAY TEAM TACKLE\n";
			}
			else if (in_possesion == AWAY)
			{
				std::cout << time << "' HOME TEAM TACKLE\n";
			}
			in_possesion = disposses(in_possesion);
		}
		else if (current_event == SHOOT)
		{
			if (in_possesion == HOME)
			{
				std::cout << time << "' HOME TEAM SHOOTS...\n";
			}
			else if (in_possesion == AWAY)
			{
				std::cout << time << "' AWAY TEAM SHOOTS....\n";
			}
		}
		else if (current_event == MISS)
		{
			if (in_possesion == HOME)
			{
				std::cout << time << "' HOME TEAM MISSES\n";
			}
			else if (in_possesion == AWAY)
			{
				std::cout << time << "' AWAY TEAM MISSES\n";
			}
			in_possesion = disposses(in_possesion);
		}
		else if (current_event == BLOCK)
		{
			if (in_possesion == HOME)
			{
				std::cout << time << "' AWAY TEAM BLOCKS\n";
			}
			else if (in_possesion == AWAY)
			{
				std::cout << time << "' HOME TEAM BLOCKS\n";
			}
			in_possesion = disposses(in_possesion);
		}
		else if (current_event == GOAL)
		{
			if(in_possesion == HOME)
			{
				std::cout <<time<< "' HOME TEAM SCORES!\n";
				home_goals += 1;
			}
			else if (in_possesion == AWAY)
			{
				std::cout <<time<< "' AWAY TEAM SCORES!\n";
				away_goals += 1;
			}
			in_possesion = disposses(in_possesion);
		}
		else if (current_event == SAVE)
		{
			if (in_possesion == HOME)
			{
				std::cout << time << "' AWAY TEAM GOALIE SAVES\n";
			}
			else if (in_possesion == AWAY)
			{
				std::cout << time << "' HOME TEAM GOALIE SAVES\n";
			}
			in_possesion = disposses(in_possesion);
		}
		
		if (time == HALF_TIME)
		{
			std::cout << "\nHALF TIME \n\n";
		}

		time++;
		

	}
	std::cout << "\nFULL TIME \n";
	//std::cout << "\nHOME TEAM " << home_goals << " - " << away_goals << " AWAY TEAM \n";
	std::cout << home.display_name() + " " << home_goals << " - " << away_goals + " "<<away.display_name() << "\n";
	//system("PAUSE");
	return 0;
}


teams disposses(teams in_possesion)
{
	if (in_possesion == HOME)
	{
		return AWAY;
	}
	else
	{
		return HOME;
	}
}