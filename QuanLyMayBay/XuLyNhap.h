
void XuLyNhapMa(string& InPut, int toadoX, int& toadoY)
{
	char c;
	while (true)
	{
		c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)) && InPut.length() < 15)//so hoac chu in hoa
		{
			InPut.insert(InPut.begin() + InPut.length(), c);
			cout << c;
		}
		else if ((c >= 97 && c <= 122) && InPut.length() < 15)//chu thuong
		{
			c = c - 32;//doi chu thuong sang chu hoa
			InPut.insert(InPut.begin() + InPut.length(), c);
			cout << c;
		}
		else if (c == 8 && InPut.length()>0)//khoang trang va do dai duong
		{
			InPut.erase(InPut.begin() + InPut.length() - 1);//xoa khoang trang
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 13 && InPut.length() > 0)// phim enter va da nhap 
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 80)//nut xuog
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)//nut len
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void XuLyNhapMa1(string& InPut)//xu lý nhap ma k co toa do
{
	char c;
	while (true)
	{
		c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)) && InPut.length() < 15)
		{
			InPut.insert(InPut.begin() + InPut.length(), c);
			cout << c;
		}
		else if ((c >= 97 && c <= 122) && InPut.length() < 15)
		{
			c = c - 32;
			InPut.insert(InPut.begin() + InPut.length(), c);
			cout << c;
		}
		else if (c == 8 && InPut.length() > 0)
		{
			InPut.erase(InPut.begin() + InPut.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 13 && InPut.length() > 0)// neu la phim enter
		{
			break;
		}
		else if (c == 27)
		{
			InPut.clear();
			break;
		}
	}
}
void XuLyNhap_Chu(string& InPut, int toadoX, int& toadoY, int LenghtMax)
{
	char c;
	while (true)
	{
		char c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && InPut.length() < LenghtMax)
		{
			InPut.insert(InPut.begin() + InPut.length(), c);
			cout << c;
		}
		else if (c == 8 && InPut.length()>0)
		{
			InPut.erase(InPut.begin() + InPut.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 32 && InPut.length() < LenghtMax && InPut.length() != 0 && InPut[whereX() - toadoX - 1] != ' ')
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), ' ');
			cout << c;
		}
		else if (c == 13 && InPut.length() > 0)// neu la phim enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)//trai
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void XuLyNhapSo(int& n, int toadoX, int& toadoY)
{
	string x;
	x = ChuyenSoSangString1(n);
	char c;
	while (true)
	{
		c = getch();
		if ((c >= 48 && c <= 57) && x.length()<10)// neu la so
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
		else if (c == 8 && x.length()>0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 13 && x.length() > 0)// neu la phim enter
		{
			toadoY = toadoY + 3;
			n = atoi(x.c_str());
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 80)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void XuLyNhapCMND1(string &InPut)//xu lý khong co toa do
{
	char c;
	while (true)
	{
		c = getch();
		if ((c >= 48 && c <= 57) && InPut.length() < 10)// neu la so
		{
			InPut.insert(InPut.begin() + InPut.length(), c);
			cout << c;
		}
		else if (c == 8 && InPut.length() > 0)
		{
			InPut.erase(InPut.begin() + InPut.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 13 && InPut.length() > 0)// neu la phim enter
		{
			break;
		}
		else if (c == 27)
		{
			InPut.clear();
			break;
		}
	}
}

void XuLyNhapCMND(string &InPut, int toadoX, int &toadoY)
{
	char c;
	while (true)
	{
		c = getch();
		if ((c >= 48 && c <= 57) && InPut.length()<10)// neu la so thì
		{
			InPut.insert(InPut.begin() + InPut.length(), c);
			cout << c;
		}
		else if (c == 8 && InPut.length()>0)
		{
			InPut.erase(InPut.begin() + InPut.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 13 && InPut.length() > 0)// neu là phím enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}

void XuatNgay(Date Ngay, int maunen, int toadoX, int toadoY)
{

	textcolor(maunen);
	gotoXY(toadoX + 7, toadoY + 1);
	if (Ngay.Ngay < 10)
	{
		cout << 0 << Ngay.Ngay;
	}
	else
		cout << Ngay.Ngay;

	gotoXY(toadoX + 17, toadoY + 1);
	if (Ngay.Thang < 10)
	{
		cout << 0 << Ngay.Thang;
	}
	else
		cout << Ngay.Thang;
	gotoXY(toadoX + 27, toadoY + 1);
	cout << Ngay.Nam;
}
void XuLyNhapNgay(Date& Ngay, int toadoX, int &toadoY, int maunen, int mauchu)
{
	Date NgayHienTai;
	LayNgayHienTai(NgayHienTai);
	ToMauHCN(toadoX, toadoY + 2, 38, 8, 238);
	textcolor(maunen);

	int SoHangToiDa;//so hang 
	int	tamX, tamY;
	int pointer1 = toadoY + 3;
	int pointer2 = toadoX + 5;
	char c;
	ShowCur(0);
	while (true)
	{
		XuatNgay(Ngay, maunen, toadoX, toadoY);
		// Xuat Nam
		textcolor(224);
		gotoXY(toadoX + 15, toadoY + 3);
		cout << " ";
		gotoXY(toadoX + 22, toadoY + 3);
		cout << " ";
		gotoXY(toadoX + 17, toadoY + 3);
		cout << Ngay.Nam;
		// Xuat Thang
		gotoXY(toadoX + 14, toadoY + 4);
		cout << " ";
		gotoXY(toadoX + 24, toadoY + 4);
		cout << " ";
		gotoXY(toadoX + 16, toadoY + 4);
		if (Ngay.Thang < 10)
		{
			cout << "Thang0" << Ngay.Thang;

		}
		else
			cout << "Thang" << Ngay.Thang;
		//Xuat Ngay
		tamX = toadoX + 5, tamY = toadoY + 6;
		for (int i = 1; i <= SoNgayCuaThang(Ngay.Thang); i++)
		{
			gotoXY(tamX, tamY);
			tamX = tamX + 3;
			cout << i;
			if (i % 10 == 0)
			{
				tamY = tamY + 1;
				tamX = toadoX + 5;
			}
		}
		if (SoNgayCuaThang(Ngay.Thang) < 31)
		{
			for (int i = SoNgayCuaThang(Ngay.Thang); i < 31; i++)//nhung ngay k có trong thang thi de trang
			{
				gotoXY(tamX, tamY);
				cout << "  ";
			}
			SoHangToiDa = 7;
		}
		else
			SoHangToiDa = 8;

		if (kbhit())
		{
			c = getch();
			if (c == -32)
			{
				c = getch();
				if (c == 72)
				{
					if (pointer1 == toadoY + 3)
					{

					}
					else
						pointer1--;
				}
				else if (c == 80)
				{
					if (pointer1 == toadoY + SoHangToiDa)
					{
						pointer1 = toadoY + 3;//vong lai len cho nam 2019 khi xuong cuoi
					}
					//else if (pointer1 == toadoY + tam - ((2 + SoNgayCuaThang(NgayHienTai.Thang) % 30) - NgayHienTai.Ngay / 10))//Khong cho lon hon ngay hien tai
					//{

					//}
					else
					{
						pointer1++;
					}

				}
				else if (c == 75)
				{
					if (pointer1 == toadoY + 3)//nam
					{
						Ngay.Nam--;
					}
					else if (pointer1 == toadoY + 4)//thang
					{
						if (Ngay.Thang == 1)//lui thanh thang 12 cua nam truoc
						{
							Ngay.Thang = 12;
							Ngay.Nam--;
						}
						else
							Ngay.Thang--;
					}
					else if (pointer1 == toadoY + 8) //tu 31 tro ve 30
					{
						pointer1 = toadoY + 7;
						pointer2 = toadoX + 32;
					}
					else
					{
						if (pointer2 == toadoX + 5)//dau trai->cuoi phai 
						{
							pointer2 = toadoX + 32;
							pointer1--;
						}
						else
							pointer2 = pointer2 - 3;//chuyen qua ngay ben canh
					}
				}
				else if (c == 77)
				{
					if (pointer1 == toadoY + 3) //nam
					{
						//if (Ngay.Nam < NgayHienTai.Nam)
						{
							Ngay.Nam++;
						}
					}
					else if (pointer1 == toadoY + 4) // thang
					{
						/*if (Ngay.Nam == NgayHienTai.Nam && Ngay.Thang == NgayHienTai.Thang)
						{

						}
						else*/
						{
							if (Ngay.Thang == 12)
							{
								Ngay.Thang = 1;
								Ngay.Nam++;
							}
							else
								Ngay.Thang++;
						}
					}
					else // ngay
					{
						/*if (Ngay.Nam == NgayHienTai.Nam && Ngay.Thang == NgayHienTai.Thang && Ngay.Ngay == NgayHienTai.Ngay)
						{

						}
						else*/
						{
							if (pointer2 == toadoX + 32)
							{
								if (pointer1 == toadoY + SoHangToiDa)//cuoi phai,hang cuoi thi cho len hang dau
								{
									pointer1 = toadoY + 5;
									pointer2 = toadoX + 5;
								}
								else//cuoi phai thi cho xuong dau trai hang duoi
								{
									pointer2 = toadoX + 5;
									pointer1++;
								}
							}
							else
								pointer2 = pointer2 + 3;//qua phai
						}
					}
				}
			}
			else if (c == 13)
			{
				ShowCur(1);
				XoaHCN(toadoX, toadoY + 2, 40, 8, maunen);
				toadoY = toadoY + 3;
				return;
			}
			else if (c == 27)
			{
				LayNgayHienTai(Ngay);
				ShowCur(1);
				XuatNgay(Ngay, maunen, toadoX, toadoY);
				XoaHCN(toadoX, toadoY + 2, 40, 8, maunen);
				toadoY = toadoY + 3;
				return;
			}
		}

		// to mau
		textcolor(236);//mau do
		if (pointer1 == toadoY + 3) // nam
		{
			gotoXY(toadoX + 15, toadoY + 3);
			cout << char(174);//<<
			gotoXY(toadoX + 22, toadoY + 3);
			cout << char(175);//>>
			gotoXY(toadoX + 17, toadoY + 3);
			cout << Ngay.Nam;
		}
		else if (pointer1 == toadoY + 4) // thang
		{
			gotoXY(toadoX + 14, toadoY + 4);
			cout << char(174);
			gotoXY(toadoX + 24, toadoY + 4);
			cout << char(175);
			gotoXY(toadoX + 16, toadoY + 4);
			if (Ngay.Thang < 10)
			{
				cout << "Thang0" << Ngay.Thang;
			}
			else
				cout << "Thang" << Ngay.Thang;
		}
		else // ngay
		{
			gotoXY(pointer2, pointer1 + 1);
			if (pointer1 == toadoY + 5)
			{
				if (pointer2 == 32)
				{
					Ngay.Ngay = 10;
				}
				else
					Ngay.Ngay = (pointer2 - toadoX - 5) / 3 + 1;

			}
			else if (pointer1 == toadoY + 6)
			{
				if (pointer2 == 32)
				{
					Ngay.Ngay = 20;
				}
				else
					Ngay.Ngay = 10 + (pointer2 - toadoX - 5) / 3 + 1;
			}
			else if (pointer1 == toadoY + 7)
			{
				if (pointer2 == 32)
				{
					Ngay.Ngay = 30;
				}
				else
					Ngay.Ngay = 20 + (pointer2 - toadoX - 5) / 3 + 1;
			}
			else if (pointer1 == toadoY + 8)
			{
				gotoXY(toadoX + 5, pointer1 + 1);
				Ngay.Ngay = 31;
			}
			cout << Ngay.Ngay;
		}
		Sleep(100);
	}
}

void ChonPhai(int toadoX, int toadoY, bool& Phai, int& pointer2)
{
	ShowCur(0);
	int pointer1 = toadoX;

	SetColor(4);
	gotoXY(toadoX, toadoY);
	cout << "Nam";
	SetColor(7);
	gotoXY(toadoX + 15, toadoY);
	cout << "Nu";
	while (true)
	{
		if (kbhit())
		{
			char c = getch();
			if (c == -32)
			{
				c = getch();
				if (c == 75)
				{
					if (pointer1 == toadoX)
						pointer1 = toadoX + 15;
					else
						pointer1 = toadoX;

					gotoXY(toadoX, toadoY);
					cout << "Nam";
					gotoXY(toadoX + 15, toadoY);
					cout << "Nu";
				}
				else if (c == 77)
				{
					if (pointer1 == toadoX + 15)
						pointer1 = toadoX;
					else
						pointer1 = toadoX + 15;

					gotoXY(toadoX, toadoY);
					cout << "Nam";
					gotoXY(toadoX + 15, toadoY);
					cout << "Nu";
				}
				else if (c == 72)
				{
					ShowCur(1);
					pointer2 = pointer2 - 3;

					SetColor(7);
					gotoXY(toadoX, toadoY);
					cout << "Nam";
					SetColor(7);
					gotoXY(toadoX + 15, toadoY);
					cout << "Nu";
					return;
				}
				else if (c == 80)
				{
					pointer2 = pointer2 + 3;

					SetColor(7);
					gotoXY(toadoX, toadoY);
					cout << "Nam";
					SetColor(7);
					gotoXY(toadoX + 15, toadoY);
					cout << "Nu";
					return;
				}
			}
			if (c == 13)
			{
				gotoXY(135, 24);
				cout << "   ";
				gotoXY(pointer1, toadoY);
				SetColor(4);
				if (pointer1 == toadoX)
				{
					cout << "Nam";
					gotoXY(135, 24);
					cout << "Nam";
					Phai = 1;
				}
				else if (pointer1 == toadoX + 15)
				{
					cout << "Nu";
					gotoXY(135, 24);
					cout << "Nu";
					Phai = 0;
				}

				SetColor(7);
				gotoXY(toadoX, toadoY);
				cout << "Nam";
				SetColor(7);
				gotoXY(toadoX + 15, toadoY);
				cout << "Nu";

				pointer2 = pointer2 + 3;
				return;
			}

			gotoXY(pointer1, toadoY);
			SetColor(4);
			if (pointer1 == toadoX)
			{
				cout << "Nam";
			}
			else if (pointer1 == toadoX + 15)
			{
				cout << "Nu";
			}
			textcolor(7);
		}
	}
}

void XuLyNhapGio(Hour& t, int toadoX, int& toadoY)
{
	char c;

	ShowCur(0);
	SetColor(4);
	gotoXY(toadoX + 2, toadoY + 1);
	if (t.Hours < 10)
	{
		cout << "0" << t.Hours;
	}
	else
		cout << t.Hours;

	int pointer2 = toadoX + 2;
	while (true)
	{
		if (kbhit())
		{
			c = getch();
			if (c == 13)
			{
				SetColor(7);
				gotoXY(toadoX + 2, toadoY + 1);
				if (t.Hours < 10)
				{
					cout << 0 << t.Hours;
				}
				else
					cout << t.Hours;
				gotoXY(toadoX + 12, toadoY + 1);
				if (t.Minute < 10)
				{
					cout << 0 << t.Minute;
				}
				else
					cout << t.Minute;

				toadoY = toadoY + 3;
				return;
			}
			else if (c == -32)
			{
				c = getch();
				if (c == 72)
				{
					if (pointer2 == toadoX + 2)
					{
						t.Hours = t.Hours + 1;
						if (t.Hours > 23)
						{
							t.Hours = 0;
						}
					}
					else if (pointer2 == toadoX + 12)
					{
						t.Minute = t.Minute + 1;
						if (t.Minute > 60)
						{
							t.Hours = t.Hours + 1;
							t.Minute = 0;
						}
					}
				}
				else if (c == 80)
				{
					if (pointer2 == toadoX + 2)
					{
						t.Hours = t.Hours - 1;
						if (t.Hours < 0)
						{
							t.Hours = 23;
						}
					}
					else if (pointer2 == toadoX + 12)
					{
						t.Minute = t.Minute - 1;
						if (t.Minute < 0)
						{
							t.Minute = 60;
							if (t.Hours > 0)
							{
								t.Hours = t.Hours - 1;
							}
							else
								t.Hours = 23;
						}
					}
				}
				else if (c == 75)
				{
					if (pointer2 == toadoX + 2)
					{
						pointer2 = toadoX + 12;
					}
					else
					{
						pointer2 = toadoX + 2;

					}
				}
				else if (c == 77)
				{
					if (pointer2 == toadoX + 2)
					{
						pointer2 = toadoX + 12;
					}
					else
					{
						pointer2 = toadoX + 2;
					}
				}
			}
			else if (c == 27)
			{
				LayGioHienTai(t);

				SetColor(7);
				gotoXY(toadoX + 12, toadoY + 1);
				if (t.Hours < 10)
				{
					cout << 0 << t.Hours;
				}
				else
					cout << t.Hours;
				gotoXY(toadoX + 12, toadoY + 1);
				if (t.Minute < 10)
				{
					cout << 0 << t.Minute;
				}
				else
					cout << t.Minute;

				toadoY = toadoY + 3;
				return;
			}

			//to mau
			if (pointer2 == toadoX + 2)
			{
				SetColor(7);
				gotoXY(toadoX + 12, toadoY + 1);
				if (t.Minute < 10)
				{
					cout << 0 << t.Minute;
				}
				else
					cout << t.Minute;
				SetColor(4);
				gotoXY(toadoX + 2, toadoY + 1);
				if (t.Hours < 10)
				{
					cout << 0 << t.Hours;
				}
				else
					cout << t.Hours;
			}
			else
			{
				SetColor(7);
				gotoXY(toadoX + 2, toadoY + 1);
				if (t.Hours < 10)
				{
					cout << 0 << t.Hours;
				}
				else
					cout << t.Hours;
				SetColor(4);
				gotoXY(toadoX + 12, toadoY + 1);
				if (t.Minute < 10)
				{
					cout << 0 << t.Minute;
				}
				else
					cout << t.Minute;
			}
		}
	}
}

