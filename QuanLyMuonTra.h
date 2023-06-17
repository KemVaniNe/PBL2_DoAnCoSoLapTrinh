#include"TTMuonTra.h"

class QuanLyMuonTra
{
protected:
    TTMuonTra *p;
    int n;

public:
    QuanLyMuonTra();
    ~QuanLyMuonTra();
    int N();
    void show();
    void insert(TTMuonTra, int);
    void clear();
    void Delete(string);
    void Search(string);
    void docfile(string);
    void ghifile(string ma);
    QuanLyMuonTra& operator=(const QuanLyMuonTra&);
    TTMuonTra operator[](int);
    void Update(string);
    void UpdateMS(string, string);
    void UpdateNVM(string, string);
    void UpdateNVT(string, string);
    void UpdateTTV(string, string);
};

QuanLyMuonTra::QuanLyMuonTra()
{
    this->n = 0;
    this->p = nullptr;
}

QuanLyMuonTra::~QuanLyMuonTra()
{
    delete[] this->p;
}

int QuanLyMuonTra::N()
{
    return this->n;
}

void QuanLyMuonTra::show()
{
    ::show(this->p,this->n);
}

void QuanLyMuonTra::insert(TTMuonTra value,int index)
{
    ::insert(this->p,this->n,value,index);
}

void QuanLyMuonTra::clear()
{
    ::clear(this->p,this->n);
}

void QuanLyMuonTra::Delete(string ma)
{
    ::Delete(this->p,this->n,ma);
}

void QuanLyMuonTra::Search(string ma)
{
    ::Search(this->p,this->n,ma);
}

void QuanLyMuonTra::docfile(string ma)
{
    ::docfile(this->p,this->n,ma);    
}

void QuanLyMuonTra::ghifile(string ma)
{
    ::ghifile(this->p,this->n,ma);
}

QuanLyMuonTra& QuanLyMuonTra::operator=(const QuanLyMuonTra &t)
{
    this->n = t.n;
    for(int i=0;i<this->n;i++)
        *(this->p+i)=*(t.p+i);
    return *this;
}

TTMuonTra QuanLyMuonTra::operator[](int index)
{
    if (index >= 0 && index < this->n)
        return this->p[index];
    else
        return TTMuonTra();
}

void QuanLyMuonTra::Update(string macu)
{
    int index = ::indexof(this->p, this->n, macu);
    if (index >= 0)
        (this->p + index)->Update();
    else
        cout << "Khong ton tai!\n";
}

void QuanLyMuonTra::UpdateMS(string macu, string mamoi)
{
    for (int i = 0; i < this->n; i++)
    {
        this->p[i].UpdateMS(macu, mamoi);
    }
}

void QuanLyMuonTra::UpdateNVM(string macu, string mamoi)
{
    for (int i = 0; i < this->n; i++)
    {
        this->p[i].UpdateNVM(macu, mamoi);
    }
}

void QuanLyMuonTra::UpdateNVT(string macu, string mamoi)
{
    for (int i = 0; i < this->n; i++)
    {
        this->p[i].UpdateNVT(macu, mamoi);
    }
}

void QuanLyMuonTra::UpdateTTV(string macu, string mamoi)
{
    for (int i = 0; i < this->n; i++)
    {
        this->p[i].UpdateTTV(macu, mamoi);
    }
}