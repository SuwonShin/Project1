#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "member.h"
#include <vector>

int tp = 0;
double iou = 0.5;
double precision, recall;
double resul;


int main(){
	member m1 = member("C:/Users/Suwon/Desktop/인턴/Task1(due 6.30)/test_label/ground_truth/Hallway.txt");
	member m2 = member("C:/Users/Suwon/Desktop/인턴/Task1(due 6.30)/test_label/YOLO/Hallway_Y.txt");	
	for (int i = 0; i < m2.getSize(); i++){
		if (!m2.get(i).empty()){
			if (!m1.get(i).empty()){
				IO io;
				vector<rectan> com;
				vector<rectan> ori;
				com = m2.get(i);
				ori = m1.get(i);
				while (!com.empty() && !ori.empty()){
					io.max = 0;
					io.x = 0;
					rectan k;
					rectan u;
					k = *com.begin();
					//u = *ori.begin();
					//cout << i << ' ' << k.x << ' ' << u.x << endl;
					//cout << ori.size() << ' ' << com.size() << ' ' << i << endl;
					for (int j = 0; j < ori.size();j++){
						resul = tool::IOU(k, ori.at(j));
						if (resul > io.max){
							io.max = resul;
							io.x = j;
						}

					}
					
					if (io.max < iou){
						com.erase(com.begin());
					}
					else{
						tp++;
						com.erase(com.begin());
						ori.erase(ori.begin() + io.x);
					}
					
				}
			}
		}
		
	}
	cout << tp << ' ' << m1.tru << ' ' << m2.tru << endl;
	precision = (double)tp / m2.tru;
	recall = (double)tp / m1.tru;
	cout << precision << ' ' <<recall << endl;
	system("pause");
	return 0;
}