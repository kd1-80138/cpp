// Q2. Write a class to store Account information of Bank customer by using following class diagram.
// Use enum to store information of account type. Create an array of 5 Accounts in main() and accept
// their details from user. Write Menu driven program to deposit/withdraw amount from the account.
// After each transaction display updated account balance. Provide appropriate getters/setters with
// necessary validations. Throw exceptions for invalid values. Also implement an exception class
// InsufficientFunds. In withdraw() member function, if sufficient balance is not available
// in account, throw this exception.
#include<iostream>
using namespace std;
enum acc_type{
    saving=1,current,dmat
};

class Insufficient_funds
{
 private:
    int accid;
    double curr_balance;
    double withdraw_amt;
 public:
        Insufficient_funds(int accid,double curr_balance,double withdraw_amt)
        {
            this->accid=accid;
            this->curr_balance=curr_balance;
            this->withdraw_amt=withdraw_amt;
        }

        void display()
        {
            cout<<"account id="<<this->accid<<endl;
            cout<<"current calance="<<this->curr_balance<<endl;
            cout<<"withdraw amount="<<this->withdraw_amt;
            cout<<"insufficient Balance....."<<endl;
        }


};

class Account 
{
    private :
         int id;
         acc_type type;
         double balance;
    public:
    Account()
    {
        this->id=0;
        this->type=acc_type(1);
        this->balance=0;

    }
    Account(int id,acc_type type,double balance)
    {
        this->id=id;
        this->type=type;
        this->balance=balance;
    }
    void accept()
    {
        cout<<"select your account type "<<endl;
        cout<<"1-SAVING \n 2-CURRENT \n 3-DMAT"<<endl;
        int n;
        cin>>n;
        this->type= acc_type(n);
       cout<<"enter id"<<endl;
        cin>>this->id;
        cout<<"enter amount u want to deposite"<<endl;
        cin>>this->balance;
    }
    void  display()
    {
        cout<<"Account id ="<<this->id<<endl;
        cout<<"Account type= "<<this->type<<endl;
        cout<<" Balance= "<<this->balance<<endl;
    }
    void set_id(int id)
    {
        this->id=id;
    }
     void set_type(acc_type type)
    {
        this->type=type;
    }
     void set_balance(double balance )
    {
        this->balance=balance;
    }

    int get_id()
    {
        return this->id;

    }
    acc_type get_type()
    {
        return this->type;
    }
    double get_balance()
    {
        return this->balance;
    }

    void Deposite(double amt)
    {
        this->balance+=amt;

    }

    
      
};

void withdraw(Account **arr,int id,double amt,int indx)
    {
        for(int i=0;i<indx;i++)
        {
            if (arr[i]->get_id()==id)
            {
                if (arr[i]->get_balance()<amt)
                   throw new Insufficient_funds(id,arr[i]->get_balance(),amt);
                
                else
                {
                    arr[i]->set_balance(arr[i]->get_balance()-amt);
                    cout<<"debited succesfully....."<<endl;
                    arr[i]->display();
                }
            }

        }
    }


//display all accounts
void display_allacc(Account **arr,int indx)
{
    for(int i=0;i<indx;i++)
    {
        arr[i]->display();
        cout<<endl;
    }
}




int  menu()
 {
    int ch;
    cout<<endl;
    cout<<"************************************************************"<<endl;
    cout<<"0-EXIT"<<endl;
    cout<<"1- ADD Details"<<endl;
    cout<<"2-Withdraw "<<endl;
    cout<<"3-Display all accounts"<<endl;
    cin>>ch;
    cout<<"************************************************************"<<endl;

        return ch;
 }


int main ()
{
    Account *arr[5];
    int choice ;
   int  index=0;

    while((choice=menu())!=0)
    {
        switch (choice)
        {
            case 1:
                    arr[index]=new Account;
                    arr[index]->accept();

                    index++;
                    break;
            case 2:
               int iid;
               double amt;
              cout<<"Enter account id to Withdraw from "<<endl;
                cin>>iid;
                cout<<"enter amount to withdraw"<<endl;
                cin>>amt;
                cout<<endl;
                
                try
                {
                  
                withdraw(arr,iid,amt,index);
                    
                }
                catch(Insufficient_funds *iftr)
                {
                    iftr->display();
                }

                break;
            case 3:
                display_allacc(arr,index);

                break;
        }
    }
    for(int i=0;i<index;i++)
    {
        delete arr[i];
    }
    cout<<"Thank you for banking with us!!!................." <<endl;

}