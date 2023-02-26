#include "stdafx.h"
#include "CConsole.h"
#include "CRandom.h"
#include "CTree.h"

int main()
{
	srand(unsigned(time(nullptr)));

	CTree<int> tree;

	for (size_t i = 0; i < 20; i++)
		tree.AddNode(CRandom<int>::Get());

	tree.PrintGoDown();
	tree.Print();

	return 0;
}