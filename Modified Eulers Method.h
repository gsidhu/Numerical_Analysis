//Gurjot Singh Sidhu
//BSc (H) Physics
//30
//AIM: To solve an ordinary differential equation using Modified Euler's method

#include <iostream>
#include <conio.h>

void main()
{
	start:
	cout << "\tModified Euler's Method for ordinary differential equation";

	double x_coeff[10]={0}, y_coeff[10]={0}, xy_coeff[20]={0}, f[10]={0}, y[10]={0}, x[10]={0}, h;
	int m_x, m_y, m_xy, cons, var;
	char c;
	
	cout << "\nOrder of x terms: ";
	cin >> m_x;
	cout << "\nOrder of y terms: ";
	cin >> m_y;
	cout << "\nHighest power of xy mixed terms: ";
	cin >> m_xy;
	var = m_xy + 2*m_xy - 2;
	cout << endl;
	for (int i = 0; i < m_x; i++)									//input coeffs of x terms
	{
		cout << "Coefficient of x^" << i+1 << ": ";
		cin >> x_coeff[i];
	}
	cout << endl;
	for (int i = 0; i < m_y; i++)									//input coeffs of y terms
	{
		cout << "Coefficient of y^" << i+1 << ": ";
		cin >> y_coeff[i];
	}
	for (int i = 0; i < var; i++)									//input coeffs of xy terms
	{
		if (i < m_xy)
		{
			cout << "Coefficient of x^" << i+1 << "y^" << i+1 << ": ";
			cin >> xy_coeff[i];
		}
	
		else if (m_xy <= i <= 2*m_xy - 2)							//input coeffs of xy^ terms
		{
			cout << "Coefficient of xy^" << i+1 << ": ";
			cin >> xy_coeff[i+m_xy-1];
		}
		else														//input coeffs of x^y terms
		{
			cout << "Coefficient of x^" << i+1 << "y: ";
			cin >> xy_coeff[i+m_xy+1];
		}
	}
	cout << "\nConstant term: ";
	cin >> cons;

	printf("\nInput values of x_0, y_0 and h:\n");
	cin >> x[0] >> y[0] >> h;

	for (int i = 1; i <= 10; i++)									//computing x values
	{
		x[i] = x[i-1] + h;
	}

	for (int k = 0; k < 6; k++)										//computing f(x) values
	{
		for (int i = 0; i < m_x; i++)
		{
			f[k] = f[k] + x_coeff[i]*pow(x[k],i+1);
		}
		for (int i = 0; i < m_y; i++)
		{
			f[k] = f[k] + y_coeff[i]*pow(y[k],i+1);
		}
		for (int i = 0; i < var; i++)
		{
			if (i < m_xy)
			{
				f[k] = f[k] + xy_coeff[i]*pow(x[k],i+1)*pow(y[k],i+1);
			}
			else if (m_xy <= i <= 2*m_xy - 2)
			{
				f[k] = f[k] + xy_coeff[i]*x[k]*pow(y[k],i+1);
			}
			else
			{
				f[k] = f[k] + xy_coeff[i]*pow(x[k],i+1)*y[k];
			}
		}
		f[k] = f[k] + cons;
		y[k+1] = y[k] + h*f[k];
	}

	for (int k(0); k < 6; k++)									//modified euler's method
	{
		y[k+1] = y[k] + (h/2)*(f[k]+f[k+1]);
	}

	cout << "\nx\t\ty(x)";
	for (int i = 0; i < 6; i++)
	{
		cout << "\n" << x[i] << "\t\t" << y[i];
	}
	cout << "\n\nTry again? (Y/N)\n";
	cin >> c;
	if (c == 'Y' || c == 'y')
	goto start;

	_getch();
 }