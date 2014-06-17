ACLOCAL_AMFLAGS = -I ./../aclocal

SUBDIRS = shared 
SUBDIRS += schedsim_priority
SUBDIRS += schedsim_simple
SUBDIRS += schedsim_cbs 
SUBDIRS += schedsim_edf

DIST_SUBDIRS = shared
DIST_SUBDIRS += shared
DIST_SUBDIRS += schedsim_priority
DIST_SUBDIRS += schedsim_simple
DIST_SUBDIRS += schedsim_cbs
DIST_SUBDIRS += schedsim_edf

if HAS_SMP
SUBDIRS += schedsim_smpsimple
SUBDIRS += schedsim_smppriority
SUBDIRS += schedsim_smppriority_affinity
SUBDIRS += schedsim_cluster01
SUBDIRS += schedsim_cluster02

DIST_SUBDIRS += schedsim_smpsimple
DIST_SUBDIRS += schedsim_smppriority
DIST_SUBDIRS += schedsim_smppriority_affinity
DIST_SUBDIRS += schedsim_cluster01
DIST_SUBDIRS += schedsim_cluster02
endif

include $(top_srcdir)/../automake/subdirs.am
include $(top_srcdir)/../automake/host.am
