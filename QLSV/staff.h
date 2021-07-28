#pragma once
#include"begin.h"

int InMenuGv();
bool XlMenuGv(int chon, ListNamHoc& l);
void GiaoVu(ListNamHoc& l);

void ThongbaoCautrucFile(bool chon);
bool importFilehayNhapTay(bool chon);

//TAO MOI
int InMenuTaoMoi();
bool XlTaoMoi(int chon, ListNamHoc& l);
//nam hoc
NodeNamHoc* TaoNodeNam();
void ThemNodeNamHoc(ListNamHoc& l, NodeNamHoc* n);
void TaoNam(ListNamHoc& l);
//lop hoc
NodeLop* TaoNodeLop(string ten);
void ThemNodeLopHoc(NodeLop*& HeadLop, NodeLop* n);
void HienLopHoc(NodeLop* HeadLop);
void TaoLopNamNhat(NodeNamHoc* node);
//hoc ky
NodeNamHoc* TimNodeNamHoc(ListNamHoc& l, int nam_bd);
bool sosanhNgay(Ngay ngay_truoc, Ngay ngay_sau);
bool XungdotTg(HocKy* hktruoc, Ngay ngBD_hksau, int hkTr, int hkS);
void TaoHocKy(ListNamHoc& l);
//mon hoc 
HocKy* HkHienTai(ListNamHoc& l, NodeNamHoc* n, int& i);
bool NhapNodeMon(NodeMon* n);
int HienLuaChonThu(int line);
string HienLuaChonGio(int line);
void XulyThu(int lc, BuoiHoc& bh);
void NhapTgMon(NodeMon* n);
bool checkTrungMon(NodeMon* head, NodeMon* n);
void TaoMon(ListNamHoc& l, int nam);
NodeMon* mondangmo_docfile(string file, int nam, int stt_hk);
NodeMon* mondangmo_nhaptay(int nam, int stt_hk);

//CAP NHAT
bool XlCapNhat(int chon, ListNamHoc& l);
int InMenuCapNhat();
int InMenuCapNhat2(); //muc 2 cua menu cap nhat chinh
int InMenuCapNhat3(); //muc 3 cua menu cap nhat chinh
//them sv
void NhapThongtinSv(NodeSv_Lop* n, int i);
bool checkTrungSv(NodeSv_Lop* n, NodeSv_Lop* head);
void GhiThongtinSv(NodeLop* nodeLop, NodeSv_Lop* n);
void ThemNodeSvLop(NodeSv_Lop*& headSvLop, NodeSv_Lop* nodeSv);
void ThemSvLop_tay(NodeLop* nodeLop);
void ThemSvLop_file(NodeLop* nodeLop);
void ThemSvLopNam1(ListNamHoc& l);
//sua info mon
void GhiFileMon(string filename, NodeMon* mon, bool remove);
void CapNhatMonHoc(ListNamHoc& l);
NodeMon* timNodeMon_CapNhat(ListNamHoc& l, int& nam, int& ki, NodeMon*& headmonHK);
//xoa mon
void XoaMonHoc(ListNamHoc& l);
//xoa mon ra khoi ds mon cua sv (neu co sv dang ky)
bool XoaMon_sv(ListNamHoc& l, NodeMon*& headmonHK, NodeMon* mon, int nam, int ki);
//diem 
//void XuatFileCsv(NodeNamHoc* nodeNam, HocKy* hk, int stt_hk);
//bool DocDiemTuFile(string file, NodeMon* mon, int siso);
//void NhapDiemTuFile(NodeNamHoc* nodeNam, HocKy* hk, int stt_hk);
//void CapNhatDiemSv(ListNamHoc& l);
//float NhapDiem(float diem);
//void LuuDiemSv(string filename, NodeSv_Mon* node_sv_mon);
//void HienThiDSLop(NodeLop* head_lop);
//void HienThiDSSv(NodeSv_Lop* head_sv_lop);

//HIENTHI
//neu chua co du lieu
void hienthiNam(ListNamHoc l, int& lc);
//ki
void hienthiKi(NodeNamHoc* A, int& lc);
void hienthiDsMon(NodeMon* head, int& lc);
void hienthiDsSv_Mon(NodeMon* A, int& lc);
void end(int& lc);
int chonSt_Year();
//lop
bool ChonTThayDiem_Lop();
void hienthiDsLop(NodeLop* head, int& lc);
void hienthiTTSv_Lop(NodeLop* A, int& lc);
void hienthiDiem_Lop(NodeLop* A, int& lc);
bool ChonKihayLop();