#include <stdio.h>
#include <math.h>

int sumEven()
{
    int sum = 0, n = 0;
    int i;

    do {
    printf("--------Caculate sum of all even numbers from 1 to n--------\n");
    printf("Enter n (n > 0): ");
    scanf("%d", &n);
    } while (n <= 0);
        
    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
        
    }
    printf("Sum Even = %d\n", sum);
    return sum;
}

int sumOdd()
{
    int sum = 0, n = 0;
    int i;

    do {
    printf("--------Caculate sum of all odd numbers from 1 to n--------\n");
    printf("Enter n (n > 0): ");
    scanf("%d", &n);
    } while (n <= 0);
        
    for (i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            sum += i;
        }
        
    }
    printf("Sum Odd = %d\n", sum);
    return sum;
}

void tableNumbers()
{
    int n = 0;
    int i;

    printf("--------Print multiplication table of any number--------\n");
    printf("Enter number: ");
    scanf("%d", &n);

    for (i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

int sumNatural()
{
    int sum = 0, n = 0, readStatus = 0;
    int i;
    char ch;

    do
    {
        printf("--------Caculate sum of all natural numbers from 1 to n--------\n");
        printf("Enter n (n > 0): ");
        readStatus = scanf("%d", &n);

        while ((ch = getchar()) != '\n')
        {
        }

        if (readStatus != 1 || n <= 0)
        {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (readStatus != 1 || n <= 0);
        
    for (i = 1; i <= n; i++)
    {
        sum += i;
    }
    printf("Sum Natural = %d\n", sum);
    return sum;
}

int main()
{
    sumEven();
    sumOdd();
    tableNumbers();
    sumNatural();
    return 0;
}
