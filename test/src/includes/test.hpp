#ifndef CDT_TEST_HPP
#define CDT_TEST_HPP

#include "test_macro.hpp"

#define BEGIN_TEST _BEGIN_TEST
#define END_TEST _END_TEST

#define DISABLE _DISABLE

#define DESCRIBE(DESCRIPTION) _DESCRIBE(DESCRIPTION)
#define END_DESCRIBE _END_DESCRIBE

#define BEFORE_EACH _BEFORE_EACH
#define END_BEFORE_EACH _END_BEFORE_EACH

#define AFTER_EACH _AFTER_EACH
#define END_AFTER_EACH _END_AFTER_EACH

#define IT(DESCRIPTION) _IT(DESCRIPTION)
#define END_IT _END_IT

#define SHOULD_NOT_THROW _SHOULD_NOT_THROW
#define END_SHOULD_NOT_THROW _END_SHOULD_NOT_THROW
#define SHOULD_NOT_THROW_TYPE _SHOULD_NOT_THROW_TYPE
#define END_SHOULD_NOT_THROW_TYPE(T) _END_SHOULD_NOT_THROW_TYPE(T)

#define SHOULD_THROW _SHOULD_THROW
#define END_SHOULD_THROW _END_SHOULD_THROW
#define SHOULD_THROW_TYPE _SHOULD_THROW_TYPE
#define END_SHOULD_THROW_TYPE(T) _END_SHOULD_THROW_TYPE(T)

#define SHOULD(T, VAR) _SHOULD(T, VAR)
#define SHOULD_CONDITION(CONDITION) _SHOULD_CONDITION(CONDITION)

#define BE(VALUE) _BE(VALUE)
#define BE_TRUE _BE(true)
#define BE_FALSE _BE(false)
#define BE_NULL _BE_NULL
#define NOT _NOT

namespace cdt {
	
void run_test_list(const std::vector<cdt::TestCase>* testcaseList);


} // cdt

#endif // CDT_TEST_HPP

