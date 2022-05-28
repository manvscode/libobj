AC_PREREQ(2.67)
AC_INIT([obj], [1.0.0], [manvscode@gmail.com], [obj], [http://www.joemarrero.com/])
AM_INIT_AUTOMAKE([1.13 foreign silent-rules dist-zip -Wall -Werror])
#AC_CONFIG_MACRO_DIRS([m4])

# Enable silent build when possible.
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_CONFIG_HEADERS([src/libobj-config.h])

AC_PROG_CC
AC_PROG_CC_C99
AC_PROG_CC_STDC
AC_HEADER_STDC
AC_C_INLINE
AC_TYPE_SIZE_T

AH_TOP([
#ifndef _LIBOBJ_H_
#define _LIBOBJ_H_
])
AH_BOTTOM([
#endif /* _LIBOBJ_H_ */
])
AX_EXT

AM_PROG_AR
LT_INIT([static shared win32-dll])
AC_PROG_LIBTOOL
AM_PROG_LIBTOOL

PKG_CHECK_MODULES([XTD], [xtd-static],
	[AC_MSG_NOTICE([Found libxtd])],
	[AC_MSG_ERROR([Missing libxtd])],
)

PKG_CHECK_MODULES([COLLECTIONS], [collections-static],
	[AC_MSG_NOTICE([Found libcollections])],
	[AC_MSG_ERROR([Missing libcollections])],
)

AC_PROG_INSTALL

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	obj-static.pc
	obj.pc
])

AC_OUTPUT
