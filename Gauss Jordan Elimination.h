//Gurjot Singh Sidhu
//BSc (H) Physics
//30
//AIM - To find the solution of a system of equations using Gauss-Jordan Elimination Method

#include <iostream>
#include <conio.h>

int n;
float coeff[15][15] = {0,0}, var[15]={0}, multiplier;

void main()
{
	printf("Enter the number of variables: ");
	cin >> n;

	printf("\nEnter the coefficients of variables and the constant terms row-wise:\n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cin >> coeff[i][j];
		}
	}

	for (int k(0); k < n-1; k++)		//creating Upper Triangular Matrix
	{
		for (int i(k+1); i < n; i++)
		{
			multiplier = (coeff[i][k]/coeff[k][k]);
			for (int j(0); j <= n; j++)
			{
				coeff[i][j] -= multiplier*coeff[k][j];
			}
		}
	}

	for (int k(n-1); k >= 0; k--)		//creating Diagonal Matrix
	{
		for (int i(k-1); i >= 0; i--)
		{
			multiplier = (coeff[i][k]/coeff[k][k]);
			for (int j(0); j <= n; j++)
			{
				coeff[i][j] -= multiplier*coeff[k][j];
			}
		}
	}

	for (int i = n-1; i >=0; i--)		//finding solutions
	{
		var[i] = coeff[i][n]/coeff[i][i];
	}

	cout << "\n Diagonal Matrix -" << endl;

	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < n+1; j++)
		{
			printf("%10.4f", coeff[i][j]);
			if (j == n-1)
				printf("\t|");
		}
	}

	cout << "\n\nResult - ";

	for (int i = 0; i < n; i++)
	{
		cout << "\nx" << i << ": " << var[i];
	}


	_getch();
}