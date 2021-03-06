#ifndef CDT_CORE_MISC_H
#define CDT_CORE_MISC_H

#include "libexport.h"

namespace cdt {

template <typename Base, typename T>
inline bool instanceOf(const T* ptr);

template <typename Base, typename T>
inline bool instanceOf();

bool CDT_API hasFlag(int value, int flag);

} // cdt

#include "misc.impl.hpp"

#endif // CDT_CORE_MISC_H
