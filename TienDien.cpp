#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct khachhang{
    string hoten,makh;
    int chisocu,chisomoi,sodien;
};
void nhapds(khachhang a[],int n){
    for (int i = 0;i < n;i++){
    cout <<"NHAP THONG TIN KHACH HANG THU "<<i+1<<endl;
    cin.ignore(32767, '\n');
    cout <<"Ho va Ten :";
    getline(cin, a[i].hoten);
    cout <<"Nhap ma khach hang :";
    cin >>a[i].makh;
    cout <<"Chi so cu :";
    cin >>a[i].chisocu;
    cout <<"Chi so moi :";
    cin >>a[i].chisomoi;
    a[i].sodien = a[i].chisomoi-a[i].chisocu;
    }
}
double thanhtien(int sodien){
    double tongtien = 0;
    if (sodien <= 50){
        tongtien = sodien * 1678;
    }
    else if (sodien <= 100){
        tongtien = 50 * 1678 + (sodien - 50) * 1734;
    }
    else if (sodien > 100){
        tongtien = 50 *1678 + 50 * 1734 + (sodien - 100) * 2014;
    }
    return tongtien;
}
void xuatds(khachhang a[],int n){
    cout <<left<<setw(20)<<"Ten Khach Hang"<<setw(10)<<"Ma KH"<<setw(10)<<"So dien"<<setw(10)<<"Thanh Tien"<<endl;
    cout <<"------------------------------------------------"<<endl;
    for (int i = 0;i < n;i++){
        double tien = thanhtien(a[i].sodien);
        cout <<left<<setw(20)<<a[i].hoten
             <<setw(10)<<a[i].makh
             <<setw(7)<<a[i].sodien
             <<setw(10)<<tien<<endl;
    }
}
int main(){
    int n;
    khachhang ds[100];
    cout <<"Nhap so luong khach hang :";
    cin >>n;
    nhapds(ds, n);
    xuatds(ds, n);
    return 0;
}