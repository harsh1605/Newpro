#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>


			class supplier                       //class for supplier
			{          int sup_id;
				   char sup_name[20];
				   char sup_no[10];
				   char city[15];
			public:    int unit;

				void i1()                      //input function for supplier
				{ cout<<"Enter The Supplier ID:- ";
				  cin>>sup_id;
				  cout<<"Enter The Supplier Name:- ";
				  gets(sup_name);
				  cout<<"Enter The City Of Supplier:- ";
				  gets(city);
				  cout<<"Enter The Supplier Mobile Number:- ";
				  cin>>sup_no;
				  cout<<"Enter The Units Supplied:- ";
				  cin>>unit;
				}

				void o1()                     //output function for supplier
				{ cout<<"Supplier ID:- "<<sup_id<<"\n";
				  cout<<"Supplier Name:- ";
				  puts(sup_name);
				  cout<<"Supplier's City:- ";
				  puts(city);
				  cout<<"Supplier's Contact Number:- "<<sup_no<<"\n";
				  cout<<"Units Supplied:- "<<unit<<"\n";
				}

				int sid()             //function to return supplier id
				{  return sup_id;}

			};

			    class customer               //class for customer
			    {         int bno;        //bill number
				      char cust_name[20];
				      char mname[20];
				      int medi_qunty;
				      float medi_cost;
				      float medi_tot;

				      void medicinetotal()             //function for calculate the total
				      { medi_tot=medi_cost*medi_qunty;
				      }

			    public:
				    void i3()                     //input function for customer
				    { cout<<"Enter the bill number:-";
				      cin>>bno;
				      cout<<"Enter The Customer Name:- ";
				      gets(cust_name);
				      cout<<"Enter The Name Of Medicine Purchased:- ";
				      gets(mname);
				      cout<<"Enter The Quantity Purchased:- ";
				      cin>>medi_qunty;
				      cout<<"Enter The Cost Of Medicine:- ";
				      cin>>medi_cost;
				      medicinetotal();

				    }

				     void o3()                    //output function for customer
				    { cout<<"Bill Number:- "<<bno<<"\n";
				      cout<<"Customer Name:- ";
				      puts(cust_name);
				      cout<<"Medicine Name:- ";
				      puts(mname);
				      cout<<"Quantity Purchased:- "<<medi_qunty<<"\n";
				      cout<<"Cost Of 1 Medicine:- "<<medi_cost<<"\n";
				      cout<<"Total Cost Of Medicine Purchased:- "<<medi_tot<<"\n"<<endl;
				    }

				     int getid()                  //function to return bill number
				     { return bno;
				     }

				     int qunty()                 //function to return medicine quantity
				     { return medi_qunty; }


			};





			class medicine:public supplier         //class for medicine
			{            char medi_name[30];
				     int rk;       //rack number
				     char ltr;     //letter name
				     float cost;
				     float total;
				     char edate[10];     //expiry date
				     char mdate[10];     //manufacture date
				     int quantity;

				     char letter()
				   {  char c;
				      c=medi_name[0];
				      return c;
				   }

				   float tot()
				   {  float f;
				      f=cost*unit;
				      return f;
				   }

				   customer c;

			public:     medicine()
				   {  cost=0.0;
				      total=0.0;
				     quantity=unit;
				   }

				   void i2()                    //input function for medicine
				   { i1();
				     cout<<"Enter The Medicine Name:- ";
				     gets(medi_name);
				     cout<<"Enter The Rack Number:- ";
				     cin>>rk;
				     ltr=letter();
				     cout<<"Enter The Cost Of 1 Medicine:- ";
				     cin>>cost;
				     total=tot();
				     medicine_qty();
				     chkqunty();
				     cout<<"Enter The Manufacturing Date Of The Medicine (MM/YY):- ";
				     gets(mdate);
				     cout<<"Enter The Expiry Date Of The Medicine (MM/YY):- ";
				     gets(edate);
				   }

				   void o2()                      //output function for medicine
				   { o1();
				     cout<<"Medicine Name:- ";
				     puts(medi_name);
				     cout<<"Rack Number:- "<<rk<<"\n";
				     cout<<"Letter Rack:- "<<ltr<<"\n";
				     cout<<"Cost Of 1 Medicine:- "<<cost<<"\n";
				     cout<<"Manufacturing Date:- ";
				     puts(mdate);
				     cout<<"Expiry Date:- ";
				     puts(edate);
				     cout<<"Quantity Left:- "<<quantity<<"\n";
				     cout<<"Total Cost Of Product:- "<<total<<"\n"<<endl;
				   }

				   void medicine_qty()
				   { int i;
				     i=c.qunty();
				     quantity=quantity-i;
				   }
				  void chkqunty();

			};

		  void medicine:: chkqunty()
				   { if(quantity<1)
				      quantity=0;
				   }


		  medicine m;
		  customer c;



   void insmedi()                   //function for insert a record
   {
      clrscr();
     ofstream ofs("medi.dat",ios::app);
     m.i2();
     ofs.write((char*)&m,sizeof(m));
     ofs.close();
     cout<<"Your record has been created\n";
     getch();
    }


    void inscust()                   //function for insert a record
    { clrscr();
       ofstream ofs("cust.dat",ios::app);
       c.i3();
       ofs.write((char*)&c,sizeof(c));
      ofs.close();
      cout<<"Your record has been created\n";
      getch();
    }



    void searchmedi()                     //function for search a record
    {
       clrscr();
       int a,p=0;
       cout<<"Enter the supplier id that you want to search:";
       cin>>a;
       ifstream ifs("medi.dat",ios::in|ios::nocreate);
       while(ifs.read((char*)&m,sizeof(m)))
       {
	   ifs.read((char*)&m,sizeof(m));
	   if(m.sid()==a)
	   {
	       m.o2();p=1;
	       break;
	       if(ifs)break;
	   }
       }      ifs.close();
       if(p!=1)
       cout<<"NO SUCH RECORD EXISTS\n";
       getch();
    }


    void searchcust()                     //function for search a record
    {
       clrscr();
       int a,p=0;
       cout<<"Enter the bill number that you want to search:";
       cin>>a;
       ifstream ifs("cust.dat",ios::in|ios::nocreate);
       while(ifs.read((char*)&c,sizeof(c)))
       {
	   ifs.read((char*)&c,sizeof(c));
	   if(c.getid()==a)
	   {
	       c.o3();p=1;
	       break;
	       if(ifs)break;
	   }
       }     ifs.close();
       if(p!=1)
       cout<<"NO SUCH RECORD EXISTS\n";
       getch();
    }

     void searchmedi1()                     //search for all record
    {
       clrscr();
       int a,p=0;
       ifstream ifs("medi.dat",ios::in|ios::nocreate);
       while(ifs.read((char*)&m,sizeof(m)))
       {
	   ifs.read((char*)&m,sizeof(m));
	       m.o2();p=1;
       }     ifs.close();
       if(p!=1)
       cout<<"NO RECORD EXISTS\n";
       cout<<"press enter to see customer details:";
       getch();
    }


    void searchcust1()                     //search for all record
    {
       clrscr();
       int a,p=0;
       ifstream ifs("cust.dat",ios::in|ios::nocreate);
       while(ifs.read((char*)&c,sizeof(c)))
       {
	   ifs.read((char*)&c,sizeof(c));
	       c.o3();p=1;
       }     ifs.close();
       if(p!=1)
       cout<<"NO RECORD EXISTS\n";
       getch();
    }

    void modifymedi()             //function for update a record
    {
       clrscr();
       int a,d=0;
       cout<<"For modifying a record\n";
       cout<<"\nEnter the supplier id that you want to modify:";
       cin>>a;
       ifstream ifs("medi.dat",ios::in|ios::nocreate);
       ofstream ofs("new.dat",ios::app);
       while(ifs.read((char*)&m,sizeof(m)))
       {
	    ifs.read((char*)&m,sizeof(m));
	    if(m.sid()!=a)
	    {
	       ofs.write((char*)&m,sizeof(m));
	    }
	    else
	      d++;
		    ofs.close();
       }
       if(d=0)
       cout<<"\nSorry no record found\n";
       else
       {
	  ofstream ofs("new.dat",ios::app);
	  cout<<"\nEnter the new values:";
	  m.i2();
	  ofs.write((char*)&m,sizeof(m));
	  ofs.close();
       }
       ifs.close();
       remove("medi.dat");
       rename("new.dat","medi.dat");
       cout<<"\nYour record has been modified\n";
       getch();
    }


    void modifycust()             //function for update a record
    {
       clrscr();
       int a,d=0;
       cout<<"For modifying a record\n";
       cout<<"\nEnter the bill number that you want to modify:";
       cin>>a;
       ifstream ifs("cust.dat",ios::in|ios::nocreate);
       ofstream ofs("new.dat",ios::app);
       while(ifs.read((char*)&c,sizeof(c)))
       {
	    ifs.read((char*)&c,sizeof(c));
	    if(c.getid()!=a)
	    {
	       ofs.write((char*)&c,sizeof(c));
	    }
	    else
	      d++;
		    ofs.close();
       }
       if(d!=0)
       cout<<"\nSorry no record found";
       else
       {
	  ofstream ofs("new.dat",ios::app);
	  cout<<"\nEnter the new values:";
	  c.i3();
	  ofs.write((char*)&c,sizeof(c));
	  ofs.close();
       }
       ifs.close();
       remove("cust.dat");
       rename("new.dat","cust.dat");
       cout<<"\nYour record has been modified";
       getch();
    }

    void delmedi()                      //function for delete a record
    {
	clrscr();
	int a,p=1;
	cout<<"Enter the supplier id that you want to delete:";
	cin>>a;
	ifstream ifs("medi.dat",ios::in|ios::nocreate);
	ofstream ofs("new.dat");
	while(ifs.read((char*)&m,sizeof(m)))
	{
		ifs.read((char*)&m,sizeof(m));
		if(m.sid()!=a)
		{
		    ofs.write((char*)&m,sizeof(m));
		}
		else
		{ p=0;}
	}
	ifs.close();
	ofs.close();
	if(p==0)
	remove("medi.dat");
	rename("new.dat","medi.dat");
	cout<<"Record has been deleted\n";
	getch();
    }


     void delcust()                      //function for delete a record
    {
	clrscr();
	int a;
	cout<<"Enter the bill number that you want to delete:";
	cin>>a;
	ifstream ifs("cust.dat",ios::in|ios::nocreate);
	ofstream ofs("new.dat");
	while(ifs.read((char*)&c,sizeof(c)))
	{
		ifs.read((char*)&c,sizeof(c));
		if(c.getid()!=a)
		{
		    ofs.write((char*)&c,sizeof(c)); break;
		}
		else
		{
		    cout<<"NO RECORD FOUND\n";
		}
	}

	ifs.close();
	ofs.close();
	remove("cust.dat");
	rename("new.dat","cust.dat");
	cout<<"Record has been deleted\n";
	getch();
    }

    void delmedi1()                      //function for delete all record
    {
	clrscr();
	ifstream ifs("medi.dat",ios::in|ios::nocreate);
	ofstream ofs("new.dat");
	ifs.close();
	ofs.close();
	remove("medi.dat");
	rename("new.dat","medi.dat");
	cout<<"Record has been deleted\n";
	getch();
    }


     void delcust1()                      //function for delete all record
    {
	clrscr();
	ifstream ifs("cust.dat",ios::in|ios::nocreate);
	ofstream ofs("new.dat");
	ifs.close();
	ofs.close();
	remove("cust.dat");
	rename("new.dat","cust.dat");
	cout<<"Record has been deleted\n";
	getch();
    }



    void main()
    {
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\*************************************************";
     cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t****THE MEDICINE MANAGEMENT****";
     cout<<"\n\n\n\n\n\n\n\n\n\n\t\t**************************************************\n\n\n";
     getch();
    int a;
    char choice;
    do
	{   clrscr();
	    cout<<"\n\n\n\t\t\tMEDICAL STORE MANAGEMENT\n";
	    cout<<"*************************************************************************\n\n";
	    cout<<"\t\t1.  Medicine Details \n";
	    cout<<"\t\t2.  Modify Details\n";
	    cout<<"\t\t3.  Search Particular Details\n";
	    cout<<"\t\t4.  Search All Details\n";
	    cout<<"\t\t5.  Delete Particular Details\n";
	    cout<<"\t\t6.  Delete All Details\n";
	    cout<<"\t\t7.  Exit\n";
	    cout<<"Enter your choice:";
	    cin>>a;
	    switch(a)
	    {
	  case 1:  { char c;
			 do
			{
			int ch;
		    cout<<"************************************************************************\n\n";
		    cout<<"\t\t1.  TO INSERT THE MEDICINE DETAILS\n";
		    cout<<"\t\t2.  TO INSERT THE CUSTOMER DETAILS\n";
		    cin >>ch;
		       switch(ch)
		       {  case 1: insmedi();break;
			  case 2: inscust();break;
			  default: cout<<"your choice is incorrect\n";
		       }
		    cout<<"\nDO YOU WANT TO INSERT MORE RECORD\n";
		    cin>>c;
		    }
		    while(c=='y'||c=='Y');
		    }
		      break;

		  case 2:{ char c;
			do
		     { int ch;
		    cout<<"************************************************************************\n\n";
		    cout<<"\t\t1.  TO MODIFY THE SUPPLIER/MEDICAL DETAILS\n";
		    cout<<"\t\t2.  TO MODIFY THE CUSTOMER DETAILS\n";
		    cin >>ch;
		       switch(ch)
		       {  case 1: modifymedi();break;
			  case 2: modifycust();break;
			  default: cout<<"your choice is incorrect\n";
			  }
		     cout<<"Do you want to modify another record:\n";
		     cin>>c;
		 }
		 while(c=='y'||c=='Y'); }
		 break;
	  case 3:{ char c;
			do
		     { int ch;
		    cout<<"************************************************************************\n\n";
		    cout<<"\t\t1.  TO SEARCH THE SUPPLIER/MEDICAL DETAILS\n";
		    cout<<"\t\t2.  TO SEARCH THE CUSTOMER DETAILS\n";
		    cin >>ch;
		       switch(ch)
		       {  case 1: searchmedi();break;
			  case 2: searchcust();break;
			  default: cout<<"your choice is incorrect\n";
			  }
		     cout<<"Do you want to search another record:\n";
		     cin>>c;
		 }
		 while(c=='y'||c=='Y'); }
		 break;
	 case 4:{
		    cout<<"************************************************************************\n\n";

		       searchmedi1();
		       searchcust1();

		  }
		 break;
	  case 5:{char c;
			do
		   { int ch;
		    cout<<"************************************************************************\n\n";
		    cout<<"\t\t1.  TO DELETE THE SUPPLIER/MEDICAL DETAILS\n";
		    cout<<"\t\t2.  TO DELETE THE CUSTOMER DETAILS\n";
		    cin >>ch;
		       switch(ch)
		       {  case 1: delmedi();break;
			  case 2: delcust();break;
			  default: cout<<"your choice is incorrect\n";
			  }
		     cout<<"Do you want to delete another record:\n";
		     cin>>c;
		 }
		 while(c=='y'||c=='Y');}
		 break;
	   case 6:
		   {
		    cout<<"************************************************************************\n\n";

		     delmedi1();
		     delcust1();



		  }

		 break;
	  case 7:exit(0);break;
	  default:cout<<"Sorry you have choosen wrong option\n";
	}
	cout<<"Do you want to continue with main menu\n";
	cin>>choice;
    }
    while(choice=='y'||choice=='Y');
    cout<<"Thanks For Using\n";
    getch();
    }
