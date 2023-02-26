#include "stdafx.h"
#include "CConsole.h"
#include "CRandom.h"
#include "CTree.h"
#include "CData.h"

int main()
{
	srand(unsigned(time(nullptr)));

	CTree<CData> tree;

	for (size_t i = 0; i < 5; i++) {
		CData data(i + 10, i);
		tree.AddNode(data);
	}

	tree.PrintGoDown();
	cout << endl;

	CData data(12, 2);
	tree.DeleteNode(data);
	tree.PrintGoDown();

	return 0;
}