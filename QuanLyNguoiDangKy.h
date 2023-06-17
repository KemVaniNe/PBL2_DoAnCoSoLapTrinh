#include"TTNguoiDangKy.h"

class QuanLyNguoiDangKy
{
protected:
    TTNguoiDangKy *p;
    int n;

public:
    QuanLyNguoiDangKy();
    ~QuanLyNguoiDangKy();
    int N();
    void show();
    void insert(TTNguoiDangKy, int);
    void clear();
    void Delete(string);
    void Search(string);
    void docfile(string);
    void ghifile(string);
    QuanLyNguoiDangKy& operator=(const QuanLyNguoiDangKy&);
    TTNguoiDangKy operator[](int);
    void Update(string);
    void UpdateTTV(string, string);
};

QuanLyNguoiDangKy::QuanLyNguoiDangKy()
{
    this->n = 0;
    this->p = nullptr;
}

QuanLyNguoiDangKy::~QuanLyNguoiDangKy()
{
    delete[] this->p;
}

int QuanLyNguoiDangKy::N()
{
    return this->n;
}

void QuanLyNguoiDangKy::show()
{
    ::show(this->p,this->n);
}

void QuanLyNguoiDangKy::insert(TTNguoiDangKy value,int index)
{
    ::insert(this->p,this->n,value,index);
}

void QuanLyNguoiDangKy::clear()
{
    ::clear(this->p,this->n);
}

void QuanLyNguoiDangKy::Delete(string ma)
{
    ::Delete(this->p,this->n,ma);
}

void QuanLyNguoiDangKy::Search(string ma)
{
    ::Search(this->p,this->n,ma);
}

void QuanLyNguoiDangKy::docfile(string ma)
{
    ::docfile(this->p,this->n,ma);    
}

void QuanLyNguoiDangKy::ghifile(string ma)
{
    ::ghifile(this->p,this->n,ma);
}

QuanLyNguoiDangKy& QuanLyNguoiDangKy::operator=(const QuanLyNguoiDangKy &t)
{
    this->n = t.n;
    for(int i=0;i<this->n;i++)
        *(this->p+i)=*(t.p+i);
    return *this;
}

TTNguoiDangKy QuanLyNguoiDangKy::operator[](int index)
{
    if (index >= 0 && index < this->n)
        return this->p[index];
    else
        return TTNguoiDangKy();
}

void QuanLyNguoiDangKy::Update(string macu)
{
    int index = ::indexof(this->p, this->n, macu);
    if (index >= 0)
        (this->p + index)->Update();
    else
        cout << "Khong ton tai!\n";
}

void QuanLyNguoiDangKy::UpdateTTV(string macu, string mamoi)
{
    for (int i = 0; i < this->n; i++)
        this->p[i].UpdateTTV(macu, mamoi);
}