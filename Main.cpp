//		Churong Zhang

#include <fstream>
#include <iostream>

using namespace std;

#include <limits.h>
#include <stdlib.h>
#include <math.h>

const	int		MaxNodes	(12);

		int		Cost		[MaxNodes] [MaxNodes];
		char	CurrPath	[MaxNodes];
		int		MinCost;
		char	MinPath		[MaxNodes];
		char	MinPath2	[MaxNodes];
		int		NodesInUse;
		bool	Visited		[MaxNodes];

void FindCost (int /* starting node */, int /* cost so far */, int /* depth in tree */);


void main (int argc, char * argv[])
	{
	
	int		i;
	fstream file;
	char Node1;
	char Node2;
	//	initialize Cost table
	//		read in NodesInUse from input
	//		loop to read in Node Node Cost from input
	//argv[1] = "Data2.txt";
	/*
	input data structure
	Number of letters(location)
	locationA1 locationA2 Cost
	locationA1 locationA3 Cost
	.
	.
	.
	.
	locationAx locationAy Cost
	*/

	file.open(argv[1]);
	file >> NodesInUse;

	while (!file.eof())
	{
		file >> Node1 >> Node2 >> i;
		Cost[Node1 - 'A'][Node2 - 'A'] = i;

	}
	MinCost	= INT_MAX;
	for (i = 0; i < NodesInUse; i++)
		{
		CurrPath [0]	= i + 'A';	// get the starting point of the path I am about to go down
		FindCost (i, 0, 1);
		}
	if (MinCost < INT_MAX)
			{
			// show info on minimum cost and path
		cout << "The minimum cost is " << MinCost << endl;
		cout << "The Path is: ";
				for (i = 0; MinPath[i] != 0; i++)
				{
					cout << " " << MinPath[i];
				}
				cout << endl;
			}
		else
			cout << "You cannot get to all nodes in the graph" << endl;

	
	system ("pause");
	}

void FindCost (int CurrentNode, int CurrentCost, int CurrentDepth)
	{
	int		i;
	int		TempCost;

	Visited [CurrentNode]	= true;
	for (i = 0; i < NodesInUse; i++)	// go through all nodes we could visit from this node
	{

		if (!Visited[i] && (Cost[CurrentNode][i] > 0))	// if we haven't visited that node yet AND there is a connection to that node
		{
			TempCost = CurrentCost + Cost[CurrentNode][i];
			if (TempCost < MinCost)
			{
				CurrPath[CurrentDepth] = i + 'A';
				FindCost(i, TempCost, CurrentDepth + 1);
			}
			else;
		}
		else;
	}
	for (i = 0; Visited [i] && (i < NodesInUse); i++);

	if (i == NodesInUse)	// if false, we did not visit every node
			{	// we visited every node so this path is a new min cost path
			MinCost	= CurrentCost;
			memcpy (MinPath, CurrPath, NodesInUse * sizeof (char));
			}
		else;
	Visited [CurrentNode] = false;		// this node at bottom of tree will be free to visit on another path
	}
