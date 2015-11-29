#ifndef AKUNGRUPHEADER_H_INCLUDED
#define AKUNGRUPHEADER_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>


#define nil NULL
#define first(l) ((l).first)
#define last(l) ((l).last)
#define admin(p) p->admin
#define info(p) p->info
#define anggota(p) p->anggota
#define next(p) p->next
#define prev(p) p->prev

/*Di sini yang menjadi parent adalah grup dan yang menjadi child adalah akun*/

typedef struct grup *addressg; // addressg = address grup
typedef struct shadow *adr;
typedef struct akun *addressa; // addressa = address akun

struct infotypeg
{
    int id;
    std::string nama,tanggal;
};

struct infotypea
{
    int id;
    std::string nama,tgllahir,user,pass;
};

struct grup
{
    infotypeg info;
    addressg next,prev;
    adr anggota,admin;
};

struct akun
{
    infotypea info;
    addressa next;
};

struct shadow
{
    addressa info;
    adr next;
};
struct listgrup
{
    addressg first,last;
};

struct listakun
{
    addressa first;
};

addressg alokasigrup (infotypeg );
addressa alokasiakun (infotypea );
adr alokasishadow (addressa );

void createlistgrup (listgrup &);
void createlistakun (listakun &);

void insertfirstgrup (listgrup &, addressg );
void insertaftergrup (listgrup &, addressg ,addressg );
void insertlastgrup (listgrup &, addressg );
void deletefirstgrup (listgrup &, addressg &);
void deleteaftergrup (listgrup &, addressg &,addressg );
void deletelastgrup (listgrup &, addressg &);

void insertfirstakun (listakun &, addressa );
void insertafterakun (listakun &, addressa ,addressa );
void insertlastakun (listakun &, addressa );
void deletefirstakun (listakun &, addressa &);
void deleteafterakun (listakun &, addressa &,addressa );
void deletelastakun (listakun &, addressa &);

void insertfirstshadow (addressg &, adr );
void insertaftershadow (addressg &, adr ,adr );
void insertlastshadow (addressg &, adr );
void deletefirstshadow (addressg &, adr &);
void deleteaftershadow (addressg &, adr &,adr );
void deletelastshadow (addressg &, adr &);

void deletemember(addressg &);
void deletegrup (listgrup &, addressg );
void deleteakuninmember (listgrup &, addressa );
void deleteakun (listgrup &,listakun &, addressa );
void deleteanggota (addressg &, addressa );

addressg findgrupbyid (listgrup , int );
addressa findakunbyid (listakun , int );
adr findsh (addressg , int );

void printinfo (listgrup );
void printinfoseb (addressg );
void printakun (listakun );

void masukkan (listgrup &, addressg );
void masukkanakun (listakun &, addressa );
void masukkansh (addressg &, adr );

#endif // AKUNGRUPHEADER_H_INCLUDED
