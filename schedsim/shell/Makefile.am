ACLOCAL_AMFLAGS = -I ./../aclocal

SUBDIRS = shared schedsim_priority
DIST_SUBDIRS = shared schedsim_priority

if HAS_SMP
SUBDIRS += schedsim_smpsimple
DIST_SUBDIRS += schedsim_smpsimple
endif

include $(top_srcdir)/../automake/subdirs.am
include $(top_srcdir)/../automake/host.am
