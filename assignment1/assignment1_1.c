#include<stdio.h>
 
 
 struct Date
 {
    int dd;
    int mm;
    int yy;

 };

 void initDate(struct Date* ptrDate)
 {
    ptrDate->dd=01;
    ptrDate->mm= 01;
    ptrDate->yy=2000;

 }

 void printDate(struct Date*  pdate)
 {
    printf("\n entered date is  %d--%d--%d",pdate->dd,pdate->mm,pdate->yy);

 }

void acceptDate(struct Date* ptrDate)
{
    printf("\n Enter day ");
    scanf("%d",&ptrDate->dd);
     printf("\n enter month ");
     scanf("%d",&ptrDate->mm);
    printf("\n enter year");
     scanf("%d",&ptrDate->yy);

}  


  int main ()
  {
    int x=1;
      struct Date d1;
      
      
      while(x)
      {
         printf("\n 0-Exit" );
        printf("\n1-to initialize default value ");
        printf("\n 2-to insert  value ");
        printf("\n 3-Display date only");
        scanf("%d",&x);


        if(x<=3 && x>=0)
        { 
            
          
        switch(x)
        {
            case 1:
                     initDate(&d1);
                     printDate(&d1);
                     break;
             case 2:
                    acceptDate(&d1);
                    printDate(&d1);
                    break;
             case 3 :
                    
                     printDate(&d1);
                     break;       
                  
        }

      }
      else 
      { 
        printf("please enter valid choice");
      }


  }
  }