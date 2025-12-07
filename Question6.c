#include <stdio.h>

void menu();
void add();
void sub();

void menu(){
    
    int select;
    printf("(1)Addition\n(2)Subtraction\n(3)Exit\nSelect any one: ");
    scanf("%d",&select);
    switch(select){
        case 1:
            add();
            menu();
            break;
        case 2:
            sub();
            menu();
            break;
        case 3:    
            printf("Exit");
            break;
        default :
            printf("\nInvalid selection!\n");
            menu();
            break;
    }
}

void add(){
    
    int a,b,sum;
    printf("Enter value of a: ");
    scanf("%d",&a);
    printf("Enter value of b: ");
    scanf("%d",&b);
    sum=a+b;
    printf("Sum of a and b is %d\n\n",sum);
    
}

void sub(){
    
    
    int a,b,diff;
    printf("Enter value of a: ");
    scanf("%d",&a);
    printf("Enter value of b: ");
    scanf("%d",&b);
    diff=a-b;
    printf("Difference of a and b is %d\n\n",diff);
    
}

int main(){

    menu();
    
    return 0;
}

