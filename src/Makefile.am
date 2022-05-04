# Add new files in alphabetical order. Thanks.
libobj_src = libobj.c

# Add new files in alphabetical order. Thanks.
libobj_headers = libobj.h

library_includedir      = $(includedir)/obj-@VERSION@/
library_include_HEADERS = $(libobj_headers)

# Library
lib_LTLIBRARIES                       = $(top_builddir)/lib/libobj.la
__top_builddir__lib_libobj_la_SOURCES = $(libobj_src)
__top_builddir__lib_libobj_la_CFLAGS  = -fPIC $(COLLECTIONS_CFLAGS) $(XTD_CFLAGS)
__top_builddir__lib_libobj_la_LIBADD  = $(COLLECTIONS_LIBS) $(XTD_LIBS)
