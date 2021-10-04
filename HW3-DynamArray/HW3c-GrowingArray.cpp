/*
	 Author: Matthew Lepis
	 Date: 10/2/2021
	 Description: CPE593A, HW3c, Capacity Based Growing Array; HW3 Main function cpp
*/

#include <string>
#include "DynamArray.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;


DynamArray HW3inputParse2nd(string in, int inCount)
{
	DynamArray out;
	string temp = in;

	while(temp.find(" ") != -1)
	{
		out.addEnd(stoi(temp.substr(0, temp.find(" "))));
		temp = temp.substr(temp.find(" ")+1);
	}
	out.addEnd(stoi(temp.substr(0, temp.find(" "))));
	return out;
}

int main()
{
	int temp[3];
	string secondInput;

	cout << "CPE 593A - Applied Data Structures\n\tHW3c - Growing Array\n\n";
	cout << "Please provide your first input string: ";
	cin >> temp[0] >> temp[1] >> temp[2];
	cin.ignore();
	cout << "\n";


	cout << "Please provide your second input string: ";
	getline(cin, secondInput);
	cout << "\n";

	DynamArray multiples = HW3inputParse2nd(secondInput, temp[2]);

	DynamArray list;
	list.HW3arrayInitializer(temp[0], temp[1]);

	for(int i = 0; i < multiples.getLength(); i++)
		list.HW3compaction(multiples.getData(i));
	cout << list.getLength();


	return 1;
}