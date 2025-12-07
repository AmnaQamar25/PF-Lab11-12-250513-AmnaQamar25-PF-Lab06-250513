#include <stdio.h>

struct Student{
	char name[50];
	int age;
	int totalMarks;
};

int main(){
	
	int i,avg;
	struct Student S[2];
	for(i=0;i<2;i++){
		printf("Enter name of %d student ",i+1);
		scanf(" %[^\n]",S[i].name);
		printf("Enter age of %d student ",i+1);
		scanf(" %d",&S[i].age);
		printf("Enter total marks of %d student ",i+1);
		scanf(" %d",&S[i].totalMarks);
	}
	for(i=0;i<2;i++){
		printf("\n\nStudent %d\n",i+1);
		printf("Name: %s\n",S[i].name);
		printf("Age: %d\n",S[i].age);
		printf("Total Marks:  %d\n",S[i].totalMarks);
	}
	avg=(S[0].totalMarks+S[1].totalMarks)/2;
	printf("\nAverage of total marks of students is: %d",avg);
	
	
	return 0;
}
