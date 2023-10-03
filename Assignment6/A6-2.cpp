// Q2. Implement following classes. Test all functionalities in main() of each created class. Note that
// employee is inherited into manager and salesman. Insted of char[] use string datatype.

#include<iostream>
using namespace std ;

//base calss 
class Employee
{
    private :
    // int id;
    // float sal;
    public:
    int id;
    float sal;
     Employee()
     { 
        
        this->id=0;
        this->sal=0;
     }
     Employee(int id , float sal)
     {
        this->id =id;
        this->sal=sal;
     }
     int get_id()
     {
        return this->id;
     }
     int get_sal()
     {
        return this->sal;
     }
     void set_id(int id)
     {
        this->id=id;
     }
      void set_sal(float sal)
     {
        this->sal=sal;
     }

     void  display()
     {
        cout<<"ID= "<<this->id<<" sal= "<<this->sal<<endl;
     }
     void accept()
     {
        cout<<"enter employee id "<<endl;
        cin>>this->id ;
        cout<<"enter salary "<<endl;
        cin>>this->sal;

     }

};

//derieved class1
class Manager : virtual public Employee
{
    private :
    //float bonus;
    public:
    float bonus;
     Manager()
     {
         this->bonus=0;
     }
     Manager(float bonus)
     {
        this->bonus=bonus;
     }
     float get_bonus()
     {
        return this->bonus;
     }
     void set_bonus(float bonus)
     {
        this->bonus=bonus;

     }

     void display()
     {
        Employee::display();
        cout<<"bonus= "<<this->bonus<<endl;
     }
     void accept()
     {
        Employee::accept();
        cout<<"enter bonus "<<endl;
        cin>>this->bonus;

     }

    protected:

    void accept_manager ()
    {
        cout<<"enter bonus "<<endl;
        cin>>this->bonus;
    }
    void display_manager()
    {
        cout<<"bonus = "<<this->bonus<<endl;
    }
};

//derieved class 2
class salesman : virtual public Employee
{
    private:
    //float comm;
    public:
    float comm;
     salesman()
     {
        
        this->comm=0;
     }
     salesman(float comm)
     {
        this->comm=comm;
     }
     float get_comm()
     {
        return this->comm;
     }
     void set_comm(float comm)
     {
        this->comm=comm;
     }
     void display()
     {
        cout<<" commission = "<<this->comm;
     }
     void accept()
     {
        Employee::accept();
        cout<<"enter commission "<<endl;
        cin>>this->comm;
        

     }

    protected:

    void accept_salesman ()
    {
        cout<<"enter commission "<<endl;
        cin>>this->comm;
    }
    void display_salesman()
    {
        cout<<"comm = "<<this->comm<<endl;
    }


};

//inderict derieved
class salesmanager : public Manager,public salesman
{
    public:
    salesmanager()
    {
        
        Employee::set_id(0);
        Employee::set_sal(0);
        Manager::set_bonus(0);
        salesman::set_comm(0);
    }
    salesmanager(int id ,float sal,float bonus,float comm)
    {
        Employee::set_id(id);
        Employee::set_sal(sal);
        Manager::set_bonus(bonus);
        salesman::set_comm(comm);
    }
    void accept()
    {
        Employee::accept();
        Manager::accept_manager();
        salesman::accept_salesman();
        
        
    }
    void display()
    {
        Employee::display();
        Manager::display_manager();
        salesman::display_salesman();
        
    }

};

int main ()
{
    salesmanager s1;
    cout<<"**********************************************************"<<endl;
    s1.accept();
    cout<<"***********************************************************"<<endl;
    s1.display();
    return 0;
}


