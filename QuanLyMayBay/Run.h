#include"CTDL.h"
#include"XuLyLT.h"
#include"DoHoa.h"
#include"XuLyNhap.h"
#include"ThongKe.h"
#include"LoadFile.h"

#include "MayBay.h"
#include "ChuyenBay.h"
#include "DatVe.h"
//#include "ChuyenBay.h"
int todoXMN = 6;
int todoYMN = 7;
int pointer = todoYMN;
string strMNMain[] = {
	"     Them May Bay                    ", //1
	"     Xoa May Bay                     ", //2
	"     Sua May Bay                     ", //3
	"     Them Chuyen Bay                 ", //4
	"     Xoa Chuyen Bay                  ", //5
	"     Sua Chuyen Bay                  ", //6
	"     Huy Chuyen Bay                  ", //7
	"     Dat Ve                          ", //8
	"     Huy Ve                          ", //9
	"     DS Khach Hang Thuoc 1 CB        ", //10
	"     DS CB Khoi Hanh                 ", //11
	"     DS Cac Ve Con Trong Cua 1 CB    ", //12
	"     Thong Ke So Luot Thuc Hien CB   ", //13
	"     Thoat                           ",  //0
	
};
void Menu()
{
	//textcolor(240);
	int j = todoYMN;
	for (int i = 0; i < sizeof(strMNMain) / sizeof(*strMNMain); i++)
	{
		gotoXY(todoXMN, j++);
		cout << strMNMain[i];
	}
}
void RunMenu(MCONTROMB &MB, List& l, TREE &t)
{
	if (kbhit()) // la ham kiem tra nguoi dung cos nhan phim nao khi chay chuong trinh khong
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72) // mui ten len
			{
				if (pointer == todoYMN)
				{
					Menu();
					pointer = todoYMN - 1 + sizeof(strMNMain) / sizeof(*strMNMain);
				}
				else
				{
					Menu();
					pointer--;
				}
			}
			else if (c == 80) // mui ten xuong
			{
				if (pointer == todoYMN - 1 + sizeof(strMNMain) / sizeof(*strMNMain))
				{
					Menu();
					pointer = todoYMN;
				}
				else
				{
					Menu();
					pointer++;
				}
			}
		}
		else if (c == 13)
		{
			switch (pointer)
			{
			case 7: //1 them may bay
				ThemMB(MB, 95, 17);
				break;
			case 8://2 xoa may bay
				XoaMB(MB);
				break;
			case 9://3 sua may bay
				SuaMB(MB, 95, 17);
				break;
			case 10://4 Them chuyen bay
				ThemCB(MB, l, 95, 17);
				break;
			case 11://5//Xoa chuyen bay
				XoaCB(l);
				break;
			case 12://6//Sua chuyen bay
				SuaCB(l, MB, 95, 17);
				break;
			case 13: //7 huy chuyen bay
				HuyChuyenBay(l, 95, 17);
				break;
			case 14://8 dat ve
				DangKiVe(MB, t, l, 95, 17);
				break;
			case 15://9 huy ve
				HuyVe(l, t, 95, 17);
				break;
			case 16://10 danh sach khach hang thuoc mot chuyen bay
				XuatDSHKTheoPage(l, t, toadoXBox, toadoYBox);
				break;
			case 17://11 danh sach chuyen bay khoi hanh
				TimKiemCB(l, 95, 17);
				break;
			case 18: //12 danh sach cac ve con trong cua mot chuyen bay
				DSCacVeConTrong(MB, l, 95, 14);
				break;
			case 19: //13 thong ke so luot thuc hien chuyen bay
				ThongKeSoLuotThucHienCB(MB, toadoXBox, toadoYBox);
				break;
			case 20://0thoat
				GhiFileMayBay(MB);
				GhiFileKH(t);
				GhiFileDanhSachChuyenBay(l);

				exit(0);
			
			}

			system("cls");
			GiaoDienMain();
			Menu();
		}
	}
	// to mau 
	textcolor(180);
	gotoXY(todoXMN, pointer);
	cout << strMNMain[pointer - todoYMN];
	textcolor(7);
}

void Khoitao(MCONTROMB &MB, List &l, TREE &t)
{
	MB.SoLgMB = 0;
	l.pHead = l.pTail = NULL;
	t = NULL;
	LoadFile(MB, t, l);
	CapNhatCB(l, MB);
	resizeConsole(1375, 650);
	HCNTextDong(4, 4, 42, 22);
	GiaoDienMain();
	Menu();
}
