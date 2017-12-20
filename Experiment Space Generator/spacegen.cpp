
#include <iostream>
#include <fstream>
#include <cmath>
#include <set>

using namespace std;

void spacegen(set<int> choices, int trials, bool withoutReplacement, int count);
int factorial(int value);

struct node {
	int item;
	node *next;
};

int **outcomes;
int trialCount = 0;

int main()
{
	ifstream input;
	input.open("spacegen.conf");

	int numberOfTrials;
	int outcomesPerTrial;
	bool withoutReplacement;
	char *outputFileName = new char[99];

	input >> numberOfTrials >> outcomesPerTrial >> withoutReplacement >> outputFileName;

	input.close();

	ofstream output;
	output.open(outputFileName);

	// number of outcomes with replacement is outcomesPerTrial ^ numberOfTrials
	// number of outcomes without replacement is outcomesPerTrial!
	int maxNumberOfOutcomes = withoutReplacement ? factorial(outcomesPerTrial) : pow(outcomesPerTrial, numberOfTrials);

	// init the choices set
	set<int> choices;
	for (int i = 0; i < outcomesPerTrial; i++) {
		choices.insert(i);
	}

	// init the outcomes
	outcomes = new int*[maxNumberOfOutcomes];
	for (int i = 0; i < maxNumberOfOutcomes; i++) {
		outcomes[i] = new int[numberOfTrials];

		for (int j = 0; j < numberOfTrials; j++)
			outcomes[i][j] = -1; // initialize to -1 to mark it as no value for later
	}

	int count = 0;
	spacegen(choices, numberOfTrials, withoutReplacement, count);

	// save
	for (int i = 0; i < trialCount; i++)
	{
		for (int j = 0; j < numberOfTrials; j++)
		{
			int currentValue = outcomes[i][j];

			// get the numbers from previous experiments
			for (int k = i; currentValue < 0 && k >= 0; k--) {
				currentValue = outcomes[k][j];
			}
			if (currentValue >= 0) output << currentValue;
		}

		output << endl;
	}

	output.close();

    return 0;
}

void spacegen(set<int> choices, int trials, bool withoutReplacement, int count)
{
	if (trials == 0 || choices.size() == 0) {
		trialCount++;
	} else {

		for (set<int>::iterator it = choices.begin(); it != choices.end(); it++) {

			outcomes[trialCount][count] = *it;

			set<int> next = choices;
			if (withoutReplacement) next.erase(*it);
			spacegen(next, trials - 1, withoutReplacement, count + 1);
		}
	}
}

int factorial(int value)
{
	if (value == 0) {
		return 1;
	}

	return value * factorial(value - 1);
}
