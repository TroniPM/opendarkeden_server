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
VSHOME  = ../../..
STLDIR  = /usr/include/STL
BINDIR  = $(VSHOME)/bin
LIBDIR  = $(VSHOME)/lib
LOGDIR  = $(VSHOME)/log
DBINCDIR  = /usr/include/mysql
SRCDIR  = ../..
COREDIR = ../../Core
SERVDIR = ..
DBDIR   = ../database
MYSQLDIR = /usr/lib/mysql

#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__SHARED_SERVER__ -D__DEBUG__
INCLUDES = -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(DBINCDIR) -I.
CCFLAGS  = -Wall -c -g 
#CCFLAGS  = -Wall -c
LIBS     = -L$(LIBDIR) -lDatabase -lSharedServerPackets -lGameServerPackets -lServerCore -lCore
SYSLIBS  = -L$(MYSQLDIR) -static -lmysqlclient -lpthread -lnsl -lz -lssl -lcrypto -ldl

.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<


#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------
OBJS = \
	Guild.o GuildManager.o ResurrectLocationManager.o GameServerPlayer.o \
	HeartbeatManager.o GameServerInfoManager.o \
	GameServerGroupInfoManager.o GameServerManager.o \
	SharedServer.o main.o StringPool.o \

SRCS = $(OBJS:.o=.cpp)

TARGET = $(BINDIR)/sharedserver


#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
$(TARGET) : $(OBJS) $(LIBDIR)/libDatabase.a $(LIBDIR)/libGameServerPackets.a $(LIBDIR)/libSharedServerPackets.a $(LIBDIR)/libServerCore.a $(LIBDIR)/libCore.a
	$(CC) -o $@ $(OBJS) $(LIBS) $(SYSLIBS)

clean :
	rm -rf *.o

cleanall :
	rm -rf *.o $(TARGET)

depall :
	gccmakedep $(SRCS) $(INCLUDES)

dep :
	gccmakedep $(SRCS) $(INCLUDES)

# DO NOT DELETE
Guild.o: Guild.cpp \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/algorithm \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algobase.h \
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
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
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
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
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
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_construct.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/new \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/exception \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_uninitialized.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_algo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_heap.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tempbuf.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/memory \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/new_allocator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/limits Guild.h \
  ../../Core/Types.h ../../Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/localefwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/ios_base.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/atomicity.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/atomic_word.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/locale_classes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_function.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/basic_string.h \
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
  ../../Core/types/PlayerTypes.h ../../Core/types/SystemTypes.h \
  ../../Core/types/ObjectTypes.h ../../Core/types/CreatureTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/ZoneTypes.h \
  ../../Core/types/QuestTypes.h ../../Core/types/ShopTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/GuildTypes.h \
  ../../Core/types/WarTypes.h ../../Core/types/ServerType.h \
  ../../Core/Utility.h ../../Core/Types.h ../../Core/Assert.h \
  ../../Core/Exception.h ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../Core/Exception.h ../Mutex.h ../../Core/Types.h \
  ../../Core/Exception.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../../Core/VSDateTime.h ../../Core/StringStream.h ../database/DB.h \
  ../database/DatabaseManager.h ../../Core/Types.h ../../Core/Exception.h \
  ../database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h ../Mutex.h \
  ../database/Statement.h ../database/Result.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h ../../Core/GuildInfo.h \
  ../../Core/Packet.h ../../Core/SocketInputStream.h ../../Core/Socket.h \
  ../../Core/SocketImpl.h ../../Core/SocketAPI.h \
  ../../Core/SocketOutputStream.h ../../Core/Gpackets/GCGuildMemberList.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  ../../Core/Packet.h ../../Core/PacketFactory.h \
  ../../Core/GuildMemberInfo.h ../../Core/GuildMemberInfo.h
GuildManager.o: GuildManager.cpp Guild.h ../../Core/Types.h \
  ../../Core/types/SystemTypes.h \
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
  ../../Core/types/PlayerTypes.h ../../Core/types/SystemTypes.h \
  ../../Core/types/ObjectTypes.h ../../Core/types/CreatureTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/ZoneTypes.h \
  ../../Core/types/QuestTypes.h ../../Core/types/ShopTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/GuildTypes.h \
  ../../Core/types/WarTypes.h ../../Core/types/ServerType.h \
  ../../Core/Utility.h ../../Core/Types.h ../../Core/Assert.h \
  ../../Core/Exception.h ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../Core/Exception.h ../Mutex.h ../../Core/Types.h \
  ../../Core/Exception.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../../Core/VSDateTime.h GuildManager.h ../Timeval.h \
  /usr/include/sys/time.h /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../../Core/StringStream.h ../database/DB.h \
  ../database/DatabaseManager.h ../../Core/Types.h ../../Core/Exception.h \
  ../database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h ../Mutex.h \
  ../database/Statement.h ../database/Result.h ../../Core/Properties.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tree.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_map.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_multimap.h \
  ../../Core/Gpackets/GCWaitGuildList.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  ../../Core/Packet.h ../../Core/SocketInputStream.h ../../Core/Socket.h \
  ../../Core/SocketImpl.h ../../Core/SocketAPI.h \
  ../../Core/SocketOutputStream.h ../../Core/PacketFactory.h \
  ../../Core/Packet.h ../../Core/GuildInfo.h \
  ../../Core/Gpackets/GCActiveGuildList.h
ResurrectLocationManager.o: ResurrectLocationManager.cpp \
  ResurrectLocationManager.h ../../Core/Types.h \
  ../../Core/types/SystemTypes.h \
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
  ../../Core/types/PlayerTypes.h ../../Core/types/SystemTypes.h \
  ../../Core/types/ObjectTypes.h ../../Core/types/CreatureTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/ZoneTypes.h \
  ../../Core/types/QuestTypes.h ../../Core/types/ShopTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/GuildTypes.h \
  ../../Core/types/WarTypes.h ../../Core/types/ServerType.h \
  ../../Core/Utility.h ../../Core/Types.h ../../Core/Exception.h \
  ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../database/DB.h ../database/DatabaseManager.h ../../Core/Types.h \
  ../../Core/Exception.h ../database/Connection.h \
  /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
  /usr/include/mysql/mysql_com.h /usr/include/mysql/mysql_time.h \
  /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
  /usr/include/mysql/my_list.h ../Mutex.h ../../Core/Types.h \
  ../../Core/Exception.h ../database/Statement.h ../database/Result.h \
  /usr/include/sys/time.h /usr/include/gentoo-multilib/amd64/sys/time.h
GameServerPlayer.o: GameServerPlayer.cpp GameServerPlayer.h \
  ../../Core/Types.h ../../Core/types/SystemTypes.h \
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
  ../../Core/types/PlayerTypes.h ../../Core/types/SystemTypes.h \
  ../../Core/types/ObjectTypes.h ../../Core/types/CreatureTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/ZoneTypes.h \
  ../../Core/types/QuestTypes.h ../../Core/types/ShopTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/GuildTypes.h \
  ../../Core/types/WarTypes.h ../../Core/types/ServerType.h \
  ../../Core/Utility.h ../../Core/Types.h ../../Core/Exception.h \
  ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../Core/Player.h ../../Core/Exception.h ../../Core/Socket.h \
  ../../Core/SocketImpl.h ../../Core/SocketAPI.h \
  ../../Core/SocketInputStream.h ../../Core/Socket.h \
  ../../Core/SocketOutputStream.h ../../Core/Assert.h ../../Core/Packet.h \
  ../../Core/SocketInputStream.h ../../Core/SocketOutputStream.h \
  ../../Core/PacketFactoryManager.h ../../Core/Packet.h \
  ../../Core/PacketFactory.h
HeartbeatManager.o: HeartbeatManager.cpp HeartbeatManager.h \
  ../../Core/Types.h ../../Core/types/SystemTypes.h \
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
  ../../Core/types/PlayerTypes.h ../../Core/types/SystemTypes.h \
  ../../Core/types/ObjectTypes.h ../../Core/types/CreatureTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/ZoneTypes.h \
  ../../Core/types/QuestTypes.h ../../Core/types/ShopTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/GuildTypes.h \
  ../../Core/types/WarTypes.h ../../Core/types/ServerType.h \
  ../../Core/Utility.h ../../Core/Types.h ../../Core/Exception.h \
  ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../Core/Assert.h ../../Core/Exception.h
GameServerInfoManager.o: GameServerInfoManager.cpp \
  GameServerInfoManager.h ../../Core/Types.h \
  ../../Core/types/SystemTypes.h \
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
  ../../Core/types/PlayerTypes.h ../../Core/types/SystemTypes.h \
  ../../Core/types/ObjectTypes.h ../../Core/types/CreatureTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/ZoneTypes.h \
  ../../Core/types/QuestTypes.h ../../Core/types/ShopTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/GuildTypes.h \
  ../../Core/types/WarTypes.h ../../Core/types/ServerType.h \
  ../../Core/Utility.h ../../Core/Types.h ../../Core/Exception.h \
  ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  GameServerInfo.h ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../database/DB.h ../database/DatabaseManager.h ../../Core/Types.h \
  ../../Core/Exception.h ../database/Connection.h \
  /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
  /usr/include/mysql/mysql_com.h /usr/include/mysql/mysql_time.h \
  /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
  /usr/include/mysql/my_list.h ../Mutex.h ../../Core/Types.h \
  ../../Core/Exception.h ../database/Statement.h ../database/Result.h \
  /usr/include/sys/time.h /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../../Core/Properties.h ../../Core/Exception.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tree.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_map.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_multimap.h
GameServerGroupInfoManager.o: GameServerGroupInfoManager.cpp \
  GameServerGroupInfoManager.h ../../Core/Types.h \
  ../../Core/types/SystemTypes.h \
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
  ../../Core/types/PlayerTypes.h ../../Core/types/SystemTypes.h \
  ../../Core/types/ObjectTypes.h ../../Core/types/CreatureTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/ZoneTypes.h \
  ../../Core/types/QuestTypes.h ../../Core/types/ShopTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/GuildTypes.h \
  ../../Core/types/WarTypes.h ../../Core/types/ServerType.h \
  ../../Core/Utility.h ../../Core/Types.h ../../Core/Exception.h \
  ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  GameServerGroupInfo.h ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../database/DatabaseManager.h ../../Core/Types.h ../../Core/Exception.h \
  ../database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h ../Mutex.h \
  ../../Core/Types.h ../../Core/Exception.h ../database/Connection.h \
  ../database/Statement.h ../database/Result.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h ../database/DB.h \
  ../database/DatabaseManager.h ../database/Statement.h \
  ../database/Result.h
GameServerManager.o: GameServerManager.cpp /usr/include/stdio.h \
  /usr/include/gentoo-multilib/amd64/stdio.h /usr/include/features.h \
  /usr/include/gentoo-multilib/amd64/features.h /usr/include/sys/cdefs.h \
  /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
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
  GameServerManager.h ../Thread.h ../../Core/Types.h \
  ../../Core/types/SystemTypes.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ostream \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ios \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iosfwd \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++locale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
  /usr/include/string.h /usr/include/gentoo-multilib/amd64/string.h \
  /usr/include/xlocale.h /usr/include/gentoo-multilib/amd64/xlocale.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstdio \
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
  ../../Core/types/PlayerTypes.h ../../Core/types/SystemTypes.h \
  ../../Core/types/ObjectTypes.h ../../Core/types/CreatureTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/ZoneTypes.h \
  ../../Core/types/QuestTypes.h ../../Core/types/ShopTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/GuildTypes.h \
  ../../Core/types/WarTypes.h ../../Core/types/ServerType.h \
  ../../Core/Utility.h ../../Core/Types.h ../../Core/Exception.h \
  ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../pthreadAPI.h ../../Core/Types.h ../Timeval.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h ../../Core/Exception.h \
  GameServerPlayer.h ../../Core/Player.h ../../Core/Exception.h \
  ../../Core/ServerSocket.h ../../Core/SocketImpl.h \
  ../../Core/SocketAPI.h ../../Core/Socket.h ../Mutex.h \
  ../../Core/Assert.h ../../Core/SocketAPI.h ../../Core/Socket.h \
  ../../Core/Properties.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tree.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_map.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_multimap.h \
  Guild.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../../Core/VSDateTime.h GuildManager.h ../../Core/Packet.h \
  ../../Core/SocketInputStream.h ../../Core/SocketOutputStream.h \
  ../database/DB.h ../database/DatabaseManager.h ../../Core/Types.h \
  ../../Core/Exception.h ../database/Connection.h \
  /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
  /usr/include/mysql/mysql_com.h /usr/include/mysql/mysql_time.h \
  /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
  /usr/include/mysql/my_list.h ../Mutex.h ../database/Statement.h \
  ../database/Result.h
SharedServer.o: SharedServer.cpp SharedServer.h ../../Core/Types.h \
  ../../Core/types/SystemTypes.h \
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
  ../../Core/types/PlayerTypes.h ../../Core/types/SystemTypes.h \
  ../../Core/types/ObjectTypes.h ../../Core/types/CreatureTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/ZoneTypes.h \
  ../../Core/types/QuestTypes.h ../../Core/types/ShopTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/GuildTypes.h \
  ../../Core/types/WarTypes.h ../../Core/types/ServerType.h \
  ../../Core/Utility.h ../../Core/Types.h ../../Core/Exception.h \
  ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../Core/Assert.h ../../Core/Exception.h GameServerInfoManager.h \
  GameServerInfo.h ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  GameServerGroupInfoManager.h GameServerGroupInfo.h GameServerManager.h \
  ../Thread.h ../../Core/Types.h ../../Core/Exception.h ../pthreadAPI.h \
  ../Timeval.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h GameServerPlayer.h \
  ../../Core/Player.h ../../Core/ServerSocket.h ../../Core/SocketImpl.h \
  ../../Core/SocketAPI.h ../../Core/Socket.h ../Mutex.h \
  HeartbeatManager.h ../database/DatabaseManager.h ../../Core/Types.h \
  ../../Core/Exception.h ../database/Connection.h \
  /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
  /usr/include/mysql/mysql_com.h /usr/include/mysql/mysql_time.h \
  /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
  /usr/include/mysql/my_list.h ../Mutex.h \
  ../../Core/PacketFactoryManager.h ../../Core/Packet.h \
  ../../Core/SocketInputStream.h ../../Core/SocketOutputStream.h \
  ../../Core/PacketFactory.h ../../Core/PacketValidator.h \
  ../../Core/PacketIDSet.h ../../Core/PlayerStatus.h \
  ../GameWorldInfoManager.h ../GameWorldInfo.h ../../Core/StringStream.h \
  GuildManager.h ResurrectLocationManager.h StringPool.h ../LogClient.h
main.o: main.cpp ../../Core/Types.h ../../Core/types/SystemTypes.h \
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
  ../../Core/types/PlayerTypes.h ../../Core/types/SystemTypes.h \
  ../../Core/types/ObjectTypes.h ../../Core/types/CreatureTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/ZoneTypes.h \
  ../../Core/types/QuestTypes.h ../../Core/types/ShopTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/GuildTypes.h \
  ../../Core/types/WarTypes.h ../../Core/types/ServerType.h \
  ../../Core/Utility.h ../../Core/Types.h ../../Core/Exception.h \
  ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SharedServer.h ../LogClient.h ../../Core/Types.h \
  ../../Core/Properties.h ../../Core/Exception.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tree.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_map.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_multimap.h \
  ../../Core/StringStream.h /usr/include/sys/resource.h \
  /usr/include/gentoo-multilib/amd64/sys/resource.h \
  /usr/include/bits/resource.h \
  /usr/include/gentoo-multilib/amd64/bits/resource.h
StringPool.o: StringPool.cpp StringPool.h ../../Core/Exception.h \
  ../../Core/Types.h ../../Core/types/SystemTypes.h \
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
  ../../Core/types/PlayerTypes.h ../../Core/types/SystemTypes.h \
  ../../Core/types/ObjectTypes.h ../../Core/types/CreatureTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/ZoneTypes.h \
  ../../Core/types/QuestTypes.h ../../Core/types/ShopTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/GuildTypes.h \
  ../../Core/types/WarTypes.h ../../Core/types/ServerType.h \
  ../../Core/Utility.h ../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../database/DB.h ../database/DatabaseManager.h ../../Core/Types.h \
  ../../Core/Exception.h ../database/Connection.h \
  /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
  /usr/include/mysql/mysql_com.h /usr/include/mysql/mysql_time.h \
  /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
  /usr/include/mysql/my_list.h ../Mutex.h ../../Core/Types.h \
  ../../Core/Exception.h ../database/Statement.h ../database/Result.h \
  /usr/include/sys/time.h /usr/include/gentoo-multilib/amd64/sys/time.h
