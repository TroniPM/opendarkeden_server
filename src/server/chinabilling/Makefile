#----------------------------------------------------------------------
#
# Filename    : Makefile
# Written By  : Reiot
# Description :
#
#----------------------------------------------------------------------

#----------------------------------------------------------------------
# Directories Setting
#----------------------------------------------------------------------
VSHOME   = ../../..
STLDIR   = /usr/include/STL
BINDIR   = $(VSHOME)/bin
LIBDIR   = $(VSHOME)/lib
LOGDIR   = $(VSHOME)/log
SRCDIR   = $(VSHOME)/src
COREDIR  = $(SRCDIR)/Core
SERVDIR  = $(SRCDIR)/server
DBDIR    = $(SERVDIR)/database
GSDIR    = $(SERVDIR)/gameserver
LSDIR    = $(SERVDIR)/loginserver
BILLDIR  = $(GSDIR)/billing
MYSQLDIR = /usr/lib/mysql


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o .gs.o .ls.o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__DEBUG__
INCLUDES = -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(LSDIR) -I$(BILLDIR) -I.
INCLUDES_GS = -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(BILLDIR) -I.
INCLUDES_LS = -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(LSDIR) -I$(BILLDIR) -I.
#CCFLAGS  = -Wall -c -g 
CCFLAGS  = -Wall -c -g
#LIBS     = -L$(LIBDIR) -lGameServerDatabase -lServerCore -lCore
#SYSLIBS  = -L$(MYSQLDIR) -static -lpthread -lnsl -lmysqlclient -lz -lssl -lcrypto -ldl

# < for Library >
TARGET     = $(LIBDIR)/libCBilling.a
TARGET_GS  = $(LIBDIR)/libGameServerCBilling.a
TARGET_LS  = $(LIBDIR)/libLoginServerCBilling.a

#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------

# < for Test >
#TARGET = test/billingTest


#	main.o
OBJS = \
	CBillingPacketErrorBody.o \
	CBillingPacketResponseLoginBody.o \
	CBillingPacketHeader.o \
	CBillingPacketResponseLogoutBody.o \
	CBillingPacketRequestIntervalValidationBody.o \
	CBillingPacketResponseMinusMinuteBody.o \
	CBillingPacketRequestLoginBody.o \
	CBillingPacketResponseMinusPointBody.o \
	CBillingPacketRequestLogoutBody.o \
	CBillingPlayer.o \
	CBillingPacketRequestMinusMinuteBody.o \
	CBillingPlayerInfo.o \
	CBillingPacketRequestMinusPointBody.o \
	CBillingPlayerManager.o \
	CBillingPacketResponseIntervalValidationBody.o \

GS_OBJS = \
	CBillingPacketErrorBody.gs.o \
	CBillingPacketResponseLoginBody.gs.o \
	CBillingPacketHeader.gs.o \
	CBillingPacketResponseLogoutBody.gs.o \
	CBillingPacketRequestIntervalValidationBody.gs.o \
	CBillingPacketResponseMinusMinuteBody.gs.o \
	CBillingPacketRequestLoginBody.gs.o \
	CBillingPacketResponseMinusPointBody.gs.o \
	CBillingPacketRequestLogoutBody.gs.o \
	CBillingPlayer.gs.o \
	CBillingPacketRequestMinusMinuteBody.gs.o \
	CBillingPlayerInfo.gs.o \
	CBillingPacketRequestMinusPointBody.gs.o \
	CBillingPlayerManager.gs.o \
	CBillingPacketResponseIntervalValidationBody.gs.o \

LS_OBJS = \
	CBillingPacketErrorBody.ls.o \
	CBillingPacketResponseLoginBody.ls.o \
	CBillingPacketHeader.ls.o \
	CBillingPacketResponseLogoutBody.ls.o \
	CBillingPacketRequestIntervalValidationBody.ls.o \
	CBillingPacketResponseMinusMinuteBody.ls.o \
	CBillingPacketRequestLoginBody.ls.o \
	CBillingPacketResponseMinusPointBody.ls.o \
	CBillingPacketRequestLogoutBody.ls.o \
	CBillingPlayer.ls.o \
	CBillingPacketRequestMinusMinuteBody.ls.o \
	CBillingPlayerInfo.ls.o \
	CBillingPacketRequestMinusPointBody.ls.o \
	CBillingPlayerManager.ls.o \
	CBillingPacketResponseIntervalValidationBody.ls.o \

SRCS = $(GS_OBJS:.gs.o=.cpp)



#.cpp.o :
#	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS)  $(INCLUDES) -o $*.o $<

.cpp.gs.o :
	$(CC) $(CCFLAGS) $(DEFS)  -D__GAME_SERVER__ $(INCLUDES_GS) -o $*.gs.o $<

.cpp.ls.o :
	$(CC) $(CCFLAGS) $(DEFS)  -D__LOGIN_SERVER__ $(INCLUDES_LS) -o $*.ls.o $<

#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
#all : $(TARGET)
all : $(TARGET_GS) $(TARGET_LS) $(TARGET)

allgameserver : $(TARGET_GS)

allloginserver : $(TARGET_LS)

# < for Library >
$(TARGET_GS) : $(GS_OBJS)
	ar r $@ $(GS_OBJS)

$(TARGET_LS) : $(LS_OBJS)
	ar r $@ $(LS_OBJS)

$(TARGET) : $(OBJS)
	ar r $@ $(OBJS)

# < for Test >
#$(TARGET) : $(OBJS) $(LIBDIR)/libGameServerDatabase.a $(LIBDIR)/libServerCore.a $(LIBDIR)/libCore.a 
#	$(CC) -o $@ $(OBJS) $(LIBS) $(SYSLIBS)


clean :
	rm -rf *.o

cleanall :
	rm -rf *.o $(TARGET_GS) $(TARGET_LS) $(TARGET)

cleanloginserver :
	rm -rf *.ls.o

cleangameserver :
	rm -rf *.gs.o

depall :
	gccmakedep $(SRCS) $(INCLUDES)

dep :
	gccmakedep $(SRCS) $(INCLUDES)

# DO NOT DELETE
CBillingPacketErrorBody.o: CBillingPacketErrorBody.cpp \
  CBillingPacketErrorBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPacketResponseLoginBody.o: CBillingPacketResponseLoginBody.cpp \
  CBillingPacketResponseLoginBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPacketHeader.o: CBillingPacketHeader.cpp CBillingPacketHeader.h \
  CBillingInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h /usr/include/time.h \
  /usr/include/gentoo-multilib/amd64/time.h /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h /usr/include/signal.h \
  /usr/include/gentoo-multilib/amd64/signal.h /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  ../../../src/Core/Exception.h ../../../src/Core/Types.h \
  ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../src/Core/SocketInputStream.h ../../../src/Core/Exception.h \
  ../../../src/Core/Socket.h ../../../src/Core/SocketImpl.h \
  ../../../src/Core/SocketAPI.h ../../../src/Core/SocketOutputStream.h \
  ../../../src/Core/Properties.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tree.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_map.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_multimap.h
CBillingPacketResponseLogoutBody.o: CBillingPacketResponseLogoutBody.cpp \
  CBillingPacketResponseLogoutBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPacketRequestIntervalValidationBody.o:  \
 CBillingPacketRequestIntervalValidationBody.cpp \
  CBillingPacketRequestIntervalValidationBody.h \
  ../../../src/Core/Exception.h ../../../src/Core/Types.h \
  ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h CBillingPlayerManager.h \
  ../../../src/Core/Types.h ../../../src/server/Thread.h \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  ../../../src/server/pthreadAPI.h ../../../src/Core/Socket.h \
  ../../../src/server/Mutex.h
CBillingPacketResponseMinusMinuteBody.o:  \
 CBillingPacketResponseMinusMinuteBody.cpp \
  CBillingPacketResponseMinusMinuteBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPacketRequestLoginBody.o: CBillingPacketRequestLoginBody.cpp \
  CBillingPacketRequestLoginBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPacketResponseMinusPointBody.o:  \
 CBillingPacketResponseMinusPointBody.cpp \
  CBillingPacketResponseMinusPointBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPacketRequestLogoutBody.o: CBillingPacketRequestLogoutBody.cpp \
  CBillingPacketRequestLogoutBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPlayer.o: CBillingPlayer.cpp CBillingPlayer.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../src/Core/Player.h ../../../src/Core/Exception.h \
  ../../../src/Core/Socket.h ../../../src/Core/SocketImpl.h \
  ../../../src/Core/SocketAPI.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Socket.h ../../../src/Core/SocketOutputStream.h \
  ../../../src/Core/Assert.h ../../../src/Core/Packet.h \
  ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/SocketOutputStream.h CBillingPlayerManager.h \
  ../../../src/server/Thread.h ../../../src/Core/Types.h \
  ../../../src/Core/Exception.h ../../../src/server/pthreadAPI.h \
  ../../../src/server/Mutex.h CBillingInfo.h CBillingPacketHeader.h \
  CBillingPacketErrorBody.h /usr/include/bits/signum.h \
  /usr/include/gentoo-multilib/amd64/bits/signum.h \
  /usr/include/bits/siginfo.h \
  /usr/include/gentoo-multilib/amd64/bits/siginfo.h \
  /usr/include/bits/sigaction.h \
  /usr/include/gentoo-multilib/amd64/bits/sigaction.h \
  /usr/include/bits/sigcontext.h \
  /usr/include/gentoo-multilib/amd64/bits/sigcontext.h \
  /usr/include/bits/sigstack.h \
  /usr/include/gentoo-multilib/amd64/bits/sigstack.h \
  /usr/include/sys/ucontext.h \
  /usr/include/gentoo-multilib/amd64/sys/ucontext.h \
  /usr/include/bits/sigthread.h \
  /usr/include/gentoo-multilib/amd64/bits/sigthread.h
CBillingPacketRequestMinusMinuteBody.o:  \
 CBillingPacketRequestMinusMinuteBody.cpp \
  CBillingPacketRequestMinusMinuteBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPlayerInfo.o: CBillingPlayerInfo.cpp CBillingPlayerInfo.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../src/server/Timeval.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h CBillingInfo.h \
  ../../../src/Core/VSDateTime.h ../../../src/Core/StringStream.h
CBillingPacketRequestMinusPointBody.o:  \
 CBillingPacketRequestMinusPointBody.cpp \
  CBillingPacketRequestMinusPointBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPlayerManager.o: CBillingPlayerManager.cpp \
  CBillingPlayerManager.h ../../../src/Core/Types.h \
  ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../src/server/Thread.h ../../../src/Core/Types.h \
  ../../../src/Core/Exception.h ../../../src/server/pthreadAPI.h \
  ../../../src/Core/Socket.h ../../../src/Core/Exception.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/server/Mutex.h CBillingInfo.h CBillingPlayer.h \
  ../../../src/Core/Player.h ../../../src/Core/Assert.h \
  ../../../src/Core/Properties.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tree.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_map.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_multimap.h \
  ../../../src/server/database/DB.h \
  ../../../src/server/database/DatabaseManager.h \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../../../src/server/database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h \
  ../../../src/server/Mutex.h ../../../src/server/database/Statement.h \
  ../../../src/server/database/Result.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../../../src/server/Timeval.h
CBillingPacketResponseIntervalValidationBody.o:  \
 CBillingPacketResponseIntervalValidationBody.cpp \
  CBillingPacketResponseIntervalValidationBody.h \
  ../../../src/Core/Exception.h ../../../src/Core/Types.h \
  ../../../src/Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/include/features.h /usr/include/gentoo-multilib/amd64/features.h \
  /usr/include/sys/cdefs.h /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
  /usr/include/stdio.h /usr/include/gentoo-multilib/amd64/stdio.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h \
  /usr/include/libio.h /usr/include/gentoo-multilib/amd64/libio.h \
  /usr/include/_G_config.h /usr/include/gentoo-multilib/amd64/_G_config.h \
  /usr/include/wchar.h /usr/include/gentoo-multilib/amd64/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gentoo-multilib/amd64/bits/wchar.h /usr/include/gconv.h \
  /usr/include/gentoo-multilib/amd64/gconv.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/clocale \
  /usr/include/locale.h /usr/include/gentoo-multilib/amd64/locale.h \
  /usr/include/bits/locale.h \
  /usr/include/gentoo-multilib/amd64/bits/locale.h \
  /usr/include/langinfo.h /usr/include/gentoo-multilib/amd64/langinfo.h \
  /usr/include/nl_types.h /usr/include/gentoo-multilib/amd64/nl_types.h \
  /usr/include/iconv.h /usr/include/gentoo-multilib/amd64/iconv.h \
  /usr/include/libintl.h /usr/include/gentoo-multilib/amd64/libintl.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++io.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/gentoo-multilib/amd64/pthread.h \
  /usr/include/sched.h /usr/include/gentoo-multilib/amd64/sched.h \
  /usr/include/time.h /usr/include/gentoo-multilib/amd64/time.h \
  /usr/include/bits/sched.h \
  /usr/include/gentoo-multilib/amd64/bits/sched.h \
  /usr/include/bits/time.h /usr/include/gentoo-multilib/amd64/bits/time.h \
  /usr/include/signal.h /usr/include/gentoo-multilib/amd64/signal.h \
  /usr/include/bits/sigset.h \
  /usr/include/gentoo-multilib/amd64/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/gentoo-multilib/amd64/bits/pthreadtypes.h \
  /usr/include/bits/setjmp.h \
  /usr/include/gentoo-multilib/amd64/bits/setjmp.h /usr/include/unistd.h \
  /usr/include/gentoo-multilib/amd64/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/gentoo-multilib/amd64/bits/posix_opt.h \
  /usr/include/bits/environments.h \
  /usr/include/gentoo-multilib/amd64/bits/environments.h \
  /usr/include/bits/confname.h \
  /usr/include/gentoo-multilib/amd64/bits/confname.h \
  /usr/include/getopt.h /usr/include/gentoo-multilib/amd64/getopt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cctype \
  /usr/include/ctype.h /usr/include/gentoo-multilib/amd64/ctype.h \
  /usr/include/endian.h /usr/include/gentoo-multilib/amd64/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/postypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwchar \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ctime \
  /usr/include/stdint.h /usr/include/gentoo-multilib/amd64/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/functexcept.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/climits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/syslimits.h \
  /usr/include/limits.h /usr/include/gentoo-multilib/amd64/limits.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/local_lim.h \
  /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/posix2_lim.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/gentoo-multilib/amd64/bits/xopen_lim.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdlib \
  /usr/include/stdlib.h /usr/include/gentoo-multilib/amd64/stdlib.h \
  /usr/include/bits/waitflags.h \
  /usr/include/gentoo-multilib/amd64/bits/waitflags.h \
  /usr/include/bits/waitstatus.h \
  /usr/include/gentoo-multilib/amd64/bits/waitstatus.h \
  /usr/include/sys/types.h /usr/include/gentoo-multilib/amd64/sys/types.h \
  /usr/include/sys/select.h \
  /usr/include/gentoo-multilib/amd64/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/gentoo-multilib/amd64/bits/select.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/gentoo-multilib/amd64/sys/sysmacros.h \
  /usr/include/alloca.h /usr/include/gentoo-multilib/amd64/alloca.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_pair.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/cpp_type_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/concept_check.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/debug/debug.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/streambuf \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/streambuf_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cwctype \
  /usr/include/wctype.h /usr/include/gentoo-multilib/amd64/wctype.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/ctype_inline.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/codecvt.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/time_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/messages_members.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_ios.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ostream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/locale \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_facets.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/typeinfo \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/istream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/istream.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/fstream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/basic_file.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/fstream.tcc \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
