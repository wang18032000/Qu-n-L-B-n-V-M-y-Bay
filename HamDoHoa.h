#pragma once
#include <conio.h>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <iostream>
using namespace std;

#define Enter 13
#define ESC 27
#define KEY_NONE	-1
#define Font_Color 1

#pragma region Hàm Thư Viện

// hàm dịch chuyển tới tọa độ (x,y)
void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//hàm lấy tọa độ X
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
// hàm lấy tọa độ Y
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

// hàm đổi màu chữ
void TextColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

// hàm tô màu background cho chữ
void textbk(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

// hàm loại bỏ thanh Scroll
void RemoveScroll()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	csbi.dwSize.X = csbi.dwMaximumWindowSize.X;
	csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;
	SetConsoleScreenBufferSize(hstdout, csbi.dwSize);

	HWND x = GetConsoleWindow();
	ShowScrollBar(x, SB_BOTH, FALSE);
}

// hàm mở full màn hình
void fullScreen()
{
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

// hàm chỉnh kích thước màn hình console
void ResizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// hàm Xóa màn hình
void XoaManHinh()
{
	system("cls");
}

void DungManHinh()
{
	system("pause");
}

// hàm tô màu chuỗi input_text
void ToMauText(int x, int y, string input_text, int color)
{
	gotoXY(x, y);
	TextColor(color);
	cout << input_text;
	TextColor(7); // màu mặc định của chữ 
}

// hàm vẽ khung
void Ve_Khung(int x, int y, int width, int height)
{
	char a = 218, b = 196, c = 191, d = 179, e = 192, f = 217;
	gotoXY(x, y);
	cout << a;
	for (int i = 1; i < width; i++) {
		gotoXY(x + i, y);
		cout << b;
	}
	gotoXY(x + width, y);
	cout << c;
	for (int i = 1; i < height; i++) {
		gotoXY(x, y + i);
		cout << d;
	}
	gotoXY(x, y + height);
	cout << e;
	for (int i = 1; i < width; i++) {
		gotoXY(x + i, y + height);
		cout << b;
	}
	gotoXY(x + width, y + height);
	cout << f;
	for (int i = 1; i < height; i++) {
		gotoXY(x + width, y + i);
		cout << d;
	}
}

//Ẩn con trỏ nhấp nháy trên màn hình,Xu_Li_Con_Tro_Chi_Vi(0) -> Ẩn con trỏ -- Xu_Li_Con_Tro_Chi_Vi(1)-> hiện lại con trỏ
void Xu_Li_Con_Tro_Chi_Vi(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

// Vẽ đường thẳng ngang từ tọa độ (x0, y) đến (x1, y)
void lineX(int x0, int x1, int y)
{
	gotoXY(x0, y);
	for (int i = x0; i < x1; i++)
	{
		cout << char(196);
	}
}
// Vẽ đường thẳng dọc từ tọa độ (x, y0) đến (x, y1)
void lineY(int y0, int y1, int x)
{
	for (int i = y0; i <= y1; i++)
	{
		gotoXY(x, i);
		cout << char(179);
	}
	gotoXY(whereX(), y0);
}

void clearRightScreen()
{
	for (int i = 4; i < 50; i++)
	{
		gotoXY(80, i);
		cout << "                                                                                                             ";
	}
}

void clearLeftScreen()
{
	for (int i = 10; i < 30; i++)
	{
		gotoXY(2, i);
		cout << "                                           ";
	}

}

// Xóa từ vị trí con trỏ tới hết dòng hiện tại, rồi đưa con trỏ về vị trí cũ
void clreol() {
	COORD coord;
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	coord.X = info.dwCursorPosition.X;
	coord.Y = info.dwCursorPosition.Y;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
		info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
	gotoXY(info.dwCursorPosition.X, info.dwCursorPosition.Y);
}

void del_row() {
	int x = whereX(), y = whereY();
	gotoXY(0, y);
	for (int i = 0; i < 50; i++)
	{
		cout << " ";
	}
	gotoXY(x, y);
}

void BaoLoi(string s) {
	int x = whereX(), y = whereY();
	gotoXY(30, 35);
	TextColor(4);
	Xu_Li_Con_Tro_Chi_Vi(0);
	cout << s;
	TextColor(1);
	Sleep(2000);
	Xu_Li_Con_Tro_Chi_Vi(1);
	gotoXY(10, 30);
	clreol();
	gotoXY(x, y);
}



int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}

	return KEY_NONE;
}

void test1()
{
	if (_kbhit())
	{
		char kitu = _getch(); // nhận kí tự vào bộ nhớ đêm getch()
		if (kitu == 'w') //kiểm tra xem kitu có bằng kí tự cần check
		{
			// code xử lý
		}
	}
}

void test2()
{
	if (_kbhit())
	{
		char kitu = _getch(); // nhận kí tự vào bộ nhớ đêm getch()
		if (kitu == -32) //kí tự kép
		{
			kitu = _getch();
			if (kitu == 72) // mũi tên lên
			{
				//code xử lý
			}
			else if (kitu == 80) //mũi tên xuống
			{
				//code xử lý
			}
			else if (kitu == 75) //mũi tên trái
			{
				//code xử lý
			}
			else if (kitu == 77) //mũi tên phải
			{
				//code xử lý
			}

		}
	}
}

void delete_line()
{
	int x = whereX();
	int y = whereY();
	clreol();
	gotoXY(x, y);

}

void draw_line(int s, int e, int row, string x)
{
	for (int i = s; i <= e; i++)
	{
		gotoXY(i, row);
		cout << x;
	}

}
void draw_column(int s, int e, int col)
{
	for (int i = s; i <= e; i++)
	{
		gotoXY(col, i);
		cout << "|";
	}

}

void Draw_Logo(ifstream& filein, string TextFilePath, int toado_x)
{
	string s;
	int line = 1;
	filein.open(TextFilePath, ios_base::in);
	TextColor(Font_Color);
	while (!filein.eof())
	{
		gotoXY(toado_x, line);
		getline(filein, s);
		cout << s;
		line++;
	}
	filein.close();
}

boolean Confirm(string s) {
	boolean kt;
	int x = whereX(), y = whereY();
	gotoXY(30, 35);
	Xu_Li_Con_Tro_Chi_Vi(0);
	cout << s;
	//Sleep(2000);
	Xu_Li_Con_Tro_Chi_Vi(1);
	gotoXY(25, 36); 
	cout << "Chon 1 de xac nhan - Chon 0 de huy";
	int value;
	while (true) 
	{
		value =_getch();
		if (value == 27)
		{
			kt = false;
			break;
		}
		if (value == '1') 
		{
			kt = true;
			break;
		}
		if (value == '0') 
		{ 
			kt = false; 
			break;
		}
	}
	
	gotoXY(10, 30);
	clreol();
	gotoXY(10, 30);
	clreol();
	gotoXY(x, y);
	return kt;
}

#pragma endregion
