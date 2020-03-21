#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);  
void gotoxy(short x, short y)                                          
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void fontsize(int a, int b){  
  PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();  
  lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
  GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
  lpConsoleCurrentFontEx->dwFontSize.X = a;  
  lpConsoleCurrentFontEx->dwFontSize.Y = b;  
  SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
 }  
class Doctor
{
	public:
	 int id;
	 string name;
	 string city;
	 string specialist;
	 void input()
	 {
	   gotoxy(20,0);
	   cout<<"Enter the details of the Doctor:";
	   gotoxy(20,1);
	   cout<<"--------------------------------";
	   gotoxy(20,4);
	   fflush(stdin);
	   cout<<"Enter the Your Name :";
	   cin>>name;
	   fflush(stdin);
	   gotoxy(20,6);
	   cout<<"Enter your City :";
	   cin>>city;
	   fflush(stdin);
	   gotoxy(20,8);
	   cout<<"Enter your specialization :";
	   cin>>specialist;
	   	
	 }	
};
class Patient
{
	public:
	 int id;
	 string name;
	 string city;
	 string disease;
	 string doctor_taken;
	 void input()
	 {
	   gotoxy(20,0);
	   cout<<"Enter the details of the Patient:";
	   gotoxy(20,1);
	   cout<<"--------------------------------";
	   gotoxy(20,4);
	   fflush(stdin);
	   cout<<"Enter the Your Name :";
	   cin>>name;
	   gotoxy(20,6);
	   fflush(stdin);
	   cout<<"Enter your City :";
	   cin>>city;
	   gotoxy(20,8);
	   fflush(stdin);
	   cout<<"Enter your disease from which the patient is suffering :";
	   cin>>disease;
	   gotoxy(20,10);
	   fflush(stdin);
	   cout<<"Enter your doctor from whom the patient is consulting :";
	   cin>>doctor_taken;	
	 }	
};
int main()
{
	fontsize(23,23);
A:   system("CLS");
   gotoxy(50,0);
   cout<<"Patient Electronic Health Record"<<endl;
   gotoxy(50,1);
   cout<<"---------------------------------"<<endl;
   gotoxy(50,12);
   cout<<"Enter 1 if You are a Doctor"<<endl;
   gotoxy(50,14);
   cout<<"Enter 2 if You are a Patient"<<endl;
   gotoxy(50,16);
   cout<<"Enter 3 For Exiting"<<endl;
   gotoxy(50,20);
   cout<<"Enter Your Choice :";
   int a;
   cin>>a;
   system("CLS");
   Patient p;
   Doctor d;
   ofstream fcout1("patient.txt",ios::app);
   ofstream fcout("doctor.txt",ios::app);
   ifstream fcout3;
   fcout3.open("id.txt");
   ofstream fcout4;
   fcout4.open("temp5.txt");
   ofstream fcout2("prescription.txt",ios::app);
   switch(a)
   {
   case 1: 
           gotoxy(50,0);
           cout<<"You Are Inside the Doctors Portal";
           gotoxy(50,1);
           cout<<"---------------------------------";
           gotoxy(50,12);
           cout<<"Enter 1 for Inserting Details of the New Doctor :";
           gotoxy(50,14);
           cout<<"Enter 2 for Updating Details of the Doctor :";
           gotoxy(50,16);
           cout<<"Enter 3 for Getting Details of the Doctor :";
           gotoxy(50,18);
           cout<<"Enter the Your Choice: ";
           int a1;
           cin>>a1;
           system("CLS");
           switch(a1)
           {
           case 1: {
		           d.input();
		           string a3;
		           gotoxy(20,12);
		           cout<<"Your Have a Generated an Id as :";
		           while(getline(fcout3,a3));
		           int a4=stoi(a3);
		           a4=a4+1;
		           cout<<a4;
		           fcout4<<a4;
		           fcout3.close();
		           fcout4.close();
		           remove("id.txt");
		           rename("temp5.txt","id.txt");
		           gotoxy(20,16);
		           fcout<<"UserID :";
		           fcout<<a4<<"    ";
		           fcout<<"Name :";
		           fcout<<d.name<<"     ";
		           fcout<<"City : ";
		           fcout<<d.city<<"     ";
		           fcout<<"Specialization :";
		           fcout<<d.specialist<<"     ";
		           fcout<<endl;
		           cout<<"Data Sucessfully Added"<<endl;
		           cout<<endl<<endl<<endl;
			       system("pause");
			  	   goto A;
				   break;
		       }
		    case 2:{
		    	   string s1;
		    	   cout<<"Name the ID whose data you want to Update :";
		    	   cin>>s1;
		    	   system("CLS");
		    	   ifstream myfile2;
		    	   myfile2.open("doctor.txt");
				   ofstream myfile1;
		    	   myfile1.open("temp.txt");
		    	   string line1;
		    	   gotoxy(20,4);
		    	   while(getline(myfile2,line1))
		    	   {
		    	   	if(line1.find(s1,0)==string::npos)
		    	   	{
		    	   	 myfile1<<line1<<endl;	
					}
				   }
				   d.input();
				   myfile1<<"UserId :";
				   myfile1<<s1<<" ";
		           myfile1<<"Name :";
		           fflush(stdin);
		           myfile1<<d.name<<"   ";
		           myfile1<<"City :";
		           myfile1<<d.city<<"   ";
		           fflush(stdin);
		           myfile1<<"Specialization :";
		           myfile1<<d.specialist;
		           myfile1<<endl;
		           fflush(stdin);
		           cout<<"Data Updated";
		           myfile1.close();
		           myfile2.close();
		           fcout.close();
		           remove("doctor.txt");
				   rename("temp.txt","doctor.txt");
				   cout<<endl<<endl<<endl;
			      system("pause");
				   goto A;
		           break;
		         }
		case 3:   {
		    	   string line;
		    	   string s;
		    	   gotoxy(50,0);
		    	   cout<<"Name the ID whose data you want to Fetch :";
		    	   cin>>s;
		    	   ifstream myfile21;
			       string filename="doctor.txt";
		    	   myfile21.open(filename);
		    	   gotoxy(50,6);
		    	   int count=0;
				   while(getline(myfile21,line))
		    	   {
		    	   	if(line.find(s)!=string::npos)
		    	   	{
		    	   		count=1;
		    	   	  	cout<<line<<endl;
					}
		           }
		           if(count==0)
				   {
				   	gotoxy(20,20);
				   	cout<<"Record Not Found "<<endl<<endl;
				   	system("pause");
				   	goto A;
				   }
			      myfile21.close();
			  }
		   }
		   cout<<endl<<endl<<endl;
			  system("pause");
		   goto A;
		   break;
   case 2:  
           gotoxy(50,0);
           cout<<"You Are Inside the Patients Portal";
           gotoxy(50,1);
           cout<<"---------------------------------";
           gotoxy(50,12);
           cout<<"Enter 1 for Inserting Details of the New Patient :";
           gotoxy(50,14);
           cout<<"Enter 2 for Updating Details of the Patient :";
           gotoxy(50,16);
           cout<<"Enter 3 for Getting Details of the Patient :";
           gotoxy(50,18);
           cout<<"Enter the Your Choice: ";
           cin>>a1;
           system("CLS");
      switch(a1)
           {
        case 1:
		       {
			   p.input();
			   string a3;
			   gotoxy(20,12);
			   cout<<"You Have a Generated an Id as :";
	           while(getline(fcout3,a3));
			   int a4=stoi(a3);
	           a4=a4+1;
	           cout<<a4;
	           fcout4<<a4;
	           fcout3.close();
	           fcout4.close();
	           remove("id.txt");
	           rename("temp5.txt","id.txt");
	           fcout1<<"User ID :";
	           fcout1<<a4<<"   ";
		       fcout1<<"Name :";
		       fcout1<<p.name<<"  ";
		       fcout1<<"City :";
		       fcout1<<p.city<<"  ";
		       fcout1<<"disease :";
		       fcout1<<p.disease<<"   ";    	   
		       fcout1<<"Consulted Doctor :";
		       fcout1<<p.doctor_taken<<endl;
		       string pres1;
		       gotoxy(20,14);
		       cout<<"Prescription Needed :";
		       fflush(stdin);
		       getline(cin,pres1);
		       fcout2<<"User ID :"<<a4<<"   ";
		       fcout2<<"Patient Name :"<<p.name<<"   ";
		       fcout2<<"Consulted Doctor :"<<p.doctor_taken<<"   ";
		       fcout2<<"Prescription : "<<pres1<<endl;
		       gotoxy(20,20);
		       cout<<"Data Inserted SucessFully";
		       cout<<endl<<endl<<endl;
			   system("pause");
			   goto A;
		       break;
		      }
		case 2:{
		    	   string s1;
		    	   cout<<"Name the ID whose data you want to Update :";
		    	   cin>>s1;
		    	   system("CLS");
		    	   ifstream myfile2,myfile3;
		    	   myfile2.open("patient.txt");
		    	   myfile3.open("prescription.txt");
				   ofstream myfile1,myfile4;
		    	   myfile1.open("temp.txt");
		    	   myfile4.open("temp1.txt");
		    	   string line1;
		    	   gotoxy(20,4);
		    	   int count=0;
				   while(getline(myfile2,line1))
		    	   {
		    	   	if(line1.find(s1,0)==string::npos)
		    	   	{
		    	   	 myfile1<<line1<<endl;	
					}
				   }
				   while(getline(myfile3,line1))
		    	   {
		    	   	if(line1.find(s1,0)==string::npos)
		    	   	{
		    	   	 myfile4<<line1<<endl;	
					}
				   }
				   p.input();
				   myfile1<<"User ID :";
				   myfile1<<s1<<"    ";
			       myfile1<<"Name :";
			       myfile1<<p.name<<"  ";
			       myfile1<<"City :";
			       myfile1<<p.city<<"   ";
			       myfile1<<"disease :";
			       myfile1<<p.disease<<"    ";    	   
			       myfile1<<"Consulted Doctor :";
			       myfile1<<p.doctor_taken<<endl;
			       string pres1;
			       gotoxy(20,12);
			       cout<<"Prescription Needed :";
			       fflush(stdin);
			       getline(cin,pres1);
			       myfile4<<"User ID :"<<s1<<"  ";
			       myfile4<<"Patient Name :"<<p.name<<"  ";
			       myfile4<<"Consulted Doctor :"<<p.doctor_taken<<"  ";
			       myfile4<<"Prescription : "<<pres1<<endl;
		           myfile4.close();
		           myfile1.close();
		           myfile2.close();
		           fcout1.close();
		           fcout2.close();
				   myfile3.close();
		           fflush(stdin);
				   remove("patient.txt");
				   rename("temp.txt","patient.txt");
		           remove("prescription.txt");
				   rename("temp1.txt","prescription.txt");
				   cout<<endl<<endl<<endl;
			       system("pause");
				   goto A;
				   break;
		         }
		case 3:   {
		    	   string s,line,line1;
		    	   gotoxy(50,0);
		    	   cout<<"Name the ID whose data you want to Fetch :";
		    	   cin>>s;
		    	   ifstream myfile21,myfile22;
			       string filename="patient.txt";
			       string filename1="prescription.txt";
		    	   myfile21.open(filename);
		    	   myfile22.open(filename1);
		    	   gotoxy(20,6);
		    	   int count=0;
				   while(getline(myfile21,line))
		    	   {
		    	   	if(line.find(s)!=string::npos)
		    	   	{
		    	   		count=1;
		    	   	  	cout<<line<<endl;
					}
		           }
		           if(count==0)
				   {
				   	gotoxy(20,20);
				   	cout<<"Record Not Found "<<endl<<endl;
				   	system("pause");
				   	goto A;
				   }
		           gotoxy(20,10);
		           while(getline(myfile22,line1))
		    	   {
		    	   	if(line1.find(s)!=string::npos)
		    	   	{
		    	   	  	cout<<line1<<endl;
					}
		           }
			      myfile21.close();
			      myfile22.close();
			  }
			  cout<<endl<<endl<<endl;
			  system("pause");
			  goto A;
		   break;
		   }
	case 3: gotoxy(50,12);
	        fontsize(28,28);
	        cout<<"Thank For Using"; 
	        cout<<endl<<endl<<endl<<endl;
	       exit(1);
       }
}
