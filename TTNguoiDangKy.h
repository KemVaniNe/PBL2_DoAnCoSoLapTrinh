#include"Date.h"
#include"DungChung.cpp"

class TTNguoiDangKy : virtual public Date
{
protected:
    string manguoidk;
    string tenguoidk;
    string sdt;
    string diachi;
    Date ngaysinh;
    Date ngaydk;
    string mathe;

public:
    TTNguoiDangKy(string = "", string = "", string = "", string = "", string ="00",string ="00",string ="0000", string ="00",string ="00",string ="0000", string = "");
    ~TTNguoiDangKy();
    friend ostream &operator<<(ostream &, const TTNguoiDangKy &);
    friend istream &operator>>(istream &, TTNguoiDangKy &);
    void Update();
    string getMa();
    void UpdateTTV(string, string);
    void docfile(string);
    void getcot();
    void getdong();
    string ghifile();
};

TTNguoiDangKy::TTNguoiDangKy(string a1, string a2, string a3, string a4, string a5, string a6, string a7, string a8, string a9, string a10, string a11)
    : manguoidk(a1), tenguoidk(a2), sdt(a3), diachi(a4), ngaysinh(a5, a6, a7), ngaydk(a8, a9, a10), mathe(a11)
{
}

TTNguoiDangKy::~TTNguoiDangKy()
{
}

ostream &operator<<(ostream &o, const TTNguoiDangKy &t)
{
    o <<"|" <<setw(12) << t.manguoidk << " |"<< setw(30) << t.tenguoidk << " |"<< setw(12) << t.sdt << " |"<< setw(25) << t.diachi << " |"<<setw(10) << " "<< setw(20) << t.ngaysinh << " |"<< setw(10) << " " << setw(20) << t.ngaydk << " |"<< setw(12) << t.mathe << " |"<< endl;
    return o;
}

istream &operator>>(istream &in, TTNguoiDangKy &t)
{
    cout << "1. Nhap ma nguoi dang ky: ";
    in >> t.manguoidk;
    cout << "2. Nhap ten nguoi dang ky: ";
    fflush(stdin);
    getline(in, t.tenguoidk);
    cout << "3. Nhap so dien thoai ";
    in >> t.sdt;
    cout << "4. Nhap dia chi: ";
    fflush(stdin);
    getline(in, t.diachi);
    cout << "5. Nhap ngay sinh: ";
    in >> t.ngaysinh;
    cout << "6. Nhap ngay dang ky: ";
    in >> t.ngaydk;
    cout << "7. Nhap ma the: ";
    in >> t.mathe;
    return in;
}

string TTNguoiDangKy::getMa()
{
    return this->manguoidk;
}

void TTNguoiDangKy::Update()
{
    char chon;
    string ma;
    Date ngay;
    do
    {
        cout << "BAN MUON THAY DOI GI:\nA. Ma nguoi dang ky\nB. Ten nguoi dang ky\nC. So dien thoai\nD. Dia chi\nE. Ngay sinh\nF. Ngay dang ky\nH. Ma the\nG. Thoat\n";
        cout << setw(4) << "Lua chon thay doi nguoi dang ky: ";
        cin >> chon;
        switch (chon)
        {
        case 'A':
            cout << "Nhap ma dang ky moi: ";
            cin >> ma;
            this->manguoidk = ma;
            break;
        case 'B':
            cout << "Nhap ten nguoi dang ky moi: ";
            fflush(stdin);
            getline(cin, ma);
            this->tenguoidk = ma;
            break;
        case 'C':
            cout << "Nhap so dien thoai moi: ";
            cin >> ma;
            this->sdt = ma;
            break;
        case 'D':
            cout << "Nhap dia chi moi: ";
            fflush(stdin);
            getline(cin, ma);
            this->diachi = ma;
            break;
        case 'E':
            cout << "Nhap ngay sinh moi: ";
            cin >> ngay;
            this->ngaysinh = ngay;
            break;
        case 'F':
            cout << "Nhap ngay dang ky moi: ";
            cin >> ngay;
            this->ngaydk = ngay;
        case 'G':
            break;
        default:
            cout << "Ban da nhap sai lua chon!\n";
            break;
        }
    } while (chon != 'G');
}

void TTNguoiDangKy::UpdateTTV(string macu, string mamoi)
{
    if (this->mathe == macu)
        this->mathe = mamoi;
}

void TTNguoiDangKy::docfile(string temp)
{
    string mathe;
    string ngay,thang,nam;
    this->manguoidk = tach(temp,",");
    this->tenguoidk = tach(temp,",");
    this->sdt = tach(temp,",");
    this->diachi = tach(temp,",");
    ngay = tach(temp,"/");
    thang = tach(temp,"/");
    nam = tach(temp,",");
    this->ngaysinh = Date(ngay,thang,nam);
    ngay = tach(temp,"/");
    thang = tach(temp,"/");
    nam = tach(temp,",");
    this->ngaydk = Date(ngay,thang,nam);
    this->mathe = temp;
}

void TTNguoiDangKy::getcot()
{
    cout << "=================================================================================================================================================\n";
    cout << "|"<<setw(12) << "MA_NGUOI_DK" << " |"<< setw(30) << "TEN_NGUOI_DK" << " |"<< setw(12) << "SDT" << " |"<< setw(25) << "DIA_CHI" << " |"<< setw(20) << "NGAY_SINH" << " |"<< setw(20) << "NGAY_DK" << " |"<< setw(12) << "MA_THE" << " |"<< endl;
    cout << "=================================================================================================================================================\n";
}

void TTNguoiDangKy::getdong()
{
    cout << "=================================================================================================================================================\n";    
}

string TTNguoiDangKy::ghifile()
{
    string temp = this->manguoidk + "," + this->tenguoidk + "," + this->sdt + "," + this->diachi + "," + this->ngaysinh.ghifile() +","+ this->ngaydk.ghifile() + "," + this->mathe;
    return temp;
}