#include <iostream>
using namespace std;

class MULTIPLY
{
private:
    int row, col;
    int **mat;

public:
    void size(int r1, int c1)
    {
        row = r1;
        col = c1;
        mat = new int *[row];
        for (int i = 0; i < row; i++)
        {
            mat[i] = new int[col];
        }
    }
    void input()
    {
        cout << "Enter the elment into matrix : " << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> mat[i][j];
            }
        }
    }
    void show()
    {
        cout << "The matrix is : " << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    MULTIPLY mul(MULTIPLY B)
    {
        int rows = row;
        int cols = B.col;
        MULTIPLY C;
        C.mat = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            C.mat[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                C.mat[i][j] = 0;
                for (int k = 0; k < cols; k++)
                {
                    C.mat[i][j] = C.mat[i][j] + mat[i][k] * B.mat[k][j];
                }
            }
        }
        return C;
    }
};
 int main()
{
    int r1, c1, r2, c2;
    cout << "Enter the row size of the first matrix :" << endl;
    cin >> r1;
    cout << "Enter the col size of the first matrix :" << endl;
    cin >> c1;
    cout << "Enter the row size of the second matrix : " << endl;
    cin >> r2;
    cout << "Enter the col size of the second matrix :" << endl;
    cin >> c2;

    if (c1 != r2)
    {
        cout << "Matrix multplication is not possible!" << endl;
        exit(0);
    }
    else
    {
        MULTIPLY A, B, C;
        A.size(r1, c1);
        A.input();
        B.size(r2, c2);
        B.input();

        C = A.mul(B);
        A.show();
        B.show();
        C.show();
    }

    return 0;
}