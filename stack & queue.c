#include <stdio.h>
#include <windows.h>
#include <string.h>
#define MAX 5


void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}




struct Tumpukan
{
    char data[5][50];
    int top; //untuk menentukan data paling atas
}tumpuk;

//buat fungsi apakah tumpukan masih kosong
int stack_isEmpty()
{
    if(tumpuk.top == -1)
    {
        return 1;
    }else{
        return 0;
    }
}

//buat fungsi apakah tumpukan sudah penuh
int stack_isFull()
{
    if(tumpuk.top == MAX-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void inisialisasi_stack()
{
    //decalare bahwa tumpukan masih kosong
    tumpuk.top = -1;
}

void push()
{
    char temp[30];
    if(stack_isFull() != 1)
    {
        tumpuk.top++;
        printf("Masukkan data:");
        scanf(" %[^\n]s",&temp);
        strcpy(tumpuk.data[tumpuk.top],temp);
        printf("\nData %s berhasil di input\n",tumpuk.data[tumpuk.top]);
        system("pause");
        system("cls");
    }
    else
    {
        printf("\nData sudah penuh\n");
        system("pause");
        system("cls");
    }
}

void pop()
{
    if(stack_isEmpty() != 1)
    {
        printf("\nData %s telah dibuang\n",tumpuk.data[tumpuk.top]);
        tumpuk.top--;
        system("pause");
        system("cls");
    }
    else
    {
        printf("\nData masih kosong\n");
        system("pause");
        system("cls");
    }
}

void printData()
{
    if(stack_isEmpty() !=1)
    {
        for(int i=tumpuk.top;i>=0;i--)
        {
            printf("\n%s",tumpuk.data[i]);
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("\nData masih kosong\n");
        system("pause");
        system("cls");
    }
}

int stacckk()
{
    inisialisasi_stack();
    int choice;
    do
    {
        printf("1.Push Stack\n");
        printf("2.Pop Stack\n");
        printf("3.Print Stack\n");
        printf("4.Clear Stack\n");
        printf("5.Exit\n");
        printf("\nInput pilihan:");
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                printData();
                break;
            case 4:
                if(stack_isEmpty())
                {
                    printf("\nData masih kosong!,tidak bisa reset\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    inisialisasi_stack();
                    printf("\nData telah di reset!\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 5:
                main();
                break;
            default:
                printf("\nTidak ada dalam pilihan\n");
                break;
        }
    }
    while(choice >0 && choice < 6);
    return 0;
}




struct Antrian{
    int head;
    int tail;
    int data[MAX];
}antrian;

int queue_isEmpty()
{
    if(antrian.tail == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int queue_isFull()
{
    if(antrian.tail == MAX -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inisialisasi_queue()
{
    antrian.head=antrian.tail = -1;
}

void enqueue(int data)
{
    if(queue_isEmpty()==1)
    {
        antrian.head=antrian.tail = 0;
        antrian.data[antrian.tail] = data;
        printf("\nData %d berhasil diinput!\n",antrian.data[antrian.tail]);
    }
    else
    {
        if(queue_isFull() == 0)
        {
            antrian.tail++;
            antrian.data[antrian.tail] = data;
            printf("\nData %d berhasil di input\n",antrian.data[antrian.tail]);
        }
    }
}

int dequeue()
{
    if(queue_isEmpty() == 1)
    {
        printf("\nData masih kosong!\n");
        system("pause");
        system("cls");
    }
    else
    {
        int i;
        int e = antrian.data[antrian.head];
        printf("\nData %d telah dikeluarkan dari antiran\n",antrian.data[antrian.head]);
        system("pause");
        system("cls");
        for(i=antrian.head;i<=antrian.tail-1;i++)
        {
            antrian.data[i] = antrian.data[i+1];
        }
        antrian.tail--;
        return e;
    }
}

void clear()
{
    if(queue_isEmpty())
    {
        printf("\nData masih kosong!,tidak bisa reset\n");
        system("pause");
        system("cls");
    }
    else
    {
        inisialisasi_stack();
        antrian.head = antrian.tail = -1;
        printf("\nData telah di reset!\n");
        system("pause");
        system("cls");
    }
}

void print()
{
    if(queue_isEmpty() == 0)
    {
        printf("\n");
        for(int i=antrian.head;i<=antrian.tail;i++)
        {
            printf("%d ",antrian.data[i]);

        }
        printf("\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("\nData masih kosongg!\n");
        system("pause");
        system("cls");
    }
}

int queuuee()
{
    int dt;
    inisialisasi_queue();
    int choice;
    do
    {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Print Queue\n");
        printf("4.Clear Queue\n");
        printf("5.Exit\n");
        printf("\nInput pilihan:");
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice)
        {
            case 1:
                if(queue_isFull() !=1)
                {
                    printf("Masukkan data:");
                    scanf("%d",&dt);
                    enqueue(dt);
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("\nData sudah penuh!\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                print();
                break;
            case 4:
                clear();
                break;
            case 5:
                main();
                break;
            default:
                printf("\nTidak ada dalam pilihan\n");
                break;
            }
    }
    while(choice>0 && choice <6);
    return 0;
}





int main()
{
    int a, key;
    system("cls");
    fflush(stdin);
	gotoxy(1,1);
	printf("================================");
	gotoxy(1,2);
	printf("     Tugas Quiz Stack & Queue     ");
	gotoxy(1,3);
	printf("================================");
	gotoxy(1,4);
	printf("--> 1. Stack String");
	gotoxy(1,5);
	printf("    2. Queue Integer");
	gotoxy(1,6);
	printf("    3. Exit");
    gotoxy(1,7);
	printf("================================");

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

		system("cls");
		gotoxy(1,1);
		printf("================================");
		gotoxy(1,2);
		printf("     Tugas Quiz Stack & Queue     ");
		gotoxy(1,3);
		printf("================================");

		// level 1
		if (a==1)
        {
			gotoxy(1,4);
			printf("--> 1. Stack String");
			if (key==13)
			{
			    system("cls");
			    stacckk();
				key==0;
				system("pause");system("cls");
				main();
			}
		}
		else
        {
			gotoxy(1,4);
			printf("    1. Stack String");
		}

		// level 2
		if(a==2)
        {
			gotoxy(1,5);
			printf("--> 2. Queue Integer");
			if (key==13)
            {
                system("cls");
			    queuuee();
				key==0;
				system("pause");system("cls");
				main();
			}
		}
		else
        {
			gotoxy(1,5);
			printf("    2. Queue Integer");
		}



        // Exit
		if(a==3)
        {
			gotoxy(1,6);
			printf("--> 3. Exit");
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
			gotoxy(1,6);
			printf("    3. Exit");
		}

		gotoxy(1,7);
		printf("================================");
	}
}

