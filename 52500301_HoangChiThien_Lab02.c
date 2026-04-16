#include <stdio.h>

void sumEven() {
	int n, i, sum = 0;

	do {
		printf("Enter n (n > 0): ");
		scanf("%d", &n);
	} while (n <= 0);

	// for
	sum = 0;
	for (i = 1; i <= n; i++)
		if (i % 2 == 0) sum += i;
	printf("For loop sum even = %d\n", sum);

	// while
	i = 1;
	sum = 0;
	while (i <= n) {
		if (i % 2 == 0) sum += i;
		i++;
	}
	printf("While loop sum even = %d\n", sum);

	// do while
	i = 1;
	sum = 0;
	do {
		if (i % 2 == 0) sum += i;
		i++;
	} while (i <= n);
	printf("Do-while sum even = %d\n", sum);
}

void sumOdd() {
	int n, i, sum = 0;

	do {
		printf("Enter n (n > 0): ");
		scanf("%d", &n);
	} while (n <= 0);

	for (i = 1; i <= n; i++)
		if (i % 2 != 0) sum += i;

	printf("Sum odd = %d\n", sum);
}

void table() {
	int n, i;
	printf("Enter number: ");
	scanf("%d", &n);

	for (i = 1; i <= 10; i++)
		printf("%d x %d = %d\n", n, i, n * i);
}

void sumNatural() {
	int n, i, sum = 0;

	do {
		printf("Enter n (n > 0): ");
		scanf("%d", &n);
	} while (n <= 0);

	for (i = 1; i <= n; i++)
		sum += i;

	printf("Sum = %d\n", sum);
}

void firstLastDigit() {
	int n, first, last;
	printf("Enter number: ");
	scanf("%d", &n);

	last = n % 10;
	while (n >= 10)
		n /= 10;
	first = n;

	printf("First = %d, Last = %d\n", first, last);
}

void sumDigits() {
	int n, sum = 0;
	printf("Enter number: ");
	scanf("%d", &n);

	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	printf("Sum of digits = %d\n", sum);
}

void productDigits() {
	int n, pro = 1;
	printf("Enter number: ");
	scanf("%d", &n);

	while (n > 0) {
		pro *= n % 10;
		n /= 10;
	}
	printf("Product of digits = %d\n", pro);
}

void countDigits() {
	int n, count = 0;
	printf("Enter number: ");
	scanf("%d", &n);

	do {
		count++;
		n /= 10;
	} while (n != 0);

	printf("Digits = %d\n", count);
}

void swapFirstLast() {
    int n, temp, first, last, div = 1;
    printf("Enter number: ");
    scanf("%d", &n);

    temp = n;
    last = n % 10;

    while (temp >= 10) {
        temp /= 10;
        div *= 10;
    }
    first = temp;

    n = n % div;
    n = n / 10;
    printf("Result = %d\n", last * div + n * 10 + first);
}

void reverseNum() {
    int n, rev = 0;
    printf("Enter number: ");
    scanf("%d", &n);

    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    printf("Reverse = %d\n", rev);
}

void palindrome() {
    int n, temp, rev = 0;
    printf("Enter number: ");
    scanf("%d", &n);

    temp = n;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    if (temp == rev)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
}

void primeCheck() {
    int n, i, flag = 1;

    do {
        printf("Enter n (>1): ");
        scanf("%d", &n);
    } while (n <= 1);

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }

    if (flag) printf("Prime\n");
    else printf("Not Prime\n");
}

void armstrong() {
    int n, temp, sum = 0, r;
    printf("Enter number: ");
    scanf("%d", &n);

    temp = n;
    while (n > 0) {
        r = n % 10;
        sum += r * r * r;
        n /= 10;
    }

    if (sum == temp) printf("Armstrong\n");
    else printf("Not Armstrong\n");
}

void perfect() {
    int n, i, sum = 0;
    printf("Enter number: ");
    scanf("%d", &n);

    for (i = 1; i < n; i++)
        if (n % i == 0) sum += i;

    if (sum == n) printf("Perfect\n");
    else printf("Not Perfect\n");
}

void primeList() {
    int n, i, j, flag;

    do {
        printf("Enter n (>1): ");
        scanf("%d", &n);
    } while (n <= 1);

    for (i = 2; i <= n; i++) {
        flag = 1;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) printf("%d ", i);
    }
    printf("\n");
}

void armstrongList() {
    int n, i, temp, sum, r;

    do {
        printf("Enter n (>0): ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Armstrong numbers: ");
    for (i = 1; i <= n; i++) {
        temp = i;
        sum = 0;

        while (temp > 0) {
            r = temp % 10;
            sum += r * r * r;
            temp /= 10;
        }

        if (sum == i)
            printf("%d ", i);
    }
    printf("\n");
}

void perfectList() {
    int n, i, j, sum;

    do {
        printf("Enter n (>0): ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Perfect numbers: ");
    for (i = 1; i <= n; i++) {
        sum = 0;

        for (j = 1; j < i; j++) {
            if (i % j == 0)
                sum += j;
        }

        if (sum == i)
            printf("%d ", i);
    }
    printf("\n");
}

void decToBin() {
    int n, bin = 0, place = 1;
    printf("Enter decimal: ");
    scanf("%d", &n);

    while (n > 0) {
        bin += (n % 2) * place;
        place *= 10;
        n /= 2;
    }
    printf("Binary = %d\n", bin);
}

void factorial() {
    int n, i;
    long long f = 1;

    do {
        printf("Enter n (>=0): ");
        scanf("%d", &n);
    } while (n < 0);

    for (i = 1; i <= n; i++)
        f *= i;

    printf("Factorial = %lld\n", f);
}

int main() {

    printf("\n===== EXERCISE 1 =====\n");
    sumEven();

    printf("\n===== EXERCISE 2 =====\n");
    sumOdd();

    printf("\n===== EXERCISE 3 =====\n");
    table();

    printf("\n===== EXERCISE 4 =====\n");
    sumNatural();

    printf("\n===== EXERCISE 5 =====\n");
    firstLastDigit();

    printf("\n===== EXERCISE 6 =====\n");
    sumDigits();

    printf("\n===== EXERCISE 7 =====\n");
    productDigits();

    printf("\n===== EXERCISE 8 =====\n");
    countDigits();

    printf("\n===== EXERCISE 9 =====\n");
    swapFirstLast();

    printf("\n===== EXERCISE 10 =====\n");
    reverseNum();

    printf("\n===== EXERCISE 11 =====\n");
    palindrome();

    printf("\n===== EXERCISE 12 =====\n");
    primeCheck();

    printf("\n===== EXERCISE 13 =====\n");
    armstrong();

    printf("\n===== EXERCISE 14 =====\n");
    perfect();

    printf("\n===== EXERCISE 15 =====\n");
    primeList();

    printf("\n===== EXERCISE 16 =====\n");
    armstrongList();

    printf("\n===== EXERCISE 17 =====\n");
    perfectList();

    printf("\n===== EXERCISE 18 =====\n");
    decToBin();

    printf("\n===== EXERCISE 19 =====\n");
    factorial();

    printf("\n===== END OF PROGRAM =====\n");

    return 0;
}