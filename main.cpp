/*Mustafa Kemal GÖKÇE
*18120205034
*/
#include<iostream>
#include<vector>
#include<string>
#include"sozluk.h"
#include"kayit.h"
#include<fstream>
using namespace std;

int main(){
    vector <Kayit> as;
    Sozluk q; //default constructor deneme
    Kayit k1("odev","zamanında yapılması gereken şey");
    Kayit k2("at","hayvan");
    Kayit k3("deneme","deneme aciklama");
    Sozluk b(k1); // constructor deneme
    as.push_back(k1); // vectorlu constructor atama
    as.push_back(k2);
    as.push_back(k3);
    Sozluk a(as);
    ofstream out;
    out.open("a.txt");
    out << a;

    cout<<a+b; // vectorlu constructor deneme
}
