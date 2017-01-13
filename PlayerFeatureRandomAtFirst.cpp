#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void PlayerFeaturesRandom(Team team[])
{
	srand(time(0));
	for(int i = 0;i<size;i++)
	{
		for(int e= 0;e<team[i].s_playercount;e++)
		{
			team[i].player[e].s_skill=(rand()%71 ) + 30;
			team[i].player[e].s_form=(rand()%71) + 30;
			team[i].player[e].s_fitness=(rand())%71 + 30;
		}
	}

	for(int i = 0;i<16;i++)
	{
		for(int j =1;i<=team[i].s_playercount;j++)
		{
			team[i].player[j].s_numforprogram=j;
		}
	}
}
