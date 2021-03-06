#ifndef CDT_APPLICATION_IAPPLICATION_HPP
#define CDT_APPLICATION_IAPPLICATION_HPP

#include <string>

#include <boost/smart_ptr/shared_ptr.hpp>

#include "IModule.hpp"

namespace cdt {
	
typedef boost::shared_ptr<IModule> ModulePtr;

struct IApplication {
	virtual void load () = 0;
	virtual void run  () = 0;
	virtual void clean() = 0;

	virtual int	 start() = 0;
	virtual void stop () = 0;
 
	virtual void      getModules   ()                                              = 0;
	virtual ModulePtr getModule    (const std::string &p_role)                     = 0;
	virtual int       addModule    (const std::string &p_role, ModulePtr p_module) = 0;
	virtual ModulePtr replaceModule(const std::string &p_role, ModulePtr p_module) = 0;
	virtual ModulePtr removeModule (const std::string &p_role)                     = 0;
	virtual bool      hasModule    (const std::string &p_role)                     = 0;
};

} // namespace cdt

#endif // CDT_APPLICATION_IAPPLICATION_HPP
