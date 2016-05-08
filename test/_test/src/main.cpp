#include "../../src/includes/test.hpp"

BEGIN_TEST

DESCRIBE("TEST")
	IT("1=1")
		int nbr = 1;
		SHOULD(int, nbr).BE(1);
	END_IT
	IT("1=2")
		int nbr = 1;
		SHOULD(int, nbr).BE(2);
	END_IT
	IT("1!=3")
		int nbr = 1;
		SHOULD(int, nbr).NOT.BE(2);
	END_IT
	IT("BE_NULL")
		int* nbr = nullptr;
		SHOULD(int, nbr).BE_NULL;
	END_IT
	IT("BE_NOT_NULL")
		int i = 1;
		int* nbr = &i;
		SHOULD(int, nbr).NOT.BE_NULL;
	END_IT
	IT("SHOULD_CONDITION")
		SHOULD_CONDITION(1==2).BE_FALSE;
		SHOULD_CONDITION(1==1).BE_TRUE;
	END_IT
END_DESCRIBE

END_TEST