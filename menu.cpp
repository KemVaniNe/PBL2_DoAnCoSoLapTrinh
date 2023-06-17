#include"QuanLyMuonTra.h"
#include"QuanLyNguoiDangKy.h"
#include"QuanLyNhanVien.h"
#include"QuanLyTheThuVien.h"
#include"QuanLySach.h"

//UPDATE
void update(QuanLySach &m1, QuanLyNguoiDangKy &m2, QuanLyTheThuVien &m3, QuanLyMuonTra &m4, QuanLyNhanVien &m5)
{
    int data = -1, index;
    string macu, mamoi;
    do
    {
        cout << "SUA DOI:" << endl;
        cout << "1. Thong tin sach" << endl;
        cout << "2. Thong tin nguoi dang ky" << endl;
        cout << "3. The thu vien" << endl;
        cout << "4. Thong tin muon tra sach" << endl;
        cout << "5. Thong tin nhan vien" << endl;
        cout << "0. Tro ve" << endl;
        cout << setw(4) << " "<< "Lua chon update la: ";
        cin >> data;
        system("cls");
        switch (data)
        {
        case 1:
            cout << setw(10) << " "
                 << "BAT DAU THAY DOI THONG TIN SACH" << endl;
            cout << "Nhap ma sach ban muon thay doi: ";
            cin >> macu;
            index = m1.indexof(macu);
            m1.Update(macu);
            if (index >= 0)
            {
                mamoi = m1[index].getMa();
                m4.UpdateMS(macu, mamoi);
            }
            break;
        case 2:
            cout << setw(10) << " "
                 << "BAT DAU THAY DOI THONG TIN NGUOI DANG KY" << endl;
            cout << "Nhap ma nguoi dang ky ban muon thay doi: ";
            cin >> macu;
            m2.Update(macu);
            break;
        case 3:
            cout << setw(10) << " "
                 << "BAT DAU THAY DOI THONG TIN THE THU VIEN" << endl;
            cout << "Nhap ma the thu vien ban muon thay doi: ";
            cin >> macu;
            index = m3.indexof(macu);
            m3.Update(macu);
            if (index >= 0)
            {
                mamoi = m3[index].getMa();
                m4.UpdateTTV(macu, mamoi);
                m2.UpdateTTV(macu, mamoi);
            }
            break;
        case 4:
            cout << setw(10) << " "
                 << "BAT DAU THAY DOI THONG TIN MUON TRA SACH" << endl;
            cout << "Nhap ma muon tra ban muon thay doi: ";
            cin >> macu;
            m4.Update(macu);
            break;
        case 5:
            cout << setw(10) << " "
                 << "BAT DAU THAY DOI THONG TIN NHAN VIEN" << endl;
            cout << "Nhap ma nhan vien ban muon thay doi: ";
            cin >> macu;
            index = m5.indexof(macu);
            m5.Update(macu);
            if (index >= 0)
            {
                m4.UpdateNVM(macu, mamoi);
                m4.UpdateNVT(macu, mamoi);
            }
            break;
        case 0:
            cout << setw(10) << " "
                 << "TRO LAI GIAO DIEN CHINH!" << endl;
            break;
        default:
            cout << setw(10) << " "
                 << "BAN DA NHAP SAI LUA CHON!\n"
                 << endl;
            break;
        }
        system("pause");
        system("cls");
    } while (data != 0);
}

//BẢNG LỰA CHỌN
void menu()
{
    cout << setw(25) << " "
         << "=============================================================\n";
    cout << setw(25) << " "
         << "|" << setw(39) << " BANG LUA CHON " << setw(22) << "|\n";
    cout << setw(25) << " "
         << "=============================================================\n";
    cout << setw(25) << " "
         << "|" << setw(61) << "***********************QUAN LY THU VIEN********************|\n";
    cout << setw(25) << " "
         << "|" << setw(61) << "-----------------------------------------------------------|\n";
    cout << setw(25) << " "
         << "|" << setw(6) << "Nhap |" << setw(8) << "Thuc hien" << setw(46) << "|\n";
    cout << setw(25) << " "
         << "|" << setw(61) << "-----------------------------------------------------------|\n";
    cout << setw(25) << " "
         << "|" << setw(6) << "1 |" << setw(30) << "Thao tac voi thong tin sach" << setw(25) << "|\n";
    cout << setw(25) << " "
         << "|" << setw(6) << "2 |" << setw(39) << "Thao tac voi thong tin nguoi dang ky" << setw(16) << "|\n";
    cout << setw(25) << " "
         << "|" << setw(6) << "3 |" << setw(28) << "Thao tac voi the thu vien" << setw(27) << "|\n";
    cout << setw(25) << " "
         << "|" << setw(6) << "4 |" << setw(39) << "Thao tac voi thong tin muon tra sach" << setw(16) << "|\n";
    cout << setw(25) << " "
         << "|" << setw(6) << "5 |" << setw(35) << "Thao tac voi thong tin nhan vien" << setw(20) << "|\n";
    cout << setw(25) << " "
         << "|" << setw(6) << "0 |" << setw(24) << "Ket thuc chuong trinh" << setw(31) << "|\n";
    cout << setw(25) << " "
         << "|" << setw(61) << "-----------------------------------------------------------|\n";
    cout << setw(25) << " "
         << "|" << setw(6) << "7 |" << setw(27) << "Cap nhat thong tin chung" << setw(28) << "|\n";
    cout << setw(25) << " "
         << "=============================================================\n";
}

//BẢNG CÔNG VIỆC
void congviec()
{
    cout << setw(15) << " "
         << "=============================================================\n";
    cout << setw(15) << " "
         << "|" << setw(39) << " BANG CONG VIEC " << setw(22) << "|\n";
    cout << setw(15) << " "
         << "=============================================================\n";
    cout << setw(15) << " "
         << "|" << setw(6) << "Nhap |" << setw(8) << "Thuc hien" << setw(46) << "|\n";
    cout << setw(15) << " "
         << "|" << setw(61) << "-----------------------------------------------------------|\n";
    cout << setw(15) << " "
         << "|" << setw(6) << "1 |" << setw(51) << "Them doi tuong vao danh sach voi vi tri bat ky" << setw(4) << "|\n";
    cout << setw(15) << " "
         << "|" << setw(6) << "2 |" << setw(37) << "Them doi tuong vao dau danh sach" << setw(18) << "|\n";
    cout << setw(15) << " "
         << "|" << setw(6) << "3 |" << setw(38) << "Them doi tuong vao cuoi danh sach" << setw(17) << "|\n";
    cout << setw(15) << " "
         << "|" << setw(6) << "4 |" << setw(36) << "Xoa thong tin doi tuong theo ma" << setw(19) << "|\n";
    cout << setw(15) << " "
         << "|" << setw(6) << "5 |" << setw(39) << "Tim kiem thong tin cua 1 doi tuong" << setw(16) << "|\n";
    cout << setw(15) << " "
         << "|" << setw(6) << "6 |" << setw(23) << "Hien thi danh sach" << setw(32) << "|\n";
    cout << setw(15) << " "
         << "|" << setw(6) << "7 |" << setw(26) << "Xoa toan bo danh sach" << setw(29) << "|\n";
    cout << setw(15) << " "
         << "|" << setw(6) << "8 |" << setw(43) << "Hien thi thong tin tai 1 vi tri bat ky" << setw(12) << "|\n";
    cout << setw(15) << " "
         << "|" << setw(6) << "0 |" << setw(23) << "Ket thuc cong viec" << setw(32) << "|\n";
    cout << setw(15) << " "
         << "=============================================================\n";
}

//LỰA CHỌN CÔNG VIỆC
template<class T,class U>
void congviec(T &m,U p)
{
    int data = -1, index;
    string ma;
    U temp;
    do
    {
        congviec();
        cout << "Nhap lua chon cua ban: ";
        cin >> data;
        system("cls");
        switch(data)
        {
            case 1:
                cout << "Nhap thong tin can them: \n";
                cin >> temp;
                cout << "Nhap vi tri can them: ";
                cin >> index;
                m.insert(temp,index);
                break;
            case 2:
                cout << "Nhap thong tin can them vao dau danh sach:\n";
                cin >> temp;
                m.insert(temp,0);
                break;
            case 3:
                cout << "Nhap thong tin can them vao cuoi danh sach:\n";
                cin >> temp;
                m.insert(temp,m.N());
                break;
            case 4:
                cout << "Nhap ma cua doi tuong can xoa: ";
                cin >> ma;
                m.Delete(ma);
                break;
            case 5:
                cout << "Nhap ma cua doi tuong can tim kiem: ";
                cin >> ma;
                m.Search(ma);
                break;
            case 6:
                cout << setw(5) << "Hien thi danh sach\n";
                m.show();
                break;
            case 7:
                cout << "Ban co chac chan muon xoa toan bo thong tin danh sach nay khong?\nA. Co\nB. Khong\n";
                char luachon;
                cin >> luachon;
                switch(luachon)
                {
                    case 'A':
                        m.clear();
                        break;
                    case 'a':
                        m.clear();
                        break;
                    case 'B':
                        break;
                    case 'b':
                        break;
                    default:
                        cout << "Ban da nhap sai!\n";
                        break;
                }
                break;
            case 8:
                cout << "Nhap vi tri ban muon hien thi: ";
                cin >> index;
                cout << m[index];
                break;
            case 0:
                cout << setw(10) << "Cong viec se ket thuc!\n";
                break;
            default:
                cout << "Ban da nhap sai lua chon!" << endl;
                break;
        }
        system("pause");
        system("cls");
    }while(data!=0);
}

//LỰA CHỌN
void LuaChon(QuanLySach m1,QuanLyNguoiDangKy m2,QuanLyTheThuVien m3,QuanLyMuonTra m4,QuanLyNhanVien m5)
{
    TTSach m11;
    TTNguoiDangKy m22;
    TheThuVien m33;
    TTMuonTra m44;
    TTNhanVien m55;
    int data = -1;
    system("cls");
    do
    {
          menu();
          cout << "Nhap lua chon cua ban: ";
          cin >> data;
          system("cls");
          switch (data)
          {
               case 1:
                    cout << setw(15) << " " << "BAT DAU THAO TAC VOI THONG TIN SACH:\n";
                    congviec(m1,m11);
                    break;
               case 2:
                    cout << setw(15) << " " << "BAT DAU THAO TAC VOI THONG TIN NGUOI DANG KY:\n";
                    congviec(m2,m22);
                    break;
               case 3:
                    cout << setw(15) << " " << "BAT DAU THAO TAC VOI THE THU VIEN:\n";
                    congviec(m3,m33);
                    break;
               case 4:
                    cout << setw(15) << " " << "BAT DAU THAO TAC VOI THONG TIN MUON TRA SACH:\n";
                    congviec(m4,m44);
                    break;
               case 5:
                    cout << setw(15) << " " << "BAT DAU THAO TAC VOI THONG TIN NHAN VIEN:\n";
                    congviec(m5,m55);
                    break;
               case 7:
                    update(m1, m2, m3, m4, m5);
                    break;
               case 0:
                    cout << setw(15) << " " << "KET THUC CHUONG TRINH!";
                    break;
               default:
                    cout << setw(15) << " " << "BAN DA NHAP SAI LUA CHON!\n";
                    break;
          }
    } while (data != 0);
}

int main()
{
     QuanLySach m1;
     QuanLyNguoiDangKy m2;
     QuanLyTheThuVien m3;
     QuanLyMuonTra m4;
     QuanLyNhanVien m5;
     m1.docfile("inSach.txt");
     m2.docfile("inNguoiDangKy.txt");
     m3.docfile("inTheThuVien.txt");
     m4.docfile("inMuonTra.txt");
     m5.docfile("inNhanVien.txt");
     LuaChon(m1,m2,m3,m4,m5);
     // m1.ghifile("outSach.txt");
     // m2.ghifile("outNguoiDangKy.txt");
     // m3.ghifile("outTheThuVien.txt");
     // m4.ghifile("outMuonTra.txt");
     // m5.ghifile("outNhanVien.txt");
     return 0;
}