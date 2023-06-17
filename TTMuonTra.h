#include"TTSach.h"
#include"Date.h"

class TTMuonTra : public TTSach, virtual public Date
{
protected:
    string mamuontra;
    string mathe;
    string nhanvienmuon;
    Date ngaymuon;
    string tinhtrang;
    string nhanvientra;
    Date ngaytra;

public:
    TTMuonTra(string = "", string = "", string = "", string = "", string ="00",string ="00",string ="0000", string = "chua tra");
    TTMuonTra(string , string , string , string , string , string , string , bool ,string ,string , string , string);
    ~TTMuonTra();
    void setTra();
    friend ostream &operator<<(ostream &, const TTMuonTra &);
    friend istream &operator>>(istream &, TTMuonTra &);
    void Update();
    string getMa();
    void UpdateMS(string, string);
    void UpdateNVM(string, string);
    void UpdateNVT(string, string);
    void UpdateTTV(string, string);
    void docfile(string);
    void getcot();
    void getdong();
    string ghifile();
};

TTMuonTra::TTMuonTra(string a1, string a2, string a3, string a, string a4, string a5, string a6, string a7)
    : mamuontra(a1), mathe(a2)
{
    this->masach = a3;
    this->nhanvienmuon = a;
    this->ngaymuon = Date(a4, a5, a6);
    this->tinhtrang = a7;
    if (a7 == "da tra"||a7 =="Da tra")
    {
        this->setTra();
    }
    else
        this->nhanvientra = "";
}

TTMuonTra::TTMuonTra(string a1, string a2, string a3, string a4, string a5, string a6, string a7, bool a8,string a9,string a10, string a11, string a12)
:mamuontra(a1),mathe(a2)
{
    this->masach=a3;
    this->nhanvienmuon=a4;
    this->ngaymuon = Date(a5,a6,a7);
    this->tinhtrang = a8;
    this->nhanvientra = a9;
    this->ngaytra = Date(a10,a11,a12);
}

void TTMuonTra::setTra()
{
    string ma;
    Date ngay;
    cout << "Nhap nhan vien tra: ";
    cin >> ma;
    cout << "Nhap ngay tra: ";
    cin >> ngay;
    this->nhanvientra = ma;
    this->ngaytra = ngay;
}

TTMuonTra::~TTMuonTra()
{
}

ostream &operator<<(ostream &o, const TTMuonTra &t)
{
    o <<"|"<< setw(12) << t.mamuontra <<" |"<< setw(12) << t.mathe <<" |"<< setw(12) << t.masach <<" |"<< setw(12) << t.nhanvienmuon <<" |"<<setw(10) << " "<< setw(20) << t.ngaymuon <<" |"<< setw(12) << t.tinhtrang <<" |"<< setw(12) << t.nhanvientra <<" |"<<setw(10) << " "<< setw(20) << t.ngaytra <<" |"<< endl;
    return o;
}

istream &operator>>(istream &in, TTMuonTra &t)
{
    cout << "1. Nhap ma muon tra: ";
    in >> t.mamuontra;
    cout << "2. Nhap ma the thu vien: ";
    in >> t.mathe;
    cout << "3. Nhap ma sach: ";
    in >> t.masach;
    cout << "4. Nhap ma nhan vien cho muon: ";
    in >> t.nhanvienmuon;
    cout << "5. Nhap ngay muon: ";
    in >> t.ngaymuon;
    cout << "6. Nhap tinh trang(da tra hoac chua tra): ";
    fflush(stdin);
    getline(in, t.tinhtrang);
    if (t.tinhtrang == "da tra")
    {
        cout << "7. Nhap ma nhan vien tra: ";
        in >> t.nhanvientra;
        cout << "8. Nhap ngay tra: ";
        in >> t.ngaytra;
    }
    return in;
}

void TTMuonTra::Update()
{
    char data;
    string ma;
    Date ngay;
    string tt;
    do
    {
        cout << "BAN MUON THAY DOI GI:\nA. Ma muon tra\nB. Ma the\nC. Ma sach\nD. Ma nhan vien cho muon\nE. Ngay muon\nF. Tinh trang\nK. Ma nhan vien tra\nL. Ngay tra\nG. Thoat\n";
        cout << setw(4) <<" "<< "Lua chon thay doi muon tra: ";
        cin >> data;
        switch (data)
        {
        case 'A':
            cout << "Nhap ma moi: ";
            cin >> ma;
            this->mamuontra = ma;
            break;
        case 'B':
            cout << "Nhap ma moi: ";
            cin >> ma;
            this->mathe = ma;
            break;
        case 'C':
            cout << "Nhap ma moi: ";
            cin >> ma;
            this->masach = ma;
            break;
        case 'D':
            cout << "Nhap ma moi: ";
            cin >> ma;
            this->nhanvienmuon = ma;
            break;
        case 'E':
            cout << "Nhap ngay moi: ";
            cin >> ngay;
            this->ngaymuon = ngay;
            break;
        case 'F':
            cout << "Nhap tinh trang: ";
            fflush(stdin);
            getline(cin, tt);
            this->tinhtrang = tt;
            if (this->tinhtrang == "da tra")
                this->setTra();
            if (this->tinhtrang == "chua tra")
                {
                    this->nhanvientra = "";
                    this->ngaytra = Date();
                }
            break;
        case 'K':
            if (this->tinhtrang == "da tra")
            {
                cout << "Nhap ma moi: ";
                cin >> ma;
                this->nhanvientra = ma;
            }
            else
                cout << "Sach chua duoc tra!\n";
            break;
        case 'L':
            if (this->tinhtrang == "da tra")
            {
                cout << "Nhap ngay moi: ";
                cin >> ngay;
                this->ngaytra = ngay;
            }
            else
                cout << "Sach chua duoc tra!\n";
            break;
        case 'G':
            break;
        default:
            cout << "Ban da lua chon\n";
            break;
        }
    } while (data != 'G');
}

string TTMuonTra::getMa()
{
    return this->mamuontra;
}

void TTMuonTra::UpdateMS(string macu, string mamoi)
{
    if (this->masach == macu)
        this->masach = mamoi;
}

void TTMuonTra::UpdateNVM(string macu, string mamoi)
{
    if (this->nhanvienmuon == macu)
        this->nhanvienmuon = mamoi;
}

void TTMuonTra::UpdateNVT(string macu, string mamoi)
{
    if (this->nhanvientra == macu)
        this->nhanvientra = mamoi;
}

void TTMuonTra::UpdateTTV(string macu, string mamoi)
{
    if (this->mathe == macu)
        this->mathe = mamoi;
}

void TTMuonTra::docfile(string temp)
{
    string ngay1,thang1,nam1; 
    this->mamuontra = tach(temp,","); 
    this->mathe = tach(temp,","); 
    this->masach = tach(temp,","); 
    this->nhanvienmuon = tach(temp,","); 
    ngay1 = tach(temp,"/"); 
    thang1 = tach(temp,"/"); 
    nam1 = tach(temp,","); 
    this->ngaymuon = Date(ngay1,thang1,nam1);
    this->tinhtrang = tach(temp,","); 
    this->nhanvientra = tach(temp,","); 
    ngay1 = tach(temp,"/"); 
    thang1 = tach(temp,"/"); 
    nam1 = temp;
    this->ngaytra = Date(ngay1,thang1,nam1);
}

void TTMuonTra::getcot()
{
    cout << "=================================================================================================================================\n";
    cout <<"|" <<setw(12) << "MA_MT" <<" |"<< setw(12) << "MA_THE" <<" |"<< setw(12) << "MA_SACH" <<" |"<< setw(12) << "NV_MUON" <<" |"<< setw(20) << "NGAY_MUON" <<" |"<< setw(12) << "TINH_TRANG" <<" |"<< setw(12) << "NV_TRA" <<" |"<< setw(20) << "NGAY_TRA" <<" |"<< endl;
    cout << "=================================================================================================================================\n";
}

void TTMuonTra::getdong()
{
    cout << "=================================================================================================================================\n";    
}

string TTMuonTra::ghifile()
{
    string temp = this->mamuontra + "," + this->mathe + "," + this->masach + "," + this->nhanvienmuon + "," + this->ngaymuon.ghifile() + "," + this->tinhtrang + "," + this->nhanvientra + "," + this->ngaytra.ghifile();
    return temp;
}