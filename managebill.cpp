#include<iostream>
using namespace std;

double getprice(int itemCode);

int main()
{

  double price[10][4];
  int i=0; string more;
  
  do {
    
    
    system("color A5");
    cout << "\n\nagain write Item code and quantity: \n";

    cout<<"item code: ";
    cin >> price[i][0];
    cout << "Quantity : ";
    cin >> price[i][1];
    
    price[i][2] = getprice(price[i][0]); 
    price[i][3] = price[i][1] * price[i][2]; 
    
    cout << "\nHave you bought more fruit ?\n ";
    cin >> more;
  
    i++;
  } while(more =="YES"|more=="yes"|more=="Yes");
  
  cout << "-----------------------------------------------------------\nItemCode\tQuantity\tUnitPrice\tTotalPrice\n-----------------------------------------------------------\n";
  int tot=0;
  for(int k=0; k<i; k++)   
    
	{
		for(int l=0; l<4; l++) 
		{
		    cout << price[k][l]  << "\t\t";		   
		}
		cout << endl;
		tot = tot + price[k][3];
	}
  system("color 3");
  cout << "\n\n#################################";
  
  cout <<"\n#\tTotal :    " << tot<<"\t\t#";
  cout << "\n#################################\n\n\n";
  
  return 0;
}
double getprice(int itemCode)
{
  double price;
  switch (itemCode)
  {
    case 1: cout<<"mango\t\t"; price = 70;
      break; 
    case 2: cout<<"grapes\t\t"; price = 60;
      break;
    case 3: cout<<"watermelon\t\t"; price = 30;
      break;
    case 4: cout<<"coconut\t\t";price = 40; 
      break;
    case 5: cout<<"strawberry\t\t"; price=200;
      break;
    case 6: cout<<"banana\t\t"; price=30;
      break;
    case 7: cout<<"apple\t\t"; price=100;
      break;
    
    default: price = 0;
      break;
  }
  return price;
}