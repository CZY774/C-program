#include <stdio.h>
#include <windows.h>


/*

Rollend Krissando   - 672022020
Harold Tanuwijaya   - 672022107
Cornelius A Yoga P  - 672022204

*/


// untuk score
int sc[3]={0,0,0,0};

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	// Menu Utama
	int a, key;
	gotoxy(1,1);
	printf("========================");
	gotoxy(1,2);
	printf("     Ping Pong Game     ");
	gotoxy(1,3);
	printf("========================");
	gotoxy(1,4);
	printf("--> 1. Play 1 Player");
	gotoxy(1,5);
	printf("    2. Play 2 Player");
	gotoxy(1,6);
	printf("    3. Exit");
	gotoxy(1,7);
	printf("========================");

	menu:
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
			a=3;
		}else if(a>3)
		{
			a=1;
		}

		// Tampilan Menu Utama
		system("cls");
		gotoxy(1,1);
		printf("========================");
		gotoxy(1,2);
		printf("     Ping Pong Game     ");
		gotoxy(1,3);
		printf("========================");

		// 1 Player
		if (a==1)
        {
			gotoxy(1,4);
			printf("--> 1. Play 1 Player");
			// Game
			if (key==13)
			{
				singleplayer();
				key==0;
			}
		}
		else
        {
			gotoxy(1,4);
			printf("    1. Play 1 Player");
		}

		// 2 Player
		if(a==2)
        {
			gotoxy(1,5);
			printf("--> 2. Play 2 Player");
			// Game
			if (key==13){
				twoplayer();
			}
		}
		else
        {
			gotoxy(1,5);
			printf("    2. Play 2 Player");
		}

		// Exit
		if(a==3)
        {
			gotoxy(1,6);
			printf("--> 3. Exit");
			// exit
			if (key==13){
				system("cls");
				exit(0);
			}
		}
		else
        {
			gotoxy(1,6);
			printf("    3. Exit");
		}

		gotoxy(1,7);
		printf("========================");
	}
}

void singleplayer()
{
	//untuk bola
	int x=40,y=10,dx=0,dy=0;
	int i,j;
	int game=0;

	//untuk papan
	int xp1,yp1,pjg,xbot,ybot;
	int gerak=1;
	pjg=2;xp1=5;yp1=8;xbot=75;ybot=8;

	char key=0;
	single:
	while (key!=27)
    {
		// gerak papan bot
		if (game==1)
		{
			ybot+=2*gerak;
			if (ybot<=1 || ybot>=17)
			{
				gerak=-gerak;
			}
		}
		// gerak papan player 1
		if (kbhit())
		{
			key=getch();
			if (key=='a')
			{
				if (xp1>=2)
				{
					xp1-=2;
				}
			}
			else if(key=='d')
			{
				if (xp1+pjg<=40)
                {
					xp1+=2;
				}
			}
			else if(key=='w')
			{
				if (yp1>=1)
                {
					yp1-=1;
				}
			}
			else if(key=='s')
                {
				if (yp1+pjg<=18)
				{
					yp1+=1;
				}
			}
			else if (game == 0 && key==' ')
            {
				game=1;
				dx=rand() % 4-2; dy=rand() % 3-1;
				if(dx==0)
				{
					dx+=1;
				}
			}
		}

		// clear / hapus
		system("cls");

		// untuk border
		int xb,yb;
		xb=0; yb=0;

		// Border
		for(i=0;i<=21;i++)
        {
			for(j=0;j<=81;j++)
			{
				if(i==0 || j==0)
				{
					xb=j;
					gotoxy(xb,yb);
					printf("%c",219);
				}
				if(i==21 || j==81)
				{
					xb=j;
					gotoxy(xb,yb);
					printf("%c",219);
				}
				if(i!=0 && i!=21 && j==40)
				{
					xb=j;
					yb=i;
					gotoxy(xb,yb);
					printf("|");
				}
			}
			yb=i;
		}

		// gerak
		x+=dx;
		y+=dy;

		//cek batas layar
		if (y<=1 || y>=19) dy=-dy;
		if (x<2)
        {
			system("cls");
			gotoxy(40,10);
			printf("G A M E  O V E R");
			gotoxy(40, 11);
			printf("B O T  W O N");
			key=27;
			sc[1]+=1;
		}
		if (x>79)
		{
			system("cls");
			gotoxy(40,10);
			printf("G A M E  O V E R");
			gotoxy(40, 11);
			printf("P L A Y E R  1  W O N");
			key=27;
			sc[0]+=1;
		}

		//cek papan
		if (y==yp1 && x==xp1+1)
        {
			if(dy>0)
			{
				dy=-dy;
			}
			else
			{
				dy=dy;
			}
			dx=-dx;
		}
		else if (y==yp1+1 && x==xp1+1)
		{
			dy=dy;
			dx=-dx;
		}
		else if (y==yp1+2 && x==xp1+1)
        {
			if(dy<0)
            {
				dy=-dy;
			}
			else
			{
				dy=dy;
			}
			dx=-dx;
		}
		else if (y==ybot && x==xbot-1)
        {
			if(dy>0)
            {
				dy=-dy;
			}
			else
			{
				dy=dy;
			}
			dx=-dx;
		}
		else if (y==ybot+1 && x==xbot-1)
        {
			dy=dy;
			dx=-dx;
		}
		else if (y==ybot+2 && x==xbot-1)
        {
			if(dy<0)
            {
				dy=-dy;
			}
			else
            {
				dy=dy;
			}
			dx=-dx;
		}

		// cetak
		gotoxy(x,y);
		printf("%c",254);

		//cetak papan
		for (i=0;i<=pjg;i++)
        {
			// papan 1
			gotoxy(xp1,yp1+i);
			printf("%c",475);
			// papan 2
			gotoxy(xbot,ybot+i);
			printf("%c",475);
		}

		//cetak score
		gotoxy(40,25);
		printf("Score Player 1: %i", sc[0]);
		gotoxy(70,25);
		printf("Score Player 2: %i", sc[1]);

		//tunda
		for (i=1;i<=2000;i++)
			for (j=1;j<=2000;j++);
	}
}

void twoplayer()
{
	//untuk bola
	int x,y,dx,dy;
	int i,j;
	x=40;y=10;dx=0;dy=0;
	int game=0;

	//untuk papan
	int xp2, yp2, pjg,xp1,yp1;
	pjg=2;
	xp1=5;
	yp1=8;

	xp2=75;
	yp2=8;

	char key=0;
	while (key!=27)
    {
		// untuk border
		int xb,yb;
		xb=0;yb=0;

		// Border
		for(i=0;i<=21;i++)
            {
			for(j=0;j<=81;j++)
			{
				if(i==0 || j==0)
				{
					xb=j;
					gotoxy(xb,yb);
					printf("%c",219);
				}
				if(i==21 || j==81)
                {
					xb=j;
					gotoxy(xb,yb);
					printf("%c",219);
				}
				if(j==40){
					xb=j;
					gotoxy(xb,yb);
					printf("|");
				}
			}
			yb=i;
		}

		if (kbhit())
        {
			key=getch();
			if (key=='a')
			{
				if (xp1>=2)
				{
					xp1-=2;
				}
			}
            else if(key=='d')
			{
				if (xp1+pjg<=40)
				{
					xp1+=2;
				}
			}
			else if(key=='w')
			{
				if (yp1>=1)
				{
					yp1-=1;
				}
			}
			else if(key=='s')
			{
				if (yp1+pjg<=18){
					yp1+=1;
				}
			}
			else if (key=='j')
            {
				if (xp2>=42)
                {
					xp2-=2;
				}
			}
			else if(key=='l')
			{
				if (xp2+pjg<=80)
				{
					xp2+=2;
				}
			}
			else if(key=='i')
            {
				if (yp2>=1)
				{
					yp2-=1;
				}
			}
			else if(key=='k')
            {
				if (yp2+pjg<=18)
				{
					yp2+=1;
				}
			}
			else if (key==' ')
            {
				game=1;
				dx=rand() % 4-2; dy=rand() % 3-1;
				if(dx==0)
				{
					dx+=1;
				}
			}
		}
		// clear / hapus
		system("cls");

		// gerak
		x+=dx;
		y+=dy;

		//cek batas layar
		if (y<=1 || y>=19) dy=-dy;
		if (x<2)
        {
			system("cls");
			gotoxy (40, 15);
			printf("P L A Y E R  2  W I N ! ! !");
			key=27;
			sc[3]+=1;
		}
		if (x>79)
		{
			system("cls");
			gotoxy (40, 15);
			printf("P L A Y E R  1  W I N ! ! !");
			key=27;
			sc[2]+=1;
		}

		//cek papan
		if (y==yp1 && x==xp1+1)
        {
			if(dy>0)
			{
				dy=-dy;
			}
			else
			{
				dy=dy;
			}
			dx=-dx;
		}
		else if (y==yp1+1 && x==xp1+1)
        {
			dy=dy;
			dx=-dx;
		}
		else if (y==yp1+2 && x==xp1+1)
        {
			if(dy<0)
			{
				dy=-dy;
			}
			else
			{
				dy=dy;
			}
			dx=-dx;
		}else if (y==yp2 && x==xp2-1)
		{
			if(dy>0)
			{
				dy=-dy;
			}
			else
			{
				dy=dy;
			}
			dx=-dx;
		}
		else if (y==yp2+1 && x==xp2-1)
        {
			dy=dy;
			dx=-dx;
		}
		else if (y==yp2+2 && x==xp2-1)
		{
			if(dy<0)
			{
				dy=-dy;
			}
			else
			{
				dy=dy;
			}
			dx=-dx;
		}
		else if (x<2)
        {
			//game over
			system("cls");
			gotoxy (40, 15);
			printf("P L A Y E R  2  W I N ! ! !");
			key=27;
		}
		else if(x>79)
        {
			//game over
			system("cls");
			gotoxy (40, 15);
			printf("P L A Y E R  1  W I N ! ! !");
			key=27;
		}

		// cetak
		gotoxy(x,y);
		printf("%c",254);

		//cetak papan
		for (i=0;i<=pjg;i++)
        {
			// papan 1
			gotoxy(xp1,yp1+i);
			printf("%c",475);
			// papan 2
			gotoxy(xp2,yp2+i);
			printf("%c",475);
		}

		//cetak score
		gotoxy(40,25);
		printf("Score Player 1: %i", sc[2]);
		gotoxy(70,25);
		printf("Score Player 2: %i", sc[3]);

		//tunda
		for (i=1;i<=2000;i++)
			for (j=1;j<=2000;j++);
	}
}
