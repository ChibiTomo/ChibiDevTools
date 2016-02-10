#include <cdt/test/test.hpp>

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
END_DESCRIBE

END_TEST