#include "HamXuLyChuyenBay.h"
#include "HamXuLyMayBay.h"

NODE_TREE* TimHanhKhach(TREE t, string idkhach) {
	if (t != NULL)
	{
		NODE_TREE* p = t;
		while (p != NULL)
		{
			if (p->data.CMND == idkhach)
				return p;
			else if (p->data.CMND > idkhach)
				p = p->pLeft;
			else
				p = p->pRight;
		}
	}
	return NULL;
}

/////////////////////////////////XUAT DU LIEU////////////////////////////////////////

//void XuatMotMayBay(MayBay MB) {
//	cout << "SO HIEU MAY BAY:" << MB.SoHieuMB << endl;
//	cout << "LOAI MAY BAY:" << MB.LoaiMayBay << endl;
//	cout << "SO DAY:" << MB.SoDay << endl;
//	cout << "SO DONG:" << MB.SoDong << endl;
//
//}
//
//void XuatDanhSachMayBay(MCONTROMB dsMB) {
//	for (int i = 0; i < dsMB.SoLgMB; i++) {
//		cout << "May Bay Thu " << i + 1;
//		XuatMotMayBay(*dsMB.data[i]);
//		cout << endl;
//
//	}
//}
//
//void XuatMotChuyenBay(ChuyenBay CB) {
//	cout << "MA CHUYEN BAY:" << CB.MaCB << endl;
//	cout << "GIO KHOI HANH:" << CB.GioKhoiHanh.Hour << ":" << CB.GioKhoiHanh.Minute << endl;
//	cout << "NGAY KHOI HANH:" << CB.NgayKhoiHanh.Ngay << "/" << CB.NgayKhoiHanh.Thang << "/" << CB.NgayKhoiHanh.Nam << endl;
//	cout << "SAN BAY DEN:" << CB.SanBayDen << endl;
//	cout << "SO HIEU MAY BAY:" << CB.SoHieuMB << endl;
//	cout << "TRANG THAI:" << CB.TrangThai << endl;
//	cout << "TONG SO VE:" << CB.TongSoVe << endl;
//
//
//}
//void XuatDanhSachChuyenBay(List l) {
//	int dem = 1;
//	for (NodeList* k = l.pHead; k != NULL; k = k->pNext) {
//		cout << "Chuyen Bay Thu " << dem++ << ":";
//		XuatMotChuyenBay(k->data);
//		cout << endl;
//	}
//}
//
//void XuatMotKhachHang(HanhKhach HK) {
//	cout << "CMND:" << HK.CMND << endl;
//	cout << "Ho:" << HK.Ho << endl;
//	cout << "Ten:" << HK.Ten << endl;
//	cout << "Phai:" << HK.Phai << endl;
//
//}
//
//void XuatDanhSachHanhKhach(TREE t) {
//	if (t == NULL) {
//		return;
//	}
//	XuatDanhSachHanhKhach(t->pLeft);
//	XuatMotKhachHang(t->data);
//	XuatDanhSachHanhKhach(t->pRight);
//
//
//}

////////////////////////////////////THONG KE///////////////////////////////////

HanhKhach LayThongTinKHTheoCMND(TREE t, string CMND)
{
	if (t != NULL)
	{
		if (t->data.CMND == CMND)
		{
			return t->data;
		}
		else if (t->data.CMND > CMND)
		{
			return LayThongTinKHTheoCMND(t->pLeft, CMND);
		}
		else
		{
			return LayThongTinKHTheoCMND(t->pRight, CMND);
		}
	}
}
void XuatDSHK1CB(TREE t, DanhSachVe DSVe[], int tam, int tam1, int toadoX, int toadoY)
{
	int j = 0;
	for (int i = tam; i < tam1; i++)
	{
		HanhKhach KH = LayThongTinKHTheoCMND(t, DSVe[i].CMND);
		gotoXY(toadoX + 1, toadoY + 4 + j);
		cout << CanDeuChuoi(ChuyenSoSangString(i), 9);
		gotoXY(toadoX + 11, toadoY + 4 + j);
		cout << CanDeuChuoi(DSVe[i].MaVe, 9);
		gotoXY(toadoX + 21, toadoY + 4 + j);
		cout << CanDeuChuoi(DSVe[i].CMND, 19);
		gotoXY(toadoX + 41, toadoY + 4 + j);
		cout << CanDeuChuoi(KH.Ho + " " + KH.Ten, 49);
		gotoXY(toadoX + 91, toadoY + 4 + j);
		if (KH.Phai == 1)
		{
			cout << CanDeuChuoi("Nam", 9);
		}
		else
			cout << CanDeuChuoi("Nu", 9);
		j = j + 2;
	}
	string str[] = { "STT","Ma Ve","CMND","Ho va Ten","Phai" };
	int DoDai[] = { 10,10,20,50,10 };
	GiaoDienXuat(toadoX, toadoY, 100, tam1 - tam, str, DoDai, 5);
}

//xuat danh sach hanh khach thuoc 1 CB theo ma chuyen 
void XuatDSHKTheoPage(List l, TREE t, int toadoX, int toadoY)
{
	string MCB;
	gotoXY(60, 10);
	ShowCur(1);
	cout << "Nhap Ma Chuyen Bay:";
	XuLyNhapMa1(MCB);
	ShowCur(0);
	gotoXY(60, 10);
	cout << "                                                                                        ";

	if (MCB.empty())
	{
		return;
	}
	NodeList* tamCB = LayThongTinCB(l, MCB);
	if (tamCB == NULL)
	{
		GiaoDienThongBao("CB K Ton Tai");
		return;
	}

	int n = 0;
	DanhSachVe *DSVe = new DanhSachVe[tamCB->data.SoVeDaDat];
	for (int i = 0; i < tamCB->data.TongSoVe; i++)
	{
		if (tamCB->data.DSVe[i].TrangThai == true)
		{
			DSVe[n++] = tamCB->data.DSVe[i];
		}
	}

	XoaManHinhChinh();
	int SoLgDong1Page = 7;
	int page = 1;
	int tam = 0;
	int tam1 = SoLgDong1Page;
	if (tam1 > n)
	{
		tam1 = n;
	}
	DeMuc("DS HK Thuoc CB " + tamCB->data.MaCB);
	gotoXY(52, 7);
	cout << CanDeuChuoi("Ngay Khoi Hanh:" + ChuyenSoSangString(tamCB->data.NgayKhoiHanh.Ngay) + "/" + ChuyenSoSangString(tamCB->data.NgayKhoiHanh.Thang) + "/" + ChuyenSoSangString(tamCB->data.NgayKhoiHanh.Nam) + " " + ChuyenSoSangString(tamCB->data.GioKhoiHanh.Hours) + ":" + ChuyenSoSangString(tamCB->data.GioKhoiHanh.Minute), 126);
	gotoXY(52, 8);
	cout << CanDeuChuoi("Noi Den: " + tamCB->data.SanBayDen, 126);
	XuatDSHK1CB(t, DSVe, tam, tam1, toadoX, toadoY);
	XuatPage(page);
	getch();
	char c;
	while (true)
	{
		if (kbhit())
		{
			c = getch();
			if (c == -32)
			{
				c = getch();
				if (c == 75)
				{
					if (tam != 0)
					{
						tam = tam - SoLgDong1Page;
						if (tam < 0)
						{
							tam = 0;
						}
						tam1 = tam + SoLgDong1Page;
						if (tam1 > n)
						{
							tam1 = n;
						}
						page--;
						XoaManHinhTuyChon(toadoX, toadoY + 4, 101, 20);
						DeMuc("DS HK Thuoc CB " + tamCB->data.MaCB);
						gotoXY(52, toadoYBox);
						cout << CanDeuChuoi("Ngay Khoi Hanh:" + ChuyenSoSangString(tamCB->data.NgayKhoiHanh.Ngay) + "/" + ChuyenSoSangString(tamCB->data.NgayKhoiHanh.Thang) + "/" + ChuyenSoSangString(tamCB->data.NgayKhoiHanh.Nam) + " " + ChuyenSoSangString(tamCB->data.GioKhoiHanh.Hours) + ":" + ChuyenSoSangString(tamCB->data.GioKhoiHanh.Minute), 126);
						gotoXY(52, toadoYBox + 1);
						cout << CanDeuChuoi("Noi Den: " + tamCB->data.SanBayDen, 126);
						XuatDSHK1CB(t, DSVe, tam, tam1, toadoX, toadoY);
						XuatPage(page);
					}
				}
				else if (c == 77)
				{
					if (tam1 < n)
					{
						tam = tam + SoLgDong1Page;
						tam1 = tam1 + SoLgDong1Page;
						if (tam1 > n)
						{
							tam1 = n;
						}
						page++;
						XoaManHinhTuyChon(toadoX, toadoY + 4, 101, 20);
						DeMuc("DS HK Thuoc CB " + tamCB->data.MaCB);
						gotoXY(52, toadoYBox);
						cout << CanDeuChuoi("Ngay Khoi Hanh:" + ChuyenSoSangString(tamCB->data.NgayKhoiHanh.Ngay) + "/" + ChuyenSoSangString(tamCB->data.NgayKhoiHanh.Thang) + "/" + ChuyenSoSangString(tamCB->data.NgayKhoiHanh.Nam) + " " + ChuyenSoSangString(tamCB->data.GioKhoiHanh.Hours) + ":" + ChuyenSoSangString(tamCB->data.GioKhoiHanh.Minute), 126);
						gotoXY(52, toadoYBox + 1);
						cout << CanDeuChuoi("Noi Den: " + tamCB->data.SanBayDen, 126);
						XuatDSHK1CB(t, DSVe, tam, tam1, toadoX, toadoY);
						XuatPage(page);
					}
				}
			}
			else if (c == 27)
			{
				return;
			}
		}
	}
}

void DSCacVeConTrong(MCONTROMB& MB, List l, int toadoX, int toadoY)
{
	DeMuc("DS CAC VE CON TRONG");
	string MCB;
	gotoXY(60, 10);
	ShowCur(1);
	cout << "Nhap Ma Chuyen Bay:";
	XuLyNhapMa1(MCB);
	ShowCur(0);
	gotoXY(60, 10);
	cout << "                                                                                        ";

	if (MCB.empty())
	{
		return;
	}
	NodeList* tamCB = LayThongTinCB(l, MCB);
	if (tamCB == NULL)
	{     
		GiaoDienThongBao("CB Khong Ton Tai");
		return;
	}
	MayBay* tamMB = LayThongTinMB(MB, tamCB->data.SoHieuMB);

	gotoXY(toadoX + 47, 32);
	SetColor(2);
	cout << "A01 :";
	gotoXY(toadoX + 52, 32);
	SetColor(7);
	cout << "\t Da Dat";
	gotoXY(toadoX + 47, 33);
	textcolor(7);
	cout << "A01 :\t Con Trong";

	int pointer1 = toadoY;
	int pointer2 = toadoX;

	int h = 0;
	for (int i = 0; i < tamMB->SoDong; i++)
	{
		pointer2 = toadoX;
		for (int j = 0; j < tamMB->SoDay; j++)
		{
			if (tamCB->data.DSVe[h].TrangThai == false)
			{
				SetColor(7);// mau xanh
				gotoXY(pointer2, pointer1);
				cout << tamCB->data.DSVe[h].MaVe;
			}
			else if (tamCB->data.DSVe[h].TrangThai == true)
			{
				SetColor(2); // mau trang
				gotoXY(pointer2, pointer1);
				cout << tamCB->data.DSVe[h].MaVe;
				//SetColor(7);
			}
			h++;
			pointer2 = pointer2 + 10;
		}
		pointer1++;
	}
	getch();
}

void XuatDanhSachCB(ChuyenBay CB[], int tam, int tam1, int toadoX, int toadoY)
{
	string str[] = { "Ma CB","Gio Khoi Hanh","Ngay Khoi Hanh","San Bay Den","So Hieu MB","So Ve Trong" };
	int DoRong[] = { 20,15,15,35,20,15 };

	GiaoDienXuat(toadoX, toadoY, 120, tam1 - tam, str, DoRong, 6);
	int j = 0;
	for (int i = tam; i < tam1; i++)
	{
		string t;
		string Ngay;
		gotoXY(toadoX + 1, toadoY + 4 + j);
		cout << CanDeuChuoi(CB[i].MaCB, 19);

		gotoXY(toadoX + 21, toadoY + 4 + j);
		if (CB[i].GioKhoiHanh.Hours < 10)
		{
			t = t + "0" + ChuyenSoSangString(CB[i].GioKhoiHanh.Hours);
		}
		else
			t = t + ChuyenSoSangString(CB[i].GioKhoiHanh.Hours);
		t.push_back(':');
		if (CB[i].GioKhoiHanh.Minute < 10)
		{
			t = t + "0" + ChuyenSoSangString(CB[i].GioKhoiHanh.Minute);
		}
		else
			t = t + ChuyenSoSangString(CB[i].GioKhoiHanh.Minute);
		cout << CanDeuChuoi(t, 14);

		gotoXY(toadoX + 36, toadoY + 4 + j);
		if (CB[i].NgayKhoiHanh.Ngay < 10)
		{
			Ngay = Ngay + "0" + ChuyenSoSangString(CB[i].NgayKhoiHanh.Ngay);
		}
		else
			Ngay = Ngay + ChuyenSoSangString(CB[i].NgayKhoiHanh.Ngay);
		Ngay.push_back('/');
		if (CB[i].NgayKhoiHanh.Thang < 10)
		{
			Ngay = Ngay + "0" + ChuyenSoSangString(CB[i].NgayKhoiHanh.Thang);
		}
		else
			Ngay = Ngay + ChuyenSoSangString(CB[i].NgayKhoiHanh.Thang);
		Ngay.push_back('/');
		Ngay = Ngay + ChuyenSoSangString(CB[i].NgayKhoiHanh.Nam);
		cout << CanDeuChuoi(Ngay, 14);

		gotoXY(toadoX + 51, toadoY + 4 + j);
		cout << CanDeuChuoi(CB[i].SanBayDen, 34);
		gotoXY(toadoX + 86, toadoY + 4 + j);
		cout << CanDeuChuoi(CB[i].SoHieuMB, 19);
		gotoXY(toadoX + 106, toadoY + 4 + j);
		cout << CanDeuChuoi(ChuyenSoSangString(CB[i].TongSoVe - CB[i].SoVeDaDat), 14);
		j = j + 2;
	}
}
void XuatDSCBTheoPage(ChuyenBay CB[], int n, int toadoX, int toadoY)
{
	XoaManHinhChinh();
	int SoLgDong1Page = 7;
	int page = 1;
	int tam = 0;
	int tam1 = SoLgDong1Page;
	if (tam1 > n)
	{
		tam1 = n;
	}
	DeMuc("DANH SACH CB");
	XuatDanhSachCB(CB, tam, tam1, toadoX, toadoY);
	XuatPage(page);
	char c;
	while (true)
	{
		if (kbhit())
		{
			c = getch();
			if (c == -32)
			{
				c = getch();
				if (c == 75)
				{
					if (tam != 0)
					{
						tam = tam - SoLgDong1Page;
						if (tam < 0)
						{
							tam = 0;
						}
						tam1 = tam + SoLgDong1Page;
						if (tam1 > n)
						{
							tam1 = n;
						}
						page--;
						XoaManHinhTuyChon(toadoX, toadoY + 4, 101, 20);
						DeMuc("DANH SACH CB");
						XuatDanhSachCB(CB, tam, tam1, toadoX, toadoY);
						XuatPage(page);
					}
				}
				else if (c == 77)
				{
					if (tam1 < n)
					{
						tam = tam + SoLgDong1Page;
						tam1 = tam1 + SoLgDong1Page;
						if (tam1 > n)
						{
							tam1 = n;
						}
						page++;
						XoaManHinhTuyChon(toadoX, toadoY + 4, 101, 20);
						DeMuc("DANH SACH CB");
						XuatDanhSachCB(CB, tam, tam1, toadoX, toadoY);
						XuatPage(page);
					}
				}

			}
			else if (c == 27)
			{
				return;
			}
		}
	}
}

void LayThongTinCBTheoDiaDiemThoiGian(List l, ChuyenBay CB[], string NoiDen, Date Ngay, int& n)
{
	for (NodeList* k = l.pHead; k != NULL; k = k->pNext)
	{
		/*if (k->data.SanBayDen == NoiDen && SoSanhNgay(k->data.NgayKhoiHanh, Ngay) == 3)
		{
			CB[n] = k->data;
			n++;
		}*/
	}
}
//danh sach chuyen bay khoi hanh
void TimKiemCB(List l, int toadoX, int toadoY)
{
	GiaoDienTimKiemCB(toadoX, toadoY);
	Date Ngay;
	LayNgayHienTai(Ngay);
	string NoiDen;

	gotoXY(toadoX + 2, toadoY - 2);
	if (Ngay.Ngay < 10)
	{
		cout << 0 << Ngay.Ngay;
	}
	else
		cout << Ngay.Ngay;
	gotoXY(toadoX + 12, toadoY - 2);
	if (Ngay.Thang < 10)
	{
		cout << 0 << Ngay.Thang;
	}
	else
		cout << Ngay.Thang;
	gotoXY(toadoX + 22, toadoY - 2);
	cout << Ngay.Nam;

	ShowCur(1);
	int pointer1 = toadoY - 6;
	while (true)
	{
		if (pointer1 == toadoY - 6)
		{
			gotoXY(toadoX + 2 + NoiDen.length(), pointer1 + 1);
			XuLyNhap_Chu(NoiDen, toadoX + 2, pointer1, 47);
			if (pointer1 < toadoY - 6)
			{
				pointer1 = toadoY - 6;
			}
		}
		else if (pointer1 == toadoY - 3)
		{
			ShowCur(0);

			SetColor(4);
			gotoXY(toadoX + 2, toadoY - 2);
			if (Ngay.Ngay < 10)
			{
				cout << 0 << Ngay.Ngay;
			}
			else
				cout << Ngay.Ngay;
			gotoXY(toadoX + 12, toadoY - 2);
			if (Ngay.Thang < 10)
			{
				cout << 0 << Ngay.Thang;
			}
			else
				cout << Ngay.Thang;
			gotoXY(toadoX + 22, toadoY - 2);
			cout << Ngay.Nam;

			if (kbhit())
			{
				char c;
				c = getch();
				if (c == 13)
				{
					XuLyNhapNgay(Ngay, toadoX - 5, pointer1, 7, 15);

				}
				else if (c == -32)
				{
					SetColor(7);
					gotoXY(toadoX + 2, toadoY - 2);
					if (Ngay.Ngay < 10)
					{
						cout << 0 << Ngay.Ngay;
					}
					else
						cout << Ngay.Ngay;
					gotoXY(toadoX + 12, toadoY - 2);
					if (Ngay.Thang < 10)
					{
						cout << 0 << Ngay.Thang;
					}
					else
						cout << Ngay.Thang;
					gotoXY(toadoX + 22, toadoY - 2);
					cout << Ngay.Nam;
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
						if (pointer2 == toadoX + 15
							&& !NoiDen.empty())
						{
							DinhDangChuoi(NoiDen);
							ChuyenBay* CB = new ChuyenBay[l.n];
							int n = 0;
							LayThongTinCBTheoDiaDiemThoiGian(l, CB, NoiDen, Ngay, n);
							XuatDSCBTheoPage(CB, n, toadoXBox - 10, toadoYBox);
							return;
						}
						else if (pointer2 == toadoX + 30)
						{
							return;
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

void SapXepMB(MCONTROMB& MB)
{
	for (int i = 0; i < MB.SoLgMB - 1; i++)
	{
		for (int j = i + 1; j < MB.SoLgMB; j++)
		{
			if (MB.data[i]->SoLuotCB > MB.data[j]->SoLuotCB)
			{
				MayBay tam;
				tam = *MB.data[i];
				*MB.data[i] = *MB.data[j];
				*MB.data[j] = tam;
			}
		}
	}
}

void XuatDanhSachMB(MCONTROMB MB, int tam, int tam1, int toadoX, int toadoY)
{
	string str[] = { "So Hieu May Bay","Loai May Bay","So Luot Thuc Hien Chuyen Bay" };
	int DoRong[] = { 20,50,30 };
	GiaoDienXuat(toadoX, toadoY, 100, tam1 - tam, str, DoRong, 3);
	int j = 0;
	for (int i = tam; i < tam1; i++)
	{
		gotoXY(toadoX + 1, toadoY + 4 + j);
		cout << CanDeuChuoi(MB.data[i]->SoHieuMB, 19);
		gotoXY(toadoX + 21, toadoY + 4 + j);
		cout << CanDeuChuoi(MB.data[i]->LoaiMayBay, 49);
		gotoXY(toadoX + 71, toadoY + 4 + j);
		cout << CanDeuChuoi(ChuyenSoSangString(MB.data[i]->SoLuotCB), 29);
		j = j + 2;
	}
}
void ThongKeSoLuotThucHienCB(MCONTROMB MB, int toadoX, int toadoY)
{
	XoaManHinhChinh();
	int SoLgDong1Page = 10;
	int page = 1;
	int tam = 0;
	int tam1 = SoLgDong1Page;//vi tri bang vi tri cua so luong dong
	if (tam1 > MB.SoLgMB)//so luong dong cua 1 page phu thuoc so luong may bay nen k the vuot qua dc
	{
		tam1 = MB.SoLgMB;
	}
	DeMuc("THONG KE SO LUOT THUC HIEN CHUYEN BAY");
	XuatDanhSachMB(MB, tam, tam1, toadoX, toadoY);
	XuatPage(page);
	char c;
	while (true)
	{
		if (kbhit())
		{
			c = getch();
			if (c == -32)
			{
				c = getch();
				if (c == 75)//trai
				{
					if (tam != 0)
					{
						tam = tam - SoLgDong1Page;
						if (tam < 0)
						{
							tam = 0;
						}
						tam1 = tam + SoLgDong1Page;//tam moi+so luong dong
						if (tam1 > MB.SoLgMB)
						{
							tam1 = MB.SoLgMB;
						}
						page--;
						XoaManHinhTuyChon(toadoX, toadoY + 4, 101, 20);
						DeMuc("THONG KE SO LUOT THUC HIEN CHUYEN BAY");
						XuatDanhSachMB(MB, tam, tam1, toadoX, toadoY);
						XuatPage(page);
					}
				}
				else if (c == 77)
				{
					if (tam1 < MB.SoLgMB)
					{
						tam = tam + SoLgDong1Page;
						tam1 = tam1 + SoLgDong1Page;
						if (tam1 > MB.SoLgMB)
						{
							tam1 = MB.SoLgMB;
						}
						page++;
						XoaManHinhTuyChon(toadoX, toadoY + 4, 101, 20);
						DeMuc("THONG KE SO LUOT THUC HIEN CHUYEN BAY");
						XuatDanhSachMB(MB, tam, tam1, toadoX, toadoY);
						XuatPage(page);
					}
				}
			}
			else if (c == 27)
			{
				return;
			}
		}
	}
}