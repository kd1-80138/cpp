// Q1. Implement following classes. Test all functionalities in main().Insted of char[] use string
// datatype

#include<iostream>
using namespace std ;

class date
{
    private:
    int day;
    int month;
    int year;

    public:
     date()
     {
        this->day=0;
        this->month=0;
        this->year=0;
     }
     date(int day,int month,int year)
     {
        this->day=day;
        this->month=month;
        this->year=year;
     }

       int  get_day()
        {
            return  this->day;
        }
        int get_month()
        {
            return this->month;
        }
        int get_year()
        {
            return this->year;
        }
        void set_day(int day)
        {
            this->day=day;
        }
        void set_month(int month)
        {
            this->month=month;
        }

       void set_year(int year)
        {
            this->year=year;
        }
     void display()
     {
        cout<<"date="<<this->day<<"/"<<this->month<<"/"<<this->year<<endl;
     }

     void accept()
     {
        cout<<"enter day"<<endl;
        cin>>this->day;
        cout<<"enter month"<<endl;
        cin>>this->month;
        cout<<"enter year"<<endl;
        cin>>this->year;
     }


    bool is_leap()
    {
        if(this->year%4==0 && this->year%100!=0 )
        return true;

        return false;
    }
};

class person 
{
    private :
      string name ;
      string address;
      date dob;
    public:
      person()
      {
        this->name="";
        this->address="";
      }
      person(string name, string address)
      {
        this->name= name ;
        this->address= address;

      }
      string get_name()
      {
        return this->name ;

      }
      string get_address()
      {
        return this->address ;
      } 
      void set_name(string name)
      {
        this->name =name ;

      }
      void set_add(string address)
      {
        this->address=address;
      }
      date get_dob()
      {
        return dob;
      }
      void set_dob(date dob)
      {
        this->dob=dob;
        // dob.set_day(day);
        // dob.set_month(m);
        // dob.set_year(y);
      }
      void accept()
      {
        cout <<"enter name of employee"<<endl;
        cin>>this->name ;
        cout<<"enter address of employee"<<endl;
        cin>>this->address;
        cout<<"enter date of birth"<<endl;
        dob.accept();
      }

      void display()
      {
         cout<<"name ="<<this->name <<endl;
         cout<<"address= "<<this->address<<endl;
         cout<<"date of birth :";
         dob.display();
      }
};

class Employee
{
  private :
    int empid;
    float sal;
    string dept;
    date doj;
    person p;

  public:
   Employee()
   {
    this->empid=0;
    this->sal=0;
    this->dept="";
   }

   Employee(int empid,float sal,string dept)
   {
    this->empid=empid;
    this->sal=sal;
    this->dept=dept;
   }
  // Employee(int empid,float sal,string dept,int day,int month,int year):doj(day,month,year)
  //  {
  //   this->empid=empid;
  //   this->sal=sal;
  //   this->dept=dept;
  //  }

  int get_id()
  {
    return this->empid;
  }
  float get_sal()
  {
    return this->sal;
  }   
  string get_dept()
  {
    return this->dept;
  }
  void set_id(int empid)
  {
    this->empid= empid ;
  }
   void set_sal(float sal)
  {
    this->sal= sal ;
  }
   void set_dept(string  dept)
  {
    this->dept= dept ;
  }
  date get_date()
  {
    return doj;
  }
  void set_doj(date doj)
  {
    this->doj=doj;
  }
  void accept()
  {
    cout<<"enter empid"<<endl;
    cin>>this->empid;
    cout<<"enter salary"<<endl;
    cin>>this->sal;
    
    cout<<"enter dept"<<endl;
    cin>>this->dept;
    cout<<"enter date of joining "<<endl;
     doj.accept();
     cout<<"enter person details"<<endl;
     p.accept();

  }

  void display()
  {
    cout<<"id= "<<this->empid<<endl;
    cout<<"sal= "<<this->sal<<endl;
    cout<<"dept="<<this->dept<<endl;
    cout<<"date of joining ";
    doj.display();
    p.display();
  }

};


int main ()
{
  Employee e1;
  e1.accept();
  e1.display();

}