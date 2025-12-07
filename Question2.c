#include<stdio.h>
#include<stdlib.h>
typedef struct time{
	int hour;
	int minute;
	int sec;
}time;
int main(){
	int sumh=0,summ=0,sums=0,i;
time *t=(time*)malloc(2*(sizeof(time)));
for(i=0;i<2;i++){
	printf("Enter the hour of time %d: ",i+1);
	scanf(" %d",&t[i].hour);
	printf("Enter the minutes of time %d: ",i+1);
	scanf("%d",&t[i].minute);
	printf("Enter the seconds of time %d: ",i+1);
	scanf("%d",&t[i].sec);
}
for(i=0;i<2;i++){
	sumh+=t[i].hour;
	summ+=t[i].minute;
	sums+=t[i].sec;
}
do{
	if(sums>60){
	sums-=60;
	summ++;
}
}while(sums>60);
do{
	if(summ>60){
	summ-=60;
	sumh=sumh+1;
}
}while(summ>60);
printf("Sum of all times is: %d:%d:%d",sumh,summ,sums);
free(t);	
return 0;
}
