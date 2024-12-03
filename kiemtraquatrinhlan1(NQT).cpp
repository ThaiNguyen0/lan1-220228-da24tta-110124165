/* 
	-MSSV:110124165
	-HoTen:Nguyen Quoc Thai
	-Lop:DA24TTA
*/ 

#include<stdio.h>
#include <stdlib.h>
#define ngaytrongtuan 7

void Nhaptghoc(float tghoc[]);
void Xuattghoc(float tghoc[]);
float tongtghoc(float tghoc[]);
float TBtghoc(float tghoc[]);
void TimItNhieutghoc(float tghoc[]);
void HQhoctap(float tghoc[]);
void SapXeptghoc(float tghoc[]);
void TGSapXep(float tghoc[]);

int main() {
    float tghoc[ngaytrongtuan];

    Nhaptghoc(tghoc);
    Xuattghoc(tghoc);
    printf("\nTong thoi gian hoc trong tuan: %.2f gio\n", tongtghoc(tghoc));
    printf("Thoi gian hoc trung binh: %.2f gio\n", TBtghoc(tghoc));
    TimItNhieutghoc(tghoc);
    HQhoctap(tghoc);
    SapXeptghoc(tghoc);
    TGSapXep(tghoc);

    return 0;
}

void Nhaptghoc(float tghoc[]) {
    for (int i = 0; i < ngaytrongtuan; i++) {
        do {
            printf("Nhap thoi gian hoc cho ngay %d (0 <= gio <= 15): ", i + 1);
            scanf("%f", &tghoc[i]);
            if (tghoc[i] < 0 || tghoc[i] > 15) {
                printf("Nhap sai thoi gian vui long nhap lai\n");
            }
        } while (tghoc[i] < 0 || tghoc[i] > 15);
    }
}

void Xuattghoc(float tghoc[]) {
    const char *days[] = {"Thu 2", "Thu 3", "Thu 4", "Thu 5", "Thu 6", "Thu 7", "Chu Nhat"};
    printf("\nThoi gian hoc trong tuan la:\n");
    for (int i = 0; i < ngaytrongtuan; i++) {
        printf("%s: %.2f gio\n", days[i], tghoc[i]);
    }
}

float tongtghoc(float tghoc[]) {
    float tong = 0;
    for (int i = 0; i < ngaytrongtuan; i++) {
        tong += tghoc[i];
    }
    return tong;
}

float TBtghoc(float tghoc[]) {
    return tongtghoc(tghoc) / ngaytrongtuan;
}

void TimItNhieutghoc(float tghoc[]) {
    int ngaynhieu = 0, ngayit = 0;
    for (int i = 1; i < ngaytrongtuan; i++) {
        if (tghoc[i] > tghoc[ngaynhieu]) {
            ngaynhieu = i;
        }
        if (tghoc[i] < tghoc[ngayit]) {
            ngayit = i;
        }
    }
    const char *days[] = {"Thu 2", "Thu 3", "Thu 4", "Thu 5", "Thu 6", "Thu 7", "Chu Nhat"};
    printf("\nNgay hoc nhieu nhat: %s: %.2f gio\n", days[ngaynhieu], tghoc[ngaynhieu]);
    printf("Ngay hoc it nhat: %s: %.2f gio\n", days[ngayit], tghoc[ngayit]);
}

void HQhoctap(float tghoc[]) {
    float muctieu;
    printf("\nNhap muc tieu so gio hoc (X): ");
    scanf("%f", &muctieu);

    int ngayvuotMT = 0, ngaychuadatMT = 0;
    for (int i = 0; i < ngaytrongtuan; i++) {
        if (tghoc[i] >= muctieu) {
            ngayvuotMT++;
        } else {
            ngaychuadatMT++;
        }
    }

    printf("\nSo ngay vuot muc tieu: %d ngay\n", ngayvuotMT);
    printf("So ngay chua dat muc tieu: %d ngay\n", ngaychuadatMT);
}

void SapXeptghoc(float tghoc[]) {
    for (int i = 0; i < ngaytrongtuan - 1; i++) {
        for (int j = i + 1; j < ngaytrongtuan; j++) {
            if (tghoc[i] < tghoc[j]) {
                float temp = tghoc[i];
                tghoc[i] = tghoc[j];
                tghoc[j] = temp;
            }
        }
    }
}

void TGSapXep(float tghoc[]) {
    printf("\nThoi gian hoc tap sau khi sap xep:\n");
    const char *days[] = {"Thu 2", "Thu 3", "Thu 4", "Thu 5", "Thu 6", "Thu 7", "Chu Nhat"};
    for (int i = 0; i < ngaytrongtuan; i++) {
        printf("%s: %.2f gio\n", days[i], tghoc[i]);
    }
}


