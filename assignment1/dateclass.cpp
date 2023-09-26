#include<iostream>


class Date 
{
    private:
    int dd,mm,yy;
    public:

   void initDate()
  {
    dd=1;
    mm=1;
    yy=2000;
  }


 void printDate() {
       printf("\n entered date is  %d--%d--%d",dd,mm,yy);

     }

 void acceptDate(){
    printf("\n Enter day ");
    scanf("%d",&dd);
     printf("\n enter month ");
     scanf("%d",&mm);
    printf("\n enter year");
     scanf("%d",&yy);

   }  
   bool isLeap()
 {
    int year;
    printf("\n enter year to check for");
    scanf("%d",&year);
  if (year%4==0 && year%100 != 0 || year%400==0)
          {  return true;
          }
          
      return false;
     
    
 }
};

int main ()
{
    Date d1;

    int x;
    while(x)
    { 
        printf("\n 0-Exit" );
        printf("\n1-to initialize default value ");
        printf("\n 2-to insert  value ");
        printf("\n 3-Display date only");
        printf("\n 4- to check leap year");

        scanf("%x",&x);

        if (x<=4 && x>=0)
        { 
            switch(x)
    { 

    
    case 1:
            d1.initDate();
            d1.printDate();
            break;

    case 2:
             d1.acceptDate();
             d1.printDate();
             break;

    case 3:
           d1.printDate();
           break;


    case 4:
       if (d1.isLeap() ){ 
            printf("entered year is leap year");
            }
         else {
                 printf("entered year is not a leap year");
                  }
             break;
        
          }
        }
        else {
            printf("enter valid choice ");
        }

    
    
    }
}