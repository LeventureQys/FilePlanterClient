#pragma once

#include <QtCore/qglobal.h>

# if defined(LGQTNETWORK_LIB)
#  define LGQTNETWORK_EXPORT Q_DECL_EXPORT
# else
#  define LGQTNETWORK_EXPORT Q_DECL_IMPORT
# endif