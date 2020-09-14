#pragma once
#include "CTDL.h"
#include "HamXuLyMayBay.h"

int SoSanhGio(Hour thoiGian) { // so sanh gio so voi gio hien tai 
	Hour thoiGianHienTai;
	LayGioHienTai(thoiGianHienTai);

	int t1 = thoiGian.Hours * 60 + thoiGian.Minute;
	int t2 = thoiGianHienTai.Hours * 60 + thoiGianHienTai.Minute;

	//if (t1 - t2 < MAX_TIME) {  // cach gio hien tai nho hon 4h
	//	return false;
	//}
	//else
	//{
	//	return true; // lon hon gio hien tai it nhat 4h 
	//}

	return t1 - t2;
}

int SoSanhNgay(Date d) // 1: lon hon ngay htai, 2: nho hon ngay hien tai, 3: = ngay htai
{
	Date ngayHienTai;
	LayNgayHienTai(ngayHienTai);

	if (d.Nam == ngayHienTai.Nam)
	{
		if (d.Thang == ngayHienTai.Thang)
		{
			if (d.Ngay > ngayHienTai.Ngay)
			{
				return 1;
			}
			else if (d.Ngay < ngayHienTai.Ngay)
			{
				return 2;
			}
			else
				return 3;
		}
		else if (d.Thang > ngayHienTai.Thang)
		{
			return 1;
		}
		else
			return 2;
	}
	else if (d.Nam > ngayHienTai.Nam)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

int KhoangCachNgayThangNam(Date date) { //
	Date ngayHienTai;
	LayNgayHienTai(ngayHienTai);

	int t = 0;
	while (ngayHienTai.Nam >= date.Nam) {
		if (ngayHienTai.Nam == date.Nam && ngayHienTai.Thang == date.Thang) {
			t += ngayHienTai.Ngay - date.Ngay;
			break;
		}
		else {
			// cac thang 4,6,9,11 co 30 ngay
			if (date.Thang == 4 || date.Thang == 6 || date.Thang == 9 || date.Thang == 11) {
				t += 30 - date.Ngay;
			}
			// cac thang 1,3,5,7,8,10,12 co 31 ngay
			if (date.Thang == 1 || date.Thang == 3 || date.Thang == 5 || date.Thang == 7 || date.Thang == 8 || date.Thang == 10 || date.Thang == 12) {
				t += 31 - date.Ngay;
			}
			// thang 2 co 28 ngay, tru Nam nhuan co 29 ngay
			if (date.Thang == 2) {
				if (date.Nam % 4 == 0 && date.Nam % 100 != 0 || date.Nam % 400 == 0) {
					t += 29 - date.Ngay;
				}
				else {
					t += 28 - date.Ngay;
				}
			}

			date.Thang++;
			date.Ngay = 0;
			if (date.Thang == 13) {
				//tang Nam len
				date.Nam++;
				date.Thang = 1;
			}
		}
	}
	return t;
}

//so voi ngay hien tai
int SoGioCachNhau(Date ngay, Hour thoigian) { // nhap vao ngay gio khoi hanh cua chuyen bay
	Hour thoiGianHienTai;
	LayGioHienTai(thoiGianHienTai);

	Date ngayHienTai;
	LayNgayHienTai(ngayHienTai);

	int t1, t2, t3;
	if (SoSanhNgay(ngay) == 2) { // nho hon ngay hien tai
		if (KhoangCachNgayThangNam(ngay) == 1) {
			t1 = 24 * 60 - thoigian.Hours * 60 - thoigian.Minute;
			t2 = thoiGianHienTai.Hours * 60 + thoiGianHienTai.Minute;
			return (t1 + t2);
		}
		else
		{
			return 5 * 60;
		}
	}
	else if (SoSanhNgay(ngay) == 1) { // lon hon ngay hien tai
		if (KhoangCachNgayThangNam(ngay) == -1) {
			t1 = 24 * 60 - thoiGianHienTai.Hours * 60 - thoiGianHienTai.Minute;
			t2 = thoigian.Hours * 60 + thoigian.Minute;

			return (t1 + t2);
		}
		else {
			t1 = 24 * 60 - thoiGianHienTai.Hours * 60 - thoiGianHienTai.Minute;
			t2 = thoigian.Hours * 60 + thoigian.Minute;
			t3 = (ngay.Ngay - ngayHienTai.Ngay - 1) * 24 * 60;
			return (t1 + t2 + t3);
		}
	}
	else { // bang ngay hien tai
		t1 = thoigian.Hours * 60 + thoigian.Minute;
		t2 = thoiGianHienTai.Hours * 60 + thoiGianHienTai.Minute;
		if (t1 > t2) {
			return (t1 - t2);
		}
		else {
			return (t2 - t1);
		}
	}
}

bool KiemTraChuyenBayCungThoiDiem(List ds, string soHieu, Date ngay, Hour gio)
{
	for (NodeList *k = ds.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.SoHieuMB == soHieu && k->data.TrangThai != 3)
		{
			int t1 = SoGioCachNhau(ngay, gio);
			int t2 = SoGioCachNhau(k->data.NgayKhoiHanh, k->data.GioKhoiHanh);
			int t3 = t1 - t2;

			if (t3 < MAX_TIME && t3 > -MAX_TIME) { // khoang cach gio nho hon 4h
				return true; //MB da co dk CB roi
			}
		}
	}
	return false;
}

bool KTraTrungMaCB(List& l, string x) {
	for (NodeList* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->data.MaCB == x) {
			return true;
		}
	}
	return false;
}

void CapNhatCB(List& l, MCONTROMB &MB)//cap nhat trang thai chuyen bay va so luot CB trong ds May bay
{
	Hour GioHienTai;
	Date NgayHienTai;

	MayBay* tamMB = NULL;
	LayGioHienTai(GioHienTai);
	LayNgayHienTai(NgayHienTai);

	for (NodeList *i = l.pHead; i != NULL; i = i->pNext) {
		if (SoGioCachNhau(i->data.NgayKhoiHanh, i->data.GioKhoiHanh) > MAX_TIME && SoSanhNgay(i->data.NgayKhoiHanh) > 1 && i->data.TrangThai !=3) { // gio khoi hanh trc gio hien tai 4h thi trang thai la hoan tat
			if (SoSanhNgay(i->data.NgayKhoiHanh) == 2) { // nho hon ngay hien tai
				i->data.TrangThai = 3; // hoan tat
				tamMB = LayThongTinMB(MB, i->data.SoHieuMB);
				tamMB->SoLuotCB++;
			}
			else { // = ngay hien tai
				int t1 = i->data.GioKhoiHanh.Hours * 60 + i->data.GioKhoiHanh.Minute;
				int t2 = GioHienTai.Hours * 60 + GioHienTai.Minute;
				if (t1 < t2) {
					i->data.TrangThai = 3; // hoan tat
					tamMB = LayThongTinMB(MB, i->data.SoHieuMB);
					tamMB->SoLuotCB++;
				}
			}
		}

		//if (i->data.SoVeDaDat == i->data.TongSoVe) {
		//	i->data.TrangThai = 2; // het ve
		//}
	}
}
NodeList* LayThongTinCB(List l, string id) {
	if (l.pHead == NULL) return NULL;
	for (NodeList* p = l.pHead; p != NULL; p = p->pNext)
		if (p->data.MaCB == id)
			return p;
	return NULL;
}
