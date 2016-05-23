#include <vector>
#include <list>
#include <cstdlib> 
#include <iostream>
#include <iterator> 
#include <algorithm> 
#include <set>
#include <map>
#include <ctime>

int main() 
{

	std::list<unsigned int> randomnumber(100);
	for(auto& i: randomnumber)
	{
		i=std::rand() %101;
	}	
	
	std::vector<unsigned int> vec_randomnumber(100); //Oder randomnumber.size()
	std::copy(std::begin(randomnumber), std::end(randomnumber), std::begin(vec_randomnumber));
	
	std::set<unsigned int> number_list(std::begin(randomnumber), std::end(randomnumber)); //std::set ohne doppelte Werte (unique objects of type key)
	std::cout << "Soviele unterschiedliche Zahlen sind in der Liste: " << number_list.size()<<std::endl;	

	std::cout << "Folgende Werte sind nicht in der Liste" << std::endl;
	for(int i = 0; i<=100; i++)
	{
		if(number_list.count(i)!=true)
		{
			std::cout << i <<"\n";
		}
	}

	std::map<unsigned int, unsigned int> map_list; //map pair
	for(auto& i : randomnumber)
	{
		++map_list[i]; //Zählt Anzahl pro Zahl
	}

	std::cout<<"Zahl : Häufigkeit"<<std::endl;
	for(int i = 0; i<=100; i++)
	{
		std::cout<<i<<":"<<map_list[i]<<std::endl;
	}
  


  return 0;

}
