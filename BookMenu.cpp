#include <iostream>
#include <string.h>

using namespace std;

struct BookInfo {
	char* maSach = new char[7];
	char* tenSach = new char[50];
	char* tacGia = new char[50];
	char* nhaXuatBan = new char[50];
	int giaBan, soTrang, namXuatBan;
};

void nhapThongTinQuyenSach(BookInfo* k) {
	cout << "Dien vao ma sach (toi da 7 ky tu, khong khoang trang): ";
	cin.ignore();
	cin.getline(k->maSach, 99);
	cout << "Dien vao ten sach: ";
	cin.ignore();
	cin.getline(k->tenSach, 99);
	cout << "Dien vao ho ten tac gia: ";
	cin.ignore();
	cin.getline(k->tacGia, 99);
	cout << "Dien vao ten nha xuat ban: ";
	cin.ignore();
	cin.getline(k->nhaXuatBan, 99);
	cout << "Dien vao gia ban (nghin dong): ";
	cin >> k->giaBan;
	cout << "Dien vao so trang: ";
	cin >> k->soTrang;
	cout << "Dien vao nam xuat ban: ";
	cin >> k->namXuatBan;
}

void xuatThongTinQuyenSach(BookInfo* k) {
	cout << "Ma sach: " << k->maSach << endl;
	cout << "Ten sach: " << k->tenSach << endl;
	cout << "Tac gia: " << k->tacGia << endl;
	cout << "Nha xuat ban: " << k->nhaXuatBan << endl;
	cout << "Gia: " << k->giaBan << " nghin dong" << endl;
	cout << "So trang: " << k->soTrang << " trang" << endl;
	cout << "Nam xuat ban: " << k->namXuatBan << endl;
}

void nhapDanhSach(BookInfo*& danhSach, int n) {
	danhSach = new BookInfo[n + 20];
	for (int i = 0; i < n; i++) {
		cout << "- STT " << i + 1 << " -" << endl;
		nhapThongTinQuyenSach(danhSach + i);
	}
}

void xuatDanhSach(BookInfo* danhSach, int n) {
	for (int i = 0; i < n; i++) {
		cout << "- STT " << i + 1 << " -" << endl;
		xuatThongTinQuyenSach(danhSach + i);
	}
}

int main() {
	int soLuong, key;
	BookInfo* danhSach = new BookInfo[50];

	cout << "MENU QUAN LY DANH SACH CAC QUYEN SACH\n";
	cout << "---\n";
	cout << "1. Nhap danh sach cac quyen sach.\n";
	cout << "2. Xuat danh sach ra man hinh.\n";
	cout << "3. Sap xep danh sach theo thu tu tang dan cua nam xuat ban.\n";
	cout << "4. Tim quyen sach it hon k trang co gia ban cao nhat.\n";
	cout << "5. Them 1 quyen sach vao danh sach.\n";
	cout << "6. Xoa cac quyen sach co nam xuat ban truoc nam chi dinh.\n";
	cout << "0. Thoat.\n";

	do {
		cout << "\nNhap tuy chon: ";
		cin >> key;
		switch (key) {
		case 1:
			cout << "1. Nhap danh sach.\n";
			cout << "Nhap so luong quyen sach: ";
			cin >> soLuong;
			nhapDanhSach(danhSach, soLuong);
			cout << "Nhap danh sach thanh cong!\n";
			break;
		case 2:
			cout << "2. Xuat danh sach.\n";
			xuatDanhSach(danhSach, soLuong);
			break;
		case 3:
			cout << "3. Sap xep danh sach.\n";

			break;
		case 4:
			cout << "4. Tim sach.\n";
			break;
		case 5:
			cout << "5. Them 1 quyen sach.\n";
			break;
		case 6:
			cout << "6. Xoa sach.\n";
			break;
		case 0:
			cout << "Ban da chon thoat chuong trinh.\n";
			break;
		default:
			cout << "Tuy chon khong hop le!\n";
			break;
		}
	} while (key != 0);

	delete[] danhSach;

	return 0;
}