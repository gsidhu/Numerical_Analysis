//Gurjot Singh Sidhu
//BSc (H) Physics
//30
//AIM - To find the solution of a system of equations using Gauss-Seidel Method

#include <iostream>
#include <conio.h>

int n, counter(0), iterations(10), error(0.0001);
float coeff[15][15] = {0,0}, x[15]={0}, a[15]={0}, b[15]={0};

void main()
{
	cout << "Solving a system of linear equations using Gauss Seidel Method\n";
	cout << "Maximum number of iterations = 10\n";

	cout << "Enter the number of variables: ";
	cin >> n;

	cout << "\nEnter the coefficients of variables and the constant terms row-wise:\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cin >> coeff[i][j];
		}
	}

	cout << "\n  Iteration\t";		//outputting table header
	for (int i(0); i < n; i++)
	{
		printf("x(%d)\t\t", i+1);
	}

	while (counter < iterations)
	{
		for (int i(0); i < n; i++)
		{
			a[i] = x[i];
		}
		counter += 1;
		for (int i(0); i < n; i++)
		{
			b[i] = coeff[i][n];
			for (int j = 0; j < n; j++)
			{	
				if (i != j)
				{
					b[i] = b[i] - coeff[i][j] * x[j];
					x[i] = b[i]/coeff[i][i];
				}
			}
		}
		printf("\n  %d\t\t", counter);
		for (int i(0); i < n; i++)
		{
			if (abs(a[i] - x[i]) < error)
				{break;}
			printf("%f\t", x[i]);
		}
	}

	_getch();
}