#include<cmath>
#include<thread>
#include<vector>
#include<utility>
#include<iostream>

#define PI 3.1415926

double function(double x){
	return (1/std::sqrt(2 * PI)) * std::exp(-x*x/2);
}

void subint(double begin, double end, double m, double& sq){
	double delta = (end - begin)/m;
	for (int i = 0; i < m; ++i){
		sq += delta*function(begin + delta*i);
	}
}

double integral(int number_of_threads, int number_of_points){
	std::vector<std::thread> threads;
	double k1 = -0.5;
	double k3 = 0.5;
	double t1 = 0, t2 = 0;
	double k2 = k1 + (k3 - k1)/number_of_threads;
	std::vector<double> sq;
	sq.resize(number_of_threads);
	int m = number_of_points/number_of_threads;
	for(int i = 0; i < number_of_threads; ++i){
		t1 = k1 + i*(k3 - k1)/number_of_threads;
		t2 = k2 + i*(k3 - k1)/number_of_threads;
		sq.at(i) = 0;
		std::thread th(subint, t1, t2, m, std::ref(sq.at(i)));
		threads.push_back(std::move(th));
	}
	for(int i = 0; i < number_of_threads; ++i){
		threads.at(i).join();
	}
	double res = 0;
	for(int i = 0; i < number_of_threads; ++i){
		res += sq.at(i);
	}
	return res;
}

int main(){
	std::cout << integral(64, 50000000);
}
