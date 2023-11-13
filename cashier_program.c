#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>


int arID[10],decision,arqty[10],Bill[10],counter=0,qtybyr;
char buyer[50][50],ch,admin[50],password[50];


int login()
{
    int p=0;
    login:
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tAdministrator: ");
        gets(admin);
        printf("\t\t\t\t\t\tPassword:      ");
        while(1)
        {
            ch=getch();
            if (ch==13)
            {
                password[p]='\0';
                break;
            }
            else
            {
                password[p]=ch;
                p++;
                printf("*");
            }
        }
    if (strcmp(admin,"qwe123")==0)
    {
        if (strcmp(password,"qwe123")==0)
        {
            system("color 20");
            printf("\n\n\t\t\t\t\t    Login success, welcome %s",admin);
            printf("\n\n\t\t\t\t\t    ");
            system("pause");
            exe();
        }
        else
            system("color 40");
            printf("\n\n\t\t\t\t\tInvalid password...\n\n\t\t\t\t\t");
            system("pause");
            main();
    }
    else
        system("color 40");
        printf("\n\n\t\t\t\t\tInvalid username...\n\n\t\t\t\t\t");
        system("pause");
        main();
    getch();
}


int main_page()
{
    int n;
    system("cls");
    system("color 30");
    printf("\n\n\n\n\n\n\t\t\t\t    ================================================\n\n");
    printf("\t\t\t\t\t    K O P E R A S I  A W O K A W O K\n\n");
    printf("\t\t\t\t    ================================================\n\n");
    printf("\t\t\t\t\t    1. CHECKOUT\n");
    printf("\t\t\t\t\t    2. BUYER'S NAME\n");
    printf("\t\t\t\t\t    3. BUYER'S DATA\n");
    printf("\t\t\t\t\t    4. RECEIPT\n");
    printf("\t\t\t\t\t    5. DEAR ASDOS\n");
    printf("\t\t\t\t\t    6. EXIT\n\n");
    printf("\t\t\t\t    ================================================\n\n");
    printf("\n\t\t\t\t\t    Choose your option: ");
    scanf("%d",&n);
    return n;
}


void menu_order()
{
    int i;
    work:
        system("cls");
        system("color A0");
        printf("\t\t\t\t=====================================================\n\n");
        printf("\t\t\t\t\t\tGrab your needs!:\n");
        printf("\t\t\t\t\t\tPress 0 to end order\n\n");
        printf("\t\t\t\t=====================================================\n\n");
        printf("\t\t\t\t\t1. PENCIL...................Rp. 5.000\n");
        printf("\t\t\t\t\t2. PEN......................Rp. 10.000\n");
        printf("\t\t\t\t\t3. ERASER...................Rp. 3.000\n");
        printf("\t\t\t\t\t4. TIPE-X...................Rp. 4.000\n");
        printf("\t\t\t\t\t5. HIGHLITER................Rp. 6.000\n");
        printf("\t\t\t\t\t6. PAPER....................Rp. 2.000\n");
        printf("\t\t\t\t\t7. CUTTER...................Rp. 20.000\n");
        printf("\t\t\t\t\t8. RULER....................Rp. 10.000\n");
        printf("\t\t\t\t\t9. NOTEBOOK.................Rp. 50.000\n");
        printf("\t\t\t\t\t10. CAMPUS'S BOOK...........Rp. 100.000\n\n");
        printf("\t\t\t\t=====================================================\n\n");
        printf("\n\t\t\t\t\t\tHow many buyer: ");
        scanf("%i",&qtybyr);
        for(i=0;i<qtybyr;i++)
        {
            printf("\n\t\t\t\t\t\tBuyer name: ");
            scanf(" %[^\n]s",&buyer[i]);
            while(1)
            {
                counter++;
                printf("\n\t\t\t\t\t\tEnter Item ID: ");
                scanf("%d",&arID[counter-1]);
                if(arID[counter-1]==0)
                {
                    break;
                }
                else if(arID[counter-1]>10)
                {
                    printf("\n\t\t\t\t\t\tInvalid input\n\t\t\t\t\t\t");
                    system("pause");
                    goto work;
                }
                printf("\t\t\t\t\t\tEnter Quantity: ");
                scanf("%d",&arqty[counter-1]);
            }
        }
        printf("\n\n\t\t\t\t\t\tENTER 1 BACK TO MENU \n\n\t\t\t\t\t\tENTER: ");
        scanf("%d",&decision);

        counter--;

        if(decision==1)
        {
            exe();
        }
        else
            main();
}


 buyer_name()
{
    int i,j=0,n;
    system("cls");
    system("color 50");
    printf("==============================\n\n");
    printf("BUYER's NAME\n\n");
    printf("==============================\n\n");
    for(i=0;i<qtybyr;i++)
    {
        printf("%s\n",strupr(buyer[i]));
    }
    printf("\n");
    printf("==============================\n\n");
    printf("Administrator: %s\n",admin);
    printf("Password: %s\n\n",password);
    printf("==============================\n\n");
    printf("ENTER 1 TO ORDER AGAIN\nENTER 2 TO GO TO BACK MENU\n\nENTER: ");
    scanf("%d",&n);
    if(n==1)
    {
        menu_order();
    }
    else if(n==2)
    {
        exe();
    }
    else
        exe();
}


void kesanpesan()
{
    int n;
    system("color 60");
    printf("DEAR ASDOS\n\n");
    printf("KESAN PESAN:\n Terima kasih untuk segala waktu dan ilmu yang telah kalian berikan kepada kami ini.\nCara ngajarnya asik untuk diikuti walaupun saat live coding bikin budrek. \nBuat Kak Nata, Cara ngajarnya sangat mudah untuk dicerna walaupun kadang2 ngasih tugas bikin backflip.Personality kakak sangat open dan easy diajak ngomong juga, jangan ketularan sama Mas Budi tingkah lakunya ya kak.\n Buat Mas Aryo tingkah\n lakunya mencerminkan binatang liar. INI KOMPLIMEN LO MAS! artinya Mas itu orangnya outgoing \ndan energinya hypernya bikin nular, tetap seperti itu mas! \n");
    printf("\n");
    scanf("%d",&n);
    if(n==1)
    {
        menu_order();
    }
    else if(n==2)
    {
        exe();
    }
    else
        exe();
    exe();
}


int exe()
{
    int sum=0;
    int costs[10]={5000,10000,3000,4000,6000,2000,20000,10000,50000,100000};
    char items[10][16]={"PENCIL","PEN","ERASER","TIPE-X","HIGHLITER","PAPER","CUTTER","RULER","NOTEBOOK","CAMPUS'S BOOK"};
    int i,k,n;
    k=main_page();
            if(k==1)
            {
                menu_order();
            }
            else if(k==2)
            {
                buyer_name();
            }

            else if(k==3)
            {
                system("cls");
                    system("color 80");
                    printf("============================================\n\n");
                    printf("Buyer's name\t: %s\n\n",buyer);
                    printf("============================================\n\n");
                    printf("Item(s):\t\tQuantity:\n\n");
                    for(i=0;i<counter;i++)
                    {
                        printf("%d.%-20s %d piece(s)\n",i+1,items[arID[i]-1],arqty[i]);
                    }
                    printf("\n\nENTER 1 TO ORDER AGAIN \nENTER 2 TO GO BACK TO MENU \n\nENTER: ");
                    scanf("%d",&n);
                    if(n==1)
                    {
                        menu_order();
                    }
                    else if(n==2)
                    {
                        exe();
                    }
                    else
                        exe();
            }
            else if(k==4)
            {
                int pay,change;
                bill:
                    system("cls");
                    system("color E0");
                    time_t t = time(NULL);
                    printf("\t\t\t\t========================================================\n\n");
                    printf("\t\t\t\t\tDate\t\t: %s", ctime(&t));
                    printf("\t\t\t\t\tBuyer's name\t: %s\n\n",buyer);
                    printf("\t\t\t\t========================================================\n\n");
                    printf("\t\t\t\t\tITEM(S):\tQUANTITY:\tCOST:\n\n");
                    for(i=0;i<counter;i++)
                    {
                        printf("\t\t\t\t\t%d.%-13s %d piece(s)\tRp. %d\n",i+1,items[arID[i]-1],arqty[i],arqty[i]*costs[arID[i]-1]);
                        sum=sum+(costs[arID[i]-1]*arqty[i]);
                    }
                    printf("\n\t\t\t\t========================================================\n\n");
                    printf("\t\t\t\t\t\t\t  TOTAL BILL  = Rp. %d\n",sum);
                pay:
                    printf("\t\t\t\t\t\t\t  PAY         = Rp. ");
                    scanf("%i",&pay);
                    change=pay-sum;
                    if(change>=0)
                    {
                        printf("\t\t\t\t\t\t\t  YOUR RETURN = Rp. %i\n\n",pay-sum);
                    }
                    else
                    {
                        printf("\t\t\t\t\t\t\t  PLEASE PAY ACCORDING TO YOUR BILL\n\n\t\t\t\t\t\t\t");
                        system("pause");
                        goto bill;
                    }
                    printf("\t\t\t\t========================================================\n\n\n");
                    printf("\t\t\t\t\tENTER 1 TO ORDER AGAIN \n\t\t\t\t\tENTER 2 TO GO BACK TO MENU \n\n\t\t\t\t\tENTER: ");
                    scanf("%d",&n);
                    if(n==1)
                    {
                        menu_order();
                    }
                    else if(n==2)
                    {
                        exe();
                    }
            }
            else if(k==5)
            {
                system("cls");
                kesanpesan();
            }
            else if(k==6)
            {
                system("cls");
                system("color 0F");
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t   created by:");
                printf("\n\t\t\t\t\t\t   kelompok 19");
                printf("\n\n\t\t\t\t\t HAROLD TANUWIJIAYA 672022204\n\t\t\t\t   CORNELIUS ARDHANI YOGA PRATAMA 672022204\n\n\n\n\n\n\n\n\n\n\n");
                exit(19);
            }
            else
            {
                system("cls");
                system("color B0");
                main();
            }
}


int main()
{
    fflush(stdin);
    login();
    exe();
}
