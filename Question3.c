#include <stdio.h>

struct Book{
	char title[50];
	char author[100];
	int price;
};

int main(){
	
	struct Book b[3];
	int i,max=0,a;
	for(i=0;i<3;i++){
		printf("Enter title of %d book: ",i+1);
		scanf(" %[^\n]",b[i].title);
		printf("Enter author of %d book: ",i+1);
		scanf(" %[^\n]",b[i].author);
		printf("Enter price of %d book: ",i+1);
		scanf(" %d",&b[i].price);
	}
	for(i=0;i<3;i++){
		if(max<b[i].price){
			max=b[i].price;
			a=i;
		}
	}
	printf("\nDetails of Most Expensive Book\n");
	printf("Title: %s\n",b[a].title);
	printf("Author: %s\n",b[a].author);
	printf("Price: %d\n",b[a].price);
	a=0;
	int min=b[0].price;
	for(i=0;i<3;i++){
		if(min>b[i].price){
			min=b[i].price;
			a=i;
		}
	}
	printf("\nDetails of lowest priced Book\n");
	printf("Title: %s\n",b[a].title);
	printf("Author: %s\n",b[a].author);
	printf("Price: %d\n",b[a].price);
	
	return 0;
}
