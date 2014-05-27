ACLOCAL_AMFLAGS = -I ./../aclocal

SUBDIRS = shared schedsim_priority schedsim_simple
DIST_SUBDIRS = shared schedsim_priority schedsim_simple

if HAS_SMP
SUBDIRS += schedsim_smpsimple
DIST_SUBDIRS += schedsim_smpsimple
SUBDIRS += schedsim_smppriority
DIST_SUBDIRS += schedsim_smppriority
SUBDIRS += schedsim_smppriority_affinity
DIST_SUBDIRS += schedsim_smppriority_affinity
endif

include $(top_srcdir)/../automake/subdirs.am
include $(top_srcdir)/../automake/host.am
