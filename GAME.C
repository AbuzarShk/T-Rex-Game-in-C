#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

void intro()
{
int gd,gm,i;
char ln1[]={'W','e','l','c','o','m','e',' ','t','o',' ','t','h','e',' ','g','a','m','e','\0'};
char ln2[]={'I','n',' ','t','h','i','s',' ','g','a','m','e',',',' ','Y','O','U',' ','h','a','v','e',' ','t','o',' ','k','i','l','l',' ','R','A','V','A','N',' ','b','y',' ','j','u','m','p','i','n','g',' ','u','p','o','n',' ','h','i','s',' ','h','e','a','d',' ','b','e','f','o','r','e',' ','i','t',' ','k','i','l','l','s',' ','y','o','u','\0'};
char ln3[]={'P','r','e','s','s',' ','E','N','T','E','R',' ','t','o',' ','c','o','n','t','i','n','u','e','\0'};

clrscr();
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"c:\\turboc++\\disk\\turboc3\\bgi");

delay(1000);
printf("\n\n\n\t\t\t");
for(i=0;ln1[i]!='\0';i++)
{
delay(100);
printf("%c",ln1[i]);
}
printf("\n\n\t");
for(i=0;ln2[i]!='\0';i++)
{
delay(100);
printf("%c",ln2[i]);
}
printf("\n\n\t\t\t");
for(i=0;ln3[i]!='\0';i++)
{
delay(100);
printf("%c",ln3[i]);
}
getch();

}

void getup()
{   int x;
    textcolor(BLACK);
    textbackground(15);
    clrscr();
    window(10,2,70,3);
    cprintf("Press Space to Jump,Press X to exit the Game");
    window(62,2,80,3);
    cprintf("SCORE : ");
    window(1,25,80,25);
    for(x=0;x<79;x++)
    cprintf("�");
    textcolor(0);
}

int t,speed=40;
void ds(int jump)
{
    static int a=1;

    if(jump==0)
	t=0;
    else if(jump==2)
	t--;
    else t++;
    window(2,15-t,18,25);
    cprintf("                 ");
    cprintf("         ��������");
    cprintf("         ��������");
    cprintf("         ��������");
    cprintf(" �      �������� ");
    cprintf(" ���  ���������� ");
    cprintf(" ������������  � ");
    cprintf("   ���������     ");
    if(jump==1 || jump==2){
    cprintf("    ��� ��       ");
    cprintf("    ��   ��      ");
    }else if(a==1)
    {
    cprintf("    ����  ���    ");
    cprintf("      ��         ");
    a=2;
    }
    else if(a==2)
    {
    cprintf("     ��� ��      ");
    cprintf("          ��     ");
    a=1;
    }
    cprintf("                ");
    delay(speed);
}
void obj()
{
    static int x=0,scr=0;
    if(x==56 && t<4)
    {
    scr=0;
    speed=40;
    window(25,8,60,9);
    textcolor(RED);
    cprintf(" Game Over -- RAVAN killed YOU");
    getch();
    window(25,8,60,9);
    cprintf("                              ");
    }
    window(74-x,20,80-x,25);
    textcolor(RED);

    cprintf("��� ");
    cprintf("  ");
    cprintf(" ����� ");
    cprintf("  ���  ");
    cprintf(" ����� ");
    /*
    cprintf("�    � ");
    cprintf("�    � ");
    cprintf("������ ");
    cprintf("  �    ");
    cprintf("  �  " );
    */
    textcolor(0);
    x++;
    if(x==73)
    {
    x=0;
    scr++;
    window(70,2,80,3);
    cprintf("     ");
    window(70,2,80,3);
    cprintf("%d",scr);
    if(speed>20)
	speed--;
    }
}
void main()
{

    char ch;
    int i,jump;
    //introduction part
    intro();

    getup();
    while(1){
    while(!kbhit())
    {
	ds(jump=0);
	obj();
    }
    ch=getch();
    if(ch==' ')
    {
	for(i=0;i<10;i++)
	{
	ds(1);
	obj();
	}
	for(i=0;i<10;i++)
	{
	ds(2);
	obj();
	}
    }
    else if (ch=='x')
    return;
    } //outer while
}
