#include "AkunGrupHeader.h"

using namespace std;

//dibawah ini adalah script untuk menggunakan fungsi gotoxy di c++
void gotoxy1( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle( STD_OUTPUT_HANDLE ),
        coord
    );
}

void createlistakun (listakun &a)
{
    first(a)=nil;
}

adr alokasishadow (addressa a)
{
    adr p = new shadow;
    info(p) = a;
    next(p) = nil;
    return p;
}

addressa alokasianggota (infotypea x)
{
    addressa p = new akun;
    next(p)=nil;
    return p;
}

addressg alokasigrup (infotypeg x)
{
    addressg p = new grup;
    info(p) = x;
    next(p) = nil;
    prev(p) = nil;
    admin(p) = nil;
    anggota(p) = nil;
    return p;
}

addressa alokasiakun (infotypea x)
{
    addressa p = new akun;
    info(p) = x;
    next(p) = nil;
    return p;
}

void createlistgrup (listgrup &l)
{
    first(l) = nil;
    last(l) = nil;
}

void insertfirstgrup (listgrup &l, addressg p)
{
    if (first(l)!=nil)
    {
        next(p) = first(l);
        prev(first(l)) = p;
    }
    else
    {
        last(l) = p;
    }
    first(l) = p;
}

void insertaftergrup (listgrup &l, addressg p,addressg prec)
{
    if (prec != nil)
    {
        if (prec==last(l))
        {
            insertlastgrup(l,p);
        }
        else
        {
            next(p) = next(prec);
            prev(p) = prec;
            next(prec) = p;
            prev(next(p)) = p;
        }
    }
}

void insertlastgrup (listgrup &l, addressg p)
{
    if (last(l)!= nil)
    {
        next(last(l)) = p;
        prev(p) = last(l);
    }
    else
    {
        first(l) = p;
    }
    last(l) = p;
}

void deletemember(addressg &g)
{
    adr r;
    while (anggota(g)!=nil)
    {
        deletefirstshadow(g,r);
        delete r;
    }
}

void deletegrup (listgrup &l, addressg g)
{
    if (g==first(l))
    {
        deletefirstgrup(l,g);
    }
    else if (g==last(l))
    {
        deletelastgrup(l,g);
    }
    else
    {
        addressg prec = first(l);
        while (next(prec)!= g)
        {
            prec = next(prec);
        }
        deleteaftergrup(l,g,prec);
    }
}

void deleteakun (listgrup &l,listakun &a, addressa aa)
{
    if (aa == first(a))
    {
        deleteakuninmember(l,aa);
        deletefirstakun(a,aa);
    }
    else if (next(aa)==nil)
    {
        deleteakuninmember(l,aa);
        deletelastakun(a,aa);
    }
    else
    {
        addressa prec = first(a);
        while (next(prec)!=aa)
        {
            prec=next(prec);
        }
        deleteakuninmember(l,aa);
        deleteafterakun(a,aa,prec);
    }
}

void deleteakuninmember (listgrup &l, addressa a)
{
    addressg bantu = first(l);
    while (bantu != nil)
    {
        adr cek = anggota(bantu);
        if (cek != nil)
        {
            while (cek!=nil)
            {
                if (info(cek)==a && cek == anggota(bantu))
                {
                    if (admin(bantu)==cek)
                    {
                        admin(bantu)=nil;
                    }
                    deletefirstshadow(bantu,cek);
                }
                else if (info(cek)==a && next(cek) == nil)
                {
                    if (admin(bantu)==cek)
                    {
                        admin(bantu)=nil;
                    }
                    deletelastshadow(bantu,cek);
                }
                else
                {
                    adr prec = cek;
                    while (info(next(prec))!=a)
                    {
                        prec=next(prec);
                    }
                    if (admin(bantu)==cek)
                    {
                        admin(bantu)=nil;
                    }
                    deleteaftershadow(bantu,cek,prec);
                }
                cek = next(cek);
            }
        }
        bantu = next(bantu);
    }
}

void deleteanggota (addressg &g, addressa a)
{
    adr cek = anggota(g);
    if (cek != nil)
    {
        while (cek!=nil)
        {
            if (info(cek)==a && cek == anggota(g))
            {
                deletefirstshadow(g,cek);
            }
            else if (info(cek)==a && next(cek) == nil)
            {
                deletelastshadow(g,cek);
            }
            else
            {
                adr prec = cek;
                while (info(next(prec))!=a)
                {
                    prec=next(prec);
                }
                deleteaftershadow(g,cek,prec);
            }
            cek = next(cek);
        }
    }
}


void deletefirstgrup (listgrup &l, addressg &p)
{
    if (first(l)!=nil)
    {
        if (first(l)==last(l))
        {
            p=first(l);
            if (anggota(p)!=nil)
            {
                deletemember(p);
            }
            first(l)=nil;
            last(l)=nil;
        }
        else
        {
            p=first(l);
            if (anggota(p)!=nil)
            {
                deletemember(p);
            }
            first(l) = next(p);
            prev(first(l))=nil;
            next(p) = nil;
        }
    }
    else
    {
        p = nil;
    }
}

void deleteaftergrup (listgrup &l, addressg &p,addressg prec)
{
    if (prec!= nil)
    {
        if (next(prec)==last(l))
        {
            deletelastgrup(l,p);
        }
        else
        {
            p = next(prec);
            if (anggota(p)!=nil)
            {
                deletemember(p);
            }
            next(prec) = next(p);
            prev(next(p)) = prec;
            next(p) = nil;
            prev(p)=nil;
        }
    }
    else
    {
        p=nil;
    }
}

void deletelastgrup (listgrup &l, addressg &p)
{
    if (last(l)!=nil)
    {
        if (first(l)==last(l))
        {
            p=first(l);
            if (anggota(p)!=nil)
            {
                deletemember(p);
            }
            first(l)=nil;
            last(l)=nil;
        }
        else
        {
            p=last(l);
            if (anggota(p)!=nil)
            {
                deletemember(p);
            }
            last(l) = prev(p);
            prev(p)=nil;
            next(last(l)) = nil;
        }
    }
    else
    {
        p=nil;
    }
}


void insertfirstakun (listakun &g, addressa a)
{
    if (first(g)!=nil)
    {
        next(a) = first(g);
    }
    first(g) = a;
}

void insertafterakun (listakun &g, addressa p,addressa prec)
{
    if (prec!=nil)
    {
        if (next(prec)==nil)
        {
            insertlastakun(g,p);
        }
        else
        {
            next(p) = next(prec);
            next(prec) = p;
        }
    }
}

void insertlastakun (listakun &g, addressa a)
{
    if (first(g)!=nil)
    {
        addressa bantu = first(g);
        while (next(bantu)!=nil)
        {
            bantu = next(bantu);
        }
        next(bantu) = a;
    }
    else
    {
        first(g) = a;
    }
}

void deletefirstakun (listakun &g, addressa &p)
{
    if (first(g)!=nil)
    {
        if (next(first(g))!=nil)
        {
            p = first(g);
            first(g) = next(p);
            next(p) = nil;
        }
        else
        {
            p = first(g);
            first(g) = nil;
        }
    }
    else
    {
        p = nil;
    }
}

void deleteafterakun (listakun &g, addressa &p,addressa prec)
{
    if (prec != nil)
    {
        if (next(prec)!= nil)
        {
            p = next(prec);
            if (next(p)!=nil)
            {
                next(prec) = next(p);
                next(p) = nil;
            }
            else
            {
                next(prec) = nil;
            }
        }
        else
        {
            p = nil;
        }
    }
    else
    {
        p=nil;
    }
}

void deletelastakun (listakun &g, addressa &p)
{
    addressa q = first(g);
    if (q!=nil)
    {
        if (next(q)==nil)
        {
            p = q;
            first(g)=nil;
        }
        else
        {
            while (next(next(q))!=nil)
            {
                q = next(q);
            }
            p = next(q);
            next(q) = nil;
        }
    }
    else
    {
        p = nil;
    }
}

void insertfirstshadow (addressg &g, adr r)
{
    if (anggota(g)!=nil)
    {
        next(r) = anggota(g);
    }
    anggota(g) = r;
}

void insertaftershadow (addressg &g, adr r,adr prec)
{
    if (prec!=nil)
    {
        if (next(prec)==nil)
        {
            insertlastshadow(g,r);
        }
        else
        {
            next(r) = next(prec);
            next(prec) = r;
        }
    }
}

void insertlastshadow (addressg &g, adr r)
{
    if (anggota(g)!=nil)
    {
        adr bantu = anggota(g);
        while (next(bantu)!=nil)
        {
            bantu = next(bantu);
        }
        next(bantu) = r;
    }
    else
    {
        anggota(g) = r;
    }
}

void deletefirstshadow (addressg &g, adr &r)
{
    if (anggota(g)!=nil)
    {
        if (next(anggota(g))!=nil)
        {
            r = anggota(g);
            anggota(g) = next(r);
            next(r) = nil;
        }
        else
        {
            r = anggota(g);
            anggota(g) = nil;
        }
    }
    else
    {
        r = nil;
    }
}

void deleteaftershadow (addressg &g, adr &r,adr prec)
{
    if (prec != nil)
    {
        if (next(prec)!= nil)
        {
            r = next(prec);
            if (next(r)!=nil)
            {
                next(prec) = next(r);
                next(r) = nil;
            }
            else
            {
                next(prec) = nil;
            }
        }
        else
        {
            r = nil;
        }
    }
    else
    {
        r=nil;
    }
}
void deletelastshadow (addressg &g, adr &r)
{
    adr q = anggota(g);
    if (q!=nil)
    {
        if (next(q)==nil)
        {
            r = q;
            anggota(g)=nil;
        }
        else
        {
            while (next(next(q))!=nil)
            {
                q = next(q);
            }
            r = next(q);
            next(q) = nil;
        }
    }
    else
    {
        r= nil;
    }
}


addressg findgrupbyid (listgrup l, int x)
{
    addressg g = first(l);
    if (g != nil)
    {
        while (info(g).id != x && g != nil)
        {
            g = next(g);
            if (g==nil)
            {
                break;
            }
        }
        return g;
    }
    else
    {
        return nil;
    }
}

addressa findakunbyid (listakun g, int x)
{
    addressa a = first(g);
    if (a != nil)
    {
        while (info(a).id != x && a != nil)
        {
            a = next(a);
            if (a==nil)
            {
                break;
            }
        }
        return a;
    }
    else
    {
        return nil;
    }
}

adr findsh (addressg g, int x)
{
    adr a = anggota(g);
    if (a != nil)
    {
        while (info(info(a)).id != x && a != nil)
        {
            a = next(a);
            if (a==nil)
            {
                break;
            }
        }
        return a;
    }
    else
    {
        return nil;
    }
}

void masukkan (listgrup &l, addressg p)
{
    addressg prec = first(l);
    if (prec == nil)
    {
        insertfirstgrup(l,p);
    }
    else if (info(p).id < info(prec).id)
    {
        insertfirstgrup(l,p);
    }
    else
    {
        while (info(p).id > info(prec).id && next(prec) != nil)
        {
            if (info(next(prec)).id > info(p).id)
            {
                break;
            }
            prec = next(prec);
        }
        insertaftergrup(l,p,prec);
    }
}

void masukkanakun (listakun &g, addressa p)
{
    addressa prec = first(g);
    if (prec == nil)
    {
        insertfirstakun(g,p);
    }
    else if (info(p).id < info(prec).id)
    {
        insertfirstakun(g,p);
    }
    else
    {
        while (info(p).id > info(prec).id && next(prec) != nil)
        {
            if (info(next(prec)).id > info(p).id)
            {
                break;
            }
            prec = next(prec);
        }
        insertafterakun(g,p,prec);
    }
}

void masukkansh (addressg &g, adr r )
{
    adr prec = anggota(g);
    if (prec == nil)
    {
        insertfirstshadow(g,r);
    }
    else if (info(info(r)).id < info(info(prec)).id)
    {
        insertfirstshadow(g,r);
    }
    else
    {
        while (info(info(r)).id > info(info(prec)).id && next(prec) != nil)
        {
            if (info(info(next(prec))).id > info(info(r)).id)
            {
                break;
            }
            prec = next(prec);
        }
        insertaftershadow(g,r,prec);
    }
}

void printinfo (listgrup l)
{
    addressg p = first(l);
    adr ak,ad;
    int cek = 4;
    if (p!=nil)
    {
        gotoxy1(1,1);
        cout<<"===Data Admin==="<<endl;
        gotoxy1(4,2);
        cout<<"Nama Admin";
        gotoxy1(35,1);
        cout<<"===Data Group==="<<endl;
        gotoxy1(25,1);
        cout<<"|";
        gotoxy1(25,2);
        cout<<"|";
        gotoxy1(25,3);
        cout<<"|";
        gotoxy1(27,2);
        cout<<"ID Group";
        gotoxy1(38,2);
        cout<<"Nama Group";
        gotoxy1(51,2);
        cout<<"Tanggal Dibuat";
        gotoxy1(81,1);
        cout<<"===Data Anggota==="<<endl;
        gotoxy1(66,1);
        cout<<"|";
        gotoxy1(66,2);
        cout<<"|";
        gotoxy1(66,3);
        cout<<"|";
        gotoxy1(70,2);
        cout<<"ID_Akun";
        gotoxy1(80,2);
        cout<<"Nama Akun";
        gotoxy1(92,2);
        cout<<"Username";
        gotoxy1(102,2);
        cout<<"Password";
        gotoxy1(110,1);
        cout<<"|";
        gotoxy1(110,2);
        cout<<"|";
        gotoxy1(110,3);
        cout<<"|";
        while (p!=nil)
        {
            ad = admin(p);
            if (ad!=nil && info(ad) != nil)
            {
                gotoxy1(5,cek);
                cout<<info(info(ad)).nama<<endl;
            }
            else
            {
                gotoxy1(1,cek);
                cout<<"Admin Belum Di Pilih"<<endl;
            }
            gotoxy1(30,cek);
            cout<<info(p).id<<endl;
            gotoxy1(39,cek);
            cout<<info(p).nama<<endl;
            gotoxy1(52,cek);
            cout<<info(p).tanggal<<endl;
            if (anggota(p)!= nil)
            {
                ak = anggota(p);
                int a = 0;
                while(ak!=nil)
                {
                    gotoxy1(25,cek);
                    cout<<"|";
                    gotoxy1(66,cek);
                    cout<<"|";
                    gotoxy1(110,cek);
                    cout<<"|";
                    gotoxy1(73,cek);
                    cout<<info(info(ak)).id<<endl;
                    gotoxy1(81,cek);
                    cout<<info(info(ak)).nama<<endl;
                    gotoxy1(93,cek);
                    cout<<info(info(ak)).user<<endl;
                    gotoxy1(103,cek);
                    cout<<info(info(ak)).pass<<endl;
                    cout<<endl;
                    cek++;
                    ak=next(ak);
                }
                gotoxy1(1,cek);
                cout<<"-------------------------------------------------------------------------------------------------------------";
                cek++;
            }
            else
            {
                gotoxy1(75,cek);
                cout<<"Belum ada anggota yang terdaftar";
            }
            if (anggota(p)==nil)
            {
                gotoxy1(25,cek);
                cout<<"|";
                gotoxy1(66,cek);
                cout<<"|";
                gotoxy1(110,cek);
                cout<<"|";
                gotoxy1(1,cek+1);
                cout<<"-------------------------------------------------------------------------------------------------------------";
                cek++;
                cek++;
            }
            p=next(p);
        }
    }
    else
    {
        gotoxy1(38,2);
        cout<<"Tidak ada data";
    }
}

void printakun (listakun a)
{
    addressa aa = first(a);
    if (aa != nil)
    {
        while (aa != nil)
        {
            cout<<"ID : "<<info(aa).id<<endl;
            cout<<"Nama : "<<info(aa).nama<<endl;
            cout<<"Tanggal Lahir : "<<info(aa).tgllahir<<endl;
            cout<<"Username : "<<info(aa).user<<endl;
            cout<<"Password : "<<info(aa).pass<<endl;
            cout<<endl;
            aa=next(aa);
        }
    }
    else
    {
        gotoxy1(38,2);
        cout<<"Tidak ada data";
    }
}
