#include<fstream>
#include<iostream>

using namespace std;

int main()
{
	char data[100];

	//a writing way to open file
	ofstream outfile;
	outfile.open("afile.dat");

	cout << "Writing to the file" << endl;
	cout << "Enter your name:";
	cin.getline(data, 100);

	//write to the file that user input
	outfile << data << endl;

	cout << "Enter your age:";
	cin >> data;
	cin.ignore();

	//input the data to the file again
	outfile << data << endl;

	//close file;
	outfile.close();

	//open the file by reading way
	ifstream infile;
	infile.open("afile.dat");

	cout << "Reading from the file" << endl;
	infile >> data;

	//output the data to the screen
	cout << data << endl;

	//read the data form the file and print them again;
	infile >> data;
	cout << data << endl;

	//close the opened file
	infile.close();
	
	return 0;
}
