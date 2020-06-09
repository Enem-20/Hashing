#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class DATA
{
public:
	DATA();
	~DATA();
	
	void Read();
	void clear();
	int** GetDesk();

private:
	int** GraphDesk;
	bool** visited;
};

