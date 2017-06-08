#include <random>
#include <iostream>
#include <map>
#include <random>
#include <iterator>


void subScene::generate_map() {
	
	int x_Size;
	int y_Size;
	srand(time(NULL));

	std::vector<double> tmp;
	
	double cell = ((double(rand()) / double(6)) * (9)) -3;
	tmp.push_back(cell);
	column += 1;
	map.push_back(tmp);
	tmp.clear;
	row+=1;
}


void subScene::generate_map2() {

	int x_Size;
	int y_Size;

	std::random_device rd;
	random::mt19937 gen(rd());
	double weights[] = {




	}
	std::discrete_distribution<> d(std::begin(weights), std::end(weights));
	std::map<int, int> m;

	for(int n=0; n<10000; ++n) {
        ++m[d(gen)];
    }
    for(auto p : m) {
        std::cout << p.first << " generated " << p.second << " times\n";
    }

}

//cellular automata version
void subScene::generate_map3() {
	float chance_of_being_wall;
	float chance_of_being_hole;
	

}