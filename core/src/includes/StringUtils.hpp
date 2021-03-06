#ifndef CDT_CORE_STRINGUTILS_HPP
#define CDT_CORE_STRINGUTILS_HPP

#include <string>
#include <vector>

#include "libexport.h"

#define STR_PAD_LEFT(str, c, length) cdt::StringUtils::padLeft(str, c, length)
#define STR_PAD_RIGHT(str, c, length) cdt::StringUtils::padRight(str, c, length)
#define STR_CENTER(str, c, length) cdt::StringUtils::center(str, c, length)

#define STR_STARTS_WITH(str, needle) cdt::StringUtils::strStartsWith(str, needle)
#define STR_ENDS_WITH(str, needle) cdt::StringUtils::strEndsWith(str, needle)

#define STR_SPLIT(str, delim) cdt::StringUtils::split(str, delim)
#define STR_JOIN(list, glue) cdt::StringUtils::join(list, glue)

#define STR_MAKE(FORMAT, ARGS...) cdt::StringUtils::makeString(FORMAT, ARGS)

namespace cdt {

class CDT_API StringUtils {
public:
	static std::string padLeft(const std::string& str, const char c, size_t length);
	static std::string padRight(const std::string& str, const char c, size_t length);
	static std::string center(const std::string& str, const char c, size_t length);

	static std::vector<std::string> split(const std::string &str, const std::string& delim);
	static std::string join(const std::vector<std::string> &list, const std::string& glue);

	static bool startsWith(const std::string& str, const std::string& needle);
	static bool endsWith(const std::string& str, const std::string& needle);
	static bool contains(const std::string& str, const std::string& needle);

	static std::string makeString(const std::string& format, ...);
	
private:
	StringUtils(const StringUtils& other);
	StringUtils& operator=(const StringUtils& other);
	StringUtils() {};
	~StringUtils() {};
};

} // cdt

#endif // CDT_CORE_STRINGUTILS_HPP
