#ifndef CDT_TEST_TESTEXCEPTION_H
#define CDT_TEST_TESTEXCEPTION_H

#include <exception>
#include <string>

#define ASSERT(CONDITION) ASSERT_MSG(CONDITION, #CONDITION)
#define ASSERT_NOT_NULL(PTR) ASSERT_MSG(PTR != nullptr, "NullPointerException")
#define ASSERT_MSG(CONDITION, MSG) if (!(CONDITION)) throw cdt::TestException(MSG)

#define ASSERT_THROW_MSG(CONDITION, TYPE, MSG) if (!(CONDITION)) throw TYPE(MSG)

namespace cdt {

struct TestException : public std::exception {
	public:
		TestException(const std::string& msg = "");
		virtual ~TestException() throw();

		virtual const char* what() const throw();

	private:
		std::string m_msg;
};

} // namespace cdt

#endif // CDT_TEST_TESTEXCEPTION_H
