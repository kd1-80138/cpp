// Q1. Write a user defined function factorial() that calculates factorial of given number and it throws
// exception if number entered by user is negative.

#include<iostream>
using namespace std;

double  fact(int num)
{
    double  total=1;
    if(num<=-1)
        throw "invalid input provided ";
    
    for(int i=2;i<=num;i++)
    {
        total*=i;
    }
    return total;
    
}


int main ()
{
    int num;
        cout <<"enter number to calculate factorial of "<<endl;
        cin>>num;
        double factorial;
    try
    {
        factorial=fact(num);
         cout<<"factorial of "<<num<<"is ="<<factorial<<endl;

        
    }
    catch(const char *error)
    {
        cout<<error<<endl;
    }
    
}