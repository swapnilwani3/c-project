#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<ctime>
#include "windows.h"

uisng namespace std;

void gotoxy(int x,int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	setConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

float price_list[20]={865,2,25,44,10,20,7710,33.33,45.97,8,0.5,0.01,88,999,2500,87,4,22,200,20,150};

class po;
class requisition
{
	static int req_no;
	int iteam_code;
	int qty;
	string delivery_date;
public:
	void get_data();
	void display();
	friend void generate(requisition, po);
	
};

void requisition::get_data(){
	system("cls");
	req_no++;
	cout<<"Product iteam Code: ";
	cin>>iteam_code;
	cout<<"Quantity";
	cin>>qty;
	cout<<"Delivery Date";
	cin.clear();
	cin.ignore(1000,'\n');
	getline(cin,delivery_date);
}

int requisition::req_no;

void requisition::display(){
	system("cls");
	cout<<"Requisition Number:"<<req_no;
	cout<<"\nProduct Iteam Code:"<<iteam_code;
	cout<<"\nQuantity:"<<qty;
	cout<<"\nDelivery Date"<<delivery_date;
	getch();
}

class  po
{
	static	int po_no;
public:
	 po(){
	 	po_no;
	 }
	friend void generate(requisition, po);	
};

int po ::po_no;

void generate(requisition r,po p){
	ofstream fout;
	time_t current time(0);
	char* dt =ctime(&current);
	fout<<"\t\t\t 	Purchase Order#:"<<p.po_no<<"\n";
	fout<<"\t\t\t 	________________\n\n";
	fout<<"Requisition#: "<<r.req_no<<"\t\t\tIssue Date:"<<dt<<"\n\n";
	if(r,iteam_code >= 1 && r.iteam_code <=10)
		fout<<"Supplier: "<<"SKS Spare Parts Ltd.\n\n";
	else if(r.iteam_code >=11 && r.iteam_code <=20)
		fout<<"Supplier: "<<"KC Spare Parts Ltd.\n\n";
	else
		fout<<"Supplier: "<<"Others(________________)\n\n";
	fout<<"Delivery Date"<<r.delivery_date<<"\n\n";
	fout<<"--------------------------------------------------------------------------------------------------------------------------\n"
	fout<<"																					**Line Iteam**
																								\n";
	fout<<"---------------------------------------------------------------------------------------------------------------------------\n";
	fout<<"Iteam code\t\tQuantity\t\tPrice\t\t\tTotal\n";
	fout<<"__________\t\t_________\t\t_____\t\t\t_____\n";
	fout<<"	"<<r.iteam_code<<"\t\t\t   "<<r.qty<<"\t\t\t";
	if(r.iteam_code>=1 && r.iteam_code<=20)
		fout<<"  "<<price_list[r.iteam_code-1]<<"\t\t\t"<<price_list[r.iteam_code-1]*r.qty<<"\n\n\n";
	else
		fout<<"_ _ _\t\t\t_ _ _\n\n\n";
	ifstream fin;
	char line[80];
	fin.open(tearms.txt);
	while(fin){
		fin.getline(line,80);
		fout<<line<<"\n";
	}
	fin.close();
	fout<<"\n\n\n\n\n Authorised Signatory:\t\t\t\t\t\t  Total:_ _ _";
	fout.close();
}

