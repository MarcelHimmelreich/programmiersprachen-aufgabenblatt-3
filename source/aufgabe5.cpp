#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "circle.hpp"
#include <algorithm>
#include <vector>
#include <cstdlib> 
#include <iterator> 
#include <iostream>

bool is_even(unsigned int i) 
{
	if (i % 2 == 0) 
		{
			return true;
		}

	else return false;
}

bool is_odd(unsigned int i)
{
	if (i % 2 == 0) 
		{
			return false;
		}

	else return true;
}

template <typename T> 
  void Swap (T& obj1, T& obj2){
    T temp = obj1; 
    obj1 = obj2; 
    obj2 = temp; 
  }


template<typename container, typename function>

	container filter(container const& C, function const& F)
	{
		container newCont;
		for(auto& i : C)
		{
			if(F(i))
			{
				newCont.push_back(i);
			}		
			
		}
		return newCont;
		
	}


class circles //Functor
{
public:
	bool operator()(Circle const& a, Circle const& b)
	{
		return a.get_radius() < b.get_radius();
	}

};


TEST_CASE("describe_sort", "[sort]") //mit Lambda 3.9
{
	std::vector<Circle> cs{ 1,3,2,5,4,6}; 

	std::sort(cs.begin(),cs.end(),
		[] (Circle const& c1,Circle const& c2) { return c1 < c2; }  //Lambda
	);


	REQUIRE(std::is_sorted(cs.begin(),cs.end()));
}

TEST_CASE("describe_sort1", "[sort1]") // Ohne Lambda 3.7
{
	std::vector<Circle> cs{ 1,3,2,5,4,6}; 

	std::sort(cs.begin(),cs.end());


	REQUIRE(std::is_sorted(cs.begin(),cs.end()));
}


TEST_CASE("describe_sortfunc", "[sort_func]") // 3.14 Functor
{
	std::vector<Circle> cs{ 1,3,2,5,4,6}; 

	std::sort(cs.begin(),cs.end(), circles() );


	REQUIRE(std::is_sorted(cs.begin(),cs.end()));
}



TEST_CASE("describe_add" ,"[transform]") //3.10

{
	std::vector<int> v1{1,2,3,4,5,6,7,8,9};
	std::vector<int> v2{9,8,7,6,5,4,3,2,1};
	std::vector<int> v3(5);

	std::transform(v1.begin(),v1.begin()+5,v2.begin(),v3.begin(), 
		[] (int a, int b) {return a+b;}
	);

	REQUIRE(std::all_of(v3.begin(),v3.end(),
	[] (int a) { return a==10;}   
	)); 
}



TEST_CASE("describe_swap","[swap]")  
{
Circle c1{1.0f};
Circle c2{2.0f};

Swap(c1,c2);
REQUIRE(c1==2.0f);
REQUIRE(c2==1.0f);

float eins = 1.0f;
float zwei = 2.0f;

Swap(eins,zwei);
REQUIRE(eins==2.0f);
REQUIRE(zwei==1.0f);
}

TEST_CASE("describe_eventemplate","[even]") //3.11
{
	std::vector<int> v{1,2,3,4,5,6};
	v=filter(v,is_even);

	REQUIRE(std::all_of(v.begin(),v.end(),is_even));
}


TEST_CASE("describe_copyif","[copy_if]") //3.13 optional
{
	std::vector<Circle> circles{{5.0f},{3.0f},{8.0f},{1.0f},{5.0f}};
	std::vector<Circle> remain_circ(3);

	std::copy_if(circles.begin(),circles.end(),
		remain_circ.begin(),
		[] (Circle a) {return a.get_radius() > 4.0f; }
		);

	REQUIRE(std::all_of( remain_circ.begin() , remain_circ.end() ,
		[] (Circle a) {return a.get_radius() > 3.0f; } 
		));
}


TEST_CASE("describe_factorial", "[is_even]")  //3.5
{
	std::vector<unsigned int> v(100);
	
	for(auto& i : v)
	{
		i = std::rand() % 101;
	}

	v.erase(std::remove_if(v.begin(), v.end(), is_odd),v.end());	
 
  REQUIRE(std::all_of(v.begin(), v.end(), is_even)); 

}

int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}



