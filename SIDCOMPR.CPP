#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<fstream.h>
class shop
{
int pno;
char name[50];
float price, qty, amt, disamt;
public:
shop()
{
pno=0;
strcpy(name, " ");
price=0.0;
qty=0.0;
amt=0.0;
disamt=0.0;
}
void setpno(int pnr)
{
pno=pnr;
}
void setname(char * nm)
{
strcpy(name, nm);
}
void setprice(int pr)
{
price=pr;
}
void setqty(int q)
{
qty=q;
}
void setamt(int am)
{
amt=am;
}
void setdisamt(int dam)
{
disamt=dam;
}
int retpno()
{
return pno;
}
char* retname()
{
return name;
}
float retprice()
{
return price;
}
float retqty()
{
return qty;
}
float retamt()
{
return amt;
}
float retdisamt()
{
return disamt;
}
};
class product
{
int pno;
char name[50];
float price, dis;
public:
void create_product();
int retpno()
{
return pno;
}
float retprice()
{
return price;
}
float retdis()
{
return dis;
}
char* retname()
{
return name;
}
void setpno(int pnr)
{
pno=pnr;
}
void setpname(char * nm)
{
strcpy(name, nm);
}
void setprice(int pr)
{
price=pr;
}
void setdis(float d)
{
dis=d;
}
product()
{
pno=0;
strcpy(name, " ");
price=0.0;
dis=0.0;
}
};
void product::create_product()
{
cout<<"Enter pno: \t";
cin>>pno;
cin.ignore(1);
cout<<"\nEnter Product name :\t";
cin.getline(name, 40);
cin.ignore(1);
cout<<"Enter price: \t";
cin>>price;
cin.ignore(1);
cout<<"Enter dis: \t";
cin>>dis;
cin.ignore(1);
}
class supermarket
{
char pass[40];
char user[40];
char admin;
public:
int readpass(void);
int readuser();
void create_product();
int retpno();
void write_product();
void display_all();
void display_sp();
void modify_product();
void delete_product();
void menu();
void place_order();
void intro();
void admin_menu();
supermarket()
{
strcpy(pass, " ");
strcpy(user, " ");
admin=' ';
}
};
/**************************************************************************/
void supermarket::menu()
{
	ifstream fin;
	clrscr();
	product p2;
	cout<<"\n\n\n\tDISPLAY ALL RECORDS !!!!!!\n\n";
	fin.open("product.dat",ios::in| ios::binary);
	if(!fin)
	{
	cout<<"ERROR!!! File cannot be opened.\n\n\nGo to admin menu to create file.";
	cout<<"\n\n\nProgram is closing.....";
	getch();
	exit(0);
	}
	cout<<"\n\t"<<"PNO"<<"\t"<<"PRODUCT NAME"<<"\t"<<"PRICE"<<"\t"<<"DISCOUNT";
	cout<<"\n*****************************************************************************\n";
	while((!fin.eof()) && (fin.read((char*) &p2, sizeof(p2))))
	{
	cout<<"\n\t"<<p2.retpno()<<"\t"<<p2.retname()<<"\t\t"<<p2.retprice()<<"\t"<<p2.retdis();

	}
	fin.close();
	getch();
}
/*********************************************************************/
void supermarket::intro()
{
	clrscr();
	cout<<"\n\nSUPERMARKET : BILLING PROJECT"<<endl;
	cout<<"\n\nMADE BY     : "<<endl;
	cout<<"\n\n            : "<<endl;
	cout<<"\n\n            : "<<endl;
	getch();
}
/**********************************************************************/
void supermarket::place_order()
{
int order_arr[50], c=0;
float quan[50],amt, damt, total=0;
char ch='Y';
menu();
cout<<"\n <-<-<-PLACE YOUR ORDER->->->";
do
{
cout<<"\n\nEnter the product no. of the product : ";
cin>>order_arr[c];
cout<<"\nQuantity in number : ";
cin>>quan[c];
c++;
cout<<"\nDo you want to order another product?(Y/N)  ";
cin>>ch;
}while(ch=='Y'||ch=='y');

	cout<<"\n\n----------Thank you for placing the order.----------";
	getch();
	clrscr();
	cout<<"\n\n************************INVOICE************************\n";
	cout<<"\nPrno.\tPr Name \tPrice \tQty  \tAmount \tDiscounted Amount\n";
	product p1;
	ifstream fin;
	ofstream fout;
	for(int k=0; k<=c; k++)
	{
		fout.open("shop.dat", ios::out| ios::binary | ios::app);
		fin.open("product.dat",ios::in | ios::binary);
		shop shp1;
		while((!(fin.eof())) && fin.read((char*)&p1,sizeof(product)))
		{
			if(p1.retpno()==order_arr[k])
			{
				amt=p1.retprice()*quan[k];
				damt=amt-(amt*(p1.retdis()));
				cout<<"\n"<<order_arr[k]<<"\t"<<p1.retname()<<"\t"<<p1.retprice()<<"\t"<<quan[k]<<"\t"<<amt<<"\t"<<damt<<"\n";
				total+=damt;
				shp1.setpno(p1.retpno());
				shp1.setname(p1.retname());
				shp1.setprice(p1.retprice());
				shp1.setqty(order_arr[k]);
				shp1.setamt(amt);
				shp1.setdisamt(damt);
				fout.write((char*) &shp1, sizeof(shop));
			}


		};
		fin.close();
		}
	cout<<"\n\n\t\t\t\tTOTAL : "<<total;
	getch();
}
/**********************************************************************/
int supermarket::readuser()
{
clrscr();
cout<<"\t\t\t****LOGIN***";
cout<<"\nEnter userid:";
cin.ignore(1);
cin.getline(user,40);
if(strcmpi(user,"shop123")==0)
 {
 cout<<"User name is correct.";
 return 1;
 }
else
  return 0;
}
/********************************************************************/
int supermarket::readpass()
{
cout<<"\nEnter password:";
int i=0;
while((pass[i]=getch())!=char(13))
	{
		cout<<"*";
		i++;
	};
	pass[i++]='\0';
if(strcmpi(pass,"shopuser2226")==0)
  {

  cout<<"Password is correct.";
  getch();
  return 1;
  }
else
  {
  cout<<"worng password";
  getch();
  return 0;
}
}
/****************************************************************/
void supermarket::admin_menu()
{
	clrscr();
	char ch2;

	cout<<"\n\n\n\tADMIN MENU";
	cout<<"\n\n\n\t1. CREATE PRODUCT.";
	cout<<"\n\n\n\t2. DISPLAY ALL PRODUCTS.";
	cout<<"\n\n\n\t3. QUERY.";
	cout<<"\n\n\n\t4. MODIFY PRODUCT.";
	cout<<"\n\n\n\t5. DELETE PRODUCT.";
	cout<<"\n\n\n\t6. VIEW PRODUCT MENU.";
	cout<<"\n\n\n\t7. BACK TO MAIN MENU.";
	cout<<"\n\n\n\tPlease enter your choice (1-7) : ";
	ch2=getch();
	switch(ch2)
	{
		case'1': clrscr();
			 write_product();
			 admin_menu();
			 break;
	       case'2':  clrscr();
			 display_all();
			 admin_menu();
			 break;
		case'3': int num;
			 clrscr();
			 display_sp();
			 admin_menu();
			 break;
		case'4': modify_product();
			 admin_menu();
			 break;

		case'5': delete_product();
			 admin_menu();
			 break;

		case'6': //s1.menu();
		 break;
	}
}
/******************************************************************/
void supermarket::write_product()
{       int pn;
	char pname[50];
	float pr, d;
	product p;
	cout<<"\nEnter product no:";
	cin>>pn;
	p.setpno(pn);
	cout<<"\nEnter product Name: ";
	gets(pname);
	p.setpname(pname);
	cout<<"\nEnter product price:";
	cin>>pr;
	p.setprice(pr);
	cout<<"\nEnter disount:";
	cin>>d;
	p.setdis(d);
	ofstream fout;
	fout.open("product.dat",ios::out|ios::app);
	fout.write((char*)&p,sizeof(p));
	fout.close();
	fout<<"\n\nThe product has been created.";
	getch();
}
/***************************************************************************/
void supermarket::display_all()
{
ifstream fin;
	clrscr();
	product p2;
	cout<<"\n\n\n\tDISPLAY ALL RECORDS !!!!!!\n\n";
	fin.open("product.dat",ios::in| ios::binary);
	cout<<"\n\t"<<"PNO"<<"\t"<<"PRODUCT NAME"<<"\t\t"<<"PRICE   "<<"DISCOUNT";
	cout<<"\n*****************************************************************************\n";
	while((!fin.eof()) && (fin.read((char*) &p2, sizeof(p2))))
	{
	cout<<"\n\t"<<p2.retpno()<<"\t"<<p2.retname()<<"\t\t"<<p2.retprice()<<"\t"<<p2.retdis();

	}
	fin.close();
	getch();
}

/**************************************************************************/
void supermarket::display_sp()
{      	int no, flag=0;
	product p;
	ifstream fi;
	clrscr();
	cout<<"\n\n\QUERY";
	cout<<"\n\n\tPlease enter the product no. of the product : ";
	cin>>no;
	fi.open("product.dat", ios::in | ios::out | ios::binary);
	while((!fi.eof()) && (flag==0))
	{

			fi.read((char *) &p, sizeof(p));
			if(p.retpno()==no)
			{
			cout<<"PNO"<<"\t"<<"PRODUCT NAME"<<"\t"<<"PRICE"<<"\t"<<"DISCOUNT"<<"\n";
			cout<<p.retpno()<<"\t"<<p.retname()<<"\t\t"<<p.retprice()<<"\t"<<p.retdis()<<"\n";
			getch();
			flag++;
			}
		   }
	fi.close();
	if(flag==0)
	cout<<"\n\nRecord not found.";
	getch();
}
/********************************************************************/
void supermarket::modify_product()
{
	int no, flag=0;
	product p;
	fstream fio;
	long pos;
	clrscr();
	cout<<"\n\n\tTo modify.";
	cout<<"\n\n\tPlease enter the product no. of the product : ";
	cin>>no;
	fio.open("product.dat", ios::in | ios::out | ios::binary);
	while((!fio.eof()) && (flag==0))
	{

			pos=fio.tellg();
			fio.read((char *) &p, sizeof(p));
			if(p.retpno()==no)
			{
			cout<<"PNO"<<"\t"<<"PRODUCT NAME"<<"\t"<<"PRICE"<<"\t"<<"DISCOUNT"<<"\n";
			cout<<"\tUpdating\n";
			cout<<p.retpno()<<"\t"<<p.retname()<<"\t\t"<<p.retprice()<<"\t"<<p.retdis()<<"\n";
			getch();
			p.create_product();
			fio.seekp(pos);
			fio.write((char*)&p,sizeof(p));
			cout<<"\n\n\tRecord updated.";
			flag++;
			}
		   }
	fio.close();
	if(flag==0)
	cout<<"\n\nRecord not found.";
	getch();
}
/***************************************************************/
void supermarket::delete_product()
{       ifstream fin;
	product p;
	int flag=0;
	int no;
	clrscr();
	cout<<"\n\n\n\tDelete Record.";
	cout<<"\n\nPlease enter the product no. of the product you want to delete : ";
	cin>>no;
	fin.open("product.dat",ios::in | ios::binary);
	fstream fio;
	fio.open("Temp.dat",ios::out |ios::in | ios::binary);
	fin.seekg(0,ios::beg);
	while((!(fin.eof())) && (fin.read((char *) &p, sizeof(product))))
	{
		if(p.retpno()!=no)
		{
		 fio.write((char*)&p,sizeof(product));
		 flag++;
		}
	}
	fio.close();
	fin.close();
	remove("product.dat");
	rename("Temp.dat","product.dat");
	cout<<"\n\n\tRecord Deleted.";
	getch();
}
/****************************************************************/
void main()
{
supermarket s1;
s1.intro();
int ch=0;
do
{
menu:
clrscr();
cout<<"\n\n\n\tMAIN MENU";
cout<<"\n\n\n\t1. CUSTOMER.";
cout<<"\n\n\n\t2. ADMIN.";
cout<<"\n\n\n\t3. EXIT.";
cout<<"\n\n\n\tPlease select your option (1-3) : ";
cin>>ch;
xyz:
switch(ch)
{
case 1:
clrscr();
s1.place_order();
getch();
break;
case 2:
int x=s1.readuser();
if(x==1)
  {
   int p=s1.readpass();
  if(p==1)
    {
    s1.admin_menu();
    }
  }
else
  {
    cout<<"\n\n\t WRONG PASSWORD OR USERNAME";
    cout<<"\n\n\tPLEASE RE-ENTER THE PASSWORD";
    s1.readpass();
  }
break;
case 3:
exit(0);
break;
}
}while(ch<=3);
}
/*********************************************************/