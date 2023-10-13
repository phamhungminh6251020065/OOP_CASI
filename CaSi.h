#pragma once
#include<iostream>
#include<string>
using namespace std;
class CaSi{
protected:
	string MaCaSi, HoTen;
	float SoNamLViec;
	int SoDiaBanDuoc, SoBuoiDien;
public:
	CaSi();
	virtual void Nhap();
	virtual void Xuat();
	virtual float TinhLuong();
	bool operator >(CaSi &c);
	string GetMaCaSi();
};

