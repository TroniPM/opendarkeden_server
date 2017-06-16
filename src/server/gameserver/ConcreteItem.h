#ifndef __CONCRETE_ITEM_H__
#define __CONCRETE_ITEM_H__

#include "Item.h"
#include "ItemInfo.h"
#include "ItemInfoManager.h"
#include "DB.h"

template <Item::ItemClass IClass,
	typename StackPolicy, typename DurabilityPolicy, typename OptionPolicy, typename GradePolicy,
	typename AttackingStatPolicy>
class ConcreteItem : public Item
{
public:
	// 가상 함수 구체화
	ItemClass	getItemClass() const throw() { return IClass; }
	string		getObjectTableName() const throw() { return ItemObjectTableName[getItemClass()]; }
	ItemInfo*	getItemInfo() const { return g_pItemInfoManager->getItemInfo( getItemClass(), getItemType() ); }

	ItemType_t	getItemType() const throw() { return m_ItemType; }
	void		setItemType(ItemType_t itemType) throw() { m_ItemType = itemType; }

	VolumeWidth_t	getVolumeWidth() const throw(Error) { return getItemInfo()->getVolumeWidth(); }
	VolumeHeight_t	getVolumeHeight() const throw(Error) { return getItemInfo()->getVolumeHeight(); }
	Weight_t		getWeight() const throw(Error) { return getItemInfo()->getWeight(); }

public:
	// 아이템 쌓기 관련
	bool	isStackable() const throw() { return m_Stack.isStackable(); }

	ItemNum_t	getNum() const throw() { return m_Stack.getNum(); }
	void		setNum(ItemNum_t Num) throw() { m_Stack.setNum(Num); }

public:
	// 내구도 관련
	Durability_t	getDurability() const throw(Error) { return m_Durability.getDurability(); }
	void			setDurability(Durability_t durability) throw(Error) { m_Durability.setDurability(durability); }
	Durability_t	getMaxDurability() const {
		if ( m_Durability.hasDurability() )
			return max(1000,((int)getItemInfo()->getDurability()) + m_Grade.getDurabilityOffset());
		else
			return getItemInfo()->getDurability();
	}

public:
	// 옵션 관련
	bool						hasOptionType() const throw() { return m_Option.hasOptionType(); }
	int							getOptionTypeSize() const throw() { return m_Option.getOptionTypeSize(); }
	int							getRandomOptionType() const throw() { return m_Option.getRandomOptionType(); }
	const list<OptionType_t>&	getOptionTypeList() const throw() { return m_Option.getOptionTypeList(); }
	OptionType_t				getFirstOptionType() const throw() { return m_Option.getFirstOptionType(); }
	void						removeOptionType(OptionType_t OptionType) throw() { m_Option.removeOptionType(OptionType); }
	void						changeOptionType(OptionType_t currentOptionType, OptionType_t newOptionType) throw() { m_Option.changeOptionType(currentOptionType, newOptionType); }
	void						addOptionType(OptionType_t OptionType) throw() { m_Option.addOptionType(OptionType); }
	void						setOptionType(const list<OptionType_t>& OptionType) throw() { m_Option.setOptionType(OptionType); }

public:
	// 아이템 등급 관련
	Grade_t	getGrade() const { return m_Grade.getGrade(); }
	void	setGrade(Grade_t Grade) { m_Grade.setGrade(Grade); }

	Luck_t	getLuck() const { return m_Grade.getLuck(); }

public:
	// 공격력 관련 속성
	Damage_t	getMinDamage() const throw(Error) { return max(1,((int)getItemInfo()->getMinDamage()) + ((int)getBonusDamage()) + m_Grade.getDamageOffset()); }
	Damage_t	getMaxDamage() const throw(Error) { return max(1,((int)getItemInfo()->getMaxDamage()) + ((int)getBonusDamage()) + m_Grade.getDamageOffset()); }
	Range_t		getRange() const throw(Error) { return getItemInfo()->getRange(); }
	ToHit_t		getToHitBonus() const throw(Error) { return getItemInfo()->getToHitBonus(); }
	Speed_t		getSpeed() const throw(Error) { return getItemInfo()->getSpeed(); }
	int			getCriticalBonus() const throw() { return max(0,getItemInfo()->getCriticalBonus() + m_Grade.getCriticalOffset()); }

	BYTE		getBulletCount() const throw() { return m_AttackingStat.getBulletCount(); }
	void		setBulletCount(BYTE bulletCount) throw() { m_AttackingStat.setBulletCount(bulletCount); }

	bool		isSilverWeapon() const throw() { return m_AttackingStat.isSilverWeapon(); }
	Silver_t	getSilver() const throw() { return m_AttackingStat.getSilver(); }
	void		setSilver(Silver_t amount) throw() { m_AttackingStat.setSilver(amount); }

	bool		isGun() const throw() { return m_AttackingStat.isGun(); }

	Damage_t	getBonusDamage() const throw() { return m_AttackingStat.getBonusDamage(); }
	void		setBonusDamage(Damage_t BonusDamage) throw() { m_AttackingStat.setBonusDamage(BonusDamage); }

public:
	// 방어력 관련 속성
	Defense_t	getDefenseBonus() const throw(Error) { return max(0,((int)getItemInfo()->getDefenseBonus()) + m_Grade.getDefenseOffset()); }
	Protection_t	getProtectionBonus() const throw(Error) { return max(0,((int)getItemInfo()->getProtectionBonus()) + m_Grade.getProtectionOffset()); }

private:
	ItemType_t			m_ItemType;

	StackPolicy			m_Stack;
	DurabilityPolicy	m_Durability;
	OptionPolicy		m_Option;
	GradePolicy			m_Grade;

	AttackingStatPolicy	m_AttackingStat;
};

#endif
