#include<stdio.h>
#include<stdlib.h>
struct customer{
	char name[30];
	char city[30];
	int phone;	
};
struct product{
	char name[30];
	int  price; 
	int quantity;
};
struct order{
struct customer c;
struct product p;
int total;
};
void input(struct order *od,int n){
		int i;
		for(i=0;i<n;i++){
		printf("\nEnter order %d:\n",i+1);
		printf("Enter customer name:");
		scanf(" %[^\n]",od[i].c.name);
    	printf("Enter city name:");
		scanf(" %[^\n]",od[i].c.city);
		printf("Enter phone number:");
		scanf( " %d",&od[i].c.phone);
		printf("Enter product name:");
		scanf(" %[^\n]",od[i].p.name);
		printf("Enter price:");
		scanf(" %d",&od[i].p.price);
		printf("Enter quantity:");
		scanf(" %d",&od[i].p.quantity);
		}
}
void calculate(struct order *od,int n){
		int i;
		for(i=0;i<n;i++){
			od[i].total=od[i].p.price*od[i].p.quantity;
		}	
}
void display(struct order *od,int n){
		
		int i;
		for(i=0;i<n;i++){
		printf("\nOrder %d:\n",i+1);
		printf("customer name: %s\n",od[i].c.name);
    	printf(" city name: %s\n",od[i].c.city);
		printf(" phone number: %d\n",od[i].c.phone);
		printf(" product name: %s\n",od[i].p.name);
		printf(" price: %d\n",od[i].p.price);
		printf(" quantity:%d\n",od[i].p.quantity);
		printf(" Total: %d\n",od[i].total);
		}
}
int main(){
	int n;
	printf("Enter number of orders: ");
	scanf("%d",&n);
	struct order *od=(struct order*)malloc(n*sizeof(struct order));
	input(od,n);
	calculate(od,n);
	display(od,n);
	return 0;
}
