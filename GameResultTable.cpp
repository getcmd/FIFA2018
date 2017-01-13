#include<stdio.h>
#include <time.h>
#include <stdlib.h>


void GameResultTable(GameResult* game)
{
	short num;
	srand(time(0));
	printf("host:%s\t\t\tguest:%s\n",game->team1.c_nameteam,game.team2.c_nameteam);
	printf("%s\t\t\t%s\n",game->team1.c_nameteam,game.team2.c_nameteam);
	printf("%d\t\t\t%d\n",game->s_team1goals,game.s_team2goals);
	printf("%d\t\t\t%d\n",game->s_team2possesspercent,game.s_team2possesspercent);
	printf("%d\t\t\t%d\n",game->s_team1point,game.s_team2point);
	printf("%d\t\t\t%d\n",game->s_team1numofyellowcards,game.s_team2numofyellowcards);
	printf("%d\t\t\t%d\n",game->s_team1numofredcards,game.s_team2numofredcards);
	//team1 goaler time of goal pass goaler
	for(int i=0;i<game->s_team1goals;i++){
	printf("\n%s\n",game->team1goaldetail[i].c_goaldetail);
	}
	//team1 goaler time of goal pass goaler
	for(int i=0;i<game->s_team2goals;i++){
	printf("\n%s\n",game->team2goaldetail[i].c_goaldetail);
	}
	//a function for cards required
	//changed player function required




}