#include "DATA.h"
#include "Hash_Table.h"

DATA::DATA()
{
	visited = new bool* [8];
	GraphDesk = new int* [8];

	for (size_t i = 0; i < 8; ++i)
	{
		visited[i] = new bool[8];
		GraphDesk[i] = new int[8];
	}
}

void DATA::Read()
{
	fstream out("GraphDesk.txt", fstream::out);

	if (out.is_open())
	{
		int line = 0, column = 0;
		while (!out.eof())
		{
			out >> GraphDesk[line][column];
			++column;

			if (column == 8)
			{
				++line;
				column = 0;
			}
		}
	}
	else
	{
		cout << "File <<GraphDesk.txt>> is not open";
	}

	out.close();
}

int** DATA::GetDesk()
{
	return GraphDesk;
}

DATA::~DATA()
{
	clear();
}

void DATA::clear()
{
	for (size_t i = 0; i < 8; ++i)
	{
		delete[] visited[i];
		delete[] GraphDesk[i];
	}

	delete[] visited, GraphDesk;
}