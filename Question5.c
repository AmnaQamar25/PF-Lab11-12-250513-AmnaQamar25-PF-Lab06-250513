#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char str[], int i, int j) {
    if (i >= j) return 1; 
    if (tolower(str[i]) != tolower(str[j])) return 0; 
    return isPalindrome(str,i+1,j-1); 
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    int len = strlen(str);
    if (isPalindrome(str,0,len - 1))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}

