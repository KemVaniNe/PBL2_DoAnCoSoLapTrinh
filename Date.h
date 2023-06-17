#pragma once
#include<iostream>
#include<iomanip>
#include"DungChung.cpp"
using namespace std;
class Date
{
protected:
    string Ngay;
    string Thang;
    string Nam;

public:
    Date(string = "00",string = "00",string = "0000");
    ~Date();
    friend ostream &operator<<(ostream &, const Date &);
    friend istream &operator>>(istream &, Date &);
    string ghifile();
};

Date::Date(string a,string b,string c) : Ngay(a), Thang(b), Nam(c)
{
}

Date::~Date()
{
}

ostream &operator<<(ostream &o, const Date &t)
{
    o << setw(2) << t.Ngay << "/" << setw(2) << t.Thang << "/" << setw(4) << t.Nam;
    return o;
}

istream &operator>>(istream &in, Date &t)
{
    cout << "Nhap Ngay = ";
    in >> t.Ngay;
    cout << "Nhap Thang = ";
    in >> t.Thang;
    cout << "Nhap Nam = ";
    in >> t.Nam;
    return in;
}

string Date::ghifile()
{
    string temp = this->Ngay +  "/" + this->Thang + "/" + this->Nam;
    return temp;
}