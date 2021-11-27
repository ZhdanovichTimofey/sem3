
class IOWrapper{
public:
	handle_t* resource; // Ресурс
	IOWRapper() = delete; //конструкктор по умолчанию
	
	IOWRrapper(const &IOWrapper) = delete; // конструктор копирования
	
	IOWrapper& operator=(const &IOWrapper) = delete;
	
	IOWrapper(&&IOWrapper x): content(x.content){ //конструктор копирования
		x.content = nullptr;
	};
	
	IOWrapper& operator=(&&IOWrapper x){ //оператор присваивания перемещением
		if (&x == this)
			return *this;
			
		delete this->resource;
		this->resource = x.resource;
		x.resource = nullptr;
		return *this;
	};
	
	void Write(const std::string& content){
	}
};
