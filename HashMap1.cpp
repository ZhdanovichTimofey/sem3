#include <iostream>
#include <stdexcept>
#include <vector>
#include <utility>

class Map 
{
public:
	virtual void put(int key, int value) {};  /* methods */
    virtual void add(int key, int increment) {
	}; 
    virtual int get(int key) {
    	return 0;
	};
};

class StaticMap : public Map                                                                     
{                                                                               
public:                                                                         
    StaticMap();   /* constructor */                                            
    ~StaticMap();  /* destructor */  

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
	this->keys[i] = key;
	this->values[i] = value;
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
    int getnum(){
    	return this->number;
	}
	
private:
	int hash(int key)
	{
		unsigned long hash = 5381;
		int c = key;
		while (c > 0)
		{
			int data = c % 10;
			hash = ((hash << 5) + hash) + data;
			c = (c - data)/10;
		}
		hash = hash % this->number;
		return hash;
	}
		
	void reallocation()
	{
		this->number *= 2;
		int** hash_newkeys = new int*[this->number];
		int** hash_newvalues = new int*[this->number];
		for (int i = 0; i < this->number; i++)
		{
			hash_newkeys[i] = new int[33];
			hash_newvalues[i] = new int[33];
			hash_newkeys[i][0] = 0;
			hash_newvalues[i][0] = 0;
		}
		
		for (int i = 0; i < this->number / 2; i++)
		{
			for (int j = 1; j <= this->hash_keys[i][0]; j++)
			{
				this->private_put(this->hash_keys[i][j], this->hash_values[i][j], hash_newkeys, hash_newvalues);	
			}
		}
		for (int i = 0; i < this->number / 2; i++)
		{
			delete[] this->hash_keys[i];
			delete[] this->hash_values[i];
		} 
		delete[] this->hash_keys;
		delete[] this->hash_values;
		this->hash_keys = hash_newkeys;
		this->hash_values = hash_newvalues;
		for (int i = 0; i < this->number; i++)
		{
			this->hash_keys[i] = hash_newkeys[i];
			this->hash_values[i] = hash_newvalues[i];
			this->hash_keys[i][0] = hash_newkeys[i][0];
			this->hash_values[i][0] = hash_newvalues[i][0];
		}
	}
	
	void private_put(int key, int value, int** newkeys, int** newvalues)
	{
		int i = 1;
		int keyhash = this->hash(key);
		while ((key > newkeys[keyhash][i]) and (i < newkeys[keyhash][0]))
		{
			i++;
		}
		if ((i <= newkeys[keyhash][0]) and (key != newkeys[keyhash][i]))
		{
			for (int j = newkeys[keyhash][0] + 1; j > i; j--)
			{
				newkeys[keyhash][j] = newkeys[keyhash][j - 1];
				newvalues[keyhash][j] = newvalues[keyhash][j - 1];
			}	
		}
		newkeys[keyhash][i] = key;
		newvalues[keyhash][i] = value;
		newkeys[keyhash][0] += 1;
	}
	
	int number;
	int** hash_keys;
	int** hash_values; 
};

HashMap::HashMap()
{
	this->number = 4;
	this->hash_keys = new int*[this->number];
	this->hash_values = new int*[this->number];
	for (int i = 0; i < this->number; i++)
	{
		this->hash_keys[i] = new int[33];
		this->hash_values[i] = new int[33];
		this->hash_keys[i][0] = 0;
		this->hash_values[i][0] = 0;
	}
}

HashMap::~HashMap()
{
	for (int i = 0; i < this->number; i++)
	{
		delete[] this->hash_keys[i];
		delete[] this->hash_values[i];
	} 
	delete[] this->hash_keys;
	delete[] this->hash_values;
}

void HashMap::put(int key, int value)
{
	int keyhash = this->hash(key);
	while (this->hash_keys[keyhash][0] == 32)
	{
		this->reallocation();
	}
	int i = 1;
	while ((key > this->hash_keys[keyhash][i]) and (i < this->hash_keys[keyhash][0]))
	{
		i++;
	}
	if ((i <= this->hash_keys[keyhash][0]) and (key != this->hash_keys[keyhash][i]))
	{
		for (int j = this->hash_keys[keyhash][0] + 1; j > i; j--)
		{
			this->hash_keys[keyhash][j] = this->hash_keys[keyhash][j - 1];
			this->hash_values[keyhash][j] = this->hash_values[keyhash][j - 1];
		}	
	}
	this->hash_keys[keyhash][i] = key;
	this->hash_values[keyhash][i] = value;
	this->hash_keys[keyhash][0] += 1;
}

void HashMap::add(int key, int increment)
{
	int keyhash = this->hash(key);
	int i = 1;
	while ((key > this->hash_keys[keyhash][i]) and (i < this->hash_keys[keyhash][0]))
	{
		i++;
	}
	if (key != this->hash_keys[keyhash][i])
	{
		throw std::runtime_error("key not found");
	}
	this->hash_values[keyhash][i] += increment;
}

int HashMap::get(int key)
{
	int keyhash = this->hash(key);
	int i = 0;
	int* l = this->hash_keys[keyhash] + 1;
	int* r = l + this->hash_keys[keyhash][0]; 
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
	if (key != this->hash_keys[keyhash][l - this->hash_keys[keyhash]])
	{
		throw std::runtime_error("key not found");
	}
	else
	{
		return this->hash_values[keyhash][l - this->hash_keys[keyhash]];	
	}
}

int main()
{
	HashMap sm;
	int n = 100000;
	for (int i = 0; i < 3*n + 1; i += 3){
		sm.put(i, 20);
	}
	for (int i = 1; i < 3*n + 2; i += 3){
		sm.put(i, 20);
	}
	for (int i = 2; i < 3*n + 3; i += 3){
		sm.put(i, 20);
	}
	std::cout << sm.get(4) << '\n';
	return 0;
}
