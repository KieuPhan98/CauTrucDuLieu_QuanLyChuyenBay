
//Ham Do Hoa 
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void SetColor(WORD color)
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
//ham to mau
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
//an con tro nhay
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//thya doi kich co cua khung cmd
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
//lay toa do x cua con tro hien tai
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//Ve HCN
void HCNTextDong(int toadoX, int toadoY, int chieudai, int chieucao)
{
	for (int i = toadoX; i < toadoX + chieudai; i++)
	{
		gotoXY(i, toadoY);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoY; i < toadoY + chieucao; i++)
	{
		gotoXY(toadoX + chieudai - 1, i);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoX + chieudai - 1; i >= toadoX; i--)
	{
		gotoXY(i, toadoY + chieucao - 1);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoY + chieucao - 1; i >= toadoY; i--)
	{
		gotoXY(toadoX, i);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
}
//ve HCM bang khoang trang
void HCNText(int toadoX, int toadoY, int chieudai, int chieucao)
{
	for (int i = toadoX; i < toadoX + chieudai; i++)
	{
		gotoXY(i, toadoY);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
	for (int i = toadoY; i < toadoY + chieucao; i++)
	{
		gotoXY(toadoX + chieudai - 1, i);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
	for (int i = toadoX + chieudai - 1; i >= toadoX; i--)
	{
		gotoXY(i, toadoY + chieucao - 1);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
	for (int i = toadoY + chieucao - 1; i >= toadoY; i--)
	{
		gotoXY(toadoX, i);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
}
//hinh chu nhat co mau
void VeHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauSet)
{
	SetColor(mauSet);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}
	SetColor(7);
}

void ToMauHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauText)
{
	textcolor(mauText);
	for (int i = toadoY + 1; i < toadoY + chieucao; i++)
	{
		for (int j = toadoX + 1; j < chieudai + toadoX; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
	textcolor(7);
}
void XoaHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mau)
{
	textcolor(mau);
	for (int j = toadoY + 1; j < toadoY + chieucao; j++)
	{
		for (int i = toadoX + 1; i < toadoX + chieudai; i++)
		{
			gotoXY(i, j);
			cout << " ";
		}
	}
}
//Logo
void Logo1(int toadoX, int toadoY)
{
	string str;
	ifstream FileIn;
	FileIn.open("input1.txt", ios::in);
	int h = toadoY;
	int mamau;
	while (true)
	{
		getline(FileIn, str);
		mamau = 10 + rand() % 6;
		SetColor(mamau);
		gotoXY(toadoX, h++);
		cout << str << endl;
		if (FileIn.eof())
		{
			break;
		}
	}
	textcolor(7);
	FileIn.close();
}
void Logo2(int toadoX, int toadoY)
{
	string str;
	ifstream FileIn;
	FileIn.open("input2.txt", ios::in);
	int h = toadoY;
	int mamau;
	while (true)
	{
		getline(FileIn, str);
		mamau = 10 + rand() % 6;
		SetColor(mamau);
		gotoXY(toadoX, h++);
		cout << str << endl;
		if (FileIn.eof())
		{
			break;
		}
	}
	textcolor(7);
	FileIn.close();
}
//Xoa Man Hinh
void XoaManHinhChinh()
{
	textcolor(7);
	for (int i = 6; i < 36; i++)
	{
		for (int j = 51; j < 176; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
}
void XoaManHinhTuyChon(int toadoX, int toadoY, int chieudai, int chieucao)
{
	textcolor(7);
	for (int i = toadoY; i < chieucao + toadoY; i++)
	{
		for (int j = toadoX; j < toadoX + chieudai; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
}
//
void DeMuc(string x)
{
	SetColor(14);
	gotoXY(51, 7);
	cout << CanDeuChuoi(x, 126);
	textcolor(7);
}
void XuatPage(int page)
{
	gotoXY(111, 34);
	cout << char(174); // dau <<
	gotoXY(115, 34);
	cout << char(175);// dau >>
	gotoXY(113, 34);
	cout << page;
}
//GiaoDien
void GiaoDienMain()
{
	ShowCur(0);
	HCNText(4, 4, 42, 22);

	textcolor(112);
	// duong to mau gach xuong
	for (int i = 0; i < 36; i++)
	{
		gotoXY(50, i);
		cout << " ";
	}

	// duong to mau duoi cuoi
	for (int i = 0; i < 176; i++)
	{
		gotoXY(i, 36);
		cout << " ";
	}
	textcolor(7);
	// duong gach ngang duoi welcome
	for (int i = 51; i < 176; i++)
	{
		gotoXY(i, 5);
		cout << (char)205;
	}

	textcolor(7);
	//ToMauHCN(-1,2 , 51, 9, 240);

	gotoXY(105, 2);
	cout << "WELCOME TO N22-KNK-C27/8";
	gotoXY(23, 15);
	SetColor(9);
	cout << "MENU";
	textcolor(7);
}
void GiaoDienNhapMayBay(int toadoX, int toadoY)
{
	DeMuc("Dang Ki May Bay");
	gotoXY(75, 12);
	cout << "Nhap So Hieu MB:";
	VeHCN(toadoX, toadoY - 6, 50, 2, 7);
	gotoXY(75, 15);
	cout << "Nhap Loai MB:";
	VeHCN(toadoX, toadoY - 3, 50, 2, 7);

	gotoXY(75, 18);
	cout << "Nhap So Day:";
	VeHCN(toadoX, toadoY, 50, 2, 7);
	gotoXY(75, 21);
	cout << "Nhap So Dong:";
	VeHCN(toadoX, toadoY + 3, 50, 2, 7);

	gotoXY(toadoX + 15, toadoY + 10);
	cout << "Dang Ki";
	gotoXY(toadoX + 30, toadoY + 10);
	cout << "Cancel";
}
void GiaoDienThongBao(string str)
{
	ToMauHCN(toadoXBox + 46 - 15, toadoYBox + 5, 40, 10, 240);
	textcolor(240);
	gotoXY(toadoXBox + 46 - 15 + 1, toadoYBox + 8);
	cout << CanDeuChuoi(str, 38);
	getch();
	textcolor(7);
}
void GiaoDienNhapChuyenBay(int toadoX, int toadoY)
{
	DeMuc("Nhap chuyen bay");
	gotoXY(75, 12);
	cout << "Nhap Ma CB:";
	VeHCN(toadoX, toadoY - 6, 50, 2, 7);

	gotoXY(75, 15);
	cout << "Nhap Gio:";
	gotoXY(toadoX + 7, 15);
	cout << "H";
	gotoXY(toadoX + 17, 15);
	cout << "M";
	VeHCN(toadoX, toadoY - 3, 5, 2, 7);
	VeHCN(toadoX + 10, toadoY - 3, 5, 2, 7);

	gotoXY(75, 18);
	cout << "Nhap Ngay Di:";
	gotoXY(toadoX + 7, toadoY + 1);
	cout << "/";
	gotoXY(toadoX + 17, toadoY + 1);
	cout << "/";

	VeHCN(toadoX, toadoY, 5, 2, 7);
	VeHCN(toadoX + 10, toadoY, 5, 2, 7);
	VeHCN(toadoX + 20, toadoY, 10, 2, 7);

	gotoXY(75, 21);
	cout << "Nhap San Bay Den:";
	VeHCN(toadoX, toadoY + 3, 50, 2, 7);

	gotoXY(75, 24);
	cout << "Nhap So Hieu MB:";
	VeHCN(toadoX, toadoY + 6, 50, 2, 7);

	gotoXY(75, 27);
	cout << "Nhap Trang Thai :";
	VeHCN(toadoX, toadoY + 9, 50, 2, 7);

	gotoXY(toadoX + 15, toadoY + 15);
	cout << "Dang Ki";
	gotoXY(toadoX + 30, toadoY + 15);
	cout << "Cancel";
}
void GiaoDienSuaChuyenBay(int toadoX, int toadoY)
{
	DeMuc("Nhap chuyen bay");
	gotoXY(75, 12);
	cout << "Nhap Ma CB:";
	VeHCN(toadoX, toadoY - 6, 50, 2, 7);

	gotoXY(75, 15);
	cout << "Nhap Gio:";
	gotoXY(toadoX + 7, 15);
	cout << "H";
	gotoXY(toadoX + 17, 15);
	cout << "M";
	VeHCN(toadoX, toadoY - 3, 5, 2, 7);
	VeHCN(toadoX + 10, toadoY - 3, 5, 2, 7);

	gotoXY(75, 18);
	cout << "Nhap Ngay Di:";
	gotoXY(toadoX + 7, toadoY + 1);
	cout << "/";
	gotoXY(toadoX + 17, toadoY + 1);
	cout << "/";

	VeHCN(toadoX, toadoY, 5, 2, 7);
	VeHCN(toadoX + 10, toadoY, 5, 2, 7);
	VeHCN(toadoX + 20, toadoY, 10, 2, 7);

	gotoXY(75, 21);
	cout << "Nhap San Bay Den:";
	VeHCN(toadoX, toadoY + 3, 50, 2, 7);

	gotoXY(75, 24);
	cout << "Nhap So Hieu MB:";
	VeHCN(toadoX, toadoY + 6, 50, 2, 7);

	gotoXY(75, 27);
	cout << "Nhap Trang Thai :";
	VeHCN(toadoX, toadoY + 9, 50, 2, 7);

	gotoXY(toadoX + 15, toadoY + 15);
	cout << "Dang Ki";
	gotoXY(toadoX + 30, toadoY + 15);
	cout << "Cancel";
}
void GiaoDienDatVe(int toadoX, int toadoY)
{
	DeMuc("Dat Ve");
	gotoXY(75, 12);
	cout << "Nhap Ma CB:";
	VeHCN(toadoX, toadoY - 6, 50, 2, 7);
	gotoXY(75, 15);
	cout << "Nhap So CMND:";
	VeHCN(toadoX, toadoY - 3, 50, 2, 7);

	gotoXY(75, 18);
	cout << "Nhap Ho:";
	VeHCN(toadoX, toadoY, 50, 2, 7);

	gotoXY(75, 21);
	cout << "Nhap Ten:";
	VeHCN(toadoX, toadoY + 3, 50, 2, 7);

	gotoXY(75, 24);
	cout << "Chon Phai:";
	VeHCN(130, 23, 15, 2, 4);
	gotoXY(toadoX + 5, toadoY + 7);
	cout << "Nam";
	gotoXY(toadoX + 20, toadoY + 7);
	cout << "Nu";

	gotoXY(75, 27);
	cout << "Chon Ve:";
	VeHCN(130, 26, 15, 2, 4);
	gotoXY(toadoX + 2, toadoY + 10);
	cout << "Enter De Chon Lai";

	gotoXY(toadoX + 15, toadoY + 15);
	cout << "Dang Ki";
	gotoXY(toadoX + 30, toadoY + 15);
	cout << "Cancel";
}
void GiaoDienChonVe(int toadoX, int toadoY, int SoDay, int SoDong)
{
	DeMuc("DANH SACH VE");
	int TenDay = 65;
	int TenDong = 1;
	int toadoXtam = toadoX;

	for (int i = 0; i < SoDong; i++)
	{
		toadoX = toadoXtam;
		for (int j = 0; j < SoDay; j++)
		{
			gotoXY(toadoX, toadoY);
			if (TenDong < 10)
			{
				cout << char(TenDay) << 0 << TenDong;
			}
			else
				cout << char(TenDay) << TenDong;
			toadoX = toadoX + 10;
			TenDay++;
		}
		TenDay = 65;
		TenDong++;
		toadoY = toadoY + 1;
	}

	gotoXY(toadoXtam + 47, 32);
	SetColor(2);
	cout << "A01 :";
	gotoXY(toadoXtam + 52, 32);
	SetColor(7);
	cout << "\t Da Dat";
	gotoXY(toadoXtam + 47, 33);
	textcolor(7);
	cout << "A01 :\t Con Trong";
}

void GiaoDienHuyVe(int toadoX, int toadoY)
{
	DeMuc("Huy Ve");
	gotoXY(75, 12);
	cout << "Nhap Ma CB:";
	VeHCN(toadoX, toadoY - 6, 50, 2, 7);
	gotoXY(75, 15);
	cout << "Nhap CMND:";
	VeHCN(toadoX, toadoY - 3, 50, 2, 7);

	gotoXY(toadoX + 15, toadoY + 10);
	cout << "Xac Nhan";
	gotoXY(toadoX + 30, toadoY + 10);
	cout << "Cancel";
}

void GiaoDienHuyCB(int toadoX, int toadoY) {
	DeMuc("Huy Chuyen Bay");
	gotoXY(75, 12);
	cout << "Nhap Ma CB:";
	VeHCN(toadoX, toadoY - 3, 50, 2, 7);

	gotoXY(toadoX + 15, toadoY + 10);
	cout << "Xac Nhan";
	gotoXY(toadoX + 30, toadoY + 10);
	cout << "Cancel";
}

void GiaoDienXuat(int toadoX, int toadoY, int chieudai, int SoLgDong, string TenMoiCot[], int DoRongMoiCot[], int n)
{
	int chieucao = 3 + 2 * SoLgDong;

	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;//goc tren ben trai
		else if (i == chieudai + toadoX)
			cout << (char)191;//goc tren phai
		else
			cout << (char)196;//gach ngang
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;//goc duoi ben trai
		else if (i == chieudai + toadoX)
			cout << (char)217;//goc duoi ben phai
		else
			cout << char(196);//gach ngang
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}

	int h = 0;
	int s = 0;
	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + s + DoRongMoiCot[h])
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
			s = s + DoRongMoiCot[h];
			h++;
		}
	}

	//gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		h = 0;
		s = 0;
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i == toadoX + DoRongMoiCot[h] + s)
			{
				cout << (char)197;
				s = s + DoRongMoiCot[h++];
			}
			else
				cout << (char)196;
		}
	}

	s = 0;
	for (int i = 0; i < n; i++)
	{
		gotoXY(toadoX + 1 + s, toadoY + 1);
		cout << CanDeuChuoi(TenMoiCot[i], DoRongMoiCot[i] - 1);
		s = s + DoRongMoiCot[i];
	}
}

void GiaoDienTimKiemCB(int toadoX, int toadoY)
{
	DeMuc("TIM KIEM CHUYEN BAY");
	gotoXY(75, 12);
	cout << "Nhap Noi Den:";
	VeHCN(toadoX, toadoY - 6, 50, 2, 7);

	gotoXY(75, 15);
	cout << "Nhap Ngay Di:";
	gotoXY(toadoX + 7, toadoY - 2);
	cout << "/";
	gotoXY(toadoX + 17, toadoY - 2);
	cout << "/";

	VeHCN(toadoX, toadoY - 3, 5, 2, 7);
	VeHCN(toadoX + 10, toadoY - 3, 5, 2, 7);
	VeHCN(toadoX + 20, toadoY - 3, 10, 2, 7);

	gotoXY(toadoX + 15, toadoY + 10);
	cout << "Xac Nhan";
	gotoXY(toadoX + 30, toadoY + 10);
	cout << "Cancel";
}
