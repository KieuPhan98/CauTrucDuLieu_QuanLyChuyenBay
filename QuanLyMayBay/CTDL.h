#pragma once
#pragma warning (disable :4996)

#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include<time.h>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
#define MAXLIST 300		// toi da 300 may bay
#define MAX_TIME 4*60   // thoi diem khoi hanh sau 4h thi trang thai la hoan tat

using namespace std;

int toadoXBox = 65;
int toadoYBox = 9;
int SoLgKH = 0;

struct Hour
{
	int Hours;
	int Minute;
};
struct Date
{
	int Ngay;
	int Thang;
	int Nam;
};

struct MayBay
{
	string SoHieuMB;
	string LoaiMayBay;
	int SoLuotCB;
	int SoDay;
	int SoDong;
};
struct MCONTROMB
{
	MayBay* data[MAXLIST];
	int SoLgMB;
};

struct DanhSachVe  // danh sach tuyen tinh cap phat dong
{
	string CMND;
	string MaVe;
	bool TrangThai;//1 da dat,0 chua dat
};
struct ChuyenBay
{
	string MaCB;
	Hour GioKhoiHanh;
	Date NgayKhoiHanh;
	string SanBayDen;
	string SoHieuMB;
	int TrangThai;//0:huy chuyen,1:con ve ,2:het ve ,3:hoan tat
	DanhSachVe* DSVe;
	int TongSoVe;
	int SoVeDaDat;
};

struct NodeList
{
	ChuyenBay data;
	NodeList* pNext;
};

struct List
{
	int n = 0;//so luong chuyen bay
	NodeList* pHead;
	NodeList* pTail;
};

struct HanhKhach
{
	string CMND;
	string Ho;
	string Ten;
	bool Phai;
};
struct NODE_TREE
{
	HanhKhach data;
	NODE_TREE* pLeft;
	NODE_TREE* pRight;

};
typedef NODE_TREE* TREE;
