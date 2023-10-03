#include<iostream>
using namespace std;
// Q2. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
// holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
// Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
// should be menu driven and should not cause memory leakage.

class product
{
    private :
     int  id;
       string title;
    float price ;
    protected:
    string type;
    
 
 public:
 product()
 {
    this->id=0;
    this->title="";
    this->price=0;
    this->type="";
 }
 int get_id()
 {
    return this->id;
 }
 string get_title()
 {
    return this->title;
 }
 float get_price()
 {
    return this->price;

 }
 string get_type()
 {
    return this->type;
 }
 void set_type(string type)
 {
     this->type=type;
 }
 void set_id(int id)
 {
     this->id=id;
 }
 void set_title(string title)
 {
     this->title=title;
 }
 void set_price(float price)
 {
     this->price=price;
 }
  virtual void accept()
 {
    cout<<"enter id"<<endl;
    cin>>this->id;
     getchar();
    cout<<"enter title"<<endl;
    getline(cin,this->title);
    cout<<"enter  price"<<endl;
    cin>>this->price;

 }
 void display()
 {

 }

 


};
class book : public product
{
    private:
    string author;
    public:
    book()
    {
        this->type="Book";
        this->author="";
    }
    book(string author)
    {
        this->author=author;
    }
    string get_author()
    {
        return this->author;

    }
    void set_author(string author)
    {
        this->author =author;
    }
    void accept()
    {
        product::accept();
        getchar();
      cout<<"enter author"<<endl;
      getline(cin,this->author);
    }
    void display()
    { 

    }


};

class tape: public product
{
    private:
     string artist;
    public:
     tape()
     {
        this->type="Tape";
        this->artist="";

     }
     tape(string artist)
     {
        this->artist=artist;
     }
     string get_artist()
     {
        return this->artist;

     }
     void set_artist(string artist)
     {
        this->artist=artist;
     }
    void accept()
    {
        product::accept();
        getchar();
      cout<<"enter artist"<<endl;
      getline(cin,this->artist);
    }
    void display()
    {
        
    }

};

int menu()
{ 
    int c;
    cout<<"****************************************"<<endl;
     cout<<"0-EXIT"<<endl;
    cout<<"1-ADD BOOK"<<endl;
    cout<<"2-ADD TAPE"<<endl;
    cout<<"3-CALCULATE BILL AND EXIT "<<endl;
    cout<<"enter your choice"<<endl;

    cout<<"****************************************"<<endl;
    cin>>c;
    return c;
}
void calculate_bill(product **arr,int index)
{
     
     float tape_total=0;
     float book_total=0;
     int  book_count=0;
     int tape_count=0;
     int total=0;
                    
                   for(int i=0;i<index;i++)
                   {
                    if(arr[i]->get_type()=="Book")
                    { 
                     book_total+=arr[i]->get_price()*0.90;
                     book_count++;   
                    } 
                   }
                   
                   for(int i=0;i<index;i++)
                   {
                    
                    if(arr[i]->get_type()=="Tape")
                            {tape_total+=arr[i]->get_price()*0.95;
                                tape_count++;
                            }    
                   }
                     cout<<"TAPE COUNT"<<tape_count<<endl;
                  cout<<"BOOK  COUNT"<<book_count<<endl;

                    cout<<"Book Total"<<book_total<<endl;
                   cout<<"Tape Total"<<tape_total<<endl;
                   
                   cout<<"total bill=" <<tape_total+book_total<<endl;

    
}

int main ()
{
    int choice;
   
    product *arr[3];
    int index=0;
    while((choice=menu())!=0)
    {
        switch(choice)
        {

            case 1:
                if(index<3)
                {
                    arr[index]=new book(); //upcasting
                    arr[index]->accept();
                    index++;

              
                }
                else 
                {
                    cout<<"Array is FULL u ...MAX LIMIT OF PURCHASE REACHED"<<endl;
                }
                 break;

            case 2:
                if(index<3)
                {
                    arr[index]=new tape(); //upcasting
                    arr[index]->accept();  
                    index++;            
                }
                else 
                {
                    cout<<"Array is FULL u ...MAX LIMIT OF PURCHASE REACHED"<<endl;
                }
               break;

            case 3:
              if(index==0)
                {
                    cout<<"Empty array .. please enter items..."<<endl;

                }
                else {
                   calculate_bill(arr,index);
                }

                break;

            default:
                  cout<<"invalid choice "<<endl;
                  break;
               
                
        }

    }
        cout<<"THANK YOU FOR SHOPPING WITH US ..................." <<endl;

    for(int i=0;i<3;i++)
      delete arr[i];
   
    return 0;   
}