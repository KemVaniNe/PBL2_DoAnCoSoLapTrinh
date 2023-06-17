#include"TTSach.h"

class QuanLySach
{
protected:
    TTSach *p;
    int n;

public:
    QuanLySach();
    ~QuanLySach();
    int N();
    void show();
    void insert(TTSach, int);
    void clear();
    void Delete(string);
    void Search(string);
    void docfile(string ma);
    void ghifile(string);
    QuanLySach& operator=(const QuanLySach&);
    TTSach operator[](int);
    void Update(string);
    int indexof(string);
};

QuanLySach::QuanLySach()
{
    this->n = 0;
    this->p = nullptr;
}

QuanLySach::~QuanLySach()
{
    delete[] this->p;
}

int QuanLySach::N()
{
    return this->n;
}

void QuanLySach::show()
{
    ::show(this->p,this->n);
}

void QuanLySach::insert(TTSach value,int index)
{
    ::insert(this->p,this->n,value,index);
}

void QuanLySach::clear()
{
    ::clear(this->p,this->n);
}

void QuanLySach::Delete(string ma)
{
    ::Delete(this->p,this->n,ma);
}

void QuanLySach::Search(string ma)
{
    ::Search(this->p,this->n,ma);
}

void QuanLySach::docfile(string ma)
{
    ::docfile(this->p,this->n,ma);    
}

void QuanLySach::ghifile(string ma)
{
    ::ghifile(this->p,this->n,ma);
}

QuanLySach& QuanLySach::operator=(const QuanLySach &t)
{
    this->n = t.n;
    for(int i=0;i<this->n;i++)
        *(this->p+i)=*(t.p+i);
    return *this;
}

TTSach QuanLySach::operator[](int index)
{
    if (index >= 0 && index < this->n)
        return this->p[index];
    else
        return TTSach();
}

void QuanLySach::Update(string macu)
{
    int index = ::indexof(this->p, this->n, macu);
    if (index >= 0)
        (this->p + index)->Update();
    else
        cout << "Khong ton tai!\n";
}

int QuanLySach::indexof(string ma)
{
    int index = ::indexof(this->p, this->n, ma);
    return index;
}
