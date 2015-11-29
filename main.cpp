#include "AkunGrupHeader.h"


using namespace std;

//dibawah ini adalah script untuk menggunakan fungsi gotoxy di c++
void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle( STD_OUTPUT_HANDLE ),
        coord
    );
}


listgrup l;
listakun aa;
addressg g,bantu,cekgrup;
addressa a,cekakun;
adr sh;
infotypeg gu;
infotypea ak;
int pil,pil1;
string pil2;


void menu ()
{
    gotoxy(38,1);
    cout<<"=====Aplikasi Manajemen Akun - Grup=====\n"<<endl;
    gotoxy(38,3);
    cout<<"1. Buat Grup "<<endl;
    gotoxy(38,4);
    cout<<"2. Buat Akun "<<endl;
    gotoxy(38,5);
    cout<<"3. Masukkan Akun ke dalam Grup"<<endl;
    gotoxy(38,6);
    cout<<"4. Hapus"<<endl;
    gotoxy(38,7);
    cout<<"5. Edit Data"<<endl;
    gotoxy(38,8);
    cout<<"6. Tampilkan Data Grup"<<endl;
    gotoxy(38,9);
    cout<<"7. Tampilkan Data Akun"<<endl;
    gotoxy(38,10);
    cout<<"8. Exit"<<endl;
}

void editdata ()
{
    cin.clear();
    cin.ignore(10000,'\n');
ulang :
    system("cls");
    gotoxy(38,1);
    cout<<"1. Edit Grup"<<endl;
    gotoxy(38,2);
    cout<<"2. Edit Akun"<<endl;
    gotoxy(38,4);
    cout<<"Masukkan Pilihan : ";
    if (!(cin >> pil))
    {
        gotoxy(38,6);
        cout << "Please enter numbers only." << endl;
        getch();
        cin.clear();
        cin.ignore(10000,'\n');
        goto ulang;
    }
    switch (pil)
    {
    case 1:
ulang1:
        system("cls");
        cout<<"Masukkan ID Grup yang ingin di edit : ";
        if (!(cin >> pil))
        {
            gotoxy(38,6);
            cout << "Please enter numbers only." << endl;
            getch();
            cin.clear();
            cin.ignore(10000,'\n');
            goto ulang1;
        }
        cekgrup = findgrupbyid(l,pil);
        if (cekgrup != nil)
        {
            cout<<"Masukkan Nama Grup : ";
            cin>>gu.nama;
            cout<<"Masukkan Tanggal Pembuatan Grup : ";
            cin>>gu.tanggal;
            info(cekgrup).nama = gu.nama;
            info(cekgrup).tanggal = gu.tanggal;
            cout<<"Edit sukses";
        }
        else
        {
            cout<<"ID Tidak di temukan";
        }
        getch();
        break;
    case 2:
ulang2:
        system("cls");
        cout<<"Masukkan ID akun yang ingin di edit : ";
        if (!(cin >> pil))
        {
            gotoxy(38,6);
            cout << "Please enter numbers only." << endl;
            getch();
            cin.clear();
            cin.ignore(10000,'\n');
            goto ulang2;
        }
        cekakun = findakunbyid(aa,pil);
        if (cekakun != nil)
        {
            cout<<"Masukkan Nama Akun : ";
            cin>>ak.nama;
            cout<<"Masukkan Tanggal Lahir : ";
            cin>>ak.tgllahir;
            cout<<"Masukkan Username : ";
            cin>>ak.user;
            cout<<"Masukkan Password : ";
            cin>>ak.pass;
            info(cekakun).nama = ak.nama;
            info(cekakun).tgllahir = ak.tgllahir;
            info(cekakun).user = ak.user;
            info(cekakun).pass = ak.pass;
            cout<<"Edit sukses";
        }
        else
        {
            cout<<"ID Tidak di temukan";
        }
        getch();
        break;
    default :
        cout<<"Invalid Input";
        getch();
    }
}

void masukkandatagrup ()
{
    int k;
    cin.clear();
    cin.ignore(10000,'\n');
    cout<<"========DATA GRUP========\n"<<endl;
    do
    {
        k = rand() % 50;
        cekgrup = findgrupbyid(l,k);
    }
    while (cekgrup != false);
    gu.id = k;
    cout<<"Masukkan Nama Grup : ";
    cin>>gu.nama;
    cout<<"Masukkan Tanggal Pembuatan Grup : ";
    cin>>gu.tanggal;
    cout << "ID Grup : "<<k;
    getch();
}

void masukkandataakun ()
{
    cin.clear();
    cin.ignore(10000,'\n');
    system("cls");
    int k;
    cout<<"========DATA AKUN========\n"<<endl;
    do
    {
        k = rand() % 50;
        cekakun = findakunbyid(aa,k);
    }
    while (cekakun != false);
    ak.id = k;
    cout<<"Masukkan Nama Akun : ";
    cin>>ak.nama;
    cout<<"Masukkan Tanggal Lahir : ";
    cin>>ak.tgllahir;
    cout<<"Masukkan Username : ";
    cin>>ak.user;
    cout<<"Masukkan Password : ";
    cin>>ak.pass;
    cout << "ID Akun : "<<k;
    getch();
}

void menuhapus ()
{
    cin.clear();
    cin.ignore(10000,'\n');
ulang:
    system("cls");
    gotoxy(38,1);
    cout<<"1. Hapus Grup"<<endl;
    gotoxy(38,2);
    cout<<"2. Hapus Akun"<<endl;
    gotoxy(38,3);
    cout<<"3. Hapus Anggota dari suatu Grup"<<endl;
    gotoxy(38,5);
    cout<<"Pilihan : ";
    if (!(cin >> pil))
    {
        gotoxy(38,6);
        cout << "Please enter numbers only." << endl;
        getch();
        cin.clear();
        cin.ignore(10000,'\n');
        goto ulang;
    }
    switch (pil)
    {
    case 1:
        system("cls");
        cout<<"Peringatan ! Menghapus Grup berarti menghapus semua anggota yang berada di dalam grup !"<<endl;
        cout<<"Ingin lanjut (y/n) ? ";
        cin>>pil2;
        if (pil2 == "y")
        {
ulang1:
            system("cls");
            cout<<"Masukkan ID Grup yang ingin di hapus ? : ";
            if (!(cin >> pil))
            {
                gotoxy(38,6);
                cout << "Please enter numbers only." << endl;
                getch();
                cin.clear();
                cin.ignore(10000,'\n');
                goto ulang1;
            }
            cekgrup = findgrupbyid(l,pil);
            if (cekgrup != nil)
            {
                deletegrup(l,cekgrup);
                cout<<"Delete sukses";
            }
            else
            {
                cout<<"ID tidak ditemukan";
            }
        }
        getch();
        break;
    case 2:
        system("cls");
        cout<<"Peringatan ! Menghapus Akun berarti menghapus data akun yang sama yang berada di dalam suatu grup !"<<endl;
        cout<<"Ingin lanjut (y/n) ? ";
        cin>>pil2;
        if (pil2 == "y")
        {
ulang2:
            system("cls");
            cout<<"Masukkan ID Akun yang ingin di hapus ? : ";
            if (!(cin >> pil))
            {
                gotoxy(38,6);
                cout << "Please enter numbers only." << endl;
                getch();
                cin.clear();
                cin.ignore(10000,'\n');
                goto ulang2;
            }
            cekakun = findakunbyid(aa,pil);
            if (cekakun != nil)
            {
                deleteakun(l,aa,cekakun);
                cout<<"Delete sukses";
            }
            else
            {
                cout<<"ID tidak ditemukan";
            }
        }
        getch();
        break;
    case 3:
ulang3:
        system("cls");
        cout<<"Masukkan ID Grup : ";
        if (!(cin >> pil1))
        {
            gotoxy(38,6);
            cout << "Please enter numbers only." << endl;
            getch();
            cin.clear();
            cin.ignore(10000,'\n');
            goto ulang3;
        }
        cekgrup = findgrupbyid(l,pil1);
        if (cekgrup != nil)
        {
            cout<<"Masukkan ID Akun : ";
            if (!(cin >> pil))
            {
                gotoxy(38,6);
                cout << "Please enter numbers only." << endl;
                getch();
                cin.clear();
                cin.ignore(10000,'\n');
                goto ulang3;
            }
            cekakun = findakunbyid(aa,pil);
            sh = findsh(cekgrup,pil1);
            if (sh != nil)
            {
                if (admin(cekgrup)==sh)
                {
                    admin(cekgrup)=nil;
                }
                deleteanggota(cekgrup,cekakun);
                cout<<"Delete sukses";
            }
            else
            {
                cout<<"Akun tersebut tidak ada di dalam grup";
            }
        }
        else
        {
            cout<<"ID Tidak di temukan";
        }
        getch();
        break;
    default :
        cout<<"Invalid Input";
        getch();
    }
}

void domenu ()
{
    switch (pil)
    {
    case 1:
        system("cls");
        masukkandatagrup();
        if (cekgrup==nil)
        {
            g = alokasigrup(gu);
            masukkan(l,g);
        }
        break;
    case 2:
        system("cls");
        masukkandataakun();
        if (cekakun == nil)
        {
            a = alokasiakun(ak);
            masukkanakun(aa,a);
        }
        break;
    case 3:
ulang:
        system("cls");
        cout<<"Masukkan ID akun yang akan dimasukkan ke dalam grup : ";
        if (!(cin >> pil))
        {
            gotoxy(38,6);
            cout << "Please enter numbers only." << endl;
            getch();
            cin.clear();
            cin.ignore(10000,'\n');
            goto ulang;
        }
        a = findakunbyid (aa,pil);
        if (a!=nil)
        {
            system("cls");
            printinfo(l);
            cout<<endl;
            cout<<endl;
            cout<<"ID Akun yang akan di masukkan : "<<pil<<endl;
            cout<<"Ingin dimasukkan ke grup dengan ID ? ";
            if (!(cin >> pil1))
            {
                gotoxy(38,6);
                cout << "Please enter numbers only." << endl;
                getch();
                cin.clear();
                cin.ignore(10000,'\n');
                goto ulang;
            }
            bantu = findgrupbyid(l,pil1);
            if (bantu != nil)
            {
                sh = findsh(bantu,pil);
                if (sh == nil)
                {
                    sh = alokasishadow(a);
                    masukkansh(bantu,sh);
                    cout<<"Ingin Menjadikan Akun ini sebagai admin grup (y/n) ?";
                    cin>>pil2;
                    if (pil2 == "y" || pil2=="Y")
                    {
                        admin(bantu) = sh;
                        cout<<"Admin berhasil di ganti";
                    }
                }
                else
                {
                    cout<<"Anggota sudah berada di grup";
                }
            }
            else
            {
                cout<<"ID Tidak ditemukan";
            }
        }
        else
        {
            cout<<"ID Tidak ditemukan";
        }
        getch();
        break;
    case 4:
        system("cls");
        menuhapus();
        break;
    case 5:
        system("cls");
        editdata();
        break;
    case 6:
        system("cls");
        printinfo(l);
        getch();
        break;
    case 7:
        system("cls");
        printakun(aa);
        getch();
        break;
    case 8:
        break;
    default :
        gotoxy(38,14);
        cout<<"Invalid input";
        getch();
        break;
    }
}

int main()
{
    createlistgrup(l);
    createlistakun(aa);
    do
    {
ulang :
        system("cls");
        menu();
        gotoxy(38,12);
        cout<<"Masukkan Pilihan : ";
        if (!(cin >> pil))
        {
            gotoxy(38,14);
            cout << "Please enter numbers only." << endl;
            getch();
            cin.clear();
            cin.ignore(10000,'\n');
            goto ulang;
        }
        domenu();
    }
    while (pil != 8);
    return 0;
}
