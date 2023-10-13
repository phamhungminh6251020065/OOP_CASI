#include "CaSiChuaNoiTieng.h"
CaSiChuaNoiTieng::CaSiChuaNoiTieng():CaSi() {

}
void CaSiChuaNoiTieng::Nhap() {
	CaSi::Nhap();
}
void CaSiChuaNoiTieng::Xuat() {
	cout << "Ca si chua noi tieng" << endl;
	CaSi::Xuat();
	cout << "Luong:" << fixed << TinhLuong() << endl;
}
float CaSiChuaNoiTieng::TinhLuong() {
	return 3000000 + 500000*SoNamLViec + 1000 * SoDiaBanDuoc + 200000*SoBuoiDien;
}