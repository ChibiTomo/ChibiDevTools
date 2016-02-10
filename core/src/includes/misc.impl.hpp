#ifndef CDT_CORE_MISC_IMPL_H
#define CDT_CORE_MISC_IMPL_H

#include <boost/type_traits/is_base_of.hpp>

namespace cdt {

template <typename Base, typename T>
inline bool instanceOf(const T* ptr) {
    bool result = instanceOf<Base, T>();

    if (!result) {
        result = dynamic_cast<const Base*>(ptr) != NULL;
    }

    return result;
}

template <typename Base, typename T>
inline bool instanceOf() {
    return boost::is_base_of<Base, T>::value;
}

} // cdt

#endif // CDT_CORE_MISC_IMPL_H
