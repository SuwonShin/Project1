#include <vector>
using namespace std;

struct IO{
	int x = 0;
	double max = -1.0;
};

struct rectan{
	int x, y, w, h;
};


class member{
public:
	member(char * filename);
	void readfile(char * filename);
	int getSize();
	vector<rectan> get(int num);
	int tru;
private:
	vector<vector<rectan>> data;
};

int min(int a, int b);
int max(int a, int b);



namespace tool{
	double IOU(rectan a, rectan b);
}