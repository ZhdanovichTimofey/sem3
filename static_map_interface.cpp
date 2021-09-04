#include <iostream>
#include <stdexcept>

class StaticMap                                                                     
{                                                                               
public:                                                                         
    StaticMap();   /* constructor */                                            
    ~StaticMap();  /* destructor */                                             
                                                                                
    void put(int key, int value);  /* methods */
    void add(int key, int increment); 
    int get(int key);
    
	
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
	while (key > keys[i])
	{
		i++;
	}
	if (key != keys[i])
	{
		throw std::runtime_error("key not found");
	}
	values[i] += increment;
}

int StaticMap::get(int key){
	int i = 0;
	int* l = this->keys;
	int* r = l + this->size - 1; 
	while (l != r)
	{
		if (this->keys[(r-l)/2] < key)
		{
			l = l + (r-l)/2;
		}  
		else
		{
			r = l + (r-l)/2;
		}
	}
	std::cout << this->keys[l - this->keys];
	if (key != this->keys[l - this->keys])
	{
		throw std::runtime_error("key not found");
	}
	else
		return this->values[l - this->keys];
}

void StaticMap::put(int key, int value){
	std::cout << this->capacity << '\n';
	if (this->size == this->capacity)
		{	
			this->extend();
		} 
	int i = 0;
	while (key > keys[i])
	{
		i++;
	}
	if (key != keys[i])
	{
		for (int j = i; j < this->size; j++)
		{
			keys[j + 1] = keys[j];
			values[j + 1] = values[j];
		}	
	}
	keys[i] = key;
	values[i] = value;
	this->size += 1;	
}

int main()
{
	StaticMap sm;
	for (int i = 0; i < 100; i++)
	{
			std::cout << i << ' ';
			sm.put(i, 10);	
	}
	std::cout << sm.get(1);
	return 0;
}
