//Gurjot Singh Sidhu
//BSc. (H) Physics
//30
//AIM: Derivative using Newton's Difference Formula

#include <iostream>
#include <conio.h>

long int fac(int f)
{
	if (f > 1)
	{
		f *= fac(f-1);
		return f;
	}
	return f;
}

float diff(float p, int n, int x)
{
	float var = p, h = 0.0001, p1 = p + h, p0 = p;
	for (int i(1); i < n; i++)
	{
		if (var < 0)
		{
			p0 = p0 * (var+i);
			p1 = p1 * (var+h+i);
		}
		else
		{
			p0 = p0 * (var-i);
			p1 = p1 * (var+h-i);
		}
	}
	p = (p1 - p0)/h;
	return p;
}

void main()
{
	printf("\t\tDerivative using Newton's Difference Formula");
	int n;
	long int fact;
	float d[25][15] = {0,0};
	float x[25] = {0}, y[25] = {0}, pf, pb, a, ans(0);

	printf("\nInput the total number of data points: ");
	cin >> n;

	cout << "\nInput the value of x where y' is to be found: ";
	cin >> a;

	printf("\nInput the x, y data sets:\n");					//inputting x,y values
	for (int i(0); i < n; i++)
	{
		cin >> x[i] >> y[i];
		if ((x[i-1] < a) && (a < x[i]) && (i != 0))
		{
			pf = (a - x[i-1])/(x[i] - x[i-1]);
			pb = (a - x[i])/(x[i] - x[i-1]);
		}
	}

	for (int i(1); i <= n; i++)									//calculating values of differences
	{
		for (int m(0); m < n; m++)
		{
			d[i][m] = y[m+1] - y[m];		
			if (i > 1)
			{
				d[i][m] = d[i-1][m+1] - d[i-1][m];
			}
		}
	}

	if ((x[n/2] > a) || (x[n+1]/2 > a))
	{
		printf("\n\tUsing forward difference formula\n");		//Forward difference
		printf("\np = %g\n", pf);								//outputting value of p
		
		ans = 0;
		
		for (int i(1); i <= n-1; i++)							//calculating answer
		{
			fact = fac(i);
			ans = ans + (d[i][0])*(diff(pf, i, 1))/fact;
		}
		ans = ans/(x[1]-x[0]);
	}

	else
	{
		printf("\n\tUsing backward difference formula\n");		//Backward difference
		printf("\np = %g\n", pb);								//outputting value of p

		ans = 0;

		for (int i(1); i <= n-1; i++)							//calculating answer
		{
			fact = fac(i);
			ans = ans + (d[i][0])*(diff(pb, i, 1))/fact;
		}
		ans = ans/(x[1]-x[0]);
	}
	
	cout << "\n\tx\ty\t";										//printing table header
	for (int i(1); i <= n-1; i++)
	{
		cout << "d" << i << "\t";
	}
	cout << "\n";
	for (int i(0); i < n; i++)									//printing table
	{
		cout << "\t" << x[i] << "\t" << y[i] << "\t";
		for (int j(1); j < n; j++)
		{
			if (i == n-j)
				break;
			cout << d[j][i] << "\t";
		}
		cout << "\n";
	}
	printf("\nValue of y' at x = %g is: %g", a, ans);
	_getch();
}