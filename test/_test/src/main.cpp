#include "../../src/includes/test.hpp"

#include <exception>

BEGIN_TEST

DESCRIBE("BE")
	IT("1=1")
		int nbr = 1;
		SHOULD(int, nbr).BE(1);
	END_IT
	IT("1=2, Should fail")
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

DESCRIBE("BEFORE_EACH")
    int x = 0;
    int y = 0;
    
    BEFORE_EACH
        x = 0;
    END_BEFORE_EACH

	IT("x=1")
        x++;
		SHOULD(int, x).BE(1);
        y++;
	END_IT
	IT("x=0")
		SHOULD(int, x).BE(0);
	END_IT
	IT("x=0,y=1,x+y=1")
		SHOULD(int, x).BE(0);
		SHOULD(int, y).BE(1);
        x+=y;
		SHOULD(int, x).BE(1);
	END_IT
END_DESCRIBE

DESCRIBE("AFTER_EACH")
    int x = 1;
    int y = 0;
    
    AFTER_EACH
        x = 0;
    END_AFTER_EACH

	IT("x=2")
        x++;
        y++;
		SHOULD(int, x).BE(2);
	END_IT
	IT("x=0")
		SHOULD(int, x).BE(0);
	END_IT
	IT("x=0,y=1,x+y=1")
		SHOULD(int, x).BE(0);
		SHOULD(int, y).BE(1);
        x+=y;
		SHOULD(int, x).BE(1);
	END_IT
END_DESCRIBE

DESCRIBE("THROW")
	IT("SHOULD_THROW")
		SHOULD_THROW
            throw std::exception();
        END_SHOULD_THROW
		SHOULD_THROW_TYPE
            throw 42;
        END_SHOULD_THROW_TYPE(int)
	END_IT
	IT("SHOULD_THROW, no throw => Should fail")
		SHOULD_THROW
            int x = 0;
            x++;
        END_SHOULD_THROW
		SHOULD_THROW_TYPE
            throw 42;
        END_SHOULD_THROW_TYPE(int)
	END_IT
	IT("SHOULD_THROW, throw wrong type => Should be Error")
		SHOULD_THROW_TYPE
            throw "Hello";
        END_SHOULD_THROW_TYPE(int)
	END_IT
END_DESCRIBE

END_TEST