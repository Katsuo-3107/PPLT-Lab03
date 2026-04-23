#include <stdio.h>

int checkPrime(int n,int i){
    if (n < 2)
        return 0;
    
    if (i * i > n)
        return 1;
    
    if (n % i == 0)
        return 0;
    
    return checkPrime(n, i + 1);
}

int computeFactorial(int n){
    if (n == 0 || n == 1)
    {
        return 1;
    }
    
    return n * computeFactorial(n-1);
}

int computeTwoHeadn(int n){
    
    return 2 ** n;
}

int main()  {   
    int n;
    scanf("%d",&n);
    if (checkPrime(n, 2) == 1)
    {
        printf("Prime");
    }   else
    {
        printf("NOT Prime");
    }

    return 0;
}