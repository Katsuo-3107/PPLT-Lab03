#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.14159265358979323846

float khoangCach(float xa, float ya, float xb, float yb) {
    return sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
}

float tinhDienTichTron(float chuvi) {
    float r = chuvi / (2 * PI);
    return PI * pow(r, 2);
}

void CheckNgayHopLe(int ngay, int thang, int nam) {
    if (nam < 1 || thang < 1 || thang > 12 || ngay < 1) {
        printf("Ngay khong hop le.\n");
        return;
    }
    
    int maxNgay;
    switch (thang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxNgay = 31;
            break;
        case 4: case 6: case 9: case 11:
            maxNgay = 30;
            break;
        case 2:
            if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) {
                maxNgay = 29;
            } else {
                maxNgay = 28;
            }
            break;
        default:
            printf("Thang khong hop le.\n");
            return;
    }
    if (ngay > maxNgay) {
        printf("Ngay khong hop le.\n");
    } else {
        printf("Ngay hop le.\n");
    }
}

void kiemTraChuoiDoiXung(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            printf("0\n");
            return;
        }
    }
    printf("1\n");
}   

int DecToBinary(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 2) + 10 * DecToBinary(n / 2);
}

struct SinhVien 
{
    char MSSV[20];
    char HoTen[50];
    float DiemPPLT;
    float DiemĐSTT;
    float DiemToanTin;
    float DiemTB;
    char XepLoai[20];
};

void timSinhVien(struct SinhVien sv[], int n, char mssv[])
{
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(sv[i].MSSV, mssv) == 0)
        {
            printf("Thong tin sinh vien:\n");
            printf("MSSV: %s\n", sv[i].MSSV);
            printf("Ho ten: %s\n", sv[i].HoTen);
            printf("Diem PPLT: %.2f\n", sv[i].DiemPPLT);
            printf("Diem DSTT: %.2f\n", sv[i].DiemĐSTT);
            printf("Diem Toan Tin: %.2f\n", sv[i].DiemToanTin);
            printf("Diem TB: %.2f\n", sv[i].DiemTB);
            printf("Xep loai: %s\n", sv[i].XepLoai);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Khong tim thay sinh vien.\n");
    }
}

void tinhDiemTB(struct SinhVien *sv)
{
    sv->DiemTB = (sv->DiemPPLT + sv->DiemĐSTT + sv->DiemToanTin) / 3.0;
}

void xepLoai(struct SinhVien *sv)
{
    if (sv->DiemTB >= 8)
    {
        strcpy(sv->XepLoai, "Xuat sac");
    }
    else if (sv->DiemTB >= 6.5)
    {
        strcpy(sv->XepLoai, "Kha");
    }
    else if (sv->DiemTB >= 5)
    {
        strcpy(sv->XepLoai, "Trung binh");
    }
    else
    {
        strcpy(sv->XepLoai, "Yeu");
    }
}

void timSinhVienThapNhat(struct SinhVien sv[], int n)
{
    int minIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (sv[i].DiemTB < sv[minIndex].DiemTB)
        {
            minIndex = i;
        }
    }

    printf("Sinh vien co diem TB thap nhat:\n");
    printf("MSSV: %s\n", sv[minIndex].MSSV);
    printf("Ho ten: %s\n", sv[minIndex].HoTen);
    printf("Diem TB: %.2f\n", sv[minIndex].DiemTB);
}

int demSinhVienKhaTroLen(struct SinhVien sv[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (sv[i].DiemTB >= 6.5)
        {
            count++;
        }
    }

    return count;
}

float giaiThua(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return n * giaiThua(n - 1);
}

float giaiFx1(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 2;
    }

    return 2 * giaiFx1(n - 1) + 3 * giaiFx1(n - 2); 
}
    
float giaiFx2(int n)
{
    if (n == 0)
    {
        return 3;
    }
    else if (n == 1)
    {
        return 5;
    }

    return giaiFx2(n - 1) + 2 * giaiFx1(n - 2); 
}

float giaiFx3(int n)
{
    if (n == 0)
    {
        return 4;
    }
    else if (n == 1)
    {
        return 7;
    }

    return 4 * giaiFx2(n) - giaiFx1(n - 1); 
}

int isPrime(int n)
{
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}

int sumSoNguyenTo(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i])) sum += a[i];
    }
    return sum;
}

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int tmp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = tmp;
        }
    }
}

void doiSoGiay(int n, int *gio, int *phut, int *giay)
{
    *gio = n / 3600;
    *phut = (n % 3600) / 60;
    *giay = n % 60;
}

int countDuplicate(int a[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k) count++;
    }
    return count;
}

int search(int a[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k) return i;
    }
    return -1;
}

int sumChan(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0) sum += a[i];
    }
    return sum;
}

int sumLe(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0) sum += a[i];
    }
    return sum;
}

int findMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max) max = a[i];
    }
    return max;
}

int findMin(int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min) min = a[i];
    }
    return min;
}

int sum20a(int n)
{
    int S = 0;
    for (int i = 1; i <= n; i++)
    {
        S += 2 * i + 1;
    }
    return S;
}

float sum20b(int n)
{
    float S = 0;
    float fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
        S += fact + 1;
    }
    return S;
}

float sum20c(int n)
{
    float S = 0;
    for (int i = 1; i <= n; i++)
    {
        S += (float)(2 * i + 1) / i;
    }
    return S;
}

int main() {
    float xa, ya, xb, yb;
    
    printf("1. Nhap toa do diem A (xa, ya): ");
    scanf("%f %f", &xa, &ya);
    
    printf("Nhap toa do diem B (xb, yb): ");
    scanf("%f %f", &xb, &yb);
    
    float distance = khoangCach(xa, ya, xb, yb);
    printf("Khoang cach giua diem A va diem B la: %.2f\n", distance);
    
    printf("2. Nhap chu vi hinh tron: ");

    float chuvi;
    scanf("%f", &chuvi);    

    float area = tinhDienTichTron(chuvi);
    printf("Dien tich hinh tron la: %.2f\n", area); 

    printf("3. Nhap ngay, thang, nam: ");

    int ngay, thang, nam;
    scanf("%d %d %d", &ngay, &thang, &nam);

    CheckNgayHopLe(ngay, thang, nam);   

    printf("4. Nhap chuoi: ");

    char str[100];
    scanf("%s", str);

    kiemTraChuoiDoiXung(str);

    printf("5. Nhap so nguyen: ");

    int j;
    scanf("%d", &j);

    int binary = DecToBinary(j);

    printf("So nhi phan: %d\n", binary);

    printf("6.\n");
    int n;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    struct SinhVien sv[n];

    for (int i = 0; i < n; i++)
    {
        printf("Nhap thong tin sinh vien %d: \n", i + 1);

        printf("MSSV: ");
        scanf("%s", sv[i].MSSV);

        getchar();

        printf("Ho ten: ");
        fgets(sv[i].HoTen, sizeof(sv[i].HoTen), stdin);

        sv[i].HoTen[strcspn(sv[i].HoTen, "\n")] = '\0';

        printf("Diem PPLT: ");
        scanf("%f", &sv[i].DiemPPLT);

        printf("Diem ĐSTT: ");
        scanf("%f", &sv[i].DiemĐSTT);

        printf("Diem Toan Tin: ");
        scanf("%f", &sv[i].DiemToanTin);

        tinhDiemTB(&sv[i]);

        xepLoai(&sv[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Sinh vien %d:\n", i + 1);
        printf("MSSV: %s\n", sv[i].MSSV);
        printf("Ho ten: %s\n", sv[i].HoTen);
        printf("Diem TB: %.2f\n", sv[i].DiemTB);
        printf("Xep loai: %s\n", sv[i].XepLoai);
    }

    char mssvCanTim[20];

    printf("Nhap MSSV can tim: ");
    scanf("%s", mssvCanTim);

    timSinhVien(sv, n, mssvCanTim);

    timSinhVienThapNhat(sv, n);

    int soLuong = demSinhVienKhaTroLen(sv, n);

    printf("So sinh vien hoc luc kha tro len: %d\n", soLuong);

    int c;
    printf("7. Nhap n: ");
    scanf("%d", &c);

    if (c < 0)
    {
        printf("n phai la so khong am.\n");
    }
    else
    {
        printf("%d! = %2.f\n", c, giaiThua(c));
    }

    int a;
    printf("8. Nhap x: ");
    scanf("%d", &a);

    if (a < 0)
    {
        printf("x phai la so khong am. \n");
    }
    else
    {
        printf("f(%d) = %2.f\n", a, giaiFx1(a));
    }
    
    int b;
    printf("9. Nhap x: ");
    scanf("%d", &b);

    if (b < 0)
    {
        printf("x phai la so khong am. \n");
    }
    else
    {
        printf("f(%d) = %2.f\n", b, giaiFx2(b));
    }

    int d;
    printf("10. Nhap x: ");
    scanf("%d", &d);

    if (d < 0)
    {
        printf("x phai la so khong am. \n");
    }
    else
    {
        printf("f(%d) = %2.f\n", d, giaiFx3(d + 1));
    }

    printf("11. Nhap so phan tu mang: ");
    int m;
    scanf("%d", &m);
    int arr[100];
    for (int i = 0; i < m; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Tong so nguyen to trong mang: %d\n", sumSoNguyenTo(arr, m));

    printf("12. Nhap so phan tu mang cho sap xep: ");
    int p;
    scanf("%d", &p);
    int arr2[100];
    for (int i = 0; i < p; i++)
    {
        printf("arr2[%d] = ", i);
        scanf("%d", &arr2[i]);
    }
    int arr2Copy[100];
    for (int i = 0; i < p; i++) arr2Copy[i] = arr2[i];
    bubbleSort(arr2, p);
    printf("Bubble sort: ");
    for (int i = 0; i < p; i++) printf("%d ", arr2[i]);
    printf("\n");
    selectionSort(arr2Copy, p);
    printf("Selection sort: ");
    for (int i = 0; i < p; i++) printf("%d ", arr2Copy[i]);
    printf("\n");

    printf("13. Nhap so giay: ");
    int seconds;
    scanf("%d", &seconds);
    int hours, minutes, secs;
    doiSoGiay(seconds, &hours, &minutes, &secs);
    printf("%d giay = %d gio, %d phut, %d giay\n", seconds, hours, minutes, secs);

    printf("14. Nhap so phan tu mang va gia tri k: ");
    int q, k;
    scanf("%d %d", &q, &k);
    int arr3[100];
    for (int i = 0; i < q; i++)
    {
        printf("arr3[%d] = ", i);
        scanf("%d", &arr3[i]);
    }
    printf("So lan xuat hien cua %d trong mang = %d\n", k, countDuplicate(arr3, q, k));

    printf("15. Nhap so phan tu mang va gia tri can tim: ");
    int r, key;
    scanf("%d %d", &r, &key);
    int arr4[100];
    for (int i = 0; i < r; i++)
    {
        printf("arr4[%d] = ", i);
        scanf("%d", &arr4[i]);
    }
    int pos = search(arr4, r, key);
    if (pos >= 0)
        printf("Gia tri %d duoc tim thay o vi tri %d\n", key, pos);
    else
        printf("Khong tim thay gia tri %d\n", key);

    printf("16. Nhap so phan tu mang de tinh tong so chan: ");
    int s;
    scanf("%d", &s);
    int arr5[100];
    for (int i = 0; i < s; i++)
    {
        printf("arr5[%d] = ", i);
        scanf("%d", &arr5[i]);
    }
    printf("Tong so chan trong mang = %d\n", sumChan(arr5, s));

    printf("17. Nhap so phan tu mang de tinh tong so le: ");
    int t;
    scanf("%d", &t);
    int arr6[100];
    for (int i = 0; i < t; i++)
    {
        printf("arr6[%d] = ", i);
        scanf("%d", &arr6[i]);
    }
    printf("Tong so le trong mang = %d\n", sumLe(arr6, t));

    printf("18. Nhap so phan tu mang de tim so lon nhat: ");
    int u;
    scanf("%d", &u);
    int arr7[100];
    for (int i = 0; i < u; i++)
    {
        printf("arr7[%d] = ", i);
        scanf("%d", &arr7[i]);
    }
    printf("So lon nhat trong mang = %d\n", findMax(arr7, u));

    printf("19. Nhap so phan tu mang de tim so nho nhat: ");
    int v;
    scanf("%d", &v);
    int arr8[100];
    for (int i = 0; i < v; i++)
    {
        printf("arr8[%d] = ", i);
        scanf("%d", &arr8[i]);
    }
    printf("So nho nhat trong mang = %d\n", findMin(arr8, v));

    printf("20. Nhap n cho cac bieu thuc: ");
    int w;
    scanf("%d", &w);
    printf("a) S = %d\n", sum20a(w));
    printf("b) S = %.2f\n", sum20b(w));
    printf("c) S = %.2f\n", sum20c(w));

    return 0;
}