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
BILLINGDIR = ../gameserver/billing

#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__LOGIN_SERVER__ -D__DEBUG__
INCLUDES = -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(DBINCDIR) -I$(BILLINGDIR) -I.
CCFLAGS  = -Wall -c -g -Wno-write-strings -Wno-sequence-point
#CCFLAGS  = -Wall -c
LIBS     = -L$(LIBDIR) -lLoginServerDatabase -lLoginServerPackets -lServerCore -lCore -lLoginServerCBilling -lLoginServerBilling
SYSLIBS  = -L$(MYSQLDIR) -static -lmysqlclient -lpthread -lnsl -lz -lssl -lcrypto -ldl

.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<


#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------
OBJS = \
	ClientManager.o UserInfoManager.o \
	GameServerGroupInfoManager.o GameServerManager.o \
	LoginPlayer.o LoginPlayerManager.o LoginServer.o \
	ZoneGroupInfoManager.o ZoneInfoManager.o main.o \
	ItemDestroyer.o ReconnectLoginInfoManager.o

SRCS = $(OBJS:.o=.cpp)

TARGET = $(BINDIR)/loginserver


#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
$(TARGET) : $(OBJS) $(LIBDIR)/libLoginServerDatabase.a $(LIBDIR)/libLoginServerPackets.a $(LIBDIR)/libServerCore.a $(LIBDIR)/libCore.a $(LIBDIR)/libLoginServerCBilling.a $(LIBDIR)/libLoginServerBilling.a
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
ClientManager.o: ClientManager.cpp /usr/include/stdc-predef.h \
 ../database/DatabaseManager.h ../../Core/Types.h \
 ../../Core/types/SystemTypes.h /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc ../../Core/types/PlayerTypes.h \
 ../../Core/types/SystemTypes.h ../../Core/types/ObjectTypes.h \
 ../../Core/types/CreatureTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/ZoneTypes.h ../../Core/types/QuestTypes.h \
 ../../Core/types/ShopTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/GuildTypes.h ../../Core/types/WarTypes.h \
 ../../Core/types/ServerType.h ../../Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../Core/Types.h ../../Core/Exception.h ../../Core/StringStream.h \
 /usr/include/c++/5/list /usr/include/c++/5/bits/stl_list.h \
 /usr/include/c++/5/bits/list.tcc /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h ../database/Connection.h \
 /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
 /usr/include/mysql/mysql_com.h /usr/include/mysql/binary_log_types.h \
 /usr/include/mysql/my_command.h /usr/include/mysql/mysql_time.h \
 /usr/include/mysql/my_list.h /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../Mutex.h ClientManager.h \
 ../../Core/Assert.h ../../Core/Exception.h LoginPlayerManager.h \
 ../PlayerManager.h ../Timeval.h /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/unistd.h /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 ../../Core/SocketAPI.h ../Mutex.h ../../Core/ServerSocket.h \
 ../../Core/SocketImpl.h ../../Core/SocketAPI.h ../../Core/Socket.h \
 ReconnectLoginInfoManager.h ReconnectLoginInfo.h ../Timeval.h \
 ../../Core/StringStream.h ../Profile.h ../PacketProfile.h \
 ../../Core/Properties.h ../GameWorldInfoManager.h ../GameWorldInfo.h \
 GameServerGroupInfoManager.h GameServerGroupInfo.h
UserInfoManager.o: UserInfoManager.cpp /usr/include/stdc-predef.h \
 UserInfoManager.h ../../Core/Types.h ../../Core/types/SystemTypes.h \
 /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc ../../Core/types/PlayerTypes.h \
 ../../Core/types/SystemTypes.h ../../Core/types/ObjectTypes.h \
 ../../Core/types/CreatureTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/ZoneTypes.h ../../Core/types/QuestTypes.h \
 ../../Core/types/ShopTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/GuildTypes.h ../../Core/types/WarTypes.h \
 ../../Core/types/ServerType.h ../../Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../Core/Types.h ../../Core/Exception.h ../../Core/StringStream.h \
 /usr/include/c++/5/list /usr/include/c++/5/bits/stl_list.h \
 /usr/include/c++/5/bits/list.tcc UserInfo.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h ../database/DatabaseManager.h \
 ../database/Connection.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../Mutex.h \
 ../database/Connection.h ../database/Statement.h ../database/Result.h \
 /usr/include/x86_64-linux-gnu/sys/time.h ../database/DB.h \
 ../database/DatabaseManager.h ../database/Statement.h \
 ../database/Result.h
GameServerGroupInfoManager.o: GameServerGroupInfoManager.cpp \
 /usr/include/stdc-predef.h GameServerGroupInfoManager.h \
 ../../Core/Types.h ../../Core/types/SystemTypes.h \
 /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc ../../Core/types/PlayerTypes.h \
 ../../Core/types/SystemTypes.h ../../Core/types/ObjectTypes.h \
 ../../Core/types/CreatureTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/ZoneTypes.h ../../Core/types/QuestTypes.h \
 ../../Core/types/ShopTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/GuildTypes.h ../../Core/types/WarTypes.h \
 ../../Core/types/ServerType.h ../../Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../Core/Types.h ../../Core/Exception.h ../../Core/StringStream.h \
 /usr/include/c++/5/list /usr/include/c++/5/bits/stl_list.h \
 /usr/include/c++/5/bits/list.tcc GameServerGroupInfo.h \
 ../../Core/StringStream.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h ../database/DatabaseManager.h \
 ../database/Connection.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../Mutex.h \
 ../database/Connection.h ../database/Statement.h ../database/Result.h \
 /usr/include/x86_64-linux-gnu/sys/time.h ../database/DB.h \
 ../database/DatabaseManager.h ../database/Statement.h \
 ../database/Result.h
GameServerManager.o: GameServerManager.cpp /usr/include/stdc-predef.h \
 GameServerManager.h ../../Core/Types.h ../../Core/types/SystemTypes.h \
 /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc ../../Core/types/PlayerTypes.h \
 ../../Core/types/SystemTypes.h ../../Core/types/ObjectTypes.h \
 ../../Core/types/CreatureTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/ZoneTypes.h ../../Core/types/QuestTypes.h \
 ../../Core/types/ShopTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/GuildTypes.h ../../Core/types/WarTypes.h \
 ../../Core/types/ServerType.h ../../Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../Core/Types.h ../../Core/Exception.h ../../Core/StringStream.h \
 /usr/include/c++/5/list /usr/include/c++/5/bits/stl_list.h \
 /usr/include/c++/5/bits/list.tcc ../Thread.h ../pthreadAPI.h \
 ../../Core/DatagramSocket.h ../../Core/Exception.h \
 ../../Core/SocketAPI.h ../../Core/Datagram.h ../../Core/Properties.h \
 /usr/include/c++/5/map /usr/include/c++/5/bits/stl_tree.h \
 /usr/include/c++/5/bits/stl_map.h /usr/include/c++/5/bits/stl_multimap.h \
 ../../Core/Datagram.h ../../Core/DatagramPacket.h ../../Core/Packet.h \
 ../../Core/SocketInputStream.h ../../Core/Socket.h \
 ../../Core/SocketImpl.h ../../Core/SocketOutputStream.h ../LogClient.h \
 /usr/include/unistd.h /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 ../database/DB.h ../database/DatabaseManager.h ../database/Connection.h \
 /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
 /usr/include/mysql/mysql_com.h /usr/include/mysql/binary_log_types.h \
 /usr/include/mysql/my_command.h /usr/include/mysql/mysql_time.h \
 /usr/include/mysql/my_list.h /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../Mutex.h \
 ../database/Statement.h ../database/Result.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 ../../Core/Lpackets/LGKickCharacter.h ../../Core/PacketFactory.h
LoginPlayer.o: LoginPlayer.cpp /usr/include/stdc-predef.h LoginPlayer.h \
 ../../Core/Player.h ../../Core/Types.h ../../Core/types/SystemTypes.h \
 /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc ../../Core/types/PlayerTypes.h \
 ../../Core/types/SystemTypes.h ../../Core/types/ObjectTypes.h \
 ../../Core/types/CreatureTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/ZoneTypes.h ../../Core/types/QuestTypes.h \
 ../../Core/types/ShopTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/GuildTypes.h ../../Core/types/WarTypes.h \
 ../../Core/types/ServerType.h ../../Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../Core/Exception.h ../../Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 ../Mutex.h ../../Core/Types.h ../../Core/Exception.h \
 ../../Core/PlayerStatus.h /usr/include/c++/5/deque \
 /usr/include/c++/5/bits/stl_construct.h \
 /usr/include/c++/5/bits/stl_uninitialized.h \
 /usr/include/c++/5/bits/stl_deque.h /usr/include/c++/5/bits/deque.tcc \
 ../Timeval.h /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/unistd.h /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 ../PaySystem.h ../Timeval.h ../../Core/VSDateTime.h \
 ../gameserver/billing/BillingPlayerInfo.h \
 ../chinabilling/CBillingPlayerInfo.h ../chinabilling/CBillingInfo.h \
 ../../Core/Gpackets/GCReconnectLogin.h ../../Core/Packet.h \
 ../../Core/SocketInputStream.h ../../Core/Socket.h \
 ../../Core/SocketImpl.h ../../Core/SocketAPI.h \
 ../../Core/SocketOutputStream.h ../../Core/PacketFactory.h \
 ../../Core/Packet.h ../../Core/Assert.h \
 ../../Core/PacketFactoryManager.h ../../Core/PacketFactory.h \
 ../../Core/PacketValidator.h ../../Core/PacketIDSet.h \
 ../../Core/PlayerStatus.h /usr/include/c++/5/vector \
 /usr/include/c++/5/bits/stl_vector.h \
 /usr/include/c++/5/bits/stl_bvector.h /usr/include/c++/5/bits/vector.tcc \
 ../database/DB.h ../database/DatabaseManager.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h ../database/Connection.h \
 /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
 /usr/include/mysql/mysql_com.h /usr/include/mysql/binary_log_types.h \
 /usr/include/mysql/my_command.h /usr/include/mysql/mysql_time.h \
 /usr/include/mysql/my_list.h /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../database/Statement.h \
 ../database/Result.h ../LogClient.h ../Profile.h ../Mutex.h \
 ../PacketProfile.h ../GameServerInfoManager.h ../GameServerInfo.h \
 ../../Core/StringStream.h GameServerManager.h ../Thread.h \
 ../pthreadAPI.h ../../Core/DatagramSocket.h ../../Core/Datagram.h \
 ../gameserver/billing/BillingPlayerManager.h ../../Core/Socket.h \
 ../gameserver/billing/BillingInfo.h ../../Core/Lpackets/LCLoginOK.h \
 ../../Core/Lpackets/LCLoginError.h ../../Core/Lpackets/LGKickCharacter.h \
 ../../Core/DatagramPacket.h ../../Core/Lpackets/LCPCList.h \
 ../../Core/PCInfo.h ../../Core/PCSlayerInfo.h ../../Core/PCInfo.h \
 /usr/include/c++/5/bitset ../../Core/PCVampireInfo.h \
 ../../Core/PCOustersInfo.h
LoginPlayerManager.o: LoginPlayerManager.cpp /usr/include/stdc-predef.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h LoginPlayerManager.h \
 ../../Core/Types.h ../../Core/types/SystemTypes.h \
 /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/include/xlocale.h /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc ../../Core/types/PlayerTypes.h \
 ../../Core/types/SystemTypes.h ../../Core/types/ObjectTypes.h \
 ../../Core/types/CreatureTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/ZoneTypes.h ../../Core/types/QuestTypes.h \
 ../../Core/types/ShopTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/GuildTypes.h ../../Core/types/WarTypes.h \
 ../../Core/types/ServerType.h ../../Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../Core/Types.h ../../Core/Exception.h ../../Core/StringStream.h \
 /usr/include/c++/5/list /usr/include/c++/5/bits/stl_list.h \
 /usr/include/c++/5/bits/list.tcc ../PlayerManager.h ../Timeval.h \
 /usr/include/x86_64-linux-gnu/sys/time.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 ../../Core/SocketAPI.h ../../Core/Exception.h ../Mutex.h \
 ../../Core/ServerSocket.h ../../Core/SocketImpl.h ../../Core/SocketAPI.h \
 ../../Core/Socket.h ../../Core/Assert.h ../../Core/Socket.h \
 LoginPlayer.h ../../Core/Player.h ../Mutex.h ../../Core/PlayerStatus.h \
 /usr/include/c++/5/deque /usr/include/c++/5/bits/stl_construct.h \
 /usr/include/c++/5/bits/stl_uninitialized.h \
 /usr/include/c++/5/bits/stl_deque.h /usr/include/c++/5/bits/deque.tcc \
 ../Timeval.h ../PaySystem.h ../../Core/VSDateTime.h \
 ../gameserver/billing/BillingPlayerInfo.h \
 ../chinabilling/CBillingPlayerInfo.h ../chinabilling/CBillingInfo.h \
 ../../Core/Gpackets/GCReconnectLogin.h ../../Core/Packet.h \
 ../../Core/SocketInputStream.h ../../Core/SocketOutputStream.h \
 ../../Core/PacketFactory.h ../../Core/Packet.h ../LogClient.h \
 /usr/include/c++/5/algorithm /usr/include/c++/5/utility \
 /usr/include/c++/5/bits/stl_relops.h /usr/include/c++/5/bits/stl_algo.h \
 /usr/include/c++/5/cstdlib /usr/include/c++/5/bits/algorithmfwd.h \
 /usr/include/c++/5/bits/stl_heap.h /usr/include/c++/5/bits/stl_tempbuf.h \
 ../../Core/Properties.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h ReconnectLoginInfoManager.h \
 ReconnectLoginInfo.h ../../Core/StringStream.h \
 ../gameserver/billing/BillingInfo.h ../database/DB.h \
 ../database/DatabaseManager.h ../database/Connection.h \
 /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
 /usr/include/mysql/mysql_com.h /usr/include/mysql/binary_log_types.h \
 /usr/include/mysql/my_command.h /usr/include/mysql/mysql_time.h \
 /usr/include/mysql/my_list.h /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../database/Statement.h \
 ../database/Result.h
LoginServer.o: LoginServer.cpp /usr/include/stdc-predef.h LoginServer.h \
 ../../Core/Types.h ../../Core/types/SystemTypes.h \
 /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc ../../Core/types/PlayerTypes.h \
 ../../Core/types/SystemTypes.h ../../Core/types/ObjectTypes.h \
 ../../Core/types/CreatureTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/ZoneTypes.h ../../Core/types/QuestTypes.h \
 ../../Core/types/ShopTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/GuildTypes.h ../../Core/types/WarTypes.h \
 ../../Core/types/ServerType.h ../../Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../Core/Types.h ../../Core/Exception.h ../../Core/StringStream.h \
 /usr/include/c++/5/list /usr/include/c++/5/bits/stl_list.h \
 /usr/include/c++/5/bits/list.tcc ../../Core/Assert.h \
 ../../Core/Exception.h ../GameServerInfoManager.h ../GameServerInfo.h \
 ../../Core/StringStream.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h GameServerGroupInfoManager.h \
 GameServerGroupInfo.h GameServerManager.h ../Thread.h ../pthreadAPI.h \
 ../../Core/DatagramSocket.h ../../Core/SocketAPI.h ../../Core/Datagram.h \
 ClientManager.h ZoneInfoManager.h ZoneInfo.h ZoneGroupInfoManager.h \
 ZoneGroupInfo.h ../database/DatabaseManager.h ../database/Connection.h \
 /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
 /usr/include/mysql/mysql_com.h /usr/include/mysql/binary_log_types.h \
 /usr/include/mysql/my_command.h /usr/include/mysql/mysql_time.h \
 /usr/include/mysql/my_list.h /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../Mutex.h \
 ../../Core/PacketFactoryManager.h ../../Core/Packet.h \
 ../../Core/SocketInputStream.h ../../Core/Socket.h \
 ../../Core/SocketImpl.h ../../Core/SocketOutputStream.h \
 ../../Core/PacketFactory.h ../../Core/PacketValidator.h \
 ../../Core/PacketIDSet.h ../../Core/PlayerStatus.h \
 /usr/include/c++/5/vector /usr/include/c++/5/bits/stl_construct.h \
 /usr/include/c++/5/bits/stl_uninitialized.h \
 /usr/include/c++/5/bits/stl_vector.h \
 /usr/include/c++/5/bits/stl_bvector.h /usr/include/c++/5/bits/vector.tcc \
 ItemDestroyer.h ../database/DB.h ../database/DatabaseManager.h \
 ../database/Statement.h ../database/Result.h \
 /usr/include/x86_64-linux-gnu/sys/time.h UserInfoManager.h UserInfo.h \
 ../GameWorldInfoManager.h ../GameWorldInfo.h \
 ../chinabilling/CBillingPlayerManager.h ../../Core/Socket.h \
 ../chinabilling/CBillingInfo.h LoginPlayer.h ../../Core/Player.h \
 ../../Core/PlayerStatus.h /usr/include/c++/5/deque \
 /usr/include/c++/5/bits/stl_deque.h /usr/include/c++/5/bits/deque.tcc \
 ../Timeval.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 ../PaySystem.h ../Timeval.h ../../Core/VSDateTime.h \
 ../gameserver/billing/BillingPlayerInfo.h \
 ../chinabilling/CBillingPlayerInfo.h \
 ../../Core/Gpackets/GCReconnectLogin.h ../../Core/Packet.h \
 ../../Core/PacketFactory.h ../LogClient.h
ZoneGroupInfoManager.o: ZoneGroupInfoManager.cpp \
 /usr/include/stdc-predef.h ZoneGroupInfoManager.h ../../Core/Types.h \
 ../../Core/types/SystemTypes.h /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc ../../Core/types/PlayerTypes.h \
 ../../Core/types/SystemTypes.h ../../Core/types/ObjectTypes.h \
 ../../Core/types/CreatureTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/ZoneTypes.h ../../Core/types/QuestTypes.h \
 ../../Core/types/ShopTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/GuildTypes.h ../../Core/types/WarTypes.h \
 ../../Core/types/ServerType.h ../../Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../Core/Types.h ../../Core/Exception.h ../../Core/StringStream.h \
 /usr/include/c++/5/list /usr/include/c++/5/bits/stl_list.h \
 /usr/include/c++/5/bits/list.tcc ZoneGroupInfo.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h ../database/DatabaseManager.h \
 ../database/Connection.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../Mutex.h \
 ../database/Connection.h ../database/Statement.h ../database/Result.h \
 /usr/include/x86_64-linux-gnu/sys/time.h
ZoneInfoManager.o: ZoneInfoManager.cpp /usr/include/stdc-predef.h \
 ZoneInfoManager.h ../../Core/Types.h ../../Core/types/SystemTypes.h \
 /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc ../../Core/types/PlayerTypes.h \
 ../../Core/types/SystemTypes.h ../../Core/types/ObjectTypes.h \
 ../../Core/types/CreatureTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/ZoneTypes.h ../../Core/types/QuestTypes.h \
 ../../Core/types/ShopTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/GuildTypes.h ../../Core/types/WarTypes.h \
 ../../Core/types/ServerType.h ../../Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../Core/Types.h ../../Core/Exception.h ../../Core/StringStream.h \
 /usr/include/c++/5/list /usr/include/c++/5/bits/stl_list.h \
 /usr/include/c++/5/bits/list.tcc ZoneInfo.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h ../database/DatabaseManager.h \
 ../database/Connection.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../Mutex.h \
 ../database/Connection.h ../database/Statement.h ../database/Result.h \
 /usr/include/x86_64-linux-gnu/sys/time.h
main.o: main.cpp /usr/include/stdc-predef.h ../../Core/Types.h \
 ../../Core/types/SystemTypes.h /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc ../../Core/types/PlayerTypes.h \
 ../../Core/types/SystemTypes.h ../../Core/types/ObjectTypes.h \
 ../../Core/types/CreatureTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/ZoneTypes.h ../../Core/types/QuestTypes.h \
 ../../Core/types/ShopTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/GuildTypes.h ../../Core/types/WarTypes.h \
 ../../Core/types/ServerType.h ../../Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../Core/Types.h ../../Core/Exception.h ../../Core/StringStream.h \
 /usr/include/c++/5/list /usr/include/c++/5/bits/stl_list.h \
 /usr/include/c++/5/bits/list.tcc LoginServer.h ../LogClient.h \
 ../../Core/Properties.h ../../Core/Exception.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h ../../Core/StringStream.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/sys/resource.h \
 /usr/include/x86_64-linux-gnu/bits/resource.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h
ItemDestroyer.o: ItemDestroyer.cpp /usr/include/stdc-predef.h \
 ItemDestroyer.h ../../Core/Types.h ../../Core/types/SystemTypes.h \
 /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc ../../Core/types/PlayerTypes.h \
 ../../Core/types/SystemTypes.h ../../Core/types/ObjectTypes.h \
 ../../Core/types/CreatureTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/ZoneTypes.h ../../Core/types/QuestTypes.h \
 ../../Core/types/ShopTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/GuildTypes.h ../../Core/types/WarTypes.h \
 ../../Core/types/ServerType.h ../../Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../Core/Types.h ../../Core/Exception.h ../../Core/StringStream.h \
 /usr/include/c++/5/list /usr/include/c++/5/bits/stl_list.h \
 /usr/include/c++/5/bits/list.tcc ../database/DB.h \
 ../database/DatabaseManager.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h ../database/Connection.h \
 /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
 /usr/include/mysql/mysql_com.h /usr/include/mysql/binary_log_types.h \
 /usr/include/mysql/my_command.h /usr/include/mysql/mysql_time.h \
 /usr/include/mysql/my_list.h /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../Mutex.h \
 ../database/Statement.h ../database/Result.h \
 /usr/include/x86_64-linux-gnu/sys/time.h
ReconnectLoginInfoManager.o: ReconnectLoginInfoManager.cpp \
 /usr/include/stdc-predef.h ReconnectLoginInfoManager.h \
 ../../Core/Types.h ../../Core/types/SystemTypes.h \
 /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc ../../Core/types/PlayerTypes.h \
 ../../Core/types/SystemTypes.h ../../Core/types/ObjectTypes.h \
 ../../Core/types/CreatureTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/ZoneTypes.h ../../Core/types/QuestTypes.h \
 ../../Core/types/ShopTypes.h ../../Core/types/ItemTypes.h \
 ../../Core/types/GuildTypes.h ../../Core/types/WarTypes.h \
 ../../Core/types/ServerType.h ../../Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../Core/Types.h ../../Core/Exception.h ../../Core/StringStream.h \
 /usr/include/c++/5/list /usr/include/c++/5/bits/stl_list.h \
 /usr/include/c++/5/bits/list.tcc /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h ReconnectLoginInfo.h ../Timeval.h \
 /usr/include/x86_64-linux-gnu/sys/time.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 ../../Core/StringStream.h ../../Core/Assert.h ../../Core/Exception.h
