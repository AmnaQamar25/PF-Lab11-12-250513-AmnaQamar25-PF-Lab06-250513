#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void getChoiceName(int choice,char name[]){
	if(choice==1){
		strcpy(name,"rock");
	}
	else if(choice==2){
		strcpy(name,"paper");
	}
	else strcpy(name, "Scissors");
}
int determineWinner(int user,int comp){
	if(user == comp) return 0;
	if((user==1 && comp==3)||(user==2 && comp==1)||(user==3 &&comp==2)){
		return 1;
	}
	return -1;
	
	
}
void play(int round,int totround,int user,int comp){
	if(round>totround){
		
        printf("\n=== GAME OVER ===\n");
        printf("Final Score:\n");
        printf("You: %d | Computer: %d\n", user, comp);
        
        if(user > comp) {
            printf("**YOU WIN THE GAME!**\n");
        } else if(comp > user) {
            printf("**COMPUTER WINS THE GAME!**\n");
        } else {
            printf("**IT'S A TIE!**\n");
        }
        return;
	}
	
	printf("\n--round %d of total rounds %d: \n",round,totround);
	printf("Current Score - You: %d | Computer: %d\n", user, comp);
    
    int userChoice;
    printf("\nEnter your choice:\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("Your choice: ");
    scanf("%d", &userChoice);
    
   
    if(userChoice < 1 || userChoice > 3) {
        printf("Invalid choice! Please enter 1, 2, or 3.\n");
        play(round, totround, user, comp);  
        return;
    }
    int compChoice = rand() % 3 + 1;
    char userChoiceName[20];
    char compChoiceName[20];
    getChoiceName(userChoice, userChoiceName);
    getChoiceName(compChoice, compChoiceName);
    
    printf("\nYou chose: %s\n", userChoiceName);
    printf("Computer chose: %s\n", compChoiceName);

    int result = determineWinner(userChoice, compChoice);
    if(result == 1) {
        printf("You win this round!\n");
        play(round + 1, totround, user + 1, comp);
    } else if(result == -1) {
        printf("Computer wins this round!\n");
        play(round + 1, totround, user, comp + 1);
    } else {
        printf("It's a draw!\n");
        play(round + 1, totround, user, comp);
    }
    
}

int main(){
	int totround;
	srand(time(0));
	 printf("=== ROCK PAPER SCISSORS ===\n");
    printf("Enter number of rounds: ");
    scanf("%d", &totround);
    
    if(totround <= 0) {
        printf("Invalid number of rounds!\n");
        return 1;
    }
    play(1, totround, 0, 0);
    
	
	return 0;
}
