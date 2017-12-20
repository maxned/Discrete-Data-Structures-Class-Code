
#include <iostream>
#include <cmath>

using namespace std;

void runExperiments(int numTrials, int numExperiments, float chanceOfHead, int *&headsPerExpirement);
void getExperimentsPerHead(int numExperiments, const int *headsPerExperiment, int *&numExperimentsPerHead);
void displayResults(int numTrials, int numExperiments, float chanceOfHead, const int *numExperimentsPerHead);
uint64_t factorial(uint64_t value);

int main()
{
	int numTrials = 3;
	int numExperiments = 5;
	float chanceOfHead = 0.5;

	cin >> numTrials >> numExperiments >> chanceOfHead;

	int *headsPerExpirement = new int[numExperiments];
	for (int i = 0; i < numExperiments; i++) headsPerExpirement[i] = 0;

	runExperiments(numTrials, numExperiments, chanceOfHead, headsPerExpirement);

	int *numExperimentsPerHead = new int[numTrials + 1];
	for (int i = 0; i < numTrials + 1; i++) numExperimentsPerHead[i] = 0;

	getExperimentsPerHead(numExperiments, headsPerExpirement, numExperimentsPerHead);

	displayResults(numTrials, numExperiments, chanceOfHead, numExperimentsPerHead);

	delete [] headsPerExpirement;
	delete [] numExperimentsPerHead;

    return 0;
}

void runExperiments(int numTrials, int numExperiments, float chanceOfHead, int *&headsPerExpirement)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < numExperiments; i++)
	{
		int numHeads = 0;

		for (int j = 0; j < numTrials; j++)
		{
			float randomNumber = (float)rand() / RAND_MAX;
			if (randomNumber < chanceOfHead) numHeads++;
		}

		headsPerExpirement[i] = numHeads;
	}
}

void getExperimentsPerHead(int numExperiments, const int *headsPerExperiment, int *&numExperimentsPerHead)
{
	for (int i = 0; i < numExperiments; i++)
	{
		numExperimentsPerHead[headsPerExperiment[i]] += 1;
	}
}

void displayResults(int numTrials, int numExperiments, float chanceOfHead, const int *numExperimentsPerHead)
{
	cout << endl;

	for (int i = 0; i < numTrials + 1; i++)
	{
		cout << numExperimentsPerHead[i] << endl;
	}

	cout << endl;

	// observed probablities
	for (int i = 0; i < numTrials + 1; i++)
	{
		cout << (double)numExperimentsPerHead[i] / numExperiments << endl;
	}

	cout << endl;

	// theoretical probabilites
	for (int i = 0; i < numTrials + 1; i++)
	{
		uint64_t combination = factorial(numTrials) / (factorial(i) * factorial(numTrials - i));
		double probability = combination * pow(chanceOfHead, i) * pow(1 - chanceOfHead, numTrials - i);
		cout << probability << endl;
	}
}

uint64_t factorial(uint64_t value)
{
	if (value == 0) {
		return 1;
	}

	return value * factorial(value - 1);
}
