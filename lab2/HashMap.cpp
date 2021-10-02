#include <iostream>
#include <stdexcept>
#include <vector>
#include <utility>

class Map 
{
public:
	virtual void put(int key, int value);  /* methods */
    virtual void add(int key, int increment); 
    virtual int get(int key);
    virtual void getAll();
};

class StaticMap : public Map                                                                     
{                                                                               
public:                                                                         
    StaticMap();   /* constructor */                                            
    ~StaticMap();  /* destructor */  
//	void add(int key, int increment) override;

	void put(int key, int value);  /* methods */
	void add(int key, int increment); 
    int get(int key);
    void getAll();                                            
	                                                                               
	
	/* throws std::runtime_error("key not found")
       if key was not found */
private:
	void extend()
	{
		int* newkeys = new int[this->capacity * 2];
		int* newvalues = new int[this->capacity * 2];
		for (int i = 0; i < this->capacity; i++)
		{
			newkeys[i] = this->keys[i];
			newvalues[i] = this->values[i];
		}
		delete[] this->keys;
		delete[] this->values;
		this->keys = newkeys;
		this->values = newvalues;
		this->capacity *= 2;
	}     
	
	int* keys;
	int* values;
	int capacity;
	int size;                                                          
    /* your fields here */
};

StaticMap::StaticMap(){
	this->capacity = 32;
	this->size = 0;
	this->keys = new int[32];
	this->values = new int[32];
}

StaticMap::~StaticMap(){
	delete[] this->keys;
	delete[] this->values;
}

void StaticMap::add(int key, int increment)
{
	int i = 0;
	while ((key > keys[i]) and (i < this->size - 1))
	{
		i++;
	}
	if (key != keys[i])
	{
		throw std::runtime_error("key not found");
	}
	values[i] += increment;
}

int StaticMap::get(int key)
{
	int i = 0;
	int* l = this->keys;
	int* r = l + this->size; 
	while (l != r - 1)
	{
		if (l[(r-l)/2] <= key)
		{
			l = l + (r-l)/2;
		}  
		else
		{
			r = l + (r-l)/2;
		}
	}
	if (key != this->keys[l - this->keys])
	{
		throw std::runtime_error("key not found");
	}
	else
	{
		return this->values[l - this->keys];	
	}
}

void StaticMap::put(int key, int value)
{
	if (this->size == this->capacity)
		{	
			this->extend();
		} 
	int i = 0;
	while ((key > keys[i]) and (i < this->size))
	{
		i++;
	}
	if ((i < this->size) and (key != keys[i]))
	{
		for (int j = this->size; j > i; j--)
		{
			keys[j] = keys[j - 1];
			values[j] = values[j - 1];
		}	
	}
	keys[i] = key;
	values[i] = value;
	this->size += 1;	
}

void StaticMap::getAll()
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << this->keys[i] << ' ' << this->values[i] << '\n';
	}
}

class HashMap : public Map 
{
public:
	HashMap();   /* constructor */                                            
    ~HashMap();  /* destructor */  
	
	void put(int key, int value);  /* methods */
	void add(int key, int increment); 
    int get(int key);
    void getAll(); 
	
private:
	void extend()
	{
		int* newkeys = new int[this->capacity * 2];
		int* newvalues = new int[this->capacity * 2];
		for (int i = 0; i < this->capacity; i++)
		{
			newkeys[i] = this->keys[i];
			newvalues[i] = this->values[i];
		}
		delete[] this->keys;
		delete[] this->values;
		this->keys = newkeys;
		this->values = newvalues;
		this->capacity *= 2;
	}     
	
	int* keys;
	int* values;
	int capacity;
	int size;
	int number;
	std::vector<int>* hash_keys;
	std::vector<int>* hash_values; 
};

HashMap::HashMap(){
	this->number = 4;
	this->capacity = 32;
	this->size = 0;
	this->keys = new int[32];
	this->values = new int[32];
	this->hash_keys = new std::vector<int>[4];
	this->hash_values = new std::vector<int>[4];
}

HashMap::~HashMap(){
	delete[] this->keys;
	delete[] this->values;
}

int main()
{
	StaticMap sm;
	sm.put(0, 10);
	sm.put(3, 10);
	sm.put(1, 10);
	sm.put(4, 10);
	sm.put(2, 10);
	std::cout << sm.get(4);
	return 0;
}

