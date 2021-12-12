#include <iostream>
using namespace std;

void spiralPrint(int **arr, int nRows, int nCols)
{
    //Write your code here
    int rStart , rEnd , cStart , cEnd ;
    rStart = cStart = 0 ;
    rEnd = nRows - 1 ;
    cEnd = nCols - 1 ; 
    while(1){
    	if(rStart > rEnd || cStart > cEnd) return ;

	    for(int i = cStart ; i <= cEnd ; i++) cout << arr[rStart][i] << " " ;
	    rStart++ ;

	    if(rStart > rEnd || cStart > cEnd) return ;

	    for(int i = rStart ; i <= rEnd ; i++) cout << arr[i][cEnd] << " " ;
	    cEnd-- ;

	    if(rStart > rEnd || cStart > cEnd) return ;

		for(int i = cEnd ; i >= cStart  ; i--) cout << arr[rEnd][i] << " " ;
		rEnd-- ;

		if(rStart > rEnd || cStart > cEnd) return ;

		for(int i = rEnd ; i >= rStart ; i--) cout << arr[i][cStart] << " " ;
		cStart++ ;
    }

}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}