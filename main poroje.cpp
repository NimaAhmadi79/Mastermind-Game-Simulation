#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <bits/stdc++.h>
//-------------------------------------------------------------------------------------------------------------------------------------------
using namespace std;
//void f1();                                    //id and pass
void login();
void game();
void judge(string [],int );                   //tabe tashkhis bord va bakht
struct player{
	int id;
	char pass[3];
	int win;
	int lose;
	}a[5]; 
int A=0;                                     //shomarande tedad marahel anjam shode va tashkhis bordo bakht
int t;                                       //shomarande tedad bord va bakht har player
//--------------------------------------------------------------------------------------------------------------------------------------------	
int main(){
	fstream myfile;
	myfile.open("k.txt", ios::in);
	for(int i=0;i<5;i++){
		myfile>>a[i].id>>a[i].pass>>a[i].win>>a[i].lose;
	}
	myfile.close();
//	f1();
	login();

	return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
/*void f1(){                                   //tabe dadan id va pass
	a[0].id=1;
	a[1].id=2;
	a[2].id=3;
	a[3].id=4;
	a[4].id=5;
	a[0].lose=0;
	a[1].lose=0;
	a[2].lose=0;
	a[3].lose=0;
	a[0].lose=0;
	a[0].win=0;
	a[1].win=0;
	a[2].win=0;
	a[3].win=0;
	a[4].win=0;
	strcpy(a[0].pass,"abc");
	strcpy(a[1].pass,"rst");
	strcpy(a[2].pass,"xyz");
    strcpy(a[3].pass,"qwe");
	strcpy(a[4].pass,"nmn");
	
}*/
//---------------------------------------------------------------------------------------------------------------------------------------------------
void login(){
	cout<<"please enter id:"<<endl;
	int x;                                       //id
	cin>>x;
	if(x!=1&&x!=2&&x!=3&&x!=4&&x!=5){
		cout<<"Invalid id\a"<<endl;
		exit(0);
	}
	cout<<"please enter password:"<<endl;
	string y;                                   //password
	cin>>y;
	for(int i=0;i<5;i++){
		if(a[i].id==x&&a[i].pass==y){
			t=i;
		 	game();
		 	break;}
		if(i==4){ cout<<"Invalid password\a";}
	}
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void game(){
	enum color{red=1,white,black,yellow,blue,green};
	int q[4];                                       //entekhab davar
	srand(time(0));
	for(int i=0;i<4;i++){
		q[i]=rand()%6+1;                            //entekhab davar
	}
	
	cout<<endl<<endl<<endl;
	cout<<"----------------------------------------------------------------"<<endl<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$ WELLCOME $$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl<<"----------------------------------------------------------------"<<endl;
	cout<<endl;
	cout<<"Allowed colors:"<<endl<<endl;
	cout<<"red   blue   green   yellow   black   white"<<endl<<endl;
	cout<<"----------------------------------------------------------------"<<endl;
	for(int l=0;l<10;l++){                         //tedad marahel bazi
		cout<<"Please enter your selected beads"<<endl;	
		string m[4];                               //entekhab player		
		int n[4];                                  //tabdil rang be adad
		for(int i=0;i<4;i++){
			cin>>m[i];
			if(m[i]!="red"&&m[i]!="green"&&m[i]!="black"&&m[i]!="white"&&m[i]!="yellow"&&m[i]!="blue"){
				cout<<"undefined color\a"<<endl<<"try again:"<<endl;
				i--;
			}
		}
		for(int i=0;i<4;i++){                     //tabdil rang haie entekhabi be adad
			if(m[i]=="red") n[i]=1;
			else if(m[i]=="white") n[i]=2;
			else if(m[i]=="black") n[i]=3;
			else if(m[i]=="yellow") n[i]=4;
			else if(m[i]=="blue") n[i]=5;
			else if(m[i]=="green") n[i]=6;
		} 
		int b[2][4];                             //matris baraie moghaiese mohrehaie entekhabi davar ba bazikon
		for(int i=0;i<4;i++){                    
			b[0][i]=q[i];
		}
		for(int i=0;i<4;i++){
			b[1][i]=n[i];
		}
		/*for(int i=0;i<2;i++){cout<<endl;
			for(int j=0;j<4;j++){
				cout<<b[i][j]<<" ";
			}
		}*/
		string r[4];                            //araie reshte baraie dariaft nazarat davar
		int c=0;                                //moteghaier baraie hazf kardan shomare haie tekrari matris
		for(int i=0;i<4;i++){                    // halghe baaie mohrehaii ke jaie anha yeksan ast
			for(int j=0;j<4;j++){
				if(b[0][i]==b[1][j]&&i==j){
		 		r[i]="white";
		 		b[0][i]=c;
		 		b[1][j]=c;
		 		c--;
		 		}
			}
		} 

		int v=0;                                  //moteghaier baraie hazf kardan shomare haie tekrari matris
		for(int i=0;i<4;i++){                    // halghe baraie mohrehaii ke jaie anha yeksan nist
			for(int j=0;j<4;j++){
				if(b[0][i]==b[1][j]&&i!=j){
		 		r[i]="black";
		 		b[0][i]=v;
		 		b[1][j]=v;
		 		v--;
		 		}
			}
		}

		cout<<endl<<endl;
		cout<<"Judge's judgment:  ";
		for(int i=0;i<4;i++){                    //halghe baraie chap kardan nazarat davar
			cout<<r[i]<<"   ";
			}
		cout<<endl<<endl;
		A++;                                    //shomarande baraie tashkhis bakhtan
		judge (r,A);                            //tabe tashkhis bordo bakht

	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
void judge(string b[],int x){
	int h=0;                                   //shomarande baraie tashkhis bordan                    
	for(int i=0;i<4;i++){                      //halgheie tashkhis bord
		if(b[i]=="white"){h++;}
		if(h==4){
		cout<<endl<<endl<<"*#*#*#*#*#*#*#*#*# you win #*#*#*#*#*#*#*#*#*#*";
		a[t].win++;
		fstream myfile;
		myfile.open("k.txt");
		for(int i=0;i<5;i++){
			myfile<<a[i].id<<" "<<a[i].pass<<" "<<a[i].win<<" "<<a[i].lose<<endl;
			}	
		 exit(0);
		}
	}
	if(x==10){ cout<<endl<<endl<<"----------------you lose---------------";   //sharte bakht
	a[t].lose++;
	fstream myfile; 
	myfile.open("k.txt");
	for(int i=0;i<5;i++){
		myfile<<a[i].id<<" "<<a[i].pass<<" "<<a[i].win<<" "<< a[i].lose<<endl;
		}
		exit(0);
	}
}















