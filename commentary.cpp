#include "commentary.h"

std::string commentary::text(events last_event, events current_event, events next_event, int time, player last_actor, player acting)
{
	//should add scores in the next iteration
	std::string comment = "";

	switch (current_event)
	{
	case NONE:
	case TACKLE:
		if (((rand() % 100) > 95) && next_event == PASS)
		{
			comment = "a robust tackcle from " + acting.first_name + " to win the ball back\n";
		}
		return comment;
		break;
	case INTERCEPT:
		if (((rand() % 100) > 95) && next_event == PASS)
		{
			comment = "a well timed interception from " + acting.first_name + " to win the ball back\n";
		}
		return comment;
		break;
	case BLOCK:

		if (((rand() % 100) > 95) && next_event == PASS)
		{
			comment = "an incredible block from " + acting.first_name + " to win the ball back\n";
		}
		return comment;
		break;
	case PASS:
	case CROSS:
	case SHOOT:

		if (last_event == PASS && next_event == GOAL)
		{
			comment = std::string("a lovely pass from " + last_actor.first_name + " to " + acting.first_name + " and he scores a wonderful goal.\n");
		}
		else if (last_event == CROSS && next_event == GOAL)
		{
			comment = std::string("a lovely cross from " + last_actor.first_name + " to " + acting.first_name + " and he scores a wonderful goal.\n");
		}
		else if (last_event == PENALTY && next_event == GOAL)
		{
			comment = acting.first_name + " scores the spot kick!\n";
		}
		else if (last_event == PENALTY && next_event == MISS)
		{
			comment = acting.first_name + " misses the penalty kick!\n";
		}
		else if (last_event == PENALTY && next_event == SAVE)
		{
			comment = "the goalie saves the penalty kick!\n";
		}
		else if (last_event == FREE_KICK && next_event == GOAL)
		{
			comment = acting.first_name + " scores a fabulous freekick,what a goal!\n";
		}
		else if (last_event == FREE_KICK && next_event == MISS)
		{
			comment = acting.first_name + " misses the freekick!\n";
		}
		else if (last_event == FREE_KICK && next_event == CROSS)
		{
			comment = acting.first_name + " swings in the ball\n";
		}
		else if (last_event == FREE_KICK && next_event == PASS)
		{
			comment = acting.first_name + " lofts the ball\n";
		}
		else if (last_event == FREE_KICK && next_event == SAVE)
		{
			comment = "the goalie saves the freekick!\n";
		}
		else if (last_event == SKILL && next_event == GOAL)
		{
			comment = std::string("a lovely piece of skill from " + acting.first_name + " and he scores a wonderful solo goal.\n");
		}
		return comment;
		break;

	case SAVE:
	case SKILL:
	case FOUL:
		if (next_event == PENALTY)
		{
			comment = "oooh " + last_actor.first_name + " commits a foul and concedes a penalty.\n";
		}
		else if (next_event == FREE_KICK)
		{
			comment = last_actor.first_name + " commits a foul and concedes a freekick \n";
		}
		return comment;
		break;
	case YELLOW_CARD:
	case RED_CARD:
	case PENALTY:
		comment = acting.first_name + " to take the penalty\n";
		return comment;
		break;

	case FREE_KICK:
		if (next_event == SHOOT)
		{
			comment = acting.first_name + " to take the freekick in a dangerous position\n";
		}
		else
		{
			comment = "what can " + acting.first_name + " do from this area? \n";
		}
		return comment;
		break;
	case CORNER:
	case MISS:
	case GOAL:
	default:
		return "";
		break;
	}
}
