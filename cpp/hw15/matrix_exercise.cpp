#include <iostream>

using namespace std;


void read_matrix(int *a, int *b, int ***arr_)
{
	cin >> *a >> *b;
	int **arr = new int* [*a];
	for (int i = 0; i < *a; i++)
		arr[i] = new int [*b];
	for (int i = 0; i < *a; i++)
		for (int j = 0; j < *b; j++)
			cin >> arr[i][j];
	*arr_ = arr;
}


void add_matrices(int** m1, int** m2, int a, int b, int*** sum)
{
	int **ab = new int* [a];
	for (int i = 0; i < a; i++)                                              
		ab[i] = new int [b];
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			ab[i][j] = m1[i][j] + m2[i][j];
	*sum = ab;
}


void product_of_matrices(int** m1, int** m2,
											  int a, int b1, int b2, int*** product)
{
	int s = 0;
	int **pro = new int* [b2];
	for (int i = 0; i < b2; i++)
		pro[i]= new int [b1];
	for (int i = 0; i < b2; i++)
		for (int j = 0; j < b1; j++)
		{
			for (int ii = 0; ii < a; ii++)
				s += m1[i][ii]*m2[ii][j];
			pro[i][j] = s;
			s = 0;
		}
	*product = pro;
	
}


void print_matrix(int a, int b, int **arr)
{
	for (int i = 0; i < a; i++)
	{
   	for (int j = 0; j < b; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
}


int main ()
{
	int a = 0, b = 0, c = 0, d = 0, **arr, **mas, **sum, **product;
	read_matrix(&a, &b, &arr);
	read_matrix(&c, &d, &mas);
	print_matrix(a, b, arr);
	cout << endl;
	print_matrix(c, d, mas);
	cout << endl;
  add_matrices (arr, mas, a, b, &sum);
	print_matrix(a, b, sum);
	product_of_matrices(arr, mas, a, c, d, &product);
	cout << endl;
	print_matrix(c, d, product);
	return 0;
}
