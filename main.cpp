#include <iostream>
#include <time.h>

using namespace std;

/*  find the number of possible submatirces */
int ret_no_submatrix(int row, int col, int m, int n)
{
    return (row - m + 1) * (col - n + 1);
}

/*  find all the submatices and store it in a 3D array: submatix    */
void find_submatrix(int* arr, int row, int col, int m, int n, int* submatrix)
{
    int a=0;
    for(int i=0; i<row-m+1; i++)
    {
        for(int j=0; j<col-n+1; j++, a++)
        {
            for(int k=i, o=0; k<i+m, o<m; k++, o++)
            {
                for(int l=j, p=0; l<j+n, p<n; l++, p++)
                    *(submatrix + a*m*n + o*n + p) = *(arr + k*col + l);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int row, col, no_submatrix, m, n;

    row = 4;    //  rows of the given matix
    col = 4;    //  coloumns of the given matrix
    m = 3;      //  rows of the submatix
    n = 3;      //  coloumns of the submatix

    //int *arr = (int *)malloc(row * col * sizeof(int));    //  C style dynamic 2D array allocation
    int *arr = new int[row * col];  //  C++ style dynamic 2D array allocation
    
    /*  inputing the given matrix   */
    int k=0;
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            *(arr + i*col + j) = rand()%10;

    /*  printing the given matrix    */
    cout<<"MATRIX:"<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            cout<<*(arr + i*col + j)<<" ";
        cout<<endl;
    }

    no_submatrix = ret_no_submatrix(row, col, m, n);    //  get the number of possible submatrices

    cout<<endl<<endl<<"The given matix has "<<no_submatrix<<" submatices"<<endl;
    cout<<"Each of order: "<<m<<"X"<<n<<endl<<endl;

    //int *submatrix = (int *)malloc(no_submatrix * m * n * sizeof(int));   //C style dynamic 3D array allocation
    int *submatrix = new int[no_submatrix * m * n]; //  C++ style dynamic 3D array allocation
        
    find_submatrix(arr, row, col, m, n, submatrix); //  finding all the submatrices

    /*  printing all the submatrices    */
    for(int i=0; i<no_submatrix; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<n; k++)
                cout<<*(submatrix + i*m*n + j*n + k)<<" ";
            cout<<endl;
        }
        cout<<endl;
    }

    /*  cleanup procedure to free all the dynamically allocated memory    */
    delete []arr;
    delete []submatrix;

    return 0;
}
