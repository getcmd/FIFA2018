#include <stdio.h>
typedef struct {
	short day;
	short month;
	short year;
	short time;
}Date;
void datePlus(Date* date, int n, int x)
{
	date[n].day = date[n - 1].day + x;
	date[n].month = date[n - 1].month;
	date[n].year = date[n - 1].year;
	if (date[n].month < 7)
	{
		if (date[n].day > 31) {
			date[n].day -= 31;
			date[n].month++;
		}
	}
	else if (date[n].month < 12)
	{
		if (date[n].day > 30) {
			date[n].day -= 30;
			date[n].month++;
		}
	}
	else {
		if (date[n].day > 29) {
			date[n].day -= 29;
			date[n].month = 1;
			date[n].year++;
		}
	}
}
void date()
{
	Date date[240];
	date[0].day = 26;
	date[0].month = 6;
	date[0].year = 1395;
	date[0].time = 16;
	for (int i = 0; i < 30; i++)
	{
		if (i != 0)
		{
			datePlus(date, i * 8, 6);
		}
		date[i * 8].time = 16;
		for (int j = 1; j < 4; j++) {
			datePlus(date, (i * 8 + j), 0);
			date[i * 8 + j].time = 16 + j / 2;
		}
		datePlus(date, i * 8 + 4, 1);
		date[i * 8 + 4].time = 16;
		for (int j = 5; j < 8; j++) {
			datePlus(date, (i * 8 + j), 0);
			date[i * 8 + j].time = 16 + (j-4) / 2;
		}
	}
}