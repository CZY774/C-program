#include <stdio.h>
#include <windows.h>


void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int main()
{
    int a, key;
	gotoxy(1,1);
	printf("========================");
	gotoxy(1,2);
	printf("     Tugas Quiz ASD     ");
	gotoxy(1,3);
	printf("========================");
	gotoxy(1,4);
	printf("--> 1. Level 1");
	gotoxy(1,5);
	printf("    2. Level 2");
	gotoxy(1,6);
	printf("    3. Level 3");
	gotoxy(1,7);
	printf("    4. Exit");
    gotoxy(1,8);
	printf("========================");

	a=1;
	while((key=getch()))
    {
		if (key=='s')
        {
			a+=1;
		}else if(key=='w')
		{
			a-=1;
		}
		if(a<1)
		{
			a=4;
		}else if(a>4)
		{
			a=1;
		}

		system("cls");
		gotoxy(1,1);
		printf("========================");
		gotoxy(1,2);
		printf("     Tugas Quiz ASD     ");
		gotoxy(1,3);
		printf("========================");

		// level 1
		if (a==1)
        {
			gotoxy(1,4);
			printf("--> 1. Level 1");
			if (key==13)
			{
			    system("cls");
			    level1();
				key==0;
				system("pause");system("cls");
				main();
			}
		}
		else
        {
			gotoxy(1,4);
			printf("    1. Level 1");
		}

		// level 2
		if(a==2)
        {
			gotoxy(1,5);
			printf("--> 2. Level 2");
			if (key==13)
            {
                system("cls");
			    level2();
				key==0;
				system("pause");system("cls");
				main();
			}
		}
		else
        {
			gotoxy(1,5);
			printf("    2. Level 2");
		}

		// level 3
		if(a==3)
        {
			gotoxy(1,6);
			printf("--> 3. Level 3");
			if (key==13)
            {
                system("cls");
			    level3();
				key==0;
				system("pause");system("cls");
				main();
			}
		}
		else
        {
			gotoxy(1,6);
			printf("    3. Level 3");
		}

        // Exit
		if(a==4)
        {
			gotoxy(1,7);
			printf("--> 4. Exit");
			// exit
			if (key==13){
				system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t   created by:");
                printf("\n\n\t\t\t\t\tCornbelius Ardhani Yoga Pratama");
                printf("\n\t\t\t\t\t\t   672022204\n\n\n\n\n\n\n\n\n\n\n");
                exit(0);
			}
		}
		else
        {
			gotoxy(1,7);
			printf("    4. Exit");
		}

		gotoxy(1,8);
		printf("========================");
	}
}



void level1()
{
	int angka,i,j;
	printf("Masukkan angka: ");scanf("%d",&angka);
    for (i=0;i<angka; i++)
    {
        for (j=0;j<=i; j++)
        printf("%d ",j+i);
    printf("\n");
    }
}


void level2()
{
    int angka,i,j;
	printf("Masukkan angka: ");scanf("%d",&angka);
    for (i=1;i<=angka; i++)
    {
        for (j=1;j<=i; j++)
        printf("%d ",j*i);
    printf("\n");
    }
}


void level3()
{
    int i,j,k,l=1,m=1,angka;
    printf("Masukkan angka: ");scanf("%d",&angka);
    for(i=1;i<angka;i++)
    {
        for(j=1;j<=angka-i;j++)
        {
            printf(" ");
        }
        for(k=1;k<=2*i-1;k++)
        {
            printf("%d",m);
            if(k==i){l=0;}
            ((l==1)?(m++):(m--));
        }
        l=1;
        m=1;
        printf("\n");
    }
    for(i=angka;i>=1;i--)
    {
        for(j=1;j<=angka-i;j++)
        {
            printf(" ");
        }
        for(k=1;k<=2*i-1;k++)
        {
            printf("%d",m);
            if(k==i)
            {
                l=0;
            }
            ((l==1)?(m++):(m--));
        }
        l=1;
        m=1;
        printf("\n");
    }
}
