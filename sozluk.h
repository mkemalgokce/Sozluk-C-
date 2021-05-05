#pragma once
#include "kayit.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Sozluk
{
// Sozlukteki kayitli kelime sayisini ve toplam aciklama sayisini ekrana yazdirir.
friend ostream & operator<<(ostream & o, const Sozluk & s);
friend ofstream & operator<<(ofstream & out, const Sozluk & s);
friend ifstream & operator>>(ifstream & in, Sozluk & s);
public:
/*** CONSTRUCTORS ***/

// bos bir sozluk oluturur.
Sozluk();
// tek bir kayittan olusan bir sozluk olusturur.
Sozluk(const Kayit& kayit);
// Bir kayit vektoru alir ve sozluk olusturur. Sozlukte her kayit sadece bir kez olabilir.
// Eger vektor icinde ayni kayit sozcugu varsa bunların aciklamalarını birlestirir.
Sozluk(const vector<Kayit> & kayitlar);
~Sozluk();
Sozluk(const Sozluk& other);
const Sozluk & operator=(const Sozluk & other);
//!!! Uc buyukleri unutmayin !!!
//Verilen bir kelime degerine sahip Kaydi donderen subscript operatorunu asiriyukleyiniz
Kayit& operator[](const string & kelime);

bool operator>(const Sozluk & digerSozluk);
bool operator<(const Sozluk & digerSozluk);
bool operator<=(const Sozluk & digerSozluk);
bool operator>=(const Sozluk & digerSozluk);
bool operator==(const Sozluk & digerSozluk);
bool operator!=(const Sozluk & digerSozluk);
// Iki sozlugu buyukluk acisindan karislatiran operatorleri asiri yukleyin
// Karsilasirmalar toplam sozlukteki toplam aciklama sayisina gore yapilir
// ==, !=, >, <, <=, >= operatorlerinin tamamını asiri yukleyiniz

// Iki sozlugu birlestiren iki operandli + operatorunu asiri yukleyiniz. Birlesimsonunda ayni kayittan iki tane olmaz, aciklamalar bir kelime altina toplanir
// bir kayit altinda birebir ayni aciklama iki veya daha cok kez bulunamaz
Sozluk & operator+(const Sozluk & digerSozluk);
// Iki sozlugu birlestiren += operatorunu asiri yukleyiniz. Birlesim sonunda ayni kayittaniki tane olmaz, aciklamalar bir kelime altina toplanir
// bir kayit altinda birebir ayni aciklama iki veya daha cok kez bulunamaz
Sozluk & operator+=(const Sozluk & digerSozluk);
// Sozluk icindeki kelimede yer alan aciklamalari siler. Eger hic aciklamakalmamissa tum kelimeyi siler
Sozluk & operator-=(const Kayit & kayit);
// Sozluk icindeki kelimede yer alan TUM aciklamalari siler.
Sozluk & operator-=(const string & kelime);
friend ifstream & operator>>(ifstream & in, Sozluk & s);
friend ofstream & operator<<(ofstream & out, const Sozluk & s);
private:
Kayit * kayitlar;
unsigned int toplamKayitSayisi;
};
