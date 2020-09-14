#pragma once
#include "HamXuLyMayBay.h"
#include "XuLyLT.h"

void ThemMB(MCONTROMB& MB, int toadoX, int toadoY)
{
	GiaoDienNhapMayBay(toadoX, toadoY);
	int pointer1 = toadoY - 6;
	ShowCur(1);

	MB.data[MB.SoLgMB] = new MayBay;
	MB.data[MB.SoLgMB]->SoDay = 0;
	MB.data[MB.SoLgMB]->SoDong = 0;
	while (true)
	{
		if (pointer1 == toadoY - 6)//so hieu
		{
			gotoXY(toadoX + 2 + MB.data[MB.SoLgMB]->SoHieuMB.length(), pointer1 + 1);
			XuLyNhapMa(MB.data[MB.SoLgMB]->SoHieuMB, toadoX + 2, pointer1);
			if (pointer1 < toadoY - 6)
			{
				pointer1 = toadoY - 6;
			}
		}
		if (KTraTrungSoHieuMB(MB, MB.data[MB.SoLgMB]->SoHieuMB) == true) {
			textcolor(7);
			gotoXY(107, 30);
			cout << "SO HIEU MAY BAY PHAI LA DUY NHAT!";
		}
		else if (pointer1 == toadoY - 3)//Loai may bay
		{
			gotoXY(toadoX + 2 + MB.data[MB.SoLgMB]->LoaiMayBay.length(), pointer1 + 1);
			XuLyNhapMa(MB.data[MB.SoLgMB]->LoaiMayBay, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY) // nhap day
		{
			gotoXY(toadoX + 2 + DemChuSo(MB.data[MB.SoLgMB]->SoDay), pointer1 + 1);
			XuLyNhapSo(MB.data[MB.SoLgMB]->SoDay, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY + 3) // nhap dong
		{
			gotoXY(toadoX + 2 + DemChuSo(MB.data[MB.SoLgMB]->SoDong), pointer1 + 1);
			XuLyNhapSo(MB.data[MB.SoLgMB]->SoDong, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY + 6) // save hoac huy
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
							&& !MB.data[MB.SoLgMB]->SoHieuMB.empty()
							&& !MB.data[MB.SoLgMB]->LoaiMayBay.empty()
							&& MB.data[MB.SoLgMB]->SoDay > 0
							&& MB.data[MB.SoLgMB]->SoDong > 0)
						{
							MB.data[MB.SoLgMB]->SoLuotCB = 0;
							MB.SoLgMB++;
							return;
						}
						else if (pointer2 == toadoX + 30)
						{
							delete MB.data[MB.SoLgMB];
							return;
						}
						/*else if (KTraTrungSoHieuMB(MB, MB.data[MB.SoLgMB]->SoHieuMB) == true) {
							textcolor(7);
							gotoXY(107, 30);
							cout << "SO HIEU MAY BAY PHAI LA DUY NHAT!";
						}*/

						else
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "Vui Long Dien Day Du Thong Tin!";
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
							cout << "Dang Ki";
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
				gotoXY(pointer2, toadoY + 10);
				if (pointer2 == toadoX + 15)
				{
					cout << "Dang Ki";
					textcolor(7);
					gotoXY(toadoX + 30, toadoY + 10);
					cout << "Cancel";
				}
				else if (pointer2 == toadoX + 30)
				{
					cout << "Cancel";
					textcolor(7);
					gotoXY(toadoX + 15, toadoY + 10);
					cout << "Dang Ki";
				}

				Sleep(100);
			}
		}
	}
}
void XoaMB(MCONTROMB& MB)
{
	string SoHieuMB;
	gotoXY(60, 10);
	cout << "Nhap So Hieu May Bay:";
	XuLyNhapMa1(SoHieuMB);

	if (SoHieuMB.empty())
	{
		return;
	}

	bool KTSoHieu = false;
	for (int i = 0; i < MB.SoLgMB; i++)
	{
		if (MB.data[i]->SoHieuMB == SoHieuMB)
		{
			if (MB.data[i]->SoLuotCB == 0)//may bay chua bay chuyen nao
			{
				for (int j = i; j < MB.SoLgMB - 1; j++)
				{
					*MB.data[j] = *MB.data[j + 1];
				}
				delete MB.data[MB.SoLgMB - 1];
				MB.SoLgMB--;
				GiaoDienThongBao("Xoa Thanh Cong");
				KTSoHieu = true;
				return;
			}
			else
			{
				GiaoDienThongBao("MB KHONG THE XOA");
				return;
			}

		}

	}
	if (KTSoHieu == false) {
		GiaoDienThongBao("So Hieu May Bay Khong Ton Tai!");
	}
}
void SuaMB(MCONTROMB& MB, int toadoX, int toadoY)
{
	string SoHieuMB;
	gotoXY(60, 10);
	cout << "Nhap So Hieu May Bay:";
	//gotoXY(20, 15);
	ShowCur(1);
	XuLyNhapMa1(SoHieuMB);
	ShowCur(0);
	gotoXY(60, 10);
	cout << "                                                                                        ";

	int h = 300;
	if (SoHieuMB.empty())
	{
		return;
	}
	for (int i = 0; i < MB.SoLgMB; i++)
	{
		if (MB.data[i]->SoHieuMB == SoHieuMB)
		{
			if (MB.data[i]->SoLuotCB == 0)//chua co chuyen bay
			{
				h = i;
				break;
			}
			else //may bay da thuc hien chuyen bay r thi k dc sua 
			{
				GiaoDienThongBao("MB KHONG THE SUA");
				return;
			}
		}
	}
	if (h == 300) {//h!=300 da duoc kiem tra so hieu may bay ton tai
		GiaoDienThongBao("SO HIEU KHONG TON TAI");
		return;
	}

	MayBay MBTam = *MB.data[h];//de luu lai gia tri truoc do

	GiaoDienNhapMayBay(toadoX, toadoY);
	gotoXY(toadoX + 2, toadoY - 5);
	cout << MB.data[h]->SoHieuMB;
	gotoXY(toadoX + 2, toadoY - 2);
	cout << MB.data[h]->LoaiMayBay;
	gotoXY(toadoX + 2, toadoY + 1);
	cout << MB.data[h]->SoDay;
	gotoXY(toadoX + 2, toadoY + 4);
	cout << MB.data[h]->SoDong;

	int pointer1 = toadoY - 3;
	ShowCur(1);
	while (true)
	{
		/*if (pointer1 == toadoY - 6)
		{
			gotoXY(toadoX + 2 + MB.data[h]->SoHieuMB.length(), pointer1 + 1);
			XuLyNhapMa(MB.data[h]->SoHieuMB, toadoX + 2, pointer1);
			if (pointer1 < toadoY - 6)
			{
				pointer1 = toadoY - 6;
			}
		}
		else*/ if (pointer1 == toadoY - 3)
		{
			gotoXY(toadoX + 2 + MB.data[h]->LoaiMayBay.length(), pointer1 + 1);
			XuLyNhapMa(MB.data[h]->LoaiMayBay, toadoX + 2, pointer1);
			if (pointer1 < toadoY - 3)
			{
				pointer1 = toadoY - 3;
			}
		}
		else if (pointer1 == toadoY) // nhap day
		{
			gotoXY(toadoX + 2 + DemChuSo(MB.data[h]->SoDay), pointer1 + 1);
			XuLyNhapSo(MB.data[h]->SoDay, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY + 3) // nhap dong
		{
			gotoXY(toadoX + 2 + DemChuSo(MB.data[h]->SoDong), pointer1 + 1);
			XuLyNhapSo(MB.data[h]->SoDong, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY + 6) // save hoac huy
		{
			ShowCur(0);
			int pointer2 = toadoX + 15;//xac nhan
			while (true)
			{
				if (kbhit())//ham kiem tra co su kiem bat phim hay k
				{
					char c = getch();
					if (c == 13)//bat phim tai toa do xac nhan
					{
						if (pointer2 == toadoX + 15
							&& !MB.data[h]->SoHieuMB.empty()
							&& !MB.data[h]->LoaiMayBay.empty()
							&& MB.data[h]->SoDay > 0
							&& MB.data[h]->SoDong > 0)
						{
							return;
						}
						else if (pointer2 == toadoX + 30)//huy
						{
							*MB.data[h] = MBTam;//tra laij gia tri ban dau
							return;
						}
						else
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "Vui Long Dien Day Du Thong Tin";
						}
					}
					//bat phim tu dang o toa do xac nhan
					else if (c == -32)//ngan viec moi lan nhan phim mui ten se luon co dong in gia tri ascii -32 neu xay ra thi thuc hien get lai
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "Cancel";
							gotoXY(toadoX + 15, toadoY + 10);
							cout << "Dang Ki";
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

				SetColor(5);//bat mau tim cho xac nhan vs dang ki
				gotoXY(pointer2, toadoY + 10);
				if (pointer2 == toadoX + 15)
				{
					cout << "Dang Ki";
					textcolor(7);
					gotoXY(toadoX + 30, toadoY + 10);
					cout << "Cancel";
				}
				else if (pointer2 == toadoX + 30)
				{
					cout << "Cancel";
					textcolor(7);
					gotoXY(toadoX + 15, toadoY + 10);
					cout << "Dang Ki";
				}

				Sleep(100);
			}
		}
	}
}

