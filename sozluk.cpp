#include "kayit.h"
#include "sozluk.h"
#include <vector>
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
ofstream& operator<<(ofstream& out , const Sozluk& s){

    for(int i = 0; i < s.toplamKayitSayisi;++i){
        out << s.kayitlar[i].privatekelime() << ":" << std::endl;
        for(int j = 0; j < s.kayitlar[i].findaciklama();++j){
            out << s.kayitlar[i].getaciklama()[j] << std::endl;
            }
        out << "-----------------------------------"<<endl;

    }

        return out;
}
ifstream& operator>>(ifstream& in , Sozluk& s){
    string kelimeMiktari , aciklamaMiktari , bos;
    vector<string> aciklamalar;
    vector<Kayit> kayitlar;
    while(!in.eof()){
        getline(in,kelimeMiktari,':');
        getline(in , bos , '\n');
        getline(in , aciklamaMiktari , '\n');
        while(aciklamaMiktari !="-----------------------------------"){

            aciklamalar.push_back(aciklamaMiktari);
            getline(in , aciklamaMiktari , '\n');

        }
        Kayit k1(kelimeMiktari , aciklamalar);
        kayitlar.push_back(k1);
        aciklamalar.clear();
    }
    Sozluk sozluk1(kayitlar);
    s = sozluk1;
    return in;


}







ostream & operator<<(ostream & o, const Sozluk & s)
{
    unsigned int x=0;
    o << s.toplamKayitSayisi << endl;
    for(int i=0;i<s.toplamKayitSayisi;++i){
        x += s.kayitlar[i].findaciklama();
    }
    o<< x <<endl;
}
Sozluk::Sozluk(){
    kayitlar= nullptr;
    toplamKayitSayisi=0;

}
Sozluk::Sozluk(const Kayit & kayit)
{
	kayitlar = new Kayit [1];
	if (kayitlar == nullptr)
		exit(-1);
	kayitlar[0] = kayit;
	toplamKayitSayisi = 1;
}
Sozluk::Sozluk(const vector<Kayit> & kayitlar){
    toplamKayitSayisi = 0;
    this ->kayitlar = nullptr;
    this ->kayitlar = new Kayit[kayitlar.size()];
    toplamKayitSayisi=kayitlar.size();
    for(int i=0;i<toplamKayitSayisi;++i){
        this->kayitlar[i]=kayitlar[i];
    }



}
Sozluk::~Sozluk(){
    toplamKayitSayisi=0;
    kayitlar=nullptr;

}
Sozluk::Sozluk(const Sozluk& other){
    if (kayitlar != nullptr)
		delete[] kayitlar;
    toplamKayitSayisi = other.toplamKayitSayisi;
    for(int i=0;i<toplamKayitSayisi;++i){
        kayitlar[i]=other.kayitlar[i];
    }


}
const Sozluk & Sozluk::operator=(const Sozluk & other){
    if (this == &other)
		return *this;
	if (kayitlar != nullptr)
		delete[] kayitlar;

    toplamKayitSayisi=other.toplamKayitSayisi;
    for(int i=0;i<toplamKayitSayisi;++i){
        kayitlar[i]=other.kayitlar[i];
    }
return *this;
}
Kayit& Sozluk::operator[](const string & kelime){

    for(int i=0;i<toplamKayitSayisi;++i){
        if(kayitlar[i].privatekelime() == kelime){
            return kayitlar[i];
        }
    }


}
bool Sozluk::operator>(const Sozluk & digerSozluk){
    int x=0;
    int y=0;
    for(int i=0;i<toplamKayitSayisi;++i){
        x +=kayitlar[i].findaciklama();
        y +=digerSozluk.kayitlar[i].findaciklama();


    }
    if(x>y)
    return true;

    return false;
}
bool Sozluk::operator<(const Sozluk & digerSozluk){
    int x=0;
    int y=0;
    for(int i=0;i<toplamKayitSayisi;++i){
        x +=kayitlar[i].findaciklama();
        y +=digerSozluk.kayitlar[i].findaciklama();


    }
    if(x>y)
    return false;

    return true;
}
bool Sozluk::operator<=(const Sozluk & digerSozluk){
     int x=0;
    int y=0;
    for(int i=0;i<toplamKayitSayisi;++i){
        x +=kayitlar[i].findaciklama();
        y +=digerSozluk.kayitlar[i].findaciklama();


    }
    if(x>y)
    return false;
    if(x=y)
    return true;
    if(x<y)
    return true;
}
bool Sozluk::operator>=(const Sozluk & digerSozluk){
    int x=0;
    int y=0;
    for(int i=0;i<toplamKayitSayisi;++i){
        x +=kayitlar[i].findaciklama();
        y +=digerSozluk.kayitlar[i].findaciklama();


    }
    if(x>y)
    return true;
    if(x=y)
    return true;
    if(x<y)
    return false;
}
bool Sozluk::operator==(const Sozluk & digerSozluk){
    int x=0;
    int y=0;
    for(int i=0;i<toplamKayitSayisi;++i){
        x +=kayitlar[i].findaciklama();
        y +=digerSozluk.kayitlar[i].findaciklama();


    }
    if(x=y)
    return true;

    return false;
}
bool Sozluk::operator!=(const Sozluk & digerSozluk){
    int x=0;
    int y=0;
    for(int i=0;i<toplamKayitSayisi;++i){
        x +=kayitlar[i].findaciklama();
        y +=digerSozluk.kayitlar[i].findaciklama();


    }
    if(x=y)
    return false;

    return true;
}
Sozluk& Sozluk::operator+(const Sozluk & digerSozluk)
{
	vector<Kayit>temp;
	vector<Kayit>tempb;
	for (int i = 0; i < this->toplamKayitSayisi; i++) {
		temp.push_back(this->kayitlar[i]);
	}
	for (int i = 0; i < digerSozluk.toplamKayitSayisi; i++) {
		tempb.push_back(digerSozluk.kayitlar[i]);
	}
	for (int i = 0; i < this->toplamKayitSayisi; i++) {
		for (int j = 0; j < digerSozluk.toplamKayitSayisi; j++) {
			if (temp[i].privatekelime() == tempb[j].privatekelime()) {
				temp[i] + tempb[j];
			}
		}
	}
	toplamKayitSayisi = temp.size();
	this->kayitlar = new Kayit[toplamKayitSayisi];
	if (this->kayitlar == nullptr) exit(-1);
	for (unsigned i = 0; i < toplamKayitSayisi; i++) {
		this->kayitlar[i] = temp[i];
	}
	return *this;
}
Sozluk& Sozluk::operator+=(const Sozluk & digerSozluk){

    *this = *this + digerSozluk;
	return *this;



}








