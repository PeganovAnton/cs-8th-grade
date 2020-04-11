#include <iostream>


using namespace std;


void read_matrix_1D(int *a, int *b, int **arr_)
{
	cin >> *a >> *b;
	int *arr = new int [(*a * *b)];
	for (int i = 0; i < *a; i++)
		for (int j = 0; j < *b; j++)
			cin >> arr[(i * *b + j)];
	*arr_ = arr;
}


void add_matrices_1D(int *m1, int *m2, int a, int b, int **summa)
{
	int *sum = new int [a * b];
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			sum[(i*b + j)] = m1[(i*b + j)] + m2[b*i + j];
	*summa = sum;
}


void multiply_matrices_1D(int *m1, int *m2, int a, int b1, int b2, 
													int **multiplication)
{
	int *product = new int [(b1 * b2)], s = 0;
	for (int i = 0; i < b2; i++)
		for (int j = 0; j < b1; j++)
		{
			for (int ii = 0; ii < a; ii++)
				s += m1[(i * b1 + ii)] * m2[i * b2 + ii];
			product[(b1*i + j)] = s;
			s = 0;
		};
	*multiplication = product;
}


void print_matrix_1D(int a, int b, int *arr)
{
	for(int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			cout << arr[(i*b + j)];
	cout << endl;
	}
}


int main ()
{
	int *arr, *mas, *sum, a = 0, b = 0, c = 0, d = 0, *multiplication;
	read_matrix_1D(&a, &b, &arr);
	cout << endl;
	print_matrix_1D(a, b, arr);
	cout << endl;
	read_matrix_1D(&c, &d, &mas);
	cout << endl;
	print_matrix_1D(c, d, mas);
	cout << endl;
	/*add_matrices_1D(arr, mas, a, b, &sum);
	cout << endl;
	print_matrix_1D(a, b, sum);
	cout << endl;*/
	multiply_matrices_1D(arr, mas, a, c, d, &multiplication);
	print_matrix_1D(c, d, multiplication); 	
	return 0;
}
