#pragma once
#include"CaSi.h"
#include"CaSiNoiTieng.h"
#include"CaSiChuaNoiTieng.h"
#include<iostream>
using namespace std;
class DSCaSy{
private:
	CaSi **dsCaSi;
	int soCaSi;
public:
	DSCaSy();
	~DSCaSy();
	void Nhap();
	void Xuat();
	void LuongMax();
	void LuongTB();
	void ThemCaSi(CaSi* caSy, int viTri);
	void XoaCaSi();
	int LaySoLuongCaSi();
	void TimCaSi();
	void GiamDan();
	void GhiVaoFile();
};

