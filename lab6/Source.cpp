#include <iostream>
#include <string>

using namespace std;

class oshibki : public out_of_range {
public:
	string text;
public:
	oshibki(const string& text, const string txt = "") : out_of_range(txt), text(text) {}
};



class DotInSpace {
public:
	double x, y, z;
public:
	DotInSpace() = delete;
	DotInSpace(double x, double y, double z) {
		if (x > 1 || x < 0) throw oshibki("x is out of interval");
		if (y > 1 || y < 0) throw oshibki("y is out of interval");
		if (z > 1 || z < 0) throw oshibki("z is out of interval");
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

ostream& operator <<(ostream& out, DotInSpace DIS) {
	return out << DIS.x << "\t" << DIS.y << "\t" << DIS.z << endl;
}

int main() {
	try {
		DotInSpace dot1(0, 1, 0.6);
		cout << dot1;
		DotInSpace dot2(6, 0, 1);
		cout << dot2;
	} catch(const oshibki& er) {
		cout << er.text << endl;
	}
}
