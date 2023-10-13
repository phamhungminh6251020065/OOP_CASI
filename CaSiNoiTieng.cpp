#include "CaSiNoiTieng.h"
CaSiNoiTieng::CaSiNoiTieng() :CaSi() {
	SoGameShowThamGia = 0;
}
void CaSiNoiTieng::Nhap() {
	CaSi::Nhap();
	cout << "Nhap so gameshow tham gia:"; cin >> SoGameShowThamGia;
}
void CaSiNoiTieng::Xuat() {
	cout << "Ca si noi tieng" << endl;
	CaSi::Xuat();
	cout << "So gameshow tham gia:" << SoGameShowThamGia << endl;
	cout << "Luong:" << fixed << TinhLuong() << endl;
}
float CaSiNoiTieng::TinhLuong() {
	return 5000000 + 500000*SoNamLViec + 1200 * SoDiaBanDuoc + 500000*SoBuoiDien + 500000*SoGameShowThamGia;
}