#pragma once
#include "CTDL.h"
#include "HamXuLyChuyenBay.h"
#include "HamXuLyMayBay.h"
#include "HanhKhach.h"
#include "XuLyLT.h"

void ChonVe(DanhSachVe DSV[], int toadoX, int toadoY, int SoDong, int SoDay, string& MaVe, int& VT)
{
	int pointer1 = toadoY;//toa do ban dau
	int pointer2 = toadoX;

	int pointer1Tam = 0;//toa do cua cai dung truoc
	int pointer2Tam = 0;
	string MaVeTam;

	bool KT = false;
	int h = 0;//ban dau vi tri la 0
	int VTTam = 0;//vi tri cua cai dung truoc luc dau la 0
	for (int i = 0; i < SoDong; i++)
	{
		pointer2 = toadoX;
		for (int j = 0; j < SoDay; j++)
		{
			if (DSV[h].TrangThai == false && KT == false)//neu chua dat ve va co la false
			{
				KT = true;
				SetColor(4);//mau do
				gotoXY(pointer2, pointer1);
				cout << DSV[h].MaVe;
				MaVeTam = DSV[h].MaVe;
				VTTam = h;
				SetColor(7);

				pointer1Tam = pointer1;
				pointer2Tam = pointer2;
			}
			else if (DSV[h].TrangThai == true)
			{
				SetColor(2);//mau xanh
				gotoXY(pointer2, pointer1);
				cout << DSV[h].MaVe;
				SetColor(7);
			}
			h++;
			pointer2 = pointer2 + 10;
		}
		pointer1++;
	}

	pointer1 = pointer1Tam;
	pointer2 = pointer2Tam;

	char c;
	while (true)
	{
		if (kbhit())
		{
			c = getch();
			if (c == -32)
			{
				c = getch();
				if (c == 72)
				{
					if (pointer1 == toadoY)//vi tri tren cung khong len duoc nua
					{

					}
					else
					{
						if (DSV[VTTam - SoDay].TrangThai == true)
						{
							int pointer1Tam2 = pointer1 - 2;
							for (int i = VTTam - SoDay * 2; i >= 0; i--)
							{
								if (DSV[i].TrangThai == false)
								{
									pointer1Tam = pointer1;
									pointer2Tam = pointer2;

									pointer1 = pointer1Tam2;
									MaVeTam = DSV[VTTam].MaVe;
									VTTam = i;
									break;
								}
								pointer1Tam2--;
							}
						}
						else
						{
							pointer1Tam = pointer1;
							pointer2Tam = pointer2;
							MaVeTam = DSV[VTTam].MaVe;

							pointer1 = pointer1 - 1;
							VTTam = VTTam - SoDay;
						}
					}
				}
				else if (c == 80)
				{
					if (pointer1 == toadoY + SoDong - 1)//cuoi day
					{

					}
					else
					{
						if (DSV[VTTam + SoDay].TrangThai == true)
						{
							int pointer1Tam2 = pointer1 + 2;
							for (int i = VTTam + SoDay * 2; i < SoDay * SoDong; i++)
							{
								if (DSV[i].TrangThai == false)
								{
									pointer1Tam = pointer1;
									pointer2Tam = pointer2;

									pointer1 = pointer1Tam2;
									MaVeTam = DSV[VTTam].MaVe;
									VTTam = i;

									break;
								}
								pointer1Tam2++;
							}
						}
						else
						{
							pointer1Tam = pointer1;
							pointer2Tam = pointer2;
							MaVeTam = DSV[VTTam].MaVe;

							pointer1 = pointer1 + 1;
							VTTam = VTTam + SoDay;
						}
					}
				}
				else if (c == 75)
				{
					if (pointer2 == toadoX)//dau trai
					{

					}
					else
					{
						if (DSV[VTTam - 1].TrangThai == true)
						{
							int pointer2Tam2 = pointer2 - 20;//toa do x
							int pointer1Tam2 = pointer1;//tdo y
							for (int i = VTTam - 2; i >= 0; i--)
							{
								if (DSV[i].TrangThai == false)
								{
									pointer1Tam = pointer1;
									pointer2Tam = pointer2;

									if (pointer2Tam2 < toadoX)//xet truong hop o cuoi ben trai
									{
										pointer1Tam2--;
										pointer2Tam2 = toadoX + (10 * SoDay) - 10;

									}
									pointer2 = pointer2Tam2;
									pointer1 = pointer1Tam2;
									MaVeTam = DSV[VTTam].MaVe;
									VTTam = i;

									break;
								}
								pointer2Tam2 = pointer2Tam2 - 10;
								if (pointer2Tam2 < toadoX)
								{
									pointer1Tam2--;
									pointer2Tam2 = toadoX + (10 * SoDay) - 10;
								}
							}
						}
						else
						{
							pointer1Tam = pointer1;
							pointer2Tam = pointer2;
							MaVeTam = DSV[VTTam].MaVe;

							pointer2 = pointer2 - 10;
							VTTam--;
						}
					}
				}
				else if (c == 77)
				{
					if (pointer2 == toadoX + (10 * SoDay) - 10)
					{

					}
					else
					{
						if (DSV[VTTam + 1].TrangThai == true)
						{
							int pointer2Tam2 = pointer2 + 20;
							int pointer1Tam2 = pointer1;
							for (int i = VTTam + 2; i < SoDay * SoDong; i++)
							{
								if (DSV[i].TrangThai == false)
								{
									pointer1Tam = pointer1;
									pointer2Tam = pointer2;

									if (pointer2Tam2 > toadoX + (10 * SoDay) - 10)
									{
										pointer1Tam2++;
										pointer2Tam2 = toadoX;
									}
									pointer2 = pointer2Tam2;
									MaVeTam = DSV[VTTam].MaVe;
									VTTam = i;

									break;
								}
								pointer2Tam2 = pointer2Tam2 + 10;
								if (pointer2Tam2 > toadoX + (10 * SoDay) - 10)
								{
									pointer1Tam2++;
									pointer2Tam2 = toadoX;
								}
							}
						}
						else
						{
							pointer1Tam = pointer1;
							pointer2Tam = pointer2;
							MaVeTam = DSV[VTTam].MaVe;

							pointer2 = pointer2 + 10;
							VTTam++;
						}
					}
				}
			}
			else if (c == 13)
			{
				DSV[VTTam].TrangThai = true;
				MaVe = DSV[VTTam].MaVe;
				VT = VTTam;
				return;
			}
			else if (c == 27)
			{
				return;
			}

			/*gotoXY(100, 10);
			cout << pointer1 <<"\t"<< pointer1tam <<"\t"<< pointer2 <<"\t"<< pointer2tam;*/
			SetColor(7);
			gotoXY(pointer2Tam, pointer1Tam);
			cout << MaVeTam;

			SetColor(4);
			gotoXY(pointer2, pointer1);
			cout << DSV[VTTam].MaVe;
			SetColor(7);
		}
	}
}

void DangKiVe(MCONTROMB& MB, TREE& t, List& l, int toadoX, int toadoY)
{
	bool KTTonTai = false;
	int tamVT = 0;
	string MCB;
	string CMND;
	string MaVe;
	HanhKhach tamKH;
	NodeList* tamCB = NULL;
	GiaoDienDatVe(toadoX, toadoY);
	ShowCur(1);
a: 
	do 
	{ //kiem tra trang thai CB
		gotoXY(toadoX + 2, toadoY - 5);
		cout << "                             ";
		gotoXY(toadoX + 2, toadoY - 5);
		XuLyNhapMa1(MCB);
		if (MCB.empty())
		{
			return;
		}
		tamCB = LayThongTinCB(l, MCB);

		if (tamCB == NULL)
		{
			gotoXY(toadoX + 52, toadoY - 5);
			cout << "MCB K Ton Tai";
			MCB.clear();
		}
		else if (tamCB->data.TrangThai == 0)
		{
			gotoXY(toadoX + 52, toadoY - 5);
			cout << "CB Da Huy";
			MCB.clear();
		}
		else if (tamCB->data.TrangThai == 2)
		{
			gotoXY(toadoX + 52, toadoY - 5);
			cout << "CB Da Het Ve";
			MCB.clear();
		}
		else if (tamCB->data.TrangThai == 3)
		{
			gotoXY(toadoX + 52, toadoY - 5);
			cout << "CB Da Hoan Tat";
			MCB.clear();
		}
	} while (tamCB == NULL || tamCB->data.TrangThai != 1);
	gotoXY(toadoX + 52, toadoY - 5);
	cout << "                 ";

	MayBay tamMB = *LayThongTinMB(MB, tamCB->data.SoHieuMB);
	int pointer1 = toadoY - 3;

	// Lay Ve Dau Tien Chua Dat
	for (int i = 0; i < tamCB->data.TongSoVe; i++)
	{
		if (tamCB->data.DSVe[i].TrangThai == false)
		{
			tamCB->data.DSVe[i].TrangThai = true;
			tamVT = i;
			MaVe = tamCB->data.DSVe[i].MaVe;
			gotoXY(132, 27);
			cout << tamCB->data.DSVe[i].MaVe;
			break;
		}
	}

	while (true)
	{
		if (pointer1 == toadoY - 3)//CMND
		{
			//xoa nhap lai
		b:
			KTTonTai = false;
			tamKH.Ho.clear();
			tamKH.Ten.clear();
			CMND.clear();

			gotoXY(toadoX + 2, toadoY + 1);
			cout << "                                              ";//ho
			gotoXY(toadoX + 2, toadoY + 4);
			cout << "                                              ";//ten
			gotoXY(135, 24);
			cout << "   ";
			gotoXY(toadoX + 2, toadoY - 2);
			cout << "                                      ";

			gotoXY(toadoX + 2, toadoY - 2);
			ShowCur(1);
			XuLyNhapCMND1(CMND);
			ShowCur(0);
			if (CMND.empty())//neu cmnd rong thi esc thoa ra nhap lai tu MCB
			{
				gotoXY(toadoX + 2, toadoY - 2);
				cout << "                                      ";
				MCB.clear();
				goto a;//kt lai trang thai CB
			}

			if (KTTonTaiHangKhach(t, CMND, tamKH))//kiem tra xem khach da ton tai-> in ra thong tin san
			{
				gotoXY(toadoX + 2, toadoY + 1);
				cout << tamKH.Ho;
				gotoXY(toadoX + 2, toadoY + 4);
				cout << tamKH.Ten;
				gotoXY(132, 24);
				if (tamKH.Phai == 1)
					cout << "Nam";
				else
					cout << "Nu";
				//pointer1 = toadoY + 9;//chon ve

				if (KT_CMND_Tren1CB(tamCB->data, CMND) == true) {
					GiaoDienThongBao("CMND DA TON TAI TREN CHUYEN BAY!");
					XoaManHinhTuyChon(toadoXBox + 46 - 15, toadoYBox + 5, 40, 10);
					VeHCN(toadoX, toadoY - 3, 50, 2, 7);


					VeHCN(toadoX, toadoY, 50, 2, 7);
					VeHCN(toadoX, toadoY + 3, 50, 2, 7);
					VeHCN(130, 23, 15, 2, 4);
					//goto b;//nhap lai thong tin
				}
				else 
				{
					if (KiemTraHanhKhachCungThoiDiem(l, CMND, tamCB->data)) {//k dc dat ve tren 2 chuyen bay o cung thoi diem
						GiaoDienThongBao("CMND DA TON TAI TREN CHUYEN BAY KHAC!");
						XoaManHinhTuyChon(toadoXBox + 46 - 15, toadoYBox + 5, 40, 10);
						VeHCN(toadoX, toadoY - 3, 50, 2, 7);

						VeHCN(toadoX, toadoY, 50, 2, 7);
						VeHCN(toadoX, toadoY + 3, 50, 2, 7);
						VeHCN(130, 23, 15, 2, 4);
					}
					else
						pointer1 = toadoY + 9;
				}
			}
			else
			{
				KTTonTai = true;//khach chua ton tai
				pointer1 = pointer1 + 3;
				ShowCur(1);
			}
		}
		else if (pointer1 == toadoY)//ho
		{
			gotoXY(toadoX + 2 + tamKH.Ho.length(), pointer1 + 1);
			XuLyNhap_Chu(tamKH.Ho, toadoX + 2, pointer1, 47);
		}
		else if (pointer1 == toadoY + 3)//ten
		{
			gotoXY(toadoX + 2 + tamKH.Ten.length(), pointer1 + 1);
			XuLyNhap_Chu(tamKH.Ten, toadoX + 2, pointer1, 47);
		}
		else if (pointer1 == toadoY + 6)//phai
		{
			ChonPhai(toadoX + 5, toadoY + 7, tamKH.Phai, pointer1);
		}
		else if (pointer1 == toadoY + 9)//chon ve
		{
			ShowCur(0);
			SetColor(4);
			gotoXY(toadoX + 2, toadoY + 10);
			cout << "Enter De Nhap Lai";
			textcolor(7);
			char c;
			while (true)
			{
				if (kbhit())
				{
					c = getch();
					if (c == 13)//bat phim enter cho chon ve
					{
						tamCB->data.DSVe[tamVT].TrangThai = false;
						XoaManHinhChinh();
						GiaoDienChonVe(toadoXBox + 30, toadoYBox + 5, tamMB.SoDay, tamMB.SoDong);
						ChonVe(tamCB->data.DSVe, toadoXBox + 30, toadoYBox + 5, tamMB.SoDong, tamMB.SoDay, MaVe, tamVT);

						XoaManHinhChinh();
						GiaoDienDatVe(toadoX, toadoY);
						gotoXY(toadoX + 2, toadoY - 5);
						cout << tamCB->data.MaCB;
						gotoXY(toadoX + 2, toadoY - 2);
						cout << CMND;
						gotoXY(toadoX + 2, toadoY + 1);
						cout << tamKH.Ho;
						gotoXY(toadoX + 2, toadoY + 4);
						cout << tamKH.Ten;
						gotoXY(135, 24);
						if (tamKH.Phai == 1)
						{
							cout << "Nam";
						}
						else
							cout << "Nu";
						gotoXY(132, 27);
						cout << MaVe;
						break;
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							if (KTTonTai == true)//chua ton tai
							{
								pointer1 = pointer1 - 3;
							}
							else//ton tai cho len cmnd
								pointer1 = toadoY - 3;
							break;

							ShowCur(1);
							gotoXY(toadoX + 2, toadoY + 10);
							cout << "Enter De Nhap Lai";
							break;
						}
						else if (c == 80)
						{
							pointer1 = pointer1 + 3;

							gotoXY(toadoX + 2, toadoY + 10);
							cout << "Enter De Nhap Lai";
							break;
						}
					}
				}
			}
		}
		else if (pointer1 == toadoY + 12) // save hoac huy
		{
			ShowCur(0);
			int pointer2 = toadoX + 15;

			SetColor(5);
			gotoXY(pointer2, toadoY + 15);
			cout << "Dang Ki";
			SetColor(7);
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (pointer2 == toadoX + 15)//xac nhan
						{
							// Neu khach hang chua co thi them vao
							if (KTTonTai == true)
							{
								DinhDangChuoi(tamKH.Ten);
								DinhDangChuoi(tamKH.Ho);
								tamKH.CMND = CMND;
								ThemKhachVAoCay(t, tamKH);
							}
							tamCB->data.SoVeDaDat++;
							// Kiem tra lai CB 
							if (tamCB->data.TongSoVe == tamCB->data.SoVeDaDat)
							{
								tamCB->data.TrangThai = 2;//het ve
							}
							tamCB->data.DSVe[tamVT].CMND = CMND;
							return;
						}
						else if (pointer2 == toadoX + 30)//k dk nua
						{
							tamCB->data.DSVe[tamVT].TrangThai = false;
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
				}
			}
		}
	}
}

void HuyVe(List& l, TREE& t, int toadoX, int toadoY)
{
	GiaoDienHuyVe(toadoX, toadoY);
	int pointer1 = toadoY - 6;
	string CMND;
	string MCB;
	ShowCur(1);
	while (true)
	{
		if (pointer1 == toadoY - 6)//MCB
		{
			gotoXY(toadoX + 2 + MCB.length(), pointer1 + 1);
			XuLyNhapMa(MCB, toadoX + 2, pointer1);
			if (pointer1 < toadoY - 6)
			{
				pointer1 = toadoY - 6;
			}
			if (!KTraTrungMaCB(l, MCB)) {
				GiaoDienThongBao("Ma chuyen bay khong ton tai!");
				return;
			}
		}
		else if (pointer1 == toadoY - 3)//cmnd
		{
			gotoXY(toadoX + 2 + CMND.length(), pointer1 + 1);
			XuLyNhapCMND(CMND, toadoX + 2, pointer1);
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
						if (pointer2 == toadoX + 15
							&& !CMND.empty()
							&& !MCB.empty()
							&& tamCB->data.TrangThai != 3
							&& tamCB != NULL)
						{
							for (int i = 0; i < tamCB->data.TongSoVe; i++)
							{
								if (tamCB->data.DSVe[i].CMND == CMND)
								{
									tamCB->data.DSVe[i].TrangThai = false;
									tamCB->data.SoVeDaDat--;

									if (tamCB->data.TrangThai == 2)
									{
										tamCB->data.TrangThai = 1;
									}
									GiaoDienThongBao("Huy Ve Thanh Cong!");
									break;
								}
							} 
							return;
						}
						else if (pointer2 == toadoX + 30)
						{
							return;
						}
						else if (tamCB->data.TrangThai == 3)
						{
							GiaoDienThongBao("Chuyen Bay Da Hoan Tat!");
							return;
						}
						else if (!KT_CMND_Tren1CB(tamCB->data, CMND)) {
							GiaoDienThongBao("Hanh Khach khong co trong chuyen bay nay");
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

