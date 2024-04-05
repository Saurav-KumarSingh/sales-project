#include<iostream>
#include<fstream>
using namespace std;
fstream file;
class Payment
{
    public:
    string fruitname,name;
    int amount,accountno,cvv,pin;

};
class Creditcard:public Payment
{
    public:
    string cname=name,bname=fruitname;
    int ca=amount,Cac=accountno,CVV=cvv,cpin=pin;
    Creditcard()
    {
        file.open("manage.dat",ios::out|ios::binary);
        cout<<"Enter bank name:\t";
        getline(cin,bname);
        cout<<"Enter your name:\t";
        getline(cin,cname);
        cout<<"Account number:\t\t";
        cin>>Cac;
        cout<<"CVV number:\t";
        cin>>CVV;
        cout<<"Pin:\t";
        cin>>cpin;
        cout<<"amount:\t";
        cin>>ca;
    }
};
class Debitcard:public Payment
{
    public:
     string dname=name,dbname=fruitname;
    int da=amount,Dac=accountno,DCVV=cvv,Dpin=pin;
    Debitcard()
    {
        file.open("manage.dat",ios::out|ios::binary);
        cout<<"Enter bank name:\t";
        getline(cin,dbname);
        cout<<"\nEnter your name:\t";
        getline(cin,dname);
        cout<<"Account number:\t\t";
        cin>>Dac;
        cout<<"CVV number:\t";
        cin>>DCVV;
        cout<<"Pin:\t";
        cin>>Dpin;
        cout<<"amount:\t";
        cin>>da;
    }

};
class NETbanking:public Payment
{
    public:
    string Nname=name,Nbname=fruitname;
    long long Na=amount,Nac=accountno,Npin=pin,KYC;

    NETbanking()
    {
        file.open("manage.dat",ios::out|ios::binary);
        cout<<"Enter bank name:\t";
        getline(cin,Nbname);
        cout<<"Enter your name:\t";
        getline(cin,Nname);
        
        cout<<"KYC:\t";
        cin>>KYC;
        cout<<"Account number:\t";
        cin>>Nac;
        cout<<"Pin:\t";
        cin>>Npin;
        cout<<"amount:\t";
        cin>>Na;
    }
};
class UPI:public Payment
{
    public:
    string Uname=name,Ubname=fruitname;
    long long Ua=amount,Uac=accountno,Upin=pin;

    UPI()
    {
        file.open("manage.dat",ios::out|ios::binary);
        cout<<"Enter bank name:\t";
        getline(cin,Ubname);
        cout<<"Enter your name:\t";
        getline(cin,Uname);
        cout<<"Account number:\t\t";
        cin>>Uac;
        cout<<"Pin:\t";
        cin>>Upin;
        cout<<"amount:\t";
        cin>>Ua;
    }
};

class allpayement:public Creditcard,public Debitcard,public NETbanking,public UPI
{
    public:
    void show_all();
};
int main()
{
    system("color 74");
    string ctype;
        cout<<"#=======================================#\n";
        cout<<"|    Availble Payement Methods are      |\n";
        cout<<"*---------------------------------------*\n";
        cout<<"|    creditcard                         |\n";
        cout<<"*---------------------------------------*\n";
        cout<<"|    debitcard                          |\n";
        cout<<"*---------------------------------------*\n";
        cout<<"|    NET banking                        |\n";
        cout<<"*---------------------------------------*\n";
        cout<<"|    UPI                                |\n";
        cout<<"|=======================================|";
        cout<<"\n\nChoose payement method\t";
    getline(cin,ctype);
        cout<<"\n\n-----------------------------------------------------------------------------------------------\n";
    if(ctype=="Creditcard"||ctype=="creditcard")
        {
            Creditcard c;
        }
    else if(ctype=="Debitcard"||ctype=="debitcard")
        {
            Debitcard d;
        }
    else if(ctype=="NETbanking"||ctype=="netbanking"||ctype=="net banking"||ctype=="Net banking"||ctype=="Net Banking"||ctype=="net Banking")
        {
            NETbanking n;
        }
    else if(ctype=="UPI"||ctype=="upi")
        {
            UPI u;
        }
    
    cout<<"__________________Thank you for paying____________________\n\n";
}