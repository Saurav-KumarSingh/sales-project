#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<windows.h>
using namespace std;
int col(int a)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleTextAttribute(h,a);
}
class Item
{
    private:
     int code;
     char fruitname[30];
     int qty;
    public:
        void get_item();
        void put_item();
        int get_Code()
        {
        return code;

        }
        int update_qty(int num)
        {
            qty=qty-num;
        }
};
void Item::get_item()
{
cout<<"Enter Fruit code , Name and quantity (in kg)\n";
cin>>code>>fruitname>>qty;

}
void Item::put_item()
{
   cout<<"\t\t|"<<setw(4)<<code<<setw(4)<<"|"<<setw(13)<<fruitname<<setw(7)<<"|"<<setw(6)<<qty<<setw(6)<<"|"<<endl;
   cout<<"\t\t-----------------------------------------\n";
}
void addRecord();
void deleteRecord();
void showRecord();
void showAll();
void modifyRecord();
Item it;
fstream file;
int main()
{
    char option;
    string choice="yes",fruitname;
    system("color F5");
    cout<<"-----------------------------------------------------------------------------------------------------------------------------\n\n";
    cout<<"************************************************* WELCOME TO OUR FRUIT SHOP *************************************************";
    cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------------\n\n";
  string more;
  cout << "Enter the customer name :  ";
  getline(cin,fruitname);
    system("cls");
    do
    {
    
    system("color A1");
    cout<<"\n=================================================";
    cout<<"\n| A add the fruit\t\t\t\t|";
    cout<<"\n| B display all fruit which is bought\t\t|";
    cout<<"\n| C display single record\t\t\t|";
    cout<<"\n| D delete Record\t\t\t\t|";
    cout<<"\n| E update the record\t\t\t\t|";
    cout<<"\n=================================================";
    cout<<"\nEnter your choice :\n";
    cin>>option;
    cout<<"\n\n";
    switch (option)
    {
        
    case 'A':
        system("color B0");
        addRecord();
        system("managebill");
        system("payment_method");
        break;
    case 'B':
         system("color 94");
         showAll();
         break;
    case 'C':
         system("color D2");
         showRecord();
         break;
    case 'D':
         system("color C2");
         deleteRecord();
         break;
    case 'E':
         system("color E6");
         modifyRecord();
         break;
           
    default:
       cout<<"Invalid option";
        break;
    }
 cout<<"\n\n------------------------------------------------------------------------------------------------------------------\n\n\n";
 cout<<"do you want to do another operation yes or no\n"; 
 cin>>choice;
    }  
while(choice=="yes"||choice=="YES"||choice=="Yes");
cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------------\n\n";
cout<<"\n******************************************* THANK YOU FOR VISITING OUR FRUIT SHOP *******************************************\n\n";
cout<<"\n-----------------------------------------------------------------------------------------------------------------------------\n\n";
}

void addRecord()
{
    string ch="yes";
        cout<<"******************** Menu **********************\n"<<endl;
        cout<<"code\t"<<"fruit\n\n";
        cout<<"________________________________________________\n";
        cout<<"1\t Mango\n";
        cout<<"________________________________________________\n";
        cout<<"2\t Grapes\n";
        cout<<"________________________________________________\n";
        cout<<"3\t Watermelon\n";
        cout<<"________________________________________________\n";
        cout<<"4\t Coconut\n";
        cout<<"________________________________________________\n";
        cout<<"5\t Strawberry\n";
        cout<<"________________________________________________\n";
        cout<<"6\t Banana\n";
        cout<<"________________________________________________\n";
        cout<<"7\t Apple\n\n";
        cout<<"***********************************************\n\n\n";

    file.open("stock.dat",ios::app|ios::binary);
    while(ch=="yes" || ch=="YES"||ch=="Yes"||ch=="y"||ch=="Y")
    {
        it.get_item();
        file.write((char*)&it,sizeof(it));
        cout<<"do you want to bye more things yes or no\n";
        cin>>ch;
    }
    file.close();
    }
    void showAll()
    {
     file.open("stock.dat",ios::in|ios::binary);
     if(!file)
     {
        cout<<"file not open\n";
        exit(0);
     }
     else
     {
        cout<<"\t\t*=======================================*\n";
        cout<<"\t\t|  Code       Fruit Name       Quantity |\n";
        cout<<"\t\t*=======================================*\n";
        file.read((char*)&it,sizeof(it));
        while(!file.eof())
        {
            it.put_item();
            file.read((char*)&it,sizeof(it));
        }
     }
     file.close();
    }
    void showRecord()
    {
     int no,flag=0;
     file.open("stock.dat",ios::in|ios::binary);
     if(!file)
     {
        cout<<"file not open\n";
        exit(0);
     }
     else
     {
        cout<<"Enter the code to search the record\n";
        cin>>no;
        file.read((char*)&it,sizeof(it));
        while(!file.eof())
        {
            if(no==it.get_Code())
            {
                flag=1;
                cout<<"-------------------------------------------------------------------------------------\n\n";
                cout<<"\t\t_________________________________________\n";
                cout<<"\t\t   Code       Fruit Name       Quantity  \n";
                cout<<"\t\t_________________________________________\n";
                it.put_item();
            }
            file.read((char*)&it,sizeof(it));
        }
        if(flag==0)
        {
            cout<<"No Item found\n";
        }
     }
     file.close();
    }
    void deleteRecord()
{
   int no;
   cout<<"Enter the  code to delete The item\n";
   cin>>no;
   ofstream file2;
   file2.open("new.dat",ios::out|ios::binary);
   file.open("stock.dat",ios::in|ios::binary);
   if(!file)
   {
    cout<<"file no exists\n";
   }
   else
    {
    file.read((char*)&it,sizeof(it));
    while(!file.eof())
    { if(no!=it.get_Code())
    {
        file2.write((char*)&it,sizeof(it));
    }
    
     file.read((char*)&it,sizeof(it));
    }
     file2.close();
     file.close();
     remove("stock.dat");
     rename("new.dat","stock.dat");
    }
}
    void modifyRecord()
{
 int no,num;
 cout<<"Enter the item code which you want to modify\n";
 cin>>no;
 cout<<"Enter the item which you want to issued\n";
 cin>>num;
 file.open("stock.dat",ios::in|ios::out|ios::binary);
 if(!file)
 {
    cout<<"file not found";
 }
 while(file.read((char*)&it,sizeof(it)))
 {
  if(it.get_Code()==no)
  {

    it.update_qty(num);
    int pos=sizeof(it);
    file.seekp(-pos,ios::cur);
    file.write((char*)&it,sizeof(it));
  }

 }
 file.close();

}