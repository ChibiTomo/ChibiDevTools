#ifndef CDT_CORE_STRINGUTILS_HPP
#define CDT_CORE_STRINGUTILS_HPP

#include <string>
#include <vector>

#include "includes/libexport.h"

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
	static std::string getPadding(const std::string& str, const char c, size_t length);
	StringUtils() {};
	~StringUtils() {};
	StringUtils(const StringUtils& other);
	StringUtils& operator=(const StringUtils& other);
};

} // cdt

#endif // CDT_CORE_STRINGUTILS_HPP
