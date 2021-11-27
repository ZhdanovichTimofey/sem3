#include<iostream>
#include <utility>

template <class T>
class Grid {
private:
 	T *memory;
 	size_t x_size, y_size;

public:
 	Grid(size_t x_size, size_t y_size){
 		this->memory = new T[x_size * y_size];
	 	this->x_size = x_size;
	 	this->y_size = y_size; 
 	};

 	T operator()(size_t x_idx, size_t y_idx) const{
 		return this->memory[x_idx + this->x_size * y_idx];
 	}
 	T& operator()(size_t x_idx, size_t y_idx) {
 		return this->memory[x_idx * this->x_size + y_idx];
 	};

	size_t get_xsize() const {
 		return this->x_size;
	}
	size_t get_ysize() const {
		return this->y_size;
	}

	Grid& operator=(float q){
		for (int i = 0; i < this->x_size * this->y_size; ++i){
			this->memory[i] = q; 
		}
		return *this;
	};
	
	Grid(Grid<T> &&src){
		std::swap(this->memory, src.memory);
		this->x_size = src.x_size;
		this->y_size = src.y_size;
		delete[] src.memory;
		src.memory = NULL;
	}
	
	Grid(Grid<T> const &src) {
		this->memory = src.memory;
		this->x_size = src.x_size;
		this->y_size = src.y_size;
	}
	
	Grid<T>& operator=(Grid<T> &src){
		this->memory = src.memory;
		this->x_size = src.x_size;
		this->y_size = src.y_size;
	}
	
	Grid<T>& operator=(Grid<T> &&src){
		std::swap(this->memory, src.memory);
		this->x_size = src.x_size;
		this->y_size = src.y_size;
		delete[] src.memory;
		src.memory = NULL;
	}

	friend std::ostream& operator<<(std::ostream& out, Grid const& g){
		for (int i = 0; i < g.y_size; ++i){
			for (int j = 0; j < g.x_size; ++j){
				out << g(i, j) << ' ';	
			}
			out << '\n';
		}
		return out; 
	}
	friend std::istream& operator>>(std::istream& in, Grid & g){
		for (int i = 0; i < g.y_size; ++i){
			for (int j = 0; j < g.x_size; ++j){
				in >> g(i, j);	
			}
		}
		return in;
	}
	
	~Grid(){
		delete[] this->memory;
	}
};

int main(){
	Grid <int>g(4, 4);
	g = 2;
	Grid<int> g1(1, 2);
	g1 = 1;
	Grid<int> g2(std::move(g));
	std::cout << g2;
	
	
	Grid<int> g3 = g1;
	g3 = std::move(g2);
	//std::cout << g1;
}
