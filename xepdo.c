#include <stdio.h>

int main() {
    int so_o, so_vat;
    scanf("%d", &so_o);
    int ngan_xep[so_o];
    int so_luong_o;
    scanf("%d", &so_luong_o);
    for (int i = 0; i < so_o; i++) {
        scanf("%d", &ngan_xep[i]);
    }
    scanf("%d", &so_vat);
    int do_vat[so_vat];
    for (int i = 0; i < so_vat; i++) {
        scanf("%d", &do_vat[i]);
    }
    for (int i = 0; i < so_o - 1; i++) {
        for (int j = 0; j < so_o - i - 1; j++) {
            if (ngan_xep[j] > ngan_xep[j + 1]) {
                int tmp = ngan_xep[j];
                ngan_xep[j] = ngan_xep[j + 1];
                ngan_xep[j + 1] = tmp;
            }
        }
    }
    int dem[so_o];
    for (int i = 0; i < so_o; i++) {
        dem[i] = so_luong_o;
    }
    for (int i = 0; i < so_o; i++) {
        for (int j = 0; j < so_vat; j++) {
            if (do_vat[j] == ngan_xep[i]) {
                dem[i] = dem[i] - 1;
                if (dem[i] == 0) {
                    break;
                }
            }
        }
    }
    int kq = 0;
    for (int i = 0; i < so_o; i++) {
        if (dem[i] != 0) {
            kq++;
        }
    }
    printf("%d", kq);
    return 0;
}