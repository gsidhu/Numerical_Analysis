//Gurjot Singh Sidhu
//BSc (H) Physics
//30
//AIM - To find the solution of a system of equations using Gauss Elimination Method

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

	for (int k(0); k < n-1; k++)			//creating Upper Triangular Matrix
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

	var[n-1] = coeff[n-1][n]/coeff[n-1][n-1];	//finding solutions
	for (int i = n-1; i >=0; i--)
	{
		multiplier = 0;
		for (int j(i); j < n; j++)
		{
			multiplier += coeff[i-1][j]*var[j];
		}
		var[i-1] = (coeff[i-1][n] - multiplier)/coeff[i-1][i-1];
	}

	cout << "\nUpper Triangular Matrix -" << endl;

	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < n+1; j++)
		{
			printf("%8.4f", coeff[i][j]);
		}
	}

	cout << "\n\nResult - ";

	for (int i = 0; i < n; i++)
	{
		cout << "\nx" << i << ": " << var[i];
	}


	_getch();
}