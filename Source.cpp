#include "stdafx.h"
#include "CConsole.h"
#include "CRandom.h"
#include "CTree.h"
#include "CData.h"

int main()
{
	srand(unsigned(time(nullptr)));

	CTree<CData> tree;

	for (size_t i = 0; i < 20; i++) {
		CData data(i + 10, CRandom<int>::Get());
		tree.AddNode(data);
	}	

	tree.PrintGoDown();

	return 0;
}