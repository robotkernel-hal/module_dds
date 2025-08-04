ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libmodule_dds.la

libmodule_dds_la_SOURCES  = dds.cpp
libmodule_dds_la_CPPFLAGS = -Wall -I$(srcdir) -I$(builddir) \
                                    @ROBOTKERNEL_CFLAGS@ @SERVICE_PROVIDER_PROCESS_DATA_INSPECTION_CFLAGS@
libmodule_dds_la_LDFLAGS  = -Wall -release $(PACKAGE_VERSION)

