#include "member.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>

int min(int a, int b)
{
	if (a >= b)
		return b;
	else
		return a;
}

int max(int a, int b)
{
	if (a <= b)
		return b;
	else
		return a;
}
double tool::IOU(rectan a, rectan b)
{
	double pro;
	double area = 0.00;

	int x1, x2, y1, y2;
	x1 = min(a.x + a.w, b.x + b.w);
	x2 = max(a.x, b.x);
	y1 = min(a.y + a.h, b.y + b.h);
	y2 = max(a.y, b.y);

	if (x1 > x2 && y1 > y2)
		area = (double)((y1 - y2)*(x1 - x2));
	pro = (double)area / (a.w*a.h + b.w*b.h - area);
	return pro;
}


member :: member(char * filename){
	readfile(filename);
}


void member::readfile(char * filename){
	ifstream infile(filename);
	string line;
	vector<rectan> tmp;
	int fr = 0;
	while (getline(infile, line)){
		istringstream iss(line);
		rectan rec;
		int f, i, o1, o2;
		
		if (!(iss >> f >> i >> rec.x >> rec.y >> rec.w >> rec.h)){
			continue;
		}


		if (iss >> o1 >> o2){
			if (o1 == 1 || o2 == 1){ continue; }
		}
		

		if (f != fr){
			data.push_back(tmp);
			tmp.clear();
			fr++;
			while (fr != f){
				data.push_back(tmp);
				fr++;
			}
			tmp.push_back(rec);
			member::tru++;
		}

		else{
			tmp.push_back(rec);
			member::tru++;
		}
	}

	data.push_back(tmp);

//	for (auto i : data){
//		for (auto j : i){
//			cout << j.x << ' ' << j.y << ' ' << j.w << ' ' << j.h << endl;
//		}
//	}
}

int member::getSize(){
	return data.size();
}

vector<rectan> member::get(int num){
		return data.at(num);
}
