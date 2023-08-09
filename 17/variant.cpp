#include <iostream>
#include <variant>
#include <array>

struct NumberA{
	int num_integer_;
	NumberA(int num): num_integer_(num){
	    //std::cout<<"Parameterised constructor of NumberA is called."<<std::endl;
	}
	
	void print() {
	    std::cout<<num_integer_<<std::endl;
	}
};

struct NumberB{
	float num_float_;
	NumberB(float num): num_float_(num){
	    //std::cout<<"Parameterised constructor of NumberB is called."<<std::endl;
	}
	
	void print() {
	    std::cout<<num_float_<<std::endl;
	}

};


struct NumberC{
	std::array<int, 5> num_integer_array_{1,2,3,4,5};
	
	NumberC()=default;
	
	void print() {
		std::cout<<"Print function of NumberC is called."<<std::endl;
		
		for(auto & i: num_integer_array_) {
			std::cout<<i<<" ";
		}
		
		std::cout<<std::endl;
	}

};


class Visitor{
	public:
	
	void operator()(NumberA& a) {
		a.print();
	}
	
	
	void operator()(NumberB& b) {
		b.print();
	}
	
	void operator()(NumberC& c) {
		c.print();
	}

};

int main() {
		
	using namespace std::string_literals ;
	std::variant<NumberA, NumberB, NumberC> v{NumberA{5}};	

	//Polimorphism happens
	
	v.emplace<NumberA>(100);

	std::visit(Visitor{}, v);

	v = NumberB{10.1};

	std::visit(Visitor{}, v);

	v = NumberC{};

	std::visit(Visitor{}, v);

	return 0;
}



