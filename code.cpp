#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct hocphan{
    string tenmon,mamon;
    int tin;
    float diemcc,diemthi,diemtong,GPA;
};
void nhapds(hocphan a[],int n){
    for (int i = 0;i < n;i++){
        cout <<"Nhap ten mon :";
        cin.ignore();
        getline(cin, a[i].tenmon);
        cout <<"Nhap ma mon :";
        cin >>a[i].mamon;
        cout <<"Nhap so tin chi :";
        cin >>a[i].tin;
        cout <<"Nhap diem chuyen can :";
        cin >>a[i].diemcc;
        cout <<"Nhap diem thi :";
        cin >>a[i].diemthi;
        a[i].diemtong = a[i].diemcc * 0.3 + a[i].diemthi *0.7;
    }
}
void sapxep(hocphan a[],int n){
    for (int i = 0;i < n-1;i++){
        for (int j = i+1;j < n;j++){
            if (a[i].diemtong < a[j].diemtong){
                hocphan temp = a[i];
                a[i] = a[j];
                a[j] = temp;           
            }
            else if (a[i].diemtong == a[j].diemtong){
                if (a[i].tin > a[j].tin) a[i].tin;
                else a[j].tin;
            }
        }
    }
}
void xuatds(hocphan a[],int n){

    cout <<">>> DANH SACH CAC MON HOC <<<"<<endl;
    float diemtongX_TC;
    float tongtin;
    for (int i = 0;i < n;i++){
        cout <<left<<setw(20)<<"Ten Mon"<<setw(10)<<"Ma Mon"<<setw(5)<<"So tin"<<setw(8)<<"Diem CC"<<setw(9)<<"Diem thi"<<endl;
        cout <<"------------------------------------------------"<<endl;
        cout <<left<<setw(20)<<a[i].tenmon
             <<setw(10)<<a[i].mamon
             <<setw(5)<<a[i].tin
             <<setw(8)<<a[i].diemcc
             <<fixed<<setprecision(2)<<setw(9)<<a[i].diemthi<<endl;
        diemtongX_TC += (a[i].diemtong * a[i].tin);
        tongtin += a[i].tin; 
    }
    float GPA = diemtongX_TC/tongtin;
    cout <<"GPA ki nay cua ban la :"<<GPA<<endl;
}
int main(){
    int n;
    hocphan mon[20];
    cout <<"Nhap so mon ban hoc :";
    cin >>n;
    nhapds(mon, n);
    sapxep(mon, n);
    xuatds(mon, n);
    return 0;
}