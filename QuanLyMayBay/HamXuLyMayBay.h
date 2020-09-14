#pragma once
#include "CTDL.h"

bool KTraTrungSoHieuMB(MCONTROMB& MB, string x) {
	//de bat dieu kien so hieu may bay phai la duy nhat
	for (int i = 0; i < MB.SoLgMB; i++) {
		if (MB.data[i]->SoHieuMB == x)
			return true;
	}
	return false;
}

MayBay* LayThongTinMB(MCONTROMB MB, string SoHieuMB)
{
	for (int i = 0; i < MB.SoLgMB; i++)
	{
		if (SoHieuMB == MB.data[i]->SoHieuMB)
		{
			return MB.data[i];
		}
	}
	return NULL;
}
