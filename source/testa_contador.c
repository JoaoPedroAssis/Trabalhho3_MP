#define CATCH_CONFIG_MAIN
#include "../include/contador.h"
#include "../include/catch.hpp"
#include <stdio.h>


TEST_CASE("Código sem espaços"){
	REQUIRE(contador("../test_cases/test1.c",1,1) == 8);
}

TEST_CASE("Código sem espaços e com comentários"){

	
	REQUIRE(contador("../test_cases/test3.c",1,1) == 8);
}

TEST_CASE("Código com espaços"){

	
	REQUIRE(contador("../test_cases/test2.c",1,1) == 8);
}

TEST_CASE("Código com espaços e comentários"){

	REQUIRE(contador("../test_cases/test4.c",1,1) == 8);
}

TEST_CASE("Código com comentários dos dois tipo e espaços"){


	REQUIRE(contador("../test_cases/test5.c",1,1) == 8);
}