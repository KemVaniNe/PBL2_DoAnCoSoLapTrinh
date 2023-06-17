#pragma once
#include"DungChung.cpp"

class TTSach
{
    protected:
        string masach;
        string tensach;
        string tacgia;
        string theloai;
        string nxb;
        string namxb;
    public:
        TTSach(string = "", string = "", string = "", string = "", string = "", string = "");
        ~TTSach();
        friend ostream &operator<<(ostream &, const TTSach &);
        friend istream &operator>>(istream &, TTSach &);
        void Update();
        string getMa();
        void docfile(string);
        void getcot();
        void getdong();
        string ghifile();
};

TTSach::TTSach(string x, string y, string z, string m, string n, string k)
    : masach(x), tensach(y), tacgia(z), theloai(m), nxb(n), namxb(k)
{
}

TTSach::~TTSach()
{
}

ostream &operator<<(ostream &o, const TTSach &t)
{
    o << "|" << setw(12) << t.masach << " |"<< setw(30) << t.tensach << " |"<< setw(35) << t.tacgia << " |"<< setw(25) << t.theloai << " |"<< setw(20) << t.nxb << " |"<< setw(10) << t.namxb << " |"<< endl;
    return o;
}

istream &operator>>(istream &in, TTSach &t)
{
    cout << setw(4) << "1. Nhap ma sach: ";
    in >> t.masach;
    cout << setw(4) << "2. Nhap ten sach: ";
    fflush(stdin);
    getline(in, t.tensach);
    cout << setw(4) << "3. Nhap tac gia: ";
    fflush(stdin);
    getline(in, t.tacgia);
    cout << setw(4) << "4. Nhap the loai: ";
    fflush(stdin);
    getline(in, t.theloai);
    cout << setw(4) << "5. Nhap nha xuat ban: ";
    fflush(stdin);
    getline(in, t.nxb);
    cout << setw(4) << "6. Nhap nam xuat ban: ";
    in >> t.namxb;
    return in;
}

void TTSach::Update()
{
    char chon;
    string mamoi;
    do
    {
        cout << "BAN MUON THAY DOI GI:\nA. Ma sach\nB. Ten sach\nC. Tac gia\nD. The loai\nE. Nha xuat ban\nF. Nam xuat ban\nG. Tro ve\n";
        cout << setw(4) << " "<< "Lua chon thay doi sach cua ban la: ";
        cin >> chon;
        switch (chon)
        {
        case 'A':
            cout << "Nhap ma moi: ";
            cin >> mamoi;
            this->masach = mamoi;
            break;
        case 'B':
            cout << "Nhap ten sach:  ";
            fflush(stdin);
            getline(cin, mamoi);
            this->tensach = mamoi;
            break;
        case 'C':
            cout << "Nhap ten tac gia moi: ";
            fflush(stdin);
            getline(cin, mamoi);
            this->tacgia = mamoi;
            break;
        case 'D':
            cout << "Nhap the loai moi: ";
            fflush(stdin);
            getline(cin, mamoi);
            this->theloai = mamoi;
            break;
        case 'E':
            cout << "Nhap nha xuat ban moi: ";
            fflush(stdin);
            getline(cin, mamoi);
            this->nxb = mamoi;
            break;
        case 'F':
            cout << "Nhap nam xuat ban moi: ";
            cin >> mamoi;
            this->namxb = mamoi;
            break;
        case 'G':
            break;
        default:
            cout << "Lua chon cua ban khong hop le!\n";
            break;
        }
    } while (chon != 'G');
}

string TTSach::getMa()
{
    return this->masach;
}

void TTSach::docfile(string temp)
{
    this->masach = tach(temp,",");
    this->tensach = tach(temp,",");
    this->tacgia = tach(temp,",");
    this->theloai = tach(temp,",");
    this->nxb = tach(temp,",");
    this->namxb = temp;    
}

void TTSach::getcot()
{
    cout << "=================================================================================================================================================\n";
    cout <<"|"<< setw(12) << "MA_SACH" << " |"<< setw(30) << "TEN_SACH" << " |"<< setw(35) << "TAC_GIA" << " |"<< setw(25) << "THE_lOAI" << " |"<< setw(20) << "NXB" << " |"<< setw(10) << "NAM_XB"<< " |" << endl;
    cout << "=================================================================================================================================================\n";
}

void TTSach::getdong()
{
    cout << "=================================================================================================================================================\n";
}

string TTSach::ghifile()
{
    string temp = this->masach + "," + this->tensach + "," + this->tacgia + "," + this->theloai + "," + this->nxb + "," + this->namxb;  
    return temp;  
}