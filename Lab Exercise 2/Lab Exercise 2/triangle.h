#pragma once

class Triangle
{
public:
	double hypot()
	{
		double hypot = 0;
		hypot = sqrt((m_base * m_base) + (m_height * m_height));

		return hypot;
	}

	double area()
	{
		double area = 0;
		area = (m_base * m_height) / 2;

		return area;
	}

private:
	double m_base = 5;
	double m_height = 3;

};