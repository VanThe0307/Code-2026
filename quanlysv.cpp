#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct sinhvien{
    string hoten,masv;
    float toan,ly,anh,tb;
};
void nhapsv(sinhvien a[],int n){
    for (int i = 0;i < n;i++){
        cout <<"Nhap thong tin cua sinh vien thu "<<i+1<<endl;
        cin.ignore(32767,'\n');
        cout <<"Ho va Ten: ";getline(cin, a[i].hoten);
        cout <<"Ma SV: ";getline(cin, a[i].masv);
        cout <<"Diem toan: ";cin >>a[i].toan;
        cout <<"Diem ly: ";cin >>a[i].ly;
        cout <<"Diem anh: ";cin >>a[i].anh;
        a[i].tb = (a[i].toan+a[i].ly+a[i].anh)/3;
    }
}
void timkiem(sinhvien a[],int n){
    bool timthay = false;
    string tencantim;
    cout <<"Nhap ma cua sinh vien can tim: ";cin >>tencantim;
    for (int i = 0;i < n;i++){
        if (a[i].hoten == tencantim){
            cout <<"Ten :"<<a[i].hoten<<" | Diem TB :"<<a[i].tb<<endl;
        }
    }
    if (!timthay) cout <<"Khong tim thay sinh vien nao co ma nay!"<<endl;
}
void xoa(sinhvien a[],int &n){
    string macanxoa;
    cout <<"Nhap ma sinh vien can xoa: ";
    cin >>macanxoa;
    int vitri = -1;
    for (int i = 0;i < n;i++){
        if (a[i].masv == macanxoa){
            vitri = i;
            break;
        }
    }
    if (vitri != -1){
        for (int j = vitri;j < n-1;j++){
            a[j] = a[j+1];
        }
        n--;
        cout <<"Da xoa sinh vien "<<macanxoa<<" ra khoi sanh sach sinh vien!"<<endl;
    } else {
        cout <<"Khong tim thay sinh vien nay de xoa!"<<endl;
    }
}
void suadiem(sinhvien a[],int n){
    bool timthay = false;
    string macansua;
    cout <<"Nhap ma sinh vien can sua diem: ";
    cin >>macansua;
    for (int i = 0;i < n;i++){
        if (a[i].masv == macansua){
            cout <<"=> DA TIM THAY SINH VIEN :"<<a[i].hoten<<endl;
            cout <<"--- Nhap lai bang diem ---"<<endl;
            cout <<"Diem toan: ";cin >>a[i].toan;
            cout <<"Diem ly: ";cin >>a[i].ly;
            cout <<"Diem anh: ";cin >>a[i].anh;
            timthay = true;
            a[i].tb = (a[i].anh+a[i].ly+a[i].toan)/3.0;
            cout <<"=> Cap nhat diem thanh cong cho sinh vien "<<macansua<<"!"<<endl;
            break;        
        }
    }
    if (!timthay) cout <<"Khong tim thay sinh vien co ten "<<macansua<<"!"<<endl;
}
void thongke(sinhvien a[],int n){
    int dem = 0;
    for (int i = 0;i < n;i++){
        if (a[i].tb >= 8.0){
            dem++;
        }
    }
    cout <<"Co "<<dem<<" sinh vien co diem trung binh tren 8"<<endl;
}
void sapxep(sinhvien a[],int n){
    for (int i = 0;i < n-1;i++){
        for (int j = i+1;j < n;j++){
            if (a[i].tb < a[j].tb){
                sinhvien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void xuatds(sinhvien a[],int n){
    cout <<left<<setw(20)<<"Ho va Ten"<<setw(10)<<"Ma SV"<<setw(10)<<"Diem TB"<<endl;
    cout <<"---------------------------------------------"<<endl;
    for (int i = 0;i < n;i++){
        cout <<left<<setw(20)<<a[i].hoten
             <<setw(10)<<a[i].masv
             <<fixed<<setprecision(2)<<setw(10)<<a[i].tb<<endl;
    }
}
int main(){
    int chon,n = 0;
    sinhvien ds[100];
    do{
        cout <<"================= MENU ================="<<endl;
        cout <<"1.Xem danh sach"<<endl;
        cout <<"2.Xuat sanh sach"<<endl;
        cout <<"3.Tim kiem theo ma sinh vien"<<endl;
        cout <<"4.Xoa sinh vien"<<endl;
        cout <<"5.Sua diem sinh vien"<<endl;
        cout <<"6.Thong ke sinh vien gioi"<<endl;
        cout <<"7.Sap xep sinh vien theo thu tu diem giam dan!"<<endl;
        cout <<"0.Thoat MENU"<<endl;
        cout <<"Hay chon tab ban muon xem: ";cin >>chon;
        switch(chon){
            case 1:
            cout <<"Nhap so luong sinh vien :";cin >>n;
            nhapsv(ds, n);
            break;
            case 2:
            xuatds(ds, n);
            break;
            case 3:
            timkiem(ds, n);
            break;
            case 4:
            xoa(ds, n);
            break;
            case 5:
            suadiem(ds, n);
            break;
            case 6:
            thongke(ds, n);
            break;
            case 7:
            sapxep(ds, n);
            break;
            case 0:
            cout <<"Thoat chuong trinh!"<<endl;
            break;
            default: cout <<"Vui long chon lai dung so!"<<endl;
        }
    } while(chon != 0);
    return 0;
}





