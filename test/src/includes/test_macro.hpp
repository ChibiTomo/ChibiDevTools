#ifndef CDT_TEST_MACRO_HPP
#define CDT_TEST_MACRO_HPP

#include <string>
#include <cdt/core/macro.h>
#include "Tester.hpp"

#define _BEGIN_TEST \
	int main() { \
		std::vector<cdt::TestCase> testcaseList; \
        auto doNothing = [] ()->int { return 0; }; \
        bool disabled = false;

#define _END_TEST \
		cdt::run_test_list(&testcaseList); \
		return 0; \
	}

#define _DISABLE disabled = true;

#define _DESCRIBE(DESCRIPTION) { \
	cdt::TestCase testCase; \
	testCase.beforeEach = doNothing; \
	testCase.afterEach = doNothing; \
	testCase.desc = std::string(DESCRIPTION); \
	testCase.disabled = disabled; \
    disabled = false;

#define _END_DESCRIBE \
	testcaseList.push_back(testCase); \
}

#define _BEFORE_EACH \
    auto beforeEach_l = [&] ()->int {
#define _END_BEFORE_EACH \
        return 0; \
    }; \
	testCase.beforeEach = beforeEach_l;

#define _AFTER_EACH \
    auto afterEach_l = [&] ()->int {

#define _END_AFTER_EACH \
        return 0; \
    }; \
	testCase.afterEach = afterEach_l;

#define _IT(DESCRIPTION) { \
	cdt::Test test; \
	test.desc = std::string(DESCRIPTION); \
	test.disabled = disabled; \
    disabled = false; \
    auto testFxn_l = [&] ()->int { \
        int testDisabledNbr = 0;

#define _END_IT \
        return testDisabledNbr; \
	}; \
	test.test = testFxn_l; \
	testCase.testList.push_back(test); \
}

#define _SHOULD_NOT_THROW _SHOULD_NOT_THROW_TYPE
#define _END_SHOULD_NOT_THROW _END_SHOULD_NOT_THROW_TYPE(std::exception)
#define _SHOULD_NOT_THROW_TYPE { \
    auto noThrowFxn_l = [&] ()->int {

#define _END_SHOULD_NOT_THROW_TYPE(T) \
        return 0; \
	}; \
	_INIT_TESTER(T)._NOT._throw(noThrowFxn_l).reset(); \
}

#define _SHOULD_THROW _SHOULD_THROW_TYPE
#define _END_SHOULD_THROW _END_SHOULD_THROW_TYPE(std::exception)
#define _SHOULD_THROW_TYPE { \
    auto throwFxn_l = [&] ()->int {

#define _END_SHOULD_THROW_TYPE(T) \
        return 0; \
	}; \
	_INIT_TESTER(T)._throw(throwFxn_l).reset(); \
}

#define _SHOULD(T, VAR) _INIT_TESTER(T).toTest(VAR)
#define _SHOULD_CONDITION(CONDITION) _SHOULD(bool, CONDITION)

#define _BE(VALUE) be(VALUE).reset(); disabled = false
#define _BE_NULL beNull().reset(); disabled = false
#define _NOT not_()

#define _INIT_TESTER(T) if (disabled) { testDisabledNbr++; } cdt::Tester<T>::init(__FILE__, __LINE__, disabled)

#define VAR(NAME) tester_##NAME##_variable
#define FXN(NAME) tester_##NAME##_function

#endif // CDT_TEST_MACRO_HPP

