/* File ini akan digunakan untuk melakukan scalling file input untuk menggambar */

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cstdlib>
using namespace std;

int main() {
	string fileinput;
	double scale;

	ifstream input;
	ofstream output;

	string num_of_lines;

	string current_line;
	string delimiter = " ";
	int i = 0;

	cout << "File input: ";
	cin >> fileinput;
	cout << "Scale: ";
	cin >> scale;

	input.open(fileinput.c_str());
	output.open("scaller_result.txt", ios::out | ios::trunc);

	if(input.is_open()) {
		getline(input, num_of_lines);
		output << num_of_lines << endl;
		while(getline(input,current_line)) {
			istringstream iss(current_line);
			i = 0;
			do {
				string temp;
				int coor;
				iss >> temp;
				if(i < 8) {
					if (i > 0 && i < 5) {
						coor = atoi(temp.c_str());
						coor *= scale;
						temp = static_cast<ostringstream*>(&(ostringstream() << coor))->str();
					}
					output << temp << " ";
				}
				i++;
			} while(iss);
			output << endl;
		}
	} else {
		cout << "Error openning file: " << fileinput << endl;
		input.close();
		output.close();
		return 0;
	}

	input.close();
	output.close();

	return 0;
}