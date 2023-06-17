#pragma once
#include"DungChung.cpp"

class TTNhanVien
{
protected:
    string manhanvien;
    string tennhanvien;
    string sdt;
    string diachi;

public:
    TTNhanVien(string = "", string = "", string = "", string = "");
    ~TTNhanVien();
    friend ostream &operator<<(ostream &, const TTNhanVien &);
    friend istream &operator>>(istream &, TTNhanVien &);
    void Update();
    string getMa();
    void docfile(string);
    void getcot();
    void getdong();
    string ghifile();
};

TTNhanVien::TTNhanVien(string a1, string a2, string a3, string a4) : manhanvien(a1), tennhanvien(a2), sdt(a3), diachi(a4)
{
}

TTNhanVien::~TTNhanVien()
{
}

ostream &operator<<(ostream &o, const TTNhanVien &t)
{
    o << "|" << setw(12) << t.manhanvien << " |" << setw(30) << t.tennhanvien << " |"<< setw(12) << t.sdt << " |"<< setw(50) << t.diachi << " |"<< endl;
    return o;
}

istream &operator>>(istream &in, TTNhanVien &t)
{
    cout << "1. Nhap ma nhan vien: ";
    in >> t.manhanvien;
    cout << "2. Nhap ten nhan vien: ";
    fflush(stdin);
    getline(in, t.tennhanvien);
    cout << "3. Nhap so dien thoai: ";
    in >> t.sdt;
    cout << "4. Nhap dia chi: ";
    fflush(stdin);
    getline(in, t.diachi);
    return in;
}

string TTNhanVien::getMa()
{
    return this->manhanvien;
}

void TTNhanVien::Update()
{
    char data;
    string ma;
    do
    {
        cout << "BAN MUON THAY DOI GI:\nA. Ma nhan vien\nB. Ten nhan vien\nC. So dien thoai\nD. Dia chi\nG. Thoat\n";
        cout << setw(4) << "Lua chon thay doi nhan vien ban la: ";
        cin >> data;
        switch (data)
        {
        case 'A':
            cout << "Nhap ma nhan vien: ";
            cin >> ma;
            this->manhanvien = ma;
            break;
        case 'B':
            cout << "Nhap ten nhan vien: ";
            fflush(stdin);
            getline(cin, ma);
            this->tennhanvien = ma;
            break;
        case 'C':
            cout << "nhap dia chi moi: ";
            fflush(stdin);
            getline(cin, ma);
            this->diachi = ma;
        case 'D':
            cout << "Nhap so dien thoai moi: ";
            cin >> ma;
            this->sdt = ma;
            break;
        case 'G':
            break;
        default:
            cout << "Ban da nhap sai lua chon!\n";
            break;
        }
    } while (data != 'G');
}

void TTNhanVien::docfile(string temp)
{
    this->manhanvien = tach(temp,",");
    this->tennhanvien = tach(temp,",");
    this->sdt = tach(temp,",");
    this->diachi = temp;
}

void TTNhanVien::getcot()
{
    cout << "=================================================================================================================\n";
    cout << "|"<< setw(12) << "MA_NV" << " |"<< setw(30) << "TEN_NV" << " |"<< setw(12) << "SDT" << " |"<< setw(50) << "DIA_CHI" << " |"<< endl;
    cout << "=================================================================================================================\n";   
}

void TTNhanVien::getdong()
{
    cout << "=================================================================================================================\n";    
}

string TTNhanVien::ghifile()
{
    string temp = this->manhanvien + "," + this->tennhanvien + "," + this->sdt + "," + this->diachi; 
    return temp;
}
