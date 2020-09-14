#include"Run.h"

int main()
{
	MCONTROMB MB;
	List l;
	TREE t = NULL;
	Khoitao(MB, l, t);
	//	system("pause");

	//	ifstream filein;
	//	ofstream fileout;
	//	
	//	DocDanhSachMayBay(filein,MB);
	//	GhiFileMayBay(fileout,MB);
	//	
	//	DocFileDanhSachChuyenBay(filein,l);
	//	GhiFileDanhSachChuyenBay(fileout,l);
	//
	//	DocFileHanhKhach(filein,t);

	while (true)
	{
		RunMenu(MB, l, t);
	}
	//system("pause");
	system("color 15");
	return 0;
}