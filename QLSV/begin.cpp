#include"begin.h"
int InMenuBatDau(int ma_tk)//0 gv 1 sv lay tu login tra vector
{
	system("cls");
	BackGround();
	cout << endl;
	cout << "\t \t \t CHAO MUNG BAN DEN VOI HE THONG QUAN LY SINH VIEN\n";
	cout << "\t \t \t \t \t 1. Vao he thong chinh\n";
	cout << "\t \t \t \t \t 2. Xem thong tin cua ban\n";
	cout << "\t \t \t \t \t 3. Doi mat khau\n";
	cout << "\t \t \t \t \t 4. Dang xuat\n";
	cout << "\t \t \t \t \t 5. Thoat\n";
	return 5;//tra ve maxSelect
}
bool XlMenuBD(int chon, short lc, string tk, string& mk, ListNamHoc& l)//lc la maTk  0:Giao vu, 1: Sinh vien
{
	char lenh;
	switch (chon)
	{
	case 1:
	{
		if (lc == 0)
			GiaoVu(l);
		else
			SinhVien(l);
		break;
	}
	case 2:
	{
		cout << "Hien thi thong tin cua tai khoan";
		if (lc == 1)//tra ve sinh vien
		{
			viewInfoSv(findInfo(timLop(stoi(tk)), stoi(tk)));
			break;
		}
		if (lc == 0)
		{
			cout << "BO SUNG THONG TIN CHO GIAO VU !\n";
			system("pause");
			break;
		}
	}
	case 3:
	{
		changePass(lc, tk, mk);
	}
	case 4:
	{
		cout << "Ban se dang xuat ra khoi tai khoan nay? Y?N?" << endl;
		cin >> lenh;
		if (lenh == 'Y' || lenh == 'y')
			return true;
		system("pause");
		break;
	}
	case 5:
	{
		cout << "Ban thuc su muon thoat? Y/N?" << endl;
		cin >> lenh;
		if (lenh == 'Y' || lenh == 'y')
		{
			exit(0);
		}
	}
	}
	return false;
}

//NAM HOC 
void TaiData_Nam(ListNamHoc& l)
{
	fstream f;
	f.open("listnam.txt", ios::in | ios::app);
	string temp = "";
	while (!f.eof())
	{
		f.clear();
		getline(f, temp, ',');
		if (temp != "")//file co san du lieu
		{
			int nam_bd = stoi(temp);
			NodeNamHoc* n = new NodeNamHoc;
			n->pNext = NULL;
			n->data.tg.ngay_bd.y = nam_bd;
			n->data.tg.ngay_kt.y = nam_bd + 1;
			ThemNodeNamHoc(l, n);
			TaiData_Lop(n);
			TaiData_Mon(n);
		}
	}
	f.close();
}

//LOP HOC
NodeSv_Lop* TaoNodeSv(Sv sv)
{
	NodeSv_Lop* n = new NodeSv_Lop;
	n->sv = sv;
	n->pNext = NULL;
	return n;
}
void ThemNodeSvLop(NodeSv_Lop*& headSvLop, NodeSv_Lop* n)
{
	if (headSvLop == NULL)
	{
		headSvLop = n;
	}
	else
	{
		n->pNext = headSvLop;
		headSvLop = n;
	}
}
NodeSv_Lop* TaiData_SvLop(NodeLop* nodeLop)
{
	NodeSv_Lop* headSvLop = NULL;
	fstream f;
	f.open(nodeLop->lop.ten + ".txt", ios::in | ios::app);//mo file lop tuong ung 
	string s;
	while (!f.eof())//doc file ghi vo T, tao node sv cho T
	{
		Sv T;
		f.clear();
		getline(f, s, ',');
		if (s != "")
		{
			T.id = stoi(s);
			f.clear();
			getline(f, s, ',');
			T.stt = stoi(s);
			f.clear();
			getline(f, T.ten, ',');
			f.clear();
			getline(f, T.ho, ',');
			f.clear();
			getline(f, T.gioi, ',');
			f.clear();
			getline(f, s, ',');
			T.ngayS.d = stoi(s);
			T.ngayS.y = T.ngayS.d % 10000;
			T.ngayS.m = (T.ngayS.d / 10000) % 100;
			T.ngayS.d = T.ngayS.d / 1000000;
			f.clear();
			getline(f, s, ',');
			T.cmnd = atoi(s.c_str());
			ThemNodeSvLop(headSvLop, TaoNodeSv(T));
		}
	}
	f.close();
	return headSvLop;
}
void TaiData_Lop(NodeNamHoc* n)
{
	fstream f;
	string s;
	for (int i = 1; i <= 4; i++)
	{
		//mo file ds lop, khoi tao list lop cho sv n1234
		{
			if (i == 1)
			{
				n->data.headLopNam1 = new NodeLop;
				f.open(to_string(n->data.tg.ngay_bd.y) + "n1.txt", ios::in | ios::app);
			}
			else if (i == 2)
			{
				n->data.headLopNam2 = new NodeLop;
				//file nam nay chua dc tao -> sao chep data file nam ngoai sang 
				//vd: 2020n2.txt chua tao -> sao chep 2019n1.txt sang 
				f.open(to_string(n->data.tg.ngay_bd.y) + "n2.txt", ios::in | ios::app);
				getline(f, s);
				if (s == "")//file trong thi sao chep du lieu nam hoc cu
				{
					fstream f1;
					f1.open(to_string(n->data.tg.ngay_bd.y - 1) + "n1.txt", ios::in);
					while (!f1.eof())
					{
						getline(f1, s);
						f << s << "\n";
					}
					f1.close();//dong file nam cu
				}
				f.close();//dong lai file de khoi phuc lai con tro file 
				f.open(to_string(n->data.tg.ngay_bd.y) + "n2.txt", ios::in);//mo file moi o che do doc de doc lai tu dau file
			}
			else if (i == 3)
			{
				n->data.headLopNam3 = new NodeLop;
				f.open(to_string(n->data.tg.ngay_bd.y) + "n3.txt", ios::in | ios::app);
				getline(f, s);
				if (s == "")
				{
					fstream f1;
					f1.open(to_string(n->data.tg.ngay_bd.y - 1) + "n2.txt", ios::in);
					while (!f1.eof())
					{
						getline(f1, s);
						f << s << "\n";
						f1.close();//dong file nam cu
					}
				}
				f.close();//dong lai file vua tao moi o che do app <con tro trong file dang o cuoi>
				f.open(to_string(n->data.tg.ngay_bd.y) + "n3.txt", ios::in);//mo file moi o che do doc de doc lai tu dau file
			}
			else
			{
				n->data.headLopNam4 = new NodeLop;
				f.open(to_string(n->data.tg.ngay_bd.y) + "n4.txt", ios::in | ios::app);
				getline(f, s);
				if (s == "")
				{
					fstream f1;
					f1.open(to_string(n->data.tg.ngay_bd.y - 1) + "n3.txt", ios::in);
					while (!f1.eof())
					{
						getline(f1, s);
						f << s << "\n";
					}
					f1.close();//dong file nam cu
				}
				f.close();//dong lai file vua tao moi o che do app <con tro trong file dang o cuoi>
				f.open(to_string(n->data.tg.ngay_bd.y) + "n4.txt", ios::in);//mo file moi o che do doc de doc lai tu dau file
			}
		}
		//doc file, tao node, them node
		while (!f.eof())
		{
			f.clear();
			getline(f, s, ',');
			if (s != "")
			{
				NodeLop* node = new NodeLop;
				node->pNext = NULL;
				node->lop.ten = s;
				node->lop.headSvLop = TaiData_SvLop(node);
				if (i == 1)
					ThemNodeLopHoc(n->data.headLopNam1, node);
				else if (i == 2)
					ThemNodeLopHoc(n->data.headLopNam2, node);
				else if (i == 3)
					ThemNodeLopHoc(n->data.headLopNam3, node);
				else
					ThemNodeLopHoc(n->data.headLopNam4, node);
			}
		}
		f.close();
	}
}

//MON HOC 
void ThemNodeMon(NodeMon*& A, NodeMon* T)//themdau
{
	if (A == NULL)
		A = T;
	else
	{
		T->pNext = A;
		A = T;
	}
}
void TaiData_Mon(NodeNamHoc* n)
{
	fstream f;
	string s;
	n->data.hk1.headMon = new NodeMon;
	n->data.hk2.headMon = new NodeMon;
	n->data.hk3.headMon = new NodeMon;
	HocKy* A;
	for (int i = 1; i <= 3; i++)//xem tung hk 
	{
		//mo file thong tin cac hoc ky
		{
			if (i == 1)
			{
				f.open(to_string(n->data.tg.ngay_bd.y) + "hk1.txt", ios::in | ios::app);
				A = &(n->data.hk1);
			}
			else if (i == 2)
			{
				f.open(to_string(n->data.tg.ngay_bd.y) + "hk2.txt", ios::in | ios::app);
				A = &(n->data.hk2);
			}
			else
			{
				f.open(to_string(n->data.tg.ngay_bd.y) + "hk3.txt", ios::in | ios::app);
				A = &(n->data.hk3);
			}
		}
		//lay tg hoc ky
		f.clear();
		getline(f, s, ',');
		if (s != "" && s!="\n")
		{
			A->tg.ngay_bd.d = atoi(s.c_str());
			A->tg.ngay_bd.y = A->tg.ngay_bd.d % 10000;
			A->tg.ngay_bd.m = (A->tg.ngay_bd.d / 10000) % 100;
			A->tg.ngay_bd.d = A->tg.ngay_bd.d / 1000000;
			f.clear();
			getline(f, s, ',');
			A->tg.ngay_kt.d = atoi(s.c_str());
			A->tg.ngay_kt.y = A->tg.ngay_kt.d % 10000;
			A->tg.ngay_kt.m = (A->tg.ngay_kt.d / 10000) % 100;
			A->tg.ngay_kt.d = A->tg.ngay_kt.d / 1000000;
			getline(f, s);//xoa "/n" ra khoi f truoc khi den thong tin mon
		}
		else
		{
			f.close();
			return;
		}
		//doc info mon trong file hoc ky NEU CO 
		A->headMon = NULL;
		f.clear();
		while (!f.eof())
		{
			getline(f, s, ',');
			if (s == "" || s == "\n")
			{
				break;
			}
			NodeMon* t = new NodeMon;
			t->data.id = s;
			getline(f, t->data.tenMon, ',');
			getline(f, t->data.tenGv, ',');
			getline(f, s, ',');
			t->data.so_tc = stoi(s);
			getline(f, t->data.bh1.thu, ',');
			getline(f, t->data.bh1.buoi, ',');
			getline(f, t->data.bh2.thu, ',');
			getline(f, t->data.bh2.buoi, ',');
			getline(f, s);//xoa "\n" ra khoi f
			t->pNext = NULL;
			t->headSvMon = NULL;
			//tai dssv cua mon trong file mon len 
			TaiData_SvMon(t, n, i);
			ThemNodeMon(A->headMon, t);//them vao list mon cua hoc ky
		}
		f.close();
	}
}
NodeLop* timNodeLop(NodeNamHoc* namhoc, int styear, string lop)
{
	NodeLop* n;
	if (styear == 1)
		n = namhoc->data.headLopNam1;
	else if (styear == 2)
		n = namhoc->data.headLopNam2;
	else if (styear == 3)
		n = namhoc->data.headLopNam3;
	else
		n = namhoc->data.headLopNam4;
	while (n != NULL)
	{
		string s = n->lop.ten;
		if (s == lop) return n;
		n = n->pNext;
	}
	exit(1);
}
NodeSv_Lop* timNodeSv_Lop(NodeSv_Lop* head, int mssv)
{
	NodeSv_Lop* t = head;
	while (t != NULL)
	{
		if (t->sv.id == mssv) return t;
		t = t->pNext;
	}
	exit(1);
}
//Can cai tien them de tai su dung khi muon doc thong tin sv_mon
//Sv findInfo(int id)//co mssv -> mo file sv.txt, doc ten lop cua sv->mo file lop.txt len ->doc info sv
//{
//	string tenLop = timLop(id);
//	string s;
//	Sv T;
//	ifstream f;
//	f.open(tenLop + ".txt");
//	//do tim sv trong lop 
//	while (!f.eof())
//	{
//		f.clear();
//		getline(f, s, ',');
//		if (s == to_string(id))
//		{
//			break;
//		}
//		f.clear();
//		getline(f, s);//bo qua cac data thua cua sv khac
//	}
//	f.clear();
//	getline(f, s, ',');
//	T.stt = atoi(s.c_str());
//	f.clear();
//	getline(f, T.ten, ',');
//	f.clear();
//	getline(f, T.ho, ',');
//	f.clear();
//	getline(f, T.gioi, ',');
//	f.clear();
//	getline(f, s, ',');
//	T.ngayS.d = atoi(s.c_str());
//	T.ngayS.y = T.ngayS.d % 10000;
//	T.ngayS.m = (T.ngayS.d / 10000) % 100;
//	T.ngayS.d = T.ngayS.d / 1000000;
//	f.clear();
//	getline(f, s, ',');
//	T.cmnd = atoi(s.c_str());
//	f.close();
//	return T;
//}
void ThemNodeMon_Sv(NodeMon_Sv*& head, NodeMon* A, NodeSv_Mon* sv_mon)//them dau
{
	NodeMon_Sv* n = new NodeMon_Sv;
	n->mon = A;
	n->svMon = sv_mon;
	n->pNext = head;
	head = n;
}
void TaiData_SvMon(NodeMon*& mon, NodeNamHoc* nodeNam, int ki)
{
	fstream f;
	int nam = nodeNam->data.tg.ngay_bd.y;
	string filePath = to_string(nam) + "hk" + to_string(ki) + mon->data.id + ".txt";
	f.open(filePath, ios::in | ios::app);//chua tao file thi tao
	//trong file chua: mssv,lop,diem-gk,ck,cong,tk
	string s;
	while (!f.eof())
	{
		//doc du lieu len nodesv_mon
		f.clear();
		getline(f, s, ',');
		if (s != "")
		{
			NodeSv_Mon* t = new NodeSv_Mon;
			t->mssv = stoi(s);
			getline(f, t->lop, ',');
			getline(f, s, ',');
			if (s == "R")//neu da co diem 
			{
				getline(f, s, ',');
				t->diem.gk = stof(s);
				getline(f, s, ',');
				t->diem.ck = stof(s);
				getline(f, s, ',');
				t->diem.cong = stof(s);
				getline(f, s, ',');
				t->diem.tongket = stof(s);
			}
			getline(f, s);//bo "\n" o dong cu 
			//them node vao dau list sv_mon
			t->pNext = mon->headSvMon;
			mon->headSvMon = t;
			//them con tro den nodesv_mon vao list mon cua nodesv_lop
			{
				int study_year;//nam nhat,2,3,4
				int K = stoi(t->lop.substr(0, 2));//lay ra 2 ki tu dau cua ten lop 
				study_year = nam % 2000 - K + 1;//chi dung doi voi cac nam hoc 2000~
				NodeLop* nodeLop = timNodeLop(nodeNam, study_year, t->lop);
				NodeSv_Lop* A = timNodeSv_Lop(nodeLop->lop.headSvLop, t->mssv);
				if (ki == 1)
					ThemNodeMon_Sv(A->headMonhk1, mon, mon->headSvMon);
				else if (ki == 2)
					ThemNodeMon_Sv(A->headMonhk2, mon, mon->headSvMon);
				else
					ThemNodeMon_Sv(A->headMonhk3, mon, mon->headSvMon);
			}
		}
	}
	f.close();
}
//
string timLop(int id)//tra ve ten lop cua sv co id tuong ung 
{
	ifstream f;
	f.open("SinhVien.txt");
	string s;
	bool flag = false;
	while (!f.eof())
	{
		f.clear();
		getline(f, s, ',');
		if (s == to_string(id))
		{
			f.clear();
			getline(f, s, ',');//bo qua pass 
			f.clear();
			getline(f, s, ',');//chi doc ten lop
			break;
		}
		f.clear();
		getline(f, s);//bo qua cac data thua cua sv khac
	}
	f.close();
	return s;
}