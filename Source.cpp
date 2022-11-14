#pragma once
#include<string>
#include<conio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include "HamDoHoa.h"
using namespace std;
#pragma warning(disable:4996)

const int MACDINH = 0;
const int MD_TTCB = 1;
const int MAX_MB = 300;
const int MAX_VE = 400;
#define Width_Console 1200
#define Height_Console 800
#define Font_Color 1

#pragma region KHAI BÁO:

struct MAYBAY
{
	string soHieu_MB; // tối đa 15 kí tự
	string Loai_MB;// tối đa 40 kí tự
	int soCho_MB;
	int so_lan_bay = 0;
};

struct DANHSACHMAYBAY {
	MAYBAY* data[MAX_MB];
	int sl_mb = MACDINH;
};

struct DATETIME {
	int ngay;
	int thang;
	int nam;
	int gio;
	int phut;
};

struct HANHKHACH
{
	string CMND;// tối đa 15 kí tự và chỉ chứa kí tự số
	string Ho;// tối đa 20 kí tự và chỉ chứa kí tự từ a-z & A - Z
	string Ten;// tối đa 20 kí tự và chỉ chứa kí tự từ a-z & A - Z
	bool Phai; //true là Nam - false là Nữ
};

struct nodeKH {
	HANHKHACH data;
	nodeKH* pLeft;
	nodeKH* pRight;
};
typedef nodeKH* TREE;

struct VE {
	int vi_tri_ghe;//key
	string CMND;// tối đa 15 kí tự và chỉ chứa kí tự số
	bool tt = false;// true la co nguoi dat, false la ve bi huy
//	string Ma_CB;
};

struct DANHSACHVE
{
	VE data[MAX_VE];
	int sl_ve = MACDINH;
};

struct CHUYENBAY
{
	string Ma_CB; // tối đa 15 kí tự
	DATETIME ngayGioXuatPhat;
	string noiDen_CB; // tối đa 15 kí tự
	int trangThai_CB; // 0 huy chuyen, 1 con ve, 2 het ve, 3 hoan tat
	string soHieu_MB; // tối đa 15 kí tự

};

struct nodeCB {
	CHUYENBAY data;
	nodeCB* pNext;
	DANHSACHVE dsve;
	//int sl_cb = MACDINH;
};

#pragma endregion

#pragma region Prototype

//Doc,ghi file
void Doc_1_Khach_Hang(HANHKHACH& kh, ifstream& filein);
void Doc_File_Khach_Hang(TREE& t, ifstream& filein);
void Ghi_1_Khach_Hang(HANHKHACH kh, ofstream& fileout);
void Ghi_full_KH(TREE t, ofstream& fileout);
void Ghi_File_Khach_Hang(TREE t, ofstream& fileout);

void Doc_File_May_Bay(DANHSACHMAYBAY& dsmb, ifstream& filein);
void Ghi_File_May_Bay(DANHSACHMAYBAY dsmb, ofstream& fileout);

void Doc_File_Chuyen_Bay(ifstream& filein, nodeCB*& dscb, DANHSACHMAYBAY dsmb);
void Ghi_File_Chuyen_Bay(nodeCB* dscb, ofstream& fileout);


//Chuoi
void DeleteFirstSpace(string& str);
void DeleteSpaceBetweenWords(string& str);
void DeleteLastSpace(string& str);
void UpperFirstChar(string& str);
void ChuanHoaChuoi(string& str);
void ChuanHoa_ID(string& str);
bool Check_Length(string str, int limit_length);
string Check_ID(int limit_length);
string CheckString(int limit_length);
bool Check_Digit(string chuoi_so);
string Check_NumberInput(int limit_length);
string GetName(string s);
string GetHo(string s);
string ChuanSo(int n);

//Thoi Gian
string GetCurrentDate();
string ChuanDate(int x);
int GetCurrentDay();
int GetCurrentMonth();
int GetCurrentYear();
int GetCurrentHour();
int GetCurrentMinute();
int nhuan(int year);
int songaytrongthang(int month, int year);
int TongSoNgay(int month, int year);
int Check_Valid_Date(string date);
bool Check_Valid_Time(string time);
void Check_TTCB_RealTime(nodeCB*& dscb);

//May Bay
string Check_LoaiMayBay(int limit_length);
int SearchMayBay(DANHSACHMAYBAY& dsmb, string x);

void Xuat_MB(DANHSACHMAYBAY dsmb);
void DuyetMB(DANHSACHMAYBAY dsmb, int& index);
void SwapHaiMayBay(MAYBAY*& a, MAYBAY*& b);
void SapXepTheoSoLuotBayGiamDan(DANHSACHMAYBAY& dsmb);
void ThongKeSoLuotBayTheoMayBay(DANHSACHMAYBAY dsmb);
void Xuat_Danh_Sach_May_Bay(vector<MAYBAY> dsmb);

//Chuyen Bay
void ThemCuoi(nodeCB*& pHead, nodeCB* p);
nodeCB* SearchChuyenBayTheoSoHieuMayBay(nodeCB* pHead, string SoHieuMB);
nodeCB* SearchChuyenBay(nodeCB* pHead, string x);
void ThemChuyenBay(nodeCB*& dscb, CHUYENBAY& cb, DANHSACHMAYBAY& dsmb);
DATETIME NhapNgayGio();
void HuyChuyenBay(nodeCB*& dscb, string MaChuyenBay, DANHSACHMAYBAY& dsmb);
void HieuChinhNgayGio(nodeCB*& dscb, string MaChuyenBay);

void DuyetCB(nodeCB* dscb, int& index);
void Xuat_CB(nodeCB* dscb);
void DuyetMB_ThemCB(DANHSACHMAYBAY dsmb, int& index);
void Xuat_MB_ThemCB(DANHSACHMAYBAY dsmb);
int CountSoLuongChuyenBay(nodeCB* pHead);

//Ve
void KhoiTaoVe(VE& ve, int vitri);
void DuyetVe(DANHSACHVE dsv, int& index);
void Xuat_Ve(nodeCB* dscb);
void KhoiTaoDanhSachVe(DANHSACHMAYBAY dsmb, nodeCB*& cb);
int CountSoVeDaDat(DANHSACHVE dsv);
int DemSoLuongVeConTrong(nodeCB* dscb);

//Khach Hang
nodeCB* KhoiTaoNode(CHUYENBAY x);
bool Check_GioiTinh(int limit_length);
void Xuat_DSKH(TREE t);
string CheckGioBay();
string CheckNgayBay();
nodeKH* SearchKhachHang(TREE t, string x);
void XuatHanhKhach(HANHKHACH x, int& row);
int CountSoLuongKhachHang(TREE t);
void DuyetDSKH(TREE t, int& row);
void Them(TREE& t, HANHKHACH x);
void NhapKhachHang(TREE& t, HANHKHACH& x);
void Xuat_Danh_Sach_Khach_Hang(vector<HANHKHACH> dskh);

//Menu
void Menu_Chinh(DANHSACHMAYBAY& dsmb, nodeCB*& dscb, TREE& dskh, ifstream& filein, ofstream& fileout);

void Menu_MayBay(DANHSACHMAYBAY& dsmb, nodeCB* dscb, ifstream& filein);
void ThemMayBay(DANHSACHMAYBAY& dsmb, MAYBAY& x);
void HieuChinhMayBay(DANHSACHMAYBAY& dsmb, nodeCB* dscb);
void XoaMayBay(DANHSACHMAYBAY& dsmb, nodeCB* dscb);


void Menu_ChuyenBay(nodeCB*& dscb, DANHSACHMAYBAY& dsmb, ifstream& filein);
void UI_HieuChinhChuyenBay(nodeCB*& dscb);
void UI_HuyChuyenBay(nodeCB*& dscb, DANHSACHMAYBAY& dsmb);

void Menu_KhachHang(TREE& dskh, ifstream& filein);

void Menu_Ve(nodeCB*& dscb, TREE& dskh, ifstream& filein);
void DAT_VE(nodeCB*& dscb, TREE& dskh);
void HUY_VE(nodeCB*& dscb);
void InDanhSachVeConTrongTheoMaCB(nodeCB* dscb);

void InDanhSachHanhKhachTheoChuyenBay(nodeCB* dscb, TREE dskh);
void InDanhSachChuyenBayTheoNgayVaNoiDen(nodeCB* dscb);

// Giải phóng bộ nhớ
void ClearListMayBay(DANHSACHMAYBAY& dsmb);
void ClearListChuyenBay(nodeCB*& pHead);
void ClearListKhachHang(TREE& t);


#pragma endregion

int main()
{
	system("color 70");
	ResizeConsole(Width_Console, Height_Console);

	DANHSACHMAYBAY dsmb;
	nodeCB* dscb = NULL;
	TREE dskh = NULL;

	ofstream fileout;
	ifstream filein;

	filein.open("DSMAYBAY.txt", ios_base::in);
	Doc_File_May_Bay(dsmb, filein);
	filein.close();

	filein.open("DSCHUYENBAY.txt", ios_base::in);
	Doc_File_Chuyen_Bay(filein, dscb, dsmb);
	filein.close();

	filein.open("DSKHACHHANG.txt", ios_base::in);
	Doc_File_Khach_Hang(dskh, filein);
	filein.close();

	Check_TTCB_RealTime(dscb);

	Menu_Chinh(dsmb, dscb, dskh, filein, fileout);

	//_getch();
}

void Menu_Chinh(DANHSACHMAYBAY& dsmb, nodeCB*& dscb, TREE& dskh, ifstream& filein, ofstream& fileout)
{
	int choice;
	string c;
	do
	{
		XoaManHinh();
		Draw_Logo(filein, "logo_MainMenu.txt", 25);
		cout << "\n\t\t\t1. QUAN LY MAY BAY";
		cout << "\n\t\t\t2. QUAN LY CHUYEN BAY";
		cout << "\n\t\t\t3. QUAN LY KHACH HANG";
		cout << "\n\t\t\t4. QUAN LY VE MAY BAY";
		cout << "\n\t\t\t5. IN DANH SACH HANH KHACH THUOC 1 CHUYEN BAY";
		cout << "\n\t\t\t6. IN DANH SACH CHUYEN BAY THEO NGAY VA NOI DEN";
		cout << "\n\t\t\t7. IN VE CON TRONG CUA MOT CHUYEN BAY";
		cout << "\n\t\t\t8. THONG KE SO LUOT THUC HIEN CHUYEN BAY CUA TUNG MAY BAY";
		cout << "\n\t\t\t9. KET THUC CHUONG TRINH";
		cout << "\n\n\tNhap lua chon cua ban: ";

		int col = whereX(), row = whereY();

		//Bang chu y chinh
		draw_column(9, 13, 97);
		draw_column(9, 13, 139);
		draw_line(98, 138, 8, "_");
		gotoXY(115, 9);
		cout << "CHU Y";
		draw_line(98, 138, 10, "_");
		gotoXY(98, 11);
		cout << "- Nhap lua chon cua ban sau do nhan Enter";
		gotoXY(98, 12);
		cout << "- Chi nhap so tu 1-9";
		draw_line(98, 138, 13, "_");

		gotoXY(col, row);

		c = Check_NumberInput(1);
		if (c == "") break;
		choice = stoi(c);
		if (choice <= 0 || choice > 9)
		{
			BaoLoi("Lua chon vua nhap khong dung, vui long kiem tra lai");
		}

		switch (choice)
		{
		case 1:
		{
			XoaManHinh();
			Menu_MayBay(dsmb, dscb, filein);
			break;
		}
		case 2:
		{
			XoaManHinh();
			Menu_ChuyenBay(dscb, dsmb, filein);
			break;
		}
		case 3:
		{
			XoaManHinh();
			Menu_KhachHang(dskh, filein);
			break;
		}
		case 4:
		{
			XoaManHinh();
			Menu_Ve(dscb, dskh, filein);
			break;
		}
		case 5:
		{
			XoaManHinh();
			InDanhSachHanhKhachTheoChuyenBay(dscb, dskh);
			DungManHinh();
			break;
		}
		case 6:
		{
			XoaManHinh();

			InDanhSachChuyenBayTheoNgayVaNoiDen(dscb);
			DungManHinh();
			break;
		}
		case 7:
		{
			XoaManHinh();
			InDanhSachVeConTrongTheoMaCB(dscb);
			DungManHinh();
			break;
		}
		case 8:
		{
			XoaManHinh();
			ThongKeSoLuotBayTheoMayBay(dsmb);
			DungManHinh();
			break;
		}
		}
	} while (choice != 9);

	Ghi_File_Chuyen_Bay(dscb, fileout);
	fileout.open("DSKHACHHANG.txt", ios_base::out);
	Ghi_full_KH(dskh, fileout);
	fileout.close();
	Ghi_File_May_Bay(dsmb, fileout);
	BaoLoi("Da Luu Du Lieu Thanh Cong");

	ClearListMayBay(dsmb);
	ClearListChuyenBay(dscb);
	ClearListKhachHang(dskh);
}

#pragma region Xử lý DateTime

void Check_TTCB_RealTime(nodeCB*& dscb)
{
	string date = "";
	string time = "";
	for (nodeCB* k = dscb; k != NULL; k = k->pNext)
	{
		date = ChuanDate(k->data.ngayGioXuatPhat.ngay) + "/" + ChuanDate(k->data.ngayGioXuatPhat.thang) + "/" + ChuanDate(k->data.ngayGioXuatPhat.nam);
		if (Check_Valid_Date(date) <= 0)
		{
			time = ChuanDate(k->data.ngayGioXuatPhat.gio) + ":" + ChuanDate(k->data.ngayGioXuatPhat.phut);
			if (!Check_Valid_Time(time))
			{
				k->data.trangThai_CB = 3;
			}
		}
	}
}


string ChuanDate(int x)
{
	ostringstream convert;
	convert << x;
	if (x < 10)
	{
		return "0" + convert.str();
	}
	return convert.str();
}

string GetCurrentDate()
{
	time_t now = time(0);
	// convert now to string form
	string date_time = ctime(&now);
	return date_time;
}
int GetCurrentDay()
{
	string tam = GetCurrentDate();
	tam = tam.substr(8, 2);
	int result = stoi(tam);
	return result;
}
int GetCurrentMonth()
{
	int result = 0;
	string tam = GetCurrentDate();
	tam = tam.substr(4, 3);
	if (tam == "Jan")
	{
		result = 1;
	}
	else if (tam == "Feb")
	{
		result = 2;
	}
	else if (tam == "Mar")
	{
		result = 3;
	}
	else if (tam == "Apr")
	{
		result = 4;
	}
	else if (tam == "May")
	{
		result = 5;
	}
	else if (tam == "Jun")
	{
		result = 6;
	}
	else if (tam == "Jul")
	{
		result = 7;
	}
	else if (tam == "Aug")
	{
		result = 8;
	}
	else if (tam == "Sep")
	{
		result = 9;
	}
	else if (tam == "Oct")
	{
		result = 10;
	}
	else if (tam == "Nov")
	{
		result = 11;
	}
	else if (tam == "Dec")
	{
		result = 12;
	}
	return result;
}

int GetCurrentYear()
{
	string tam = GetCurrentDate();
	tam = tam.substr(20, 4);
	int result = stoi(tam);
	return result;
}

int GetCurrentHour()
{
	string tam = GetCurrentDate();
	tam = tam.substr(11, 2);
	int result = stoi(tam);
	return result;
}
int GetCurrentMinute()
{
	string tam = GetCurrentDate();
	tam = tam.substr(14, 2);
	int result = stoi(tam);
	return result;
}

int nhuan(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int songaytrongthang(int month, int year)
{
	switch (month)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
	{
		return 31;
		break;
	}
	case 2:
	{
		if (nhuan(year))
		{
			return 29;
		}
		return 28;
	}
	case 4:case 6:case 9:case 11:
	{
		return 30;
	}
	}
}

int TongSoNgay(int month, int year)
{
	int tong_day = 0;
	for (int i = 1; i <= month; i++)
	{
		tong_day = tong_day + songaytrongthang(i, year);
	}
	return tong_day;
}

int Check_Valid_Date(string date)
{

	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6, 4));


	if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
	{
		if (day > 30)
		{
			return -1;
		}
	}
	else if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			if (day > 29)
			{
				return -1;

			}
		}
		else
		{
			if (day > 28)
			{
				return -1;
			}
		}
	}

	int c_day = GetCurrentDay();
	int c_month = GetCurrentMonth();
	int c_year = GetCurrentYear();

	int tong_ngay_nhap_vao = (TongSoNgay(month, year) + day) + year * 365;
	int tong_ngay_hien_tai = (TongSoNgay(c_month, c_year) + c_day) + c_year * 365;

	if (tong_ngay_nhap_vao < tong_ngay_hien_tai)
	{
		return -1;
	}
	if (tong_ngay_nhap_vao == tong_ngay_hien_tai)
	{
		return 0;
	}
	return 1;

}

bool Check_Valid_Time(string time)
{
	int hour = stoi(time.substr(0, 2));
	int minute = stoi(time.substr(3, 2));
	int c_hour = GetCurrentHour();
	int c_minute = GetCurrentMinute();

	int time1 = minute + hour * 60;
	int c_time = c_minute + c_hour * 60;

	if (time1 < c_time)
	{
		return false;
	}
	return true;
}
#pragma endregion

#pragma region Đọc - Ghi File
void Doc_1_Khach_Hang(HANHKHACH& kh, ifstream& filein)
{
	string c;
	getline(filein, kh.CMND, ','); // ĐỌC dữ liệu đến dấu phẩy thì dừng
	getline(filein, kh.Ho, ',');
	getline(filein, kh.Ten, ',');
	getline(filein, c);
	if (c == "true")
	{
		kh.Phai = true;
	}
	else if (c == "false")
	{
		kh.Phai = false;
	}
}

void Doc_File_Khach_Hang(TREE& t, ifstream& filein)
{
	HANHKHACH kh;
	int n;
	string c;
	filein >> n;
	getline(filein, c);
	for (int i = 0; i < n; i++)
	{
		Doc_1_Khach_Hang(kh, filein);
		Them(t, kh);
	}
}

void Ghi_1_Khach_Hang(HANHKHACH kh, ofstream& fileout)
{
	string temp;
	if (kh.Phai == true)
	{
		temp = "true";
	}
	else
	{
		temp = "false";
	}

	fileout << kh.CMND << "," << kh.Ho << "," << kh.Ten << "," << temp << endl;
}

void Ghi_full_KH(TREE t, ofstream& fileout) {
	fileout << CountSoLuongKhachHang(t) << endl;
	Ghi_File_Khach_Hang(t, fileout);
}

void Ghi_File_Khach_Hang(TREE t, ofstream& fileout)
{
	if (t != NULL)
	{
		Ghi_1_Khach_Hang(t->data, fileout);
		Ghi_File_Khach_Hang(t->pLeft, fileout);
		Ghi_File_Khach_Hang(t->pRight, fileout);
	}
}

void Doc_File_May_Bay(DANHSACHMAYBAY& dsmb, ifstream& filein)
{
	MAYBAY mb;
	string c;
	filein >> dsmb.sl_mb;
	getline(filein, c); //đọc kí tự '\n'
	for (int i = 0; i < dsmb.sl_mb; i++)
	{
		getline(filein, mb.soHieu_MB, ','); // ĐỌC dữ liệu đến dấu phẩy thì dừng
		getline(filein, mb.Loai_MB, ',');
		getline(filein, c, ',');
		mb.soCho_MB = stoi(c);
		getline(filein, c);
		mb.so_lan_bay = stoi(c);

		dsmb.data[i] = new MAYBAY;
		*dsmb.data[i] = mb;
	}
}

void Ghi_File_May_Bay(DANHSACHMAYBAY dsmb, ofstream& fileout)
{
	fileout.open("DSMAYBAY.txt", ios_base::out);
	fileout << dsmb.sl_mb << endl;

	for (int i = 0; i < dsmb.sl_mb; i++)
	{
		fileout << dsmb.data[i]->soHieu_MB << "," << dsmb.data[i]->Loai_MB << "," << dsmb.data[i]->soCho_MB << "," << dsmb.data[i]->so_lan_bay << endl;
	}

	fileout.close();
}

void Doc_File_Chuyen_Bay(ifstream& filein, nodeCB*& dscb, DANHSACHMAYBAY dsmb)
{
	CHUYENBAY cb;
	int n;
	filein >> n;
	string c;
	int tam;
	getline(filein, c); //đọc kí tự '\n'
	for (int i = 1; i <= n; i++)
	{
		getline(filein, c, ',');
		tam = stoi(c);
		getline(filein, cb.Ma_CB, ',');
		getline(filein, cb.noiDen_CB, ',');
		getline(filein, cb.soHieu_MB, ',');
		getline(filein, c, ',');
		cb.trangThai_CB = stoi(c);
		getline(filein, c, ',');
		cb.ngayGioXuatPhat.gio = stoi(c);
		getline(filein, c, ',');
		cb.ngayGioXuatPhat.phut = stoi(c);
		getline(filein, c, ',');
		cb.ngayGioXuatPhat.ngay = stoi(c);
		getline(filein, c, ',');
		cb.ngayGioXuatPhat.thang = stoi(c);
		getline(filein, c);
		cb.ngayGioXuatPhat.nam = stoi(c);

		nodeCB* p = KhoiTaoNode(cb);
		KhoiTaoDanhSachVe(dsmb, p);


		for (int j = 0; j < tam; j++)
		{
			string cmnd_temp;
			string vi_tri_ghe_temp;
			getline(filein, cmnd_temp, ',');
			getline(filein, vi_tri_ghe_temp);
			int vtt_temp = stoi(vi_tri_ghe_temp);
			p->dsve.data[vtt_temp - 1].vi_tri_ghe = vtt_temp;
			p->dsve.data[vtt_temp - 1].CMND = cmnd_temp;
			p->dsve.data[vtt_temp - 1].tt = true;
		}

		ThemCuoi(dscb, p);
	}
}

int CountSoLuongChuyenBay(nodeCB* pHead)
{
	int count = 0;
	for (nodeCB* k = pHead; k != NULL; k = k->pNext)
	{
		count++;
	}

	return count;
}

int CountSoVeDaDat(DANHSACHVE dsv)
{
	int count = 0;
	for (int i = 0; i < dsv.sl_ve; i++)
	{
		if (dsv.data[i].tt == true)
		{
			count++;
		}
	}
	return count;
}

void Ghi_File_Chuyen_Bay(nodeCB* dscb, ofstream& fileout)
{
	fileout.open("DSCHUYENBAY.txt", ios_base::out);

	int n = CountSoLuongChuyenBay(dscb);
	fileout << n << endl;
	nodeCB* p = dscb;
	int tam = CountSoVeDaDat(p->dsve);
	for (int i = 0; i < n; i++)
	{
		tam = CountSoVeDaDat(p->dsve);

		fileout << tam << "," << p->data.Ma_CB << "," << p->data.noiDen_CB << "," << p->data.soHieu_MB << "," << p->data.trangThai_CB << "," << p->data.ngayGioXuatPhat.gio << "," << p->data.ngayGioXuatPhat.phut << "," << p->data.ngayGioXuatPhat.ngay << "," << p->data.ngayGioXuatPhat.thang << "," << p->data.ngayGioXuatPhat.nam << endl;

		for (int j = 0; j < p->dsve.sl_ve; j++)
		{
			if (p->dsve.data[j].tt == true)
			{
				fileout << p->dsve.data[j].CMND << "," << p->dsve.data[j].vi_tri_ghe << endl;
			}
		}

		p = p->pNext;
	}

	fileout.close();
}


void Xuat_Danh_Sach_May_Bay(vector<MAYBAY> dsmb)
{
	for (int i = 0; i < dsmb.size(); i++)
	{
		cout << "\n\n\t\t MAY BAY THU " << i + 1;
		cout << "\n\t So Hieu MB: " << dsmb[i].soHieu_MB;
		cout << "\n\t Loai MB: " << dsmb[i].Loai_MB;
		cout << "\n\t So Cho MB: " << dsmb[i].soCho_MB;
		cout << "\n\t So Lan Bay: " << dsmb[i].so_lan_bay;
	}
}

void Xuat_Danh_Sach_Khach_Hang(vector<HANHKHACH> dskh)
{
	for (int i = 0; i < dskh.size(); i++)
	{
		cout << "\n\n\t\t KHACH HANG THU " << i + 1;
		cout << "\n\t So Hieu MB: " << dskh[i].CMND;
		cout << "\n\t Ho: " << dskh[i].Ho;
		cout << "\n\t Ten: " << dskh[i].Ten;
		if (dskh[i].Phai == true)
		{
			cout << "\n\t Phai: " << "Nam";
		}
		else if (dskh[i].Phai == false)
		{
			cout << "\n\t Phai: " << "Nu";
		}
	}
}

#pragma endregion

#pragma region UI Khách Hàng

void Menu_KhachHang(TREE& dskh, ifstream& filein)
{
	int choice;
	string c;
	do
	{
		XoaManHinh();
		Draw_Logo(filein, "logo_QLKH.txt", 10);
		cout << "\n\t\t\t1. THEM KHACH HANG";
		cout << "\n\t\t\t2. XEM DANH SACH KHACH HANG";
		cout << "\n\t\t\t3. TRO VE";
		cout << "\n\n\tNhap lua chon cua ban: ";


		//luu con tro cu
		int col = whereX(), row = whereY();

		//Bang chu y Khach Hang
		draw_column(9, 14, 97);
		draw_column(9, 14, 139);
		draw_line(98, 138, 8, "_");
		gotoXY(108, 9);
		cout << "CHU Y";
		draw_line(98, 138, 10, "_");
		gotoXY(98, 11);
		cout << "- Nhap lua chon cua ban sau do nhan Enter";
		gotoXY(98, 12);
		cout << "- Chi nhap so tu 1-3";
		gotoXY(98, 13);
		cout << "- Nhap 3 hoac nhan ESC de tro lai";
		draw_line(98, 138, 14, "_");

		gotoXY(col, row);

		c = Check_NumberInput(1);
		if (c == "") return;
		choice = stoi(c);
		if (choice <= 0 || choice > 3)
		{
			BaoLoi("Lua chon vua nhap khong dung, vui long kiem tra lai");
		}

		switch (choice)
		{
		case 1:
		{
			XoaManHinh();
			HANHKHACH x;
			Xuat_DSKH(dskh);
			NhapKhachHang(dskh, x);
			break;
		}
		case 2:
		{
			XoaManHinh();
			Xuat_DSKH(dskh);
			DungManHinh();
			break;
		}
		}
	} while (choice != 3);
}

#pragma endregion

#pragma region UI VÉ
void Menu_Ve(nodeCB*& dscb, TREE& dskh, ifstream& filein)
{
	int choice;
	string c;
	do
	{
		XoaManHinh();
		Draw_Logo(filein, "logo_QLVE.txt", 15);
		cout << "\n\t\t\t1. DAT VE";
		cout << "\n\t\t\t2. HUY VE";
		cout << "\n\t\t\t3. XEM DANH SACH VE";
		cout << "\n\t\t\t4. TRO LAI";
		cout << "\n\n\tNhap lua chon cua ban: ";

		//luu con tro cu
		int col = whereX(), row = whereY();

		//Bang chu y Ve
		draw_column(9, 14, 97);
		draw_column(9, 14, 139);
		draw_line(98, 138, 8, "_");
		gotoXY(108, 9);
		cout << "CHU Y";
		draw_line(98, 138, 10, "_");
		gotoXY(98, 11);
		cout << "- Nhap lua chon cua ban sau do nhan Enter";
		gotoXY(98, 12);
		cout << "- Chi nhap so tu 1-4";
		gotoXY(98, 13);
		cout << "- Nhap 4 hoac nhan ESC de tro lai";
		draw_line(98, 138, 14, "_");

		gotoXY(col, row);

		c = Check_NumberInput(1);
		if (c == "") return;
		choice = stoi(c);
		if (choice <= 0 || choice > 4)
		{
			BaoLoi("Lua chon vua nhap khong dung, vui long kiem tra lai");
		}

		switch (choice)
		{
		case 1:
		{
			XoaManHinh();
			Check_TTCB_RealTime(dscb);
			DAT_VE(dscb, dskh);
			break;
		}
		case 2:
		{
			XoaManHinh();
			Check_TTCB_RealTime(dscb);
			HUY_VE(dscb);
			break;
		}
		case 3:
		{
			XoaManHinh();
			Check_TTCB_RealTime(dscb);
			Xuat_CB(dscb);
			cout << "Nhap Ma Chuyen Bay can xem danh sach ve: ";
			string ma_CB = Check_ID(15);
			nodeCB* p = SearchChuyenBay(dscb, ma_CB);
			if (p == NULL)
			{
				BaoLoi("Khong ton tai chuyen bay can xem danh sach ve");
			}
			else
			{
				XoaManHinh();
				Xuat_Ve(p);
			}
			DungManHinh();
			break;
		}
		}
	} while (choice != 4);
}

void DuyetVe(DANHSACHVE dsv, int& index)
{
	int column = 10;
	for (int i = 0; i < dsv.sl_ve; i++)
	{
		if (dsv.data[i].tt == true)
		{
			textbk(4);
			TextColor(15);

		}
		else
		{
			textbk(7);
			TextColor(Font_Color);
		}

		if (column < 64)
		{
			gotoXY(column, 4 + index);
			cout << ChuanSo(dsv.data[i].vi_tri_ghe);
			column += 6;
		}
		else {
			gotoXY(column, 4 + index);
			cout << ChuanSo(dsv.data[i].vi_tri_ghe);
			column = 10;
			index++;
		}
	}
	draw_line(10, 66, 4 + index, "_");
}

void Xuat_Ve(nodeCB* cb)
{

	int numOfrow = 0;
	gotoXY(20, 1);
	cout << "DANH SACH VE TREN CHUYEN BAY " << cb->data.Ma_CB;
	draw_line(10, 66, 0, "_");
	draw_line(10, 66, 2, "_");
	DuyetVe(cb->dsve, numOfrow);
	draw_column(1, 4 + numOfrow, 9);
	draw_column(1, 4 + numOfrow, 67);
	gotoXY(10, numOfrow + 5);
}

#pragma endregion

#pragma region  UI Chuyen Bay

void Menu_ChuyenBay(nodeCB*& dscb, DANHSACHMAYBAY& dsmb, ifstream& filein)
{
	int choice;
	string c;
	do
	{
		XoaManHinh();
		Draw_Logo(filein, "logo_QLCB.txt", 10);
		cout << "\n\t\t\t1. THEM CHUYEN BAY";
		cout << "\n\t\t\t2. HIEU CHINH CHUYEN BAY";
		cout << "\n\t\t\t3. HUY CHUYEN BAY";
		cout << "\n\t\t\t4. XEM DANH SACH CHUYEN BAY";
		cout << "\n\t\t\t5. TRO VE";
		cout << "\n\n\tNhap lua chon cua ban: ";


		//luu con tro cu
		int col = whereX(), row = whereY();

		//Bang chu y Chuyen Bay
		draw_column(9, 14, 97);
		draw_column(9, 14, 139);
		draw_line(98, 138, 8, "_");
		gotoXY(115, 9);
		cout << "CHU Y";
		draw_line(98, 138, 10, "_");
		gotoXY(98, 11);
		cout << "- Nhap lua chon cua ban sau do nhan Enter";
		gotoXY(98, 12);
		cout << "- Chi nhap so tu 1-5";
		gotoXY(98, 13);
		cout << "- Nhap 5 hoac nhan ESC de tro lai";
		draw_line(98, 138, 14, "_");

		gotoXY(col, row);

		c = Check_NumberInput(1);
		if (c == "") return;
		choice = stoi(c);
		if (choice <= 0 || choice > 5)
		{
			BaoLoi("Lua chon vua nhap khong dung, vui long kiem tra lai");
		}

		switch (choice)
		{
		case 1:
		{

			CHUYENBAY x;
			ThemChuyenBay(dscb, x, dsmb);
			//GỌI LẠI HÀM XUÂT MÁY BAY ĐỂ CẬP NHẬT DANH SÁCH VỪA THÊM
			break;
		}
		case 2:
		{
			Check_TTCB_RealTime(dscb);
			UI_HieuChinhChuyenBay(dscb);
			//GỌI LẠI HÀM XUÂT MÁY BAY ĐỂ CẬP NHẬT DANH SÁCH VỪA THÊM
			break;
		}
		case 3:
		{
			Check_TTCB_RealTime(dscb);
			UI_HuyChuyenBay(dscb, dsmb);
			//GỌI LẠI HÀM XUÂT MÁY BAY ĐỂ CẬP NHẬT DANH SÁCH VỪA THÊM
			break;

		}
		case 4:
		{
			XoaManHinh();
			Xuat_CB(dscb);
			DungManHinh();
			break;
		}
		}
	} while (choice != 5);
}

void DuyetCB(nodeCB* dscb, int& index)
{
	for (nodeCB* k = dscb; k != NULL; k = k->pNext)
	{
		gotoXY(10, 5 + index);
		cout << ChuanDate(k->data.ngayGioXuatPhat.gio) << ":" << ChuanDate(k->data.ngayGioXuatPhat.phut) << " " << ChuanDate(k->data.ngayGioXuatPhat.ngay) << "/" << ChuanDate(k->data.ngayGioXuatPhat.thang) << "/" << k->data.ngayGioXuatPhat.nam;

		gotoXY(28, 5 + index);
		cout << k->data.noiDen_CB;

		gotoXY(49, 5 + index);
		cout << k->data.Ma_CB;

		gotoXY(65, 5 + index);
		cout << k->data.soHieu_MB;

		if (k->data.trangThai_CB == 0)
		{
			gotoXY(81, 5 + index);
			cout << "Huy Chuyen";
		}
		else if (k->data.trangThai_CB == 1)
		{
			gotoXY(81, 5 + index);
			cout << "Con Ve";
		}
		else if (k->data.trangThai_CB == 2)
		{
			gotoXY(81, 5 + index);
			cout << "Het Ve";
		}
		else if (k->data.trangThai_CB == 3)
		{
			gotoXY(81, 5 + index);
			cout << "Hoan Thanh";
		}
		index++;
	}
	draw_line(10, 90, 5 + index, "_");
	index++;

}

void Xuat_CB(nodeCB* dscb)
{

	int numOfrow = 0;
	gotoXY(40, 1);
	cout << "DANH SACH CHUYEN BAY";
	draw_line(10, 90, 0, "_");
	draw_line(10, 90, 2, "_");
	draw_line(10, 90, 4, "-");

	gotoXY(12, 3);
	cout << "Thoi Gian Bay";
	gotoXY(34, 3);
	cout << "Noi Den";
	gotoXY(50, 3);
	cout << "Ma Chuyen Bay";
	gotoXY(67, 3);
	cout << "So Hieu MB";
	gotoXY(81, 3);
	cout << "Trang Thai";

	DuyetCB(dscb, numOfrow);

	draw_column(1, 4 + numOfrow, 9);
	draw_column(3, 4 + numOfrow, 27);
	draw_column(3, 4 + numOfrow, 48);
	draw_column(3, 4 + numOfrow, 64);
	draw_column(3, 4 + numOfrow, 80);
	draw_column(1, 4 + numOfrow, 91);

	gotoXY(10, numOfrow + 5);
}

void DuyetMB_ThemCB(DANHSACHMAYBAY dsmb, int& index)
{
	for (int i = 0; i < dsmb.sl_mb; i++)
	{
		gotoXY(94, 5 + index);
		cout << dsmb.data[i]->soHieu_MB;
		index++;
	}
	draw_line(91, 108, 5 + index, "_");
	index++;
}

void Xuat_MB_ThemCB(DANHSACHMAYBAY dsmb)
{
	int numOfrow = 0;
	gotoXY(92, 1);
	cout << "DANH SACH MAY BAY";
	draw_line(91, 108, 0, "_");
	draw_line(91, 108, 2, "_");
	draw_line(91, 108, 4, "-");
	gotoXY(94, 3);
	cout << "So Hieu MB";

	DuyetMB_ThemCB(dsmb, numOfrow);
	draw_column(1, 4 + numOfrow, 91);

	draw_column(1, 4 + numOfrow, 109);
	gotoXY(91, 5 + numOfrow);

}

void ThemChuyenBay(nodeCB*& dscb, CHUYENBAY& cb, DANHSACHMAYBAY& dsmb)
{
Label_MaCB:

	XoaManHinh();
	int index = 1;
	Xuat_MB_ThemCB(dsmb);
	Xuat_CB(dscb);
	int col = 10, row = whereY();
	string tam = "";
	gotoXY(col, row);
	//Nhap Ma chuyen bay
	cout << "MA CHUYEN BAY: ";
	tam = Check_ID(15); //kiem tra ESC
	if (tam == "") return;
	cb.Ma_CB = tam;
	if (SearchChuyenBay(dscb, cb.Ma_CB) != NULL)
	{
		BaoLoi("Ma Chuyen Bay da ton tai");
		gotoXY(col, row);
		clreol();
		goto Label_MaCB;
	}
	row++;

	//Nhap Ngay gio Xuat Phat
	string date = "", time = "";
	DATETIME result;
Label_Date:
	gotoXY(col, row);
	cout << "NGAY XUAT PHAT(dd/mm/yyyy): ";
	date = CheckNgayBay();
	if (date == "") return;
	if (Check_Valid_Date(date) == -1)
	{
		BaoLoi("Ngay Xuat Phat khong hop le");
		//gotoXY(col, row);
		//clreol();
		del_row();
		goto Label_Date;
	}
	row++;

label_time:
	gotoXY(col, row);
	if (Check_Valid_Date(date) > 0)
	{
		cout << "GIO XUAT PHAT(hh:mm): ";
		time = CheckGioBay();
		if (time == "") return;
	}
	else if (Check_Valid_Date(date) == 0)
	{
	
		cout << "GIO XUAT PHAT(hh:mm): ";
		time = CheckGioBay();
		if (time == "") return;
		if (!Check_Valid_Time(time))
		{
			BaoLoi("Thoi Gian nhap vao khong hop le");
			//gotoXY(col, row);
			//clreol();
			del_row();
			goto label_time;
		}
	}

	result.nam = stoi(date.substr(6, 4));
	result.thang = stoi(date.substr(3, 2));
	result.ngay = stoi(date.substr(0, 2));
	result.gio = stoi(time.substr(0, 2));
	result.phut = stoi(time.substr(3, 2));
	cb.ngayGioXuatPhat = result;
	row++;

	//Nhap Noi den
	gotoXY(col, row);
	cout << "NOI DEN: ";
	tam = CheckString(15);
	if (tam == "") return;
	cb.noiDen_CB = tam;
	row++;

	//Dat trang thai chuyen bay
	cb.trangThai_CB = MD_TTCB;

	//Nhap so Hieu May Bay
Nhap_So_Hieu_MB:
	gotoXY(col, row);
	cout << "SO HIEU MAY BAY: ";
	tam = Check_ID(15); //kiem tra ESC
	if (tam == "") return;
	cb.soHieu_MB = tam;
	Check_TTCB_RealTime(dscb);
	int i = SearchMayBay(dsmb, cb.soHieu_MB);
	if (i == -1)
	{
		BaoLoi("Khong tim thay So Hieu May Bay");
		//gotoXY(col, row);
		//clreol();
		del_row();
		goto Nhap_So_Hieu_MB;
	}
	else
	{
		for (nodeCB* k = dscb; k != NULL; k = k->pNext)
		{
			if (k->data.trangThai_CB != 0 && k->data.trangThai_CB != 3 && k->data.soHieu_MB == cb.soHieu_MB)
			{
				BaoLoi("Khong the tao chuyen bay tren may bay nay");
				gotoXY(col, row);
				clreol();
				goto Nhap_So_Hieu_MB;
			}
		}
	}

	nodeCB* p = KhoiTaoNode(cb);
	KhoiTaoDanhSachVe(dsmb, p);
	ThemCuoi(dscb, p);

	dsmb.data[i]->so_lan_bay++;
}

void UI_HieuChinhChuyenBay(nodeCB*& dscb)
{
KIEM_TRA_MA_CB:
	XoaManHinh();
	Xuat_CB(dscb);
	string Ma_CB = "";
	int col = whereX(), row = whereY();
	//gotoXY(col, row);

	cout << "MA CHUYEN BAY: ";
	Ma_CB = Check_ID(15);
	if (Ma_CB == "") return;
	nodeCB* p = SearchChuyenBay(dscb, Ma_CB);
	if (p == NULL)
	{
		BaoLoi("KHONG TIM THAY MA CHUYEN BAY CAN HIEU CHINH NGAY GIO");
		//gotoXY(col, row);
		//clreol();
		del_row();
		goto KIEM_TRA_MA_CB;
	}
	else
	{
		if (p->data.trangThai_CB == 3 || p->data.trangThai_CB == 0)
		{
			BaoLoi("CHUYEN BAY KHONG THE HIEU CHINH");
			//gotoXY(col, row);
			//clreol();
			del_row();
			goto KIEM_TRA_MA_CB;
		}
	}
	row++;

	//Nhap Ngay gio Xuat Phat
	string date = "", time = "";
	DATETIME result;
Label_Date:
	gotoXY(col, row);
	cout << "NGAY XUAT PHAT(dd/mm/yyyy): ";
	date = CheckNgayBay();
	if (date == "") return;
	if (Check_Valid_Date(date) == -1)
	{
		BaoLoi("Ngay Xuat Phat khong hop le");
		//gotoXY(col, row);
		//clreol();
		del_row();
		goto Label_Date;
	}
	row++;
label_time:
	gotoXY(col, row);

	if (Check_Valid_Date(date) > 0)
	{
		cout << "GIO XUAT PHAT(hh:mm): ";
		time = CheckGioBay();
		if (time == "") return;
	}
	else if (Check_Valid_Date(date) == 0)
	{
	
		cout << "GIO XUAT PHAT(hh:mm): ";
		time = CheckGioBay();
		if (time == "") return;
		if (!Check_Valid_Time(time))
		{
			BaoLoi("Thoi Gian nhap vao khong hop le");
			//gotoXY(col, row);
			//clreol();
			del_row();
			goto label_time;
		}
	}

	if (Confirm("Xac nhan hieu chinh chuyen bay") == false) goto KIEM_TRA_MA_CB;

	result.nam = stoi(date.substr(6, 4));
	result.thang = stoi(date.substr(3, 2));
	result.ngay = stoi(date.substr(0, 2));
	result.gio = stoi(time.substr(0, 2));
	result.phut = stoi(time.substr(3, 2));
	p->data.ngayGioXuatPhat = result;
}

void UI_HuyChuyenBay(nodeCB*& dscb, DANHSACHMAYBAY& dsmb)
{
KIEM_TRA_MA_CB:
	XoaManHinh();
	Xuat_CB(dscb);
	string Ma_CB = "";
	int col = whereX(), row = whereY();

	cout << "MA CHUYEN BAY: ";
	Ma_CB = Check_ID(15);
	if (Ma_CB == "") return;
	nodeCB* p = SearchChuyenBay(dscb, Ma_CB);
	if (p == NULL)
	{
		BaoLoi("KHONG TIM THAY MA CHUYEN BAY CAN HUY VE");
		//gotoXY(col, row);
		//clreol();
		del_row();
		goto KIEM_TRA_MA_CB;
	}
	else
	{
		if (p->data.trangThai_CB == 0 || p->data.trangThai_CB == 3)
		{
			BaoLoi("CHUYEN BAY KHONG THE HUY");
			//gotoXY(col, row);
			//clreol();
			del_row();
			goto KIEM_TRA_MA_CB;
		}
	}

	if (Confirm("Xac nhan hieu chinh chuyen bay") == false) goto KIEM_TRA_MA_CB;
	HuyChuyenBay(dscb, Ma_CB, dsmb);
}

#pragma endregion

#pragma region MÁY BAY

string Check_LoaiMayBay(int limit_length)
{
	string str = "";
	int value;
	while (true)
	{
		value = getch(); //đọc dữ liệu vào nhưng ko xuất ra màn hình
		if (value == 27)
		{
			return "";
		}
		if (Check_Length(str, limit_length) && ((value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z') || value == ' '))
		{
			cout << char(value);
			str.insert(str.begin() + str.length(), char(value));
		}
		else if (value == 8 && str.length() > 0)
		{
			cout << "\b \b";
			str.erase(str.begin() + str.length() - 1);
		}
		else if (value == 13 && str.length() > 0)
		{
			break;
		}
	}
	ChuanHoaChuoi(str);
	return str;
}

int SearchMayBay(DANHSACHMAYBAY& dsmb, string x)
{
	for (int i = 0; i < dsmb.sl_mb; i++)
	{
		if (dsmb.data[i]->soHieu_MB == x)
		{
			return i;
		}
	}
	return -1;
}

#pragma endregion

#pragma region UI May Bay

void Menu_MayBay(DANHSACHMAYBAY& dsmb, nodeCB* dscb, ifstream& filein)
{
	int choice;
	string c;
	do
	{
		XoaManHinh();
		Draw_Logo(filein, "logo_QLMB.txt", 20);

		cout << "\n\t\t\t1. THEM MAY BAY";
		cout << "\n\t\t\t2. HIEU CHINH MAY BAY";
		cout << "\n\t\t\t3. XOA MAY BAY";
		cout << "\n\t\t\t4. XEM DANH SACH MAY BAY";
		cout << "\n\t\t\t5. TRO VE";
		cout << "\n\n\tNhap lua chon cua ban: ";

		//luu con tro cu
		int col = whereX(), row = whereY();

		//Bang chu y May Bay
		draw_column(9, 14, 97);
		draw_column(9, 14, 139);
		draw_line(98, 138, 8, "_");
		gotoXY(115, 9);
		cout << "CHU Y";
		draw_line(98, 138, 10, "_");
		gotoXY(98, 11);
		cout << "- Nhap lua chon cua ban sau do nhan Enter";
		gotoXY(98, 12);
		cout << "- Chi nhap so tu 1-5";
		gotoXY(98, 13);
		cout << "- Nhap 5 hoac nhan ESC de tro lai";
		draw_line(98, 138, 14, "_");

		gotoXY(col, row);
		c = Check_NumberInput(1);




		if (c == "") return;
		choice = stoi(c);
		if (choice <= 0 || choice > 5)
		{
			BaoLoi("Lua chon vua nhap khong dung, vui long kiem tra lai");
		}

		switch (choice)
		{
		case 1:
		{
			XoaManHinh();
			//	int index = 1;
			Xuat_MB(dsmb);
			MAYBAY x;
			ThemMayBay(dsmb, x);
			//GỌI LẠI HÀM XUÂT MÁY BAY ĐỂ CẬP NHẬT DANH SÁCH VỪA THÊM
			break;
		}
		case 2:
		{
			//XoaManHinh();
			HieuChinhMayBay(dsmb, dscb);
			//GỌI LẠI HÀM XUÂT MÁY BAY ĐỂ CẬP NHẬT DANH SÁCH VỪA THÊM
			break;
		}
		case 3:
		{
			//XoaManHinh();
			XoaMayBay(dsmb, dscb);
			//GỌI LẠI HÀM XUÂT MÁY BAY ĐỂ CẬP NHẬT DANH SÁCH VỪA THÊM
			break;
		}
		case 4:
		{
			XoaManHinh();
			Xuat_MB(dsmb);
			DungManHinh();
			break;
		}
		}
	} while (choice != 5);
}

void ThemMayBay(DANHSACHMAYBAY& dsmb, MAYBAY& x)
{
	int col = whereX(), row = whereY();
	string tam = "";
KIEM_TRA_SoHieuMB:
	gotoXY(col, row);
	cout << "SO HIEU MAY BAY: ";

	tam = Check_ID(15);//kiem tra ESC
	if (tam == "") return;
	x.soHieu_MB = tam;

	if (SearchMayBay(dsmb, x.soHieu_MB) != -1)
	{
		BaoLoi("So Hieu May Bay da ton tai");
		gotoXY(col, row);
		clreol();
		goto KIEM_TRA_SoHieuMB;
	}
	row++;

	gotoXY(col, row);
	cout << "LOAI MAY BAY: ";
	tam = Check_LoaiMayBay(40);//kiem tra ESC
	if (tam == "") return;
	x.Loai_MB = tam;
	row++;

KIEM_TRA_CHO_NGOI:
	gotoXY(col, row);
	cout << "SO CHO NGOI: ";
	tam = Check_NumberInput(5);//kiem tra ESC
	if (tam == "") return;


	if (!Check_Digit(tam))
	{
		BaoLoi("Vui long nhap so");
		gotoXY(col, row);
		clreol();
		goto KIEM_TRA_CHO_NGOI;
	}
	if (stoi(tam) < 20)
	{
		BaoLoi("So cho phai lon hon 20");
		gotoXY(col, row);
		clreol();
		goto KIEM_TRA_CHO_NGOI;
	}
	x.soCho_MB = stoi(tam);

	if (dsmb.sl_mb < MAX_MB)
	{
		dsmb.data[dsmb.sl_mb] = new MAYBAY;
		*dsmb.data[dsmb.sl_mb] = x;
		dsmb.sl_mb++;
	}
	else
	{
		BaoLoi("DANH SACH DAY");
	}
}

void DuyetMB(DANHSACHMAYBAY dsmb, int& index)
{
	for (int i = 0; i < dsmb.sl_mb; i++)
	{
		gotoXY(10, 5 + index);
		cout << dsmb.data[i]->soHieu_MB;
		gotoXY(27, 5 + index);
		cout << dsmb.data[i]->Loai_MB;
		gotoXY(70, 5 + index);
		cout << dsmb.data[i]->soCho_MB;
		gotoXY(79, 5 + index);
		cout << dsmb.data[i]->so_lan_bay;
		index++;
	}
	draw_line(10, 83, 5 + index, "_");
	index++;
}

void Xuat_MB(DANHSACHMAYBAY dsmb)
{
	int numOfrow = 0;
	gotoXY(40, 1);
	cout << "DANH SACH MAY BAY";
	draw_line(10, 83, 0, "_");
	draw_line(10, 83, 2, "_");
	draw_line(10, 83, 4, "-");
	gotoXY(10, 3);
	cout << "So Hieu MB";
	gotoXY(27, 3);
	cout << "Loai MB";
	gotoXY(69, 3);
	cout << "So Cho";
	gotoXY(76, 3);
	cout << "Luot Bay";

	DuyetMB(dsmb, numOfrow);
	draw_column(1, 4 + numOfrow, 9);
	draw_column(3, 4 + numOfrow, 26);
	draw_column(3, 4 + numOfrow, 68);
	draw_column(3, 4 + numOfrow, 75);
	draw_column(1, 4 + numOfrow, 84);
	gotoXY(10, 5 + numOfrow);

}

void HieuChinhMayBay(DANHSACHMAYBAY& dsmb, nodeCB* dscb)
{
Label_SoHieuMB_HieuChinh:
	XoaManHinh();
	Xuat_MB(dsmb);
	string SoHieuMB, LoaiMB, tam = "";
	int so_cho, col = whereX(), row = whereY();


	gotoXY(col, row);
	cout << "So Hieu May Bay Can Hieu Chinh: ";
	tam = Check_ID(15);//kiem tra ESC
	if (tam == "") return;

	int i = SearchMayBay(dsmb, tam);
	if (i == -1)
	{
		BaoLoi("Khong tim thay So Hieu May Bay can hieu chinh");
		gotoXY(col, row);
		clreol();
		goto Label_SoHieuMB_HieuChinh;
	}
	else if (SearchChuyenBayTheoSoHieuMayBay(dscb, tam) != NULL)
	{
		BaoLoi("KHONG HIEU CHINH DO MAY BAY NAY DA TON TAI CHUYEN BAY");
		gotoXY(col, row);
		clreol();
		goto Label_SoHieuMB_HieuChinh;
	}
	row++;

	gotoXY(col, row);
	cout << "LOAI MAY BAY: ";
	tam = Check_LoaiMayBay(40);//kiem tra ESC
	if (tam == "") return;
	LoaiMB = tam;
	row++;

KIEM_TRA_CHO_NGOI:
	gotoXY(col, row);
	cout << "SO CHO NGOI: ";

	tam = Check_NumberInput(5);//kiem tra ESC
	if (tam == "") return;

	if (!Check_Digit(tam))
	{
		goto KIEM_TRA_CHO_NGOI;
	}
	if (stoi(tam) < 20)
	{
		goto KIEM_TRA_CHO_NGOI;
	}
	so_cho = stoi(tam);

	if (Confirm("Xac nhan hieu chinh may bay") == false) goto Label_SoHieuMB_HieuChinh;

	// Sửa thông tin máy bay gồm Số chỗ & Loại Máy Bay
	dsmb.data[i]->soCho_MB = so_cho;
	dsmb.data[i]->Loai_MB = LoaiMB;

}

void XoaMayBay(DANHSACHMAYBAY& dsmb, nodeCB* dscb)
{
Label_XoaMB:
	XoaManHinh();
	string soHieuMB = "";
	Xuat_MB(dsmb);
	int col = whereX(), row = whereY();

	gotoXY(col, row);
	cout << "So Hieu May Bay Can Xoa: ";
	soHieuMB = Check_ID(15);
	if (soHieuMB == "") return;
	int i = SearchMayBay(dsmb, soHieuMB);
	if (i == -1)
	{
		BaoLoi("Khong tim thay So Hieu May Bay can xoa");
		gotoXY(col, row);
		clreol();
		goto Label_XoaMB;
	}
	else if (SearchChuyenBayTheoSoHieuMayBay(dscb, soHieuMB) != NULL)
	{
		BaoLoi("KHONG XOA DUOC VI MAY BAY DANG TON TAI CHUYEN BAY");
		gotoXY(col, row);
		clreol();
		goto Label_XoaMB;
	}
	else
	{
		if (Confirm("Xac nhan xoa may bay") == false) goto Label_XoaMB;
		delete  dsmb.data[i];
		for (int j = i + 1; j < dsmb.sl_mb; j++)
			dsmb.data[j - 1] = dsmb.data[j];
		dsmb.sl_mb--;
	}

}
#pragma endregion

#pragma region Phụ trợ xử lý danh sách

nodeCB* KhoiTaoNode(CHUYENBAY x)
{
	nodeCB* p = new nodeCB;
	if (p == NULL)
	{
		return NULL; //cấp phát thất bại
	}

	p->data = x;
	p->pNext = NULL;

	return p;
}

void ThemCuoi(nodeCB*& pHead, nodeCB* p)
{
	if (pHead == NULL) // danh sách đang rỗng
	{
		pHead = p;
	}
	else
	{
		for (nodeCB* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == NULL) // node cuối
			{
				k->pNext = p;
				break;
			}
		}
	}
}

#pragma endregion

#pragma region Chuẩn Hóa Chuỗi

string ChuanSo(int n) {
	ostringstream convert;
	convert << n;
	if (n < 10) {
		return "00" + convert.str();
	}
	else if (n < 100) {
		return "0" + convert.str();
	}
	else {
		return convert.str();
	}
}

void DeleteFirstSpace(string& str)
{
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}
}

void DeleteLastSpace(string& str)
{

	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1);
	}
}

void DeleteSpaceBetweenWords(string& str)
{
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			// xóa ký tự tại vị trí i
			str.erase(str.begin() + i);
			i--;
		}
	}
}

void UpperFirstChar(string& str)
{

	//Chuyển toàn bộ chuỗi về ký tự in thường
	int n = str.length();
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
	}
	//In hoa ký tự đầu của từ
	str.insert(str.begin() + 0, ' '); // thêm ký tự khoảng trắng vào đầu chuỗi
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
		{
			str[i + 1] = str[i + 1] - 32;
		}
	}
	str.erase(str.begin() + 0); // xóa ký tự khoảng trắng vào đầu chuỗi
}

void ChuanHoa_ID(string& str)
{
	int n = str.length();
	// đưa toàn bộ chữ về in thường
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
	}
	// đưa toàn bộ chữ về in hoa
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
	}
}

void ChuanHoaChuoi(string& str)
{
	DeleteFirstSpace(str);
	DeleteLastSpace(str);
	DeleteSpaceBetweenWords(str);
	UpperFirstChar(str);
}

string GetName(string s)
{
	int n = s.length(); //10
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			return s.substr(i + 1);
		}
	}
	return "Error!";
}

string GetHo(string s)
{
	int n = s.length();
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			return s.substr(0, i);
		}
	}
	return "Error!";
}

bool Check_Length(string str, int limit_length)
{
	int n = str.length();
	if (n <= (limit_length - 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Check_ID(int limit_length)
{
	string str = "";
	int value; //nhận từng giá trị nhập vào từ bàn phím
	while (true)
	{
		value = getch(); //đọc dữ liệu vào nhưng ko xuất ra màn hình
		if (value == 27)
		{
			return "";
		}
		if (value == 8 && str.length() > 0)
		{
			cout << "\b \b"; //xóa kí tự đó trên màn hình hiển thị
			str.erase(str.begin() + str.length() - 1);//xóa thực sự bên trong chuỗi str
		}
		else if (Check_Length(str, limit_length) && value != '\b' && value != 13 && value != ' ')
		{
			cout << char(value); //xuất 1 kí tự
			str.insert(str.begin() + str.length(), char(value)); // thêm 1 kí tự vào (vị trí vt,kí tự cần thêm)
		}
		else if (value == 13 && str.length() > 0)
		{
			break;
		}
	}
	ChuanHoa_ID(str);
	return str;
}

bool Check_GioiTinh(int limit_length)
{
	string str = "";
	int value;
	while (true)
	{
		value = getch();//đọc dữ liệu vào nhưng ko xuất ra màn hình
		if (value == 27) return "";
		if (value == 8 && str.length() > 0)
		{
			cout << "\b \b"; //xóa kí tự đó trên màn hình hiển thị
			str.erase(str.begin() + str.length() - 1);//xóa thực sự bên trong chuỗi str
		}
		else if (str.length() == 0 && (value == 'N' || value == 'n'))
		{
			cout << char(value);
			str.insert(str.begin() + str.length(), char(value));
		}
		else if (str.length() == 1 && (value == 'a' || value == 'A' || value == 'u' || value == 'U'))
		{
			cout << char(value);
			str.insert(str.begin() + str.length(), char(value));
		}
		else if (str.length() == 2 && (value == 'm' || value == 'M'))
		{
			cout << char(value);
			str.insert(str.begin() + str.length(), char(value));
		}
		else if (value == 13 && str.length() > 0 && (stricmp(str.c_str(), "nam") == 0 || stricmp(str.c_str(), "nu") == 0))
		{
			break;
		}
	}
	if (stricmp(str.c_str(), "nam") == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string CheckString(int limit_length)
{
	string str = "";
	int value;
	while (true)
	{
		value = getch();//đọc dữ liệu vào nhưng ko xuất ra màn hình
		if (value == 27)
		{
			return "";
		}
		if (Check_Length(str, limit_length) && ((value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z') || value == ' '))
		{
			cout << char(value);
			str.insert(str.begin() + str.length(), char(value));
		}
		else if (value == 8 && str.length() > 0)
		{
			cout << "\b \b";
			str.erase(str.begin() + str.length() - 1);
		}
		else if (value == 13 & str.length() > 0)
		{
			break;
		}
	}

	ChuanHoaChuoi(str);
	return str;
}

string Check_NumberInput(int limit_length)
{
	string str = "";
	int value; //nhận từng giá trị nhập vào từ bàn phím
	while (true)
	{
		value = getch(); //đọc dữ liệu vào nhưng ko xuất ra màn hình

		if (value == 27)
		{
			return "";
		}
		if (value == 8 && str.length() > 0)
		{
			cout << "\b \b"; //xóa kí tự đó trên màn hình hiển thị
			str.erase(str.begin() + str.length() - 1);//xóa thực sự bên trong chuỗi str
		}
		else if (Check_Length(str, limit_length) && value != '\b' && value != 13 && value != ' ' && (value >= '0' && value <= '9'))
		{
			cout << char(value); //xuất 1 kí tự
			str.insert(str.begin() + str.length(), char(value)); // thêm 1 kí tự vào (vị trí vt,kí tự cần thêm)
		}
		else if (value == 13 && str.length() > 0)
		{
			break;
		}
	}
	return str;

}

string CheckNgayBay()
{
	string str = "";
	int value;

	while (true)
	{
		value = getch(); //đọc dữ liệu vào nhưng ko xuất ra màn hình
		if (value == 27) return "";

		if (value == 8 && str.length() > 0) //check lỗi xóa dấu '/'
		{
			cout << "\b \b";
			str.erase(str.begin() + str.length() - 1);
		}
		else if (str.length() == 0 && value >= '0' && value <= '3')
		{
			cout << char(value);
			str.insert(str.begin() + str.length(), char(value));
		}
		else if (str.length() == 1)
		{
			if (str[0] == '3' && (value == '0' || value == '1'))
			{
				cout << char(value);
				str.insert(str.begin() + str.length(), char(value));
				cout << "/";
				str.insert(str.begin() + str.length(), '/');
			}
			else if ((str[0] == '0'))
			{
				if (value >= '1' && value <= '9')
				{
					cout << char(value);
					str.insert(str.begin() + str.length(), char(value));

					cout << "/";
					str.insert(str.begin() + str.length(), '/');
				}
			}
			else if ((str[0] == '1' || str[0] == '2'))
			{
				if (value >= '0' && value <= '9')
				{
					cout << char(value);
					str.insert(str.begin() + str.length(), char(value));

					cout << "/";
					str.insert(str.begin() + str.length(), '/');
				}
			}
		}
		else if (str.length() == 3 && value >= '0' && value <= '1')
		{
			cout << char(value);
			str.insert(str.begin() + str.length(), char(value));
		}
		else if (str.length() == 4)
		{
			if (str[3] == '0' && value >= '1' && value <= '9')
			{
				cout << char(value);
				str.insert(str.begin() + str.length(), char(value));

				cout << "/";
				str.insert(str.begin() + str.length(), '/');
			}
			else if (str[3] == '1' && value >= '0' && value <= '2')
			{
				cout << char(value);
				str.insert(str.begin() + str.length(), char(value));

				cout << "/";
				str.insert(str.begin() + str.length(), '/');
			}
		}
		else if (str.length() == 6 && (value == '2')) // cho nhập năm 2xxx
		{
			cout << char(value);
			str.insert(str.begin() + str.length(), char(value));
		}
		else if ((str.length() == 7 || str.length() == 8 || str.length() == 9) && (value >= '0' && value <= '9')) // 3 số sau của năm
		{
			cout << char(value);
			str.insert(str.begin() + str.length(), char(value));
		}
		else if (value == 13 && str.length() == 10)
		{

			break;
		}
	}
	return str;
}

string CheckGioBay()
{
	string str = "";
	int value;

	while (true)
	{
		value = getch(); //đọc dữ liệu vào nhưng ko xuất ra màn hình
		if (value == 27) return "";
		if (value == 8 && str.length() > 0) //check lỗi xóa dấu '/'
		{
			cout << "\b \b";
			str.erase(str.begin() + str.length() - 1);
		}
		else if (str.length() == 0 && value >= '0' && value <= '2')
		{
			cout << char(value);
			str.insert(str.begin() + str.length(), char(value));
		}
		else if (str.length() == 1)
		{
			if (str[0] == '2' && value >= '0' && value <= '3')
			{
				cout << char(value);
				str.insert(str.begin() + str.length(), char(value));
				cout << ":";
				str.insert(str.begin() + str.length(), ':');
			}
			else if (str[0] == '0' || str[0] == '1')
			{
				if (value >= '0' && value <= '9')
				{
					cout << char(value);
					str.insert(str.begin() + str.length(), char(value));

					cout << ":";
					str.insert(str.begin() + str.length(), ':');
				}
			}
		}
		else if (str.length() == 3 && value >= '0' && value <= '5')
		{
			cout << char(value);
			str.insert(str.begin() + str.length(), char(value));
		}
		else if (str.length() == 4 && (value >= '0' && value <= '9'))
		{
			cout << char(value);
			str.insert(str.begin() + str.length(), char(value));
		}
		else if (value == 13 && str.length() == 5)
		{
			break;
		}
	}

	return str;
}

bool Check_Digit(string chuoi_so)
{
	int l = chuoi_so.length();
	for (int i = 0; i < l; i++)
	{
		if (chuoi_so[i] < '0' || chuoi_so[i] > '9')
		{
			return false;
		}
	}
	return true;
}

#pragma endregion

#pragma region CHUYẾN BAY

nodeCB* SearchChuyenBay(nodeCB* pHead, string x)
{

	for (nodeCB* k = pHead; k != NULL; k = k->pNext)
	{
		if (k->data.Ma_CB == x)
		{
			return k;
		}
	}
	return NULL;
}

nodeCB* SearchChuyenBayTheoSoHieuMayBay(nodeCB* pHead, string SoHieuMB)
{
	for (nodeCB* k = pHead; k != NULL; k = k->pNext)
	{
		if (k->data.soHieu_MB == SoHieuMB)
		{
			return k;
		}
	}
	return NULL;

}

DATETIME NhapNgayGio()
{
	string date = "";
	DATETIME result;
	int col = whereX(), row = whereY();
Label_Date:
	gotoXY(col, row);
	cout << "NGAY XUAT PHAT(dd/mm/yyyy): ";
	date = CheckNgayBay();
	//if (date == "") return;

	if (Check_Valid_Date(date) == -1)
	{
		BaoLoi("Ngay Xuat Phat khong hop le");
		gotoXY(col, row);
		clreol();
		goto Label_Date;
	}
	row++;

	gotoXY(col, row);
	string time = "";
	if (Check_Valid_Date(date) > 0)
	{
		cout << "\nGIO XUAT PHAT(hh:mm): ";
		time = CheckGioBay();
		//if (time == "") return;
	}
	else if (Check_Valid_Date(date) == 0)
	{
	label_time:
		//gotoXY(col, row);
		cout << "\nGIO XUAT PHAT(hh:mm): ";
		time = CheckGioBay();
		//if (time == "") return;
		if (!Check_Valid_Time(time))
		{
			BaoLoi("Thoi Gian nhap vao khong hop le");
			gotoXY(col, row);
			clreol();
			goto label_time;
		}
	}

	result.nam = stoi(date.substr(6, 4));
	result.thang = stoi(date.substr(3, 2));
	result.ngay = stoi(date.substr(0, 2));
	result.gio = stoi(time.substr(0, 2));
	result.phut = stoi(time.substr(3, 2));

	return result;
}

void HieuChinhNgayGio(nodeCB*& dscb, string MaChuyenBay)
{
	nodeCB* p = SearchChuyenBay(dscb, MaChuyenBay);
	if (p == NULL)
	{
		//BaoLoi("KHONG TIM THAY MA CHUYEN BAY CAN HIEU CHINH NGAY GIO");
		return;
	}
	else
	{
		DATETIME ngaygiohieuchinh = NhapNgayGio();
		p->data.ngayGioXuatPhat = ngaygiohieuchinh;
	}
}


void HuyChuyenBay(nodeCB*& dscb, string MaChuyenBay, DANHSACHMAYBAY& dsmb)
{
	nodeCB* p = SearchChuyenBay(dscb, MaChuyenBay);
	int tam = SearchMayBay(dsmb, p->data.soHieu_MB);
	p->data.trangThai_CB = 0;
	dsmb.data[tam]->so_lan_bay--;

	//PHẦN SỬA TRẠNG THÁI VÉ
	for (int i = 0; i < p->dsve.sl_ve; i++)
	{
		KhoiTaoVe(p->dsve.data[i], i + 1);
	}
}
#pragma endregion

#pragma region ĐẶT VÉ & THÊM KHÁCH HÀNG

void Them(TREE& t, HANHKHACH x)
{
	// nếu cây rỗng <=> NODE đang xét của cây không tồn tại cây con trái và cây con phải
	if (t == NULL)
	{
		// khởi tạo node
		nodeKH* p = new nodeKH;
		p->data = x;
		p->pLeft = NULL; // cây con trái chưa liên kết đến node nào hết
		p->pRight = NULL; // cây con phải chưa liên kết đến node nào hết
		// thêm NODE p vào cây
		t = p;
	}
	else
	{
		if (stricmp(x.CMND.c_str(), t->data.CMND.c_str()) > 0)
		{
			Them(t->pRight, x);
		}
		else if (stricmp(x.CMND.c_str(), t->data.CMND.c_str()) < 0)
		{
			Them(t->pLeft, x);
		}
	}
}


nodeKH* SearchKhachHang(TREE t, string x)
{
	if (t != NULL)
	{
		if (stricmp(x.c_str(), t->data.CMND.c_str()) == 0) // Tìm thấy
			return t;
		if (stricmp(x.c_str(), t->data.CMND.c_str()) < 0)
			return SearchKhachHang(t->pLeft, x); // Tìm cây con bên trái
		return SearchKhachHang(t->pRight, x); // Tìm cây con bên phải
	}
	return NULL; // Không tìm thấy
}


void NhapKhachHang(TREE& t, HANHKHACH& x)
{
	int col = whereX(), row = whereY();
	string temp = "";
Nhap_kh:
	gotoXY(col, row);
	cout << "CMND: ";
	temp = Check_NumberInput(15);
	if (temp == "") return;
	if (SearchKhachHang(t,temp)!=NULL) {
		BaoLoi("Khach hang da ton tai");
		del_row();
		goto Nhap_kh;
	}
	x.CMND = temp;
	row++;
	gotoXY(col, row);
	cout << "Nhap Ho & Ten: ";
	temp = CheckString(50);
	if (temp == "") return;
	x.Ho = GetHo(temp);
	x.Ten = GetName(temp);
	row++;
	gotoXY(col, row);
	cout << "Nhap Gioi Tinh: ";
	x.Phai = Check_GioiTinh(3);

	//Thêm khách hàng x vào cây t
	Them(t, x);
}

// duyệt cây NLR
void DuyetDSKH(TREE t, int& row)
{
	// nếu cây không rỗng
	if (t != NULL)
	{
		
		DuyetDSKH(t->pLeft, row);
		XuatHanhKhach(t->data, row);
		row++;
		DuyetDSKH(t->pRight, row);
	}
}

void XuatHanhKhach(HANHKHACH x, int& row)
{
	gotoXY(10, row);
	cout << x.CMND;
	gotoXY(24, row);
	cout << x.Ho << " " << x.Ten;
	gotoXY(69, row);
	if (x.Phai == true)
	{
		cout << "Nam";
	}
	else
		cout << "Nu";

}

void Xuat_DSKH(TREE t)
{
	int numOfrow = 5;
	gotoXY(30, 1);
	cout << "DANH SACH HANH KHACH";
	draw_line(10, 75, 0, "_");
	draw_line(10, 75, 2, "_");
	draw_line(10, 75, 4, "-");
	gotoXY(10, 3);
	cout << "So CMND";
	gotoXY(40, 3);
	cout << "Ho va Ten";
	gotoXY(66, 3);
	cout << "Gioi Tinh";

	DuyetDSKH(t, numOfrow);
	draw_line(10, 75, numOfrow, "_");
	draw_column(1, numOfrow, 9);
	draw_column(3, numOfrow, 23);
	draw_column(3, numOfrow, 65);
	draw_column(1, numOfrow, 75);
	gotoXY(10, numOfrow + 1);
}

int CountSoLuongKhachHang(TREE t) {
	if (t == NULL)
		return 0;
	else
		return 1 + CountSoLuongKhachHang(t->pLeft) + CountSoLuongKhachHang(t->pRight);
}

void DAT_VE(nodeCB*& dscb, TREE& dskh) //SET TRẠNG THÁI VÉ THÀNH TRUE
{
	//1. Tìm mã chuyến bay cần đặt (có tồn tại - ko tồn tại)
	//2. Chọn vị trí ghế ngồi - kiểm tra vị trí ghế đã có vé đặt ghế đó chưa (nếu có thì báo lỗi, không có thì qua bước 3)


	//3. Tìm CMND trong danh sách vé trong dscb
	// 	   TH1: nếu CMND đã tồn tại => không cho đặt 
	// 	   TH2: nếu CMND không tồn tại => Dò qua danh sách KHÁCH HÀNG
	//		TH2.1:nếu tổn tại CMND thì đặt vé  
	//		TH2.2:ko có thì tự thêm khách hàng + thêm vé
START_TICKET:
	XoaManHinh();
	Xuat_CB(dscb);
	string Ma_CB = "";
	int col = whereX(), row = whereY();
KIEM_TRA_MA_CB:
	cout << "Nhap Ma Chuyen Bay can dat ve: ";
	Ma_CB = Check_ID(15);
	if (Ma_CB == "") return;
	nodeCB* p = SearchChuyenBay(dscb, Ma_CB);
	if (p == NULL)
	{
		BaoLoi("Khong ton tai chuyen bay can dat ve");
		gotoXY(col, row);
		clreol();
		goto KIEM_TRA_MA_CB;
	}

	if (p->data.trangThai_CB != 1)
	{
		if (p->data.trangThai_CB == 0)
		{
			BaoLoi("Chuyen bay da bi huy. Khong dat duoc ve");
			gotoXY(col, row);
			clreol();
			goto KIEM_TRA_MA_CB;
		}
		else if (p->data.trangThai_CB == 2)
		{
			BaoLoi("Chuyen bay da het ve. Khong dat duoc ve");
			gotoXY(col, row);
			clreol();
			goto KIEM_TRA_MA_CB;
		}
		else if (p->data.trangThai_CB == 3)
		{
			BaoLoi("Chuyen bay da hoan tat. Khong dat duoc ve");
			gotoXY(col, row);
			clreol();
			goto KIEM_TRA_MA_CB;
		}
	}
	else
	{
		XoaManHinh();
		Xuat_Ve(p);
		col = whereX();
		row = whereY();
	DAT_VE:
		gotoXY(col, row);
		cout << "Chon vi tri ghe can dat ve:";
		string temp = Check_NumberInput(3);
		if (temp == "") goto START_TICKET;
		int vt_ghe = stoi(temp);


		for (int i = 0; i < p->dsve.sl_ve; i++)
		{
			if (vt_ghe == p->dsve.data[i].vi_tri_ghe)
			{
				if (p->dsve.data[i].tt == true)
				{
					BaoLoi("Ve da co nguoi dat truoc");
					//gotoXY(col, row);
					//clreol();
					del_row();
					goto DAT_VE;
				}
				else //bước 3
				{
					gotoXY(col, row + 1);
					cout << "Nhap CMND de dat ve: ";
					string CMND = Check_NumberInput(15);
					if (CMND == "") goto START_TICKET;

					for (int j = 0; j < p->dsve.sl_ve; j++)
					{
						if (stricmp(CMND.c_str(), p->dsve.data[j].CMND.c_str()) == 0)
						{
							BaoLoi("Khach hang da co ve tren chuyen bay nay");
							gotoXY(col, row);
							clreol();
							goto START_TICKET;
						}
					}
					nodeKH* t = SearchKhachHang(dskh, CMND);
					if (t == NULL) //TH 2.2 ko có thì tự thêm khách hàng + thêm vé
					{
						gotoXY(col, row + 2);
						cout << "Nhap them thong tin khach hang";
						HANHKHACH x;
						bool gt;
						string temp = "";
						x.CMND = CMND;
						gotoXY(col, row + 3);
						cout << "Nhap Ho & Ten: ";
						temp = CheckString(50);
						if (temp == "") goto START_TICKET;
						x.Ho = GetHo(temp);
						x.Ten = GetName(temp);
						gotoXY(col, row + 4);
						cout << "Nhap Gioi Tinh: ";
						x.Phai = Check_GioiTinh(3);
						//Thêm khách hàng x vào cây t
						Them(dskh, x);

						//	NhapKhachHang(dskh, x, 2);
							//Tạo vé

						if (Confirm("Ban co muon dat ve nay!"))
						{
							p->dsve.data[vt_ghe - 1].tt = true;
							p->dsve.data[vt_ghe - 1].CMND = CMND;
							BaoLoi("Dat ve thanh cong");
							gotoXY(col, row);
							clreol();
							goto START_TICKET;
						}
						else goto START_TICKET;


					}
					else //TH2.1 nếu tổn tại CMND thì đặt vé
					{
						HANHKHACH kh;
						kh = t->data;
						row += 2;
						gotoXY(col, row);
						cout << "Thong tin khach hang:";
						row++;
						gotoXY(col, row);
						cout << "Ho va ten khach hang: " << kh.Ho << " " << kh.Ten;
						row++;
						gotoXY(col, row);
						if (kh.Phai == true) {
							cout << "Gioi tinh: Nam";
						}
						else {
							cout << "Gioi tinh: Nu";
						}

						if (Confirm("Ban co muon dat ve nay!"))
						{
							p->dsve.data[vt_ghe - 1].tt = true;
							p->dsve.data[vt_ghe - 1].CMND = CMND;
							BaoLoi("Dat ve thanh cong");
							gotoXY(col, row);
							clreol();
							goto START_TICKET;
						}
						else goto START_TICKET;

					}


				}
			}

		}
		BaoLoi("Khong co vi tri ghe vua dat");
		del_row();
		goto DAT_VE;
	}

}

void HUY_VE(nodeCB*& dscb)
{
HUY_VE:
	XoaManHinh();
	Xuat_CB(dscb);
	int col = whereX(), row = whereY();
	gotoXY(col, row);

	cout << "Nhap Ma Chuyen Bay can huy ve: ";
	string ma_CB = Check_ID(15);
	if (ma_CB == "") return;
	nodeCB* p = SearchChuyenBay(dscb, ma_CB);
	if (p == NULL)
	{
		BaoLoi("Khong tim thay chuyen bay can huy ve");
		gotoXY(col, row);
		clreol();
		goto HUY_VE;
	}
	else if (p->data.trangThai_CB != 1 && p->data.trangThai_CB != 2)
	{
		BaoLoi("Khong the huy ve tren chuyen bay nay");
		gotoXY(col, row);
		clreol();
		goto HUY_VE;
	}
	else
	{
		row++;
		//XoaManHinh();
	NHAP_LAI_CMND:
		gotoXY(col, row);
		cout << "Nhap CMND can huy ve: ";
		string CMND = Check_NumberInput(15);
		if (CMND == "") goto HUY_VE;

		for (int i = 0; i < p->dsve.sl_ve; i++)
		{
			if (stricmp(p->dsve.data[i].CMND.c_str(), CMND.c_str()) == 0)
			{
				BaoLoi("Huy ve thanh cong");
				KhoiTaoVe(p->dsve.data[i], i + 1);
				return;
			}
		}
		BaoLoi("Khong tim thay CMND can huy ve");
		gotoXY(col, row);
		clreol();
		goto NHAP_LAI_CMND;
	}

}

void KhoiTaoVe(VE& ve, int vitri)
{
	ve.CMND = "";
	ve.tt = false;
	ve.vi_tri_ghe = vitri;
}

void KhoiTaoDanhSachVe(DANHSACHMAYBAY dsmb, nodeCB*& cb)
{
	for (int i = 0; i < dsmb.sl_mb; i++)
	{
		if (stricmp(cb->data.soHieu_MB.c_str(), dsmb.data[i]->soHieu_MB.c_str()) == 0)
		{
			cb->dsve.sl_ve = dsmb.data[i]->soCho_MB;
			break;
		}
	}

	for (int i = 0; i < cb->dsve.sl_ve; i++)
	{
		KhoiTaoVe(cb->dsve.data[i], i + 1);
	}
}

#pragma endregion

#pragma region In Danh Sách(chức năng 5,6,7,8) 
//In danh sách các hành khách thuộc 1 chuyến bay dựa vào mã chuyến bay.
void InDanhSachHanhKhachTheoChuyenBay(nodeCB* dscb, TREE dskh)
{
	string Ma_CB;
	Xuat_CB(dscb);
	cout << "Nhap Ma Chuyen Bay can in danh sach: ";
	Ma_CB = Check_ID(15);
	if (Ma_CB == "") return;

	nodeCB* p = SearchChuyenBay(dscb, Ma_CB);
	if (p == NULL)
	{
		BaoLoi("Khong tim thay Ma Chuyen Bay can in danh sach");
	}
	else
	{
		XoaManHinh();
		gotoXY(20, 1);
		cout << "Danh sach hanh khach thuoc chuyen bay " << p->data.Ma_CB;
		gotoXY(10, 2);
		cout << "Ngay gio khoi hanh: " << ChuanDate(p->data.ngayGioXuatPhat.ngay) << "/" << ChuanDate(p->data.ngayGioXuatPhat.thang) << "/" << p->data.ngayGioXuatPhat.nam;
		gotoXY(55, 2);
		cout << "Noi Den: " << p->data.noiDen_CB;
		draw_line(10, 78, 0, "_");
		draw_line(10, 78, 3, "_");
		draw_line(10, 78, 5, "-");
		gotoXY(10, 4);
		cout << "STT";
		gotoXY(14, 4);
		cout << "So Ve";
		gotoXY(20, 4);
		cout << "CMND";
		gotoXY(33, 4);
		cout << "Ho va Ten";
		gotoXY(70, 4);
		cout << "Gioi Tinh";

		int stt = 1, row = 6;
		for (int i = 0; i < p->dsve.sl_ve; i++)
		{
			if (p->dsve.data[i].tt == true)
			{
				nodeKH* tam = SearchKhachHang(dskh, p->dsve.data[i].CMND);
				gotoXY(10, row);
				cout << stt;
				gotoXY(14, row);
				cout << ChuanSo(p->dsve.data[i].vi_tri_ghe);
				gotoXY(20, row);
				cout << tam->data.CMND;
				gotoXY(33, row);
				cout << tam->data.Ho << " " << tam->data.Ten;
				gotoXY(70, row);
				if (tam->data.Phai == true)
				{
					cout << "Nam";
				}
				else
				{
					cout << "Nu";
				}
				stt++;
				row++;
			}
		}
		draw_line(10, 78, row, "_");
		draw_column(1, row, 9);
		draw_column(4, row, 13);
		draw_column(4, row, 19);
		draw_column(4, row, 32);
		draw_column(4, row, 69);
		draw_column(1, row, 79);
	}

}

int DemSoLuongVeConTrong(nodeCB* dscb)
{
	int count = 0;
	for (int i = 0; i < dscb->dsve.sl_ve; i++)
	{
		if (dscb->dsve.data[i].tt == false)
		{
			count++;
		}
	}
	return count;
}

//6. In danh sách các chuyến bay khởi hành trong  ngày dd / mm / yyyy đến nơi XXXX mà còn vé(cho biết cụ thể số lượng các vé còn trống và giờ khởi hành)
void InDanhSachChuyenBayTheoNgayVaNoiDen(nodeCB* dscb)
{
	string dt = "";
	string NoiDen = "";

	Xuat_CB(dscb);
	int col = whereX(), row = whereY();
	cout << "Danh sach chuyen bay trong ngay ";

	dt = CheckNgayBay();
	if (dt == "") return;
	gotoXY(col + 42, row);

	int d = stoi(dt.substr(0, 2));
	int m = stoi(dt.substr(3, 2));
	int y = stoi(dt.substr(6, 4));

	cout << " den ";
	NoiDen = CheckString(15);
	if (NoiDen == "") return;
	//gotoXY(col + 60, row);

	XoaManHinh();
	row = 5;
	int stt = 1;
	gotoXY(10, 1);
	cout << "DANH SACH CHUYEN BAY TRONG NGAY " << dt << " DEN " << NoiDen;

	draw_line(10, 70, 0, "_");
	draw_line(10, 70, 2, "_");
	draw_line(10, 70, 4, "-");
	gotoXY(10, 3);
	cout << "STT";
	gotoXY(14, 3);
	cout << "Gio Khoi Hanh";
	gotoXY(28, 3);
	cout << "Ma Chuyen Bay";
	gotoXY(47, 3);
	cout << "So Luong Ve Trong";

	for (nodeCB* k = dscb; k != NULL; k = k->pNext)
	{
		if (k->data.noiDen_CB == NoiDen && k->data.ngayGioXuatPhat.ngay == d && k->data.ngayGioXuatPhat.thang == m && k->data.ngayGioXuatPhat.nam == y)
		{
			gotoXY(10, row);
			cout << stt;;
			gotoXY(17, row);
			cout << ChuanDate(k->data.ngayGioXuatPhat.gio) << ":" << ChuanDate(k->data.ngayGioXuatPhat.phut);
			gotoXY(28, row);
			cout << k->data.Ma_CB;
			gotoXY(55, row);
			cout << DemSoLuongVeConTrong(k);
			stt++;
			row++;
		}
	}
	draw_column(1, row, 9);
	draw_column(3, row, 13);
	draw_column(3, row, 27);
	draw_column(3, row, 41);
	draw_column(1, row, 71);
	draw_line(10, 70, row, "_");
	gotoXY(10, row + 1);
}

//7. In danh sách các vé còn trống của 1 chuyến bay có mã chuyến bay là X.
void InDanhSachVeConTrongTheoMaCB(nodeCB* dscb)
{
	Xuat_CB(dscb);
	int col = whereX(), row = whereY();
NHAP_MA_CB:
	string MaCB = "";
	cout << "Nhap Ma Chuyen Bay can in danh sach ve con trong: ";
	MaCB = Check_ID(15);
	if (MaCB == "") return;

	nodeCB* p = SearchChuyenBay(dscb, MaCB);
	if (p == NULL)
	{
		BaoLoi("Khong tim thay danh sach ve cho ma CB vua nhap");
		gotoXY(col, row);
		clreol();
		goto NHAP_MA_CB;
	}
	else if (p->data.trangThai_CB != 1)
	{
		BaoLoi("Chuyen bay het ve hoac da bi huy");
		gotoXY(col, row);
		clreol();
		goto NHAP_MA_CB;
	}
	else
	{
		XoaManHinh();

		//for (int i = 0; i < p->dsve.sl_ve; i++)
		//{
			//if (p->dsve.data[i].tt == false)
			//{
				//	cout << "\n" << p->dsve.data[i].vi_tri_ghe;
		Xuat_Ve(p);
		//}
	//}
	}
}


void SwapHaiMayBay(MAYBAY*& a, MAYBAY*& b)
{
	MAYBAY* temp = a;
	a = b;
	b = temp;
}

void SapXepTheoSoLuotBayGiamDan(DANHSACHMAYBAY& dsmb)
{
	MAYBAY x;
	for (int i = 0; i < dsmb.sl_mb - 1; i++)
	{
		for (int j = i + 1; j < dsmb.sl_mb; j++)
		{
			if (dsmb.data[i]->so_lan_bay < dsmb.data[j]->so_lan_bay)
			{

				SwapHaiMayBay(dsmb.data[i], dsmb.data[j]);

			}
		}
	}
}

//8.Thống kê số lượt thực hiện chuyến bay của từng máy bay theo thứ tự  số lượt thực hiện giảm dần
void ThongKeSoLuotBayTheoMayBay(DANHSACHMAYBAY dsmb)
{
	SapXepTheoSoLuotBayGiamDan(dsmb);
	draw_line(10, 65, 0, "_");
	draw_line(10, 65, 2, "_");
	draw_line(10, 65, 4, "-");
	gotoXY(20, 1);
	cout << "THONG KE SO LUOT BAY CUA TUNG MAY BAY";
	gotoXY(15, 3);
	cout << "So Hieu May Bay";
	gotoXY(48, 3);
	cout << "So Luot Bay";
	int row = 5;
	for (int i = 0; i < dsmb.sl_mb; i++)
	{
		gotoXY(15, row);
		cout << dsmb.data[i]->soHieu_MB;
		gotoXY(51, row);
		cout << dsmb.data[i]->so_lan_bay;
		row++;
	}
	draw_line(10, 65, row, "_");
	draw_column(1, row, 9);
	draw_column(3, row, 39);
	draw_column(1, row, 66);
}
#pragma endregion

#pragma region Giải phóng bộ nhớ

void ClearListMayBay(DANHSACHMAYBAY& dsmb)
{
	for (int i = 0; i < dsmb.sl_mb; i++)
	{
		delete dsmb.data[i];
	}
}

void ClearListChuyenBay(nodeCB*& pHead)
{
	nodeCB* k = NULL;
	while (pHead != NULL)
	{
		k = pHead->pNext;
		delete pHead;
		pHead = k;
	}
}

void ClearListKhachHang(TREE& t)
{
	if (t != NULL)
	{
		ClearListKhachHang(t->pLeft);
		ClearListKhachHang(t->pRight);
		delete t;
	}
}

#pragma endregion
