#pragma once

#include <QtCore/qglobal.h>

#ifdef PLUGIN_LIB
# define Plugin_Export Q_DECL_EXPORT
#else
# define Plugin_Export Q_DECL_IMPORT
#endif // PLUGIN_LIB
