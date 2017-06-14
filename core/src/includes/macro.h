#ifndef CDT_CORE_MACRO_H
#define CDT_CORE_MACRO_H


#define CONCAT(a, b) CONCAT_HELPER(a, b)
#define CONCAT_HELPER(a, b) a ## b

#define UNIQUE_NAME(name) CONCAT(name, __LINE__)

#endif // CDT_CORE_MACRO_H
