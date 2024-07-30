#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 100

void taoVaXuatMaTran(int a[][MAX], int m, int n, int k) {
    srand(time(NULL));
    printf("Ma tran ngau nhien:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % (k + 1);
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void tinhTongTungDong(int a[][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        int tong = 0;
        for (int j = 0; j < n; j++) {
            tong += a[i][j];
        }
        printf("Tong dong %d: %d\n", i, tong);
    }
}

void xuatCacPhanTuDuongBien(int a[][MAX], int m, int n) {
    printf("Cac phan tu tren duong bien:\n");
    // In hàng đầu tiên
    for (int j = 0; j < n; j++) {
        printf("%d ", a[0][j]);
    }
    // In cột cuối cùng trừ phần tử đầu và cuối
    for (int i = 1; i < m; i++) {
        printf("%d ", a[i][n - 1]);
    }
    // In hàng cuối cùng trừ phần tử đầu và cuối
    for (int j = n - 2; j >= 0; j--) {
        printf("%d ", a[m - 1][j]);
    }
    // In cột đầu tiên trừ phần tử đầu và cuối
    for (int i = m - 2; i > 0; i--) {
        printf("%d ", a[i][0]);
    }
    printf("\n");
}

void tinhTongTungDong(int a[][MAX], int m, int n) {
    printf("Tong gia tri tung dong:\n");
    for (int i = 0; i < m; i++) {
        int tong = 0;
        for (int j = 0; j < n; j++) {
            tong += a[i][j];
        }
        printf("Tong dong %d: %d\n", i, tong);
    }
}

void xuatPhanTuLonNhatTungCot(int a[][MAX], int m, int n) {
    printf("Phan tu lon nhat tren tung cot:\n");
    for (int j = 0; j < n; j++) {
        int max = a[0][j];
        for (int i = 1; i < m; i++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        printf("Cot %d: %d\n", j, max);
    }
}

void xuatPhanTuCucDai(int a[][MAX], int m, int n) {
    printf("Cac phan tu cuc dai:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            bool cucDai = true;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && !(di == 0 && dj == 0)) {
                        if (a[ni][nj] >= a[i][j]) {
                            cucDai = false;
                            break;
                        }
                    }
                }
                if (!cucDai) break;
            }
            if (cucDai) printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}

void xuatPhanTuHoangHau(int a[][MAX], int m, int n) {
    printf("Cac phan tu hoang hau:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            bool hoangHau = true;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && !(di == 0 && dj == 0)) {
                        if (a[ni][nj] >= a[i][j]) {
                            hoangHau = false;
                            break;
                        }
                    }
                }
                if (!hoangHau) break;
            }
            if (hoangHau) printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}

void xuatDiemYenNgua(int a[][MAX], int m, int n) {
    printf("Cac phan tu diem yen ngua:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            bool yenNgua = true;
            for (int k = 0; k < n; k++) {
                if (a[i][k] > a[i][j]) {
                    yenNgua = false;
                    break;
                }
            }
            if (yenNgua) {
                for (int k = 0; k < m; k++) {
                    if (a[k][j] < a[i][j]) {
                        yenNgua = false;
                        break;
                    }
                }
            }
            if (yenNgua) printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}

void xuatDongToanChan(int a[][MAX], int m, int n) {
    printf("Cac dong chi chua so chan:\n");
    for (int i = 0; i < m; i++) {
        bool allEven = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                allEven = false;
                break;
            }
        }
        if (allEven) {
            for (int j = 0; j < n; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}

void sapXepTangTheoDong(int a[][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i][j] > a[i][k]) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}

void menu() {
    printf("1. Tao va xuat ma tran\n");
    printf("2. Tinh tong gia tri tung dong\n");
    printf("3. Xuat phan tu lon nhat tren tung cot\n");
    printf("4. Xuat cac phan tu thuoc duong bien\n");
    printf("5. Xuat cac phan tu cuc dai\n");
    printf("6. Xuat cac phan tu hoang hau\n");
    printf("7. Xuat cac phan tu diem yen ngua\n");
    printf("8. Xuat dong chi chua so chan\n");
    printf("9. Sap xep ma tran tang theo tung dong\n");
    printf("0. Thoat\n");
}


int main() {
      int a[MAX][MAX], m, n, k;
    int choice;
    printf("Nhap so dong m: ");
    scanf_s("%d", &m);
    printf("Nhap so cot n: ");
    scanf_s("%d", &n);
    printf("Nhap gia tri ngau nhien toi da k: ");
    scanf_s("%d", &k);
    do {
        menu();
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            taoVaXuatMaTran(a, m, n, k);
            break;
        case 2:
            tinhTongTungDong(a, m, n);
            break;
        case 3:
            xuatPhanTuLonNhatTungCot(a, m, n);
            break;
        case 4:
            xuatCacPhanTuDuongBien(a, m, n);
            break;
        case 5:
            xuatPhanTuCucDai(a, m, n);
            break;
        case 6:
            xuatPhanTuHoangHau(a, m, n);
            break;
        case 7:
            xuatDiemYenNgua(a, m, n);
            break;
        case 8:
            xuatDongToanChan(a, m, n);
            break;
        case 9:
            sapXepTangTheoDong(a, m, n);
            printf("Ma tran sau khi sap xep tang theo tung dong:\n");
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
            break;
        case 0:
            printf("Thoat chuong trinh\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
