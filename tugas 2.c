#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


// LOGIN REGISTER



char ch,user1[50],pass1[50];




void reg()
{
    char user2[50],pass2[50];
    system("cls");
    printf("Daftarkan username Anda: ");gets(user2);
    printf("Daftarkan username Anda: ");gets(pass2);
    strcpy(user1,user2);
    strcpy(pass1,pass2);
    system("pause");
    startup();
}


int login()
{
    int p=0;
    char user2[50],pass2[50];
    login:
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tAdministrator: ");
        gets(user2);
        printf("\t\t\t\t\t\tPassword:      ");
        while(1)
        {
            ch=getch();
            if (ch==13)
            {
                pass1[p]='\0';
                break;
            }
            else
            {
                pass2[p]=ch;
                p++;
                printf("*");
            }
        }
    if ((strcmp(user1,user2)==0) && (strcmp(pass1,pass2)==0))
    {

            system("color 20");
            printf("\n\nLogin success, welcome %s",user2);
            printf("\n\n");
            system("pause");
            menu();

    }
    else
        system("color 40");
        printf("\n\n\t\t\t\t\tInvalid username or password...\n\n\t\t\t\t\t");
        system("pause");
        main();
    getch();
}




void arrowHere(int realPosition, int arrowPosition)
{
    if(realPosition==arrowPosition)
    {
        printf(" --> ");
    }
    else
    {
        printf("     ");
    }
}


void startup()
{
    system("cls");
    int position=1,keyPressed=0;
    #define MAX 3
    #define MIN 1
    while (keyPressed!=13)
    {
        system("cls");
        printf("===================================\n");
        printf("                                   \n");
        printf("===================================\n");
        arrowHere(1,position);printf("1. Reg\n");
        arrowHere(2,position);printf("2. Login\n");
        arrowHere(3,position);printf("3. Exit\n");
        printf("===================================\n");
        keyPressed=getch();
        if(keyPressed==80&&position!=MAX)
        {
            position++;
        }
        else if(keyPressed==72&&position!=MIN)
        {
            position--;
        }
        if(keyPressed==13&&position==1)
        {
            reg();
        }
        else if(keyPressed==13&&position==2)
        {
            login();
        }
        else if(keyPressed==13&&position==3)
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t   created by:");
            printf("\n\n\t\t\t\t\tCornbelius Ardhani Yoga Pratama");
            printf("\n\t\t\t\t\t\t   672022204\n\n\n\n\n\n\n\n\n\n\n");
            exit(0);
        }
        else
        {
            position=position;
        }
    }
}


void menu()
{
    system("cls");
    int position=1,keyPressed=0;
    #define MAX 5
    #define MIN 1
    while (keyPressed!=13)
    {
        system("cls");
        printf("===================================\n");
        printf("          Tugas Kalkulator         \n");
        printf("===================================\n");
        arrowHere(1,position);printf("1. PingPoroLanSudo\n");
        arrowHere(2,position);printf("2. SinCosTan\n");
        arrowHere(3,position);printf("3. Hitung Keliling & Luas\n");
        arrowHere(4,position);printf("4. Hitung Akar Kuadrat\n");
        arrowHere(5,position);printf("5. Kembali ke tampilan awal\n");
        printf("===================================\n");
        keyPressed=getch();
        if(keyPressed==80&&position!=MAX)
        {
            position++;
        }
        else if(keyPressed==72&&position!=MIN)
        {
            position--;
        }
        if(keyPressed==13&&position==1)
        {
            pingporolansudo();
        }
        else if(keyPressed==13&&position==2)
        {
            sincostan();
        }
        else if(keyPressed==13&&position==3)
        {
            kelilingluas();
        }
        else if(keyPressed==13&&position==4)
        {
            akarkuadrat();
        }
        else if(keyPressed==13&&position==5)
        {
            startup();
        }
        else
        {
            position=position;
        }
    }
}




void pingporolansudo()
{
    system("cls");
    int position=1,keyPressed=0;
    #define MAX 5
    #define MIN 1
    while (keyPressed!=13)
    {
        system("cls");
        printf("===================================\n");
        printf("         Ping Poro Lan Sudo         \n");
        printf("===================================\n");
        arrowHere(1,position);printf("1. Perkalian\n");
        arrowHere(2,position);printf("2. Pembagian\n");
        arrowHere(3,position);printf("3. Penjumlahan\n");
        arrowHere(4,position);printf("4. Pengurangan\n");
        arrowHere(5,position);printf("5. Kembali ke menu\n");
        printf("===================================\n");
        keyPressed=getch();
        if(keyPressed==80&&position!=MAX)
        {
            position++;
        }
        else if(keyPressed==72&&position!=MIN)
        {
            position--;
        }
        else if(keyPressed==13&&position==1)
        {
            perkalian();
        }
        else if(keyPressed==13&&position==2)
        {
            pembagian();
        }
        else if(keyPressed==13&&position==3)
        {
            penjumlahan();
        }
        else if(keyPressed==13&&position==4)
        {
            pengurangan();
        }
        else if(keyPressed==13&&position==5)
        {
            menu();
        }
        else
        {
            position=position;
        }
    }
}


void perkalian()
{
    system("cls");
    int opsi;
    float num1,num2,res;
    printf("PERKALIAN\n\n");
    printf("Masukkan angka pertama = ");scanf("%f",&num1);
    printf("Masukkan angka kedua = ");scanf("%f",&num2);
    res=num1*num2;
    printf("\nHasil dari %.2f * %.2f = %.2f\n\n",num1,num2,res);
    system("pause");
    ulang:
    printf("\nIngin mengulang perkalian?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        perkalian();
    }
    else if(opsi==2)
    {
        pingporolansudo();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void pembagian()
{
    system("cls");
    int opsi;
    float num1,num2,res;
    printf("PEMBAGIAN\n\n");
    printf("Masukkan angka pertama = ");scanf("%f",&num1);
    printf("Masukkan angka kedua = ");scanf("%f",&num2);
    res=num1/num2;
    printf("\nHasil dari %.2f : %.2f = %.2f\n\n",num1,num2,res);
    system("pause");
    ulang:
    printf("\nIngin mengulang pembagian?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        pembagian();
    }
    else if(opsi==2)
    {
        pingporolansudo();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void penjumlahan()
{
    system("cls");
    int opsi;
    float num1, num2, res;
    printf("PENJUMLAHAN\n\n");
    printf("Masukkan angka pertama = ");scanf("%f",&num1);
    printf("Masukkan angka kedua = ");scanf("%f",&num2);
    res=num1+num2;
    printf("\nHasil dari %.2f + %.2f = %.2f\n\n",num1,num2,res);
    system("pause");
    ulang:
    printf("\nIngin mengulang penjumlahan?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        penjumlahan();
    }
    else if(opsi==2)
    {
        pingporolansudo();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void pengurangan()
{
    system("cls");
    int opsi;
    float num1,num2,res;
    printf("PENGURANGAN\n\n");
    printf("Masukkan angka pertama = ");scanf("%f",&num1);
    printf("Masukkan angka kedua = ");scanf("%f",&num2);
    res=num1-num2;
    printf("\nHasil dari %.2f - %.2f = %.2f\n\n",num1,num2,res);
    system("pause");
    ulang:
    printf("\nIngin mengulang pengurangan?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        pengurangan();
    }
    else if(opsi==2)
    {
        pingporolansudo();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}




void sincostan()
{
    system("cls");
    int position=1,keyPressed=0;
    #define MAX 4
    #define MIN 1
    while (keyPressed!=13)
    {
        system("cls");
        printf("=============================\n");
        printf("         Sin Cos Tan         \n");
        printf("=============================\n");
        arrowHere(1,position);printf("1. Sinus\n");
        arrowHere(2,position);printf("2. Cosinus\n");
        arrowHere(3,position);printf("3. Tangen\n");
        arrowHere(4,position);printf("4. Kembali ke menu\n");
        printf("=============================\n");
        keyPressed=getch();
        if(keyPressed==80&&position!=MAX)
        {
            position++;
        }
        else if(keyPressed==72&&position!=MIN)
        {
            position--;
        }
        else if(keyPressed==13&&position==1)
        {
            sinus();
        }
        else if(keyPressed==13&&position==2)
        {
            cosinus();
        }
        else if(keyPressed==13&&position==3)
        {
            tangen();
        }
        else if(keyPressed==13&&position==4)
        {
            menu();
        }
        else
        {
            position=position;
        }
    }
}


void sinus()
{
    system("cls");
    int opsi;
    float deg,rad;
    const float phi=3.142857142857143;
    printf("SINUS\n\n");
    printf("Masukkan derajat = ");scanf("%f",&deg);
    rad=deg*(phi/180.00);
    printf("\nHasil sinus (%.2f) adalah = %.2f\n\n",deg,sin(rad));
    system("pause");
    ulang:
    printf("\nIngin mengulang sinus?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        sinus();
    }
    else if(opsi==2)
    {
        sincostan();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void cosinus()
{
    system("cls");
    int opsi;
    float deg,rad;
    const float phi=3.142857142857143;
    printf("COSINUS\n\n");
    printf("Masukkan derajat = ");scanf("%f",&deg);
    rad=deg*(phi/180.00);
    printf("\nHasil cosinus (%.2f) adalah = %.2f\n\n",deg,cos(rad));
    system("pause");
    ulang:
    printf("\nIngin mengulang cosinus?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        cosinus();
    }
    else if(opsi==2)
    {
        sincostan();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void tangen()
{
    system("cls");
    int opsi;
    float deg, rad;
    const float phi=3.142857142857143;
    printf("TANGEN\n\n");
    printf("Masukkan derajat = ");scanf("%f",&deg);
    rad=deg*(phi/180.00);
    printf("\nHasil tangen (%.2f) adalah = %.2f\n\n",deg,tan(rad));
    system("pause");
    ulang:
    printf("\nIngin mengulang tangen?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        tangen();
    }
    else if(opsi==2)
    {
        sincostan();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}




void kelilingluas()
{
    system("cls");
    int position=1,keyPressed=0;
    #define MAX 4
    #define MIN 1
    while (keyPressed!=13)
    {
        system("cls");
        printf("===================================\n");
        printf("      Hitung Keliling & Luas       \n");
        printf("===================================\n");
        arrowHere(1,position);printf("1. Hitung Keliling Bangun Datar\n");
        arrowHere(2,position);printf("2. Hitung Luas Bangun Datar\n");
        arrowHere(3,position);printf("3. Hitung Volume Bangun Ruang\n");
        arrowHere(4,position);printf("4. Kembali ke menu\n");
        printf("===================================\n");
        keyPressed=getch();
        if(keyPressed==80&&position!=MAX)
        {
            position++;
        }
        else if(keyPressed==72&&position!=MIN)
        {
            position--;
        }
        else if(keyPressed==13&&position==1)
        {
            kelilingdatar();
        }
        else if(keyPressed==13&&position==2)
        {
            luasdatar();
        }
        else if(keyPressed==13&&position==3)
        {
            volumeruang();
        }
        else if(keyPressed==13&&position==4)
        {
            menu();
        }
        else
        {
            position=position;
        }
    }
}


void kelilingdatar()
{
    system("cls");
    int position=1, keyPressed=0;
    #define MAX 5
    #define MIN 1
    while (keyPressed!=13)
    {
        system("cls");
        printf("===================================\n");
        printf("       Keliling Bangun Datar       \n");
        printf("===================================\n");
        arrowHere(1,position);printf("1. Keliling Persegi\n");
        arrowHere(2,position);printf("2. Keliling Trapesium\n");
        arrowHere(3,position);printf("3. Keliling Layang-Layang\n");
        arrowHere(4,position);printf("4. Keliling Lingkaran\n");
        arrowHere(5,position);printf("5. Kembali ke menu\n");
        printf("===================================\n");
        keyPressed=getch();
        if(keyPressed==80 && position!=MAX)
        {
            position++;
        }
        else if(keyPressed==72&&position!=MIN)
        {
            position--;
        }
        else if(keyPressed==13&&position==1)
        {
            kelilingpersegi();
        }
        else if(keyPressed==13&&position==2)
        {
            kelilingtrapesium();
        }
        else if(keyPressed==13&&position==3)
        {
            kelilinglayang();
        }
        else if(keyPressed==13&&position==4)
        {
            kelilinglingkaran();
        }
        else if(keyPressed==13&&position==5)
        {
            kelilingluas();
        }
        else
        {
            position=position;
        }
    }
}


void kelilingpersegi()
{
    system("cls");
    int opsi;
    float num1,num2,res;
    printf("KELILING PERSEGI\n\n");
    printf("Masukkan panjang persegi = ");scanf("%f",&num1);
    printf("Masukkan lebar persegi = ");scanf("%f",&num2);
    res=2*num1+2*num2;
    printf("\nKeliling persegi adalah = %.2f\n\n",res);
    system("pause");
    ulang:
    printf("\nIngin mengulang keliling persegi?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        kelilingpersegi();
    }
    else if(opsi==2)
    {
        kelilingdatar();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void kelilingtrapesium()
{
    system("cls");
    int opsi;
    float num1,num2,num3,res;
    printf("KELILING TRAPESIUM SAMA KAKI\n\n");
    printf("Masukkan panjang sisi atas = ");scanf("%f",&num1);
    printf("Masukan panjang sisi bawah = ");scanf("%f",&num2);
    printf("Masukkan panjang sisi miring = ");scanf("%f",&num3);
    res=num1+num2+(num3*2);
    printf("\nKeliling trapesium sama kaki adalah = %.2f\n\n",res);
    system("pause");
    ulang:
    printf("\nIngin mengulang keliling trapesium sama kaki?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        kelilingtrapesium();
    }
    else if(opsi==2)
    {
        kelilingdatar();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void kelilinglayang()
{
    system("cls");
    int opsi;
    float num1,num2,res;
    printf("KELILING LAYANG-LAYANG\n\n");
    printf("Masukkan panjang sisi atas = ");scanf("%f",&num1);
    printf("Masukkan panjang sisi bawah = ");scanf("%f",&num2);
    res=num1*2+num2*2;
    printf("\nKeliling layang-layang adalah = %.2f\n\n",res);
    system("pause");
    ulang:
    printf("\nIngin mengulang keliling layang-layang?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        kelilinglayang();
    }
    else if(opsi==2)
    {
        kelilingdatar();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void kelilinglingkaran()
{
    system("cls");
    int opsi;
    float num1,num2,res_r,res_d;
    const float phi=3.142857142857143;
    printf("KELILING LINGKARAN\n\n");
    printf("Masukkan panjang jari-jari = ");scanf("%f",&num1);
    printf("Masukkan panjang diameter = ");scanf("%f",&num2);
    res_r=phi*2*num1;
    res_d=phi*num2;
    printf("\nKeliling lingkaran berdasar jari-jari = %.2f\n",res_r);
    printf("Keliling lingkaran berdasar diameter = %.2f\n\n",res_d);
    system("pause");
    ulang:
    printf("\nIngin mengulang keliling lingkaran?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        kelilinglingkaran();
    }
    else if(opsi==2)
    {
        kelilingdatar();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void luasdatar()
{
    system("cls");
    int position=1, keyPressed=0;
    #define MAX 5
    #define MIN 1
    while (keyPressed!=13)
    {
        system("cls");
        printf("===================================\n");
        printf("         Luas Bangun Datar         \n");
        printf("===================================\n");
        arrowHere(1,position);printf("1. Luas Persegi\n");
        arrowHere(2,position);printf("2. Luas Trapesium\n");
        arrowHere(3,position);printf("3. Luas Layang-Layang\n");
        arrowHere(4,position);printf("4. Luas Lingkaran\n");
        arrowHere(5,position);printf("5. Kembali ke menu\n");
        printf("===================================\n");
        keyPressed=getch();
        if(keyPressed==80&&position!=MAX)
        {
            position++;
        }
        else if(keyPressed==72&&position!=MIN)
        {
            position--;
        }
        else if(keyPressed==13&&position==1)
        {
            luaspersegi();
        }
        else if(keyPressed==13&&position==2)
        {
            luastrapesium();
        }
        else if(keyPressed==13&&position==3)
        {
            luaslayang();
        }
        else if(keyPressed==13&&position==4)
        {
            luaslingkaran();
        }
        else if(keyPressed==13&&position==5)
        {
            menu();
        }
        else
        {
            position=position;
        }
    }
}


void luaspersegi()
{
    system("cls");
    int opsi;
    float num1,num2,res;
    printf("LUAS PERSEGI\n\n");
    printf("Masukkan panjang persegi = ");scanf("%f",&num1);
    printf("Masukkan lebar persegi = ");scanf("%f",&num2);
    res=num1*num2;
    printf("\nLuas persegi adalah = %.2f\n\n",res);
    system("pause");
    ulang:
    printf("\nIngin mengulang luas persegi?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        luaspersegi();
    }
    else if(opsi==2)
    {
        luasdatar();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void luastrapesium()
{
    system("cls");
    int opsi;
    float num1,num2,num3,res;
    printf("LUAS TRAPESIUM SAMA KAKI\n\n");
    printf("Masukkan sisi atas trapesium = ");scanf("%f",&num1);
    printf("Masukkan sisi bawah trapesium = ");scanf("%f",&num2);
    printf("Masukkan tinggi trapesium = ");scanf("%f",&num3);
    res=(num1+num2)*1/2*num3;
    printf("\nLuas trapesium sama kaki adalah = %.2f\n\n",res);
    system("pause");
    ulang:
    printf("\nIngin mengulang luas trapesium sama kaki?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        luastrapesium();
    }
    else if(opsi==2)
    {
        luasdatar();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}

void luaslayang()
{
    system("cls");
    int opsi;
    float num1,num2,res;
    printf("LUAS LAYANG-LAYANG\n\n");
    printf("Masukkan diagonal panjang = ");scanf("%f",&num1);
    printf("Masukkan diagonal lebar = ");scanf("%f",&num2);
    res=num1*num2*1/2;
    printf("\nLuas layang-layang adalah = %.2f\n\n",res);
    system("pause");
    ulang:
    printf("\nIngin mengulang luas layang-layang?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        luaslayang();
    }
    else if(opsi==2)
    {
        luasdatar();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void luaslingkaran()
{
    system("cls");
    int opsi;
    float num_r,num_d,res_r,res_d;
    const float phi=3.142857142857143;
    printf("LUAS LINGKARAN\n\n");
    printf("Masukkan panjang jari-jari = ");scanf("%f",&num_r);
    printf("Masukkan panjang diameter = ");scanf("%f",&num_d);
    res_r=phi*num_r*num_r;
    res_d=phi*num_d*num_d*1/4;
    printf("\nLuas lingkaran berdasarkan jari-jari adalah = %.2f",res_r);
    printf("\nLuas lingkaran berdasarkan diameter adalah = %.2f\n\n",res_d);
    system("pause");
    ulang:
    printf("\nIngin mengulang luas persegi?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        luaslingkaran();
    }
    else if(opsi==2)
    {
        luasdatar();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void volumeruang()
{
    system("cls");
    int position=1,keyPressed=0;
    #define MAX 5
    #define MIN 1
    while (keyPressed!=13)
    {
        system("cls");
        printf("===================================\n");
        printf("         Volume Bangun Ruang         \n");
        printf("===================================\n");
        arrowHere(1,position);printf("1. Volume Kubus\n");
        arrowHere(2,position);printf("2. Volume Prisma\n");
        arrowHere(3,position);printf("3. Volume Limas\n");
        arrowHere(4,position);printf("4. Volume Bola\n");
        arrowHere(5,position);printf("5. Kembali ke menu\n");
        printf("===================================\n");
        keyPressed=getch();
        if(keyPressed==80&&position!=MAX)
        {
            position++;
        }
        else if(keyPressed==72&&position!=MIN)
        {
            position--;
        }
        else if(keyPressed==13&&position==1)
        {
            volumekubus();
        }
        else if(keyPressed==13&&position==2)
        {
            volumeprisma();
        }
        else if(keyPressed==13&&position==3)
        {
            volumelimas();
        }
        else if(keyPressed==13&&position==4)
        {
            volumebola();
        }
        else if(keyPressed==13&&position==5)
        {
            menu();
        }
        else
        {
            position=position;
        }
    }
}


void volumekubus()
{
    system("cls");
    int opsi;
    float num1,res;
    printf("VOLUME KUBUS\n\n");
    printf("Masukkan panjang sisi kubus = ");scanf("%f",&num1);
    res=num1*num1*num1;
    printf("\nVolume kubus adalah = %.2f\n\n",res);
    system("pause");
    ulang:
    printf("\nIngin mengulang volume kubus?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        volumekubus();
    }
    else if(opsi==2)
    {
        volumeruang();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void volumeprisma()
{
    system("cls");
    int opsi;
    float num_sq,num_btm_tri,num_height_tri,num_r,num_d,num_height_prsm,res_sq,res_tri,res_r,res_d;
    const float phi=3.142857142857143;
    printf("VOLUME PRISMA\n\n");
    printf("Masukkan panjang sisi persegi = ");scanf("%f",&num_sq);
    printf("Masukkan lebar alas segitiga = ");scanf("%f",&num_btm_tri);
    printf("Masukkan tinggi segitiga = ");scanf("%f",&num_height_tri);
    printf("Masukkan panjang jari-jari lingkaran = ");scanf("%f",&num_r);
    printf("Masukkan panjang diameter lingkaran = ");scanf("%f",&num_d);
    printf("Masukkan tinggi prisma = ");scanf("%f",&num_height_prsm);
    res_sq=(num_sq*num_sq)*num_height_prsm;
    res_tri=(num_btm_tri*num_height_tri*1/2)*num_height_prsm;
    res_r=(phi*num_r*num_r)*num_height_prsm;
    res_d=(phi*num_d*num_d)*num_height_prsm*1/4;
    printf("\nVolume prisma persegi adalah = %.2f",res_sq);
    printf("\nVolume prisma seegitiga adalah = %.2f",res_tri);
    printf("\nVolume silinder berdasar jari-jari adalah = %.2f",res_r);
    printf("\nVolume silinder berdasar diameter adalah = %.2f\n\n",res_d);
    system("pause");
    ulang:
    printf("\nIngin mengulang volume prisma?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        volumeprisma();
    }
    else if(opsi==2)
    {
        volumeruang();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void volumelimas()
{
    system("cls");
    int opsi;
    float num_sq,num_btm_tri,num_height_tri,num_r,num_d,num_height_pmd,res_pmd_sq,res_pmd_tri,res_pmd_r,res_pmd_d;
    const float phi=3.142857142857143;
    printf("VOLUME LIMAS\n\n");
    printf("Masukkan panjang sisi persegi = ");scanf("%f",&num_sq);
    printf("Masukkan lebar alas segitiga = ");scanf("%f",&num_btm_tri);
    printf("Masukkan tinggi segitiga = ");scanf("%f",&num_height_tri);
    printf("Masukkan panjang jari-jari lingkaran = ");scanf("%f",&num_r);
    printf("Masukkan panjang diameter lingkaran = ");scanf("%f",&num_d);
    printf("Masukkan tinggi limas = ");scanf("%f",&num_height_pmd);
    res_pmd_sq=(num_sq*num_sq)*num_height_pmd*1/3;
    res_pmd_tri=(num_btm_tri*num_height_tri*1/2)*num_height_pmd*1/3;
    res_pmd_r=(phi*num_r*num_r)*num_height_pmd*1/3;
    res_pmd_d=(phi*num_d*num_d*1/4)*num_height_pmd*1/3;
    printf("\nVolume limas persegi adalah = %.2f",res_pmd_sq);
    printf("\nVolume limas segitiga adalah = %.2f",res_pmd_tri);
    printf("\nVolume limas silinder berdasar jari-jari adalah = %.2f",res_pmd_r);
    printf("\nVolume limas silinder berdasar diameter adalah = %.2f\n\n",res_pmd_d);
    system("pause");
    ulang:
    printf("\nIngin mengulang volume limas?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        volumelimas();
    }
    else if(opsi==2)
    {
        volumeruang();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}


void volumebola()
{
    system("cls");
    int opsi;
    float num_r,num_d,num_d_to_r,res_r,res_d;
    const float phi=3.142857142857143;
    printf("VOLUME BOLA\n\n");
    printf("Masukkan panjang jari-jari lingkaran = ");scanf("%f",&num_r);
    printf("Masukkan panjang diameter lingkaran = ");scanf("%f",&num_d);;
    res_r=(phi*num_r*num_r*num_r)*4/3;
    num_d_to_r=num_d/2;res_d=(phi*num_d_to_r*num_d_to_r*num_d_to_r)*4/3;
    printf("\nVolume bola berdasar jari-jari adalah = %.2f",res_r);
    printf("\nVolume bola berdasar diameter adalah = %.2f\n\n",res_d);
    system("pause");
    ulang:
    printf("\nIngin mengulang volume bola?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        volumebola();
    }
    else if(opsi==2)
    {
        volumeruang();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}




void akarkuadrat()
{
    system("cls");
    int opsi;
    float num1,res;
    printf("AKAR KUADRAT\n\n");
    printf("Masukkan bilangan yang akan diakar = ");scanf("%f",&num1);
    res=sqrt(num1);
    printf("\nHasil akar dari %.2f adalah %.2f\n\n",num1,res);
    system("pause");
    ulang:
    printf("\nIngin mengulang hitung akar?\n(1 untuk ya, 2 untuk kembali ke menu)");scanf("%d",&opsi);
    fflush(stdin);
    if(opsi==1)
    {
        akarkuadrat();
    }
    else if(opsi==2)
    {
        menu();
    }
    else
    {
        system("cls");
        printf("PILIHAN SALAH! MASUKKAN DENGAN SESUAI!\n\n");
        system("pause");
        fflush(stdin);
        goto ulang;
    }
}




int main()
{
    fflush(stdin);
    startup();
    return 0;
}
