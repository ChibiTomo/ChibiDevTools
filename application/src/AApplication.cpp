#include <iostream>
#include <string>

#include "AApplication.hpp"

namespace cdt {

int AApplication::start() {
	this->load();
	this->run();
	this->clean();
	return 0;
}

void AApplication::stop() {
}

void AApplication::getModules() {
}

ModulePtr AApplication::getModule(const std::string &p_role) {
	return nullptr;
}

int AApplication::addModule(const std::string &p_role, ModulePtr p_module) {
	std::cout << "Adding module: " << p_role << " " << p_module << std::endl;
	
	ModuleMap_t::iterator mod = m_modules.find(p_role);
	std::cout << "Module found: " << mod->second << std::endl;
	if (mod != m_modules.end()) {
		std::cout << "Module already added" << std::endl;
		return -1;
	}
	
	m_modules.insert(std::pair<const std::string&, ModulePtr>(p_role, p_module));
	return 0;
}

ModulePtr AApplication::replaceModule(const std::string &p_role, ModulePtr p_module) {
	ModuleMap_t::iterator mod = m_modules.find(p_role);
	m_modules.insert(std::pair<const std::string&, ModulePtr>(p_role, p_module));
	return mod->second;
}

ModulePtr AApplication::removeModule(const std::string &p_role) {
	return nullptr;
}

bool AApplication::hasModule(const std::string &p_role) {
	ModuleMap_t::iterator mod = m_modules.find(p_role);
	return mod != m_modules.end();
}

} // namespace cdt
