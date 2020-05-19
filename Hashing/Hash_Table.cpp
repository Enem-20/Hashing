#include "Hash_Table.h"

template<class Key, class Value>
void Hash_Table<Key, Value>::Set_Size(int size)
{
	capacity = pow(2, size + 3);
	Value* Buf = new Value[capacity];
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

	if (Table[index] == val)
	{
		if (Search_Position(index, val) == -1)
		{
			Set_Size(size + 1);
			Search_Position(index, val);
		}
	}
	else
	{
		Table[index] = val;
	}
}

template<class Key, class Value>
Value Hash_Table<Key, Value>::Find(Value val)
{
	
}

template<class Key, class Value>
void Hash_Table<Key, Value>::Hash(Key key)
{

}

template<class Key, class Value>
int Hash_Table<Key, Value>::Search_Position(long key, Value val)
{
	for (size_t i = key + 1; i < capacity; ++i)
	{
		if (Table[i] == nullptr || i != key)
		{
			Table[i] = val;
			if (i >= size)
			{
				++size;
			}

			return 1;
		}
		else if (i == key)
		{
			return -1;
		}

		if (i == capacity - 1)
		{
			i = -1;
		}
	}
}