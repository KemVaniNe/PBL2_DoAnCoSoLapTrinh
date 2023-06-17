#include"Date.h"
#include"DungChung.cpp"

class TheThuVien : virtual public Date
{
protected:
    string mathe;
    Date ngaybatdau;
    Date ngayketthuc;

public:
    TheThuVien(string = "", string = "00", string = "00", string = "0000", string = "00",string = "00", string = "0000");
    ~TheThuVien();
    friend ostream &operator<<(ostream &, const TheThuVien &);
    friend istream &operator>>(istream &, TheThuVien &);
    void Update();
    string getMa();
    void docfile(string);
    void getcot();
    void getdong();
    string ghifile();
};

TheThuVien::TheThuVien(string a1, string a2, string a3, string a4, string a5, string a6, string a7) 
: mathe(a1), ngaybatdau(a2, a3, a4), ngayketthuc(a5, a6, a7)
{
}

TheThuVien::~TheThuVien()
{
}

ostream &operator<<(ostream &o, const TheThuVien &t)
{
    o << "|"<<setw(12) << t.mathe <<" |" <<setw(10) << " "<<setw(11) << t.ngaybatdau <<" |"<<setw(10) << " "<< setw(11) << t.ngayketthuc <<" |"<< endl;
    return o;
}

istream &operator>>(istream &in, TheThuVien &t)
{
    cout << "1. Nhap ma the: ";
    in >> t.mathe;
    cout << "2. Nhap ngay bat dau: ";
    in >> t.ngaybatdau;
    cout << "3. Nhap ngay ket thuc: ";
    in >> t.ngayketthuc;
    return in;
}

void TheThuVien::Update()
{
    Date ngay;
    string ma;
    char chon;
    do
    {
        cout << "BAN MUON THAY DOI GI:\nA. Ma the\nB. Ngay bat dau\nC. Ngay ket thuc\nG. Thoat\n";
        cout << setw(4) << "Lua chon thay doi the thu vien: ";
        cin >> chon;
        switch (chon)
        {
        case 'A':
            cout << "Nhap ma the moi: ";
            cin >> ma;
            this->mathe = ma;
            break;
        case 'B':
            cout << "Nhap ngay dat dau: ";
            cin >> ngay;
            this->ngaybatdau = ngay;
            break;
        case 'C':
            cout << "Nhap ngay ket thuc: ";
            cin >> ngay;
            this->ngayketthuc = ngay;
            break;
        case 'G':
            break;
        default:
            cout << "Ban da nhap sai lua chon!\n";
            break;
        }
    } while (chon != 'G');
}

string TheThuVien::getMa()
{
    return this->mathe;
}

void TheThuVien::docfile(string temp)
{
    string ngay1,thang1,nam1;
    this->mathe = tach(temp,",");
    ngay1 = tach(temp,"/");
    thang1 = tach(temp,"/");
    nam1 = tach(temp,",");
    this->ngaybatdau = Date(ngay1,thang1,nam1);
    ngay1 = tach(temp,"/");
    thang1 = tach(temp,"/");
    nam1 = temp;
    this->ngayketthuc = Date(ngay1,thang1,nam1);
}

void TheThuVien::getcot()
{
    cout << "===========================================================\n";
    cout <<"|"<< setw(12) << "MA_THE" <<" |"<< setw(20) << "NGAY_BD" <<" |"<< setw(20) << "NGAY_KT" <<" |"<< endl;
    cout << "===========================================================\n";
}

void TheThuVien::getdong()
{
    cout << "===========================================================\n";
}

string TheThuVien::ghifile()
{
    string temp = this->mathe + "," + this->ngaybatdau.ghifile() + "," + this->ngayketthuc.ghifile();
    return temp;
}