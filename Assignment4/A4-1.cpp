// Q1. Write a class for Time and provide the functionality
// Time()
// Time(int h,int m,int s)
// getHour()
// getMinute()
// getSeconds()
// printTime()
// setHour()
// setMinute()
// setSeconds()
// In main create array of objects of Time.
// Allocate the memory for the array and the object dynamically.

#include<iostream>
using namespace std;

class Time
{
    private:
    int hr;
    int min;
    int sec;

   public:

    Time()
    {
        this->hr=0;
        this->min=0;
        this->sec=0;
    }

     Time(int hr,int min ,int sec)
    {
        this->hr=hr;
        this->min=min;
        this->sec=sec;
    }

     int  get_hr()
     {
        return this->hr;
     }
     int get_min()
     {
       return this->min;
     }
     int  get_sec()
     {
        return this->sec;
     }
      void printtime()
      {
        cout<<"time="<<this->hr<<":"<<this->min<<":"<<this->sec<<endl;
      }

      void set_hr()
      {
         cout<<"enter hour"<<endl;
         cin>>this->hr;
      }
      void set_min()
      {
         cout<<"enter minutes"<<endl;
         cin>>this->min;
      }
      void set_sec()
      {
         cout<<"enter seconds"<<endl;
         cin>>this->sec;
      }


};


int main ()
{
    int n;
        //take input from user how many objects to create
        cout<<"enter objects you want to create"<<endl;
        cin>>n;
        Time **arr= new Time *[n];
         
         for(int i=0;i<n;i++)
           arr[i]=new Time;

        
        for(int i=0;i<n;i++)
        {
            cout<<"enter time  for object"<<i<<endl;
            arr[i]->set_hr();
            arr[i]->set_min();
            arr[i]->set_sec();
        }
        for(int i=0;i<n;i++)
        {
            cout<<"time at index " <<i<<endl;
            arr[i]->printtime();
        }

        for(int i=0;i<n;i++)
            delete arr[i];
        delete[] arr;
    

}