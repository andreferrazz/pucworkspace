#include <stdio.h>
#include <stdbool.h> 

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    int original = x; 
    long reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x = x / 10;
    }

    return original == reversed;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPalindrome(n)) {
        printf("É palindromo.\n");
    } else {
        printf("Nao é palindromo.\n");
    }

    return 0;
}

