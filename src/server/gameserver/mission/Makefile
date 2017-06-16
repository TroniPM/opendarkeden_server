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
VSHOME   = ../../../..
STLDIR   = /usr/include/STL
BINDIR   = $(VSHOME)/bin
LIBDIR   = $(VSHOME)/lib
LOGDIR   = $(VSHOME)/log
SRCDIR   = ../../..
COREDIR  = ../../../Core
SERVDIR  = ../..
DBDIR    = ../../database
GSDIR    = ..
MYSQLDIR = /usr/lib/mysql


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__GAME_SERVER__
INCLUDES = -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I.
CCFLAGS  = -Wall -c -g 
#CCFLAGS  = -Wall -c

.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------

OBJS = \
	QuestInfo.o \
	MonsterKillQuestInfo.o \
	GatherItemQuestInfo.o \
	MeetNPCQuestInfo.o \
	RewardClass.o \
	RandomRewardClass.o \
	SlayerWeaponRewardClass.o \
	AnotherQuestRewardClass.o \
	RewardInfo.o \
	ItemRewardInfo.o \
	QuestAdvanceRewardInfo.o \
	AnotherQuestRewardInfo.o \
	MiniGameQuestInfo.o \
	QuestInfoManager.o \
	SimpleQuestInfoManager.o \
	EventQuestInfoManager.o \
	RewardClassInfoManager.o \
	SimpleQuestRewardManager.o \
	QuestManager.o \
	QuestStatus.o \
	MonsterKillQuestStatus.o \
	GatherItemQuestStatus.o \
	DummyQuestStatus.o \
	MeetNPCQuestStatus.o \
	MiniGameQuestStatus.o \
	EventQuestAdvance.o \
	EventQuestLootingManager.o

SRCS = $(OBJS:.o=.cpp)

TARGET = $(LIBDIR)/libMission.a

#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
all : $(TARGET)

$(TARGET) : $(OBJS)
	ar rc $@ $^

clean :
	rm -rf *.o

cleanall :
	rm -rf *.o $(TARGET)

depall :
	gccmakedep $(SRCS) $(INCLUDES)

dep :
	gccmakedep $(SRCS) $(INCLUDES)
# DO NOT DELETE
QuestInfo.o: QuestInfo.cpp QuestInfo.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/Assert.h ../../../Core/Exception.h RewardClass.h \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/SocketInputStream.h ../../../Core/Socket.h \
  ../../../Core/SocketImpl.h ../../../Core/SocketAPI.h \
  ../../../Core/SocketOutputStream.h ../../../Core/PacketFactory.h \
  ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  QuestManager.h QuestStatus.h ../../../Core/VSDateTime.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  EventQuestAdvance.h ../PlayerCreature.h ../Creature.h ../Object.h \
  ../../../Core/Types.h ../../../Core/Exception.h ../../../Core/Assert.h \
  ../EffectManager.h ../Effect.h ../../Timeval.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../../../Core/EffectInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  ../ObjectRegistry.h ../../Mutex.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../InventorySlot.h ../Item.h ../Garbage.h \
  ../RankBonus.h ../ExpFwd.h \
  ../../../Core/Gpackets/GCMonsterKillQuestInfo.h \
  ../../../Core/Gpackets/GCSelectQuestID.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  ../Slayer.h ../PlayerCreature.h ../Zone.h ../Tile.h ../Obstacle.h \
  ../Portal.h ../quest/TriggerManager.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../quest/Trigger.h ../quest/Condition.h \
  ../quest/PropertyBuffer.h ../Sector.h ../Party.h \
  ../../../Core/ModifyInfo.h ../PCManager.h ../CreatureManager.h \
  ../../../Core/Encrypter.h ../../../Core/EncryptUtility.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/queue \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/deque \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_deque.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/deque.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_queue.h \
  ../Inventory.h ../VolumeInfo.h ../../../Core/PCSlayerInfo.h \
  ../../../Core/PCInfo.h ../../../Core/PCSlayerInfo2.h \
  ../../../Core/PCSlayerInfo3.h ../../../Core/Assert.h \
  ../../../Core/InventoryInfo.h ../../../Core/InventorySlotInfo.h \
  ../../../Core/PCItemInfo.h ../../../Core/SubItemInfo.h \
  ../ItemLoaderManager.h ../ItemLoader.h ../../../Core/GearInfo.h \
  ../../../Core/GearSlotInfo.h ../../../Core/ExtraInfo.h \
  ../../../Core/ExtraSlotInfo.h ../OptionInfo.h \
  ../../../Core/RideMotorcycleInfo.h \
  ../../../Core/RideMotorcycleSlotInfo.h ../../../Core/SlayerSkillInfo.h \
  ../../../Core/PCSkillInfo.h ../../../Core/SubSlayerSkillInfo.h \
  ../CreatureUtil.h ../SlayerAttrExpTable.h ../SomethingGrowingUp.h \
  ../../database/DB.h ../../database/DatabaseManager.h \
  ../../../Core/Types.h ../../../Core/Exception.h \
  ../../database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h \
  ../../Mutex.h ../../database/Statement.h ../../database/Result.h \
  ../skill/Skill.h ../../../Core/Types.h ../skill/SkillSlot.h \
  ../../Timeval.h ../skill/Skill.h ../../../Core/Exception.h \
  ../../../Core/Gpackets/GCModifyInformation.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../../Core/ModifyInfo.h ../Vampire.h \
  ../../../Core/PCVampireInfo.h ../../../Core/PCVampireInfo2.h \
  ../../../Core/PCVampireInfo3.h ../../../Core/VampireSkillInfo.h \
  ../../../Core/SubVampireSkillInfo.h ../skill/VampireSkillSlot.h \
  ../Ousters.h ../../../Core/PCOustersInfo.h \
  ../../../Core/PCOustersInfo2.h ../../../Core/PCOustersInfo3.h \
  ../../../Core/OustersSkillInfo.h ../../../Core/SubOustersSkillInfo.h \
  ../skill/OustersSkillSlot.h ../../../Core/StringStream.h
MonsterKillQuestInfo.o: MonsterKillQuestInfo.cpp MonsterKillQuestInfo.h \
  ../../../Core/Types.h ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  QuestInfo.h ../../../Core/Assert.h ../../../Core/Exception.h \
  RewardClass.h ../../../Core/Gpackets/GCNPCResponse.h \
  ../../../Core/Packet.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  MonsterKillQuestStatus.h QuestStatus.h ../../../Core/VSDateTime.h \
  ../../../Core/Gpackets/GCQuestStatus.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../database/DB.h \
  ../../database/DatabaseManager.h ../../../Core/Types.h \
  ../../../Core/Exception.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../../database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h \
  ../../Mutex.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../database/Statement.h ../../database/Result.h \
  /usr/include/sys/time.h /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../../../Core/StringStream.h
GatherItemQuestInfo.o: GatherItemQuestInfo.cpp GatherItemQuestStatus.h \
  QuestStatus.h ../../../Core/Types.h ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/VSDateTime.h ../../../Core/Assert.h \
  ../../../Core/Exception.h QuestInfo.h RewardClass.h \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/SocketInputStream.h ../../../Core/Socket.h \
  ../../../Core/SocketImpl.h ../../../Core/SocketAPI.h \
  ../../../Core/SocketOutputStream.h ../../../Core/PacketFactory.h \
  ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  ../Item.h ../Object.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/Assert.h ../Effect.h ../../Timeval.h \
  /usr/include/sys/time.h /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../EffectManager.h ../../../Core/EffectInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  ../../../Core/Gpackets/GCQuestStatus.h ../../../Core/Types.h \
  ../../../Core/Exception.h GatherItemQuestInfo.h ../PlayerCreature.h \
  ../Creature.h ../ObjectRegistry.h ../../Mutex.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../InventorySlot.h ../Item.h ../Garbage.h \
  ../RankBonus.h ../ExpFwd.h \
  ../../../Core/Gpackets/GCMonsterKillQuestInfo.h \
  ../../../Core/Gpackets/GCSelectQuestID.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist
MeetNPCQuestInfo.o: MeetNPCQuestInfo.cpp MeetNPCQuestInfo.h \
  ../../../Core/Types.h ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  QuestInfo.h ../../../Core/Assert.h ../../../Core/Exception.h \
  RewardClass.h ../../../Core/Gpackets/GCNPCResponse.h \
  ../../../Core/Packet.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  MeetNPCQuestStatus.h QuestStatus.h ../../../Core/VSDateTime.h \
  ../../../Core/Gpackets/GCQuestStatus.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../database/DB.h \
  ../../database/DatabaseManager.h ../../../Core/Types.h \
  ../../../Core/Exception.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../../database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h \
  ../../Mutex.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../database/Statement.h ../../database/Result.h \
  /usr/include/sys/time.h /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../../../Core/StringStream.h
RewardClass.o: RewardClass.cpp RewardClass.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/Exception.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  RewardInfo.h ../../../Core/Assert.h ../../../Core/StringStream.h
RandomRewardClass.o: RandomRewardClass.cpp RandomRewardClass.h \
  RewardClass.h ../../../Core/Types.h ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/Exception.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  RewardInfo.h ../../../Core/Assert.h
SlayerWeaponRewardClass.o: SlayerWeaponRewardClass.cpp \
  SlayerWeaponRewardClass.h RewardClass.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/Exception.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  ../PlayerCreature.h ../Creature.h ../Object.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../../Core/Assert.h ../EffectManager.h \
  ../Effect.h ../../Timeval.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../../../Core/EffectInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  ../ObjectRegistry.h ../../Mutex.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../InventorySlot.h ../Item.h ../Garbage.h \
  ../RankBonus.h ../ExpFwd.h \
  ../../../Core/Gpackets/GCMonsterKillQuestInfo.h \
  ../../../Core/Gpackets/GCSelectQuestID.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  ../Slayer.h ../PlayerCreature.h ../Zone.h ../Tile.h ../Obstacle.h \
  ../Portal.h ../quest/TriggerManager.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../quest/Trigger.h ../quest/Condition.h \
  ../quest/PropertyBuffer.h ../Sector.h ../Party.h \
  ../../../Core/ModifyInfo.h ../PCManager.h ../CreatureManager.h \
  ../../../Core/Encrypter.h ../../../Core/EncryptUtility.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/queue \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/deque \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_deque.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/deque.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_queue.h \
  ../Inventory.h ../VolumeInfo.h ../../../Core/PCSlayerInfo.h \
  ../../../Core/PCInfo.h ../../../Core/PCSlayerInfo2.h \
  ../../../Core/PCSlayerInfo3.h ../../../Core/Assert.h \
  ../../../Core/InventoryInfo.h ../../../Core/InventorySlotInfo.h \
  ../../../Core/PCItemInfo.h ../../../Core/SubItemInfo.h \
  ../ItemLoaderManager.h ../ItemLoader.h ../../../Core/GearInfo.h \
  ../../../Core/GearSlotInfo.h ../../../Core/ExtraInfo.h \
  ../../../Core/ExtraSlotInfo.h ../OptionInfo.h \
  ../../../Core/RideMotorcycleInfo.h \
  ../../../Core/RideMotorcycleSlotInfo.h ../../../Core/SlayerSkillInfo.h \
  ../../../Core/PCSkillInfo.h ../../../Core/SubSlayerSkillInfo.h \
  ../CreatureUtil.h ../SlayerAttrExpTable.h ../SomethingGrowingUp.h \
  ../../database/DB.h ../../database/DatabaseManager.h \
  ../../../Core/Types.h ../../../Core/Exception.h \
  ../../database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h \
  ../../Mutex.h ../../database/Statement.h ../../database/Result.h \
  ../skill/Skill.h ../../../Core/Types.h ../skill/SkillSlot.h \
  ../../Timeval.h ../skill/Skill.h ../../../Core/Exception.h \
  ../../../Core/Gpackets/GCModifyInformation.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../../Core/ModifyInfo.h ../Ousters.h \
  ../../../Core/PCOustersInfo.h ../../../Core/PCOustersInfo2.h \
  ../../../Core/PCOustersInfo3.h ../../../Core/OustersSkillInfo.h \
  ../../../Core/SubOustersSkillInfo.h ../skill/OustersSkillSlot.h \
  ItemRewardInfo.h ../Item.h RewardInfo.h ../ItemUtil.h
AnotherQuestRewardClass.o: AnotherQuestRewardClass.cpp \
  AnotherQuestRewardClass.h RewardClass.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/Exception.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  RewardInfo.h ../../../Core/Assert.h
RewardInfo.o: RewardInfo.cpp RewardInfo.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/Exception.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  ../../../Core/StringStream.h
ItemRewardInfo.o: ItemRewardInfo.cpp ItemRewardInfo.h \
  ../../../Core/Types.h ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../Item.h ../Object.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/Assert.h ../../../Core/Exception.h ../Effect.h \
  ../../Timeval.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h ../EffectManager.h \
  ../../../Core/EffectInfo.h ../../../Core/Packet.h \
  ../../../Core/SocketInputStream.h ../../../Core/Socket.h \
  ../../../Core/SocketImpl.h ../../../Core/SocketAPI.h \
  ../../../Core/SocketOutputStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  RewardInfo.h ../../../Core/Gpackets/GCNPCResponse.h \
  ../../../Core/Packet.h ../../../Core/PacketFactory.h RewardClass.h \
  ../PlayerCreature.h ../Creature.h ../ObjectRegistry.h ../../Mutex.h \
  ../../../Core/Types.h ../../../Core/Exception.h ../InventorySlot.h \
  ../Item.h ../Garbage.h ../RankBonus.h ../ExpFwd.h \
  ../../../Core/Gpackets/GCMonsterKillQuestInfo.h \
  ../../../Core/Gpackets/GCSelectQuestID.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  ../Inventory.h ../VolumeInfo.h ../ItemInfoManager.h ../ItemInfo.h \
  ../InfoClassManager.h ../ItemFactoryManager.h ../ItemFactory.h \
  ../../../Core/Player.h ../Zone.h ../Tile.h ../Obstacle.h ../Portal.h \
  ../quest/TriggerManager.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../quest/Trigger.h ../quest/Condition.h \
  ../quest/PropertyBuffer.h ../Sector.h ../Party.h \
  ../../../Core/ModifyInfo.h ../PCManager.h ../CreatureManager.h \
  ../../../Core/Encrypter.h ../../../Core/EncryptUtility.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/queue \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/deque \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_deque.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/deque.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_queue.h \
  ../../database/DB.h ../../database/DatabaseManager.h \
  ../../../Core/Types.h ../../../Core/Exception.h \
  ../../database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h \
  ../../Mutex.h ../../database/Statement.h ../../database/Result.h \
  ../ItemUtil.h ../PacketUtil.h ../../../Core/StringStream.h \
  ../../../Core/PetInfo.h ../../../Core/types/PetTypes.h \
  ../../../Core/VSDateTime.h ../item/PetItem.h ../Item.h ../ItemInfo.h \
  ../InfoClassManager.h ../ItemFactory.h ../ItemLoader.h ../../Mutex.h \
  ../../../Core/PetInfo.h ../PetTypeInfo.h ../../../Core/types/PetTypes.h \
  ../../../Core/VSDateTime.h ../../../Core/Gpackets/GCCreateItem.h
QuestAdvanceRewardInfo.o: QuestAdvanceRewardInfo.cpp \
  QuestAdvanceRewardInfo.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../Item.h ../Object.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/Assert.h ../../../Core/Exception.h ../Effect.h \
  ../../Timeval.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h ../EffectManager.h \
  ../../../Core/EffectInfo.h ../../../Core/Packet.h \
  ../../../Core/SocketInputStream.h ../../../Core/Socket.h \
  ../../../Core/SocketImpl.h ../../../Core/SocketAPI.h \
  ../../../Core/SocketOutputStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  RewardInfo.h ../../../Core/Gpackets/GCNPCResponse.h \
  ../../../Core/Packet.h ../../../Core/PacketFactory.h QuestManager.h \
  QuestInfo.h ../../../Core/Assert.h RewardClass.h QuestStatus.h \
  ../../../Core/VSDateTime.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  EventQuestAdvance.h ../PlayerCreature.h ../Creature.h \
  ../ObjectRegistry.h ../../Mutex.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../InventorySlot.h ../Item.h ../Garbage.h \
  ../RankBonus.h ../ExpFwd.h \
  ../../../Core/Gpackets/GCMonsterKillQuestInfo.h \
  ../../../Core/Gpackets/GCSelectQuestID.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist
AnotherQuestRewardInfo.o: AnotherQuestRewardInfo.cpp \
  AnotherQuestRewardInfo.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../Item.h ../Object.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/Assert.h ../../../Core/Exception.h ../Effect.h \
  ../../Timeval.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h ../EffectManager.h \
  ../../../Core/EffectInfo.h ../../../Core/Packet.h \
  ../../../Core/SocketInputStream.h ../../../Core/Socket.h \
  ../../../Core/SocketImpl.h ../../../Core/SocketAPI.h \
  ../../../Core/SocketOutputStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  RewardInfo.h ../../../Core/Gpackets/GCNPCResponse.h \
  ../../../Core/Packet.h ../../../Core/PacketFactory.h QuestManager.h \
  QuestInfo.h ../../../Core/Assert.h RewardClass.h QuestStatus.h \
  ../../../Core/VSDateTime.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../PlayerCreature.h ../Creature.h ../ObjectRegistry.h ../../Mutex.h \
  ../../../Core/Types.h ../../../Core/Exception.h ../InventorySlot.h \
  ../Item.h ../Garbage.h ../RankBonus.h ../ExpFwd.h \
  ../../../Core/Gpackets/GCMonsterKillQuestInfo.h \
  ../../../Core/Gpackets/GCSelectQuestID.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist
MiniGameQuestInfo.o: MiniGameQuestInfo.cpp MiniGameQuestInfo.h \
  ../../../Core/Types.h ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  QuestInfo.h ../../../Core/Assert.h ../../../Core/Exception.h \
  RewardClass.h ../../../Core/Gpackets/GCNPCResponse.h \
  ../../../Core/Packet.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  MiniGameQuestStatus.h QuestStatus.h ../../../Core/VSDateTime.h \
  ../../../Core/Gpackets/GCQuestStatus.h ../../../Core/Types.h \
  ../../../Core/Exception.h
QuestInfoManager.o: QuestInfoManager.cpp QuestInfoManager.h \
  ../../../Core/Types.h ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/Exception.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  QuestInfo.h ../../../Core/Assert.h RewardClass.h ItemRewardInfo.h \
  ../Item.h ../Object.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/Assert.h ../Effect.h ../../Timeval.h \
  /usr/include/sys/time.h /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../EffectManager.h ../../../Core/EffectInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  RewardInfo.h MonsterKillQuestInfo.h MonsterKillQuestStatus.h \
  QuestStatus.h ../../../Core/VSDateTime.h \
  ../../../Core/Gpackets/GCQuestStatus.h ../../../Core/Types.h \
  ../../../Core/Exception.h GatherItemQuestInfo.h GatherItemQuestStatus.h \
  QuestManager.h EventQuestAdvance.h ../PlayerCreature.h ../Creature.h \
  ../ObjectRegistry.h ../../Mutex.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../InventorySlot.h ../Item.h ../Garbage.h \
  ../RankBonus.h ../ExpFwd.h \
  ../../../Core/Gpackets/GCMonsterKillQuestInfo.h \
  ../../../Core/Gpackets/GCSelectQuestID.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  ../NPC.h ../Zone.h ../Tile.h ../Obstacle.h ../Portal.h \
  ../quest/TriggerManager.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../quest/Trigger.h ../quest/Condition.h \
  ../quest/PropertyBuffer.h ../Sector.h ../Party.h \
  ../../../Core/ModifyInfo.h ../PCManager.h ../CreatureManager.h \
  ../../../Core/Encrypter.h ../../../Core/EncryptUtility.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/queue \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/deque \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_deque.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/deque.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_queue.h \
  ../Inventory.h ../VolumeInfo.h ../couple/PartnerWaitingManager.h \
  ../../../Core/Exception.h ../../../Core/Types.h ../../Timeval.h \
  ../PlayerCreature.h ../VariableManager.h ../../database/DB.h \
  ../../database/DatabaseManager.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../database/Connection.h \
  /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
  /usr/include/mysql/mysql_com.h /usr/include/mysql/mysql_time.h \
  /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
  /usr/include/mysql/my_list.h ../../Mutex.h ../../database/Statement.h \
  ../../database/Result.h
SimpleQuestInfoManager.o: SimpleQuestInfoManager.cpp \
  SimpleQuestInfoManager.h QuestInfoManager.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/Exception.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  RewardClass.h RewardClassInfoManager.h MonsterKillQuestInfo.h \
  QuestInfo.h ../../../Core/Assert.h MonsterKillQuestStatus.h \
  QuestStatus.h ../../../Core/VSDateTime.h \
  ../../../Core/Gpackets/GCQuestStatus.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../database/DB.h \
  ../../database/DatabaseManager.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../database/Connection.h \
  /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
  /usr/include/mysql/mysql_com.h /usr/include/mysql/mysql_time.h \
  /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
  /usr/include/mysql/my_list.h ../../Mutex.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../database/Statement.h \
  ../../database/Result.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h
EventQuestInfoManager.o: EventQuestInfoManager.cpp \
  EventQuestInfoManager.h QuestInfoManager.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/Exception.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  RewardClass.h RewardClassInfoManager.h MonsterKillQuestInfo.h \
  QuestInfo.h ../../../Core/Assert.h MonsterKillQuestStatus.h \
  QuestStatus.h ../../../Core/VSDateTime.h \
  ../../../Core/Gpackets/GCQuestStatus.h ../../../Core/Types.h \
  ../../../Core/Exception.h GatherItemQuestInfo.h ../Item.h ../Object.h \
  ../../../Core/Types.h ../../../Core/Exception.h ../../../Core/Assert.h \
  ../Effect.h ../../Timeval.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h ../EffectManager.h \
  ../../../Core/EffectInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  GatherItemQuestStatus.h MeetNPCQuestInfo.h MeetNPCQuestStatus.h \
  MiniGameQuestInfo.h MiniGameQuestStatus.h ../../database/DB.h \
  ../../database/DatabaseManager.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../database/Connection.h \
  /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
  /usr/include/mysql/mysql_com.h /usr/include/mysql/mysql_time.h \
  /usr/include/mysql/typelib.h /usr/include/mysql/my_alloc.h \
  /usr/include/mysql/my_list.h ../../Mutex.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../database/Statement.h \
  ../../database/Result.h
RewardClassInfoManager.o: RewardClassInfoManager.cpp \
  RewardClassInfoManager.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/Exception.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  RandomRewardClass.h RewardClass.h SlayerWeaponRewardClass.h \
  ItemRewardInfo.h ../Item.h ../Object.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../../Core/Assert.h ../Effect.h \
  ../../Timeval.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h ../EffectManager.h \
  ../../../Core/EffectInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  RewardInfo.h ../../database/DB.h ../../database/DatabaseManager.h \
  ../../../Core/Types.h ../../../Core/Exception.h \
  ../../database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h \
  ../../Mutex.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../database/Statement.h ../../database/Result.h
SimpleQuestRewardManager.o: SimpleQuestRewardManager.cpp \
  SimpleQuestRewardManager.h RewardClassInfoManager.h \
  ../../../Core/Types.h ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/Exception.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../../database/DB.h ../../database/DatabaseManager.h \
  ../../../Core/Types.h ../../../Core/Exception.h \
  ../../database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h \
  ../../Mutex.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../database/Statement.h ../../database/Result.h \
  /usr/include/sys/time.h /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../Item.h ../Object.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/Assert.h ../Effect.h ../../Timeval.h ../EffectManager.h \
  ../../../Core/EffectInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  RandomRewardClass.h RewardClass.h SlayerWeaponRewardClass.h \
  ItemRewardInfo.h RewardInfo.h
QuestManager.o: QuestManager.cpp QuestManager.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  QuestInfo.h ../../../Core/Assert.h ../../../Core/Exception.h \
  RewardClass.h ../../../Core/Gpackets/GCNPCResponse.h \
  ../../../Core/Packet.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  ../../../Core/PacketFactory.h ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  QuestStatus.h ../../../Core/VSDateTime.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  MonsterKillQuestStatus.h ../../../Core/Gpackets/GCQuestStatus.h \
  ../../../Core/Types.h ../../../Core/Exception.h GatherItemQuestStatus.h \
  ../Item.h ../Object.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/Assert.h ../Effect.h ../../Timeval.h \
  /usr/include/sys/time.h /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../EffectManager.h ../../../Core/EffectInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  MeetNPCQuestStatus.h MiniGameQuestStatus.h QuestInfoManager.h \
  EventQuestAdvance.h ../PlayerCreature.h ../Creature.h \
  ../ObjectRegistry.h ../../Mutex.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../InventorySlot.h ../Item.h ../Garbage.h \
  ../RankBonus.h ../ExpFwd.h \
  ../../../Core/Gpackets/GCMonsterKillQuestInfo.h \
  ../../../Core/Gpackets/GCSelectQuestID.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  ../../../Core/Player.h ../Monster.h ../MonsterInfo.h \
  ../MonsterSummonInfo.h ../MonsterInfoTypes.h ../Treasure.h \
  ../PrecedenceTable.h ../NPC.h ../Zone.h ../Tile.h ../Obstacle.h \
  ../Portal.h ../quest/TriggerManager.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../quest/Trigger.h ../quest/Condition.h \
  ../quest/PropertyBuffer.h ../Sector.h ../Party.h \
  ../../../Core/ModifyInfo.h ../PCManager.h ../CreatureManager.h \
  ../../../Core/Encrypter.h ../../../Core/EncryptUtility.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/queue \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/deque \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_deque.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/deque.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_queue.h \
  ../Inventory.h ../VolumeInfo.h ../couple/PartnerWaitingManager.h \
  ../../../Core/Exception.h ../../../Core/Types.h ../../Timeval.h \
  ../PlayerCreature.h ../VariableManager.h ../../../Core/Packet.h \
  ../../../Core/StringStream.h
QuestStatus.o: QuestStatus.cpp QuestStatus.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/VSDateTime.h ../../../Core/Assert.h \
  ../../../Core/Exception.h QuestInfo.h RewardClass.h \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/SocketInputStream.h ../../../Core/Socket.h \
  ../../../Core/SocketImpl.h ../../../Core/SocketAPI.h \
  ../../../Core/SocketOutputStream.h ../../../Core/PacketFactory.h \
  ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  QuestManager.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../../../Core/StringStream.h
MonsterKillQuestStatus.o: MonsterKillQuestStatus.cpp \
  MonsterKillQuestStatus.h QuestStatus.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/VSDateTime.h ../../../Core/Assert.h \
  ../../../Core/Exception.h QuestInfo.h RewardClass.h \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/SocketInputStream.h ../../../Core/Socket.h \
  ../../../Core/SocketImpl.h ../../../Core/SocketAPI.h \
  ../../../Core/SocketOutputStream.h ../../../Core/PacketFactory.h \
  ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  ../../../Core/Gpackets/GCQuestStatus.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../../Core/StringStream.h
GatherItemQuestStatus.o: GatherItemQuestStatus.cpp \
  GatherItemQuestStatus.h QuestStatus.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/VSDateTime.h ../../../Core/Assert.h \
  ../../../Core/Exception.h QuestInfo.h RewardClass.h \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/SocketInputStream.h ../../../Core/Socket.h \
  ../../../Core/SocketImpl.h ../../../Core/SocketAPI.h \
  ../../../Core/SocketOutputStream.h ../../../Core/PacketFactory.h \
  ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  ../Item.h ../Object.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/Assert.h ../Effect.h ../../Timeval.h \
  /usr/include/sys/time.h /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../EffectManager.h ../../../Core/EffectInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  ../../../Core/Gpackets/GCQuestStatus.h ../../../Core/Types.h \
  ../../../Core/Exception.h QuestInfoManager.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../PlayerCreature.h ../Creature.h ../ObjectRegistry.h ../../Mutex.h \
  ../../../Core/Types.h ../../../Core/Exception.h ../InventorySlot.h \
  ../Item.h ../Garbage.h ../RankBonus.h ../ExpFwd.h \
  ../../../Core/Gpackets/GCMonsterKillQuestInfo.h \
  ../../../Core/Gpackets/GCSelectQuestID.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  ../Inventory.h ../VolumeInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tree.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_map.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_multimap.h
DummyQuestStatus.o: DummyQuestStatus.cpp DummyQuestStatus.h QuestStatus.h \
  ../../../Core/Types.h ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/VSDateTime.h ../../../Core/Assert.h \
  ../../../Core/Exception.h QuestInfo.h RewardClass.h \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/SocketInputStream.h ../../../Core/Socket.h \
  ../../../Core/SocketImpl.h ../../../Core/SocketAPI.h \
  ../../../Core/SocketOutputStream.h ../../../Core/PacketFactory.h \
  ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  ../../../Core/Gpackets/GCQuestStatus.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../../Core/StringStream.h
MeetNPCQuestStatus.o: MeetNPCQuestStatus.cpp MeetNPCQuestStatus.h \
  QuestStatus.h ../../../Core/Types.h ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/VSDateTime.h ../../../Core/Assert.h \
  ../../../Core/Exception.h QuestInfo.h RewardClass.h \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/SocketInputStream.h ../../../Core/Socket.h \
  ../../../Core/SocketImpl.h ../../../Core/SocketAPI.h \
  ../../../Core/SocketOutputStream.h ../../../Core/PacketFactory.h \
  ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  ../../../Core/Gpackets/GCQuestStatus.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../../Core/StringStream.h
MiniGameQuestStatus.o: MiniGameQuestStatus.cpp MiniGameQuestStatus.h \
  QuestStatus.h ../../../Core/Types.h ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/VSDateTime.h ../../../Core/Assert.h \
  ../../../Core/Exception.h QuestInfo.h RewardClass.h \
  ../../../Core/Gpackets/GCNPCResponse.h ../../../Core/Packet.h \
  ../../../Core/SocketInputStream.h ../../../Core/Socket.h \
  ../../../Core/SocketImpl.h ../../../Core/SocketAPI.h \
  ../../../Core/SocketOutputStream.h ../../../Core/PacketFactory.h \
  ../../../Core/Packet.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  ../../../Core/Gpackets/GCQuestStatus.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../PlayerCreature.h ../Creature.h ../Object.h \
  ../../../Core/Types.h ../../../Core/Exception.h ../../../Core/Assert.h \
  ../EffectManager.h ../Effect.h ../../Timeval.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../../../Core/EffectInfo.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  ../ObjectRegistry.h ../../Mutex.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../InventorySlot.h ../Item.h ../Garbage.h \
  ../RankBonus.h ../ExpFwd.h \
  ../../../Core/Gpackets/GCMonsterKillQuestInfo.h \
  ../../../Core/Gpackets/GCSelectQuestID.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  ../Slayer.h ../PlayerCreature.h ../Zone.h ../Tile.h ../Obstacle.h \
  ../Portal.h ../quest/TriggerManager.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../quest/Trigger.h ../quest/Condition.h \
  ../quest/PropertyBuffer.h ../Sector.h ../Party.h \
  ../../../Core/ModifyInfo.h ../PCManager.h ../CreatureManager.h \
  ../../../Core/Encrypter.h ../../../Core/EncryptUtility.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/queue \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/deque \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_deque.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/deque.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_queue.h \
  ../Inventory.h ../VolumeInfo.h ../../../Core/PCSlayerInfo.h \
  ../../../Core/PCInfo.h ../../../Core/PCSlayerInfo2.h \
  ../../../Core/PCSlayerInfo3.h ../../../Core/Assert.h \
  ../../../Core/InventoryInfo.h ../../../Core/InventorySlotInfo.h \
  ../../../Core/PCItemInfo.h ../../../Core/SubItemInfo.h \
  ../ItemLoaderManager.h ../ItemLoader.h ../../../Core/GearInfo.h \
  ../../../Core/GearSlotInfo.h ../../../Core/ExtraInfo.h \
  ../../../Core/ExtraSlotInfo.h ../OptionInfo.h \
  ../../../Core/RideMotorcycleInfo.h \
  ../../../Core/RideMotorcycleSlotInfo.h ../../../Core/SlayerSkillInfo.h \
  ../../../Core/PCSkillInfo.h ../../../Core/SubSlayerSkillInfo.h \
  ../CreatureUtil.h ../SlayerAttrExpTable.h ../SomethingGrowingUp.h \
  ../../database/DB.h ../../database/DatabaseManager.h \
  ../../../Core/Types.h ../../../Core/Exception.h \
  ../../database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h \
  ../../Mutex.h ../../database/Statement.h ../../database/Result.h \
  ../skill/Skill.h ../../../Core/Types.h ../skill/SkillSlot.h \
  ../../Timeval.h ../skill/Skill.h ../../../Core/Exception.h \
  ../../../Core/Gpackets/GCModifyInformation.h ../../../Core/ModifyInfo.h \
  ../Vampire.h ../../../Core/PCVampireInfo.h \
  ../../../Core/PCVampireInfo2.h ../../../Core/PCVampireInfo3.h \
  ../../../Core/VampireSkillInfo.h ../../../Core/SubVampireSkillInfo.h \
  ../skill/VampireSkillSlot.h ../Ousters.h ../../../Core/PCOustersInfo.h \
  ../../../Core/PCOustersInfo2.h ../../../Core/PCOustersInfo3.h \
  ../../../Core/OustersSkillInfo.h ../../../Core/SubOustersSkillInfo.h \
  ../skill/OustersSkillSlot.h ../../../Core/Player.h \
  ../../../Core/StringStream.h ../../database/DB.h ../PacketUtil.h \
  ../../../Core/Gpackets/GCMiniGameScores.h ../../../Core/Assert.h
EventQuestAdvance.o: EventQuestAdvance.cpp EventQuestAdvance.h \
  ../../../Core/Types.h ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../../../Core/Assert.h ../../../Core/Exception.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  ../../database/DB.h ../../database/DatabaseManager.h \
  ../../../Core/Types.h ../../../Core/Exception.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../../database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h \
  ../../Mutex.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../database/Statement.h ../../database/Result.h \
  /usr/include/sys/time.h /usr/include/gentoo-multilib/amd64/sys/time.h \
  ../PlayerCreature.h ../Creature.h ../Object.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../../Core/Assert.h ../EffectManager.h \
  ../Effect.h ../../Timeval.h ../../../Core/EffectInfo.h \
  ../../../Core/Packet.h ../../../Core/SocketInputStream.h \
  ../../../Core/Socket.h ../../../Core/SocketImpl.h \
  ../../../Core/SocketAPI.h ../../../Core/SocketOutputStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  ../ObjectRegistry.h ../../Mutex.h ../InventorySlot.h ../Item.h \
  ../Garbage.h ../RankBonus.h ../ExpFwd.h \
  ../../../Core/Gpackets/GCMonsterKillQuestInfo.h ../../../Core/Packet.h \
  ../../../Core/PacketFactory.h ../../../Core/Gpackets/GCSelectQuestID.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist
EventQuestLootingManager.o: EventQuestLootingManager.cpp \
  EventQuestLootingManager.h ../../../Core/Types.h \
  ../../../Core/types/SystemTypes.h \
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
  ../../../Core/types/PlayerTypes.h ../../../Core/types/SystemTypes.h \
  ../../../Core/types/ObjectTypes.h ../../../Core/types/CreatureTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/ZoneTypes.h \
  ../../../Core/types/QuestTypes.h ../../../Core/types/ShopTypes.h \
  ../../../Core/types/ItemTypes.h ../../../Core/types/GuildTypes.h \
  ../../../Core/types/WarTypes.h ../../../Core/types/ServerType.h \
  ../../../Core/Utility.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/StringStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/list \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_list.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/list.tcc \
  ../Item.h ../Object.h ../../../Core/Types.h ../../../Core/Exception.h \
  ../../../Core/Assert.h ../../../Core/Exception.h ../Effect.h \
  ../../Timeval.h /usr/include/sys/time.h \
  /usr/include/gentoo-multilib/amd64/sys/time.h ../EffectManager.h \
  ../../../Core/EffectInfo.h ../../../Core/Packet.h \
  ../../../Core/SocketInputStream.h ../../../Core/Socket.h \
  ../../../Core/SocketImpl.h ../../../Core/SocketAPI.h \
  ../../../Core/SocketOutputStream.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bitset \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/vector \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_vector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_bvector.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/vector.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_tree.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_map.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_multimap.h \
  ../Monster.h ../Creature.h ../MonsterInfo.h ../MonsterSummonInfo.h \
  ../MonsterInfoTypes.h ../Treasure.h ../Item.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_map \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hashtable.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/iterator \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stream_iterator.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/hash_fun.h \
  ../PrecedenceTable.h ../ItemFactoryManager.h ../ItemFactory.h \
  ../PlayerCreature.h ../ObjectRegistry.h ../../Mutex.h \
  ../../../Core/Types.h ../../../Core/Exception.h ../InventorySlot.h \
  ../Garbage.h ../RankBonus.h ../ExpFwd.h \
  ../../../Core/Gpackets/GCMonsterKillQuestInfo.h ../../../Core/Packet.h \
  ../../../Core/PacketFactory.h ../../../Core/Gpackets/GCSelectQuestID.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/ext/slist \
  ../Slayer.h ../PlayerCreature.h ../Zone.h ../Tile.h ../Obstacle.h \
  ../Portal.h ../quest/TriggerManager.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../quest/Trigger.h ../quest/Condition.h \
  ../quest/PropertyBuffer.h ../Sector.h ../Party.h \
  ../../../Core/ModifyInfo.h ../PCManager.h ../CreatureManager.h \
  ../../../Core/Encrypter.h ../../../Core/EncryptUtility.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/queue \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/deque \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_deque.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/deque.tcc \
  /usr/lib/gcc/x86_64-pc-linux-gnu/4.1.1/include/g++-v4/bits/stl_queue.h \
  ../Inventory.h ../VolumeInfo.h ../../../Core/PCSlayerInfo.h \
  ../../../Core/PCInfo.h ../../../Core/PCSlayerInfo2.h \
  ../../../Core/PCSlayerInfo3.h ../../../Core/Assert.h \
  ../../../Core/InventoryInfo.h ../../../Core/InventorySlotInfo.h \
  ../../../Core/PCItemInfo.h ../../../Core/SubItemInfo.h \
  ../ItemLoaderManager.h ../ItemLoader.h ../../../Core/GearInfo.h \
  ../../../Core/GearSlotInfo.h ../../../Core/ExtraInfo.h \
  ../../../Core/ExtraSlotInfo.h ../OptionInfo.h \
  ../../../Core/RideMotorcycleInfo.h \
  ../../../Core/RideMotorcycleSlotInfo.h ../../../Core/SlayerSkillInfo.h \
  ../../../Core/PCSkillInfo.h ../../../Core/SubSlayerSkillInfo.h \
  ../CreatureUtil.h ../SlayerAttrExpTable.h ../SomethingGrowingUp.h \
  ../../database/DB.h ../../database/DatabaseManager.h \
  ../../../Core/Types.h ../../../Core/Exception.h \
  ../../database/Connection.h /usr/include/mysql/mysql.h \
  /usr/include/mysql/mysql_version.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_time.h /usr/include/mysql/typelib.h \
  /usr/include/mysql/my_alloc.h /usr/include/mysql/my_list.h \
  ../../Mutex.h ../../database/Statement.h ../../database/Result.h \
  ../skill/Skill.h ../../../Core/Types.h ../skill/SkillSlot.h \
  ../../Timeval.h ../skill/Skill.h ../../../Core/Exception.h \
  ../../../Core/Gpackets/GCModifyInformation.h ../../../Core/Types.h \
  ../../../Core/Exception.h ../../../Core/ModifyInfo.h ../Vampire.h \
  ../../../Core/PCVampireInfo.h ../../../Core/PCVampireInfo2.h \
  ../../../Core/PCVampireInfo3.h ../../../Core/VampireSkillInfo.h \
  ../../../Core/SubVampireSkillInfo.h ../skill/VampireSkillSlot.h \
  ../Ousters.h ../../../Core/PCOustersInfo.h \
  ../../../Core/PCOustersInfo2.h ../../../Core/PCOustersInfo3.h \
  ../../../Core/OustersSkillInfo.h ../../../Core/SubOustersSkillInfo.h \
  ../skill/OustersSkillSlot.h EventQuestAdvance.h ../../../Core/Assert.h \
  QuestManager.h QuestInfo.h RewardClass.h \
  ../../../Core/Gpackets/GCNPCResponse.h QuestStatus.h \
  ../../../Core/VSDateTime.h ../../../Core/StringStream.h \
  ../../database/DB.h
