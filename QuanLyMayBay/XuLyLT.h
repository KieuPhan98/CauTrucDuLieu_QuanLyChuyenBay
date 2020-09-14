#pragma once 
#define MAX_TIME 240
//Chuoi
int DemChuSo(int n)
{
	int dem = 0;
	while (n > 0)
	{
		n = n / 10;
		dem++;
	}
	return dem;
}
char Chuyen1SoSangKiTu(int n)
{
	switch (n)
	{
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 0:
		return '0';
	}
}

//De Nhap
string ChuyenSoSangString1(int n)
{
	string str;
	int a;
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));
		n = n / 10;
	}
	return str;
}
//De Xuat
string ChuyenSoSangString(int n)
{
	string str;
	int a;
	if (n == 0)
	{
		str = "0";
	}
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));
		n = n / 10;
	}
	return str;
}
void DinhDangChuoi(string& str)
{
	//Xoa khoang trong
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + (str.length() - 1));
	}

	for (int i = 1; i < str.length() - 1; i++)
	{
		if (str[i + 1] == ' ' && str[i] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	//Viet thuong all lai
	for (int i = 0; i < str.length(); i++)
	{
		if ((65 <= str[i] && str[i] <= 90) && str[i] != ' ')
		{
			str[i] = str[i] + 32;
		}
	}
	//Viet hoa
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && (97 <= str[i] && str[i] <= 122))
		{
			str[0] = str[0] - 32;
		}
		if (str[i] == ' ' && (97 <= str[i + 1] && str[i + 1] <= 122))
		{
			str[i + 1] = str[i + 1] - 32;
		}
	}

}
string CanDeuChuoi(string str, int ChieuRong)
{
	if (str.empty())
	{
		return str;
	}
	else if (str.length() > ChieuRong)
	{
		return str;
	}
	return string((ChieuRong - str.length()) / 2, ' ') + str;
}

//Lay Gio Hien Tai
//void LayGioHienTai(Hour &t) //BO
//{
//	// tra ve date/time hien tai dua tren system hien tai
//	time_t hientai = time(0);
//	// chuyen doi hientai thanh dang chuoi
//	char* dt = ctime(&hientai);
//	string str1, str2, str3, str4, str5;
//	//Gio
//	for (int i = 11; i < 13; i++)
//	{
//		str4.push_back(dt[i]);
//	}
//	t.Hours = atoi(str4.c_str());
//	//Phut
//	for (int i = 14; i < 16; i++)
//	{
//		str5.push_back(dt[i]);
//	}
//	t.Minute = atoi(str5.c_str());
//}
// Lay Ngay Hien Tai
// Xu Ly Ngay

int ChuyenThang(string str)
{
	if (str == "Jan")
	{
		return 1;
	}
	else if (str == "Feb")
	{
		return 2;
	}
	else if (str == "Mar")
	{
		return 3;
	}
	else if (str == "Apr")
	{
		return 4;
	}
	else if (str == "May")
	{
		return 5;
	}
	else if (str == "Jun")
	{
		return 6;
	}
	else if (str == "Jul")
	{
		return 7;
	}
	else if (str == "Aug")
	{
		return 8;
	}
	else if (str == "Sep")
	{
		return 9;
	}
	else if (str == "Oct")
	{
		return 10;
	}
	else if (str == "Nov")
	{
		return 11;
	}
	else if (str == "Dec")
	{
		return 12;
	}
}

void LayNgayHienTai(Date& d)
{
	// tra ve date/time hien tai dua tren system hien tai
	time_t hientai = time(0);
	// chuyen doi hientai thanh dang chuoi
	char* dt = ctime(&hientai);   // dt= Sat Sep 5 13:19:41 2020 
	string str1, str2, str3;
	//ngay
	for (int i = 8; i < 10; i++)
	{
		str1.push_back(dt[i]);
	}
	d.Ngay = atoi(str1.c_str());
	// thang
	for (int i = 4; i < 7; i++)
	{
		str2.push_back(dt[i]);
	}
	d.Thang = ChuyenThang(str2);
	//nam
	for (int i = 20; i < 24; i++)
	{
		str3.push_back(dt[i]);
	}
	d.Nam = atoi(str3.c_str());
}
void LayGioHienTai(Hour &t)
{
	// tra ve date/time hien tai dua tren system hien tai
	time_t hientai = time(0);

	// chuyen doi hientai thanh dang chuoi
	char *dt = ctime(&hientai);

	string str1, str2;
	//Gio
	for (int i = 11; i < 13; i++)
	{
		str1.push_back(dt[i]);
	}
	t.Hours = atoi(str1.c_str());
	//Phut
	for (int i = 14; i < 16; i++)
	{
		str2.push_back(dt[i]);
	}
	t.Minute = atoi(str2.c_str());
}


bool KTNamNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		return true;
	}
	else
		return false;
}

// 1:Hour > Hour1; 2:Hour <Hour1; 3:Hour=Hour1
bool SoSanhHour(Hour t, Hour t1)
{
	int t0 = t.Hours * 60 + t.Minute;
	int t2 = t1.Hours * 60 + t1.Minute;

	if (t0 - t2 < MAX_TIME || t2 -t0 < MAX_TIME) {  // cach gio hien tai nho hon 4h
		return false;
	}
	else
	{
		return true; // lon hon gio hien tai it nhat 4h 
	}

	
}
int SoNgayCuaThang(int thang)
{
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
	{
		return 31;
	}
	else if (thang == 2)
	{
		if (KTNamNhuan)
		{
			return 29;
		}
		else
			return 28;
	}
	else
		return 30;
}
/*int SoNgayQuaHan(Date d)
{
	Date d1;
	LayNgayHienTai(d1);
	if (SoSanhNgay(d1, d) == 1)
	{
		if (d.Nam == d1.Nam)
		{
			if (d.Thang == d1.Thang)
			{
				return d1.Ngay - d.Ngay;
			}
			else
			{
				return SoNgayCuaThang(d.Thang) - d.Ngay + d1.Ngay;
			}
		}
		else
		{
			int SoNgayConLaiCuaNam = 0;
			for (int i = 1; i < d.Thang; i++)
			{
				SoNgayConLaiCuaNam = SoNgayConLaiCuaNam + i * SoNgayCuaThang(i);
			}
			if (KTNamNhuan(d.Nam))
			{
				return 366 - SoNgayConLaiCuaNam - d.Ngay + d1.Ngay;
			}
			else
			{
				return 365 - SoNgayConLaiCuaNam - d.Ngay + d1.Ngay;
			}
		}
	}
	else
		return 0;
}*/
Date CongNgay(Date t, int SoNgay)
{
	Date d = t;
	d.Ngay = d.Ngay + SoNgay;
	if (d.Ngay > SoNgayCuaThang(d.Thang))
	{
		if (d.Thang == 12)
		{
			d.Thang = 1;
			d.Nam = d.Nam + 1;
		}
		else
		{
			d.Thang = d.Thang + 1;
		}
		d.Ngay = d.Ngay - SoNgayCuaThang(t.Thang);
	}
	return d;
}


