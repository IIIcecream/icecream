#pragma once

#include <QtCore/qglobal.h>

#ifdef DDExportTest_LIB
# define DDExportTest_EXPORT Q_DECL_EXPORT
#else
# define DDExportTest_EXPORT Q_DECL_IMPORT
#endif

