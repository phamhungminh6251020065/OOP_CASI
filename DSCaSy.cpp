#include "DSCaSy.h"
#include <fstream>
DSCaSy::DSCaSy() {
	dsCaSi = nullptr;
	soCaSi = 0;
}
DSCaSy::~DSCaSy() {
	if (dsCaSi != nullptr) {
		for (int i = 0; i < soCaSi; i++) {
			delete dsCaSi[i];
		}
		delete[] dsCaSi;
	}	
}
void DSCaSy::Nhap() {
	cout << "\t\tNHAP THONG TIN CA SI " << endl;
	cout << "Nhap so ca si:"; cin >> soCaSi;
	dsCaSi = new CaSi*[soCaSi];
	for (int i = 0; i < soCaSi; i++) {
		cout << "\t\t*************CA_SI***************" << endl;
		cout << "\t\t**          1.Noi tieng        **" << endl;
		cout << "\t\t**          2.Chua noi tieng   **" << endl;
		cout << "\t\t*********************************" << endl;
		int chon;
		cout << "Nhap loai ca si:"; cin >> chon;
		if (chon == 1) {
			dsCaSi[i] = new CaSiNoiTieng();
			dsCaSi[i]->Nhap();
		}
		else if (chon == 2) {
			dsCaSi[i] = new CaSiChuaNoiTieng();
			dsCaSi[i]->Nhap();
		}
		else {
			cout << "Khong hop le";
			i--;
		}
		
	}
}
void DSCaSy::Xuat() {
	cout << "\t\tDANH SACH CA SI " << endl;
	for (int i = 0; i < soCaSi; i++) {
		cout << "Thong tin ca si thu " << i + 1 << endl;
		dsCaSi[i]->Xuat();
		cout << endl;
	}
}
void DSCaSy::LuongMax() {
	CaSi *maxLuong = dsCaSi[0];
	for (int i=0; i < soCaSi; i++) {
		if (dsCaSi[i] > maxLuong) {
			dsCaSi[i] = maxLuong;
		}
	}
	cout << "Thong tin ca si luong cao nhat" << endl;
	maxLuong->Xuat();
}
void DSCaSy::LuongTB() {
	float tongLuong = 0;
	int dem = 0;
	for (int i = 0; i < soCaSi; i++) {
		tongLuong += dsCaSi[i]->TinhLuong();
	}
	float luongTB = tongLuong / soCaSi;
	for (int i = 0; i < soCaSi; i++) {
		if (dsCaSi[i]->TinhLuong() > luongTB) {
			dem++;
		}
	}
	cout << "Luong TB la:" << luongTB << endl;
	cout << "So ca sy co luong cao hon trung binh la: " << dem << endl;
}
/*void DSCaSy::ThemCaSi() {
	int ViTri;
	CaSi *cs;
	CaSi** them = new CaSi*[soCaSi + 1];
	for (int i = 0; i < soCaSi; i++) {
		them[i] = dsCaSi[i];
	}
	delete[] dsCaSi;
	dsCaSi = them;
	soCaSi++;
	int vt, type;
	cout << "So luong ca si hien co trong danh sach: " << LaySoLuongCaSi() << endl;
	cout << "Nhap vao vi tri can them trong danh sach: ";

	do {
		cin >> vt;
		if (vt < 0 || vt > LaySoLuongCaSi()) {
			cout << "Vi tri nhap vao khong hop le. Vui long nhap lai! ";
		}
	} while (vt < 0 || vt > LaySoLuongCaSi());

	cout << "\t\t*************CA_SI***************" << endl;
	cout << "\t\t**          1.Noi tieng        **" << endl;
	cout << "\t\t**          2.Chua noi tieng   **" << endl;
	cout << "\t\t*********************************" << endl;
	cout << "Chon loai ca si can them:"; cin >> type;
	if (type == 1) {
		cs = new CaSiNoiTieng();
		cs->Nhap();
	}
	else if (type == 2) {
		cs = new CaSiChuaNoiTieng();
		cs->Nhap();
	}
	else {
		cout << "Lua chon khong hop le\n";
		return;
	}

	delete[] dsCaSi;
	dsCaSi = them;
	soCaSi++;
}*/
void DSCaSy::ThemCaSi(CaSi* caSy, int viTri) {
	CaSi** temp = new CaSi*[soCaSi + 1];
	for (int i = 0; i < soCaSi + 1; i++) {
		if (i < viTri) {
			temp[i] = dsCaSi[i];
		}
		else if (i == viTri) {
			temp[i] = caSy;
		}
		else {
			temp[i] = dsCaSi[i - 1];
		}
	}
	delete[] dsCaSi;
	dsCaSi = temp;
	soCaSi++;
}

void DSCaSy::XoaCaSi() {
	/*// Neu pos <= 0 => Xoa dau
	if (ViTri < 0) {
		ViTri = 0;
	}
	// Neu pos >= n => Xoa cuoi
	else if (ViTri >= soCaSi) {
		ViTri = soCaSi - 1;
	}
	delete dsCaSi[ViTri];
	// Dich chuyen mang
	for (int i = ViTri; i < soCaSi - 1; i++) {
		dsCaSi[i] = dsCaSi[i + 1];
	}
	// Giam so luong phan tu sau khi xoa.
	--soCaSi;*/
	////////////////////////
	cout << "So luong ca si hien co trong danh sach: " << LaySoLuongCaSi() << endl;
	int ViTri;
	cout << "Nhap vao vi tri can xoa trong danh sach: ";

	// do-while loop để ràng buộc giá trị vt
	do {
		cin >> ViTri;
		if (ViTri < 0 || ViTri > LaySoLuongCaSi()) {
			cout << "Vi tri nhap vao khong hop le. Vui long nhap lai! ";
		}
	} while (ViTri < 0 || ViTri >LaySoLuongCaSi());
	delete dsCaSi[ViTri];
	// Dich chuyen mang
	for (int i = ViTri; i < soCaSi - 1; i++) {
		dsCaSi[i] = dsCaSi[i + 1];
	}
	// Giam so luong phan tu sau khi xoa.
	--soCaSi; 


}
int DSCaSy::LaySoLuongCaSi() {
	return soCaSi;
}
void DSCaSy::TimCaSi() {
	string macasi;
	cout << "\nNhap vao ma ca si can tim: ";
	cin.ignore();
	getline(cin, macasi);
	bool timThay = false;
	for (int i = 0; i < soCaSi; i++) {
		if (dsCaSi[i]->GetMaCaSi() == macasi) {
			dsCaSi[i]->Xuat();
			timThay = true;
		}
	}
	if (!timThay) {
		cout << "Khong tim thay ca sy co ma " << macasi << "da nhap vao !" << endl;
	}
}
void DSCaSy::GiamDan() {
	for (int i = 0; i < soCaSi - 1; i++) {
		for (int j = i + 1; j < soCaSi; j++) {
			if (dsCaSi[i] > dsCaSi[j]) {
				swap(dsCaSi[i], dsCaSi[j]);
			}
		}
	}
	cout << "\t\tDANH SACH CA SI GIAM DAN THEO LUONG" << endl;
	Xuat();
}
void DSCaSy::GhiVaoFile() {
	// Mở file để ghi
	ofstream outfile("danhsach.txt");
	// Chuyển đầu ra của console vào file
	streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(outfile.rdbuf());
	// In ra kết quả trên console để chuyển vào file
	for (int i = 0; i < soCaSi; i++) {
		cout << "\n-------\n";
		cout << "\nThong tin ca si thu : " << i + 1 << endl;
		dsCaSi[i]->Xuat();
	}
	// Đóng file sau khi ghi
	outfile.close();
	// Chuyển lại đầu ra mặc định của console
	cout.rdbuf(coutbuf);
}