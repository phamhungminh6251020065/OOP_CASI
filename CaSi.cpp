#include "CaSi.h"
CaSi::CaSi() {
	MaCaSi = "";
	HoTen = "";
	SoNamLViec = 0;
	SoDiaBanDuoc = 0;
	SoBuoiDien = 0;
}
void CaSi::Nhap() {
	cin.ignore();
	cout << "Nhap ma ca si:"; getline(cin, MaCaSi);
	cout << "Nhap ho ten:"; getline(cin, HoTen);
	cout << "Nhap so nam lam viec:"; cin >> SoNamLViec;
	cout << "Nhap so dia ban duoc:"; cin >> SoDiaBanDuoc;
	cout << "Nhap so buoi dien:"; cin >> SoBuoiDien;
}
void CaSi::Xuat() {
	cout << "Ma ca si:" << MaCaSi << endl;
	cout << "Ho ten:" << HoTen << endl;
	cout << "So nam lam viec:" << SoNamLViec << endl;
	cout << "So dia ban duoc:" << SoDiaBanDuoc << endl;
	cout << "So buoi dien:" << SoBuoiDien << endl;
}
float CaSi::TinhLuong() {
	return 0;
}
bool CaSi::operator>(CaSi &c) {
	return this->TinhLuong() > c.TinhLuong();
}
string CaSi::GetMaCaSi() {
	return MaCaSi;
}