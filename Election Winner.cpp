#include "../../std_lib_facilites.h"

int findMax(const double* array, int counter);
void printData(const string* names, const int* votes, const double* percent, int counter);

int main()
{
	cout << fixed << showpoint << setprecision(2);

	string* names = new string[100];
	int* votes = new int[100];

	double totalVotes = 0;

	int counter = 0;
	string name;
	int vote;
	cout << "Enter on each line, the name the candidate followed by the number of votes received: " << endl;
	while (cin >> name)
	{
		cin >> vote;
		if (!cin)
			error("Invalid number of votes for ", name);
		names[counter] = name;
		votes[counter] = vote;
		totalVotes = totalVotes + votes[counter];
		counter++;
		cout << "End" << endl;
	}


	double* percentage = new double[counter];
	for (int i = 0; i < counter; i++)
		percentage[i] = (static_cast<double>(votes[i]) / totalVotes) * 100;

	cout << endl;
	cout << left << setw(17) << "Candidate"
		<< left << setw(17) << "Votes Received"
		<< left << setw(17) << "% of Total Votes" << endl;

	printData(names, votes, percentage, counter);
	cout << left << setw(17) << "Total"
		<< left << setw(17) << totalVotes << endl;

	cout << endl;
	cout << "The Winner of the Election is " << names[findMax(percentage, counter)] << endl;

	return 0;
}

int findMax(const double* array, int counter)
{
	double max = array[0];
	int index = 0;
	for (int i = 1; i < counter; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
			index = i;
		}
	}
	return index;
}

void printData(const string* names, const int* votes, const double* percent, int counter)
{
	for (int i = 0; i < counter; i++)

		cout << setw(17) << names[i]
		<< left << setw(17) << votes[i]
		<< left << setw(17) << percent[i] << endl;
}