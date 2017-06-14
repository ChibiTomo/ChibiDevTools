#ifndef CDT_APPLICATION_AAPPLICATION_HPP
#define CDT_APPLICATION_AAPPLICATION_HPP

#include <map>
#include <string>

#include "includes/IApplication.hpp"
#include "includes/IModule.hpp"

namespace cdt {

class AApplication : public IApplication {
	public:
		int  start() override;
		void stop () override;

		void      getModules   ()                                              override;
		ModulePtr getModule    (const std::string &p_role)                     override;
		int       addModule    (const std::string &p_role, ModulePtr p_module) override;
		ModulePtr replaceModule(const std::string &p_role, ModulePtr p_module) override;
		ModulePtr removeModule (const std::string &p_role)                     override;
		bool      hasModule    (const std::string &p_role)                     override;
	
	private:
		typedef std::map<const std::string, ModulePtr> ModuleMap_t;
		ModuleMap_t m_modules;
};

} // namespace cdt

#endif // CDT_APPLICATION_AAPPLICATION_HPP
