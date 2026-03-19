#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct nhanvien{
    string ten,ma;
    float luongcung,heso,luong;
};
void nhapds(nhanvien a[],int n){
    for (int i = 0;i < n;i++){
        cout <<"Nhap ten cua nhan vien thu "<<i+1<<" :";
        cin.ignore();
        getline(cin, a[i].ten);
        cout <<"Nhap ma so nhan vien :";
        cin >>a[i].ma;
        cout <<"Nhap luong co ban :";
        cin >>a[i].luongcung;
        cout <<"He so luong :";
        cin >>a[i].heso;
        a[i].luong = a[i].luongcung*a[i].heso;
    }
}
void xapsep(nhanvien a[],int n){
    for (int i = 0;i < n-1;i++){
        for (int j = i+1;j < n;j++){
            if (a[i].luong < a[j].luong){
                nhanvien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void timkiem(nhanvien a[],int n){
    string ma;
    cout <<"Nhap ma nhan vien muon tim :";
    cin.ignore();
    getline(cin, ma);
    for (int i = 0;i < n;i++){
        if (a[i].ma == ma){
            cout <<"Nhan vien ma so "<<a[i].ma<<" nay co ten la :"<<a[i].ten<<endl;
            cout <<"Muc luong cua nhan vien nay :"<<a[i].luong<<" trieu dong";
        }
    }
}
void xuatds(nhanvien a[],int n){
    cout <<"Danh Sach Nhan Vien Trong Cong Ty :"<<endl;
    cout <<"-------------------------------------"<<endl;
    cout <<"\n"<<left<<setw(20)<<"Ho va ten"<<setw(10)<<"Ma so"<<setw(10)<<"Luong"<<endl;
    cout <<"--------------------------------------"<<endl;
    for (int i = 0;i < n;i++){
        cout <<left<<setw(20)<<a[i].ten
             <<setw(10)<<a[i].ma
             <<fixed<<setprecision(2)<<setw(10)<<a[i].luong<<endl;
    }
}
int main(){
    nhanvien phong[100];
    int n;
    cout <<"Nhap so luong nhan vien :";
    cin >>n;
    nhapds(phong, n);
    xuatds(phong, n);
    xapsep(phong, n);
    timkiem(phong, n);
    return 0;
}

