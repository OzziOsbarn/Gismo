#include <math.h>
#include <iostream>
#include <fstream>
#include <conio.h> 
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <string> 
#include <cmath> // ���������
#include <stdio.h>  
#include <tchar.h>
#include <clocale> 
#include <windows.h>                     //��� ����� � �������������, ���������
#include <windowsx.h>                  //� ����������� ������� Windows
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
#define DLL_EXPORT __declspec(dllexport)
using namespace std;
double B,NumbSym[26],NumbSym1[26],KSym,B1;
int A1,i,ke,c,n,x,y,H,KK[26];
string S1,LanguageText,Eng22,second1,S2,S,way,K,k1[1];
string Eng1="AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"; //�� 0 �� 51
string Eng2="abcdefghijklmnopqrstuvwxyz"; //�� 0 �� 25
string Rus="�����������娸����������������������������������������������������"; //�� 0 �� 65
//��������� �������
string Istin="etaoinshrdlcumwfgypbvkxjqz";
double IstinN[26]={12.7,9.06,8.17,7.51,6.97,6.75,6.33,6.09,5.99,4.25,4.03,2.78,2.76,2.41,2.36,2.23,2.02,1.97,1.93,1.49,0.98,0.77,0.15,0.15,0.1,0.05};
int symblS[26]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
bool Koe = false;
char field [3][9]; //����
short xI, xJ; //������� ������
bool FOxBOSS; //������� ����������
bool conditions(); //�������
void Redraw(); //�����������
void Cur(short, short); //����� ����� ������
void Move(); //������������ �������
void clear();
void table();
void LanguageTEST();
void tablePrint();
bool Esc();
void save();
string ReLater(string Eng2);
void YY();
void Graphic();
void koef();

int main()
{SetConsoleTitle(L"FOxBOSS 2.0");
setlocale(LC_CTYPE,"Rus"); 
POINT op;
    HWND hWnd=GetConsoleWindow(); //�������� ���������� ���� �������
    HDC hDC=GetDC(hWnd); //�������� �������� ���������� �� ����������� �����������
    SelectObject(hDC,GetStockObject(WHITE_PEN)); //�������� ���� WHITE_PEN � ��������
	xI=0;
    xJ=0;
	while(!FOxBOSS)
{
// ���������� � ����������
SelectObject(hDC,GetStockObject(WHITE_PEN)); //�������� ���� WHITE_PEN � ��������
//�����
MoveToEx(hDC,2,2,&op);
LineTo(hDC,2,30);LineTo(hDC,290,30);LineTo(hDC,290,2);LineTo(hDC,2,2);MoveToEx(hDC,3,3,&op);
LineTo(hDC,3,29);LineTo(hDC,289,29);LineTo(hDC,289,3);LineTo(hDC,3,3);
//������
MoveToEx(hDC,280,7,&op);
LineTo(hDC,270,26);LineTo(hDC,260,7);LineTo(hDC,265,10);LineTo(hDC,275,10);LineTo(hDC,280,7);MoveToEx(hDC,272,15,&op);LineTo(hDC,274,12);
MoveToEx(hDC,268,15,&op);
LineTo(hDC,266,12);
MoveToEx(hDC,270,26,&op);
LineTo(hDC,270,24);LineTo(hDC,268,24);LineTo(hDC,270,24);LineTo(hDC,272,24);
cout<<endl<<" FOxBOSS 2.0"<<endl<<endl<<"(FOxBOSS):������������, ��� ������������ ��������� FOxBOSS.\n(FOxBOSS):� ������� ������ ��������� �� ������ ��������� ���������\n ������ �������, ���������� �� ���������� �����.\n";
// �������� �� ������������� ����� 
probros:
cout <<"(FOxBOSS):������� ������ ���� �� �����, ������� �������� ����� � ���\n ����������.\n";
cout<<"(User):";
cin >> way;
ifstream fin(way);
if (!fin.is_open())
{cout << "(FOxBOSS):����, �� ������� ������ '" << way << "' �� ����� ���� ������!\n"; goto probros;}//���� �� ������ �� ������� � ����� ������
else {
while(true) {
    getline(fin, S1);
    if(!fin.eof())
       S=S+" "+S1;
    else break;
    }	
	S=S+" "+S1;
	S1=S2=S; //������� ������ ������
	fin.close();
	n=S.length();//������� ����� ������
	}
H=0;
LanguageTEST();//�������� �� ������� ���� ������� �����
if (H!=0) {cout<<"(FOxBOSS):� ����� ���� ������� �����: "<<H<<" ����.\n(FOxBOSS):�������, ����� ������ �������� �� ���� ������ �����.\n(FOxBOSS):������� ����� ������� �����.\n"; system("pause");system("cls");goto probros;} 
else cout<<"(FOxBOSS):� ����� ����������� ������� �����.\n";
cout<<"(FOxBOSS):���� ��������. ������� Enter.\n";
Esc(); //����� �� ���������
//������� ����
clear();
// ���������� ���������� ���� � ������ ������ ����
for(int j=0;j<=50;j+=2)
{for(int i=1;i<=n-1;i++) 
if (S1[i]==Eng1[j]) S1[i]=Eng1[j+1];}
H=0;

for(int j=0;j<=25;j++)
{for(int i=1;i<=n-1;i++) 
if (S1[i]==Eng2[j]) H=H+1;
NumbSym1[j]=H;
H=0;}
// ���������� ������� ������� ����
for(int i=0;i<=25;i++)
{NumbSym[i]=(NumbSym1[i]/A1)*100;}
//���������� �� ������ ��������
for(int i=0;i<=100;i++)
	for(int j=1;j<=25;j++)
	{if (NumbSym[j]>NumbSym[j-1]) {KSym=NumbSym[j-1];NumbSym[j-1]=NumbSym[j];NumbSym[j]=KSym;KSym=NumbSym1[j-1];NumbSym1[j-1]=NumbSym1[j];NumbSym1[j]=KSym;K[0]=Eng2[j-1];Eng2[j-1]=Eng2[j];Eng2[j]=K[0];}}cout<<"\n";
B=NumbSym1[0];
//������� ������������ �������
koef();
 //������
Graphic();
field[0][0] = ' ';
    field[0][1] = Istin[0];
    field[0][2] = Istin[1];
    field[0][3] = Istin[2];
    field[0][4] = Istin[3];
    field[0][5] = Istin[4];
    field[0][6] = Istin[5];
    field[0][7] = Istin[6];
    field[0][8] = Istin[7];
    field[1][0] = Istin[8];
    field[1][1] = Istin[9];
    field[1][2] = Istin[10];
    field[1][3] = Istin[11];
    field[1][4] = Istin[12];
    field[1][5] = Istin[13];
    field[1][6] = Istin[14];
    field[1][7] = Istin[15];
    field[1][8] = Istin[16];
    field[2][0] = Istin[17];
    field[2][1] = Istin[18];  
	field[2][2] = Istin[19];
    field[2][3] = Istin[20];
    field[2][4] = Istin[21];
    field[2][5] = Istin[22];
    field[2][6] = Istin[23];
    field[2][7] = Istin[24];
    field[2][8] = Istin[25]; 
//������ ������ �� �������
for(int j=0;j<=25;j++)
{for(int i=1;i<=n-1;i++) 
if (S1[i]==Eng2[j]) S1[i]=symblS[j];}
Eng22=Istin;
table();//����� ������
Esc(); //����� �� ���������
clear();
while(!FOxBOSS)
{ Redraw();
 FOxBOSS=conditions();
}}}
void koef()
{// ������� ������������ �������
ke=1;
if (B>=190) {while(B>=190)
 {B=B/2;
  ke=ke+1;}
B=pow(2,ke);} else B=1;}
//-------------------------------------------
void Graphic()
{clear();
POINT op;
    HWND hWnd=GetConsoleWindow(); //�������� ���������� ���� �������
    HDC hDC=GetDC(hWnd); //�������� �������� ���������� �� ����������� �����������
    SelectObject(hDC,GetStockObject(WHITE_PEN)); //�������� ���� WHITE_PEN � ��������
 MoveToEx(hDC,5,10,&op);
 LineTo(hDC,5,200);LineTo(hDC,360,200);
 MoveToEx(hDC,6,200,&op);
 x=5;y=201;
for(i=25;i>=0;i--)
 {y=y-int(NumbSym1[i]/B);
 LineTo(hDC,x,y);
 x=x+12;
  LineTo(hDC,x,y);
y=y+int(NumbSym1[i]/B);
 LineTo(hDC,x,y);
 MoveToEx(hDC,x+1,200,&op);}
 for(int i=0;i<=15;i++)
 {cout<<endl;}
 cout<<"  ";cout<<endl<<" ";
 for(int i=25;i>=0;i--)
 {cout<<" "<<Eng2[i];}
 Esc();
 clear();}
//----------------------------------------
void save()
{clear();
cout<<"(FOxBOSS):���� �������� ��������.\n";
ofstream fout("text.txt");
fout<<endl<<S2;
fout.close();
system("pause");}
//-----------------------------------------
bool Esc()
{c = _getch();
if (c == 27) //������ esc
return true;} //����� �� ���������
//-----------------------------------------
void clear()
{ //������� ����
 POINT op;
    HWND hWnd=GetConsoleWindow(); //�������� ���������� ���� �������
    HDC hDC=GetDC(hWnd); //�������� �������� ���������� �� ����������� �����������
	SelectObject(hDC,GetStockObject(BLACK_PEN)); //�������� ���� WHITE_PEN � ��������
 MoveToEx(hDC,0,0,&op);
 x=0;y=0;
 for(int i=0;i<=300;i++)
 { x=x+400;
 LineTo(hDC,x,y);
 y=y+1;
  LineTo(hDC,x,y);
  x=x-400;
 LineTo(hDC,x,y);}
 system("cls");}
//-----------------------------------------
void table()
{cout<<"  ��������� �������/������� ������ ���� ������"<<endl;
for(int i=0;i<=25;i++)
{cout<<"              "<<Istin[i]<<"  "<<char(Eng2[i])<<"  "<<NumbSym[i]<<"%  "<<" "<<NumbSym1[i]<<"\n";}
system("pause");
//������ ��������
for(int j=0;j<=25;j++)
{for(int i=1;i<=n-1;i++) 
if (S1[i]==symblS[j]) S2[i]=Eng22[j];}
//����� ����������� ������
for(int j=1;j<=n-1;j++) 
	{cout<<S2[j];}
cout<<endl<<"��������:\n(���������������� ����������,2000(The Mathematical Association of America))";
cout<<endl<<"(��� ����������� � �������� ����������� ������ Space (������).)\n";

 }
//-----------------------------------------
void LanguageTEST()
{	for(int j=0;j<=51;j++)//���������� ��������
	{for(int i=1;i<=n-1;i++) 
	if (S1[i]==Eng1[j]) {H=H+1;}}
if (H!=0) {cout<<"(FOxBOSS):� ����� ���� ���������� �����: "<<H<<" ����.\n";A1=H;H=0;} 
		for(int j=0;j<=65;j++)//������� ��������
		{for(int i=1;i<=n-1;i++) 
		if (S1[i]==Rus[j]) {H=H+1;}}
}
//-----------------------------------------
void Move()
{int c = _getch();
if (c == 75 && xJ > 0)
 {xJ--;
  Redraw();
  }
else if (c == 77 && xJ < 8)
 {xJ++;
  Redraw();
  }
else if (c == 72 && xI > 0)
 {xI--;
  Redraw();
  }
else if (c == 80 && xI < 2)
 {xI++;
  Redraw();
  }
}
//-----------------------------------------
void YY()
{Eng22[0]=field[0][1]; 
Eng22[1]=field[0][2];
Eng22[2]=field[0][3]; 
Eng22[3]=field[0][4];
Eng22[4]=field[0][5];
Eng22[5]=field[0][6];
Eng22[6]=field[0][7];
Eng22[7]=field[0][8]; 
Eng22[8]=field[1][0];
Eng22[9]=field[1][1];
Eng22[10]=field[1][2]; 
Eng22[11]=field[1][3]; 
Eng22[12]=field[1][4]; 
Eng22[13]=field[1][5];
Eng22[14]=field[1][6];
Eng22[15]=field[1][7]; 
Eng22[16]=field[1][8];
Eng22[17]=field[2][0];
Eng22[18]=field[2][1];
Eng22[19]=field[2][2];
Eng22[20]=field[2][3]; 
Eng22[21]=field[2][4];
Eng22[22]=field[2][5];
Eng22[23]=field[2][6]; 
Eng22[24]=field[2][7]; 
Eng22[25]=field[2][8]; }
//--------------------------
bool conditions()
{int c = _getch();
	if ((field[xI][xJ]!=field[0][0])&&(c==97)) {field[xI][xJ]='a'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==98)) {field[xI][xJ]='b';} else
	if ((field[xI][xJ]!=field[0][0])&&(c==99)) {field[xI][xJ]='c';} else
	if ((field[xI][xJ]!=field[0][0])&&(c==100)) {field[xI][xJ]='d'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==101)) {field[xI][xJ]='e'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==102)) {field[xI][xJ]='f'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==103)) {field[xI][xJ]='g'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==104)) {field[xI][xJ]='h'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==105)) {field[xI][xJ]='i'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==106)) {field[xI][xJ]='j'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==107)) {field[xI][xJ]='k'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==108)) {field[xI][xJ]='l';} else
	if ((field[xI][xJ]!=field[0][0])&&(c==109)) {field[xI][xJ]='m'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==110)) {field[xI][xJ]='n'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==111)) {field[xI][xJ]='o'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==112)) {field[xI][xJ]='p'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==113)) {field[xI][xJ]='q'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==114)) {field[xI][xJ]='r'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==115)) {field[xI][xJ]='s'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==116)) {field[xI][xJ]='t'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==117)) {field[xI][xJ]='u'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==118)) {field[xI][xJ]='v'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==119)) {field[xI][xJ]='w'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==120)) {field[xI][xJ]='x'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==121)) {field[xI][xJ]='y'; } else
	if ((field[xI][xJ]!=field[0][0])&&(c==122)) {field[xI][xJ]='z'; } else
    if (c == 27) //������ esc
	{return true;} //�������
	else if (c == 32) {
		clear();
		table();
		Esc();}//����� ������� ���� ������ ������
	else if (c == 224) Move();
	else if (c == 13) {save();}
	YY();
      return false;
}
//-----------------------------------------
void Redraw()
{system ("cls");
cout << endl<< " +---+---+---+---+---+---+---+---+---+" <<endl;
cout << " |";
for (int i = 0; i<8; i++)
{Cur (0, i);
 cout << "|";
}
Cur (0, 8);
cout << "|"<< endl;

cout << " |---+---+---+---+---+---+---+---+---|" << endl<< " |";
for (int i = 0; i <8; i++)
{Cur (1, i);
cout << "|";
}
Cur (1, 8);
cout << "|"<< endl;

cout << " |---+---+---+---+---+---+---+---+---|" << endl<< " |";
for (int i = 0; i <8; i++)
{Cur (2, i);
cout << "|";
}
Cur (2, 8);
cout<< "|" << endl<< " +---+---+---+---+---+---+---+---+---+" << endl;
cout<<"(FOxBOSS):����� �� ������ �������� �������� ���� ������, ��������� ���������.\n(FOxBOSS):��� ����������� ����������� ������� �� ����������.\n";
cout<<"(FOxBOSS):��� ������ ������ ������� Space (������).\n(FOxBOSS):��� ���������� ����� ������� Enter\n(FOxBOSS):��� ������ �� ���������� ������� Esc\n";
}
//-----------------------------------------
void Cur (short i, short j)
{if (i == xI && j == xJ)
 cout << "[";
  else cout << " ";
cout << field[i][j];
if (i == xI && j == xJ)
 cout << "]";
  else cout << " ";
  }
//-----------------------------------------



