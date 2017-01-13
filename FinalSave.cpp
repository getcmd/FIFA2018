#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Save(Team team[])
{
	char savename[20], command[20];
	char *saved;
	int condition, number;
	FILE *savefiles = fopen("savefiles.txt", "r+");//opening saved files names
	fgets(command, 20, savefiles);
	number = Input(command);//number of saved files
	saved = (char*)calloc(number, 20);
	for (int i = 0; i < number; i++)
	{
		fgets(&saved[i * 20], 20, savefiles);
	}
	fclose(savefiles);
	savefiles = NULL;
	while (1)
	{
		printf("give me a name for your saving\n");
		//get name for saving
		fgets(savename, 20, stdin);
		condition = Input(savename);
		while (condition == -100)
		{
			fgets(savename, 20, stdin);
			condition = Input(savename);
		}//not to be a command
		for(int i=0 ; i<number;i++)
		{//check to not to be saved before
			if (!strcmp(savename, &saved[i*20]))
			{
				printf("\nthis saving is available, do you want to rewrite?\n");
				fgets(command, 20, stdin);
				condition = Input(command);
				while (condition != -1 && condition != -2)
				{
					printf("\nwrong input\n");
					fgets(command, 20, stdin);
					condition = Input(command);
				}//check to be a suitable input
				break;
			}
		}
		if (condition == -1)
		{
			break;
			condition = -1000;
		}
		else if (condition == -2) {
			continue;
			condition = -1000;
		}
		savefiles = fopen("savefiles.txt", "w");
		fprintf(savefiles, "%d\n", number+1);
		for (int j = 0; j < number; j++)
		{
			fprintf(savefiles, "%s", &saved[j * 20]);
		}
		fprintf(savefiles, "%s", savename);
		fclose(savefiles);
		savefiles = NULL;
		break;
	}
	savename[strlen(savename)-1] = '\0';
	strcat(savename, ".txt");
	FILE *saving = fopen(savename, "w");
	//starting save process

	for (int i = 0; i < 16; i++) {
		fprintf(saving,"\t\t%s %d %d %d %d\n", team[i].c_nameteam, team[i].s_playercount, team[i].s_score, team[i].s_goalsfor, team[i].s_goalsagainst);
		for (int j = 0; j < team[i].s_playercount; j++) 
		{
			fprintf(saving, "%s %d %d %d %d %d %d %d %d\n", team[i].player[j].c_nameplayer,
				team[i].player[j].s_number, team[i].player[j].s_age, team[i].player[j].post,
				team[i].player[j].s_skill, team[i].player[j].s_fitness, team[i].player[j].s_form,
				team[i].player[j].s_goalcount, team[i].player[j].s_goalpasscount);
		}
	}

	fclose(saving);
}
