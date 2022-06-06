if ENABLE_EXAMPLES
AM_CFLAGS = -std=c99 -pedantic -O0 -g -I ../src/ $(COLLECTIONS_CFLAGS) $(XTD_CFLAGS)
LDADD = -L$(top_builddir)/lib/ $(top_builddir)/lib/.libs/libobj.a $(COLLECTIONS_LIBS) $(XTD_LIBS)

examples = $(top_builddir)/bin/create-obj \
		   $(top_builddir)/bin/parse-obj

__top_builddir__bin_create_obj_SOURCES = create-obj.c
__top_builddir__bin_parse_obj_SOURCES = parse-obj.c


bin_PROGRAMS = $(examples)

endif
