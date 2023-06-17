#include"TheThuVien.h"

class QuanLyTheThuVien
{
protected:
    TheThuVien *p;
    int n;

public:
    QuanLyTheThuVien();
    ~QuanLyTheThuVien();
    int N();
    void show();
    void insert(TheThuVien, int);
    void clear();
    void Delete(string);
    void Search(string);
    void docfile(string);
    void ghifile(string ma);
    QuanLyTheThuVien& operator=(const QuanLyTheThuVien&);
    TheThuVien operator[](int);
    void Update(string);
    int indexof(string);
};

QuanLyTheThuVien::QuanLyTheThuVien()
{
    this->n = 0;
    this->p = nullptr;
}

QuanLyTheThuVien::~QuanLyTheThuVien()
{
    delete[] this->p;
}

int QuanLyTheThuVien::N()
{
    return this->n;
}

void QuanLyTheThuVien::show()
{
    ::show(this->p,this->n);
}

void QuanLyTheThuVien::insert(TheThuVien value,int index)
{
    ::insert(this->p,this->n,value,index);
}

void QuanLyTheThuVien::clear()
{
    ::clear(this->p,this->n);
}

void QuanLyTheThuVien::Delete(string ma)
{
    ::Delete(this->p,this->n,ma);
}

void QuanLyTheThuVien::Search(string ma)
{
    ::Search(this->p,this->n,ma);
}

void QuanLyTheThuVien::docfile(string ma)
{
    ::docfile(this->p,this->n,ma);    
}

void QuanLyTheThuVien::ghifile(string ma)
{
    ::ghifile(this->p,this->n,ma);
}

QuanLyTheThuVien& QuanLyTheThuVien::operator=(const QuanLyTheThuVien &t)
{
    this->n = t.n;
    for(int i=0;i<this->n;i++)
        *(this->p+i)=*(t.p+i);
    return *this;
}

TheThuVien QuanLyTheThuVien::operator[](int index)
{
    if (index >= 0 && index < this->n)
        return this->p[index];
    else
        return TheThuVien();
}

void QuanLyTheThuVien::Update(string macu)
{
    int index = ::indexof(this->p, this->n, macu);
    if (index >= 0)
    {
        (this->p + index)->Update();
    }
    else
        cout << "Khong ton tai!\n";
}

int QuanLyTheThuVien::indexof(string ma)
{
    int index = ::indexof(this->p, this->n, ma);
    return index;
}