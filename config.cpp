
//
// Created by Administrator on 2017-8-5.
//

#include "config.h"

#ifdef QT_NO_DEBUG
bool Config::isDebug = false;
#else
bool Config::isDebug = true;
#endif

// 也可以
/*

#if defined(QT_NO_DEBUG)
bool Config::isDebug = false;
#else
bool Config::isDebug = true;
#endif

*/

