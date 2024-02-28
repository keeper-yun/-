#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    int i;

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


void guess(int x) {

    int i;
    for(i=2;i<x/2;i++){
        if(isPrime(i) && isPrime(x-i)){
            printf("%d\n",i);
            printf("%d\n",x-i);
            break;
        }
    }
}


int main() {
    int n;

    scanf("%d",&n);
    if (n <= 2 || n % 2 != 0) {
        printf("0");    
    }
    else{
        guess(n);
    }
}