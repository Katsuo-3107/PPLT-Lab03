#include <stdio.h>
#include <math.h>

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
    if (n == 0) {
        return 1;
    }
    return 2 * computeTwoHeadn(n - 1);
}

int computeXHeadn(int x, int n){
    if (n == 0) {
        return 1;
    }
    return x * computeXHeadn(x, n - 1);
}

int returnNumberOfDigitsOfPositiveInteger(int n){
    if (n == 0) {
        return 0;
    }
    return 1 + returnNumberOfDigitsOfPositiveInteger(n / 10);
}

int sumTwoIPlusOne(int n) {
    if (n == 0) {
        return 0;
    }
    return (2 * n + 1) + sumTwoIPlusOne(n - 1);
}

double sumIDivideTwo(int n) {
    if (n == 0) {
        return 0;
    }
    return (double)n / 2 + sumIDivideTwo(n - 1);
}

int sumFactorial(int n) {
    if (n == 0) {
        return 0;
    }
    return computeFactorial(n) + sumFactorial(n - 1);
}

double sumSqrtI(int n) {
    if (n == 0) {
        return 0;
    }
    return sqrt(n) + sumSqrtI(n - 1);
}

long long productFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return (long long)computeFactorial(n) * productFactorial(n - 1);
}


int main()  {   
    int n;
    printf("Add n: ");
    scanf("%d",&n);
    if (checkPrime(n, 2) == 1)
    {
        printf("CheckPrime: Prime\n");
    }   else
    {
        printf("CheckPrime: NOT Prime\n");
    }
    printf("ComputeFactorial: %d\n", computeFactorial(n));
    printf("ComputeTwoHeadn: %d\n", computeTwoHeadn(n));
    int x;
    printf("Add x: ");
    scanf("%d",&x);
    printf("ComputeXHeadn: %d\n", computeXHeadn(x, n));
    printf("ReturnNumberOfDigitsOfPositiveInteger: %d\n", returnNumberOfDigitsOfPositiveInteger(n));
    printf("SumTwoIPlusOne: %d\n", sumTwoIPlusOne(n));
    printf("SumIDivideTwo: %.2lf\n", sumIDivideTwo(n));
    printf("SumFactorial: %d\n", sumFactorial(n));
    printf("SumSqrtI: %.2lf\n", sumSqrtI(n));
    printf("ProductFactorial: %lld\n", productFactorial(n));
    return 0;
}
