#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessNumber(int secret,int *attempts){
    
    int guess;
    printf("Guess the random generated number: \n");
    scanf("%d",&guess);
    (*attempts)++;
    if(guess==secret) return;
    if(guess<secret) printf("Too Low!\n");
    if(guess>secret) printf("Too High!\n");
    guessNumber(secret,attempts);
}

int main() {
    
    srand(time(0));
    int secret = (rand() % 50) + 1;
    int attempts=0;
    guessNumber(secret,&attempts);
    printf("Correct guess!\n");
    printf("Number of attempts: %d",attempts);

    return 0;
}

