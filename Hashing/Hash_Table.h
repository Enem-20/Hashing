#pragma once

template<class Key, class Value>
class Hash_Table
{
public:
	Hash_Table(int size = 20)
	{
		this->size = size;
		Table = new Value[size];
	}
	~Hash_Table()
	{
		delete[] Table;
	}

	void Set_Size(int size);
	void Insert(Key index, Value val);

private:
	int size;
	
	Value* Table;
	Value& operator[](const Key& index);
};