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
	cin.getline(k->tenSach, 99);
	cout << "Dien vao ho ten tac gia: ";
	cin.getline(k->tacGia, 99);
	cout << "Dien vao ten nha xuat ban: ";
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

void sapXepTheoNXB(BookInfo* k, int n) {
	BookInfo tmp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (k[i].namXuatBan > k[j].namXuatBan) {
				tmp = k[i];
				k[i] = k[j];
				k[j] = tmp;
			}
		}
	}
}

void timSach(BookInfo* danhSach, int k, int n) {
	int j = 0, max = 0, found1 = 0;
	//tao mang chua cac quyen sach co it hon k trang
	BookInfo* tmp = new BookInfo[n + 10];
	for (int i = 0; i < n; i++) {
		if (danhSach[i].soTrang < k) {
			tmp[j] = danhSach[i];
			j++;
			found1++;
		}
	}
	//xet coi co sach nao thoa dieu kien it hon k trang khong
	if (found1 == 0) {
		cout << "Khong co quyen sach nao co so trang it hon " << k << " trang.\n";
	}
	else {
		//tao mang chua cac quyen sach co gia ban cao nhat
		BookInfo* maxPrice = new BookInfo[j + 10];
		int m = 0, mark;
		for (int i = 0; i < j; i++) {
			if (tmp[i].giaBan > max) {
				maxPrice[m] = tmp[i];
				max = tmp[i].giaBan;
				mark = i;
			}
		}
		m++;
		//xet xem con sach nao co cung gia ban cao nhat khong
		for (int i = mark + 1; i < j; i++) {
			if (tmp[i].giaBan = max) {
				maxPrice[m] = tmp[i];
				m++;
			}
		}
		xuatDanhSach(maxPrice, m);
	}
}

void themSach(BookInfo*& danhSach, int n) {
	int k;
	//tao mang chua thong tin cua quyen sach can them vao
	BookInfo* ak = new BookInfo[1];

	cout << "Nhap vi tri can them: ";
	cin >> k;
	if (k < 1 || k > (n + 1)) {
		do {
			cout << "Vi tri khong hop le! Vui long nhap lai.\n";
			cout << "Nhap vi tri can them: ";
			cin >> k;
		} while (k < 1 || k > (n + 1));
	}
	k--;
	cout << "Dien thong tin cua quyen sach duoc them." << endl;
	nhapThongTinQuyenSach(ak + 0);

	//copy tu dau den danhSach[k-1]
	n++;
	BookInfo* danhSach02 = new BookInfo[n + 20];
	for (int i = 0; i < k; i++) {
		danhSach02[i] = danhSach[i];
	}
	danhSach02[k] = ak[0];
	//copy phan con lai
	for (int i = k + 1; i < n + 1; i++) {
		danhSach02[i] = danhSach[i - 1];
	}
	//cap phat dong lai
	delete[] danhSach;
	danhSach = new BookInfo[n + 20];
	for (int i = 0; i < n; i++) {
		danhSach[i] = danhSach02[i];
	}
}

//ham kiem tra va dem so quyen sach co NXB truoc nam chi dinh
int kiemTraNXB(BookInfo* danhSach, int year, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (danhSach[i].namXuatBan < year) {
			count++;
		}
	}
	return count;
}

int xoaSach(BookInfo*& danhSach, int year, int n) {
	if (kiemTraNXB(danhSach, year, n) == 0) {
		cout << "Khong co quyen sach nao thoa dieu kien.\n";
		return 0;
	}
	else {
		int j = 0;
		//tao mang chua danh sach cac quyen sach co nam xuat ban sau nam chi dinh
		BookInfo* danhSach03 = new BookInfo[n + 20];
		for (int i = 0; i < n; i++) {
			if (danhSach[i].namXuatBan >= year) {
				danhSach03[j] = danhSach[i];
				j++;
			}
		}
		//cap phat dong lai
		delete[] danhSach;
		danhSach = new BookInfo[j + 20];
		for (int i = 0; i < j; i++) {
			danhSach[i] = danhSach03[i];
		}
		return 1;
	}
}

int main() {
	int soLuongSach, key, k, year;
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
			cout << "\n1. Nhap danh sach.\n";
			cout << "Nhap so luong quyen sach: ";
			cin >> soLuongSach;
			nhapDanhSach(danhSach, soLuongSach);
			cout << "Nhap danh sach thanh cong!\n";
			break;
		case 2:
			if (soLuongSach > 0) {
				cout << "\n2. Xuat danh sach.\n";
				xuatDanhSach(danhSach, soLuongSach);
			}
			else {
				cout << "Danh sach trong!\n";
			}
			break;
		case 3:
			if (soLuongSach > 0) {
				cout << "\n3. Sap xep danh sach.\n";
				sapXepTheoNXB(danhSach, soLuongSach);
				xuatDanhSach(danhSach, soLuongSach);
			}
			else {
				cout << "Danh sach trong!\n";
			}
			break;
		case 4:
			if (soLuongSach > 0) {
				cout << "\n4. Tim sach.\n";
				cout << "Nhap k: ";
				cin >> k;
				cout << "Cac quyen sach co it hon " << k << " trang va co gia ban cao nhat:\n";
				timSach(danhSach, k, soLuongSach);
			}
			else {
				cout << "Danh sach trong!\n";
			}
			break;
		case 5:
			if (soLuongSach > 0) {
				cout << "\n5. Them 1 quyen sach.\n";
				themSach(danhSach, soLuongSach);
				soLuongSach++;
			}
			else {
				cout << "Danh sach trong!\n";
			}
			break;
		case 6:
			if (soLuongSach > 0) {
				cout << "\n6. Xoa sach.\n";
				cout << "Nhap vao nam xuat ban: ";
				cin >> year;
				xoaSach(danhSach, year, soLuongSach);
				if (xoaSach(danhSach, year, soLuongSach) == 1) {
					cout << "Cac quyen sach co nam xuat ban truoc " << year << " da duoc xoa thanh cong!\n";
					soLuongSach = soLuongSach - kiemTraNXB(danhSach, year, soLuongSach);
				}
			}
			else {
				cout << "Danh sach trong!\n";
			}
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