//Gurjot Singh Sidhu
//BSc. (H) Physics
//30
//AIM: Integration by Simpson's 1/3rd Rule

#include <iostream>
#include <conio.h>
#include <math.h>

void main()
{
	cout << "\t\t\Simpson's 1/3 Rule";
	double coeff[50];											//inputting the polynomial
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

	for (int j = 1; j <= n; j++)								//values of x
	{
		x[j] = x[j-1] + h;
	}

	for (int i = 0; i <= n; i++)
	{
		y[i] = 0;
		for (int j = 0; j <= m; j++)							//values of y
		{
			y[i] = y[i] + coeff[j] * pow(x[i], j); 
		}
	}
	
	result = y[0] + y[n];

	for (int i = 1; i < n; i++)
	{
		part1 = part1 + y[i];
		i++;
	}

	for (int i = 2; i < n; i++)
	{
		part2 = part2 + y[i];
		i++;
	}

	result = result + 4*part1 + 2*part2;
	result = result * (h/3);

	cout << "\n\nThe result of the definite integral is: ";
	cout << result;

	_getch();
}