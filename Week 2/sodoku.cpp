#include<iostream>

using namespace std;

int a[10][10];
int count;

void Nhap(){
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            cin >> a[i][j];
        }
    }
}

int checkCot(int k, int i, int j){
    for (int t=1; t<=9; t++){
        if (k == a[t][j] && t!=i ) return 0;
    }
    return 1;
}

int checkHang(int k, int i, int j){
    for (int t=1; t<=9; t++){
        if (k == a[i][t] && j!=t ) return 0;
    }
    return 1;
}

int checkO(int k, int i, int j){
    int c = ((i-1)/3)*3 + 1;
    int b = ((j-1)/3)*3 + 1;
    for(int t=c; t<=c+2; t++){
        for(int h=b; h<=b+2; h++){
            if(a[t][h] == k && i!=t && j!=h) return 0;
        }
    }
    return 1;
}

int checkExist(int i, int j){
    if(a[i][j] != 0) return 0;
    else return 1;
}

void Try(int i, int j){
    if(checkExist(i,j)){
        for(int k=1; k<=9; k++){
            if(checkCot(k,i,j) * checkHang(k,i,j) * checkO(k,i,j) ){
                a[i][j]=k;
                if(i==9 && j==9){
                    count++;
                }
                else if(i<9 && j==9 )  Try(i+1,1);
                else  Try(i,j+1);
                a[i][j] = 0; // Quay lui để thử các giá trị khác
            }
        }
    }
    else{
        if(i==9 && j==9){
            count++;
        }
        else if(i<9 && j==9 )  Try(i+1,1);
        else  Try(i,j+1); 
    }
}

int main(){
    // freopen("skt.inp", "r", stdin);
    // freopen("skt.out", "w", stdout);
    Nhap();
    count = 0;
    Try(1,1);
    cout << count;
    return 0;
}
