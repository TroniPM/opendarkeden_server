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
VSHOME = ../..
STLDIR = /usr/include/STL
BINDIR = $(VSHOME)/bin
LIBDIR = $(VSHOME)/lib
LOGDIR = $(VSHOME)/log
#XMLDIR = /home/darkeden/xerces-c-src_2_5_0/src

#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o .gs.o .ls.o .us.o .ss.o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__DEBUG__
INCLUDES = -I$(STLDIR) -I.
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
# Core Library
#----------------------------------------------------------------------
CORE_OBJS = WarInfo.o RaceWarInfo.o GuildWarInfo.o LevelWarInfo.o BloodBibleBonusInfo.o \
			Assert.o Datagram.o SerialDatagram.o DatagramSocket.o FileAPI.o GameTime.o \
			ScriptParameter.o \
			Player.o PCSlayerInfo.o PCVampireInfo.o PCSlayerInfo2.o \
			PCVampireInfo2.o PCSlayerInfo3.o PCVampireInfo3.o \
			Properties.o Resource.o ResourceManager.o \
			ServerSocket.o Socket.o SocketAPI.o SocketImpl.o \
			SocketInputStream.o SocketOutputStream.o StringStream.o \
			Update.o UpdateManager.o InventoryInfo.o InventorySlotInfo.o \
			RideMotorcycleInfo.o RideMotorcycleSlotInfo.o \
			GearSlotInfo.o GearInfo.o ExtraInfo.o \
			ExtraSlotInfo.o PCItemInfo.o SubItemInfo.o \
			ModifyInfo.o ModifyItemInfo.o \
			EffectInfo.o SlayerSkillInfo.o VampireSkillInfo.o \
			SubSlayerSkillInfo.o SubVampireSkillInfo.o Utility.o VSDateTime.o ServerGroupInfo.o \
			NPCInfo.o Shape.o Geometry.o WorldInfo.o GuildInfo.o GuildMemberInfo.o \
			GuildInfo2.o GuildMemberInfo2.o \
			Encrypter.o	SocketEncryptInputStream.o SocketEncryptOutputStream.o \
			OustersSkillInfo.o PCOustersInfo.o PCOustersInfo2.o PCOustersInfo3.o SubOustersSkillInfo.o \
			ItemNameInfo.o SweeperBonusInfo.o PetInfo.o


CORE_SRCS = $(CORE_OBJS:.o=.cpp)
CORE_LIB = $(LIBDIR)/libCore.a

#----------------------------------------------------------------------
# Packet Library for GameServer
#----------------------------------------------------------------------
GS_PACKET_OBJS = PacketFactoryManager.gs.o PacketIDSet.gs.o PacketValidator.gs.o
GS_PACKET_SRCS = $(GS_PACKET_OBJS:.gs.o=.cpp)
GS_PACKET_LIB  = $(LIBDIR)/libGameServerPackets.a

#----------------------------------------------------------------------
# Packet Library for LoginServer
#----------------------------------------------------------------------
LS_PACKET_OBJS = PacketFactoryManager.ls.o PacketIDSet.ls.o PacketValidator.ls.o
LS_PACKET_SRCS = $(LS_PACKET_OBJS:.ls.o=.cpp)
LS_PACKET_LIB  = $(LIBDIR)/libLoginServerPackets.a

#----------------------------------------------------------------------
# Packet Library for Updateserver 
#----------------------------------------------------------------------
US_PACKET_OBJS = PacketFactoryManager.us.o PacketIDSet.us.o PacketValidator.us.o
US_PACKET_SRCS = $(US_PACKET_OBJS:.us.o=.cpp)
US_PACKET_LIB  = $(LIBDIR)/libUpdateServerPackets.a

#----------------------------------------------------------------------
# Packet Library for SharedServer
#----------------------------------------------------------------------
SS_PACKET_OBJS = PacketFactoryManager.ss.o PacketIDSet.ss.o PacketValidator.ss.o
SS_PACKET_SRCS = $(SS_PACKET_OBJS:.ss.o=.cpp)
SS_PACKET_LIB  = $(LIBDIR)/libSharedServerPackets.a

#----------------------------------------------------------------------
# All Targets
#----------------------------------------------------------------------
#TARGETS = $(CORE_LIB) $(LS_PACKET_LIB) $(GS_PACKET_LIB) $(LCC_PACKET_LIB) 
SRCS = $(CORE_SRCS) $(LS_PACKET_SRCS) $(GS_PACKET_SRCS) $(LCC_PACKET_SRCS) $(US_PACKET_SRCS) $(SS_PACKET_SRCS)
TARGETS = $(CORE_LIB) $(GS_PACKET_LIB) $(LS_PACKET_LIB) $(US_PACKET_LIB) $(SS_PACKET_LIB)

#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
all : $(TARGETS)
	$(MAKE) -C Lpackets
	$(MAKE) -C Gpackets
	$(MAKE) -C Cpackets
	$(MAKE) -C Upackets
	$(MAKE) -C Spackets
	$(MAKE) -C TOpackets

core : $(CORE_LIB)

allloginserver : $(TARGETS)
	$(MAKE) -C Lpackets allloginserver
	$(MAKE) -C Gpackets allloginserver
	$(MAKE) -C Cpackets allloginserver
	$(MAKE) -C Upackets allloginserver
	$(MAKE) -C Spackets allloginserver

allgameserver : $(TARGETS)
	$(MAKE) -C Lpackets allgameserver
	$(MAKE) -C Gpackets allgameserver
	$(MAKE) -C Cpackets allgameserver
	$(MAKE) -C Upackets allgameserver
	$(MAKE) -C Spackets allgameserver
	$(MAKE) -C TOpackets allgameserver

allsharedserver : $(TARGETS)
	$(MAKE) -C Lpackets allsharedserver
	$(MAKE) -C Gpackets allsharedserver
	$(MAKE) -C Cpackets allsharedserver
	$(MAKE) -C Spackets allsharedserver
#	$(MAKE) -C Upackets allsharedserver

alltheoneserver : $(CORE_LIB)
	$(MAKE) -C TOpackets alltheoneserver

$(CORE_LIB) : $(CORE_OBJS)
	ar rc $@ $^

$(LS_PACKET_LIB) : $(LS_PACKET_OBJS)
	ar rc $@ $^

$(GS_PACKET_LIB) : $(GS_PACKET_OBJS)
	ar rc $@ $^

$(LCC_PACKET_LIB) : $(LCC_PACKET_OBJS)
	ar rc $@ $^

$(US_PACKET_LIB) : $(US_PACKET_OBJS)
	ar rc $@ $^

$(SS_PACKET_LIB) : $(SS_PACKET_OBJS)
	ar rc $@ $^

clean :
	$(MAKE) -C Lpackets clean
	$(MAKE) -C Gpackets clean
	$(MAKE) -C Cpackets clean
	$(MAKE) -C Upackets clean
	$(MAKE) -C Spackets clean
	$(MAKE) -C TOpackets clean
	rm -rf *.o

cleanall :
	$(MAKE) -C Lpackets cleanall
	$(MAKE) -C Gpackets cleanall
	$(MAKE) -C Cpackets cleanall
	$(MAKE) -C Upackets cleanall
	$(MAKE) -C Spackets cleanall
	$(MAKE) -C TOpackets cleanall
	rm -rf *.o $(TARGETS)

cleangameserver :
	$(MAKE) -C Lpackets cleangameserver
	$(MAKE) -C Gpackets cleangameserver
	$(MAKE) -C Cpackets cleangameserver
	$(MAKE) -C Upackets cleangameserver
	$(MAKE) -C Spackets cleangameserver
	$(MAKE) -C TOpackets cleangameserver
	rm -rf *.o $(TARGETS)

cleanloginserver :
	$(MAKE) -C Lpackets cleanloginserver
	$(MAKE) -C Gpackets cleanloginserver
	$(MAKE) -C Cpackets cleanloginserver
	$(MAKE) -C Upackets cleanloginserver
	$(MAKE) -C Spackets cleanloginserver
	rm -rf *.o $(TARGETS)

cleansharedserver :
	$(MAKE) -C Lpackets cleansharedserver
	$(MAKE) -C Gpackets cleansharedserver
	$(MAKE) -C Cpackets cleansharedserver
	$(MAKE) -C Upackets cleansharedserver
	$(MAKE) -C Spackets cleansharedserver
	rm -rf *.o $(TARGETS)

depall :
	$(MAKE) -C Lpackets depall
	$(MAKE) -C Gpackets depall
	$(MAKE) -C Cpackets depall
	$(MAKE) -C Upackets depall
	$(MAKE) -C Spackets depall
	$(MAKE) -C TOpackets depall
	gccmakedep $(SRCS) $(INCLUDES)

dep :
	gccmakedep $(SRCS) $(INCLUDES)
# DO NOT DELETE
WarInfo.o: WarInfo.cpp WarInfo.h Packet.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PacketFactory.h ValueList.h
RaceWarInfo.o: RaceWarInfo.cpp RaceWarInfo.h Packet.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PacketFactory.h WarInfo.h ValueList.h
GuildWarInfo.o: GuildWarInfo.cpp GuildWarInfo.h Packet.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PacketFactory.h WarInfo.h ValueList.h
LevelWarInfo.o: LevelWarInfo.cpp LevelWarInfo.h Packet.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PacketFactory.h WarInfo.h ValueList.h
BloodBibleBonusInfo.o: BloodBibleBonusInfo.cpp BloodBibleBonusInfo.h \
  Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Packet.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
Assert.o: Assert.cpp Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Assert.h Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc
Datagram.o: Datagram.cpp Datagram.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketAPI.h Assert.h PacketFactoryManager.h Packet.h \
  SocketInputStream.h Socket.h SocketImpl.h SocketOutputStream.h \
  PacketFactory.h DatagramPacket.h
SerialDatagram.o: SerialDatagram.cpp SerialDatagram.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketAPI.h Assert.h PacketFactoryManager.h Packet.h \
  SocketInputStream.h Socket.h SocketImpl.h SocketOutputStream.h \
  PacketFactory.h SerialDatagramPacket.h
DatagramSocket.o: DatagramSocket.cpp DatagramSocket.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketAPI.h Datagram.h Assert.h FileAPI.h
FileAPI.o: FileAPI.cpp FileAPI.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Assert.h
GameTime.o: GameTime.cpp GameTime.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
ScriptParameter.o: ScriptParameter.cpp ScriptParameter.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Packet.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
Player.o: Player.cpp /usr/include/stdio.h \
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
  /usr/include/gentoo-multilib/amd64/bits/sys_errlist.h Player.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Socket.h SocketImpl.h SocketAPI.h SocketInputStream.h \
  SocketOutputStream.h Assert.h Packet.h
PCSlayerInfo.o: PCSlayerInfo.cpp PCSlayerInfo.h PCInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset
PCVampireInfo.o: PCVampireInfo.cpp PCVampireInfo.h PCInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
PCSlayerInfo2.o: PCSlayerInfo2.cpp PCSlayerInfo2.h PCInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
PCVampireInfo2.o: PCVampireInfo2.cpp PCVampireInfo2.h PCInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
PCSlayerInfo3.o: PCSlayerInfo3.cpp PCSlayerInfo3.h PCInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h Assert.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset
PCVampireInfo3.o: PCVampireInfo3.cpp PCVampireInfo3.h PCInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h Assert.h
Properties.o: Properties.cpp Properties.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tree.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_map.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_multimap.h
Resource.o: Resource.cpp Resource.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  UpdateDef.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
ResourceManager.o: ResourceManager.cpp ResourceManager.h Resource.h \
  Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  UpdateDef.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h Assert.h
ServerSocket.o: ServerSocket.cpp ServerSocket.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketImpl.h SocketAPI.h Socket.h
Socket.o: Socket.cpp Socket.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketImpl.h SocketAPI.h Assert.h
SocketAPI.o: SocketAPI.cpp SocketAPI.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  FileAPI.h
SocketImpl.o: SocketImpl.cpp SocketImpl.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketAPI.h FileAPI.h
SocketInputStream.o: SocketInputStream.cpp SocketInputStream.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Socket.h SocketImpl.h SocketAPI.h /usr/include/errno.h \
  /usr/include/gentoo-multilib/amd64/errno.h /usr/include/bits/errno.h \
  /usr/include/gentoo-multilib/amd64/bits/errno.h \
  /usr/include/linux/errno.h /usr/include/asm/errno.h \
  /usr/include/asm-x86_64/errno.h /usr/include/asm-generic/errno.h \
  /usr/include/asm-generic/errno-base.h Assert.h Packet.h \
  SocketOutputStream.h
SocketOutputStream.o: SocketOutputStream.cpp SocketOutputStream.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Socket.h SocketImpl.h SocketAPI.h Assert.h Packet.h SocketInputStream.h \
  VSDateTime.h
StringStream.o: StringStream.cpp StringStream.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc
Update.o: Update.cpp Update.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  UpdateDef.h Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Assert.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
UpdateManager.o: UpdateManager.cpp UpdateManager.h Update.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  UpdateDef.h Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Assert.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h Resource.h ResourceManager.h
InventoryInfo.o: InventoryInfo.cpp InventoryInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  InventorySlotInfo.h SocketInputStream.h Socket.h SocketImpl.h \
  SocketAPI.h SocketOutputStream.h PCItemInfo.h SubItemInfo.h Assert.h \
  Packet.h
InventorySlotInfo.o: InventorySlotInfo.cpp InventorySlotInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PCItemInfo.h SubItemInfo.h Assert.h
RideMotorcycleInfo.o: RideMotorcycleInfo.cpp RideMotorcycleInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  RideMotorcycleSlotInfo.h SocketInputStream.h Socket.h SocketImpl.h \
  SocketAPI.h SocketOutputStream.h PCItemInfo.h SubItemInfo.h Assert.h \
  Packet.h
RideMotorcycleSlotInfo.o: RideMotorcycleSlotInfo.cpp \
  RideMotorcycleSlotInfo.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PCItemInfo.h SubItemInfo.h Assert.h
GearSlotInfo.o: GearSlotInfo.cpp GearSlotInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PCItemInfo.h SubItemInfo.h Assert.h
GearInfo.o: GearInfo.cpp GearInfo.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  GearSlotInfo.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PCItemInfo.h SubItemInfo.h Assert.h Packet.h
ExtraInfo.o: ExtraInfo.cpp ExtraInfo.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ExtraSlotInfo.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PCItemInfo.h SubItemInfo.h Assert.h Packet.h
ExtraSlotInfo.o: ExtraSlotInfo.cpp ExtraSlotInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PCItemInfo.h SubItemInfo.h Assert.h
PCItemInfo.o: PCItemInfo.cpp PCItemInfo.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h SubItemInfo.h Assert.h
SubItemInfo.o: SubItemInfo.cpp SubItemInfo.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
ModifyInfo.o: ModifyInfo.cpp ModifyInfo.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Packet.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
ModifyItemInfo.o: ModifyItemInfo.cpp ModifyItemInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Packet.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h ModifyInfo.h
EffectInfo.o: EffectInfo.cpp EffectInfo.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Packet.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
SlayerSkillInfo.o: SlayerSkillInfo.cpp SlayerSkillInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  PCSkillInfo.h Packet.h SocketInputStream.h Socket.h SocketImpl.h \
  SocketAPI.h SocketOutputStream.h SubSlayerSkillInfo.h Assert.h
VampireSkillInfo.o: VampireSkillInfo.cpp VampireSkillInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  PCSkillInfo.h Packet.h SocketInputStream.h Socket.h SocketImpl.h \
  SocketAPI.h SocketOutputStream.h SubVampireSkillInfo.h Assert.h
SubSlayerSkillInfo.o: SubSlayerSkillInfo.cpp SubSlayerSkillInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
SubVampireSkillInfo.o: SubVampireSkillInfo.cpp SubVampireSkillInfo.h \
  Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
Utility.o: Utility.cpp Utility.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Assert.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  VSDateTime.h
VSDateTime.o: VSDateTime.cpp VSDateTime.h /usr/include/sys/types.h \
  /usr/include/gentoo-multilib/amd64/sys/types.h /usr/include/features.h \
  /usr/include/gentoo-multilib/amd64/features.h /usr/include/sys/cdefs.h \
  /usr/include/gentoo-multilib/amd64/sys/cdefs.h \
  /usr/include/bits/wordsize.h \
  /usr/include/gentoo-multilib/amd64/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gentoo-multilib/amd64/gnu/stubs.h \
  /usr/include/gnu/stubs-64.h \
  /usr/include/gentoo-multilib/amd64/gnu/stubs-64.h \
  /usr/include/bits/types.h \
  /usr/include/gentoo-multilib/amd64/bits/types.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/stddef.h \
  /usr/include/bits/typesizes.h \
  /usr/include/gentoo-multilib/amd64/bits/typesizes.h /usr/include/time.h \
  /usr/include/gentoo-multilib/amd64/time.h /usr/include/endian.h \
  /usr/include/gentoo-multilib/amd64/endian.h /usr/include/bits/endian.h \
  /usr/include/gentoo-multilib/amd64/bits/endian.h \
  /usr/include/sys/select.h \
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
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/string \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/c++config.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/os_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/x86_64-pc-linux-gnu/bits/cpu_defines.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stringfwd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/char_traits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstring \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/cstddef \
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
  /usr/include/sys/time.h /usr/include/gentoo-multilib/amd64/sys/time.h
ServerGroupInfo.o: ServerGroupInfo.cpp ServerGroupInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Packet.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
NPCInfo.o: NPCInfo.cpp NPCInfo.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
Shape.o: Shape.cpp Shape.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc
Geometry.o: Geometry.cpp Geometry.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc
WorldInfo.o: WorldInfo.cpp WorldInfo.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Packet.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
GuildInfo.o: GuildInfo.cpp GuildInfo.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Packet.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
GuildMemberInfo.o: GuildMemberInfo.cpp GuildMemberInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Packet.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
GuildInfo2.o: GuildInfo2.cpp GuildInfo2.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Packet.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h GuildMemberInfo2.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist
GuildMemberInfo2.o: GuildMemberInfo2.cpp GuildMemberInfo2.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Packet.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
Encrypter.o: Encrypter.cpp Encrypter.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  EncryptUtility.h
SocketEncryptInputStream.o: SocketEncryptInputStream.cpp \
  SocketEncryptInputStream.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h Encrypter.h \
  EncryptUtility.h Assert.h
SocketEncryptOutputStream.o: SocketEncryptOutputStream.cpp \
  SocketEncryptOutputStream.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketOutputStream.h Socket.h SocketImpl.h SocketAPI.h Encrypter.h \
  EncryptUtility.h Assert.h
OustersSkillInfo.o: OustersSkillInfo.cpp OustersSkillInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  PCSkillInfo.h Packet.h SocketInputStream.h Socket.h SocketImpl.h \
  SocketAPI.h SocketOutputStream.h SubOustersSkillInfo.h Assert.h
PCOustersInfo.o: PCOustersInfo.cpp PCOustersInfo.h PCInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
PCOustersInfo2.o: PCOustersInfo2.cpp PCOustersInfo2.h PCInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
PCOustersInfo3.o: PCOustersInfo3.cpp PCOustersInfo3.h PCInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h Assert.h
SubOustersSkillInfo.o: SubOustersSkillInfo.cpp SubOustersSkillInfo.h \
  Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
ItemNameInfo.o: ItemNameInfo.cpp ItemNameInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Packet.h Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PacketFactory.h
SweeperBonusInfo.o: SweeperBonusInfo.cpp SweeperBonusInfo.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Packet.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h
PetInfo.o: PetInfo.cpp PetInfo.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  types/PetTypes.h Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  Packet.h SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h VSDateTime.h
PacketFactoryManager.o: PacketFactoryManager.cpp Assert.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  PacketFactoryManager.h Packet.h SocketInputStream.h Socket.h \
  SocketImpl.h SocketAPI.h SocketOutputStream.h PacketFactory.h \
  Cpackets/CGAttack.h Types.h Exception.h Packet.h PacketFactory.h \
  Cpackets/CGAddGearToMouse.h Cpackets/CGAddInventoryToMouse.h \
  Cpackets/CGAddMouseToGear.h Cpackets/CGAddMouseToInventory.h \
  Cpackets/CGAddMouseToQuickSlot.h Cpackets/CGAddMouseToZone.h \
  Cpackets/CGAddQuickSlotToMouse.h Cpackets/CGAddZoneToMouse.h \
  Cpackets/CGAddZoneToInventory.h Cpackets/CGBloodDrain.h \
  Cpackets/CGUnburrow.h Cpackets/CGUntransform.h \
  Cpackets/CGCastingSkill.h Cpackets/CGConnect.h \
  Cpackets/CGDissectionCorpse.h Cpackets/CGDropMoney.h \
  Cpackets/CGGetOffMotorCycle.h Cpackets/CGGlobalChat.h \
  Cpackets/CGLearnSkill.h Cpackets/CGLogout.h Cpackets/CGMakeItem.h \
  Cpackets/CGMove.h Cpackets/CGNPCAskAnswer.h Cpackets/CGNPCTalk.h \
  Cpackets/CGPickupMoney.h Cpackets/CGReady.h \
  Cpackets/CGReloadFromInventory.h Cpackets/CGReloadFromQuickSlot.h \
  Cpackets/CGRideMotorCycle.h Cpackets/CGSay.h \
  Cpackets/CGShopRequestBuy.h Cpackets/CGShopRequestList.h \
  Cpackets/CGShopRequestSell.h Cpackets/CGSkillToInventory.h \
  Cpackets/CGThrowBomb.h Gpackets/GCThrowBombOK1.h Types.h Exception.h \
  ModifyInfo.h Types.h Exception.h Packet.h PacketFactory.h \
  Gpackets/GCThrowBombOK2.h Gpackets/GCThrowBombOK3.h Packet.h \
  Cpackets/CGThrowItem.h Cpackets/CGUseBonusPoint.h \
  Cpackets/CGUsePotionFromInventory.h Cpackets/CGUsePotionFromQuickSlot.h \
  Cpackets/CGRequestRepair.h Cpackets/CGVisible.h Cpackets/CGVerifyTime.h \
  Cpackets/CGRequestNewbieItem.h Cpackets/CGWithdrawTax.h \
  Cpackets/CGTypeStringList.h Cpackets/CGUseItemFromGear.h \
  Cpackets/CLCreatePC.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  Cpackets/CLDeletePC.h Cpackets/CLGetPCList.h Cpackets/CLLogin.h \
  Cpackets/CLLogout.h Cpackets/CLQueryPlayerID.h \
  Cpackets/CLQueryCharacterName.h Cpackets/CLRegisterPlayer.h \
  Cpackets/CLSelectPC.h Player.h Cpackets/CLVersionCheck.h \
  Cpackets/CLGetServerList.h Cpackets/CLChangeServer.h \
  Cpackets/CLReconnectLogin.h Cpackets/CLGetWorldList.h \
  Cpackets/CLSelectWorld.h Cpackets/CLSelectServer.h Gpackets/GCAddBat.h \
  Gpackets/GCAddBurrowingCreature.h Gpackets/GCAddEffect.h \
  Gpackets/GCAddEffectToTile.h Gpackets/GCAddGearToInventory.h \
  Gpackets/GCAddGearToZone.h Gpackets/GCAddInstalledMineToZone.h \
  SubItemInfo.h SocketInputStream.h SocketOutputStream.h \
  Gpackets/GCAddItemToZone.h Gpackets/GCAddMonster.h EffectInfo.h \
  Gpackets/GCAddMonsterCorpse.h Gpackets/GCAddMonsterFromBurrowing.h \
  Gpackets/GCAddMonsterFromTransformation.h Gpackets/GCAddNewItemToZone.h \
  Gpackets/GCAddNPC.h Gpackets/GCAddSlayer.h PCSlayerInfo3.h PCInfo.h \
  Assert.h PetInfo.h types/PetTypes.h types/SystemTypes.h VSDateTime.h \
  Gpackets/GCAddSlayerCorpse.h Gpackets/GCAddVampire.h PCVampireInfo3.h \
  Gpackets/GCAddVampireCorpse.h Gpackets/GCAddVampireFromBurrowing.h \
  Gpackets/GCAddVampireFromTransformation.h Gpackets/GCAddWolf.h \
  Gpackets/GCAddInjuriousCreature.h Gpackets/GCAttackArmsOK1.h \
  Gpackets/GCAttackArmsOK2.h Gpackets/GCAttackArmsOK3.h \
  Gpackets/GCAttackArmsOK4.h Gpackets/GCAttackArmsOK5.h \
  Gpackets/GCAttackMeleeOK1.h Gpackets/GCAttackMeleeOK2.h \
  Gpackets/GCAttackMeleeOK3.h Gpackets/GCAttack.h \
  Gpackets/GCBloodDrainOK1.h Gpackets/GCBloodDrainOK2.h \
  Gpackets/GCBloodDrainOK3.h Gpackets/GCCannotAdd.h \
  Gpackets/GCCannotUse.h Gpackets/GCCastingSkill.h \
  Gpackets/GCCreateItem.h Gpackets/GCCreatureDied.h \
  Gpackets/GCChangeShape.h Gpackets/GCChangeDarkLight.h \
  Gpackets/GCChangeWeather.h Gpackets/GCCrossCounterOK1.h \
  Gpackets/GCCrossCounterOK2.h Gpackets/GCCrossCounterOK3.h \
  Gpackets/GCDeleteInventoryItem.h Gpackets/GCDeleteObject.h \
  Gpackets/GCRemoveCorpseHead.h Gpackets/GCRemoveInjuriousCreature.h \
  Gpackets/GCDeleteandPickUpOK.h Gpackets/GCDeleteEffectFromTile.h \
  Gpackets/GCDisconnect.h Gpackets/GCDropItemToZone.h \
  Gpackets/GCFastMove.h Gpackets/GCFakeMove.h Gpackets/GCGetDamage.h \
  Gpackets/GCGetOffMotorCycle.h Gpackets/GCGetOffMotorCycleFailed.h \
  Gpackets/GCGetOffMotorCycleOK.h Gpackets/GCGlobalChat.h \
  Gpackets/GCHPRecoveryStartToSelf.h Gpackets/GCHPRecoveryStartToOthers.h \
  Gpackets/GCHPRecoveryEndToSelf.h Gpackets/GCHPRecoveryEndToOthers.h \
  Gpackets/GCKnockBack.h Gpackets/GCKnocksTargetBackOK1.h \
  ModifyItemInfo.h ModifyInfo.h Gpackets/GCKnocksTargetBackOK2.h \
  Gpackets/GCKnocksTargetBackOK4.h Gpackets/GCKnocksTargetBackOK5.h \
  Gpackets/GCLearnSkillFailed.h Gpackets/GCLearnSkillOK.h \
  Gpackets/GCLearnSkillReady.h Gpackets/GCLightning.h \
  Gpackets/GCMakeItemOK.h Gpackets/GCChangeInventoryItemNum.h \
  Gpackets/GCAddItemToInventory.h Gpackets/GCMakeItemFail.h \
  Gpackets/GCMineExplosionOK1.h Gpackets/GCMineExplosionOK2.h \
  Gpackets/GCModifyInformation.h Gpackets/GCMorph1.h GameTime.h \
  PCSlayerInfo2.h PCVampireInfo2.h InventoryInfo.h InventorySlotInfo.h \
  PCItemInfo.h SubItemInfo.h GearInfo.h GearSlotInfo.h ExtraInfo.h \
  ExtraSlotInfo.h Assert.h Gpackets/GCMorphSlayer2.h \
  Gpackets/GCMorphVampire2.h Gpackets/GCMove.h Gpackets/GCMoveOK.h \
  Gpackets/GCMoveError.h Gpackets/GCMPRecoveryStart.h \
  Gpackets/GCMPRecoveryEnd.h Gpackets/GCNPCAsk.h Gpackets/GCNPCSay.h \
  Gpackets/GCRealWearingInfo.h Gpackets/GCReconnect.h \
  Gpackets/GCReconnectLogin.h Gpackets/GCRemoveEffect.h \
  Gpackets/GCRemoveFromGear.h Gpackets/GCRideMotorCycle.h \
  Gpackets/GCRideMotorCycleFailed.h Gpackets/GCRideMotorCycleOK.h \
  Gpackets/GCReloadOK.h Gpackets/GCSay.h Gpackets/GCSearchMotorcycleOK.h \
  Gpackets/GCSearchMotorcycleFail.h Gpackets/GCSetPosition.h \
  Gpackets/GCShopBuyOK.h Gpackets/GCShopBuyFail.h Gpackets/GCShopList.h \
  Gpackets/GCShopListMysterious.h Gpackets/GCShopSold.h \
  Gpackets/GCShopVersion.h Gpackets/GCShopBought.h \
  Gpackets/GCShopSellOK.h Gpackets/GCShopSellFail.h \
  Gpackets/GCShopMarketCondition.h Gpackets/GCSkillFailed1.h \
  Gpackets/GCSkillFailed2.h Gpackets/GCSkillToInventoryOK1.h \
  Gpackets/GCSkillToInventoryOK2.h Gpackets/GCSkillToObjectOK1.h \
  Gpackets/GCSkillToObjectOK2.h Gpackets/GCSkillToObjectOK3.h \
  Gpackets/GCSkillToObjectOK4.h Gpackets/GCSkillToObjectOK5.h \
  Gpackets/GCSkillToObjectOK6.h Gpackets/GCSkillToSelfOK1.h \
  Gpackets/GCSkillToSelfOK2.h Gpackets/GCSkillToSelfOK3.h \
  Gpackets/GCSkillToTileOK1.h Gpackets/GCSkillToTileOK2.h \
  Gpackets/GCSkillToTileOK3.h Gpackets/GCSkillToTileOK4.h \
  Gpackets/GCSkillToTileOK5.h Gpackets/GCSkillToTileOK6.h \
  Gpackets/GCSystemMessage.h Gpackets/GCUnburrowOK.h \
  Gpackets/GCUnburrowFail.h Gpackets/GCUntransformOK.h \
  Gpackets/GCUntransformFail.h Gpackets/GCTeachSkillInfo.h \
  Gpackets/GCUpdateInfo.h RideMotorcycleInfo.h RideMotorcycleSlotInfo.h \
  NPCInfo.h Gpackets/GCUseBonusPointFail.h Gpackets/GCUseBonusPointOK.h \
  Gpackets/GCUseOK.h Gpackets/GCTakeOff.h Gpackets/GCThrowItemOK1.h \
  Gpackets/GCThrowItemOK2.h Gpackets/GCThrowItemOK3.h \
  Gpackets/GCVisibleOK.h Gpackets/GCVisibleFail.h Gpackets/GCNPCInfo.h \
  Gpackets/GCNPCAskVariable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ScriptParameter.h Gpackets/GCWarScheduleList.h Gpackets/GCWarList.h \
  GuildWarInfo.h PacketFactory.h WarInfo.h ValueList.h types/WarTypes.h \
  RaceWarInfo.h Gpackets/GMServerInfo.h DatagramPacket.h Datagram.h \
  SocketAPI.h Gpackets/GLIncomingConnection.h \
  Gpackets/GLIncomingConnectionError.h Gpackets/GLIncomingConnectionOK.h \
  Gpackets/GLKickVerify.h Lpackets/LCCreatePCError.h Packet.h \
  PacketFactory.h Lpackets/LCCreatePCOK.h Lpackets/LCDeletePCError.h \
  Lpackets/LCDeletePCOK.h Lpackets/LCLoginError.h Lpackets/LCLoginOK.h \
  Lpackets/LCPCList.h PCInfo.h PCSlayerInfo.h PCVampireInfo.h \
  PCOustersInfo.h Lpackets/LCQueryResultPlayerID.h \
  Lpackets/LCQueryResultCharacterName.h Lpackets/LCReconnect.h \
  Lpackets/LCRegisterPlayerError.h Lpackets/LCRegisterPlayerOK.h \
  Lpackets/LCSelectPCError.h Lpackets/LGIncomingConnection.h \
  DatagramPacket.h Lpackets/LGIncomingConnectionOK.h \
  Lpackets/LGIncomingConnectionError.h Lpackets/LGKickCharacter.h \
  Lpackets/LCVersionCheckOK.h Lpackets/LCVersionCheckError.h \
  Lpackets/LCServerList.h ServerGroupInfo.h Lpackets/LCWorldList.h \
  WorldInfo.h Cpackets/CGWhisper.h Gpackets/GCWhisper.h \
  Gpackets/GCWhisperFailed.h Gpackets/GCSkillInfo.h PCSkillInfo.h \
  SlayerSkillInfo.h PCSkillInfo.h SubSlayerSkillInfo.h VampireSkillInfo.h \
  SubVampireSkillInfo.h Gpackets/GCStatusCurrentHP.h \
  Cpackets/CGSetSlayerHotKey.h Cpackets/CGSetVampireHotKey.h \
  Cpackets/CGSelectPortal.h Cpackets/CGMouseToStash.h \
  Cpackets/CGStashToMouse.h Cpackets/CGStashList.h Gpackets/GCStashList.h \
  Cpackets/CGStashDeposit.h Cpackets/CGStashWithdraw.h \
  Cpackets/CGStashRequestBuy.h Gpackets/GCStashSell.h \
  Cpackets/CGTradePrepare.h Cpackets/CGTradeAddItem.h \
  Cpackets/CGTradeRemoveItem.h Cpackets/CGTradeMoney.h \
  Cpackets/CGTradeFinish.h Gpackets/GCTradePrepare.h \
  Gpackets/GCTradeAddItem.h Gpackets/GCTradeRemoveItem.h \
  Gpackets/GCTradeMoney.h Gpackets/GCTradeFinish.h \
  Gpackets/GCTradeError.h Gpackets/GCTradeVerify.h \
  Cpackets/CGSkillToObject.h Cpackets/CGSkillToSelf.h \
  Cpackets/CGSkillToTile.h Cpackets/CGSilverCoating.h \
  Gpackets/GCNPCResponse.h Gpackets/GCNPCSayDynamic.h \
  Gpackets/GCNPCAskDynamic.h Cpackets/CGUseItemFromInventory.h \
  Cpackets/CGSelectWayPoint.h Gpackets/GCAddHelicopter.h \
  Gpackets/GCAddVampirePortal.h Gpackets/GCEnterVampirePortal.h \
  Cpackets/CGSelectTileEffect.h Cpackets/CGPartyInvite.h \
  Cpackets/CGPartyLeave.h Gpackets/GCPartyInvite.h \
  Gpackets/GCPartyLeave.h Gpackets/GCPartyJoined.h \
  Gpackets/GCPartyError.h Cpackets/CGResurrect.h Cpackets/CGRequestIP.h \
  Gpackets/GCRequestedIP.h Gpackets/GCRequestFailed.h \
  Gpackets/GCOtherModifyInfo.h Gpackets/GGCommand.h \
  Cpackets/CGRegistGuild.h Gpackets/GCWaitGuildList.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  GuildInfo.h Gpackets/GCShowWaitGuildInfo.h Gpackets/GCShowGuildInfo.h \
  Cpackets/CGSelectGuild.h Cpackets/CGTryJoinGuild.h \
  Gpackets/GCShowGuildJoin.h Cpackets/CGJoinGuild.h \
  Gpackets/GCShowMessageBox.h Cpackets/CGRequestGuildMemberList.h \
  Cpackets/CGSelectGuildMember.h Cpackets/CGModifyGuildMember.h \
  Gpackets/GCActiveGuildList.h Gpackets/GCShowGuildMemberInfo.h \
  Gpackets/GCGuildMemberList.h GuildMemberInfo.h \
  Gpackets/GCModifyGuildMemberInfo.h Gpackets/GSAddGuild.h \
  Gpackets/GSAddGuildMember.h Gpackets/GSQuitGuild.h \
  Gpackets/GSExpelGuildMember.h Gpackets/GSModifyGuildMember.h \
  Spackets/SGAddGuildOK.h Packet.h PacketFactory.h \
  Spackets/SGAddGuildMemberOK.h Spackets/SGQuitGuildOK.h \
  Spackets/SGExpelGuildMemberOK.h Spackets/SGModifyGuildMemberOK.h \
  Spackets/SGDeleteGuildOK.h Spackets/SGModifyGuildOK.h \
  Cpackets/CGRelicToObject.h Cpackets/CGPortCheck.h DatagramPacket.h \
  Cpackets/CGGuildChat.h Gpackets/GCGuildChat.h Gpackets/GGGuildChat.h \
  Gpackets/GSRequestGuildInfo.h Spackets/SGGuildInfo.h GuildInfo2.h \
  GuildMemberInfo2.h GuildMemberInfo2.h Cpackets/CGAddItemToItem.h \
  Gpackets/GCAddItemToItemVerify.h Cpackets/CGRequestInfo.h \
  Gpackets/GCNoticeEvent.h Utility.h Cpackets/CGModifyGuildIntro.h \
  Cpackets/CGModifyGuildMemberIntro.h Gpackets/GSModifyGuildIntro.h \
  Spackets/SGModifyGuildIntroOK.h Gpackets/GSGuildMemberLogOn.h \
  Spackets/SGGuildMemberLogOnOK.h Cpackets/CGSelectRankBonus.h \
  Gpackets/GCSelectRankBonusOK.h Gpackets/GCSelectRankBonusFailed.h \
  Gpackets/GCRankBonusInfo.h Cpackets/CGSkillToNamed.h \
  Cpackets/CGUseMessageItemFromInventory.h \
  Cpackets/CGUseItemFromInventory.h Gpackets/GCHolyLandBonusInfo.h \
  BloodBibleBonusInfo.h Gpackets/GCBloodBibleStatus.h \
  Gpackets/GCKickMessage.h Gpackets/GCTimeLimitItemInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tree.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_map.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_multimap.h \
  Gpackets/GCSelectQuestID.h Cpackets/CGSelectQuest.h \
  Gpackets/GCQuestStatus.h Gpackets/GCMonsterKillQuestInfo.h \
  Gpackets/GCSelectQuestID.h Cpackets/CGLotterySelect.h \
  Gpackets/GCNotifyWin.h Gpackets/GCGoodsList.h Cpackets/CGTakeOutGood.h \
  Gpackets/GCTakeOutOK.h Gpackets/GCTakeOutFail.h Gpackets/GCAddOusters.h \
  PCOustersInfo3.h Cpackets/CGMixItem.h Assert.h \
  Gpackets/GCAddOustersCorpse.h Cpackets/CGAbsorbSoul.h \
  Cpackets/CGDownSkill.h Gpackets/GCDownSkillOK.h \
  Gpackets/GCDownSkillFailed.h Gpackets/GCMiniGameScores.h \
  Cpackets/CGSubmitScore.h Cpackets/CGFailQuest.h \
  Cpackets/CGAddItemToCodeSheet.h Gpackets/GCFlagWarStatus.h \
  Gpackets/GCOtherGuildName.h Gpackets/GCSweeperBonusInfo.h \
  SweeperBonusInfo.h Cpackets/CGSelectRegenZone.h \
  Gpackets/GCRegenZoneStatus.h Gpackets/GCPetInfo.h \
  Cpackets/CGTameMonster.h Cpackets/CGPetGamble.h \
  Cpackets/CGCrashReport.h Gpackets/GCPetUseSkill.h \
  Gpackets/GCSystemAvailabilities.h Gpackets/GCPartyPosition.h \
  Cpackets/CGPartyPosition.h Gpackets/GCPartySay.h Cpackets/CGPartySay.h \
  Gpackets/GGServerChat.h Gpackets/GCPetStashList.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/numeric \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_numeric.h \
  Cpackets/CGWithdrawPet.h Cpackets/CGDepositPet.h \
  Gpackets/GCPetStashVerify.h
PacketIDSet.o: PacketIDSet.cpp PacketIDSet.h Packet.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PlayerStatus.h Assert.h
PacketValidator.o: PacketValidator.cpp PacketValidator.h PacketIDSet.h \
  Packet.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PlayerStatus.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc
PacketFactoryManager.o: PacketFactoryManager.cpp Assert.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  PacketFactoryManager.h Packet.h SocketInputStream.h Socket.h \
  SocketImpl.h SocketAPI.h SocketOutputStream.h PacketFactory.h \
  Cpackets/CGAttack.h Types.h Exception.h Packet.h PacketFactory.h \
  Cpackets/CGAddGearToMouse.h Cpackets/CGAddInventoryToMouse.h \
  Cpackets/CGAddMouseToGear.h Cpackets/CGAddMouseToInventory.h \
  Cpackets/CGAddMouseToQuickSlot.h Cpackets/CGAddMouseToZone.h \
  Cpackets/CGAddQuickSlotToMouse.h Cpackets/CGAddZoneToMouse.h \
  Cpackets/CGAddZoneToInventory.h Cpackets/CGBloodDrain.h \
  Cpackets/CGUnburrow.h Cpackets/CGUntransform.h \
  Cpackets/CGCastingSkill.h Cpackets/CGConnect.h \
  Cpackets/CGDissectionCorpse.h Cpackets/CGDropMoney.h \
  Cpackets/CGGetOffMotorCycle.h Cpackets/CGGlobalChat.h \
  Cpackets/CGLearnSkill.h Cpackets/CGLogout.h Cpackets/CGMakeItem.h \
  Cpackets/CGMove.h Cpackets/CGNPCAskAnswer.h Cpackets/CGNPCTalk.h \
  Cpackets/CGPickupMoney.h Cpackets/CGReady.h \
  Cpackets/CGReloadFromInventory.h Cpackets/CGReloadFromQuickSlot.h \
  Cpackets/CGRideMotorCycle.h Cpackets/CGSay.h \
  Cpackets/CGShopRequestBuy.h Cpackets/CGShopRequestList.h \
  Cpackets/CGShopRequestSell.h Cpackets/CGSkillToInventory.h \
  Cpackets/CGThrowBomb.h Gpackets/GCThrowBombOK1.h Types.h Exception.h \
  ModifyInfo.h Types.h Exception.h Packet.h PacketFactory.h \
  Gpackets/GCThrowBombOK2.h Gpackets/GCThrowBombOK3.h Packet.h \
  Cpackets/CGThrowItem.h Cpackets/CGUseBonusPoint.h \
  Cpackets/CGUsePotionFromInventory.h Cpackets/CGUsePotionFromQuickSlot.h \
  Cpackets/CGRequestRepair.h Cpackets/CGVisible.h Cpackets/CGVerifyTime.h \
  Cpackets/CGRequestNewbieItem.h Cpackets/CGWithdrawTax.h \
  Cpackets/CGTypeStringList.h Cpackets/CGUseItemFromGear.h \
  Cpackets/CLCreatePC.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  Cpackets/CLDeletePC.h Cpackets/CLGetPCList.h Cpackets/CLLogin.h \
  Cpackets/CLLogout.h Cpackets/CLQueryPlayerID.h \
  Cpackets/CLQueryCharacterName.h Cpackets/CLRegisterPlayer.h \
  Cpackets/CLSelectPC.h Player.h Cpackets/CLVersionCheck.h \
  Cpackets/CLGetServerList.h Cpackets/CLChangeServer.h \
  Cpackets/CLReconnectLogin.h Cpackets/CLGetWorldList.h \
  Cpackets/CLSelectWorld.h Cpackets/CLSelectServer.h Gpackets/GCAddBat.h \
  Gpackets/GCAddBurrowingCreature.h Gpackets/GCAddEffect.h \
  Gpackets/GCAddEffectToTile.h Gpackets/GCAddGearToInventory.h \
  Gpackets/GCAddGearToZone.h Gpackets/GCAddInstalledMineToZone.h \
  SubItemInfo.h SocketInputStream.h SocketOutputStream.h \
  Gpackets/GCAddItemToZone.h Gpackets/GCAddMonster.h EffectInfo.h \
  Gpackets/GCAddMonsterCorpse.h Gpackets/GCAddMonsterFromBurrowing.h \
  Gpackets/GCAddMonsterFromTransformation.h Gpackets/GCAddNewItemToZone.h \
  Gpackets/GCAddNPC.h Gpackets/GCAddSlayer.h PCSlayerInfo3.h PCInfo.h \
  Assert.h PetInfo.h types/PetTypes.h types/SystemTypes.h VSDateTime.h \
  Gpackets/GCAddSlayerCorpse.h Gpackets/GCAddVampire.h PCVampireInfo3.h \
  Gpackets/GCAddVampireCorpse.h Gpackets/GCAddVampireFromBurrowing.h \
  Gpackets/GCAddVampireFromTransformation.h Gpackets/GCAddWolf.h \
  Gpackets/GCAddInjuriousCreature.h Gpackets/GCAttackArmsOK1.h \
  Gpackets/GCAttackArmsOK2.h Gpackets/GCAttackArmsOK3.h \
  Gpackets/GCAttackArmsOK4.h Gpackets/GCAttackArmsOK5.h \
  Gpackets/GCAttackMeleeOK1.h Gpackets/GCAttackMeleeOK2.h \
  Gpackets/GCAttackMeleeOK3.h Gpackets/GCAttack.h \
  Gpackets/GCBloodDrainOK1.h Gpackets/GCBloodDrainOK2.h \
  Gpackets/GCBloodDrainOK3.h Gpackets/GCCannotAdd.h \
  Gpackets/GCCannotUse.h Gpackets/GCCastingSkill.h \
  Gpackets/GCCreateItem.h Gpackets/GCCreatureDied.h \
  Gpackets/GCChangeShape.h Gpackets/GCChangeDarkLight.h \
  Gpackets/GCChangeWeather.h Gpackets/GCCrossCounterOK1.h \
  Gpackets/GCCrossCounterOK2.h Gpackets/GCCrossCounterOK3.h \
  Gpackets/GCDeleteInventoryItem.h Gpackets/GCDeleteObject.h \
  Gpackets/GCRemoveCorpseHead.h Gpackets/GCRemoveInjuriousCreature.h \
  Gpackets/GCDeleteandPickUpOK.h Gpackets/GCDeleteEffectFromTile.h \
  Gpackets/GCDisconnect.h Gpackets/GCDropItemToZone.h \
  Gpackets/GCFastMove.h Gpackets/GCFakeMove.h Gpackets/GCGetDamage.h \
  Gpackets/GCGetOffMotorCycle.h Gpackets/GCGetOffMotorCycleFailed.h \
  Gpackets/GCGetOffMotorCycleOK.h Gpackets/GCGlobalChat.h \
  Gpackets/GCHPRecoveryStartToSelf.h Gpackets/GCHPRecoveryStartToOthers.h \
  Gpackets/GCHPRecoveryEndToSelf.h Gpackets/GCHPRecoveryEndToOthers.h \
  Gpackets/GCKnockBack.h Gpackets/GCKnocksTargetBackOK1.h \
  ModifyItemInfo.h ModifyInfo.h Gpackets/GCKnocksTargetBackOK2.h \
  Gpackets/GCKnocksTargetBackOK4.h Gpackets/GCKnocksTargetBackOK5.h \
  Gpackets/GCLearnSkillFailed.h Gpackets/GCLearnSkillOK.h \
  Gpackets/GCLearnSkillReady.h Gpackets/GCLightning.h \
  Gpackets/GCMakeItemOK.h Gpackets/GCChangeInventoryItemNum.h \
  Gpackets/GCAddItemToInventory.h Gpackets/GCMakeItemFail.h \
  Gpackets/GCMineExplosionOK1.h Gpackets/GCMineExplosionOK2.h \
  Gpackets/GCModifyInformation.h Gpackets/GCMorph1.h GameTime.h \
  PCSlayerInfo2.h PCVampireInfo2.h InventoryInfo.h InventorySlotInfo.h \
  PCItemInfo.h SubItemInfo.h GearInfo.h GearSlotInfo.h ExtraInfo.h \
  ExtraSlotInfo.h Assert.h Gpackets/GCMorphSlayer2.h \
  Gpackets/GCMorphVampire2.h Gpackets/GCMove.h Gpackets/GCMoveOK.h \
  Gpackets/GCMoveError.h Gpackets/GCMPRecoveryStart.h \
  Gpackets/GCMPRecoveryEnd.h Gpackets/GCNPCAsk.h Gpackets/GCNPCSay.h \
  Gpackets/GCRealWearingInfo.h Gpackets/GCReconnect.h \
  Gpackets/GCReconnectLogin.h Gpackets/GCRemoveEffect.h \
  Gpackets/GCRemoveFromGear.h Gpackets/GCRideMotorCycle.h \
  Gpackets/GCRideMotorCycleFailed.h Gpackets/GCRideMotorCycleOK.h \
  Gpackets/GCReloadOK.h Gpackets/GCSay.h Gpackets/GCSearchMotorcycleOK.h \
  Gpackets/GCSearchMotorcycleFail.h Gpackets/GCSetPosition.h \
  Gpackets/GCShopBuyOK.h Gpackets/GCShopBuyFail.h Gpackets/GCShopList.h \
  Gpackets/GCShopListMysterious.h Gpackets/GCShopSold.h \
  Gpackets/GCShopVersion.h Gpackets/GCShopBought.h \
  Gpackets/GCShopSellOK.h Gpackets/GCShopSellFail.h \
  Gpackets/GCShopMarketCondition.h Gpackets/GCSkillFailed1.h \
  Gpackets/GCSkillFailed2.h Gpackets/GCSkillToInventoryOK1.h \
  Gpackets/GCSkillToInventoryOK2.h Gpackets/GCSkillToObjectOK1.h \
  Gpackets/GCSkillToObjectOK2.h Gpackets/GCSkillToObjectOK3.h \
  Gpackets/GCSkillToObjectOK4.h Gpackets/GCSkillToObjectOK5.h \
  Gpackets/GCSkillToObjectOK6.h Gpackets/GCSkillToSelfOK1.h \
  Gpackets/GCSkillToSelfOK2.h Gpackets/GCSkillToSelfOK3.h \
  Gpackets/GCSkillToTileOK1.h Gpackets/GCSkillToTileOK2.h \
  Gpackets/GCSkillToTileOK3.h Gpackets/GCSkillToTileOK4.h \
  Gpackets/GCSkillToTileOK5.h Gpackets/GCSkillToTileOK6.h \
  Gpackets/GCSystemMessage.h Gpackets/GCUnburrowOK.h \
  Gpackets/GCUnburrowFail.h Gpackets/GCUntransformOK.h \
  Gpackets/GCUntransformFail.h Gpackets/GCTeachSkillInfo.h \
  Gpackets/GCUpdateInfo.h RideMotorcycleInfo.h RideMotorcycleSlotInfo.h \
  NPCInfo.h Gpackets/GCUseBonusPointFail.h Gpackets/GCUseBonusPointOK.h \
  Gpackets/GCUseOK.h Gpackets/GCTakeOff.h Gpackets/GCThrowItemOK1.h \
  Gpackets/GCThrowItemOK2.h Gpackets/GCThrowItemOK3.h \
  Gpackets/GCVisibleOK.h Gpackets/GCVisibleFail.h Gpackets/GCNPCInfo.h \
  Gpackets/GCNPCAskVariable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ScriptParameter.h Gpackets/GCWarScheduleList.h Gpackets/GCWarList.h \
  GuildWarInfo.h PacketFactory.h WarInfo.h ValueList.h types/WarTypes.h \
  RaceWarInfo.h Gpackets/GMServerInfo.h DatagramPacket.h Datagram.h \
  SocketAPI.h Gpackets/GLIncomingConnection.h \
  Gpackets/GLIncomingConnectionError.h Gpackets/GLIncomingConnectionOK.h \
  Gpackets/GLKickVerify.h Lpackets/LCCreatePCError.h Packet.h \
  PacketFactory.h Lpackets/LCCreatePCOK.h Lpackets/LCDeletePCError.h \
  Lpackets/LCDeletePCOK.h Lpackets/LCLoginError.h Lpackets/LCLoginOK.h \
  Lpackets/LCPCList.h PCInfo.h PCSlayerInfo.h PCVampireInfo.h \
  PCOustersInfo.h Lpackets/LCQueryResultPlayerID.h \
  Lpackets/LCQueryResultCharacterName.h Lpackets/LCReconnect.h \
  Lpackets/LCRegisterPlayerError.h Lpackets/LCRegisterPlayerOK.h \
  Lpackets/LCSelectPCError.h Lpackets/LGIncomingConnection.h \
  DatagramPacket.h Lpackets/LGIncomingConnectionOK.h \
  Lpackets/LGIncomingConnectionError.h Lpackets/LGKickCharacter.h \
  Lpackets/LCVersionCheckOK.h Lpackets/LCVersionCheckError.h \
  Lpackets/LCServerList.h ServerGroupInfo.h Lpackets/LCWorldList.h \
  WorldInfo.h Cpackets/CGWhisper.h Gpackets/GCWhisper.h \
  Gpackets/GCWhisperFailed.h Gpackets/GCSkillInfo.h PCSkillInfo.h \
  SlayerSkillInfo.h PCSkillInfo.h SubSlayerSkillInfo.h VampireSkillInfo.h \
  SubVampireSkillInfo.h Gpackets/GCStatusCurrentHP.h \
  Cpackets/CGSetSlayerHotKey.h Cpackets/CGSetVampireHotKey.h \
  Cpackets/CGSelectPortal.h Cpackets/CGMouseToStash.h \
  Cpackets/CGStashToMouse.h Cpackets/CGStashList.h Gpackets/GCStashList.h \
  Cpackets/CGStashDeposit.h Cpackets/CGStashWithdraw.h \
  Cpackets/CGStashRequestBuy.h Gpackets/GCStashSell.h \
  Cpackets/CGTradePrepare.h Cpackets/CGTradeAddItem.h \
  Cpackets/CGTradeRemoveItem.h Cpackets/CGTradeMoney.h \
  Cpackets/CGTradeFinish.h Gpackets/GCTradePrepare.h \
  Gpackets/GCTradeAddItem.h Gpackets/GCTradeRemoveItem.h \
  Gpackets/GCTradeMoney.h Gpackets/GCTradeFinish.h \
  Gpackets/GCTradeError.h Gpackets/GCTradeVerify.h \
  Cpackets/CGSkillToObject.h Cpackets/CGSkillToSelf.h \
  Cpackets/CGSkillToTile.h Cpackets/CGSilverCoating.h \
  Gpackets/GCNPCResponse.h Gpackets/GCNPCSayDynamic.h \
  Gpackets/GCNPCAskDynamic.h Cpackets/CGUseItemFromInventory.h \
  Cpackets/CGSelectWayPoint.h Gpackets/GCAddHelicopter.h \
  Gpackets/GCAddVampirePortal.h Gpackets/GCEnterVampirePortal.h \
  Cpackets/CGSelectTileEffect.h Cpackets/CGPartyInvite.h \
  Cpackets/CGPartyLeave.h Gpackets/GCPartyInvite.h \
  Gpackets/GCPartyLeave.h Gpackets/GCPartyJoined.h \
  Gpackets/GCPartyError.h Cpackets/CGResurrect.h Cpackets/CGRequestIP.h \
  Gpackets/GCRequestedIP.h Gpackets/GCRequestFailed.h \
  Gpackets/GCOtherModifyInfo.h Gpackets/GGCommand.h \
  Cpackets/CGRegistGuild.h Gpackets/GCWaitGuildList.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  GuildInfo.h Gpackets/GCShowWaitGuildInfo.h Gpackets/GCShowGuildInfo.h \
  Cpackets/CGSelectGuild.h Cpackets/CGTryJoinGuild.h \
  Gpackets/GCShowGuildJoin.h Cpackets/CGJoinGuild.h \
  Gpackets/GCShowMessageBox.h Cpackets/CGRequestGuildMemberList.h \
  Cpackets/CGSelectGuildMember.h Cpackets/CGModifyGuildMember.h \
  Gpackets/GCActiveGuildList.h Gpackets/GCShowGuildMemberInfo.h \
  Gpackets/GCGuildMemberList.h GuildMemberInfo.h \
  Gpackets/GCModifyGuildMemberInfo.h Gpackets/GSAddGuild.h \
  Gpackets/GSAddGuildMember.h Gpackets/GSQuitGuild.h \
  Gpackets/GSExpelGuildMember.h Gpackets/GSModifyGuildMember.h \
  Spackets/SGAddGuildOK.h Packet.h PacketFactory.h \
  Spackets/SGAddGuildMemberOK.h Spackets/SGQuitGuildOK.h \
  Spackets/SGExpelGuildMemberOK.h Spackets/SGModifyGuildMemberOK.h \
  Spackets/SGDeleteGuildOK.h Spackets/SGModifyGuildOK.h \
  Cpackets/CGRelicToObject.h Cpackets/CGPortCheck.h DatagramPacket.h \
  Cpackets/CGGuildChat.h Gpackets/GCGuildChat.h Gpackets/GGGuildChat.h \
  Gpackets/GSRequestGuildInfo.h Spackets/SGGuildInfo.h GuildInfo2.h \
  GuildMemberInfo2.h GuildMemberInfo2.h Cpackets/CGAddItemToItem.h \
  Gpackets/GCAddItemToItemVerify.h Cpackets/CGRequestInfo.h \
  Gpackets/GCNoticeEvent.h Utility.h Cpackets/CGModifyGuildIntro.h \
  Cpackets/CGModifyGuildMemberIntro.h Gpackets/GSModifyGuildIntro.h \
  Spackets/SGModifyGuildIntroOK.h Gpackets/GSGuildMemberLogOn.h \
  Spackets/SGGuildMemberLogOnOK.h Cpackets/CGSelectRankBonus.h \
  Gpackets/GCSelectRankBonusOK.h Gpackets/GCSelectRankBonusFailed.h \
  Gpackets/GCRankBonusInfo.h Cpackets/CGSkillToNamed.h \
  Cpackets/CGUseMessageItemFromInventory.h \
  Cpackets/CGUseItemFromInventory.h Gpackets/GCHolyLandBonusInfo.h \
  BloodBibleBonusInfo.h Gpackets/GCBloodBibleStatus.h \
  Gpackets/GCKickMessage.h Gpackets/GCTimeLimitItemInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tree.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_map.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_multimap.h \
  Gpackets/GCSelectQuestID.h Cpackets/CGSelectQuest.h \
  Gpackets/GCQuestStatus.h Gpackets/GCMonsterKillQuestInfo.h \
  Gpackets/GCSelectQuestID.h Cpackets/CGLotterySelect.h \
  Gpackets/GCNotifyWin.h Gpackets/GCGoodsList.h Cpackets/CGTakeOutGood.h \
  Gpackets/GCTakeOutOK.h Gpackets/GCTakeOutFail.h Gpackets/GCAddOusters.h \
  PCOustersInfo3.h Cpackets/CGMixItem.h Assert.h \
  Gpackets/GCAddOustersCorpse.h Cpackets/CGAbsorbSoul.h \
  Cpackets/CGDownSkill.h Gpackets/GCDownSkillOK.h \
  Gpackets/GCDownSkillFailed.h Gpackets/GCMiniGameScores.h \
  Cpackets/CGSubmitScore.h Cpackets/CGFailQuest.h \
  Cpackets/CGAddItemToCodeSheet.h Gpackets/GCFlagWarStatus.h \
  Gpackets/GCOtherGuildName.h Gpackets/GCSweeperBonusInfo.h \
  SweeperBonusInfo.h Cpackets/CGSelectRegenZone.h \
  Gpackets/GCRegenZoneStatus.h Gpackets/GCPetInfo.h \
  Cpackets/CGTameMonster.h Cpackets/CGPetGamble.h \
  Cpackets/CGCrashReport.h Gpackets/GCPetUseSkill.h \
  Gpackets/GCSystemAvailabilities.h Gpackets/GCPartyPosition.h \
  Cpackets/CGPartyPosition.h Gpackets/GCPartySay.h Cpackets/CGPartySay.h \
  Gpackets/GGServerChat.h Gpackets/GCPetStashList.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/numeric \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_numeric.h \
  Cpackets/CGWithdrawPet.h Cpackets/CGDepositPet.h \
  Gpackets/GCPetStashVerify.h
PacketIDSet.o: PacketIDSet.cpp PacketIDSet.h Packet.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PlayerStatus.h Assert.h
PacketValidator.o: PacketValidator.cpp PacketValidator.h PacketIDSet.h \
  Packet.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PlayerStatus.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc
PacketFactoryManager.o: PacketFactoryManager.cpp Assert.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  PacketFactoryManager.h Packet.h SocketInputStream.h Socket.h \
  SocketImpl.h SocketAPI.h SocketOutputStream.h PacketFactory.h \
  Cpackets/CGAttack.h Types.h Exception.h Packet.h PacketFactory.h \
  Cpackets/CGAddGearToMouse.h Cpackets/CGAddInventoryToMouse.h \
  Cpackets/CGAddMouseToGear.h Cpackets/CGAddMouseToInventory.h \
  Cpackets/CGAddMouseToQuickSlot.h Cpackets/CGAddMouseToZone.h \
  Cpackets/CGAddQuickSlotToMouse.h Cpackets/CGAddZoneToMouse.h \
  Cpackets/CGAddZoneToInventory.h Cpackets/CGBloodDrain.h \
  Cpackets/CGUnburrow.h Cpackets/CGUntransform.h \
  Cpackets/CGCastingSkill.h Cpackets/CGConnect.h \
  Cpackets/CGDissectionCorpse.h Cpackets/CGDropMoney.h \
  Cpackets/CGGetOffMotorCycle.h Cpackets/CGGlobalChat.h \
  Cpackets/CGLearnSkill.h Cpackets/CGLogout.h Cpackets/CGMakeItem.h \
  Cpackets/CGMove.h Cpackets/CGNPCAskAnswer.h Cpackets/CGNPCTalk.h \
  Cpackets/CGPickupMoney.h Cpackets/CGReady.h \
  Cpackets/CGReloadFromInventory.h Cpackets/CGReloadFromQuickSlot.h \
  Cpackets/CGRideMotorCycle.h Cpackets/CGSay.h \
  Cpackets/CGShopRequestBuy.h Cpackets/CGShopRequestList.h \
  Cpackets/CGShopRequestSell.h Cpackets/CGSkillToInventory.h \
  Cpackets/CGThrowBomb.h Gpackets/GCThrowBombOK1.h Types.h Exception.h \
  ModifyInfo.h Types.h Exception.h Packet.h PacketFactory.h \
  Gpackets/GCThrowBombOK2.h Gpackets/GCThrowBombOK3.h Packet.h \
  Cpackets/CGThrowItem.h Cpackets/CGUseBonusPoint.h \
  Cpackets/CGUsePotionFromInventory.h Cpackets/CGUsePotionFromQuickSlot.h \
  Cpackets/CGRequestRepair.h Cpackets/CGVisible.h Cpackets/CGVerifyTime.h \
  Cpackets/CGRequestNewbieItem.h Cpackets/CGWithdrawTax.h \
  Cpackets/CGTypeStringList.h Cpackets/CGUseItemFromGear.h \
  Cpackets/CLCreatePC.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  Cpackets/CLDeletePC.h Cpackets/CLGetPCList.h Cpackets/CLLogin.h \
  Cpackets/CLLogout.h Cpackets/CLQueryPlayerID.h \
  Cpackets/CLQueryCharacterName.h Cpackets/CLRegisterPlayer.h \
  Cpackets/CLSelectPC.h Player.h Cpackets/CLVersionCheck.h \
  Cpackets/CLGetServerList.h Cpackets/CLChangeServer.h \
  Cpackets/CLReconnectLogin.h Cpackets/CLGetWorldList.h \
  Cpackets/CLSelectWorld.h Cpackets/CLSelectServer.h Gpackets/GCAddBat.h \
  Gpackets/GCAddBurrowingCreature.h Gpackets/GCAddEffect.h \
  Gpackets/GCAddEffectToTile.h Gpackets/GCAddGearToInventory.h \
  Gpackets/GCAddGearToZone.h Gpackets/GCAddInstalledMineToZone.h \
  SubItemInfo.h SocketInputStream.h SocketOutputStream.h \
  Gpackets/GCAddItemToZone.h Gpackets/GCAddMonster.h EffectInfo.h \
  Gpackets/GCAddMonsterCorpse.h Gpackets/GCAddMonsterFromBurrowing.h \
  Gpackets/GCAddMonsterFromTransformation.h Gpackets/GCAddNewItemToZone.h \
  Gpackets/GCAddNPC.h Gpackets/GCAddSlayer.h PCSlayerInfo3.h PCInfo.h \
  Assert.h PetInfo.h types/PetTypes.h types/SystemTypes.h VSDateTime.h \
  Gpackets/GCAddSlayerCorpse.h Gpackets/GCAddVampire.h PCVampireInfo3.h \
  Gpackets/GCAddVampireCorpse.h Gpackets/GCAddVampireFromBurrowing.h \
  Gpackets/GCAddVampireFromTransformation.h Gpackets/GCAddWolf.h \
  Gpackets/GCAddInjuriousCreature.h Gpackets/GCAttackArmsOK1.h \
  Gpackets/GCAttackArmsOK2.h Gpackets/GCAttackArmsOK3.h \
  Gpackets/GCAttackArmsOK4.h Gpackets/GCAttackArmsOK5.h \
  Gpackets/GCAttackMeleeOK1.h Gpackets/GCAttackMeleeOK2.h \
  Gpackets/GCAttackMeleeOK3.h Gpackets/GCAttack.h \
  Gpackets/GCBloodDrainOK1.h Gpackets/GCBloodDrainOK2.h \
  Gpackets/GCBloodDrainOK3.h Gpackets/GCCannotAdd.h \
  Gpackets/GCCannotUse.h Gpackets/GCCastingSkill.h \
  Gpackets/GCCreateItem.h Gpackets/GCCreatureDied.h \
  Gpackets/GCChangeShape.h Gpackets/GCChangeDarkLight.h \
  Gpackets/GCChangeWeather.h Gpackets/GCCrossCounterOK1.h \
  Gpackets/GCCrossCounterOK2.h Gpackets/GCCrossCounterOK3.h \
  Gpackets/GCDeleteInventoryItem.h Gpackets/GCDeleteObject.h \
  Gpackets/GCRemoveCorpseHead.h Gpackets/GCRemoveInjuriousCreature.h \
  Gpackets/GCDeleteandPickUpOK.h Gpackets/GCDeleteEffectFromTile.h \
  Gpackets/GCDisconnect.h Gpackets/GCDropItemToZone.h \
  Gpackets/GCFastMove.h Gpackets/GCFakeMove.h Gpackets/GCGetDamage.h \
  Gpackets/GCGetOffMotorCycle.h Gpackets/GCGetOffMotorCycleFailed.h \
  Gpackets/GCGetOffMotorCycleOK.h Gpackets/GCGlobalChat.h \
  Gpackets/GCHPRecoveryStartToSelf.h Gpackets/GCHPRecoveryStartToOthers.h \
  Gpackets/GCHPRecoveryEndToSelf.h Gpackets/GCHPRecoveryEndToOthers.h \
  Gpackets/GCKnockBack.h Gpackets/GCKnocksTargetBackOK1.h \
  ModifyItemInfo.h ModifyInfo.h Gpackets/GCKnocksTargetBackOK2.h \
  Gpackets/GCKnocksTargetBackOK4.h Gpackets/GCKnocksTargetBackOK5.h \
  Gpackets/GCLearnSkillFailed.h Gpackets/GCLearnSkillOK.h \
  Gpackets/GCLearnSkillReady.h Gpackets/GCLightning.h \
  Gpackets/GCMakeItemOK.h Gpackets/GCChangeInventoryItemNum.h \
  Gpackets/GCAddItemToInventory.h Gpackets/GCMakeItemFail.h \
  Gpackets/GCMineExplosionOK1.h Gpackets/GCMineExplosionOK2.h \
  Gpackets/GCModifyInformation.h Gpackets/GCMorph1.h GameTime.h \
  PCSlayerInfo2.h PCVampireInfo2.h InventoryInfo.h InventorySlotInfo.h \
  PCItemInfo.h SubItemInfo.h GearInfo.h GearSlotInfo.h ExtraInfo.h \
  ExtraSlotInfo.h Assert.h Gpackets/GCMorphSlayer2.h \
  Gpackets/GCMorphVampire2.h Gpackets/GCMove.h Gpackets/GCMoveOK.h \
  Gpackets/GCMoveError.h Gpackets/GCMPRecoveryStart.h \
  Gpackets/GCMPRecoveryEnd.h Gpackets/GCNPCAsk.h Gpackets/GCNPCSay.h \
  Gpackets/GCRealWearingInfo.h Gpackets/GCReconnect.h \
  Gpackets/GCReconnectLogin.h Gpackets/GCRemoveEffect.h \
  Gpackets/GCRemoveFromGear.h Gpackets/GCRideMotorCycle.h \
  Gpackets/GCRideMotorCycleFailed.h Gpackets/GCRideMotorCycleOK.h \
  Gpackets/GCReloadOK.h Gpackets/GCSay.h Gpackets/GCSearchMotorcycleOK.h \
  Gpackets/GCSearchMotorcycleFail.h Gpackets/GCSetPosition.h \
  Gpackets/GCShopBuyOK.h Gpackets/GCShopBuyFail.h Gpackets/GCShopList.h \
  Gpackets/GCShopListMysterious.h Gpackets/GCShopSold.h \
  Gpackets/GCShopVersion.h Gpackets/GCShopBought.h \
  Gpackets/GCShopSellOK.h Gpackets/GCShopSellFail.h \
  Gpackets/GCShopMarketCondition.h Gpackets/GCSkillFailed1.h \
  Gpackets/GCSkillFailed2.h Gpackets/GCSkillToInventoryOK1.h \
  Gpackets/GCSkillToInventoryOK2.h Gpackets/GCSkillToObjectOK1.h \
  Gpackets/GCSkillToObjectOK2.h Gpackets/GCSkillToObjectOK3.h \
  Gpackets/GCSkillToObjectOK4.h Gpackets/GCSkillToObjectOK5.h \
  Gpackets/GCSkillToObjectOK6.h Gpackets/GCSkillToSelfOK1.h \
  Gpackets/GCSkillToSelfOK2.h Gpackets/GCSkillToSelfOK3.h \
  Gpackets/GCSkillToTileOK1.h Gpackets/GCSkillToTileOK2.h \
  Gpackets/GCSkillToTileOK3.h Gpackets/GCSkillToTileOK4.h \
  Gpackets/GCSkillToTileOK5.h Gpackets/GCSkillToTileOK6.h \
  Gpackets/GCSystemMessage.h Gpackets/GCUnburrowOK.h \
  Gpackets/GCUnburrowFail.h Gpackets/GCUntransformOK.h \
  Gpackets/GCUntransformFail.h Gpackets/GCTeachSkillInfo.h \
  Gpackets/GCUpdateInfo.h RideMotorcycleInfo.h RideMotorcycleSlotInfo.h \
  NPCInfo.h Gpackets/GCUseBonusPointFail.h Gpackets/GCUseBonusPointOK.h \
  Gpackets/GCUseOK.h Gpackets/GCTakeOff.h Gpackets/GCThrowItemOK1.h \
  Gpackets/GCThrowItemOK2.h Gpackets/GCThrowItemOK3.h \
  Gpackets/GCVisibleOK.h Gpackets/GCVisibleFail.h Gpackets/GCNPCInfo.h \
  Gpackets/GCNPCAskVariable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ScriptParameter.h Gpackets/GCWarScheduleList.h Gpackets/GCWarList.h \
  GuildWarInfo.h PacketFactory.h WarInfo.h ValueList.h types/WarTypes.h \
  RaceWarInfo.h Gpackets/GMServerInfo.h DatagramPacket.h Datagram.h \
  SocketAPI.h Gpackets/GLIncomingConnection.h \
  Gpackets/GLIncomingConnectionError.h Gpackets/GLIncomingConnectionOK.h \
  Gpackets/GLKickVerify.h Lpackets/LCCreatePCError.h Packet.h \
  PacketFactory.h Lpackets/LCCreatePCOK.h Lpackets/LCDeletePCError.h \
  Lpackets/LCDeletePCOK.h Lpackets/LCLoginError.h Lpackets/LCLoginOK.h \
  Lpackets/LCPCList.h PCInfo.h PCSlayerInfo.h PCVampireInfo.h \
  PCOustersInfo.h Lpackets/LCQueryResultPlayerID.h \
  Lpackets/LCQueryResultCharacterName.h Lpackets/LCReconnect.h \
  Lpackets/LCRegisterPlayerError.h Lpackets/LCRegisterPlayerOK.h \
  Lpackets/LCSelectPCError.h Lpackets/LGIncomingConnection.h \
  DatagramPacket.h Lpackets/LGIncomingConnectionOK.h \
  Lpackets/LGIncomingConnectionError.h Lpackets/LGKickCharacter.h \
  Lpackets/LCVersionCheckOK.h Lpackets/LCVersionCheckError.h \
  Lpackets/LCServerList.h ServerGroupInfo.h Lpackets/LCWorldList.h \
  WorldInfo.h Cpackets/CGWhisper.h Gpackets/GCWhisper.h \
  Gpackets/GCWhisperFailed.h Gpackets/GCSkillInfo.h PCSkillInfo.h \
  SlayerSkillInfo.h PCSkillInfo.h SubSlayerSkillInfo.h VampireSkillInfo.h \
  SubVampireSkillInfo.h Gpackets/GCStatusCurrentHP.h \
  Cpackets/CGSetSlayerHotKey.h Cpackets/CGSetVampireHotKey.h \
  Cpackets/CGSelectPortal.h Cpackets/CGMouseToStash.h \
  Cpackets/CGStashToMouse.h Cpackets/CGStashList.h Gpackets/GCStashList.h \
  Cpackets/CGStashDeposit.h Cpackets/CGStashWithdraw.h \
  Cpackets/CGStashRequestBuy.h Gpackets/GCStashSell.h \
  Cpackets/CGTradePrepare.h Cpackets/CGTradeAddItem.h \
  Cpackets/CGTradeRemoveItem.h Cpackets/CGTradeMoney.h \
  Cpackets/CGTradeFinish.h Gpackets/GCTradePrepare.h \
  Gpackets/GCTradeAddItem.h Gpackets/GCTradeRemoveItem.h \
  Gpackets/GCTradeMoney.h Gpackets/GCTradeFinish.h \
  Gpackets/GCTradeError.h Gpackets/GCTradeVerify.h \
  Cpackets/CGSkillToObject.h Cpackets/CGSkillToSelf.h \
  Cpackets/CGSkillToTile.h Cpackets/CGSilverCoating.h \
  Gpackets/GCNPCResponse.h Gpackets/GCNPCSayDynamic.h \
  Gpackets/GCNPCAskDynamic.h Cpackets/CGUseItemFromInventory.h \
  Cpackets/CGSelectWayPoint.h Gpackets/GCAddHelicopter.h \
  Gpackets/GCAddVampirePortal.h Gpackets/GCEnterVampirePortal.h \
  Cpackets/CGSelectTileEffect.h Cpackets/CGPartyInvite.h \
  Cpackets/CGPartyLeave.h Gpackets/GCPartyInvite.h \
  Gpackets/GCPartyLeave.h Gpackets/GCPartyJoined.h \
  Gpackets/GCPartyError.h Cpackets/CGResurrect.h Cpackets/CGRequestIP.h \
  Gpackets/GCRequestedIP.h Gpackets/GCRequestFailed.h \
  Gpackets/GCOtherModifyInfo.h Gpackets/GGCommand.h \
  Cpackets/CGRegistGuild.h Gpackets/GCWaitGuildList.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  GuildInfo.h Gpackets/GCShowWaitGuildInfo.h Gpackets/GCShowGuildInfo.h \
  Cpackets/CGSelectGuild.h Cpackets/CGTryJoinGuild.h \
  Gpackets/GCShowGuildJoin.h Cpackets/CGJoinGuild.h \
  Gpackets/GCShowMessageBox.h Cpackets/CGRequestGuildMemberList.h \
  Cpackets/CGSelectGuildMember.h Cpackets/CGModifyGuildMember.h \
  Gpackets/GCActiveGuildList.h Gpackets/GCShowGuildMemberInfo.h \
  Gpackets/GCGuildMemberList.h GuildMemberInfo.h \
  Gpackets/GCModifyGuildMemberInfo.h Gpackets/GSAddGuild.h \
  Gpackets/GSAddGuildMember.h Gpackets/GSQuitGuild.h \
  Gpackets/GSExpelGuildMember.h Gpackets/GSModifyGuildMember.h \
  Spackets/SGAddGuildOK.h Packet.h PacketFactory.h \
  Spackets/SGAddGuildMemberOK.h Spackets/SGQuitGuildOK.h \
  Spackets/SGExpelGuildMemberOK.h Spackets/SGModifyGuildMemberOK.h \
  Spackets/SGDeleteGuildOK.h Spackets/SGModifyGuildOK.h \
  Cpackets/CGRelicToObject.h Cpackets/CGPortCheck.h DatagramPacket.h \
  Cpackets/CGGuildChat.h Gpackets/GCGuildChat.h Gpackets/GGGuildChat.h \
  Gpackets/GSRequestGuildInfo.h Spackets/SGGuildInfo.h GuildInfo2.h \
  GuildMemberInfo2.h GuildMemberInfo2.h Cpackets/CGAddItemToItem.h \
  Gpackets/GCAddItemToItemVerify.h Cpackets/CGRequestInfo.h \
  Gpackets/GCNoticeEvent.h Utility.h Cpackets/CGModifyGuildIntro.h \
  Cpackets/CGModifyGuildMemberIntro.h Gpackets/GSModifyGuildIntro.h \
  Spackets/SGModifyGuildIntroOK.h Gpackets/GSGuildMemberLogOn.h \
  Spackets/SGGuildMemberLogOnOK.h Cpackets/CGSelectRankBonus.h \
  Gpackets/GCSelectRankBonusOK.h Gpackets/GCSelectRankBonusFailed.h \
  Gpackets/GCRankBonusInfo.h Cpackets/CGSkillToNamed.h \
  Cpackets/CGUseMessageItemFromInventory.h \
  Cpackets/CGUseItemFromInventory.h Gpackets/GCHolyLandBonusInfo.h \
  BloodBibleBonusInfo.h Gpackets/GCBloodBibleStatus.h \
  Gpackets/GCKickMessage.h Gpackets/GCTimeLimitItemInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tree.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_map.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_multimap.h \
  Gpackets/GCSelectQuestID.h Cpackets/CGSelectQuest.h \
  Gpackets/GCQuestStatus.h Gpackets/GCMonsterKillQuestInfo.h \
  Gpackets/GCSelectQuestID.h Cpackets/CGLotterySelect.h \
  Gpackets/GCNotifyWin.h Gpackets/GCGoodsList.h Cpackets/CGTakeOutGood.h \
  Gpackets/GCTakeOutOK.h Gpackets/GCTakeOutFail.h Gpackets/GCAddOusters.h \
  PCOustersInfo3.h Cpackets/CGMixItem.h Assert.h \
  Gpackets/GCAddOustersCorpse.h Cpackets/CGAbsorbSoul.h \
  Cpackets/CGDownSkill.h Gpackets/GCDownSkillOK.h \
  Gpackets/GCDownSkillFailed.h Gpackets/GCMiniGameScores.h \
  Cpackets/CGSubmitScore.h Cpackets/CGFailQuest.h \
  Cpackets/CGAddItemToCodeSheet.h Gpackets/GCFlagWarStatus.h \
  Gpackets/GCOtherGuildName.h Gpackets/GCSweeperBonusInfo.h \
  SweeperBonusInfo.h Cpackets/CGSelectRegenZone.h \
  Gpackets/GCRegenZoneStatus.h Gpackets/GCPetInfo.h \
  Cpackets/CGTameMonster.h Cpackets/CGPetGamble.h \
  Cpackets/CGCrashReport.h Gpackets/GCPetUseSkill.h \
  Gpackets/GCSystemAvailabilities.h Gpackets/GCPartyPosition.h \
  Cpackets/CGPartyPosition.h Gpackets/GCPartySay.h Cpackets/CGPartySay.h \
  Gpackets/GGServerChat.h Gpackets/GCPetStashList.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/numeric \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_numeric.h \
  Cpackets/CGWithdrawPet.h Cpackets/CGDepositPet.h \
  Gpackets/GCPetStashVerify.h
PacketIDSet.o: PacketIDSet.cpp PacketIDSet.h Packet.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PlayerStatus.h Assert.h
PacketValidator.o: PacketValidator.cpp PacketValidator.h PacketIDSet.h \
  Packet.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PlayerStatus.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc
PacketFactoryManager.o: PacketFactoryManager.cpp Assert.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  PacketFactoryManager.h Packet.h SocketInputStream.h Socket.h \
  SocketImpl.h SocketAPI.h SocketOutputStream.h PacketFactory.h \
  Cpackets/CGAttack.h Types.h Exception.h Packet.h PacketFactory.h \
  Cpackets/CGAddGearToMouse.h Cpackets/CGAddInventoryToMouse.h \
  Cpackets/CGAddMouseToGear.h Cpackets/CGAddMouseToInventory.h \
  Cpackets/CGAddMouseToQuickSlot.h Cpackets/CGAddMouseToZone.h \
  Cpackets/CGAddQuickSlotToMouse.h Cpackets/CGAddZoneToMouse.h \
  Cpackets/CGAddZoneToInventory.h Cpackets/CGBloodDrain.h \
  Cpackets/CGUnburrow.h Cpackets/CGUntransform.h \
  Cpackets/CGCastingSkill.h Cpackets/CGConnect.h \
  Cpackets/CGDissectionCorpse.h Cpackets/CGDropMoney.h \
  Cpackets/CGGetOffMotorCycle.h Cpackets/CGGlobalChat.h \
  Cpackets/CGLearnSkill.h Cpackets/CGLogout.h Cpackets/CGMakeItem.h \
  Cpackets/CGMove.h Cpackets/CGNPCAskAnswer.h Cpackets/CGNPCTalk.h \
  Cpackets/CGPickupMoney.h Cpackets/CGReady.h \
  Cpackets/CGReloadFromInventory.h Cpackets/CGReloadFromQuickSlot.h \
  Cpackets/CGRideMotorCycle.h Cpackets/CGSay.h \
  Cpackets/CGShopRequestBuy.h Cpackets/CGShopRequestList.h \
  Cpackets/CGShopRequestSell.h Cpackets/CGSkillToInventory.h \
  Cpackets/CGThrowBomb.h Gpackets/GCThrowBombOK1.h Types.h Exception.h \
  ModifyInfo.h Types.h Exception.h Packet.h PacketFactory.h \
  Gpackets/GCThrowBombOK2.h Gpackets/GCThrowBombOK3.h Packet.h \
  Cpackets/CGThrowItem.h Cpackets/CGUseBonusPoint.h \
  Cpackets/CGUsePotionFromInventory.h Cpackets/CGUsePotionFromQuickSlot.h \
  Cpackets/CGRequestRepair.h Cpackets/CGVisible.h Cpackets/CGVerifyTime.h \
  Cpackets/CGRequestNewbieItem.h Cpackets/CGWithdrawTax.h \
  Cpackets/CGTypeStringList.h Cpackets/CGUseItemFromGear.h \
  Cpackets/CLCreatePC.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  Cpackets/CLDeletePC.h Cpackets/CLGetPCList.h Cpackets/CLLogin.h \
  Cpackets/CLLogout.h Cpackets/CLQueryPlayerID.h \
  Cpackets/CLQueryCharacterName.h Cpackets/CLRegisterPlayer.h \
  Cpackets/CLSelectPC.h Player.h Cpackets/CLVersionCheck.h \
  Cpackets/CLGetServerList.h Cpackets/CLChangeServer.h \
  Cpackets/CLReconnectLogin.h Cpackets/CLGetWorldList.h \
  Cpackets/CLSelectWorld.h Cpackets/CLSelectServer.h Gpackets/GCAddBat.h \
  Gpackets/GCAddBurrowingCreature.h Gpackets/GCAddEffect.h \
  Gpackets/GCAddEffectToTile.h Gpackets/GCAddGearToInventory.h \
  Gpackets/GCAddGearToZone.h Gpackets/GCAddInstalledMineToZone.h \
  SubItemInfo.h SocketInputStream.h SocketOutputStream.h \
  Gpackets/GCAddItemToZone.h Gpackets/GCAddMonster.h EffectInfo.h \
  Gpackets/GCAddMonsterCorpse.h Gpackets/GCAddMonsterFromBurrowing.h \
  Gpackets/GCAddMonsterFromTransformation.h Gpackets/GCAddNewItemToZone.h \
  Gpackets/GCAddNPC.h Gpackets/GCAddSlayer.h PCSlayerInfo3.h PCInfo.h \
  Assert.h PetInfo.h types/PetTypes.h types/SystemTypes.h VSDateTime.h \
  Gpackets/GCAddSlayerCorpse.h Gpackets/GCAddVampire.h PCVampireInfo3.h \
  Gpackets/GCAddVampireCorpse.h Gpackets/GCAddVampireFromBurrowing.h \
  Gpackets/GCAddVampireFromTransformation.h Gpackets/GCAddWolf.h \
  Gpackets/GCAddInjuriousCreature.h Gpackets/GCAttackArmsOK1.h \
  Gpackets/GCAttackArmsOK2.h Gpackets/GCAttackArmsOK3.h \
  Gpackets/GCAttackArmsOK4.h Gpackets/GCAttackArmsOK5.h \
  Gpackets/GCAttackMeleeOK1.h Gpackets/GCAttackMeleeOK2.h \
  Gpackets/GCAttackMeleeOK3.h Gpackets/GCAttack.h \
  Gpackets/GCBloodDrainOK1.h Gpackets/GCBloodDrainOK2.h \
  Gpackets/GCBloodDrainOK3.h Gpackets/GCCannotAdd.h \
  Gpackets/GCCannotUse.h Gpackets/GCCastingSkill.h \
  Gpackets/GCCreateItem.h Gpackets/GCCreatureDied.h \
  Gpackets/GCChangeShape.h Gpackets/GCChangeDarkLight.h \
  Gpackets/GCChangeWeather.h Gpackets/GCCrossCounterOK1.h \
  Gpackets/GCCrossCounterOK2.h Gpackets/GCCrossCounterOK3.h \
  Gpackets/GCDeleteInventoryItem.h Gpackets/GCDeleteObject.h \
  Gpackets/GCRemoveCorpseHead.h Gpackets/GCRemoveInjuriousCreature.h \
  Gpackets/GCDeleteandPickUpOK.h Gpackets/GCDeleteEffectFromTile.h \
  Gpackets/GCDisconnect.h Gpackets/GCDropItemToZone.h \
  Gpackets/GCFastMove.h Gpackets/GCFakeMove.h Gpackets/GCGetDamage.h \
  Gpackets/GCGetOffMotorCycle.h Gpackets/GCGetOffMotorCycleFailed.h \
  Gpackets/GCGetOffMotorCycleOK.h Gpackets/GCGlobalChat.h \
  Gpackets/GCHPRecoveryStartToSelf.h Gpackets/GCHPRecoveryStartToOthers.h \
  Gpackets/GCHPRecoveryEndToSelf.h Gpackets/GCHPRecoveryEndToOthers.h \
  Gpackets/GCKnockBack.h Gpackets/GCKnocksTargetBackOK1.h \
  ModifyItemInfo.h ModifyInfo.h Gpackets/GCKnocksTargetBackOK2.h \
  Gpackets/GCKnocksTargetBackOK4.h Gpackets/GCKnocksTargetBackOK5.h \
  Gpackets/GCLearnSkillFailed.h Gpackets/GCLearnSkillOK.h \
  Gpackets/GCLearnSkillReady.h Gpackets/GCLightning.h \
  Gpackets/GCMakeItemOK.h Gpackets/GCChangeInventoryItemNum.h \
  Gpackets/GCAddItemToInventory.h Gpackets/GCMakeItemFail.h \
  Gpackets/GCMineExplosionOK1.h Gpackets/GCMineExplosionOK2.h \
  Gpackets/GCModifyInformation.h Gpackets/GCMorph1.h GameTime.h \
  PCSlayerInfo2.h PCVampireInfo2.h InventoryInfo.h InventorySlotInfo.h \
  PCItemInfo.h SubItemInfo.h GearInfo.h GearSlotInfo.h ExtraInfo.h \
  ExtraSlotInfo.h Assert.h Gpackets/GCMorphSlayer2.h \
  Gpackets/GCMorphVampire2.h Gpackets/GCMove.h Gpackets/GCMoveOK.h \
  Gpackets/GCMoveError.h Gpackets/GCMPRecoveryStart.h \
  Gpackets/GCMPRecoveryEnd.h Gpackets/GCNPCAsk.h Gpackets/GCNPCSay.h \
  Gpackets/GCRealWearingInfo.h Gpackets/GCReconnect.h \
  Gpackets/GCReconnectLogin.h Gpackets/GCRemoveEffect.h \
  Gpackets/GCRemoveFromGear.h Gpackets/GCRideMotorCycle.h \
  Gpackets/GCRideMotorCycleFailed.h Gpackets/GCRideMotorCycleOK.h \
  Gpackets/GCReloadOK.h Gpackets/GCSay.h Gpackets/GCSearchMotorcycleOK.h \
  Gpackets/GCSearchMotorcycleFail.h Gpackets/GCSetPosition.h \
  Gpackets/GCShopBuyOK.h Gpackets/GCShopBuyFail.h Gpackets/GCShopList.h \
  Gpackets/GCShopListMysterious.h Gpackets/GCShopSold.h \
  Gpackets/GCShopVersion.h Gpackets/GCShopBought.h \
  Gpackets/GCShopSellOK.h Gpackets/GCShopSellFail.h \
  Gpackets/GCShopMarketCondition.h Gpackets/GCSkillFailed1.h \
  Gpackets/GCSkillFailed2.h Gpackets/GCSkillToInventoryOK1.h \
  Gpackets/GCSkillToInventoryOK2.h Gpackets/GCSkillToObjectOK1.h \
  Gpackets/GCSkillToObjectOK2.h Gpackets/GCSkillToObjectOK3.h \
  Gpackets/GCSkillToObjectOK4.h Gpackets/GCSkillToObjectOK5.h \
  Gpackets/GCSkillToObjectOK6.h Gpackets/GCSkillToSelfOK1.h \
  Gpackets/GCSkillToSelfOK2.h Gpackets/GCSkillToSelfOK3.h \
  Gpackets/GCSkillToTileOK1.h Gpackets/GCSkillToTileOK2.h \
  Gpackets/GCSkillToTileOK3.h Gpackets/GCSkillToTileOK4.h \
  Gpackets/GCSkillToTileOK5.h Gpackets/GCSkillToTileOK6.h \
  Gpackets/GCSystemMessage.h Gpackets/GCUnburrowOK.h \
  Gpackets/GCUnburrowFail.h Gpackets/GCUntransformOK.h \
  Gpackets/GCUntransformFail.h Gpackets/GCTeachSkillInfo.h \
  Gpackets/GCUpdateInfo.h RideMotorcycleInfo.h RideMotorcycleSlotInfo.h \
  NPCInfo.h Gpackets/GCUseBonusPointFail.h Gpackets/GCUseBonusPointOK.h \
  Gpackets/GCUseOK.h Gpackets/GCTakeOff.h Gpackets/GCThrowItemOK1.h \
  Gpackets/GCThrowItemOK2.h Gpackets/GCThrowItemOK3.h \
  Gpackets/GCVisibleOK.h Gpackets/GCVisibleFail.h Gpackets/GCNPCInfo.h \
  Gpackets/GCNPCAskVariable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ScriptParameter.h Gpackets/GCWarScheduleList.h Gpackets/GCWarList.h \
  GuildWarInfo.h PacketFactory.h WarInfo.h ValueList.h types/WarTypes.h \
  RaceWarInfo.h Gpackets/GMServerInfo.h DatagramPacket.h Datagram.h \
  SocketAPI.h Gpackets/GLIncomingConnection.h \
  Gpackets/GLIncomingConnectionError.h Gpackets/GLIncomingConnectionOK.h \
  Gpackets/GLKickVerify.h Lpackets/LCCreatePCError.h Packet.h \
  PacketFactory.h Lpackets/LCCreatePCOK.h Lpackets/LCDeletePCError.h \
  Lpackets/LCDeletePCOK.h Lpackets/LCLoginError.h Lpackets/LCLoginOK.h \
  Lpackets/LCPCList.h PCInfo.h PCSlayerInfo.h PCVampireInfo.h \
  PCOustersInfo.h Lpackets/LCQueryResultPlayerID.h \
  Lpackets/LCQueryResultCharacterName.h Lpackets/LCReconnect.h \
  Lpackets/LCRegisterPlayerError.h Lpackets/LCRegisterPlayerOK.h \
  Lpackets/LCSelectPCError.h Lpackets/LGIncomingConnection.h \
  DatagramPacket.h Lpackets/LGIncomingConnectionOK.h \
  Lpackets/LGIncomingConnectionError.h Lpackets/LGKickCharacter.h \
  Lpackets/LCVersionCheckOK.h Lpackets/LCVersionCheckError.h \
  Lpackets/LCServerList.h ServerGroupInfo.h Lpackets/LCWorldList.h \
  WorldInfo.h Cpackets/CGWhisper.h Gpackets/GCWhisper.h \
  Gpackets/GCWhisperFailed.h Gpackets/GCSkillInfo.h PCSkillInfo.h \
  SlayerSkillInfo.h PCSkillInfo.h SubSlayerSkillInfo.h VampireSkillInfo.h \
  SubVampireSkillInfo.h Gpackets/GCStatusCurrentHP.h \
  Cpackets/CGSetSlayerHotKey.h Cpackets/CGSetVampireHotKey.h \
  Cpackets/CGSelectPortal.h Cpackets/CGMouseToStash.h \
  Cpackets/CGStashToMouse.h Cpackets/CGStashList.h Gpackets/GCStashList.h \
  Cpackets/CGStashDeposit.h Cpackets/CGStashWithdraw.h \
  Cpackets/CGStashRequestBuy.h Gpackets/GCStashSell.h \
  Cpackets/CGTradePrepare.h Cpackets/CGTradeAddItem.h \
  Cpackets/CGTradeRemoveItem.h Cpackets/CGTradeMoney.h \
  Cpackets/CGTradeFinish.h Gpackets/GCTradePrepare.h \
  Gpackets/GCTradeAddItem.h Gpackets/GCTradeRemoveItem.h \
  Gpackets/GCTradeMoney.h Gpackets/GCTradeFinish.h \
  Gpackets/GCTradeError.h Gpackets/GCTradeVerify.h \
  Cpackets/CGSkillToObject.h Cpackets/CGSkillToSelf.h \
  Cpackets/CGSkillToTile.h Cpackets/CGSilverCoating.h \
  Gpackets/GCNPCResponse.h Gpackets/GCNPCSayDynamic.h \
  Gpackets/GCNPCAskDynamic.h Cpackets/CGUseItemFromInventory.h \
  Cpackets/CGSelectWayPoint.h Gpackets/GCAddHelicopter.h \
  Gpackets/GCAddVampirePortal.h Gpackets/GCEnterVampirePortal.h \
  Cpackets/CGSelectTileEffect.h Cpackets/CGPartyInvite.h \
  Cpackets/CGPartyLeave.h Gpackets/GCPartyInvite.h \
  Gpackets/GCPartyLeave.h Gpackets/GCPartyJoined.h \
  Gpackets/GCPartyError.h Cpackets/CGResurrect.h Cpackets/CGRequestIP.h \
  Gpackets/GCRequestedIP.h Gpackets/GCRequestFailed.h \
  Gpackets/GCOtherModifyInfo.h Gpackets/GGCommand.h \
  Cpackets/CGRegistGuild.h Gpackets/GCWaitGuildList.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  GuildInfo.h Gpackets/GCShowWaitGuildInfo.h Gpackets/GCShowGuildInfo.h \
  Cpackets/CGSelectGuild.h Cpackets/CGTryJoinGuild.h \
  Gpackets/GCShowGuildJoin.h Cpackets/CGJoinGuild.h \
  Gpackets/GCShowMessageBox.h Cpackets/CGRequestGuildMemberList.h \
  Cpackets/CGSelectGuildMember.h Cpackets/CGModifyGuildMember.h \
  Gpackets/GCActiveGuildList.h Gpackets/GCShowGuildMemberInfo.h \
  Gpackets/GCGuildMemberList.h GuildMemberInfo.h \
  Gpackets/GCModifyGuildMemberInfo.h Gpackets/GSAddGuild.h \
  Gpackets/GSAddGuildMember.h Gpackets/GSQuitGuild.h \
  Gpackets/GSExpelGuildMember.h Gpackets/GSModifyGuildMember.h \
  Spackets/SGAddGuildOK.h Packet.h PacketFactory.h \
  Spackets/SGAddGuildMemberOK.h Spackets/SGQuitGuildOK.h \
  Spackets/SGExpelGuildMemberOK.h Spackets/SGModifyGuildMemberOK.h \
  Spackets/SGDeleteGuildOK.h Spackets/SGModifyGuildOK.h \
  Cpackets/CGRelicToObject.h Cpackets/CGPortCheck.h DatagramPacket.h \
  Cpackets/CGGuildChat.h Gpackets/GCGuildChat.h Gpackets/GGGuildChat.h \
  Gpackets/GSRequestGuildInfo.h Spackets/SGGuildInfo.h GuildInfo2.h \
  GuildMemberInfo2.h GuildMemberInfo2.h Cpackets/CGAddItemToItem.h \
  Gpackets/GCAddItemToItemVerify.h Cpackets/CGRequestInfo.h \
  Gpackets/GCNoticeEvent.h Utility.h Cpackets/CGModifyGuildIntro.h \
  Cpackets/CGModifyGuildMemberIntro.h Gpackets/GSModifyGuildIntro.h \
  Spackets/SGModifyGuildIntroOK.h Gpackets/GSGuildMemberLogOn.h \
  Spackets/SGGuildMemberLogOnOK.h Cpackets/CGSelectRankBonus.h \
  Gpackets/GCSelectRankBonusOK.h Gpackets/GCSelectRankBonusFailed.h \
  Gpackets/GCRankBonusInfo.h Cpackets/CGSkillToNamed.h \
  Cpackets/CGUseMessageItemFromInventory.h \
  Cpackets/CGUseItemFromInventory.h Gpackets/GCHolyLandBonusInfo.h \
  BloodBibleBonusInfo.h Gpackets/GCBloodBibleStatus.h \
  Gpackets/GCKickMessage.h Gpackets/GCTimeLimitItemInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tree.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_map.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_multimap.h \
  Gpackets/GCSelectQuestID.h Cpackets/CGSelectQuest.h \
  Gpackets/GCQuestStatus.h Gpackets/GCMonsterKillQuestInfo.h \
  Gpackets/GCSelectQuestID.h Cpackets/CGLotterySelect.h \
  Gpackets/GCNotifyWin.h Gpackets/GCGoodsList.h Cpackets/CGTakeOutGood.h \
  Gpackets/GCTakeOutOK.h Gpackets/GCTakeOutFail.h Gpackets/GCAddOusters.h \
  PCOustersInfo3.h Cpackets/CGMixItem.h Assert.h \
  Gpackets/GCAddOustersCorpse.h Cpackets/CGAbsorbSoul.h \
  Cpackets/CGDownSkill.h Gpackets/GCDownSkillOK.h \
  Gpackets/GCDownSkillFailed.h Gpackets/GCMiniGameScores.h \
  Cpackets/CGSubmitScore.h Cpackets/CGFailQuest.h \
  Cpackets/CGAddItemToCodeSheet.h Gpackets/GCFlagWarStatus.h \
  Gpackets/GCOtherGuildName.h Gpackets/GCSweeperBonusInfo.h \
  SweeperBonusInfo.h Cpackets/CGSelectRegenZone.h \
  Gpackets/GCRegenZoneStatus.h Gpackets/GCPetInfo.h \
  Cpackets/CGTameMonster.h Cpackets/CGPetGamble.h \
  Cpackets/CGCrashReport.h Gpackets/GCPetUseSkill.h \
  Gpackets/GCSystemAvailabilities.h Gpackets/GCPartyPosition.h \
  Cpackets/CGPartyPosition.h Gpackets/GCPartySay.h Cpackets/CGPartySay.h \
  Gpackets/GGServerChat.h Gpackets/GCPetStashList.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/numeric \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_numeric.h \
  Cpackets/CGWithdrawPet.h Cpackets/CGDepositPet.h \
  Gpackets/GCPetStashVerify.h
PacketIDSet.o: PacketIDSet.cpp PacketIDSet.h Packet.h Types.h \
  types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PlayerStatus.h Assert.h
PacketValidator.o: PacketValidator.cpp PacketValidator.h PacketIDSet.h \
  Packet.h Types.h types/SystemTypes.h \
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
  types/PlayerTypes.h types/SystemTypes.h types/ObjectTypes.h \
  types/CreatureTypes.h types/ItemTypes.h types/ZoneTypes.h \
  types/QuestTypes.h types/ShopTypes.h types/ItemTypes.h \
  types/GuildTypes.h types/WarTypes.h types/ServerType.h Utility.h \
  Exception.h StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  SocketInputStream.h Socket.h SocketImpl.h SocketAPI.h \
  SocketOutputStream.h PlayerStatus.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc
