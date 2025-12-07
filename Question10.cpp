#include <stdio.h>
#include <stdlib.h>

struct availabilityInfo{
	int copiesAvail;
	int totalCopies;
};

struct publicationInfo{
	char publisher[30];
	int year;
};

struct Book{
	int id;
	char title[50];
	char author[30];
	struct publicationInfo p;
	struct availabilityInfo a;
};

void inputBook(struct Book *b);
void displayBook(struct Book *b);
void updateCopies(struct Book *b,int newCopies);
void findBookByID(struct Book *b,int id);

int main(){
	
	int n,i,select,id,newCopies,flag1,flag2;
	printf("How many books to want to add? ");
	scanf("%d",&n);
	struct Book *b = (struct Book*) malloc(n * sizeof(struct Book));
    if(b == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
	for(i=0;i<n;i++){
		printf("For Book %d\n",i+1);
		inputBook(&b[i]);
	}
	do{
	printf("\n(1)View all books\n(2)Update Copies of a specific book\n(3)Find book by ID\n(4)Exit\n\nSelect any one: ");
	scanf("%d",&select);
	switch(select){
		case 1:
			for(i=0;i<n;i++){
				printf("\nBook: %d\n",i+1);
				displayBook(&b[i]);
			}
			break;
		case 2:
			flag1=0;
			printf("Enter number of new copies: ");
			scanf("%d",&newCopies);
			printf("\nEnter ID of Book of which you want to update copies: ");
			scanf("%d",&id);
			for(i=0;i<n;i++){
				if(b[i].id==id){
					updateCopies(&b[i],newCopies);
					flag1=1;
				}
			}
			if(flag1==0)	printf("\nInvalid ID!\n");
			break;
		case 3:
			flag2=0;
			printf("Enter ID of Book which you want to search: ");
			scanf("%d",&id);
			for(i=0;i<n;i++){
				if(b[i].id==id){
					findBookByID(&b[i],id);
					flag2=1;
				}
			}
			if(flag2==0)	printf("\nInvalid ID!\n");
			break;
		case 4:
			printf("Exiting..");
			break;
		default :
			printf("\nInvalid selection!\n");
			break;						
	}
}while(select!=4);
	free(b);
	return 0;
}

void inputBook(struct Book *b){
	
		printf("Enter ID: ");
		scanf("%d",&b->id);
		printf("Enter Title: ");
		scanf(" %[^\n]",b->title);
		printf("Enter Author: ");
		scanf(" %[^\n]",b->author);
		printf("Enter Publisher: ");
		scanf(" %[^\n]",b->p.publisher);
		printf("Enter Year: ");
		scanf("%d",&b->p.year);
		printf("Enter Available copies of book: ");
		scanf("%d",&b->a.copiesAvail);
		printf("Enter Total Copies: ");
		scanf("%d",&b->a.totalCopies);
	
}

void displayBook(struct Book *b){
	
		printf("ID: %d\t",b->id);
		printf("Title: %s\t",b->title);
		printf("Author: %s\t",b->author);
		printf("Publisher: %s\t",b->p.publisher);
		printf("Year: %d\t",b->p.year);
		printf("Copies Available: %d\t",b->a.copiesAvail);
		printf("Total Copies: %d\t\n",b->a.totalCopies);
	
}

void updateCopies(struct Book *b,int newCopies){
	
			b->a.copiesAvail += newCopies;		

}

void findBookByID(struct Book *b,int id){
	
	if(b->id==id){
		printf("\nDetails of Book having ID %d\n",id);
		printf("Title: %s\t",b->title);
		printf("Author: %s\t",b->author);
		printf("Publisher: %s\t",b->p.publisher);
		printf("Year: %d\t",b->p.year);
		printf("Copies Available: %d\t",b->a.copiesAvail);
		printf("Total Copies: %d\t\n",b->a.totalCopies);
	}
}
