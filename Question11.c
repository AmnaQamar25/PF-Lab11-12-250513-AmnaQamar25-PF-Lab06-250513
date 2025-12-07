#include<stdio.h>
#include<stdlib.h>
void input(int *vector,int n,char name[]){
	int i;
	printf("\nEnter nutritional values for %s:\n",name);
		for(i=0;i<n;i++){
		printf("Attribute:%d\n",i+1);
		scanf("%d",&vector[i]);
		}
}
void display(int *vector,int n,char name[]){
	int i;
	printf("nutritional values for %s:\n",name);
	for(i=0;i<n;i++){
		printf("%d ",vector[i]);
		}
		printf("\n");
}
int dotproduct(int *vectorA,int *vectorB,int n){
	int i,p=0;
	for(i=0;i<n;i++){
		printf("%d x %d = %d\n", vectorA[i], vectorB[i], vectorA[i] * vectorB[i]);
		p+=vectorA[i]*vectorB[i];
	}
	return p;
}
void determineSimilarity(int result){
	if (result>50) {
        printf("HIGHLY SIMILAR \n");
        printf("These food items have very similar nutritional profiles.\n");
        printf("Recommendation: Strong match for substitution!\n");
    }
    else if(result >= 20 && result <= 50) {
        printf("MODERATELY SIMILAR \n");
        printf("These food items share some nutritional characteristics.\n");
        printf("Recommendation: Could be alternative options.\n");
    }
    else {
        printf(" LOW SIMILARITY \n");
        printf("These food items have quite different nutritional profiles.\n");
        printf("Recommendation: Consider them as diverse choices.\n");
}
}
int main(){
	int n;
	printf("Enter the number of nutritional attributes: ");
	scanf("%d",&n);
	if(n <= 0) {
        printf("Error: Number of attributes must be positive!\n");
        return 1;
    }
     printf("\nExample attributes: Calories, Protein, Carbohydrates, Fats, etc.\n");
	int *vectorA=(int*)malloc(n*sizeof(int));
	int *vectorB=(int*)malloc(n*sizeof(int));
	int *result=(int*)malloc(1*(sizeof(int)));
		
input(vectorA,n,"Food item 1");
input(vectorB,n,"Food item 2");

display(vectorA,n,"Food item 1");
display(vectorB,n,"Food item 2");

	result[0]=dotproduct(vectorA,vectorB,n);
	printf("\nTotal Dot Product: %d\n", result[0]);
	
	determineSimilarity(result[0]);
	free(vectorA);
	free(vectorB);
    free(result);
    printf("Thank you for using the Food Recommendation System!\n");
    
	return 0;
}
