#include<iostream>
using namespace std;
// Q3. Using the Q1 from assignment 6. Create an array of 10 employees. Provide menu driven code
// for the functionalities: Insted of char[] use string datatype
// 1. Accept Employee
// 2. Display the count of all employees with respect to
// designation
// 3. Display respective designation employees
#include<iostream>
using namespace std ;

//base calss 
class Employee
{
    private :
    int id;
    float sal;
    protected:
    string Designation;
    public:
    
   
     Employee()
     { 
        this->Designation="Employee";
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
     string get_designation()
     {
        return this->Designation;
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

     virtual void  display()
     {
        cout<<"ID= "<<this->id<<" sal= "<<this->sal<<endl;
     }
      virtual void accept()
     {
        cout<<"enter employee id "<<endl;
        cin>>this->id ;
        cout<<"enter salary "<<endl;
        cin>>this->sal;

     }
    virtual  ~Employee()
     {
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
        this->Designation="manager";
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
        this->Designation="salesman";
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
        Employee::display();
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

//indirect derieved
class salesmanager : public Manager,public salesman
{
    public:
    salesmanager()
    {
        this->Designation="salesmanager";
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

enum emenu{Exit,Add,count_by_designation,Display_by_designation};

   emenu  menu()
 {
    int ch;
    cout<<endl;
    cout<<"************************************************************"<<endl;
    cout<<"0-EXIT"<<endl;
    cout<<"1- ADD Employee"<<endl;
    cout<<"2-Display the count of all employees with respect to DESIGNATION"<<endl;
    cout<<"3-Display respective designation employees"<<endl;
    cout<<"************************************************************"<<endl;
    cin>>ch;
        return emenu(ch);
 }

int Count_Designation(Employee **arr,int index,string designation)
{
    int count_d=0;
    for(int i=0;i<index;i++)
    {
        if(arr[i]->get_designation()==designation)
        {
            count_d++;
        }
        
    }
    return count_d;
}

//
void display_by_des(Employee  **arr,int index,string designation)
{
    
    for(int i=0;i<index;i++)
    {
        if(arr[i]->get_designation()==designation)
        {
            arr[i]->display();
        }
    }
}

int main ()
{
    Employee *arr[10];//array of pointers;
    emenu choice;
    int index=0;
    while((choice=menu())!=Exit)
    {
        switch(choice)
        {
            case Add:
            if(index<10)
            { 
                   int ch;
                   cout<<" 1-ADD MANAGER \n 2-ADD SALESMAN \n 3-ADD SALESMANAGER \n";
                   cin>>ch;
                   switch(ch)
                   {
                    
                    case 1:  //adds manager
                         arr[index]=new Manager ;
                         arr[index]->accept();
                         index++;
                         break;
                    case 2:    //add salesman
                         arr[index]=new salesman;
                         arr[index]->accept();
                         index++;
                         break;
                     case 3:    //add salesmanager
                         arr[index]=new salesmanager;
                         arr[index]->accept();
                         arr[index]->display();
                         index++;
                         break;
                   }
             }
            break;

            case count_by_designation:
                            int d;
                          cout<<"choose designation to count employees of that designation"<<endl;
                          cout<<" \n 1- Manager \n 2-Salesman \n 3-Salesmanager"<<endl;
                          cin>>d;
                          switch(d)
                          {
                            
                            case 1:
                            cout<<"************************************************************"<<endl;
                                 cout<<"Total Manager "<<Count_Designation(arr,index,"manager")<<endl;
                             cout<<"************************************************************"<<endl;

                            break;
                            case  2:
                            cout<<"************************************************************"<<endl;
                            cout<<"Total Salesman "<<Count_Designation(arr,index,"salesman")<<endl;
                           cout<<"************************************************************"<<endl;
                            break;
                            case 3:
                            cout<<"************************************************************"<<endl;
                            cout<<"Total Salesmanager "<<Count_Designation(arr,index,"salesmanager")<<endl;
                            cout<<"************************************************************"<<endl;
                            break;
                          }


             break;
            case Display_by_designation:
                  int e;
                          cout<<"choose designation to display employees of that designation"<<endl;
                          cout<<" 1 Manager \n 2-Salesman \n 3-Salesmanager"<<endl;
                          cin>>d;
                          switch(d)
                          {
                            
                     case 1:
                            cout<<"************************************************************"<<endl;   
                                   cout<<"Manager"<<endl;  
                                    // Manager *dptr=dynamic_cast<Manager*>(arr) ;//downcasting                        
                                 display_by_des(arr,index,"manager");
                            cout<<"************************************************************"<<endl;                

                            break;
                      case  2:
                             cout<<"************************************************************"<<endl;   

                            cout<<" Salesman \n";
                    
                            display_by_des(arr,index,"salesman");
                            cout<<endl;
                            cout<<"************************************************************"<<endl;
                            break;
                       case 3:
                            cout<<"************************************************************"<<endl;
                            cout<<" Salesmanager\n";
                            display_by_des(arr,index,"salesmanager");
                            cout<<endl;
                            cout<<"************************************************************"<<endl;
                            break;
                          }

                           break; 

        }
    }
    cout<<"THANK YOU !!!................................."<<endl;
    for(int i=0;i<10;i++)
    delete arr[i];
    

    return 0;



}

