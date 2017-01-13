#include <stdio.h>
#include <stdlib.h>

void SortTable(Team team[16])
{
	for(int i = 1;i<=16;i++)
	{
		team[i].s_numforprogram=i;
	}
	for(int i = 0;i<16;i++)
	{
		for(int j=i;j<15;j++)
		{
			if(team[j].s_score>team[j+1].s_score)
			{
				short tmp = team[j].s_numforprogram;
				team[j].s_numforprogram=team[j+1].s_numforprogram;
				team[j+1].s_numforprogram=tmp;
			}
			else if(team[j].s_score==team[j+1].s_score)
			{
				if(team[j].s_goaldiffrence==team[j+1].s_score)
				{
					short tmp = team[j].s_numforprogram;
					team[j].s_numforprogram=team[j+1].s_numforprogram;
					team[j+1].s_numforprogram=tmp;
				}
			}
		}
	}
}