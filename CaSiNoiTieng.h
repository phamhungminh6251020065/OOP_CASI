#pragma once
#include"CaSi.h"
#include<iostream>
using namespace std;
class CaSiNoiTieng:public CaSi{
private:
	int SoGameShowThamGia;
public:
	CaSiNoiTieng();
	void Nhap();
	void Xuat();
	float TinhLuong();
};

