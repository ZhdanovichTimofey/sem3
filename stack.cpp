#include <iostream>

class Stack                                                                     
{                                                                               
public:                                                                         
    Stack();   /* constructor */                                            
    ~Stack();  /* destructor */                                             
                                                                                
    void push(int elem);  /* method */                                      
private:                                                                        
    int* content; /* fields */                                              
    int size;                                                               
    int capacity;                                                           
}; 

Stack::Stack()                                                                  
{                                                                               
    this->content = new int[32];                                            
    this->size = 0;                                                         
    this->capacity = 32;                                                    
}                                                                               
                                                                                
Stack::~Stack()                                                                 
{                                                                               
    delete[] this->content;                                                   
}   

void Stack::push(int elem)                                                                                                                                   
{
   		if (this->size == this->capacity)
		{
			int* newcontent = new int[this->capacity * 2];
			for (int i = 0; i < this->capacity; i++)
			{
				newcontent[i] = this->content[i];
			}
			delete[] this->content;
			this->content = newcontent;
			this->capacity *= 2;
		} 
		this->content[this->size++] = elem;                                               
}
                                                                                
int main()                                                                      
{                                                                               
    Stack st;                                                               
    st.push(1);                                                             
    st.push(2);                                                             
    return 0;                                                               
} 
