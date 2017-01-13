#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	Team team[16];
	FILE *source = fopen("default.txt", "r");
	if (!source)
	{
		perror("fopen failed");
		return 0;
	}
	TeamInfoGet(source, team);

	return 0;
}
void TeamInfoGet(FILE *source,Team team[size])
{
	char infoget[100];
	for (int i = 0; i < size; i++)
	{
		fgets(infoget, 99, source);
		sscanf(infoget, "%s %d %d %d %d", team[i].c_nameteam, &team[i].s_playercount, &team[i].s_score, &team[i].s_goalsfor, &team[i].s_goalsagainst);
		for (int j = 0; j < team[i].s_playercount; j++)
		{
			fgets(infoget, 99, source);
			sscanf(infoget, "%s %d %d %d %d %d %d %d %d", team[i].player[j].c_nameplayer,
				&team[i].player[j].s_number, &team[i].player[j].s_age, &team[i].player[j].post,
				&team[i].player[j].s_skill, &team[i].player[j].s_fitness, &team[i].player[j].s_form,
				&team[i].player[j].s_goalcount, &team[i].player[j].s_goalpasscount);
		}
	}
}