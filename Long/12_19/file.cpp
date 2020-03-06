    #include <iostream>
    #include <fstream>
    #include <string>
    #include<set>

    using namespace std;
    int main()
    {
        setlocale(LC_ALL, "");

        const int rows = 5;
        const int cols = 5;

        int pos = 0;
        int neg = 0;
        int null = 0;

        int iMin = 0;
        int jMin = 0;
        int iMax = 0;
        int jMax = 0;

        //for larget negative
        int ineg=0;
        int jneg=0;
        //for lowest positive
        int ipos=0;
        int jpos=0;

        double average;
        double sum = 0;

        ifstream matrix("Matrix.txt", ios::in);

        int arr[rows][cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix >> arr[i][j];
                cout << arr[i][j] << " " << "\t";
            }

            cout << endl;
        }
        cout << endl;

        matrix.close();

        ofstream final_matrix("Final_matrix.txt", ios::out);

                    set<int, greater<int>> s;

                    set<int> s1;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (arr[i][j] > 0)
                    {
                        pos++;
                    }
                    else if (arr[i][j] < 0)
                    {
                        neg++;
                    }
                    else
                    {
                        null++;
                    }

                    if (arr[i][j] < arr[iMin][jMin])
                    {
                        iMin = i;
                        jMin = j;
                    }


                    if (arr[i][j] > arr[iMax][jMax])
                    {
                        iMax = i;
                        jMax = j;
                    }

                    sum += arr[i][j]; 

                    if(arr[i][j]<0)
                    {
                        s.insert(arr[i][j]);
                    }

                    if(arr[i][j]>0)
                    {
                        s1.insert(arr[i][j]);
                    }
                }
            }
            int prod = rows * cols;

                    set<int>::iterator it1 = s1.begin();
                    set<int, greater<int> > ::iterator it = s.begin(); 

            cout << "The number of positive numbers in the matrix: " << pos << endl;
            final_matrix << "The number of positive numbers in the matrix: " << pos << endl;

            cout << "The number of negative numbers in the matrix: " << neg << endl;
            final_matrix << "The number of negative numbers in the matrix: " << neg << endl;

            cout << "The number of zeros in the matrix: " << null << endl;
            final_matrix << "The number of zeros in the matrix: " << null << endl;

            cout << "The minimum number in the matrix: " << arr[iMin][jMin] << endl;
            final_matrix << "The minimum number in the matrix: " << arr[iMin][jMin] << endl;

            cout << "The maximum number in the matrix: " << arr[iMax][jMax] << endl;
            final_matrix << "The maximum number in the matrix: " << arr[iMax][jMax] << endl;

            cout << "The lowest positive number in the matrix: " << *it1 << endl;
            final_matrix << "The lowest positive number in the matrix: " << *it1 << endl;

            cout << "The largest negative number in the matrix: " << *it << endl;
            final_matrix << "The largest negative number in the matrix: " << *it <<endl;

            cout << "Arithmetic mean of the matrix: " << sum / prod << endl;
            final_matrix << "Arithmetic mean of the matrix: " << sum / (rows * cols) << endl;

            final_matrix.close();

        cin.get();
    }