#include "Hash_Table.h"

template<class Key, class Value>
void Hash_Table<Key, Value>::Set_Size(int size)
{
	Value* Buf = new Value[size];
	for (int i = 0; i < this->size; ++i)
	{
		Buf[i] = Table[i];
	}

	Table = Buf;
	this->size = size;
	delete[] Buf;
}

template<class Key, class Value>
Value& Hash_Table<Key, Value>::operator[](const Key& index)
{
	return Table[index];
}

template<class Key, class Value>
void Hash_Table<Key, Value>::Insert(Key index, Value val)
{
	//Hash function needed here
	Table[index] = val;
}