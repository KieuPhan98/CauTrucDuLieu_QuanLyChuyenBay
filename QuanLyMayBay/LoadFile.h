#pragma once
#include "HamXuLyMayBay.h"
#include "ChuyenBay.h"
#include "HanhKhach.h"

void LoadFileMB(MCONTROMB& MB)
{
	ifstream FileIn("MAYBAY.txt", ios::in);
	FileIn >> MB.SoLgMB;
	FileIn.ignore();
	for (int i = 0; i < MB.SoLgMB; i++)
	{
		MB.data[i] = new MayBay;
		getline(FileIn, MB.data[i]->SoHieuMB, ',');
		getline(FileIn, MB.data[i]->LoaiMayBay, ',');
		FileIn >> MB.data[i]->SoLuotCB;
		FileIn.ignore();
		FileIn >> MB.data[i]->SoDay;
		FileIn.ignore();
		FileIn >> MB.data[i]->SoDong;
		FileIn.ignore();
	}
	FileIn.close();
}

void GhiFileMayBay(MCONTROMB MB) {
	ofstream fileout;
	fileout.open("MAYBAY.txt", ios::out);
	fileout << MB.SoLgMB << endl;
	for (int i = 0; i<MB.SoLgMB; i++) {
		fileout << MB.data[i]->SoHieuMB << "," << MB.data[i]->LoaiMayBay << "," << MB.data[i]->SoLuotCB << ","
			<< MB.data[i]->SoDay << "," << MB.data[i]->SoDong << endl;
	}
	fileout.close();
}
//void LoadFileKH(TREE& t)
//{
//	int n = 0;
//	ifstream FileIn("HANHKHACH.txt", ios::in);
//	FileIn >> n;
//	FileIn.ignore();
//	string tam;
//	HanhKhach KH;
//	for (int i = 0; i < n; i++)
//	{
//		getline(FileIn, KH.CMND, ',');
//		getline(FileIn, KH.Ho, ' ');
//		getline(FileIn, tam, ' ');
//		KH.Ho = KH.Ho + " " + tam;
//		getline(FileIn, KH.Ten, ',');
//		FileIn >> KH.Phai;
//		FileIn.ignore();
//		ThemKhachVAoCay(t, KH);
//	}
//	FileIn.close();
//}

void tachLayTenVaHo(string str, string& ten, string& ho)
{
	int k = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			k = i;
			break;
		}
	}

	for (int i = 0; i < k; i++)
	{
		ho += str[i];
	}

	for (int i = k + 1; i < str.length(); i++)
	{
		ten += str[i];
	}
}

void LoadFileKH(TREE& t)
{
	int n = 0;
	ifstream FileIn("HANHKHACH.txt", ios::in);
	FileIn >> n;
	FileIn.ignore();
	string str;
	HanhKhach KH;
	for (int i = 0; i < n; i++)
	{
		getline(FileIn, KH.CMND, ',');
		getline(FileIn, str, ',');
		tachLayTenVaHo(str, KH.Ten, KH.Ho);
		FileIn >> KH.Phai;
		FileIn.ignore();
		ThemKhachVAoCay(t, KH);

		KH.Ho = KH.Ten = "";
	}
	FileIn.close();
}

void Duyet_HanhKhach(TREE &t, ofstream &fileout) {
	if (t == NULL) {
		return;
	}
	Duyet_HanhKhach(t->pLeft, fileout);
	fileout << t->data.CMND << "," << t->data.Ho << " " << t->data.Ten << "," << t->data.Phai << endl;
	Duyet_HanhKhach(t->pRight, fileout);

}

void GhiFileKH(TREE &t) {
	ofstream fileout;
	fileout.open("HANHKHACH.txt");
	fileout << SoLgKH << endl;
	Duyet_HanhKhach(t, fileout);
	fileout.close();
}

void LoadFileCB(List& l, MCONTROMB MB)
{
	int n;
	ifstream FileIn("CHUYENBAY.txt", ios::in);
	ChuyenBay CB;
	FileIn >> n;
	FileIn.ignore();
	for (int k = 0; k < n; k++)
	{
		getline(FileIn, CB.MaCB, ',');
		//cout << CB.MaCB << ",";
		FileIn >> CB.GioKhoiHanh.Hours;
		//cout << CB.GioKhoiHanh.Hour<<",";
		FileIn.ignore();
		FileIn >> CB.GioKhoiHanh.Minute;
		//cout << CB.GioKhoiHanh.Minute<< ",";
		FileIn.ignore();
		FileIn >> CB.NgayKhoiHanh.Ngay;
		//cout << CB.NgayKhoiHanh.Ngay<< ",";
		FileIn.ignore();
		FileIn >> CB.NgayKhoiHanh.Thang;
		//cout << CB.NgayKhoiHanh.Thang<< ",";
		FileIn.ignore();
		FileIn >> CB.NgayKhoiHanh.Nam;
		//cout << CB.NgayKhoiHanh.Nam << ",";
		FileIn.ignore();
		getline(FileIn, CB.SanBayDen, ',');
		getline(FileIn, CB.SoHieuMB, ',');
		FileIn >> CB.TrangThai;
		FileIn.ignore();
		FileIn >> CB.TongSoVe;
		FileIn.ignore();
		FileIn >> CB.SoVeDaDat;
		//cout << CB.SoVeDaDat<<endl;
		FileIn.ignore();

		CB.DSVe = new DanhSachVe[CB.TongSoVe];

		MayBay* tamMB = LayThongTinMB(MB, CB.SoHieuMB);
		//Dat ten cho ve 
		int h = 0;
		int TenDay = 65;
		int TenDong = 1;
		for (int i = 0; i < tamMB->SoDong; i++)
		{
			TenDay = 65;
			for (int j = 0; j < tamMB->SoDay; j++)
			{
				if (TenDong < 10)
				{
					CB.DSVe[h].MaVe.push_back((char)TenDay);
					CB.DSVe[h].MaVe.push_back((char)48);
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
		/*
		for (int j = 0; j < CB.TongSoVe; j++)
		{
		cout << CB.DSVe[j].MaVe << endl;
		}*/

		string MaVe;
		string CMND;
		for (int i = 0; i < CB.SoVeDaDat; i++)
		{
			getline(FileIn, CMND, ',');
			/*cout << CMND << endl;
			system("pause");*/
			getline(FileIn, MaVe);
			for (int j = 0; j < CB.TongSoVe; j++)
			{
				if (CB.DSVe[j].MaVe == MaVe)
				{
					CB.DSVe[j].TrangThai = true;
					CB.DSVe[j].CMND = CMND;
					break;
				}
			}
			//FileIn.ignore();
		}

		dscb_themcuoi(l, CB);
	}
	FileIn.close();
}

void GhiFileDanhSachChuyenBay(List l) {
	ofstream fileout;
	fileout.open("CHUYENBAY.txt", ios::out);
	fileout << l.n << endl;
	for (NodeList *k = l.pHead; k != NULL; k = k->pNext)
	{
		fileout << k->data.MaCB << "," << k->data.GioKhoiHanh.Hours << ":" << k->data.GioKhoiHanh.Minute << ","
			<< k->data.NgayKhoiHanh.Ngay << "/" << k->data.NgayKhoiHanh.Thang << "/" << k->data.NgayKhoiHanh.Nam << ","
			<< k->data.SanBayDen << "," << k->data.SoHieuMB << "," << k->data.TrangThai << "," << k->data.TongSoVe << "," << k->data.SoVeDaDat << endl;
		if (k->data.SoVeDaDat>0)
		{
			for (int i = 0; i<k->data.TongSoVe; i++)
			{
				if (k->data.DSVe[i].TrangThai == true)
				{
					fileout << k->data.DSVe[i].CMND << "," << k->data.DSVe[i].MaVe << endl;
				}
			}
		}
	}
	fileout.close();
}

void LoadFile(MCONTROMB& MB, TREE& t, List& l)
{
	LoadFileMB(MB);
	LoadFileKH(t);
	LoadFileCB(l, MB);
}