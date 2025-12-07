#include <stdio.h>

void printStars(int n){
    if(n==0) return;
    putchar('*');
    printStars(n-1);
}

void hourglass(int n,int orig){
    if(n==0) return;
    printStars(n);
    putchar('\n');
    hourglass(n-1,orig);
    if(n!=orig){
        printStars(n);
        putchar('\n');
    }
}

int main(){
    int w=5;
    hourglass(w,w);
    return 0;
}

