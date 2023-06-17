#pragma once
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

int getn(string ma)
{
    int count = 0;
    string temp;
    ifstream filein;
    filein.open(ma,ios::in);
    if(filein.fail()==true)
        cout << "Khong the mo file" << endl;
    else
    {
        while(!filein.eof())
        {
            getline(filein,temp,'\n');
            count ++;
        }
    }
    filein.close();
    return count;
}

string tach(string &chuoicu,string kytu)
{
    size_t index = 0;
    string chuoimoi ;
    if(!chuoicu.empty())
    {
        index = chuoicu.find(kytu);
        if(index !=string::npos)
        {
            chuoimoi = chuoicu.substr(0,index);
            chuoicu.erase(0,index+kytu.length());
        }
        else
        {
            chuoimoi = " ";
        }
    }
    return chuoimoi;
}

template <class T>
void show(T *p, int n)
{
    p[0].getcot();
    for(int i=0;i<n;i++)
        cout << *(p+i);
    p[0].getdong();
}

template <class T>
void insert(T *&p, int &n, T value, int index)
{
    if (index >= 0 && index <= n)
    {
        T *temp = new T[n];
        for (int i = 0; i < n; i++)
        {
            *(temp + i) = *(p + i);
        }
        delete[] p;
        p = new T[n + 1];
        for (int i = 0; i <= n; i++)
        {
            if (i < index)
                *(p + i) = *(temp + i);
            if (i == index)
                *(p + i) = value;
            if (i > index)
                *(p + i) = *(temp + i - 1);
        }
        delete[] temp;
        n++;
    }
    else
        cout << "Khong ton tai vi tri nay!\n";
}

template <class T>
void clear(T *&p, int &n)
{
    delete[] p;
    p = nullptr;
    n = 0;
}

template <class T>
int indexof(T *p, int n, string ma)
{
    for (int i = 0; i < n; i++)
    {
        if ((p + i)->getMa() == ma)
        {
            return i;
        }
    }
    return -1;
}

template <class T>
void Delete(T *&p, int &n, string ma)
{
    int data = indexof(p, n, ma);
    if (data >= 0)
    {
        if (n == 1)
        {
            delete[] p;
            p = nullptr;
        }
        else
        {
            T *temp = new T[n];
            for (int i = 0; i < n; i++)
            {
                *(temp + i) = *(p + i);
            }
            delete[] p;
            p = new T[n - 1];
            for (int i = 0; i < n - 1; i++)
            {
                if (i < data)
                    *(p + i) = *(temp + i);
                else
                    *(p + i) = *(temp + i + 1);
            }
            delete[] temp;
        }
        n--;
    }
}

template <class T>
void Search(T *t, int n, string ma)
{
    int data = indexof(t, n, ma);
    if (data >= 0)
        cout << *(t + data);
    else
        cout << "Khong ton tai!" << endl;
}

template <class T>
void docfile(T* &t,int &n,string ma)
{
    T *muon = new T[n];
    for(int i=0;i<n;i++)
    {
        *(muon+i) = t[i];
    }
    delete[] t;
    int them = ::getn(ma);
    string temp;
    ifstream filein;
    filein.open(ma);
    t = new T[n+them];
    for(int i=0;i<n;i++)
    {
        t[i] = *(muon+i);
    }
    delete[] muon;
    if(filein.fail()==true)
        cout << "Khong the mo file" << endl;
    else
    {
        for(int i=n;i<them+n;i++)
        {
            getline(filein,temp);
            T x;
            x.docfile(temp);
            t[i] = x;
        }
    } 
    filein.close();   
    n = n+them;
}

template<class T>
void ghifile(T *p,int n,string ma)
{
    ofstream fileout;
    fileout.open(ma);
    for(int i=0;i<n;i++)
    {
        fileout << p[i].ghifile() << endl;
    }
    fileout.close();
}
