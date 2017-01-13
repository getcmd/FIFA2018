#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GoalerAndPassesRand (GameResult* game){
	short s_numforgoaler , s_numforpassgoaler,s_chanceofgoalerposts;
	for(int i = 0;i<game->s_team1goals;i++)
		{
			s_chanceofgoalerposts=rand()%30;//0-14 a forward goals 15-24 a midfielder goals 25-28 a defender goals 29 the goalkeeper goals
			if(s_chanceofgoalerposts>=0&&s_chanceofgoalerposts<=14){
				while(1){
					s_numforgoaler = rand()%game->team1.s_playercount;
					if(game->team1.player[s_numforgoaler].post==Forward)
					{
						game->team1.player[s_numforgoaler].s_goalcount++;
						break;
					}
				}
			}
			else if(s_chanceofgoalerposts>=15&&s_chanceofgoalerposts<=24){
				while(1){
					s_numforgoaler = rand()%game->team1.s_playercount;
					if(game->team1.player[s_numforgoaler].post==Midfielder)
					{
						game->team1.player[s_numforgoaler].s_goalcount++;
						break;
					}
				}
			}
			else if(s_chanceofgoalerposts>=25&&s_chanceofgoalerposts<=28){
				while(1){
					s_numforgoaler = rand()%game->team1.s_playercount;
					if(game->team1.player[s_numforgoaler].post==Defender)
					{
						game->team1.player[s_numforgoaler].s_goalcount++;
						break;
					}
				}
			}
			else
			{
					s_numforgoaler = rand()%game->team1.s_playercount;
						game->team1.player[s_numforgoaler].s_goalcount++;
			}
		
			while(1)
			{
				s_numforpassgoaler= rand()%game.team1.s_playercount;
				if(s_numforpassgoaler!=s_numforgoaler && game->team1.player[s_numforpassgoaler].post!=Goalkeeper)
				{
					game->team1.player[s_numforpassgoaler].s_goalpasscount++;
					break;
				}
			}
			sprintf(game->team1goaldetail[i].c_goaldetail,"%s\t\t%d:%d\t\ton pass from: %s\n",game->team1.player[s_numforgoaler].c_nameplayer,rand()%90,rand()%60,game->team1.player[s_numforpassgoaler].c_nameplayer);//player name minute nad second of goal random//team2
	}
for(int i = 0;i<game->s_team2goals;i++)
		{
			s_chanceofgoalerposts=rand()%30;
			if(s_chanceofgoalerposts>=0&&s_chanceofgoalerposts<=14){
				while(1){
					s_numforgoaler = rand()%game->team2.s_playercount;
					if(game->team2.player[s_numforgoaler].post==Forward)
					{
						game->team2.player[s_numforgoaler].s_goalcount++;
						break;
					}
				}
			}
			else if(s_chanceofgoalerposts>=15&&s_chanceofgoalerposts<=24){
				while(1){
					s_numforgoaler = rand()%game->team2.s_playercount;
					if(game->team2.player[s_numforgoaler].post==Midfielder)
					{
						game->team2.player[s_numforgoaler].s_goalcount++;
						break;
					}
				}
			}
			else if(s_chanceofgoalerposts>=25&&s_chanceofgoalerposts<=28){
				while(1){
					s_numforgoaler = rand()%game->team2.s_playercount;
					if(game->team2.player[s_numforgoaler].post==Defender)
					{
						game->team2.player[s_numforgoaler].s_goalcount++;
						break;
					}
				}
			}
			else
			{
					s_numforgoaler = rand()%game->team2.s_playercount;
						game->team2.player[s_numforgoaler].s_goalcount++;
			}
		
			while(1)
			{
				s_numforpassgoaler= rand()%game.team2.s_playercount;
				if(s_numforpassgoaler!=s_numforgoaler && game->team2.player[s_numforpassgoaler].post!=Goalkeeper)
				{
					game->team2.player[s_numforpassgoaler].s_goalpasscount++;
					break;
				}
			}
			sprintf(game->team2goaldetail[i].c_goaldetail,"%s\t\t%d:%d\t\ton pass from: %s\n",game->team2.player[s_numforgoaler].c_nameplayer,rand()%90,rand()%60,game->team2.player[s_numforpassgoaler].c_nameplayer);//player name minute nad second of goal random//team2
	
}
