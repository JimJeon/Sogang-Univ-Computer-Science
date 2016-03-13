#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum Date {Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};

enum Date getDate(int y,int m,int d);
char* getDay(enum Date currDate);

int main(void)
{
	struct Calendar
	{
		int year, month, day;
		enum Date date;
		char *dateString;
	} DateData;

	printf("Year : ");
	scanf("%d",&DateData.year);
	printf("Month : ");
	scanf("%d",&DateData.month);
	printf("Day : ");
	scanf("%d",&DateData.day);

	DateData.date = getDate(DateData.year,DateData.month,DateData.day);

	DateData.dateString = getDay(DateData.date);

	printf("dataString : %s\n",DateData.dateString);
	return 0;
}
enum Date getDate(int y,int m,int d)
{
	return (y + y/4 - y/100 + y/400 + (13*m + 8)/5 + d) % 7;
}
char* getDay(enum Date currDate)
{
	char *str = (char*)malloc(10*sizeof(char));

	switch(currDate)
	{
		case 0:
			strcpy(str,"Sunday");
			break;
		case 1:
			strcpy(str,"Monday");
			break;
		case 2:
			strcpy(str,"Tuesday");
			break;
		case 3:
			strcpy(str,"Wednesday");
			break;
		case 4:
			strcpy(str,"Thursday");
			break;
		case 5:
			strcpy(str,"Friday");
			break;
		case 6:
			strcpy(str,"Saturday");
			break;
	}
	return str;
}
