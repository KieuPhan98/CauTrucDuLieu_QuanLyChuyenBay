#pragma once
#include "CTDL.h"
#include "HamXuLyChuyenBay.h"

bool KTTonTaiHangKhach(TREE t, string CMND, HanhKhach& HK)
{
	if (t == NULL)
	{
		return false;
	}
	else if (t->data.CMND == CMND)
	{
		HK = t->data;
		return true;
	}
	else if (t->data.CMND > CMND)
	{
		return KTTonTaiHangKhach(t->pLeft, CMND, HK);
	}
	else
	{
		return KTTonTaiHangKhach(t->pRight, CMND, HK);
	}
}

bool KT_CMND_Tren1CB(ChuyenBay& CB, string CMND) {
	for (int i = 0; i < CB.TongSoVe; i++) {
		if (CB.DSVe[i].TrangThai == 1 && CB.DSVe[i].CMND == CMND) {
			return true;
		}
	}
	return false;
}

bool KiemTraHanhKhachCungThoiDiem(List l, string CMND, ChuyenBay CB) {
	for (NodeList *p = l.pHead; p != NULL; p = p->pNext) {
		if (KT_CMND_Tren1CB(p->data, CMND)) {
			if (p->data.TrangThai != 0 || p->data.TrangThai == 3) {
				return false; // khong cung thoi diem 
			}
			else {
				int t1 = SoGioCachNhau(CB.NgayKhoiHanh, CB.GioKhoiHanh);
				int t2 = SoGioCachNhau(p->data.NgayKhoiHanh, p->data.GioKhoiHanh);
				int t3 = t1 - t2;

				if (t3 > -MAX_TIME && t3 < MAX_TIME) {
					return true;// cung thoi diem
				}
			}
		}
	}
}

void ThemKhachVAoCay(TREE& t, HanhKhach x)
{
	if (t == NULL)
	{
		SoLgKH++;
		NODE_TREE* p = new NODE_TREE;
		p->data = x;
		p->pLeft = p->pRight = NULL;
		t = p;
	}
	else
	{
		if (x.CMND < t->data.CMND)
			ThemKhachVAoCay(t->pLeft, x);
		else if (x.CMND > t->data.CMND)
			ThemKhachVAoCay(t->pRight, x);
	}
}
