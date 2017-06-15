#ifndef CDT_TEST_MACRO_HPP
#define CDT_TEST_MACRO_HPP

#include <string>
#include <cdt/core/macro.h>
#include "Tester.hpp"

#define _BEGIN_TEST \
	int main() { \
		std::vector<cdt::TestCase> testcaseList;

#define _END_TEST \
		cdt::run_test(&testcaseList); \
		return 0; \
	}

#define _DESCRIBE(DESCRIPTION) { \
	cdt::TestCase testCase; \
	testCase.beforeEach = cdt::Dummy::doNothing; \
	testCase.afterEach = cdt::Dummy::doNothing; \
	testCase.desc = std::string(DESCRIPTION);

#define _END_DESCRIBE \
	testcaseList.push_back(testCase); \
}

#define _BEFORE_EACH \
	struct BeforeEach { \
		static void process() {

#define _END_BEFORE_EACH \
		}; \
	}; \
	testCase.beforeEach = BeforeEach::process;

#define _AFTER_EACH(BODY...) \
	struct AfterEach { \
		static void process() {

#define _END_AFTER_EACH \
		}; \
	}; \
	testCase.afterEach = AfterEach::process;

#define _IT(DESCRIPTION) { \
	cdt::Test test; \
	test.desc = std::string(DESCRIPTION); \
	struct TestFxn { \
		static void process() {

#define _END_IT \
		}; \
	}; \
	test.test = TestFxn::process; \
	testCase.testList.push_back(test); \
}

#define _SHOULD_NOT_THROW _SHOULD_NOT_THROW_TYPE
#define _END_SHOULD_NOT_THROW _END_SHOULD_NOT_THROW_TYPE(std::exception)
#define _SHOULD_NOT_THROW_TYPE { \
	struct UNIQUE_NAME(ThrowFxn) { \
		static void process() {

#define _END_SHOULD_NOT_THROW_TYPE(T) }; \
	}; \
	cdt::Tester<T>::init(__FILE__, __LINE__).not_()._throw(UNIQUE_NAME(ThrowFxn)::process) \
		.reset(); \
}

#define _SHOULD_THROW _SHOULD_THROW_TYPE
#define _END_SHOULD_THROW _END_SHOULD_THROW_TYPE(std::exception)
#define _SHOULD_THROW_TYPE { \
	struct ThrowFxn { \
		static void process() {

#define _END_SHOULD_THROW_TYPE(T) }; \
	}; \
	cdt::Tester<T>::init(__FILE__, __LINE__)._throw(ThrowFxn::process) \
		.reset(); \
}

#define _SHOULD(T, VAR) cdt::Tester<T>::init(__FILE__, __LINE__).toTest(VAR)
#define _SHOULD_CONDITION(CONDITION) _SHOULD(bool, CONDITION)

#define _BE(VALUE) be(VALUE).reset()
#define _BE_NULL beNull().reset()
#define _NOT not_()

#endif // CDT_TEST_MACRO_HPP

