#ifndef __EVENT_ITEM_UTIL_H__
#define __EVENT_ITEM_UTIL_H__

class Item;
class PlayerCreature;
class Monster;

enum MoonCard
{
	NO_CARD,
	FULL_MOON,
	OLD_MOON,
	HALF_MOON,
	NEW_MOON
};

MoonCard getCardKind( PlayerCreature* pPC, Monster* pMonster );
Item* getCardItem( MoonCard card );

enum LuckyBag
{
	NO_LUCKY_BAG,
	GREEN_LUCKY_BAG,
	BLUE_LUCKY_BAG,
	GOLD_LUCKY_BAG,
	RED_LUCKY_BAG
};

LuckyBag getLuckyBagKind( PlayerCreature* pPC, Monster* pMonster );
Item* getLuckyBagItem( LuckyBag luckybag );

enum GiftBox
{
	NO_GIFT_BOX,
	RED_GIFT_BOX,
	BLUE_GIFT_BOX,
	GREEN_GIFT_BOX,
	YELLOW_GIFT_BOX
};

GiftBox getGiftBoxKind( PlayerCreature* pPC, Monster* pMonster );
Item* getGiftBoxItem( GiftBox giftbox );

int getBlackGiftBoxType( int t1, int t2);
bool canGiveEventItem( PlayerCreature* pPC, Monster* pMonster );

#endif// __EVENT_ITEM_UTIL_H__
