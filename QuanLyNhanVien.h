#include"TTNhanVien.h"

class QuanLyNhanVien
{
protected:
    TTNhanVien *p;
    int n;

public:
    QuanLyNhanVien();
    ~QuanLyNhanVien();
    int N();
    void show();
    void insert(TTNhanVien, int);
    void clear();
    void Delete(string);
    void Search(string);
    void docfile(string);
    void ghifile(string);
    QuanLyNhanVien& operator=(const QuanLyNhanVien&);
    TTNhanVien operator[](int);
    void Update(string);
    int indexof(string);
};

QuanLyNhanVien::QuanLyNhanVien()
{
    this->n = 0;
    this->p = nullptr;
}

QuanLyNhanVien::~QuanLyNhanVien()
{
    delete[] this->p;
}

int QuanLyNhanVien::N()
{
    return this->n;
}

void QuanLyNhanVien::show()
{
    ::show(this->p,this->n);
}

void QuanLyNhanVien::insert(TTNhanVien value,int index)
{
    ::insert(this->p,this->n,value,index);
}

void QuanLyNhanVien::clear()
{
    ::clear(this->p,this->n);
}

void QuanLyNhanVien::Delete(string ma)
{
    ::Delete(this->p,this->n,ma);
}

void QuanLyNhanVien::Search(string ma)
{
    ::Search(this->p,this->n,ma);
}

void QuanLyNhanVien::docfile(string ma)
{
    ::docfile(this->p,this->n,ma);    
}

void QuanLyNhanVien::ghifile(string ma)
{
    ::ghifile(this->p,this->n,ma);
}

QuanLyNhanVien& QuanLyNhanVien::operator=(const QuanLyNhanVien &t)
{
    this->n = t.n;
    for(int i=0;i<this->n;i++)
        *(this->p+i)=*(t.p+i);
    return *this;
}

TTNhanVien QuanLyNhanVien::operator[](int index)
{
    if (index >= 0 && index < this->n)
        return this->p[index];
    else
        return TTNhanVien();
}

void QuanLyNhanVien::Update(string macu)
{
    int index = ::indexof(this->p, this->n, macu);
    if (index >= 0)
        (this->p + index)->Update();
    else
        cout << "Khong ton tai!\n";
}

int QuanLyNhanVien::indexof(string ma)
{
    int index = ::indexof(this->p, this->n, ma);
    return index;
}