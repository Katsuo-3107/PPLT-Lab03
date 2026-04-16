#include <stdio.h>
#include <stdlib.h>

void Convert() {
    int days;
    printf("\nInput how many days: \n");
    scanf("%d",&days);
    printf("\nDays:%d",days);
    printf("\nConvert to Weeks:%d", days / 7);
    printf("\nConvert to Years:%d", days / 365);
}

void Prompting() {
    int a,b;
    printf("Input Integers a & b:\n");
    scanf("%d%d",&a,&b);
    printf("\nAddition:%d ", a + b);
    printf("\nSubtraction:%d ", a - b);
    printf("\nMultiplication:%d ", a * b);
    printf("\nDivision:%d ", a / b);
    printf("\nRemainder:%d ", a % b);
}

void Rectangle() {
    int height,width;
    printf("\nInput Intergers height & width of the rectangle:\n");
    scanf("%d%d",&height,&width);
    printf("\nPerimeter:%d", (height+width)*2);
    printf("\nArea:%d",height*width);
}

void Square()    {
    int height;
    printf("\nInput Intergers height of the square:\n");
    scanf("%d",&height);
    printf("\nPerimeter:%d",height*4);
    printf("\nArea:%d",height*height);
}

void Cel_Fah() {
    float celsius;
    printf("\nInput the Celsius temperature:\n");
    scanf("%f", &celsius);

    float fahrenheit = (celsius * 1.8f) + 32;
    printf("Convert to Fahrenheit: %.2f\n", fahrenheit);
}

void Abs_Num()   {
    int num;
    printf("\nInput the Number:\n");
    scanf("%d", &num);

    printf("\nConvert to absolute value number:%d",abs(num));
}

void Leap_Year() {
    int year;
    printf("\nInput the year:\n");
    scanf("%d", &year);

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))    
    {
        printf("LEAP YEAR !");
    } else    
    {
        printf("NOT leap year !");
    }
}

void Max2()   {
    int a,b;
    printf("\nInput 2 Numbers a & b:\n");
    scanf("%d%d", &a,&b);
    int max = a;

    if (max < b)    
    {
        max = b;
    }

    printf("Max:%d",max);
}

void Max3()  {
    int a,b,c;
    printf("\nInput 3 Numbers a & b & c:\n");
    scanf("%d%d%d", &a, &b, &c);
    int max = a;

    if (max < b)    
    {
        max = b;
    }   
    if (max < c)  
    {
        max = c;
    }
    printf("Max:%d",max);
}

void Check_Even_Odd()    {
    int num;
    printf("\nInput the Number:\n");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
        printf("The number is even !");
    }   else    
    {
        printf("The number is odd !");
    }
}

void Check_Alphanumeric() {
    char a;
    printf("\nInput one letter to check:\n");
    scanf(" %c", &a);

    if ((a >= 48 && a <= 57) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122))
        printf("Alphanumeric !");
    else
        printf("NOT Alphanumeric !");
}


void Check_Triangle_Angle() {
    float a1, a2, a3;
    printf("\nInput 3 angle:\n");
    scanf("%f %f %f", &a1, &a2, &a3);

    if (a1 > 0 && a2 > 0 && a3 > 0 && (a1 + a2 + a3 == 180))
        printf("It is TRIANGLE !");
    else
        printf("It is NOT TRIANGLE !");
}


float Percentage(float diem) {
    float result = (diem / 10.0f) * 100;
    return result;
}

void Mark_Grade(float percentage) {
    if (percentage < 40) {
        printf(" Grade F");
    }
    else if (percentage < 60) {
        printf(" Grade E");
    }
    else if (percentage < 70) {
        printf(" Grade D");
    }
    else if (percentage < 80) {
        printf(" Grade C");
    }
    else if (percentage < 90) {
        printf(" Grade B");
    }
    else {
        printf(" Grade A");
    }
}


void Score() {
    float diem_phy, diem_che, diem_bio, diem_math, diem_com;
    float percent_phy, percent_che, percent_bio, percent_math, percent_com;

    printf("\nInput your Physics score:\n");
    scanf("%f", &diem_phy);

    printf("Input your Chemistry score:\n");
    scanf("%f", &diem_che);

    printf("Input your Biology score:\n");
    scanf("%f", &diem_bio);

    printf("Input your Mathematics score:\n");
    scanf("%f", &diem_math);

    printf("Input your Computer score:\n");
    scanf("%f", &diem_com);

    percent_phy  = Percentage(diem_phy);
    percent_che  = Percentage(diem_che);
    percent_bio  = Percentage(diem_bio);
    percent_math = Percentage(diem_math);
    percent_com  = Percentage(diem_com);

    printf("\n---- Percentage Result ----\n");

    printf("Physics     : %.2f%%", percent_phy);
    Mark_Grade(percent_phy);
    printf("\n");

    printf("Chemistry   : %.2f%%", percent_che);
    Mark_Grade(percent_che);
    printf("\n");

    printf("Biology     : %.2f%%", percent_bio);
    Mark_Grade(percent_bio);
    printf("\n");

    printf("Mathematics : %.2f%%", percent_math);
    Mark_Grade(percent_math);
    printf("\n");

    printf("Computer    : %.2f%%", percent_com);
    Mark_Grade(percent_com);
    printf("\n");
}

int main()  {
    // Exercise 1
    printf("Name: Hoàng Chí Thiện\n");
    printf("Date of Birth: 25//11//2007\n");
    printf("Phone Number: 0855851539\n");
    //
    // Exercise 2
    Prompting();
    //
    // Exercise 3
    Rectangle();
    Square();
    //
    // Exercise 4
    Convert();
    //
    // Exercise 5
    Cel_Fah();
    //
    // Exercise 6
    Abs_Num();
    //
    // Exercise 7  
    Leap_Year();
    //
    // Exercise 8
    Max2();
    //
    // Exercise 9
    Max3();
    //
    // Exercise 10
    Check_Even_Odd();
    //
    // Exercise 11
    Check_Alphanumeric();
    //
    // Execise 12
    Check_Triangle_Angle();
    //
    // Exercise 13
    Score();
    //
    return 0;
}
