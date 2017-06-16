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
DBINCDIR  = /usr/include/mysql
BINDIR  = $(VSHOME)/bin
LIBDIR  = $(VSHOME)/lib
LOGDIR  = $(VSHOME)/log
SRCDIR  = $(VSHOME)/src
COREDIR = $(SRCDIR)/Core
SERVDIR = $(SRCDIR)/server


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o .gs.o .ls.o .us.o .ss.o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__DEBUG__
INCLUDES = -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBINCDIR) -I.
CCFLAGS  = -Wall -c -g 
#CCFLAGS  = -Wall -c

.cpp.o : 
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

.cpp.gs.o :
	$(CC) $(CCFLAGS) $(DEFS) -D__GAME_SERVER__ $(INCLUDES) -o $*.gs.o $<

.cpp.ls.o :
	$(CC) $(CCFLAGS) $(DEFS) -D__LOGIN_SERVER__ $(INCLUDES) -o $*.ls.o $<

.cpp.us.o :
	$(CC) $(CCFLAGS) $(DEFS) -D__UPDATE_SERVER__ $(INCLUDES) -o $*.us.o $<

.cpp.ss.o :
	$(CC) $(CCFLAGS) $(DEFS) -D__SHARED_SERVER__ $(INCLUDES) -o $*.ss.o $<

#----------------------------------------------------------------------
# Server Core Library
#----------------------------------------------------------------------
DB_OBJS = Connection.o Statement.o Result.o DatabaseManager.o
DB_SRC  = $(DB_OBJS:.o=.cpp)
DB_LIB  = $(LIBDIR)/libDatabase.a

#----------------------------------------------------------------------
# Packet Library for GameServer
#----------------------------------------------------------------------
GS_DB_OBJS = Connection.gs.o Statement.gs.o Result.gs.o DatabaseManager.gs.o
GS_DB_SRCS = $(GS_DB_OBJS:.gs.o=.cpp)
GS_DB_LIB  = $(LIBDIR)/libGameServerDatabase.a

#----------------------------------------------------------------------
# Packet Library for LoginServer
#----------------------------------------------------------------------
LS_DB_OBJS = Connection.ls.o Statement.ls.o Result.ls.o DatabaseManager.ls.o
LS_DB_SRCS = $(LS_DB_OBJS:.ls.o=.cpp)
LS_DB_LIB  = $(LIBDIR)/libLoginServerDatabase.a

#----------------------------------------------------------------------
# Packet Library for Updateserver 
#----------------------------------------------------------------------
US_DB_OBJS = Connection.us.o Statement.us.o Result.gs.o DatabaseManager.us.o
US_DB_SRCS = $(US_DB_OBJS:.us.o=.cpp)
US_DB_LIB  = $(LIBDIR)/libUpdateServerDatabase.a

#----------------------------------------------------------------------
# Database Library for Updateserver 
#----------------------------------------------------------------------
SS_DB_OBJS = Connection.ss.o Statement.ss.o Result.ss.o DatabaseManager.ss.o
SS_DB_SRCS = $(SS_DB_OBJS:.ss.o=.cpp)
SS_DB_LIB  = $(LIBDIR)/libSharedServerDatabase.a

#----------------------------------------------------------------------
# All Targets
#----------------------------------------------------------------------
#TARGETS = $(CORE_LIB) $(LS_DB_LIB) $(GS_DB_LIB)
SRCS = $(LS_DB_SRCS) $(GS_DB_SRCS) $(US_DB_SRCS) $(SS_DB_SRCS)
TARGETS = $(DB_LIB) $(LS_DB_LIB) $(GS_DB_LIB) $(US_DB_LIB) $(SS_DB_LIB)

#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
all : $(TARGETS)

$(DB_LIB) : $(DB_OBJS)
	ar rc $@ $^

$(LS_DB_LIB) : $(LS_DB_OBJS)
	ar rc $@ $^

$(GS_DB_LIB) : $(GS_DB_OBJS)
	ar rc $@ $^

$(US_DB_LIB) : $(US_DB_OBJS)
	ar rc $@ $^

$(SS_DB_LIB) : $(SS_DB_OBJS)
	ar rc $@ $^

clean :
	rm -rf *.o

cleanall :
	rm -rf *.o $(TARGETS)

depall : 
	gccmakedep $(SRCS) $(INCLUDES)

dep : 
	gccmakedep $(SRCS) $(INCLUDES)

# DO NOT DELETE
Connection.o: Connection.cpp /usr/include/stdc-predef.h Connection.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
 /usr/include/mysql/mysql_com.h /usr/include/mysql/binary_log_types.h \
 /usr/include/mysql/my_command.h /usr/include/mysql/mysql_time.h \
 /usr/include/mysql/my_list.h /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/server/Mutex.h \
 Statement.h
Statement.o: Statement.cpp /usr/include/stdc-predef.h Statement.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 Connection.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/server/Mutex.h \
 /usr/include/x86_64-linux-gnu/sys/time.h Result.h \
 ../../../src/Core/Assert.h ../../../src/Core/Exception.h \
 ../../../src/server/Profile.h ../../../src/server/Timeval.h \
 /usr/include/unistd.h /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 ../../../src/server/Mutex.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h /usr/include/c++/5/cstdarg
Result.o: Result.cpp /usr/include/stdc-predef.h Result.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 /usr/include/x86_64-linux-gnu/sys/time.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/Core/Assert.h \
 ../../../src/Core/Exception.h ../../../src/Core/StringStream.h
DatabaseManager.o: DatabaseManager.cpp /usr/include/stdc-predef.h \
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
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h DatabaseManager.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 /usr/include/c++/5/map /usr/include/c++/5/bits/stl_tree.h \
 /usr/include/c++/5/bits/stl_map.h /usr/include/c++/5/bits/stl_multimap.h \
 Connection.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/server/Mutex.h \
 ../../../src/Core/Properties.h ../../../src/Core/Exception.h \
 ../../../src/Core/Utility.h ../../../src/server/Thread.h \
 ../../../src/server/pthreadAPI.h ../../../src/server/Timeval.h \
 /usr/include/x86_64-linux-gnu/sys/time.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 Result.h Statement.h ../../../src/Core/Assert.h DB.h
Connection.o: Connection.cpp /usr/include/stdc-predef.h Connection.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
 /usr/include/mysql/mysql_com.h /usr/include/mysql/binary_log_types.h \
 /usr/include/mysql/my_command.h /usr/include/mysql/mysql_time.h \
 /usr/include/mysql/my_list.h /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/server/Mutex.h \
 Statement.h
Statement.o: Statement.cpp /usr/include/stdc-predef.h Statement.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 Connection.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/server/Mutex.h \
 /usr/include/x86_64-linux-gnu/sys/time.h Result.h \
 ../../../src/Core/Assert.h ../../../src/Core/Exception.h \
 ../../../src/server/Profile.h ../../../src/server/Timeval.h \
 /usr/include/unistd.h /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 ../../../src/server/Mutex.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h /usr/include/c++/5/cstdarg
Result.o: Result.cpp /usr/include/stdc-predef.h Result.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 /usr/include/x86_64-linux-gnu/sys/time.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/Core/Assert.h \
 ../../../src/Core/Exception.h ../../../src/Core/StringStream.h
DatabaseManager.o: DatabaseManager.cpp /usr/include/stdc-predef.h \
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
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h DatabaseManager.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 /usr/include/c++/5/map /usr/include/c++/5/bits/stl_tree.h \
 /usr/include/c++/5/bits/stl_map.h /usr/include/c++/5/bits/stl_multimap.h \
 Connection.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/server/Mutex.h \
 ../../../src/Core/Properties.h ../../../src/Core/Exception.h \
 ../../../src/Core/Utility.h ../../../src/server/Thread.h \
 ../../../src/server/pthreadAPI.h ../../../src/server/Timeval.h \
 /usr/include/x86_64-linux-gnu/sys/time.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 Result.h Statement.h ../../../src/Core/Assert.h DB.h
Connection.o: Connection.cpp /usr/include/stdc-predef.h Connection.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
 /usr/include/mysql/mysql_com.h /usr/include/mysql/binary_log_types.h \
 /usr/include/mysql/my_command.h /usr/include/mysql/mysql_time.h \
 /usr/include/mysql/my_list.h /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/server/Mutex.h \
 Statement.h
Statement.o: Statement.cpp /usr/include/stdc-predef.h Statement.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 Connection.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/server/Mutex.h \
 /usr/include/x86_64-linux-gnu/sys/time.h Result.h \
 ../../../src/Core/Assert.h ../../../src/Core/Exception.h \
 ../../../src/server/Profile.h ../../../src/server/Timeval.h \
 /usr/include/unistd.h /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 ../../../src/server/Mutex.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h /usr/include/c++/5/cstdarg
DatabaseManager.o: DatabaseManager.cpp /usr/include/stdc-predef.h \
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
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h DatabaseManager.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 /usr/include/c++/5/map /usr/include/c++/5/bits/stl_tree.h \
 /usr/include/c++/5/bits/stl_map.h /usr/include/c++/5/bits/stl_multimap.h \
 Connection.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/server/Mutex.h \
 ../../../src/Core/Properties.h ../../../src/Core/Exception.h \
 ../../../src/Core/Utility.h ../../../src/server/Thread.h \
 ../../../src/server/pthreadAPI.h ../../../src/server/Timeval.h \
 /usr/include/x86_64-linux-gnu/sys/time.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 Result.h Statement.h ../../../src/Core/Assert.h DB.h
Connection.o: Connection.cpp /usr/include/stdc-predef.h Connection.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
 /usr/include/mysql/mysql_com.h /usr/include/mysql/binary_log_types.h \
 /usr/include/mysql/my_command.h /usr/include/mysql/mysql_time.h \
 /usr/include/mysql/my_list.h /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/server/Mutex.h \
 Statement.h
Statement.o: Statement.cpp /usr/include/stdc-predef.h Statement.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 Connection.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/server/Mutex.h \
 /usr/include/x86_64-linux-gnu/sys/time.h Result.h \
 ../../../src/Core/Assert.h ../../../src/Core/Exception.h \
 ../../../src/server/Profile.h ../../../src/server/Timeval.h \
 /usr/include/unistd.h /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 ../../../src/server/Mutex.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h /usr/include/c++/5/cstdarg
Result.o: Result.cpp /usr/include/stdc-predef.h Result.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 /usr/include/x86_64-linux-gnu/sys/time.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/Core/Assert.h \
 ../../../src/Core/Exception.h ../../../src/Core/StringStream.h
DatabaseManager.o: DatabaseManager.cpp /usr/include/stdc-predef.h \
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
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h DatabaseManager.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
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
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Types.h ../../../src/Core/Exception.h \
 ../../../src/Core/StringStream.h /usr/include/c++/5/list \
 /usr/include/c++/5/bits/stl_list.h /usr/include/c++/5/bits/list.tcc \
 /usr/include/c++/5/map /usr/include/c++/5/bits/stl_tree.h \
 /usr/include/c++/5/bits/stl_map.h /usr/include/c++/5/bits/stl_multimap.h \
 Connection.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
 /usr/include/mysql/binary_log_types.h /usr/include/mysql/my_command.h \
 /usr/include/mysql/mysql_time.h /usr/include/mysql/my_list.h \
 /usr/include/mysql/mysql/client_plugin.h \
 /usr/include/mysql/mysql/plugin_auth_common.h \
 /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
 /usr/include/mysql/mysql/psi/psi_memory.h \
 /usr/include/mysql/mysql/psi/psi_base.h ../../../src/server/Mutex.h \
 ../../../src/Core/Properties.h ../../../src/Core/Exception.h \
 ../../../src/Core/Utility.h ../../../src/server/Thread.h \
 ../../../src/server/pthreadAPI.h ../../../src/server/Timeval.h \
 /usr/include/x86_64-linux-gnu/sys/time.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h /usr/include/getopt.h \
 Result.h Statement.h ../../../src/Core/Assert.h DB.h
