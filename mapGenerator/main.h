#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

class tile
{
private:
	char value;
	double altitude, mag;

public:
	void buildTerrain();
	char terrain();
	void setAltitude(double value);
	double getAltitude();
	void setMag(double mag);
	double getMag();


};

class map {

public:
	double x, y, amplitude;
	const int width = 40, height = 20;
	tile t[40][20];
	void render();
	void create();
};

#endif // MAIN_H_INCLUDED
