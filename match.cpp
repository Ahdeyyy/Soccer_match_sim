#include "match.h"

match::match(team home, team away)
{

	this->home_goals = 0;
	this->away_goals = 0;
	this->home_corners = 0;
	this->away_corners = 0;
	this->home_free_kicks = 0;
	this->away_free_kicks = 0;
	this->home_fouls = 0;
	this->away_fouls = 0;
	this->home_possesion = 0;
	this->away_possesion = 0;
	this->home_shots = 0;
	this->away_shots = 0;
	this->home_passes = 0;
	this->away_passes = 0;
	this->home_passes_completed = 0;
	this->away_passes_completed = 0;

	this->game_time = 0;

	this->in_possesion = HOME;
	this->home = home;
	this->away = away;

	this->position = MID;
	this->acting = home.players[9];

	this->last_event = NONE;
	this->current_event = PASS;
	//srand(time(NULL));
	this->next_event = match_events::new_event(current_event, rand() % 100);

}

teams match::dispossess(teams in_possesion)
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

player match::player_on_ball(positions position , team in_possession)
{
	//srand(time(NULL));
	int probability = rand() % 100;

	switch (position)
	{
		case GK: 
			return in_possession.players[1];

		case DEF:
			//srand(time(NULL));
			if (probability < 80)
			{
				int player_index = (rand() % 4) + 2;
				return in_possession.players[player_index];
			}
			else if (probability < 90)
			{
				int player_index = (rand() % 3) + 6;
				return in_possession.players[player_index];
			}
			else
			{
				int player_index = (rand() % 3) + 9;
				return in_possession.players[player_index];
			}

		case MID:
			//srand(time(NULL));
			if (probability < 25)
			{
				int player_index = (rand() % 4) + 2;
				return in_possession.players[player_index];
			}
			else if (probability < 50)
			{
				int player_index = (rand() % 3) + 6;
				return in_possession.players[player_index];
			}
			else
			{
				int player_index = (rand() % 3) + 9;
				return in_possession.players[player_index];
			}

		case FWD:
			//srand(time(NULL));
			if (probability < 15)
			{
				int player_index = (rand() % 4) + 2;
				return in_possession.players[player_index];
			}
			else if (probability < 35)
			{
				int player_index = (rand() % 3) + 6;
				return in_possession.players[player_index];
			}
			else
			{
				int player_index = (rand() % 3) + 9;
				return in_possession.players[player_index];
			}

	}



}

positions match::play_position(events current_event , events next_event)
{
	switch (current_event)
	{
	case SAVE:
		return GK;

	case INTERCEPT:
		return DEF;

	case BLOCK:
		return DEF;

	case TACKLE:
		return DEF;

	case PASS:
		return MID;

	case CROSS :
		return MID;

	case SKILL:
		if (next_event == SHOOT) 
		{
			return FWD;
		}
		else
		{
			return MID;
		}

	case SHOOT :
		return FWD;

	case CORNER:
		return MID;

	case FREE_KICK:
		if (next_event == SHOOT)
		{
			return FWD;
		}
		else
		{
			return MID;
		}

	case PENALTY:
		return FWD;

	}
}

void match::show_squads()
{
	std::cout <<"\n"<< home.display_name() + "\t\t" + away.display_name() + "\n";
	std::cout << "coach \t\t\t\t coach \n";
	std::cout << home.players[0].display_name() + "\t\t\t" + away.players[0].display_name() + "\n";
	std::cout << "players \t\t\t players\n";
	for (int i = 1; i < 12; i++)
	{
		std::cout <<i<<". " + home.players[i].display_name() + "\t\t\t" << i <<". " + away.players[i].display_name() + "\n\n";
	}
}

void match::stats()
{
	std::cout <<"\n\t" + home.display_name() + "\t\t" + away.display_name() + "\n";
	std::cout << "goals " << home_goals << "\t\t" << away_goals << "\n";
	std::cout << "possession " << home_possesion << "\t\t" << away_possesion << "\n";
	//should probably be a variable
	//integer division by zero also occurs
	std::cout << "possession(%) " << (home_possesion / (home_possesion + away_possesion)) * 100 << "\t\t" << (away_possesion / (home_possesion + away_possesion)) * 100 << "\n";
	std::cout << "shots " << home_shots << "\t\t" << away_shots << "\n";
	std::cout << "fouls " << home_fouls << "\t\t" << away_fouls << "\n";
	std::cout << "free kicks " << home_free_kicks << "\t\t" << away_free_kicks << "\n";
	std::cout << "passes " << home_passes << "\t\t" << away_passes << "\n";
	std::cout << "passes completed " << home_passes_completed << "\t\t" << away_passes_completed << "\n";
	std::cout << "corners " << home_corners << "\t\t" << away_corners << "\n";
}

void match::play()
{
	//srand(time(NULL));

	while (game_time <= FULL_TIME )
	{
		if (game_time == HALF_TIME)
		{
			current_event = PASS;
			in_possesion = AWAY;
			acting = away.players[9];

			std::cout << "\n HALF TIME \n\n";
		}

		switch (current_event)
		{
		case NONE:
			//should rethink this not wise
			std::cout << "break in play\n";
			break;
		case TACKLE:
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_on_ball(position, away);
				std::cout << acting.first_name + " " + acting.last_name << " SUCCESSFULLY TACKLES AND WINS THE BALL\n";
			}
			else
			{
				acting = player_on_ball(position, home);
				std::cout << acting.first_name + " " + acting.last_name << " SUCCESSFULLY TACKLES AND WINS THE BALL\n";
			}
			dispossess(in_possesion);
			break;
		case INTERCEPT:
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_on_ball(position, away);
				home_passes_completed -= 1;
				std::cout << acting.first_name + " " + acting.last_name << " SUCCESSFULLY INTERCEPTS AND WINS THE BALL\n";
			}
			else
			{
				acting = player_on_ball(position, home);
				away_passes_completed -= 1;
				std::cout << acting.first_name + " " + acting.last_name << " SUCCESSFULLY INTERCEPTS AND WINS THE BALL\n";
			}
			dispossess(in_possesion);
			break;
		case BLOCK:
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_on_ball(position, away);
				std::cout << acting.first_name + " " + acting.last_name << " SUCCESSFULLY BLOCKS\n";
			}
			else
			{
				acting = player_on_ball(position, home);
				std::cout << acting.first_name +" " + acting.last_name << " SUCCESSFULLY BLOCKS\n";
			}
			dispossess(in_possesion);
			break;
		case PASS:
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_on_ball(position, home);
				home_passes += 1;
				home_passes_completed += 1;
				std::cout << acting.first_name + " " + acting.last_name << " PASSES THE BALL\n";
			}
			else
			{
				acting = player_on_ball(position, away);
				away_passes += 1;
				away_passes_completed += 1;
				std::cout << acting.first_name +" " + acting.last_name << " PASSES THE BALL\n";
			}
			break;
		case CROSS:
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_on_ball(position, home);
				std::cout << acting.first_name + " " + acting.last_name << " CROSSES THE BALL\n";
			}
			else
			{
				acting = player_on_ball(position, away);
				std::cout << acting.first_name + " " + acting.last_name << " CROSSES THE BALL\n";
			}
			break;
		case SHOOT:
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_on_ball(position, home);
				home_shots += 1;
				std::cout << acting.first_name + " " + acting.last_name << " SHOOTS THE BALL\n";
			}
			else
			{
				acting = player_on_ball(position, away);
				away_shots += 1;
				std::cout << acting.first_name + " " + acting.last_name << " SHOOTS THE BALL\n";
			}
			break;
		case SAVE:
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_on_ball(position, away);
				std::cout << acting.first_name + " " + acting.last_name << " SAVES THE SHOT\n";
			}
			else
			{
				acting = player_on_ball(position, home);
				std::cout << acting.first_name + " " + acting.last_name << " SAVES THE SHOT\n";
			}
			dispossess(in_possesion);
			break;
		case SKILL:
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_on_ball(position, home);
				std::cout << acting.first_name + " " + acting.last_name << " PERFORMS A SKILL\n";
			}
			else
			{
				acting = player_on_ball(position, away);
				std::cout << acting.first_name + " " + acting.last_name << " PERFORMS A SKILL\n";
			}
			break;
		case FOUL:
			//modify tackle so the team on the ball doesn't switch if it results in a foul
			//-*use the next_event
			dispossess(in_possesion);
			if (in_possesion == HOME)
			{
				home_fouls += 1;
				std::cout << acting.first_name + " " + acting.last_name << " COMMITS A FOUL\n";
			}
			else
			{
				away_fouls += 1;
				std::cout << acting.first_name + " " + acting.last_name << " COMMITS A FOUL\n";
			}
			
			break;
		case YELLOW_CARD:
			if (in_possesion == HOME)
			{

			}
			else
			{

			}
			break;
		case RED_CARD:
			if (in_possesion == HOME)
			{

			}
			else
			{

			}
			break;
		case PENALTY:
			if (in_possesion == HOME)
			{
				acting = player_on_ball(position, home);
				std::cout << acting.first_name + " " + acting.last_name << " SHOOTS THE BALL\n";
			}
			else
			{
				acting = player_on_ball(position, away);
				std::cout << acting.first_name + " " + acting.last_name << " SHOOTS THE BALL\n";
			}
			break;
		case FREE_KICK:
			if (in_possesion == HOME)
			{
				home_free_kicks += 1;
				acting = player_on_ball(position, home);
				std::cout << acting.first_name + " " + acting.last_name << " TO TAKE THE FREEKICK\n";
			}
			else
			{
				away_free_kicks += 1;
				acting = player_on_ball(position, away);
				std::cout << acting.first_name + " " + acting.last_name << " TO TAKE THE FREEKICK\n";
			}
			break;
		case CORNER:
			dispossess(in_possesion);
			if (in_possesion == HOME)
			{
				home_corners += 1;
				acting = player_on_ball(position, home);
				std::cout << acting.first_name + " " + acting.last_name << " TO TAKE THE CORNER KICK\n";
			}
			else
			{
				away_corners += 1;
				acting = player_on_ball(position, away);
				std::cout << acting.first_name + " " + acting.last_name << " TO TAKE THE CORNER KICK\n";
			}
			break;
		case MISS:
			if (in_possesion == HOME)
			{
				std::cout << acting.first_name + " " + acting.last_name << " MISSES THE SHOT\n";
			}
			else
			{
				std::cout << acting.first_name + " " + acting.last_name << " MISSES THE SHOT\n";
			}
			dispossess(in_possesion);
			break;
		case GOAL:
			if (in_possesion == HOME)
			{
				std::cout << acting.first_name + " " + acting.last_name << " SCORES!!!!\n";
				home_goals += 1;
			}
			else
			{
				std::cout << acting.first_name + " " + acting.last_name << " SCORES!!!!\n";
				away_goals += 1;
			}
			dispossess(in_possesion);
			break;

		}

		last_event = current_event;
		current_event = next_event;
		next_event = match_events::new_event(current_event, rand() % 100);
		position = play_position(current_event, next_event);
		if (in_possesion == HOME)
		{
			home_possesion += 1;
		}
		else
		{
			away_possesion += 1;
		}
		game_time++;

	}
}