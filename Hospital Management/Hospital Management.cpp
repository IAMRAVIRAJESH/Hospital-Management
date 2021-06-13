#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<windows.h>
void menu();
void passcode();
void cpasscode();
using namespace std;
class one
{
    public:
    virtual void get()=0;
    virtual void show()=0;
};
class info:public one
{
    public:
    char name[50],time[50];
    int num,age;
    void get()
    {
        system("cls");
        cin.sync();
        cout<<"\n Pateint name:";
        cin.getline(name,50);
        cout<<"\n Appointment Time:";
        cin.getline(time,50);
        cout<<"\n Age:";
        cin>>age;
        cout<<"\n Appointment Number:";
        cin>>num;
    }
    void show()
    {
        cout<<"\nName:"<<name;
        cout<<"\nAge:"<<age;
        cout<<"\nNumber:"<<num;
        cout<<"\nTime:"<<time;
    }
};
class ravi:public info
{
    public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("ravi.txt",ios ::app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"\nEntry has been saved.";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("ravi.txt");
        if(in==NULL)
        {
            cout<<"\n\nNo data in the file";
            cout<<"\n\n\tPress any key to continue:";
            getch();
            menu();
        }
        else
        {
            while(!in.eof())
            {
                in.read((char*)&a1,sizeof(a1));
                a1.show();
            }
            in.close();
            getch();
            menu();
        }
    }
};
class king:public info
{
     public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("king.txt",ios ::app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"\nEntry has been saved.";
        getch();
        menu();
    }
    void show()
    {
     ifstream in("king.txt");
        if(in==NULL)
        {
            cout<<"\n\nNo data in the file";
            cout<<"\n\n\tPress any key to continue:";
            getch();
            menu();
        }
        else
        {
            while(!in.eof())
            {
                in.read((char*)&a1,sizeof(a1));
                a1.show();
            }
            in.close();
            cout<<"Press enter to continue:";
            getch();
            menu();
        }
    }
}; 
class dang:public info
{
     public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("dang.txt",ios ::app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"\nEntry has been saved.";
        getch();
        menu();
    }
    void show()
    {
     ifstream in("dang.txt");
        if(in==NULL)
        {
            cout<<"\n\nNo data in the file";
            cout<<"\n\n\tPress any key to continue:";
            getch();
            menu();
        }
        else
        {
            while(!in.eof())
            {
                in.read((char*)&a1,sizeof(a1));
                a1.show();
            }
           in.close();
        }
    }
};
class staff:public one
{
    public:
    char all[999];
    char name[50],age[20],sal[30],pos[20];
    void get()
    {
        ofstream out("staff.txt",ios::app);
        {
            system("cls");
            cin.sync();
            cout<<"\n Name:";
            cin.getline(name,50);
            cout<<"\n Age:";
            cin.getline(age,20);
            cout<<"\n Salary:";
            cin.getline(sal,30);
            cout<<"\n Position:";
            cin.getline(pos,20);
        }
        out<<"\nName:" <<name<<"\nAge:"<<age<<"\nSalary:"<<sal<<"\nPosition:"<<pos;
        out.close();
        cout<<"\n\n Your information has been saved:\n\t\t\tPress any key to continue.";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("staff.txt");
        if(!in)
        {
            cout<<"File open error";
        }
        while(!(in.eof()))
        {
            in.getline(all,999);
            cout<<all<<endl;
        }
        in.close();
        cout<<"\n\n\t\t\tPress any key to continue:";
        getch();
        menu();
    }
};
class information
{
    public:
    void drinfo()
    {
        system("cls");
        system("color F3");
        cout<<"\n==============================================================================\n";
        cout<<"\n\t\t(3 doctors are available)\n\n\t[Information and timing are given below:]\n";
        cout<<"\n==============================================================================\n";
        cout<<"\t\tAvailable Doctors:\n";
        cout<<"------------------------------------------------------------------------------\n";
        cout<<"\t\tDr. RAVI (skin specialist)\n\n";
        cout<<"\t\t\t[[Timing]]:\n\n";
        cout<<"\tMonday to Friday\t\t9AM to 5PM\n";
        cout<<"\tSaturday        \t\t9AM to 1PM\n";
        cout<<"\tSunday          \t\tOFF\n";
        cout<<"\n---------------------------------------------------\n";
         cout<<"\t\tDr. KING (child specialist)\n\n";
        cout<<"\t\t\t[[Timing]]:\n\n";
        cout<<"\tMonday to Friday\t\t2PM to 10PM\n";
        cout<<"\tSaturday        \t\t8AM to 1PM\n";
        cout<<"\tSunday          \t\t12PM to 9PM\n";
        cout<<"\n---------------------------------------------------\n";
         cout<<"\t\t\tDr. DANG (DVM)\n\n";
        cout<<"\t\t\t[[Timing]]:\n\n";
        cout<<"\tMonday to Friday\t\t8AM to 5PM\n";
        cout<<"\tSaturday       \t\t\t10AM to 1PM\n";
        cout<<"\tSunday         \t\t\tOFF\n";
        cout<<"\n---------------------------------------------------\n";
        cout<<"\nPress any key to continue";
        getch();
        menu();
    }
};
void call_dr()
{
    system("cls");
    int choice;
    cout<<"\nSelect doctor:";
    cout<<"\n\n\t\t1 for Dr. Ravi";
	cout<<"\n\n\t\t2 for Dr. KING";
	cout<<"\n\n\t\t3 for Dr. DANG";
    cin>>choice;
    one *ptr;
    ravi s3;
    king s4;
    dang s5;
    if(choice==1)
    {
        ptr=&s3;
        ptr->get();
    }
    if(choice==2)
    {
        ptr=&s4;
        ptr->get();
    }
    if(choice==3)
    {
        ptr=&s5;
        ptr->get();
    }
    else
    {
        cout<<"Sorry invalid choice";
    }
}
void pinfoshow()
{
    system("cls");
    int choice;
    cout<<"\nSelect doctor:";
    cout<<"\n\n\t\t1 for Dr. Ravi";
	cout<<"\n\n\t\t2 for Dr. KING";
	cout<<"\n\n\t\t3 for Dr. DANG";
    cin>>choice;
    one *ptr;
    ravi s3;
    king s4;
    dang s5;
    if(choice==1)
    {
        ptr=&s3;
        ptr->show();
    }
    if(choice==2)
    {
        ptr=&s4;
        ptr->show();
    }
    if(choice==3)
    {
        ptr=&s5;
        ptr->show();
    }
    else
    {
        cout<<"Sorry invalid choice";
        getch();
        menu();
    }
}
void menu()
{
    system("cls");
    system("Color FC");
    cout<<"\n";
    cout<<"\n";
    cout<<"\t\t\t\t\t|===========================================|\n";
    cout<<"\t\t\t\t\t|--------------Fortis Hospital--------------|\n";
    cout<<"\t\t\t\t\t|===========================================|\n";
    cout<<"\n\t\t\t\t\t                 MAIN MENU\n";
     cout<<"\t\t\t\t\t                -----------\n";
    cout<<"\n\n\t1-Available Doctor's information\n\n";
    cout<<"\t2-Doctor appointment\n\n";
    cout<<"\t3-Save Staff Information\n\n";
    cout<<"\t4-Check pateint appointment menu\n\n";
    cout<<"\t5-Check Staff information menu\n\n";
    cout<<"\t6-Change password\n\n";
    cout<<"\t7-Logout\n";
    cout<<"\n\n\tPlease enter your choice:";
    information a1;
    one *ptr;
    staff a2;
    int a;
    cin>>a;
    if(a==1)
    {
        a1.drinfo();
    }
    else if(a==2)
    {
        call_dr();
    }
    else if(a==3)
    {
        ptr=&a2;
        ptr->get();
    }
    else if(a==4)
    {
        pinfoshow();
    }
    else if(a==5)
    {
        ptr=&a2;
        ptr->show();
    }
    else if(a==6)
    {
        cpasscode();
    }
    else if(a==7)
    {
        passcode();
    }
    else
    {
        cout<<"Sorry invalid choice:";
    }
};
void passcode()
{
    system("cls");
    char p1[50],p2[50],p3[50];
    system("color FC");
    ifstream in("password.txt");
    {
        cin.sync();
        cout<<"\n\n\n\n\n\n\n\t\t\tEnter the password:";
        cin.getline(p1,50);
        in.getline(p2,50);
        if(strcmp(p2,p1)==0)
        {
            menu();
        }
        else
        {
            cout<<"\n\n\t\t\tIncorrect password please try again.";
            Sleep(999);
            passcode();
        }
    }
    in.close();
}
void cpasscode()
{
    char n[50];
    system("cls");
    ofstream out("password.txt");
    {
        cin.sync();
        cout<<"\n\n\n\n\t\t\tEnter the new password:";
        cin.getline(n,50);
        out<<n;
    }
    out.close();
    cout<<"\n\nYour password has been saved.";
    getch();
    menu();
}
int main()
{
    passcode();
    system("pause");
}
