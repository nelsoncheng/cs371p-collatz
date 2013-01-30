#include <cstdlib>
#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream outputFile;
	outputFile.open("RunCollatz.in");
	int x, y;
	for(int n = 0; n < 1000; n++){
	x = (rand()%999999)+1;
	y = (rand()%999999)+1;
	outputFile << x << " " << y << endl;}
	outputFile.close();
}
