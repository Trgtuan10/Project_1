#include <bits/stdc++.h>
using namespace std;

int so_kwh;
double tinh_tien(int so_kwh, int muc_gia[], double gia[]){
    int i = 0;
    double tien_dien = 0;
    while (so_kwh > 0) {
        int muc = min(muc_gia[i], so_kwh);
        tien_dien += muc * gia[i];
        so_kwh -= muc;
        i++;
    }
    return tien_dien;
}

int main() {
    cin >> so_kwh;

    int muc_gia_moi[] = {100, 100, 200, 300, 100000};
    double gia_moi[] = {1.728, 2.074, 2.612, 3.111, 3.457};

    int muc_gia_cu[] = {50, 50, 100, 100, 100, 1000000};
    double gia_cu[] = {1.728, 1.786, 2.074, 2.612, 2.919, 3.015};

    double tien_dien_moi = tinh_tien(so_kwh, muc_gia_moi, gia_moi);
    double tien_dien_cu = tinh_tien(so_kwh, muc_gia_cu, gia_cu);

    double chenh_lech = tien_dien_moi - tien_dien_cu;


    std::cout << std::fixed << std::setprecision(2) << chenh_lech*1.1*1000  << std::endl;

    return 0;
}