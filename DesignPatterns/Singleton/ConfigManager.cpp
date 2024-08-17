#include "ConfigManager.h"

unique_ptr<ConfigManager> ConfigManager::m_instance;
once_flag ConfigManager::m_flag;
