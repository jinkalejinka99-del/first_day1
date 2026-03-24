#include<stdio.h>
#include<stdlib.h>
typedef struct{
char*day;
int dt;
char*desc;
}date;
void create();
date*calender;
void read();
void display();
void main()
{
printf("***creating***\n");
create();
printf("***Reading***\n");
read();
printf("***Display***\n");
display();
}
void create()
{
calender=(date*)malloc(sizeof(date)*7);
}
void read()
{
int i;
for(i=0;i<7;i++)
{
printf("enter the day  of the week\n");
calender[i].day=(char*)malloc(sizeof(char)*100);
scanf("%s",calender[i].day);
printf("enter the date\n");
scanf("%d",&calender[i].dt);
printf("enter the discription\n");
calender[i].desc=(char*)malloc(sizeof(char)*100);
scanf("%s",calender[i].desc);
}
}
void display()
{
int i;
printf("Day\t\tDate\tDescription\n");
for(i=0;i<7;i++)
printf("%s\t\t%d\t%s\n",calender[i].day,calender[i].dt,calender[i].desc);
}
