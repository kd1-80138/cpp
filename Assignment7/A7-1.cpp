

#include <iostream>
using namespace std;

class date
{
private:
    int day;
    int month;
    int year;

public:
    date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    int get_day()
    {
        return this->day;
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
        this->day = day;
    }
    void set_month(int month)
    {
        this->month = month;
    }
    void set_year(int year)
    {
        this->year = year;
    }

    void accept()
    {
        cout << "enter day" << endl;
        cin >> this->day;
        cout << "enter month" << endl;
        cin >> this->month;
        cout << "enter year" << endl;
        cin >> this->year;
    }

    bool is_leap()
    {
        if (this->year % 4 == 0 && this->year % 100 != 0)
            return true;

        return false;
    }
    void display()
    {
        cout << "date= " << this->day << "/" << this->month << "/" << this->year << endl;
    }
};

class person
{
private:
    string name;
    string add;
    // composition(association)
protected:
    date dob;

public:
    person()
    {
        this->name = "";
        this->add = "";
    }
    person(string name, string add, int day, int month, int year) : dob(day, month, year)
    {
        this->name = name;
        this->add = add;
    }

    string get_name()
    {
        return this->name;
    }
    string get_address()
    {
        return this->add;
    }
    date get_date()
    {
        return dob;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_add(string add)
    {
        this->add = add;
    }
    void set_dob(date d)
    {
        dob=d;
        
    }
     virtual void accept()
    {
        cout << "enter name of employee" << endl;
        cin >> this->name;
        cout << "enter address of employee" << endl;
        cin >> this->add;
        cout << "enter date of birth" << endl;
        dob.accept();
    }
     virtual void display()
    {
        cout << "name =" << this->name << endl;
        cout << "address= " << this->add << endl;
        cout << "date of birth :";
        dob.display();
    }
};

class Employee : public person
{
private:
    int id;
    float sal;
    string dept;
    date doj;

public:
    Employee()
    {
        this->id = 0;
        this->sal = 0;
        this->dept = "";
    }

    Employee(int empid, float sal, string dept)
    {
        this->id = empid;
        this->sal = sal;
        this->dept = dept;
    }
    Employee(int empid, float sal, string dept, int day, int month, int year) : doj(day, month, year)
    {
        this->id = empid;
        this->sal = sal;
        this->dept = dept;
    }
    Employee(string name, string add, date dob, int id, float sal, string dept, int day, int month, int year) : doj(day, month, year)
    {

        this->id = id;
        this->sal = sal;
        this->dept = dept;
        this->set_dob(dob);
        
    }
    int get_id()
    {
        return this->id;
    }
     float get_sal()
    {
        return this->sal;
    }
     string get_dept()
    {
        return this->dept;
    }
    date get_doj()
    {
        return this->doj;
    }
    void set_id(int id )
    {
        this->id= id ;
   }
   void set_sal(float sal )
    {
        this->sal= sal ;
   }
   void set_dept(string dept) 
    {
        this->dept= dept ;
   }
   void set_doj(date d)
   {
       doj=d;
   }
   void display()
   {
    cout<<"*******************************************"<<endl;
     person::display();
     cout<<"id= "<<this->id<<"sal= "<<this->sal<<"dept= "<<this->dept;
     doj.display();
         cout<<"*******************************************"<<endl;

   }
   void accept()
   {
    cout<<"*******************************"<<endl;
    cout<<"enter employee details"<<endl;
     person::accept();
     cout<<"enter id"<<endl;
     cin>>this->id;
     cout<<"enter salary"<<endl;
     cin>>this->sal;
     cout<<"enter dept"<<endl;
     cin>>this->dept;
     doj.accept();
   }
};


int main ()
{
   person *bptr=new Employee; //upcasting 
    bptr->accept();
    bptr->display();
    Employee *dptr=(Employee*)bptr; //downcasting
    dptr->accept();
    dptr->display();

   delete bptr;
   return 0;

}