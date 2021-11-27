
class IOWrapper{
public:
	handle_t* resource; // ������
	IOWRapper() = delete; //������������ �� ���������
	
	IOWRrapper(const &IOWrapper) = delete; // ����������� �����������
	
	IOWrapper& operator=(const &IOWrapper) = delete;
	
	IOWrapper(&&IOWrapper x): content(x.content){ //����������� �����������
		x.content = nullptr;
	};
	
	IOWrapper& operator=(&&IOWrapper x){ //�������� ������������ ������������
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
