// Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll.
// Mostly they do, but sometimes a car goes by without paying.
// The tollbooth keeps track of the number of cars that have gone by and of the total amount of money
// collected. Model this tollbooth with a class called tollbooth.
// The two data items are a type unsigned int to hold the total number of cars, and a type double to
// hold the total amount of money collected.
// A constructor initializes all data members to 0. A member function called payingCar() increments
// the car total and adds 0.50 to the cash total. An other function, called nopayCar()
// increments the car total but adds nothing to the cash total. Finally, a member function called
// printOnConsole() displays the two totals and number of paying as well as non paying cars total.
// ( write a menu driven code for it)'

#include<iostream>
using namespace std;
 class tollbooth
 {
    private:
      unsigned int hcar;
      double cmoney;
     
    public:
    tollbooth()
    {
        this->hcar=0;
        this->cmoney=0;
    }

    double get_cashtotal()
    {
        return cmoney;
    }

    unsigned int get_cartotal()
    {
        return hcar;
    }


    void payingcar()
    {
       this->hcar=this->hcar+1;
        this->cmoney=this->cmoney+0.5;
    
    }
    void nopaycar()
    {
        this->hcar=this->hcar+1;

    }
 };

  enum emenu{Exit,pay,nopay};

  emenu menu()
  {int choice;
    cout<<endl;
    cout<<"1-car has paid"<<endl;
    cout<<"2-car has not paid "<<endl;
    cout<<"0- exit"<<endl;
    cin>>choice;
     return emenu(choice);
  }

  int main ()
  {
    tollbooth t1;     // object declared //default constructor called
                   //sets value to zero;

    emenu ch;
    int ctotal ; 
    
    while ((ch=menu())!= Exit)
    {
        switch(ch)
        {
            case pay :  
             double t;       // car paid increment in cash_total
               t1.payingcar();
               t=t1.get_cashtotal();
               ctotal=t1.get_cartotal();

               
               cout<<"total cash collected = "<<t<<endl;
               cout<<"total cars passed "<<ctotal;
               break;
             
            case nopay:
               
                   t1.nopaycar();              //car not paid car total increament
                   ctotal= t1.get_cartotal();
                   cout<<"cars not paid = "<<ctotal;
                   break;

            default :
                   cout<<"enter valid choice"<<endl;
        }
    }
    cout<<"thank you for visiting ......."<<endl;
    
  }