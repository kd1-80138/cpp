// Q3. Write a Matrix class. Allocate memory dynamically in parameterized constructor. Also write
// parameter-less constructor. Write accept() and print() functions.
// Also provide add(), subtract(), multiply() and transpose() function.



#include<iostream>
using namespace std;


class Matrix
{
    private:
     int **arr;
    int **arr1;
    int row;
    int col;
    int **res;

    public:
        Matrix(int row,int col)
        {
            this->row=row;
            this->col=col;
            //1st 2-D array 
            arr=new int*[col];
             for(int i=0;i<col;i++)
               arr[i]=new int[row];
            //2nd 2-D array
            arr1=new int*[col];
             for(int i=0;i<col;i++)
               arr1[i]=new int[row];
            //resultant 2-D array
            res=new int*[col]; 
             for(int i=0;i<col;i++)
               res[i]=new int[row];
           
        }

        void accept()
        {
            cout<<"enter values for 1st Matrix"<<endl;
            for(int i=0;i<this->row;i++)
            {
                for(int j=0;j<this->col;j++)
                {
                    cin>>arr[i][j];
                }
            } 
            cout<<"enter values for 2 Matrix"<<endl;
            for(int i=0;i<this->row;i++)
            {
                for(int j=0;j<this->col;j++)
                {
                    cin>>arr1[i][j];
                }
            } 

            cout<<"input taken successfully"<<endl;

        }

        void display_Matrix1()
        {
           cout<<"1nd Matrix display"<<endl;
            for(int i=0;i<this->row;i++)
            {
                for(int j=0;j<this->col;j++)
                {
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        void display_Matrix2()
        { 
            cout<<"2nd Matrix display"<<endl;
            for(int i=0;i<this->row;i++)
            {
                for(int j=0;j<this->col;j++)
                {
                    cout<<arr1[i][j]<<" ";
                }
                cout<<endl;
            }

        }
         void display_res()
        { 
            cout<<"resultant  Matrix display"<<endl;
            for(int i=0;i<this->row;i++)
            {
                for(int j=0;j<this->col;j++)
                {
                    cout<<res[i][j]<<" ";
                }
                cout<<endl;
            }
        }



        void addition()
        {
            for (int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    res[i][j]=arr[i][j]+arr1[i][j];
                    
                }
            }
        }
         void substraction()
        {
            for (int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    res[i][j]=arr[i][j]-arr1[i][j];
                    
                }
            }
        }

        void multiplication()
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    res[i][j]=0;
                    for (int k=0;k<col;k++)
                    { 

                    res[i][j]+=arr[i][k]* arr1[k][j];

                    }
                }
            }         
        }

        void Tanspose()
        {
            cout<<"Tranpose of first matrix is "<<endl;
            for(int i=0;i<row;i++)
             for (int j=0;j<col;j++)
             {
                res[i][j]=arr[j][i];
             }
             this->display_res();

             cout<<"Tranpose of second matrix is "<<endl;
            for(int i=0;i<row;i++)
             for (int j=0;j<col;j++)
             {
                res[i][j]=arr[j][i];
             }
             this->display_res();



        }

        ~Matrix()
        {
            
            for(int i=0;i<row;i++)
              delete[] arr[i];
            for(int i=0;i<row;i++)
              delete[] arr1[i];
            delete[] arr;
            delete[] arr1;

        }
      

};
  


int main ()
{
    Matrix m(3,3);
    m.accept();
    m.addition();
    m.display_res();
    m.substraction();
    m.display_res();
    m.multiplication();
    m.display_res();
    m.Tanspose();

}