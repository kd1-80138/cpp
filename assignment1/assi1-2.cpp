#include<iostream>

 
 struct Date
 {
    int dd;
    int mm;
    int yy;



  void initDate()
 {
    dd=01;
    mm= 01;
    yy=2000;

 }
 void acceptDate()
{
    printf("\n Enter day ");
    scanf("%d",&dd);
     printf("\n enter month ");
     scanf("%d",&mm);
    printf("\n enter year");
     scanf("%d",&yy);

}  
void printDate()
 {
    printf("\n entered date is  %d--%d--%d",dd,mm,yy);

 }
 bool isLeap(int year)
 {
    if (year%4==0 && year%100 != 0 || year%400==0)
          {  return true;
          }
     else{
      return false;
     }
 }

 };


 int main ()
  {
    int x;
      struct Date d1;
      
      
      while(x)
      {
         printf("\n 0-Exit" );
        printf("\n1-to initialize default value ");
        printf("\n 2-to insert  value ");
        printf("\n 3-Display date only");
        printf("\n 4- to check leap year");
        
        scanf("%d",&x);
        if (x<5 && x>=0)
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
             case 3 :
                    
                     d1.printDate();
                     break;       
                  
              case 4:
                int yy;
                printf("enter year to check for ");
                scanf("%d",&yy); 
                if (d1.isLeap(yy))
                {  
                  printf("entered year is  a leap year") ;
                }
                else 
                { 
                printf("entered year is not leap year");
                }

                break;  
           }
        }
        else 
        {
         printf("\nenter valid choice ");
        }

      }
  }
