#pragma once
#include "HamXuLyChuyenBay.h"
#include "XuLyLT.h"
#include "HamXuLyMayBay.h"

NodeList* GetNodeCB(ChuyenBay cb)
{
	NodeList* p = new NodeList;

	if (p == NULL)
	{
		return NULL;
	}
	p->data = cb;
	p->pNext = NULL; // khoi tao moi lien ket
	return p;
}

int kiemTraThuTuMaCB(List l, string macb) {
	int count = 1;
	ChuyenBay CB;
	char *ch1 = (char*)macb.c_str();
	for (NodeList* k = l.pHead; k != NULL; k = k->pNext) {
		char* ch2 = (char*)k->data.MaCB.c_str();
		if (strcmp(ch1, ch2) > 0) {
			count++;
		}
	}
	return count;
}
void dscb_themcuoi(List& l, ChuyenBay cb) {
	NodeList* p = GetNodeCB(cb);
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
	++l.n;
}
void dscb_themdau(List& ds, ChuyenBay cb) {
	NodeList* p = GetNodeCB(cb);
	if (ds.pHead == NULL) {
		ds.pHead = ds.pTail = p;
	}
	else
	{
		p->pNext = ds.pHead;
		ds.pHead = p;
	}
	ds.n++;
}
void dscb_themViTriBatKy(List& l, ChuyenBay cb, int vt) {
	int dem = 0; // xác định vt cần thêm
	NodeList* g = new NodeList; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
	// duyệt danh sách từ đầu đến cuối để tìm node q <=> tìm ra cái vị trí vt cần thêm node p vào..
	for (NodeList* k = l.pHead; k != NULL; k = k->pNext)
	{
		dem++;
		// tìm vị trí vt cần thêm
		if (dem == vt)
		{
			NodeList* h = GetNodeCB(cb); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h
			// thực hiện bài toán thêm node p vào sau node g là ra vấn đề <=> thêm node p vào trước node q
			h->pNext = k; // Bước 1: cho node h trỏ(liên kết) đến node k <=> cũng chính là cho node h trỏ đến node q
			g->pNext = h; // Bước 2: cho node g trỏ đến node h 
			break;
		}
		g = k; // gi
	}
	l.n++;
}

void themChuyenBay(List &l, ChuyenBay cb, string macb) {
	int slcb = 0;
	int vt = kiemTraThuTuMaCB(l, macb);
	for (NodeList* k = l.pHead; k != NULL; k = k->pNext) {
		slcb++;
	}
	if (vt == 1) {
		dscb_themdau(l, cb);
	}
	else if (vt == slcb + 1) {
		dscb_themcuoi(l, cb);
	}
	else
		dscb_themViTriBatKy(l, cb, vt);
}

void ThemCB(MCONTROMB MB, List& l, int toadoX, int toadoY)
{
	ChuyenBay CB;
	Date NgayHienTai;
	Hour GioHienTai;
	LayNgayHienTai(CB.NgayKhoiHanh);
	LayGioHienTai(CB.GioKhoiHanh);
	CB.TrangThai = 1;
	gotoXY(toadoX + 2, toadoY + 10);
	cout << CB.TrangThai;

	GiaoDienNhapChuyenBay(toadoX, toadoY);

	gotoXY(toadoX + 2, toadoY - 2);
	cout << CB.GioKhoiHanh.Hours;
	gotoXY(toadoX + 12, toadoY - 2);
	cout << CB.GioKhoiHanh.Minute;

	gotoXY(toadoX + 2, toadoY + 1);
	if (CB.NgayKhoiHanh.Ngay < 10)
	{
		cout << 0 << CB.NgayKhoiHanh.Ngay;
	}
	else
		cout << CB.NgayKhoiHanh.Ngay;
	gotoXY(toadoX + 12, toadoY + 1);
	if (CB.NgayKhoiHanh.Thang < 10)
	{
		cout << 0 << CB.NgayKhoiHanh.Thang;
	}
	else
		cout << CB.NgayKhoiHanh.Thang;
	gotoXY(toadoX + 22, toadoY + 1);
	cout << CB.NgayKhoiHanh.Nam;

	int pointer1 = toadoY - 6;//o tren dau la MCB

	ShowCur(1);

	while (true)
	{
		if (pointer1 == toadoY - 6)//MCB
		{
			gotoXY(toadoX + 2 + CB.MaCB.length(), pointer1 + 1);
			XuLyNhapMa(CB.MaCB, toadoX + 2, pointer1);
			if (pointer1 < toadoY - 6)
			{
				pointer1 = toadoY - 6;
			}
			if (KTraTrungMaCB(l, CB.MaCB)) {
				GiaoDienThongBao("Ma chuyen bay khong duoc trung!");
				return;
			}
		}
		else if (pointer1 == toadoY - 3)//h
		{
			ShowCur(0);
			SetColor(4);
			gotoXY(toadoX + 2, pointer1 + 1);
			cout << CB.GioKhoiHanh.Hours;
			gotoXY(toadoX + 12, pointer1 + 1);
			cout << CB.GioKhoiHanh.Minute;

			while (true)
			{
				//bat phim tai vi tri gio,phut
				char c;
				if (kbhit())
				{
					c = getch();
					if (c == -32)
					{
						c = getch();
						if (c == 72)//set mau lai binh thuong vs bat phim len
						{
							ShowCur(1);
							SetColor(7);
							gotoXY(toadoX + 2, pointer1 + 1);
							cout << CB.GioKhoiHanh.Hours;
							gotoXY(toadoX + 12, pointer1 + 1);
							cout << CB.GioKhoiHanh.Minute;

							pointer1 = pointer1 - 3;

							break;
						}
						else if (c == 80)
						{
							ShowCur(1);
							SetColor(7);
							gotoXY(toadoX + 2, pointer1 + 1);
							cout << CB.GioKhoiHanh.Hours;
							gotoXY(toadoX + 12, pointer1 + 1);
							cout << CB.GioKhoiHanh.Minute;

							pointer1 = pointer1 + 3;

							break;
						}
					}
					else if (c == 13)//xu ly nhap gio
					{
						SetColor(7);
						gotoXY(toadoX + 2, pointer1 + 1);
						cout << CB.GioKhoiHanh.Hours;
						gotoXY(toadoX + 12, pointer1 + 1);
						cout << CB.GioKhoiHanh.Minute;

						XuLyNhapGio(CB.GioKhoiHanh, toadoX, pointer1);
						break;
					}
				}
			}
		}
		else if (pointer1 == toadoY)//vtri ngay,thang,nam
		{
			ShowCur(0);

			SetColor(4);
			gotoXY(toadoX + 2, toadoY + 1);
			if (CB.NgayKhoiHanh.Ngay < 10)
			{
				cout << 0 << CB.NgayKhoiHanh.Ngay;
			}
			else
				cout << CB.NgayKhoiHanh.Ngay;
			gotoXY(toadoX + 12, toadoY + 1);
			if (CB.NgayKhoiHanh.Thang < 10)
			{
				cout << 0 << CB.NgayKhoiHanh.Thang;
			}
			else
				cout << CB.NgayKhoiHanh.Thang;
			gotoXY(toadoX + 22, toadoY + 1);
			cout << CB.NgayKhoiHanh.Nam;

			if (kbhit())
			{
				char c;
				c = getch();
				if (c == 13)
				{
					XuLyNhapNgay(CB.NgayKhoiHanh, toadoX - 5, pointer1, 7, 15);
					if (SoSanhNgay(CB.NgayKhoiHanh) == 2) { // nho hon ngay hien tai
						/*gotoXY(107, 30);
						cout << "Thoi diem khoi hanh phai lon hon thoi diem hien tai!.." << endl << endl;*/
						GiaoDienThongBao("Thoi diem khoi hanh phai lon hon thoi diem hien tai!");
						return;
					}

					if (SoSanhNgay(CB.NgayKhoiHanh) == 3 && SoSanhGio(CB.GioKhoiHanh) < MAX_TIME) {
						/*gotoXY(107, 30);
						cout << "Thoi diem khoi hanh phai lon hon thoi diem hien tai it nhat 4 gio.." << endl << endl;*/
						GiaoDienThongBao("Thoi diem khoi hanh phai lon hon thoi diem hien tai it nhat 4 gio");
						return;
					}
					gotoXY(75, 21);
					cout << "Nhap San Bay Den:";
					VeHCN(toadoX, toadoY + 3, 50, 2, 7);
					gotoXY(toadoX + 2, toadoY + 4);
					cout << CB.SanBayDen;

				a: {
					gotoXY(75, 24);
					cout << "Nhap So Hieu MB:";
					VeHCN(toadoX, toadoY + 6, 50, 2, 7);
					gotoXY(toadoX + 2, toadoY + 7);
					cout << CB.SoHieuMB;
				}

					gotoXY(75, 27);
					cout << "Nhap Trang Thai :";
					VeHCN(toadoX, toadoY + 9, 50, 2, 7);
				}
				else if (c == -32)
				{
					SetColor(7);
					gotoXY(toadoX + 2, toadoY + 1);
					if (CB.NgayKhoiHanh.Ngay < 10)
					{
						cout << 0 << CB.NgayKhoiHanh.Ngay;
					}
					else
						cout << CB.NgayKhoiHanh.Ngay;
					gotoXY(toadoX + 12, toadoY + 1);
					if (CB.NgayKhoiHanh.Thang < 10)
					{
						cout << 0 << CB.NgayKhoiHanh.Thang;
					}
					else
						cout << CB.NgayKhoiHanh.Thang;
					gotoXY(toadoX + 22, toadoY + 1);
					cout << CB.NgayKhoiHanh.Nam;
					ShowCur(1);

					c = getch();
					if (c == 72)
					{
						pointer1 = pointer1 - 3;
					}
					else if (c == 80)
					{
						pointer1 = pointer1 + 3;
					}
				}
			}
		}
		else if (pointer1 == toadoY + 3)//san bay den
		{
			gotoXY(toadoX + 2 + CB.SanBayDen.length(), pointer1 + 1);
			XuLyNhap_Chu(CB.SanBayDen, toadoX + 2, pointer1, 47);
		}
		else if (pointer1 == toadoY + 6)//so hieu
		{
			gotoXY(toadoX + 2 + CB.SoHieuMB.length(), pointer1 + 1);
			XuLyNhapMa(CB.SoHieuMB, toadoX + 2, pointer1);

			if (!KTraTrungSoHieuMB(MB, CB.SoHieuMB)) {
				GiaoDienThongBao("So hieu may bay khong ton tai..");
				return;
			}
			if (KiemTraChuyenBayCungThoiDiem(l, CB.SoHieuMB, CB.NgayKhoiHanh, CB.GioKhoiHanh)) {
				if (CB.TrangThai != 3) {
					GiaoDienThongBao("May bay nay da duoc dang ki chuyen bay roi..");
					//return;
					goto a;
				}
			}
		}
		//		else if (pointer1 == toadoY + 9)
		//		{
		//			gotoXY(toadoX + 2 + DemChuSo(CB.TrangThai), pointer1 + 1);
		//			XuLyNhapSo(CB.TrangThai, toadoX + 2, pointer1);
		//		}
		else if (pointer1 == toadoY + 9) // save hoac huy
		{
			ShowCur(0);
			int pointer2 = toadoX + 15;
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						MayBay* tamMB = LayThongTinMB(MB, CB.SoHieuMB);

						if (pointer2 == toadoX + 15
							&& !CB.MaCB.empty()
							&& CB.NgayKhoiHanh.Ngay > 0
							&& !CB.SanBayDen.empty()
							&& !CB.SoHieuMB.empty()
							&& CB.TrangThai > -1 && CB.TrangThai < 4
							&& tamMB != NULL
							&& !KiemTraChuyenBayCungThoiDiem(l, tamMB->SoHieuMB, CB.NgayKhoiHanh, CB.GioKhoiHanh)
							&& KTraTrungMaCB(l, CB.MaCB) == false)
							//							&& SoSanhNgay(NgayHienTai,CB.NgayKhoiHanh)==1) 
						{
							DinhDangChuoi(CB.SanBayDen);
							CB.SoVeDaDat = 0;
							CB.TongSoVe = tamMB->SoDong * tamMB->SoDay;
							CB.DSVe = new DanhSachVe[CB.TongSoVe];

							//Dat ten cho ve 
							int h = 0;//so ve
							int TenDay = 65;//A
							int TenDong = 1;
							for (int i = 0; i < tamMB->SoDong; i++)
							{
								TenDay = 65;//A
								for (int j = 0; j < tamMB->SoDay; j++)
								{
									if (TenDong < 10)
									{
										CB.DSVe[h].MaVe.push_back((char)TenDay);
										CB.DSVe[h].MaVe.push_back((char)48);//0
										CB.DSVe[h].MaVe = CB.DSVe[h].MaVe + ChuyenSoSangString1(TenDong);
									}
									else
									{
										CB.DSVe[h].MaVe.push_back((char)TenDay);
										CB.DSVe[h].MaVe = CB.DSVe[h].MaVe + ChuyenSoSangString1(TenDong);
									}
									CB.DSVe[h].TrangThai = false;
									TenDay++;
									h++;
								}
								TenDong++;
							}
							themChuyenBay(l, CB, CB.MaCB);
							//	tamMB->SoLuotCB++;
							return;
						}
						else if (pointer2 == toadoX + 30)
						{
							return;
						}
						/*else if (tamMB == NULL)
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "So Hieu May Bay Khong Ton Tai";
						}*/
						//else if (KiemTraChuyenBayCungThoiDiem(l, tamMB->SoHieuMB, CB.NgayKhoiHanh, CB.GioKhoiHanh))//k cho tao 2 chuyen bay tren cung 1 may bay taij cung 1 thoi diem
						//{
						//	textcolor(7);
						//	gotoXY(107, 30);
						//	cout << "MB DA DK CB ROI!";
						//}
						/*else if (KTraTrungMaCB(l, CB.MaCB) == true) {
							textcolor(7);
							gotoXY(107, 30);
							cout << "MA CHUYEN BAY PHAI LA DUY NHAT!";
						}*/
						/*else if (CB.TrangThai < -1 || CB.TrangThai > 4)
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "Trang Thai Khong Hop Le";
						}*/
						//						else if( SoSanhNgay(NgayHienTai,CB.NgayKhoiHanh)=1){
						//							textcolor(7);
						//							gotoXY(107, 30);
						//							cout << "Ngay Khong Hop Le!";
						//						}
						else
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "Vui Long Dien Day Du Thong Tin";
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(toadoX + 30, toadoY + 15);
							cout << "Cancel";
							gotoXY(toadoX + 15, toadoY + 15);
							cout << "Dang Ki";
							ShowCur(1);
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80)
						{
							textcolor(7);
							gotoXY(toadoX + 30, toadoY + 15);
							cout << "Cancel";
							gotoXY(toadoX + 15, toadoY + 15);
							cout << "Dang Ki";
							ShowCur(1);
							pointer1 = toadoY - 6;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == toadoX + 30)
							{
								pointer2 = toadoX + 15;
							}
							else
								pointer2 = toadoX + 30;
						}
						else if (c == 77)
						{
							if (pointer2 == toadoX + 15)
							{
								pointer2 = toadoX + 30;
							}
							else
								pointer2 = toadoX + 15;
						}
						gotoXY(pointer2, toadoY + 10);
					}
				}

				SetColor(5);
				gotoXY(pointer2, toadoY + 15);
				if (pointer2 == toadoX + 15)
				{
					cout << "Dang Ki";
					textcolor(7);
					gotoXY(toadoX + 30, toadoY + 15);
					cout << "Cancel";
				}
				else if (pointer2 == toadoX + 30)
				{
					cout << "Cancel";
					textcolor(7);
					gotoXY(toadoX + 15, toadoY + 15);
					cout << "Dang Ki";
				}

				Sleep(100);
			}
		}
	}
	GiaoDienThongBao("Them thanh cong !!");
}

bool dscb_kiemtrarong(List& l) {//kiem tra ds rong
	return l.pHead == NULL;
}

void dscb_xoadau(List& l) {
	if (dscb_kiemtrarong(l)) return;
	NodeList* p = l.pHead;
	l.pHead = p->pNext;
	delete p;
	--l.n;
	return;
}

void dscb_xoacuoi(List& l) {
	if (dscb_kiemtrarong(l)) return;
	NodeList* beforP = NULL;
	for (NodeList* p = l.pHead; p != NULL; p = p->pNext) {
		if (p == l.pTail) {
			l.pTail = beforP;
			beforP->pNext = NULL;
			delete p;
			--l.n;
			return;
		}
		beforP = p;
	}
}

void dscb_xoasau(List& l, NodeList* p) { // xoa node sau p
	if (p == NULL || p->pNext == NULL) return;
	NodeList* nodeDeleted = p->pNext;
	p->pNext = nodeDeleted->pNext;
	delete nodeDeleted;
	--l.n;
	return;
}

void XoaCB(List& l) {
	string MCB;
	gotoXY(60, 10);
	cout << "Nhap Ma Chuyen Bay Can Xoa:";
	XuLyNhapMa1(MCB);
	if (!KTraTrungMaCB(l, MCB)) {
		GiaoDienThongBao("Ma chuyen bay khong ton tai !");
		return;
	}
	if (MCB.empty())
	{
		return;
	}

	// Xoa CB
	NodeList* nodeDeleted = LayThongTinCB(l, MCB);
	/*if (nodeDeleted->data.TrangThai == 3)
	{
		GiaoDienThongBao("Khong The Xoa Chuyen Bay Da Hoan Tat!");
		return;
	}*/
	if (nodeDeleted->data.SoVeDaDat != 0) {
		GiaoDienThongBao("Chuyen bay da co ve dat nen khong the xoa !");
		return;
	}
	else if (nodeDeleted == l.pHead)
		dscb_xoadau(l);
	else if (nodeDeleted == l.pTail)
		dscb_xoacuoi(l);
	else {
		NodeList* temp = l.pHead;
		while (temp->pNext != nodeDeleted)
			temp = temp->pNext;
		dscb_xoasau(l, temp);
	}
	GiaoDienThongBao("Xoa Thanh Cong");
}

void SuaCB(List& l, MCONTROMB MB, int toadoX, int toadoY) {
	string MCB;
	gotoXY(60, 10);
	cout << "Nhap So Ma Chuyen Bay Can Sua:";
	ShowCur(1);
	XuLyNhapMa1(MCB);
	if (!KTraTrungMaCB(l, MCB)) {
		GiaoDienThongBao("Ma chuyen bay khong ton tai !!");
		return;
	}
	ShowCur(0);
	gotoXY(60, 10);
	cout << "                                                                                        ";

	if (MCB.empty())
	{
		return;
	}

	NodeList* nodeSua = LayThongTinCB(l, MCB);
	string soHieuMBtam = nodeSua->data.SoHieuMB;
	if (nodeSua->data.TrangThai == 3)
	{
		GiaoDienThongBao("CB da hoan tat nen khong the sua!");
		return;
	}
	
	ChuyenBay CBTam = nodeSua->data;// luu lai gia tri

	GiaoDienSuaChuyenBay(toadoX, toadoY);
	gotoXY(toadoX + 2, toadoY - 5);
	cout << nodeSua->data.MaCB;
	//gotoXY(toadoX + 2, toadoY + 1);

	gotoXY(toadoX + 2, toadoY - 2);
	cout << nodeSua->data.GioKhoiHanh.Hours;
	gotoXY(toadoX + 12, toadoY - 2);
	cout << nodeSua->data.GioKhoiHanh.Minute;

	gotoXY(toadoX + 2, toadoY + 1);
	if (nodeSua->data.NgayKhoiHanh.Ngay < 10)
	{
		cout << 0 << nodeSua->data.NgayKhoiHanh.Ngay;
	}
	else
		cout << nodeSua->data.NgayKhoiHanh.Ngay;
	gotoXY(toadoX + 12, toadoY + 1);
	if (nodeSua->data.NgayKhoiHanh.Thang < 10)
	{
		cout << 0 << nodeSua->data.NgayKhoiHanh.Thang;
	}
	else
		cout << nodeSua->data.NgayKhoiHanh.Thang;
	gotoXY(toadoX + 22, toadoY + 1);
	cout << nodeSua->data.NgayKhoiHanh.Nam;

	gotoXY(toadoX + 2, toadoY + 4);
	cout << nodeSua->data.SanBayDen;
	gotoXY(toadoX + 2, toadoY + 7);
	cout << nodeSua->data.SoHieuMB;
	gotoXY(toadoX + 2, toadoY + 10);
	cout << nodeSua->data.TrangThai;

	int pointer1 = toadoY - 3;
	ShowCur(1);
	while (true)
	{
		if (pointer1 == toadoY - 3)//gio
		{
			ShowCur(0);
			SetColor(4);
			gotoXY(toadoX + 2, pointer1 + 1);
			cout << nodeSua->data.GioKhoiHanh.Hours;
			gotoXY(toadoX + 12, pointer1 + 1);
			cout << nodeSua->data.GioKhoiHanh.Minute;

			while (true)
			{
				char c;
				if (kbhit())
				{
					c = getch();
					if (c == -32)//bat phim tu gio khoi hanh
					{
						c = getch();
						if (c == 72)
						{
							ShowCur(1);
							SetColor(7);
							gotoXY(toadoX + 2, pointer1 + 1);
							cout << nodeSua->data.GioKhoiHanh.Hours;
							gotoXY(toadoX + 12, pointer1 + 1);
							cout << nodeSua->data.GioKhoiHanh.Minute;

							pointer1 = pointer1 - 3;
							if (pointer1 < toadoY - 3)
							{
								pointer1 = toadoY - 3;
							}

							break;
						}
						else if (c == 80)
						{
							ShowCur(1);
							SetColor(7);
							gotoXY(toadoX + 2, pointer1 + 1);
							cout << nodeSua->data.GioKhoiHanh.Hours;
							gotoXY(toadoX + 12, pointer1 + 1);
							cout << nodeSua->data.GioKhoiHanh.Minute;

							pointer1 = pointer1 + 3;

							break;
						}
					}
					else if (c == 13)
					{
						SetColor(7);
						gotoXY(toadoX + 2, pointer1 + 1);
						cout << nodeSua->data.GioKhoiHanh.Hours;
						gotoXY(toadoX + 12, pointer1 + 1);
						cout << nodeSua->data.GioKhoiHanh.Minute;

						XuLyNhapGio(nodeSua->data.GioKhoiHanh, toadoX, pointer1);

						break;
					}
				}
			}
		}
		else if (pointer1 == toadoY)//ngay
		{
			ShowCur(0);

			SetColor(4);
			gotoXY(toadoX + 2, toadoY + 1);
			if (nodeSua->data.NgayKhoiHanh.Ngay < 10)
			{
				cout << 0 << nodeSua->data.NgayKhoiHanh.Ngay;
			}
			else
				cout << nodeSua->data.NgayKhoiHanh.Ngay;
			gotoXY(toadoX + 12, toadoY + 1);
			if (nodeSua->data.NgayKhoiHanh.Thang < 10)
			{
				cout << 0 << nodeSua->data.NgayKhoiHanh.Thang;
			}
			else
				cout << nodeSua->data.NgayKhoiHanh.Thang;
			gotoXY(toadoX + 22, toadoY + 1);
			cout << nodeSua->data.NgayKhoiHanh.Nam;

			if (kbhit())
			{
				char c;
				c = getch();
				if (c == 13)
				{
					XuLyNhapNgay(nodeSua->data.NgayKhoiHanh, toadoX - 5, pointer1, 7, 15);

					if (SoSanhNgay(nodeSua->data.NgayKhoiHanh) == 2) { // nho hon ngay hien tai
						/*gotoXY(107, 30);
						cout << "Thoi diem khoi hanh phai lon hon thoi diem hien tai!.." << endl << endl;*/
						GiaoDienThongBao("Thoi diem khoi hanh phai lon hon thoi diem hien tai!");
						return;
					}

					if (SoSanhNgay(nodeSua->data.NgayKhoiHanh) == 3 && SoSanhGio(nodeSua->data.GioKhoiHanh) < MAX_TIME) {
						/*gotoXY(107, 30);
						cout << "Thoi diem khoi hanh phai lon hon thoi diem hien tai it nhat 4 gio.." << endl << endl;*/
						GiaoDienThongBao("Thoi diem khoi hanh phai lon hon thoi diem hien tai it nhat 4 gio");
						return;
					}

					gotoXY(75, 21);
					cout << "Nhap San Bay Den:";
					VeHCN(toadoX, toadoY + 3, 50, 2, 7);

					gotoXY(75, 24);
					cout << "Nhap So Hieu MB:";
					VeHCN(toadoX, toadoY + 6, 50, 2, 7);

					gotoXY(75, 27);
					cout << "Nhap Trang Thai :";
					VeHCN(toadoX, toadoY + 9, 50, 2, 7);
				}
				else if (c == -32)
				{
					SetColor(7);
					gotoXY(toadoX + 2, toadoY + 1);
					if (nodeSua->data.NgayKhoiHanh.Ngay < 10)
					{
						cout << 0 << nodeSua->data.NgayKhoiHanh.Ngay;
					}
					else
						cout << nodeSua->data.NgayKhoiHanh.Ngay;
					gotoXY(toadoX + 12, toadoY + 1);
					if (nodeSua->data.NgayKhoiHanh.Thang < 10)
					{
						cout << 0 << nodeSua->data.NgayKhoiHanh.Thang;
					}
					else
						cout << nodeSua->data.NgayKhoiHanh.Thang;
					gotoXY(toadoX + 22, toadoY + 1);
					cout << nodeSua->data.NgayKhoiHanh.Nam;
					ShowCur(1);

					c = getch();
					if (c == 80)
					{
						pointer1 = pointer1 + 3;
					}
				}
			}
		}
		else if (pointer1 == toadoY + 3)
		{
			gotoXY(toadoX + 2 + nodeSua->data.SanBayDen.length(), pointer1 + 1);
			XuLyNhapMa(nodeSua->data.SanBayDen, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY + 6)
		{
			gotoXY(toadoX + 2 + nodeSua->data.SoHieuMB.length(), pointer1 + 1);
			XuLyNhapMa(nodeSua->data.SoHieuMB, toadoX + 2, pointer1);

			MayBay *mb1 = LayThongTinMB(MB, nodeSua->data.SoHieuMB);
			MayBay *mb2 = LayThongTinMB(MB, soHieuMBtam);
			if (nodeSua->data.TrangThai == 1 || nodeSua->data.TrangThai == 2) {
				if (mb1->SoDay < mb2->SoDay || mb1->SoDong < mb2->SoDong) {
					GiaoDienThongBao("May bay moi phai co so day va so dong lon hon may bay cu!");
					return;
				}
			}
		}
		else if (pointer1 == toadoY + 9)
		{
			gotoXY(toadoX + 2 + DemChuSo(nodeSua->data.TrangThai), pointer1 + 1);
			XuLyNhapSo(nodeSua->data.TrangThai, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY + 12) // save hoac huy
		{
			ShowCur(0);
			int pointer2 = toadoX + 15;
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if(pointer2 == toadoX + 15
							&& nodeSua->data.TrangThai > -1 && nodeSua->data.TrangThai < 4
							&& nodeSua->data.NgayKhoiHanh.Ngay > 0
							&& !nodeSua->data.SanBayDen.empty())
						{
							return;
						}
						else if (pointer2 == toadoX + 30)
						{
							nodeSua->data = CBTam;//huy
							return;
						}
						else if (nodeSua->data.TrangThai < -1 || nodeSua->data.TrangThai > 4)
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "Trang Thai Khong Hop Le";
						}
						else
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "Vui Long Dien Day Du Thong Tin";
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(toadoX + 30, toadoY + 15);
							cout << "Cancel";
							gotoXY(toadoX + 15, toadoY + 15);
							cout << "Dang Ki";
							ShowCur(1);
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80)
						{
							textcolor(7);
							gotoXY(toadoX + 30, toadoY + 15);
							cout << "Cancel";
							gotoXY(toadoX + 15, toadoY + 15);
							cout << "Dang Ki";
							ShowCur(1);
							pointer1 = toadoY - 3;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == toadoX + 30)
							{
								pointer2 = toadoX + 15;
							}
							else
								pointer2 = toadoX + 30;
						}
						else if (c == 77)
						{
							if (pointer2 == toadoX + 15)
							{
								pointer2 = toadoX + 30;
							}
							else
								pointer2 = toadoX + 15;
						}
						gotoXY(pointer2, toadoY + 10);
					}
				}

				SetColor(5);
				gotoXY(pointer2, toadoY + 15);
				if (pointer2 == toadoX + 15)
				{
					cout << "Dang Ki";
					textcolor(7);
					gotoXY(toadoX + 30, toadoY + 15);
					cout << "Cancel";
				}
				else if (pointer2 == toadoX + 30)
				{
					cout << "Cancel";
					textcolor(7);
					gotoXY(toadoX + 15, toadoY + 15);
					cout << "Dang Ki";
				}

				Sleep(100);
			}
		}
	}
}

//void HuyChuyenBay(List& l, int toadoX, int toadoY) { // chi duoc phep huy chuyen khi chuyen bay chua khoi hanh
//	string maCB;
//	int i = 1;
//		
//		fflush(stdin);
//		GiaoDienHuyCB(toadoX, toadoY);
//
//		if (!KTraTrungMaCB(l, maCB)) {
//			cout << "Ma chuyen bay nay khong ton tai.. Nhap lai ma chuyen bay khac: " << endl << endl;
//		}
//
//	NodeList *tam = LayThongTinCB(dsCB, maCB);
//	if (SoSanhNgay(tam->CB.ngayKhoiHanh) == 2 || (SoSanhNgay(tam->CB.ngayKhoiHanh) == 3 && SoSanhGio(tam->CB.gioKhoiHanh)) < 0) {
//		cout << "Chuyen bay da duoc khoi hanh nen khong the huy chuyen !" << endl;
//		return;
//	}
//	else {
//		tam->CB.trangThai = 0;
//	}
//}

void HuyChuyenBay(List& l, int toadoX, int toadoY)
{
	GiaoDienHuyCB(toadoX, toadoY);
	int pointer1 = toadoY - 3;
	string MCB;
	ShowCur(1);
	while (true)
	{
		if (pointer1 == toadoY - 3)//MCB
		{
			gotoXY(toadoX + 2 + MCB.length(), pointer1 + 1);
			XuLyNhapMa(MCB, toadoX + 2, pointer1);
			if (pointer1 < toadoY - 3)
			{
				pointer1 = toadoY - 3;
			}
			if (!KTraTrungMaCB(l, MCB)) {
				GiaoDienThongBao("Ma chuyen bay khong ton tai!");
				return;
			}
		}
		else if (pointer1 == toadoY) // save hoac huy
		{
			ShowCur(0);
			int pointer2 = toadoX + 15;
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						NodeList* tamCB = LayThongTinCB(l, MCB);
						if (pointer2 == toadoX + 15)
						{
							NodeList *tam = LayThongTinCB(l, MCB);
							if (SoSanhNgay(tam->data.NgayKhoiHanh) == 2 || (SoSanhNgay(tam->data.NgayKhoiHanh) == 3 && SoSanhGio(tam->data.GioKhoiHanh) < 0) ) {
								GiaoDienThongBao("Chuyen bay da duoc khoi hanh nen khong the huy chuyen !");
								return;
							}
							else {
								tam->data.TrangThai = 0;
							}
							return;
						}
						else if (pointer2 == toadoX + 30)
						{
							return;
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "Cancel";
							gotoXY(toadoX + 15, toadoY + 10);
							cout << "Xac Nhan";
							ShowCur(1);
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80)
						{
							textcolor(7);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "Cancel";
							gotoXY(toadoX + 15, toadoY + 10);
							cout << "Xac Nhan";
							ShowCur(1);
							pointer1 = toadoY - 3;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == toadoX + 30)
							{
								pointer2 = toadoX + 15;
							}
							else
								pointer2 = toadoX + 30;
						}
						else if (c == 77)
						{
							if (pointer2 == toadoX + 15)
							{
								pointer2 = toadoX + 30;
							}
							else
								pointer2 = toadoX + 15;
						}
						gotoXY(pointer2, toadoY + 10);
					}
				}
				SetColor(5);
				gotoXY(pointer2, toadoY + 10);
				if (pointer2 == toadoX + 15)
				{
					cout << "Xac Nhan";
					textcolor(7);
					gotoXY(toadoX + 30, toadoY + 10);
					cout << "Cancel";
				}
				else if (pointer2 == toadoX + 30)
				{
					cout << "Cancel";
					textcolor(7);
					gotoXY(toadoX + 15, toadoY + 10);
					cout << "Xac Nhan";
				}
				Sleep(100);
			}
		}
	}
}

