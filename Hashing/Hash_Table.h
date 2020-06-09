#pragma once

template<class Key, class Value>
class Hash_Table
{
public:
	Hash_Table(int size = 20)
	{
		this->size = pow(2,size);
		capacity = this->size + 3;
		Table = new Value[capacity] = {nullptr};
	}
	~Hash_Table()
	{
		delete[] Table;
	}

	void Set_Size(int size);
	void Insert(Key index, Value val);
	Value Find(Value val);
	void Hash(Key key, Value val);

private:
	int size;
	int capacity;
	
	Value* Table;
	Value& operator[](const Key& index);
	const Value& operator[](const Key& index) const;
	Value& operator=(Value val);

	int Search_Position(long key, Value val);
};