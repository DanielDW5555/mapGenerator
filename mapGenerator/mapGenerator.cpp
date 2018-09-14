#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <cstdio>
#include "main.h"

using namespace std;

void tile::buildTerrain()
{
	if (mag >= 0.85)
	{
		value = 'M';
	}
	else if (mag >= 0.5)
	{
		value = 'L';
	}
	else
	{
		value = ' ';
	}
}

char tile::terrain()
{
	return value;
}

void tile::setAltitude(double value)
{
	altitude = value;
}

double tile::getAltitude()
{
	return altitude;
}

void tile::setMag(double value2)
{
	mag = value2;
}

double tile::getMag()
{
	return mag;
}

void map::create()
{
	srand(time(NULL));
	double rand1 = rand() % 13 + 1, rand2 = rand() % 13 + 1, rand3 = rand() % 10 + 1;
	cout << "rand1: " << rand1 << " rand2: " << rand2 << " rand3: " << rand3 << endl;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			double mapx = (cos((rand1) / 20 * x) + (rand1 / 20)*sin((rand2 / rand3) / 20 * x) + cos(x / rand1));
			double mapy = sin((rand2) / 20 * y) + cos((rand3 / rand2) / 20 * y) + 0.2*cos(y + (rand3 / 3)) + rand2 / 5;
			double altitude = mapx + mapy;
			t[x][y].setAltitude(altitude);
		}
	}

	//Cycles through the pre made tiles and finds the highest altitude and applies a %
	double maximum = t[0][0].getAltitude();
	double lowest = t[0][0].getAltitude();
	for (int y = 0; y < height; y++)
	{
		for (int x = 1; x < width; x++)
		{
			if (t[x][y].getAltitude() >= maximum)
			{
				maximum = t[x][y].getAltitude();
			}
			if (t[x][y].getAltitude() <= lowest)
			{
				lowest = t[x][y].getAltitude();
			}
		}
	}
	if (lowest < 0) { lowest = lowest*-1; }
	double newMax = lowest + maximum;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			t[x][y].setMag((t[x][y].getAltitude() + lowest) / (newMax));
			t[x][y].buildTerrain();
		}
	}
}

void map::render()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			cout << t[x][y].terrain();
		}
		cout << endl;
	}
}

int main()
{
	map m;
	m.create();
	m.render();

	getchar();

	return 0;
}