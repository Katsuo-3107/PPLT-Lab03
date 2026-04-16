#include <stdio.h>
#include <math.h>

long long factorial(int n){
    long long f=1;
    for(int i=1;i<=n;i++) f*=i;
    return f;
}

double sum_a(int n){
    double S=0;
    for(int i=1;i<=n;i++) S += (double)i/2;
    return S;
}

int sum_b(int n){
    int S=0;
    for(int i=1;i<=n;i++) S += (2*i+1);
    return S;
}

long long sum_c(int n){
    long long S=0;
    for(int i=1;i<=n;i++) S += factorial(i)+1;
    return S;
}

long long product_d(int n){
    long long P=1;
    for(int i=1;i<=n;i++) P *= factorial(i);
    return P;
}

double product_e(int n){
    double P=1;
    for(int i=1;i<=n;i++) P *= (double)(2*i)/3;
    return P;
}

void inputArray(int a[], int n){
    for(int i=0;i<n;i++){
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }
}

void printArray(int a[], int n){
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}

int findMax(int a[], int n){
    int max=a[0];
    for(int i=1;i<n;i++) if(a[i]>max) max=a[i];
    return max;
}

int findMin(int a[], int n){
    int min=a[0];
    for(int i=1;i<n;i++) if(a[i]<min) min=a[i];
    return min;
}

int sumArray(int a[], int n){
    int S=0;
    for(int i=0;i<n;i++) S+=a[i];
    return S;
}

int sumNonPositive(int a[], int n){
    int S=0;
    for(int i=0;i<n;i++) if(a[i]<=0) S+=a[i];
    return S;
}

int sumEven(int a[], int n){
    int S=0;
    for(int i=0;i<n;i++) if(a[i]%2==0) S+=a[i];
    return S;
}

void reverseArray(int a[], int n){
    for(int i=0;i<n/2;i++){
        int t=a[i]; a[i]=a[n-1-i]; a[n-1-i]=t;
    }
}

void deletePos(int a[], int *n, int k){
    for(int i=k;i<*n-1;i++) a[i]=a[i+1];
    (*n)--;
}

int countDuplicates(int a[], int n){
    int count=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]==a[j]){ count++; break; }
    return count;
}

void deleteDuplicates(int a[], int *n){
    for(int i=0;i<*n;i++)
        for(int j=i+1;j<*n;j++)
            if(a[i]==a[j]){
                deletePos(a,n,j);
                j--;
            }
}

int search(int a[], int n, int key){
    for(int i=0;i<n;i++) if(a[i]==key) return i;
    return -1;
}

void sortAsc(int a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j]){
                int t=a[i]; a[i]=a[j]; a[j]=t;
            }
}

void inputMatrix(int A[][50], int r,int c){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            printf("A[%d][%d]=",i,j);
            scanf("%d",&A[i][j]);
        }
}

void printMatrix(int A[][50], int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++) printf("%4d",A[i][j]);
        printf("\n");
    }
}

void addMatrix(int A[][50],int B[][50],int C[][50],int r,int c){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            C[i][j]=A[i][j]+B[i][j];
}

void subMatrix(int A[][50],int B[][50],int C[][50],int r,int c){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            C[i][j]=A[i][j]-B[i][j];
}

void mulMatrix(int A[][50],int B[][50],int C[][50],int r1,int c1,int c2){
    for(int i=0;i<r1;i++)
        for(int j=0;j<c2;j++){
            C[i][j]=0;
            for(int k=0;k<c1;k++)
                C[i][j]+=A[i][k]*B[k][j];
        }
}

int equalMatrix(int A[][50],int B[][50],int r,int c){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(A[i][j]!=B[i][j]) return 0;
    return 1;
}

void transpose(int A[][50],int T[][50],int r,int c){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            T[j][i]=A[i][j];
}

int det2x2(int A[][50]){
    return A[0][0]*A[1][1] - A[0][1]*A[1][0];
}

int main(){
    int n = 5;
    printf("n = %d\n", n);
    printf("Sum a = %.2lf\n", sum_a(n));
    printf("Sum b = %d\n", sum_b(n));
    printf("Sum c = %lld\n", sum_c(n));
    printf("Product d = %lld\n", product_d(n));
    printf("Product e = %.2lf\n\n", product_e(n));

    int a[100] = {5, -2, 7, 5, 8, -2, 4};
    int size = 7;

    printf("Original array: ");
    printArray(a,size);

    printf("Max = %d\n", findMax(a,size));
    printf("Min = %d\n", findMin(a,size));
    printf("Sum = %d\n", sumArray(a,size));
    printf("Sum non-positive = %d\n", sumNonPositive(a,size));
    printf("Sum even = %d\n", sumEven(a,size));

    printf("Duplicate count = %d\n", countDuplicates(a,size));

    printf("Reverse array: ");
    reverseArray(a,size);
    printArray(a,size);

    printf("Sort ascending: ");
    sortAsc(a,size);
    printArray(a,size);

    printf("Delete position 2:\n");
    deletePos(a,&size,2);
    printArray(a,size);

    printf("Delete duplicates:\n");
    deleteDuplicates(a,&size);
    printArray(a,size);

    int key = 7;
    printf("Search %d at index = %d\n\n", key, search(a,size,key));

    int A[50][50] = {{1,2},{3,4}};
    int B[50][50] = {{5,6},{7,8}};
    int C[50][50], T[50][50];

    printf("Matrix A:\n"); printMatrix(A,2,2);
    printf("Matrix B:\n"); printMatrix(B,2,2);

    printf("A + B:\n");
    addMatrix(A,B,C,2,2);
    printMatrix(C,2,2);

    printf("A - B:\n");
    subMatrix(A,B,C,2,2);
    printMatrix(C,2,2);

    printf("A * B:\n");
    mulMatrix(A,B,C,2,2,2);
    printMatrix(C,2,2);

    printf("A == B ? %s\n", equalMatrix(A,B,2,2) ? "YES" : "NO");

    printf("Transpose A:\n");
    transpose(A,T,2,2);
    printMatrix(T,2,2);

    printf("Determinant of A = %d\n", det2x2(A));

    return 0;
}
