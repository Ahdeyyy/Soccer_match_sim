#include "match.h"

match::match(team home, team away)
{

	this->home_goals = 0;
	this->away_goals = 0;
	this->home_corners = 0;
	this->away_corners = 0;
	this->home_free_kicks = 0;
	this->away_free_kicks = 0;
	this->home_penalties = 0;
	this->away_penalties = 0;
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
	this->last_actor = home.players[9];

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

player match::player_with_ball(positions position , team in_possession)
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
	std::cout <<"\n"<< home.display_name() + "\t\t\t\t\t" + away.display_name() + "\n";
	std::cout << "coach \t\t\t\t\t\t\t coach \n";
	std::cout << home.players[0].display_name() + "\t\t\t\t\t\t\t\t\t" + away.players[0].display_name() + "\n";
	std::cout << "players \t\t\t\t\t\t\t\t\t players\n";
	for (int i = 1; i < 12; i++)
	{
		std::cout <<i<<". " + home.players[i].display_name() + "\t\t\t\t\t\t" << i <<". " + away.players[i].display_name() + "\n\n";
	}
}

void match::stats()
{
	std::cout <<"\n\t\t\t" + home.display_name() + "\t\t\t\t" + away.display_name() + "\n";
	std::cout << "goals " <<"\t\t\t" <<home_goals << "\t\t\t\t\t\t" << away_goals << "\n";
	std::cout << "possession " <<"\t\t"<< home_possesion << "\t\t\t\t\t\t" << away_possesion << "\n";
	//should probably be a variable
	//integer division by zero also occurs
	std::cout << "possession(%) " <<"\t\t"<< (home_possesion * 100 / (home_possesion + away_possesion)) << "\t\t\t\t\t\t" << (away_possesion * 100 / (home_possesion + away_possesion)) << "\n";
	std::cout << "shots " <<"\t\t\t"<< home_shots << "\t\t\t\t\t\t" << away_shots << "\n";
	std::cout << "fouls " <<"\t\t\t"<< home_fouls << "\t\t\t\t\t\t" << away_fouls << "\n";
	std::cout << "free kicks " <<"\t\t"<< home_free_kicks << "\t\t\t\t\t\t" << away_free_kicks << "\n";
	std::cout << "penalties " <<"\t\t"<< home_penalties << "\t\t\t\t\t\t" << away_penalties << "\n";
	std::cout << "passes " <<"\t\t\t"<< home_passes << "\t\t\t\t\t\t" << away_passes << "\n";
	std::cout << "passes completed " <<"\t"<< home_passes_completed << "\t\t\t\t\t\t" << away_passes_completed << "\n";
	std::cout << "corners " <<"\t\t"<< home_corners << "\t\t\t\t\t\t" << away_corners << "\n";
}

void match::play()
{
	//srand(time(NULL));

	while (game_time <= FULL_TIME * 5 )
	{
		srand(rand() * time(0) * time(0));
		if (game_time == HALF_TIME * 5)
		{
			current_event = PASS;
			in_possesion = AWAY;
			acting = away.players[9];

			std::cout << "\n HALF TIME \n\n";
		}
		comment = commentary::text(last_event, current_event, next_event, game_time, last_actor, acting);
		if (comment != "") {
			std::cout << "'" << (game_time / 5) << " " << comment;
		};
		switch (current_event)
		{
		case NONE:
			//should rethink , this not wise
			
			break;
		case TACKLE:
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_with_ball(position, away);
			}
			else
			{
				acting = player_with_ball(position, home);
				
			}
			dispossess(in_possesion);
			break;
		case INTERCEPT:
			last_actor = acting;
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_with_ball(position, away);
				home_passes_completed -= 1;
			}
			else
			{
				acting = player_with_ball(position, home);
				away_passes_completed -= 1;
			}
			dispossess(in_possesion);
			break;
		case BLOCK:
			last_actor = acting;
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_with_ball(position, away);
			}
			else
			{
				acting = player_with_ball(position, home);
			}
			dispossess(in_possesion);
			break;
		case PASS:
			last_actor = acting;
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				
				srand(rand() * time(0) * rand() * time(0));
				acting = player_with_ball(position, home);
				home_passes += 1;
				home_passes_completed += 1;
			}
			else
			{
				acting = player_with_ball(position, away);
				away_passes += 1;
				away_passes_completed += 1;
			}
			break;
		case CROSS:
			last_actor = acting;
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_with_ball(position, home);
			}
			else
			{
				acting = player_with_ball(position, away);
			}
			break;
		case SHOOT:
			last_actor = acting;
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_with_ball(position, home);
				home_shots += 1;
			}
			else
			{
				acting = player_with_ball(position, away);
				away_shots += 1;
			}
			break;
		case SAVE:
			last_actor = acting;
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				/*acting = player_with_ball(position, away);*/
				acting = away.players[1];
			}
			else
			{
				acting = player_with_ball(position, home);
			}
			dispossess(in_possesion);
			break;
		case SKILL:
			last_actor = acting;
			position = play_position(current_event, next_event);
			if (in_possesion == HOME)
			{
				acting = player_with_ball(position, home);
			}
			else
			{
				acting = player_with_ball(position, away);
			}
			break;
		case FOUL:
			//modify tackle so the team on the ball doesn't switch if it results in a foul
			//-*use the next_event
			dispossess(in_possesion);
			if (in_possesion == HOME)
			{
				home_fouls += 1;
			}
			else
			{
				away_fouls += 1;
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
			last_actor = acting;
			if (in_possesion == HOME)
			{
				//acting = player_with_ball(position, home);
				home_penalties += 1;
			}
			else
			{
				//acting = player_with_ball(position, away);
				away_penalties += 1;
			}
			break;
		case FREE_KICK:
			//last_actor = acting;
			if (in_possesion == HOME)
			{
				home_free_kicks += 1;
				acting = player_with_ball(position, home);
			}
			else
			{
				away_free_kicks += 1;
				acting = player_with_ball(position, away);
			}
			break;
		case CORNER:
			last_actor = acting;
			dispossess(in_possesion);
			if (in_possesion == HOME)
			{
				home_corners += 1;
				acting = player_with_ball(position, home);
			}
			else
			{
				away_corners += 1;
				acting = player_with_ball(position, away);
			}
			break;
		case MISS:
			if (in_possesion == HOME)
			{
			}
			else
			{
			}
			dispossess(in_possesion);
			break;
		case GOAL:
			if (in_possesion == HOME)
			{
				home_goals += 1;
			}
			else
			{
				away_goals += 1;
			}
			dispossess(in_possesion);
			break;

		}
		//last_actor = acting;
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