//Gurjot Singh Sidhu
//BSc (H) Physics
//30
//AIM: Euler's method to evaluate an ordinary differential equation

#include <iostream>
#include <conio.h>

void main()
{
	cout << "\t\tEuler's Method for ordinary differential equation";

	double x_coeff[10]={0}, y_coeff[10]={0}, f[10]={0}, y[10]={0}, x[10]={0}, h;
	int m_x, m_y, cons, count(0);

	printf("\nOrder of x terms: ");
	cin >> m_x;
	printf("\nOrder of y terms: ");
	cin >> m_y;
	cout << endl;
	for (int i = 0; i < m_x; i++)
	{
		cout << "Coefficient of x^" << i+1 << ": ";
		cin >> x_coeff[i];
	}
	cout << endl;
	for (int i = 0; i < m_y; i++)
	{
		cout << "Coefficient of y^" << i+1 << ": ";
		cin >> y_coeff[i];
	}
	
	cout << "\nConstant term: ";
	cin >> cons;

	printf("\nInput values of x_0, y_0 and h:\n");
	cin >> x[0] >> y[0] >> h;

	for (int i = 1; i <= 10; i++)
	{
		x[i] = x[i-1] + h;
	}

	for (int k = 0; k < 6; k++)
	{
		for (int i = 0; i < m_x; i++)
		{
			f[k] = f[k] + x_coeff[i]*pow(x[k],i+1);
		}
		for (int i = 0; i < m_y; i++)
		{
			f[k] = f[k] + y_coeff[i]*pow(y[k],i+1);
		}

		f[k] = f[k] + cons;
		y[k+1] = y[k] + h*f[k];
	}

	cout << "\nx\t\ty(x)";
	for (int i = 0; i < 6; i++)
	{
		cout << "\n" << x[i] << "\t\t" << y[i];
	}
	_getch();
 }