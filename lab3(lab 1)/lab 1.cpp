#include <iostream>
#include <set>
#include <random>
#include <ctime>
#include <algorithm>
#include <fstream>                                                             

class State{
public:
	virtual bool contains(int s) const {};  	
};

class DiscreteState : public State {
private:
    int const state;

public:
    DiscreteState(int state): state(state) { }

    bool contains(int s) const {
        return s == state;
    }
};

class SegmentState : public State {
private:
    int const beg, end;
    
public:
    SegmentState(): beg(0), end(-1) { }
    SegmentState(int beg, int end): beg(beg), end(end) { }
    
    bool contains(int s) const {
        return s >= beg && s <= end;
    }
};

class SetState : public State {
private:
    std::set<int> const states;
    
public:
    SetState(): states() { }
    SetState(std::set<int> const &src): states(src) { }
    
    bool contains(int s) const {
        return states.count(s) > 0;
    }
};
/*
class SetSegmentState : public State {
	private:
		std::set<SegmentState> const segstates;
	public:
		bool contains(int s) const {
			int count = 0;
			for (SegmentState* i = &segstates[0]; i != &segstates[0] + segstates.size(); ++i){
				if (&i.contains(s))
					++count;
			}
			return count;
		}
};
*/
class ProbabilityTest {
private:
    unsigned seed;
    int test_min, test_max;
    unsigned test_count;
   
public:
    ProbabilityTest(unsigned seed, int test_min, int test_max, unsigned test_count): seed(seed), test_min(test_min),test_max(test_max), test_count(test_count) { }
    
    float operator() (State const &s) const {
		std::default_random_engine rng(seed);
        std::uniform_int_distribution<int> dstr(test_min,test_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (s.contains(dstr(rng))) ++good;
        
        return static_cast<float>(good)/static_cast<float>(test_count);
	}
};

int main(int argc, const char * argv[]) {
    DiscreteState d(1);
    SegmentState s(0,10);
    SetState ss({1, 3, 5, 7, 23, 48, 57, 60, 90, 99});
    std::ofstream fout("results.csv");                                                                  
    fout << "discrete" << ',' << "segment" << ',' << "set" << std::endl;
    for (int i = 10; i < 1000000; i += 1000){
    	ProbabilityTest pt(10,0,100, i);
    	fout << pt(d) << ',' << pt(s) << ',' << pt(ss) << ',' << pt(d)/(1.0/101.0) << ',' << pt(s)/(11.0/101.0) << ',' << pt(ss)/(10.0/101.0) << std::endl;
	}
	fout.close(); 
    return 0;
}
