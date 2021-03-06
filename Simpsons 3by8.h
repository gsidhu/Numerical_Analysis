//Gurjot Singh Sidhu
//BSc. (H) Physics
//30
//AIM: Integration by Simpson's 3/8th Rule

#include <iostream>
#include <conio.h>
#include <math.h>

void main()
{
	cout << "\t\t\Simpson's 3/8 Rule";
	double coeff[50];												//inputting the polynomial
	int m;
	printf("\nOrder of polynomial: ");
	cin >> m;

	printf("\nInput the constant term followed by the coefficients in increasing order:\n");
	for (int i = 0; i <= m; i++)
	{
		cin >> coeff[i];
	}

	double h, a, b, f(0), x[50], y[50], result(0), part1(0), part2(0);
	int n;														//dividing into subintervals
	printf("\nNumber of divisions: ");
	cin >> n;
	printf("\nLower limit of integral: ");
	cin >> a;
	printf("\nUpper limit of integral: ");
	cin >> b;

	h = (b-a)/n;
	x[0] = a;
	x[n] = b;

	for (int j = 1; j <= n; j++)									//values of x
	{
		x[j] = x[j-1] + h;
	}

	for (int i = 0; i <= n; i++)
	{
		y[i] = 0;
		for (int j = 0; j <= m; j++)								//values of y
		{
			y[i] = y[i] + coeff[j] * pow(x[i], j); 
		}
	}

	result = y[0] + y[n];

	for (int i = 1; i < n; i++)
	{
		if (i%3 == 0)
		{
			part1 = part1 + y[i];
		}
		else
		{
			part2 = part2 + y[i];
		}
	}

	result = result + 2*part1 + 3*part2;
	result = result * (3*h/8);

	cout << "\n\nThe result of the definite integral is: ";
	cout << result;

	_getch();
}