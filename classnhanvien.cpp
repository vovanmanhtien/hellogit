#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class NhanVien{
	char Ho[10],Ten[10],HoTen[20];
	int luong, phuCap; 
	float heSo;
	public:
		void tachHoTen(char hoten[]){
			int l = strlen(hoten), dd = l-1;
			while (hoten[dd] != ' ' && dd > 0) --dd;
			
			for (int i=0; i<dd; ++i) Ho[i] = hoten[i]; Ho[dd] = 0;
			
			int size = 0;
			for (int i=dd+1; i<l; ++i) Ten[size++] = hoten[i]; Ten[size] = 0;
		}
		void tinhLuong(int heso){
			phuCap = (heSo >= 4.0 ? 3 : heSo < 3.0 ? 7 : 5) * 100000;
			luong = heSo * 1350000 + phuCap;
			heSo = heso;
		}
		
		NhanVien(){}
		NhanVien(char hoten[], float HESO){
			tinhLuong(HESO);
			tachHoTen(hoten);
		}
		
		void nhap(){
			cout<<"ten nhanh vien: ";
			cin.get(HoTen,20);
			cin.ignore();
			cout<<"he so luong: ";
			cin >> heSo;
			tinhLuong(heSo);
			tachHoTen(HoTen);
		}
		void xuat(){
			cout << Ho << ' ' << Ten << endl;
			cout << luong << ' ' << phuCap << ' ' << heSo << endl;
		}
		
		char* getHoTen(){
			return HoTen;
		}
		char* getHo(){
			return Ho;
		}
		char* getTen(){
			return Ten;
		}
		
		int getLuong(){
			return luong;
		}
};

void hoanVi(char *a, char *b){
	char *t = (char*) malloc (20);
	strcpy(t,a);
	strcpy(a,b);
	strcpy(b,t);
}

void sapXep(NhanVien DS[], int n){
	for (int i=0; i<n-1; ++i){
		for (int j=i+1; j<n; ++j){
			char *a = DS[i].getTen(), *b = DS[i].getTen();
			int f = strcmp(a, b);
			if (f == 1){
				hoanVi(a,b);
			} else if (f == 0){
				a = DS[i].getHo(); b = DS[j].getHo();
				f = strcmp(a, b);
				if (f == 1){
					hoanVi(a, b);
				}
			}
		}
	}
}

int main(){
	char hoten[] = {"QUOC HUY"};
	NhanVien a(hoten,3.5);
	a.xuat();

	NhanVien DS[50];
	cout<<"so nhan vien:";
	int n; cin >> n;
	
//	freopen("Test.txt","r",stdin);
	for (int i=0; i<n; ++i){
		cin.ignore();
		DS[i].nhap();
	}
	for (int i=0; i<n; ++i){
		DS[i].xuat();
	}
	cout << "SAPXEP :" << endl;
	sapXep(DS,n);
	for (int i=0; i<n; ++i){
		DS[i].xuat();
	}
return 0;}
