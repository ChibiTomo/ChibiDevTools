#ifndef CDT_TEST_HPP#define CDT_TEST_HPP
#include "test_macro.hpp"
#define BEGIN_TEST _BEGIN_TEST#define END_TEST _END_TEST#define DESCRIBE(DESCRIPTION) _DESCRIBE(DESCRIPTION)#define END_DESCRIBE _END_DESCRIBE#define BEFORE_EACH(BODY...) _BEFORE_EACH(BODY)#define AFTER_EACH(BODY...) _AFTER_EACH(BODY)#define IT(DESCRIPTION) _IT(DESCRIPTION)#define END_IT _END_IT#define SHOULD_NOT_THROW(CODE...) _SHOULD_NOT_THROW(CODE)#define SHOULD_NOT_THROW_TYPE(T, CODE...) _SHOULD_NOT_THROW_TYPE(T, CODE)#define SHOULD_THROW(CODE...) _SHOULD_THROW(CODE)#define SHOULD_THROW_TYPE(T, CODE...) _SHOULD_THROW_TYPE(T, CODE)#define SHOULD(T, VAR) _SHOULD(T, VAR)#define BE(VALUE) _BE(VALUE)#define NOT _NOT

namespace cdt {

void run_test(const std::vector<cdt::TestCase>* testcaseList);

} // cdt#endif // CDT_TEST_HPP