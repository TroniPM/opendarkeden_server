////////////////////////////////////////////////////////////////////////////////
// Filename    : Inventory.cpp
// Written By  : elca@ewestsoft.com
// Revised By  : �輺��
// Description : 
////////////////////////////////////////////////////////////////////////////////

#include "Inventory.h"
#include "Assert.h"
#include "ItemInfoManager.h"
#include "VolumeInfo.h"
#include "ParkingCenter.h"
#include "ObjectRegistry.h"
#include "ItemUtil.h"
#include "EffectSchedule.h"
#include "Zone.h"
#include <map>

#include "Key.h"
#include "Belt.h"

#include "EffectVampirePortal.h"

////////////////////////////////////////////////////////////////////////////////
//
// CONSTRUCTOR & DESTRUCTOR
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// �⺻ ������
////////////////////////////////////////////////////////////
Inventory::Inventory(CoordInven_t Width, CoordInven_t Height, bool bDeleteAll)
	throw()
{
	__BEGIN_TRY

	m_Owner          = "";
	m_Width          = Width;
	m_Height         = Height;
	m_TotalNum       = 0;
	m_TotalWeight    = 0;
	m_bDeleteAll     = bDeleteAll;
	m_pInventorySlot = NULL;

	m_pInventorySlot = new InventorySlot*[m_Width];
	for (int i=0; i < m_Width ; i ++) 
	{
		m_pInventorySlot[i] = new InventorySlot[m_Height];
	}


	__END_CATCH
}

////////////////////////////////////////////////////////////
// ���� ������
////////////////////////////////////////////////////////////
Inventory::Inventory(const Inventory* pInventory)
	throw()
{
	__BEGIN_TRY

	m_Width          = pInventory->getWidth();
	m_Height         = pInventory->getHeight();
	m_TotalNum       = pInventory->getItemNum();
	m_TotalWeight    = pInventory->getWeight();
	m_bDeleteAll     = pInventory->getDeleteAllFlag();
	m_pInventorySlot = NULL;

	m_pInventorySlot = new InventorySlot*[m_Width];
	for (int i=0; i < m_Width ; i ++) 
	{
		m_pInventorySlot[i] = new InventorySlot[m_Height];
	}

	for (int x=0; x<m_Width; x++)
	{
		for (int y=0; y<m_Height; y++)
		{
			Item* pItem = pInventory->getInventorySlot(x, y).getItem();
			if (pItem != NULL) m_pInventorySlot[x][y].addItem(pItem);
		}
	}

	__END_CATCH
}

////////////////////////////////////////////////////////////
// �Ҹ���
////////////////////////////////////////////////////////////
Inventory::~Inventory()
	throw()
{
	__BEGIN_TRY

	int i, j, k;

	try 
	{
		if (m_pInventorySlot != NULL)
		{
			// �κ��丮�� ����ϴ� ���� �����۵�� ����Ѵ�.
			// ������ ũ�⸦ �����ϸ� ��� ����ȭ�� �� ��� ���̴�.
			for (j = 0 ; j < m_Height ; j++) 
			{
				for (i = 0 ; i < m_Width ; i++) 
				{
					Item* pItem = m_pInventorySlot[i][j].getItem();
					if (pItem != NULL) 
					{
						// �κ��丮 ����� NULL �� ����Ѵ�.

						deleteItem(i,j);

						if (m_bDeleteAll)
						{
							// ������ ���쿡 ParkingCenter���� �������� ����� �������.
							// Zone���� �������̸� ������ְ�, ParkingCenter�� �������̸� ����Ѵ�.
							// ���� �����ϰ� �ϱ� ��ؼ� GamePlayer ������ Creature�� destructor����
							// �ؾ��ϳ�, �˻� �ð��� ����� ��ؼ� �Ǽ��� ���⼭ �ϵ��� �Ѵ�.
							// �̰� ���ֹ�, �� �ȴ�.
							if (pItem->getItemClass() == Item::ITEM_CLASS_KEY) 
							{
								Key* pKey = dynamic_cast<Key*>(pItem);
								// �� �����ϰ� �̾ȿ��� �˾Ƽ� ����� ���� �ֵ��� ����.
								if (g_pParkingCenter->hasMotorcycleBox(pKey->getTarget())) 
								{
									g_pParkingCenter->deleteMotorcycleBox(pKey->getTarget());
								}
							}

							SAFE_DELETE(pItem);
						} // end of if (m_bDeleteAll)
					} // end of if (pItem != NULL)
				} // end of for
			} // end of for

			//Assert(m_TotalNum == 0);
			//Assert(m_TotalWeight == 0);
			// �ӽ÷� �־��� �ڵ�.. �׳� ���ڳ� ���� �; - -; by sigi. 2002.5.15
			if (m_TotalNum != 0)
			{
				filelog("inventoryBug.txt", "TotalNum=%d", m_TotalNum);
			}

			Assert(m_TotalNum == 0);

			for (k = 0; k < m_Width; k++) 
			{
				if (m_pInventorySlot[k] != NULL)
				{
					SAFE_DELETE_ARRAY(m_pInventorySlot[k]);
				}
			}

			SAFE_DELETE_ARRAY(m_pInventorySlot);
		}
	} 
	catch (Throwable & t) 
	{ 
		//cerr << t.toString() << endl; 
	}
	
	__END_CATCH
}
 




////////////////////////////////////////////////////////////////////////////////
//
// CHECK METHODS
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// ����� �ġ�� �������� �ִ°�?
////////////////////////////////////////////////////////////
bool Inventory::hasItem(CoordInven_t X, CoordInven_t Y)
	throw()
{
	__BEGIN_TRY

	if (X < m_Width && Y < m_Height) 
	{
		InventorySlot& slot = getInventorySlot(X, Y);
		return (slot.getItem() != NULL) ? true : false;
	}
	return false;
	
	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� �������� �ִ°�?
////////////////////////////////////////////////////////////
bool Inventory::hasItem(ObjectID_t ObjectID)
	throw()
{
	__BEGIN_TRY

	CoordInven_t x, y;
	if (findItemOID(ObjectID, x, y) != NULL) return true;
	return false;

	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� �������� �ִ°�?
////////////////////////////////////////////////////////////
bool Inventory::hasItemWithItemID(ItemID_t ItemID)
	throw()
{
	__BEGIN_TRY

	CoordInven_t x, y;
	if (findItemIID(ItemID, x, y) != NULL) return true;
	return false;

	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� Ÿ��� Ÿ����� �ϴ� ���踦 ������ �ִ°�?
////////////////////////////////////////////////////////////
bool Inventory::hasKey(ItemID_t TargetItemID)
	throw()
{
	__BEGIN_TRY

	for (int x = 0; x < m_Width; x++) 
	{
		for (int y = 0; y < m_Height; y++) 
		{
			Item* pSlotItem = m_pInventorySlot[x][y].getItem();

			if (pSlotItem != NULL && pSlotItem->getItemClass() == Item::ITEM_CLASS_KEY) 
			{
				Key* pKey = dynamic_cast<Key*>(pSlotItem);
				if (pKey->getTarget() == TargetItemID) return true;
			}
		}
	}

	return false;

	__END_CATCH
}

////////////////////////////////////////////////////////////
// �־��� �ġ�� ������� ���� �� �ִ°�? 
// �� �Լ��� �ϳ��� ���콺�� ���� �� �ִٰ� ����ϰ� 
// ������ �����Ѵ�.
////////////////////////////////////////////////////////////
bool Inventory::canAdding(CoordInven_t X, CoordInven_t Y, Item* pItem)
	throw()
{
	__BEGIN_TRY

	// get Volume's Size Width, Height
	VolumeWidth_t  ItemWidth  = pItem->getVolumeWidth();
	VolumeHeight_t ItemHeight = pItem->getVolumeHeight();
	int            ItemCount = 0;
	ObjectID_t     ItemObjectID;

	if ((X+ItemWidth > m_Width) || (Y+ItemHeight > m_Height)) return false;

	for (int x = X; x < X + ItemWidth ; x++) 
	{
		for (int y = Y; y < Y + ItemHeight ; y++) 
		{
			if (hasItem(x, y)) 
			{
				Item*      pTempItem    = m_pInventorySlot[x][y].getItem();
				ObjectID_t TempObjectID = pTempItem->getObjectID();

				if (ItemCount == 0) 
				{
					ItemObjectID = TempObjectID;  
					ItemCount++;
				}
				if (ItemObjectID != TempObjectID) 
				{
					ItemCount++;
				}
			}
		}
	}

	if (ItemCount > 1) return false;

	// if not false return true
	return true;

	__END_CATCH
}

////////////////////////////////////////////////////////////
// �־��� �ġ�� ������� ���� �� �ִ°�? 
// �� �Լ��� ���콺�� ������� ���� �� �ִٰ� 
// ������� ***�ʴ´�.***
////////////////////////////////////////////////////////////
bool Inventory::canAddingEx(CoordInven_t X, CoordInven_t Y, Item* pItem)
	throw()
{
	__BEGIN_TRY

	VolumeWidth_t   ItemWidth     = pItem->getVolumeWidth();
	VolumeHeight_t  ItemHeight    = pItem->getVolumeHeight();
	list<Item*>     prevItemList;

	if ((X+ItemWidth > m_Width) || (Y+ItemHeight > m_Height)) return false;

	// �κ��丮�� �˻��ϸ鼭, �� �ڸ��� �������� �ִٸ�,
	// ����Ʈ�� �� �������� ������ �˻��� ��, ����Ʈ���� ������� �����ִ´�.
	for (int x=X; x<X+ItemWidth; x++)
	{
		for (int y=Y; y<Y+ItemHeight; y++)
		{
			Item* pInvenItem = m_pInventorySlot[x][y].getItem();

			// �� �ڸ��� �������� �ִٸ�...
			if (pInvenItem != NULL)
			{
				bool bAdd = true;

				// ����Ʈ�� ����ϴ��� �˻�
				list<Item*>::iterator itr = prevItemList.begin();
				for (; itr != prevItemList.end(); itr++)
				{
					if (*itr == pInvenItem)
					{
						bAdd = false;
						break;
					}
				}

				// ����Ʈ���ٰ� ������� ���Ѵ�.
				if (bAdd) prevItemList.push_back(pInvenItem);
			}
		} 
	} 

	// ������� ������ �ϴ� ���� �� ���� �̻��� �������� �ִٸ�,
	// ������� ��� �� ����.
	if (prevItemList.size() > 1) return false;

	// �������� �ϳ� �ִٸ� �� ������� ���̴� �������̾��� �ϰ�,
	// ������ �����۰� Ŭ������ Ÿ���� ���ƾ� �Ѵ�.
	if (prevItemList.size() == 1)
	{
		Item::ItemClass IClass      = pItem->getItemClass();
		ItemType_t      IType       = pItem->getItemType();

		Item*           pInvenItem  = prevItemList.front();
		Item::ItemClass InvenIClass = pInvenItem->getItemClass();
		ItemType_t      InvenIType  = pInvenItem->getItemType();

		// �������� ����� �ٸ� ���̶��� �翬�� false��.
		if (IClass != InvenIClass || IType != InvenIType) return false;
		
		// ���� �� �ִ� �������� �ƴϾ��ٸ� �翬�� false��.
		if (!isStackable(pItem)) return false;

		// ������ �Ѿ �翬�� false��.
		uint MaxStack = ItemMaxStack[IClass];
		if ((pItem->getNum() + pInvenItem->getNum()) > (int)(MaxStack)) return false;
	}

	prevItemList.clear();

	return true;

	__END_CATCH
}






////////////////////////////////////////////////////////////////////////////////
//
// ADDITION & DELETION RELATED METHODS
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// ����� �ġ�� ������� ���Ѵ�.
////////////////////////////////////////////////////////////
bool Inventory::addItem(CoordInven_t X, CoordInven_t Y, Item* pItem)
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	if (pItem == NULL)
	{
		//cerr << "Inventory::addItem() : ������ �����Ͱ� ���Դϴ�." << endl;
		return false;
	}
	
    VolumeWidth_t  ItemWidth  = pItem->getVolumeWidth();
    VolumeHeight_t ItemHeight = pItem->getVolumeHeight();
	Weight_t       ItemWeight = pItem->getWeight();
			
	// ������� ���ϱ� ���� Ȯ��� �Ѵ�.
	for (int x = X; x < X + ItemWidth ; x++) 
		for (int y = Y; y < Y + ItemHeight ; y++) 
			if (getInventorySlot(x, y).getItem() != NULL) return false;

	// Add Item to Inventory
	for (int x = X; x < X + ItemWidth ; x++) 
	{
		for (int y = Y; y < Y + ItemHeight ; y++) 
		{
			InventorySlot& slot = getInventorySlot(x, y);
			slot.addItem(pItem);
		}
	}
	
	// ������ ������ŭ ���Ը� ���ϰ�, ������ ���Ѵ�.
	m_TotalWeight += (ItemWeight* pItem->getNum());	
	m_TotalNum    += pItem->getNum();

	return true;

	__END_DEBUG
	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� �ġ�� ������� ���Ѵ�.
////////////////////////////////////////////////////////////
Item* Inventory::addItemEx(CoordInven_t X, CoordInven_t Y, Item* pItem)
	throw(Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	if (!canAddingEx(X, Y, pItem)) 
	{
		//cerr << "Inventory::addItemEx() : canAddingExCheck failed!!!" << endl;
		//cerr << toString() << endl;
		throw Error("Inventory::addItemEx() : ������� ���� �� ����ϴ�!");
	}

	VolumeWidth_t   ItemWidth  = pItem->getVolumeWidth();
	VolumeHeight_t  ItemHeight = pItem->getVolumeHeight();
	Item*           pInvenItem = m_pInventorySlot[X][Y].getItem();

	// �������� ����Ѵٸ� ���� �� �ִ� �������̱�
	// ������, ���ڸ� ������ �ش�.
	if (pInvenItem != NULL)
	{
		pInvenItem->setNum(pItem->getNum()+pInvenItem->getNum());

		// �����͸� ����ϱ⿡ �ռ�, ���Կ� ������ ���ڸ� �������ش�.
		m_TotalWeight += (pItem->getWeight()* pItem->getNum());
		m_TotalNum    += pItem->getNum();

		// �κ��丮 �������� ī��Ʈ�� ��������ϱ�, 
		// ���϶��� �� ������� ������ش�.
		// *** ������ ����� �߾��µ�, 
		// �ƹ����� �̻��ؼ�, �ϴ�� �׳� ���д�. ***
		//SAFE_DELETE(pItem);
		//pItem = NULL;
		return pInvenItem;
	}

	for (int x=X; x<X+ItemWidth; x++)
	{
		for (int y=Y; y<Y+ItemHeight; y++)
		{
			// �������� ���ٸ�...���� ���Կ��ٰ� ��� �����͸� �Ҵ��� �ش�.
			m_pInventorySlot[x][y].addItem(pItem);
		}
	}

	m_TotalWeight += (pItem->getWeight()* pItem->getNum());
	m_TotalNum    += pItem->getNum();

	return pItem;

	__END_DEBUG
	__END_CATCH
}

////////////////////////////////////////////////////////////
// ������� �˾Ƽ� ���Ѵ�.
////////////////////////////////////////////////////////////
bool Inventory::addItem(Item* pItem)
	throw(InventoryFullException , Error)
{
	__BEGIN_TRY

	Assert (pItem != NULL);

	_TPOINT pt;

	if (getEmptySlot(pItem, pt))
	{
		addItem(pt.x, pt.y, pItem);
		return true;
	}

	return false;

	__END_CATCH
}

////////////////////////////////////////////////////////////
// ������� �˾Ƽ� ���Ѵ�.
////////////////////////////////////////////////////////////
bool Inventory::addItem(Item* pItem, TPOINT& rpt)
	throw(InventoryFullException , Error)
{
	__BEGIN_TRY

	Assert (pItem != NULL);

	_TPOINT pt;

	if (getEmptySlot(pItem, pt))
	{
		rpt.x = pt.x;
		rpt.y = pt.y;
		addItem(pt.x, pt.y, pItem);
		return true;
	}

	rpt.x = 255;
	rpt.y = 255;

	return false;

	__END_CATCH
}

////////////////////////////////////////////////////////////
// ������� ��� �� �ִ� �� �ڸ��� ã�´�.
////////////////////////////////////////////////////////////
bool Inventory::getEmptySlot(VolumeWidth_t ItemWidth, VolumeHeight_t ItemHeight, _TPOINT& p)
	throw()
{
	__BEGIN_TRY

	int x, y;
	int i, j;

	//---------------------------------------------------------
	// grid�� ����(x,y)�� pItem� �߰��� �� �ִ��� �˻��غ���.
	//---------------------------------------------------------
	int yLimit = m_Height - ItemHeight;
	int xLimit = m_Width  - ItemWidth;

	int yPlusHeight, xPlusWidth;

	for (x = 0; x <= xLimit; x++)
	{
		xPlusWidth = x + ItemWidth;

		for (y = 0; y <= yLimit; y++)
		{           
			yPlusHeight = y + ItemHeight;

			//---------------------------------------------------------
			// (x,y)�� ��� �� �ִ��� üũ..
			//---------------------------------------------------------
			bool bPlace = true;

			for (i = y; bPlace && i < yPlusHeight; i++)
			{
				for (j = x; bPlace && j < xPlusWidth; j++)
				{
					//---------------------------------------------------------
					// �̹� �ٸ� Item�� �ִ� grid�� �ϳ����� �ִٸ� �߰��� �� ����.
					//---------------------------------------------------------
					Item* pItem = m_pInventorySlot[j][i].getItem();
					if (pItem != NULL)
					{
						bPlace = false;

						// ����� üũ�� ��...
				//		y = i + pItem->getVolumeHeight() - 1;

						break;
					}
				}
			}

			//---------------------------------------------------------
			// (x,y)�� ��� �� �ִ� ����
			//---------------------------------------------------------
			if (bPlace)
			{
				p.x = x; 
				p.y = y;

				//cout << (int)x << ", " << (int)y << " ]" << endl;
				return true;
			}
		}
	}

	return false;

	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� ������� ã�Ƽ� ������.
////////////////////////////////////////////////////////////
void Inventory::deleteItem(ObjectID_t ObjectID)
	throw(Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Item*        pTargetItem = NULL;
	CoordInven_t x           = 0;
	CoordInven_t y           = 0;

	pTargetItem = findItemOID(ObjectID, x, y);

	if (pTargetItem != NULL)
	{
		deleteItem(x, y);
	}
	else Assert(false);

	__END_DEBUG
	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� �ġ���� ������� ������.
// *** ���� *** 
// 1x1 �������� �ƴ� ����, ���� ������ ��ǥ�� ���������
// ����� ������ ������ �߻��� �� �ִ�.
////////////////////////////////////////////////////////////
void Inventory::deleteItem(CoordInven_t X, CoordInven_t Y)
	throw(Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	if (X < m_Width && Y < m_Height)
	{
		Item* pItem = m_pInventorySlot[X][Y].getItem();
		//Assert(pItem != NULL);

		if (pItem != NULL)
		{
			// get Volume's Size Width, Height
			VolumeWidth_t  ItemWidth  = pItem->getVolumeWidth();
			VolumeHeight_t ItemHeight = pItem->getVolumeHeight();

			Assert(ItemWidth != 0);
			Assert(ItemHeight != 0);

			for (int x = X; x < X + ItemWidth ; x++) 
			{
				for (int y = Y; y < Y + ItemHeight ; y++) 
				{
					InventorySlot& slot = getInventorySlot(x, y);

					//if (slot.getItem()==pItem)
					{
						slot.deleteItem();
					}
					/*
					// �ٸ� �������. - -;
					// Restore���� �����̾� ������ ���� ���⸦ �ϳ� üũ�� ���ؼ� �׷���.
					// by sigi. 2002.8.29 ��
					else
					{
						// �κ��丮�� ���� �̻��� ������ �ִٰ� �������Ƿ�
						// �ϴ� �ٿ� ����� ���� ��ؼ�..
						// ��ü�� �˻��ؼ� ������� ������.
						// by sigi. 2002.8.29
						filelog("inventoryDeleteBug.txt", "deleteItem(%d, %d): class=%d, type=%d, volume(%d, %d), Wrong Item. (%d, %d) ",
								(int)X, (int)Y, (int)pItem->getItemClass(), (int)pItem->getItemType(), (int)ItemWidth, (int)ItemHeight, (int)x, (int)y);

						// ��ü �˻��ؼ� pItem� ������.
						for (int a=0; a<m_Width; a++)
						{
							for (int b=0; b<m_Height; b++)
							{
								InventorySlot& tempSlot = getInventorySlot(a, b);

								if (tempSlot.getItem()==pItem)
								{
									slot.deleteItem();

									filelog("inventoryDeleteBug.txt", 
											"delete another position(%d, %d)",
											a, b);
								}
							}
						}
					}
					*/
				}
			}

			m_TotalWeight -= (pItem->getWeight()* pItem->getNum());
			m_TotalNum    -= pItem->getNum();
		}
		else
		{
		}
	}

	__END_DEBUG
	__END_CATCH
}






////////////////////////////////////////////////////////////////////////////////
//
// FIND METHODS
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// X, Y�κ��� �������� ũ�⸸ŭ�� ����� �˻��Ͽ�,
// ����ϴ� �������� ����� �� �����͸� �����Ѵ�.
////////////////////////////////////////////////////////////
Item* Inventory::searchItem(CoordInven_t X, CoordInven_t Y, Item* pItem, TPOINT & pt)
	throw()
{
	__BEGIN_TRY

	// get Volume's Size Width, Height
	VolumeWidth_t  ItemWidth  = pItem->getVolumeWidth();
	VolumeHeight_t ItemHeight = pItem->getVolumeHeight();

	if ((X + ItemWidth <= m_Width) && (Y + ItemHeight <= m_Height)) 
	{
		for (int x = X; x < (X + ItemWidth); x++) 
		{
			for (int y = Y; y < (Y + ItemHeight); y++) 
			{
				if (hasItem(x, y)) 
				{
					pt.x = x;
					pt.y = y;
					return m_pInventorySlot[x][y].getItem();
				}
			}
		}
	}

	return NULL;

	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� ������� ã�Ƽ� �����͸� �����Ѵ�.
////////////////////////////////////////////////////////////
Item* Inventory::getItemWithItemID (ItemID_t itemID)
	throw (Error)
{
	__BEGIN_TRY

	CoordInven_t x, y;	
	return findItemIID(itemID, x, y);

	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� ��Ʈ�� ã�Ƽ� �����͸� �����Ѵ�.
////////////////////////////////////////////////////////////
Item* Inventory::getBeltWithItemID(ItemID_t itemID)
	throw (Error)
{
	__BEGIN_TRY

	CoordInven_t x, y;
	return findItemIID(itemID, Item::ITEM_CLASS_BELT, x, y);

	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� ������� ã�Ƽ� �����͸� �����Ѵ�.
////////////////////////////////////////////////////////////
Item* Inventory::getItemWithObjectID(ObjectID_t objectID)
	throw (Error)
{
	__BEGIN_TRY

	CoordInven_t x, y;
	return findItemOID(objectID, x, y);

	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� ������� ã�Ƽ� �����͸� �����Ѵ�.
// �̿� �Բ� �� �������� ���� ���� ��ǥ�� ���� �����ش�.
////////////////////////////////////////////////////////////
Item* Inventory::findItemOID(ObjectID_t id, CoordInven_t& X, CoordInven_t& Y)
	throw()
{
	__BEGIN_TRY

	for (int j=0; j<m_Height; j++)
	{
		for (int i=0; i<m_Width; i++)
		{
			InventorySlot& slot  = getInventorySlot(i, j);
			Item*          pItem = slot.getItem();

			if (pItem != NULL && pItem->getObjectID() == id)
			{
				X = i;
				Y = j;
				return pItem;
			}
		}
	}
	
	return NULL;

	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� ������� ã�Ƽ� �����͸� �����Ѵ�.
// �̿� �Բ� �� �������� ���� ���� ��ǥ�� ���� �����ش�.
////////////////////////////////////////////////////////////
Item* Inventory::findItemIID(ItemID_t id, CoordInven_t& X, CoordInven_t& Y)
	throw()
{
	__BEGIN_TRY

	for (int y=0; y<m_Height; y++)
	{
		for (int x=0; x<m_Width; x++)
		{
			InventorySlot& slot  = getInventorySlot(x, y);
			Item*          pItem = slot.getItem();

			if (pItem != NULL && pItem->getItemID() == id)
			{
				X = x;
				Y = y;
				return pItem;
			}
		}
	}
	
	return NULL;

	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� id�� Ŭ������ ������� ã�Ƽ� �����͸� �����Ѵ�.
// �̿� �Բ� �� �������� ���� ���� ��ǥ�� ���� �����ش�.
////////////////////////////////////////////////////////////
Item* Inventory::findItemOID(ObjectID_t id, Item::ItemClass IClass, CoordInven_t& X, CoordInven_t& Y)
	throw()
{
	__BEGIN_TRY

	for (int j=0; j<m_Height; j++)
	{
		for (int i=0; i<m_Width; i++)
		{
			InventorySlot& slot  = getInventorySlot(i, j);
			Item*          pItem = slot.getItem();

			if (pItem != NULL && 
				pItem->getItemClass() == IClass && pItem->getObjectID() == id)
			{
				X = i;
				Y = j;
				return pItem;
			}
		}
	}
	
	return NULL;

	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� id�� Ŭ������ ������� ã�Ƽ� �����͸� �����Ѵ�.
// �̿� �Բ� �� �������� ���� ���� ��ǥ�� ���� �����ش�.
////////////////////////////////////////////////////////////
Item* Inventory::findItemIID(ItemID_t id, Item::ItemClass IClass, CoordInven_t& X, CoordInven_t& Y)
	throw()
{
	__BEGIN_TRY

	for (int y=0; y<m_Height; y++)
	{
		for (int x=0; x<m_Width; x++)
		{
			InventorySlot& slot  = getInventorySlot(x, y);
			Item*          pItem = slot.getItem();

			if (pItem != NULL && 
				pItem->getItemClass() == IClass && pItem->getItemID() == id)
			{
				X = x;
				Y = y;
				return pItem;
			}
		}
	}
	
	return NULL;

	__END_CATCH
}

/////////////////////////////////////////////////////////////////////////////////////
// findItem
//    : ItemClass
//  Desctiption: �ش� �κ��丮�� Ư� Item Class�� �������� ����ϴ� �� üũ�Ѵ�.
//               ���� �����͸� �׿�� ���� ��Ÿ���� ������� ��ȯ�ϱ� ��ؼ� 
//               �� ������ ������ �ִ� Ư� Item Class�� ������� ��ȯ�Ѵ�.
//
//  2002.09.04 ��ȫâ 
/////////////////////////////////////////////////////////////////////////////////////

Item* Inventory::findItem(Item::ItemClass IClass, ItemType_t itemType)//, CoordInven_t& X, CoordInven_t& Y)
	throw()
{
	__BEGIN_TRY

	for (int y=0; y<m_Height; y++)
	{
		for (int x=0; x<m_Width; x++)
		{
			InventorySlot& slot  = getInventorySlot(x, y);
			Item*          pItem = slot.getItem();

			if (pItem != NULL && 
				pItem->getItemClass() == IClass 
				&& (itemType==0xFFFF || pItem->getItemType() == itemType))
			{
				//X = x;
				//Y = y;
				return pItem;
			}
		}
	}
	
	return NULL;

	__END_CATCH
}

Item* Inventory::findItem(Item::ItemClass IClass, ItemType_t itemType, CoordInven_t& X, CoordInven_t& Y)
	throw()
{
	__BEGIN_TRY

	for (int y=0; y<m_Height; y++)
	{
		for (int x=0; x<m_Width; x++)
		{
			InventorySlot& slot  = getInventorySlot(x, y);
			Item*          pItem = slot.getItem();

			if (pItem != NULL && 
				pItem->getItemClass() == IClass 
				&& (itemType==0xFFFF || pItem->getItemType() == itemType))
			{
				X = x;
				Y = y;
				return pItem;
			}
		}
	}
	
//	X = -1;
//	Y = -1;
	return NULL;

	__END_CATCH
}



////////////////////////////////////////////////////////////////////////////////
//
// ITEM MANIPULATION RELATED METHODS
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// ����� �ġ�� ������ �����͸� �����Ѵ�.
////////////////////////////////////////////////////////////
Item* Inventory::getItem(CoordInven_t X, CoordInven_t Y) const 
	throw()
{
	__BEGIN_TRY

	InventorySlot& slot = getInventorySlot(X, Y);
	return slot.getItem();

	__END_CATCH
}

////////////////////////////////////////////////////////////
// ����� �ġ�� ������ �����͸� �������ش�.
////////////////////////////////////////////////////////////
void Inventory::setItem(CoordInven_t X, CoordInven_t Y, Item* pItem)
	throw()
{
	__BEGIN_TRY

	InventorySlot& slot = getInventorySlot(X, Y);
	slot.addItem(pItem);

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// 
// PACKING RELATED METHODS
// 
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// �κ��丮���� ������ ������ ���θ� ����Ѵ�.
// ����� ������ ��ü�� �������� �ʴ´�.
////////////////////////////////////////////////////////////
void Inventory::clear()
	throw ()
{
	__BEGIN_TRY

	// �κ��丮 ��ü�� �޿� �˻��ϸ鼭...
	for (int y=0; y<m_Height; y++)
	{
		for (int x=0; x<m_Width; x++)
		{
			InventorySlot& slot = getInventorySlot(x, y);
			slot.deleteItem();
		}
	}

	m_TotalNum    = 0;
	m_TotalWeight = 0;

	__END_CATCH
}

////////////////////////////////////////////////////////////
// �κ��丮�� �����ִ� ������� ����Ʈ�� ����� �����Ѵ�.
////////////////////////////////////////////////////////////
list<Item*> Inventory::getList() const
	throw()
{
	__BEGIN_TRY

	list<Item*> itemList;

	for (int x=0; x<m_Width; x++)
	{
		for (int y=0; y<m_Height;y++)
		{
			InventorySlot& slot  = getInventorySlot(x, y);
			Item*          pItem = slot.getItem();
			bool           bAdd  = true;

			// �������� �ִٸ� ������ ����Ʈ�� 
			// �̹� ��� ������ ����� üũ�� �ؾ� �Ѵ�.
			if (pItem != NULL)
			{
				// ����Ʈ�� ��� ���� �ִ��� üũ�� �Ѵ�.
				list<Item*>::iterator itr = itemList.begin();
				for (; itr != itemList.end(); itr++)
				{
					if (*itr == pItem) 
					{
						bAdd = false;
						break;
					}
				}

				// ����Ʈ�� �Ȱ�� �������� �����ٸ� ����Ʈ���ٰ� ���Ѵ�.
				if (bAdd)
				{
					itemList.push_back(pItem);
					y += pItem->getVolumeHeight() - 1;
					continue;
				}
			}
		}
	}

	return itemList;

	__END_CATCH
}

////////////////////////////////////////////////////////////
// �κ��丮 �ȿ� ���� �ִ� 2x2 �������� ������ �����Ѵ�.
////////////////////////////////////////////////////////////
int Inventory::calc2x2Item(void) const
	throw()
{
	__BEGIN_TRY

	int rValue = 0;
	list<Item*> itemList = getList();

	list<Item*>::const_iterator itr = itemList.begin();
	for (; itr != itemList.end(); itr++)
	{
		Item* pItem = (*itr);
		if (pItem->getVolumeWidth()  == 2 && 
			pItem->getVolumeHeight() == 2) rValue += 1;
	}

	return rValue;

	__END_CATCH
}


////////////////////////////////////////////////////////////////////////////////
//
// MISC METHODS
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
void Inventory::save(const string& owner) 
	throw()
{
	__BEGIN_TRY

	list<Item*> itemList;

	for (int x=0; x<m_Width; x++)
	{
		for (int y=0; y<m_Height;y++)
		{
			InventorySlot& slot  = getInventorySlot(x, y);
			Item*          pItem = slot.getItem();
			bool           bAdd  = true;

			// �������� �ִٸ� ������ ����Ʈ�� 
			// �̹� ��� ������ ����� üũ�� �ؾ� �Ѵ�.
			if (pItem != NULL)
			{
				// ����Ʈ�� ��� ���� �ִ��� üũ�� �Ѵ�.
				list<Item*>::iterator itr = itemList.begin();
				for (; itr != itemList.end(); itr++)
				{
					if (*itr == pItem) 
					{
						bAdd = false;
						break;
					}
				}

				// ����Ʈ�� �Ȱ�� �������� �����ٸ� ����Ʈ���ٰ� ���Ѵ�.
				// ��Ʈ�� ���쿡�� Belt::save���� �ȿ� �����ִ� �����۱���
				// �����ϴϱ�, ����� �ʿ�����.
				if (bAdd)
				{
					pItem->save(owner, STORAGE_INVENTORY, 0, x, y);
					itemList.push_back(pItem);
					//y += pItem->getVolumeHeight() - 1;
				}
			}
		}
	}

	__END_CATCH
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
string Inventory::toString () const 
	throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "Inventory(" << "\n";
	msg	<< "Owner:" << m_Owner << "\n";

	for (int y=0; y<m_Height; y++)
	{
		for (int x=0; x<m_Width; x++)
		{
			InventorySlot& slot  = getInventorySlot(x, y);
			Item*          pItem = slot.getItem();

			if (pItem != NULL)
			{
				msg << pItem->getNum();
			}
		}

		msg << "\n";
	}

	msg << "\n";
	msg << ")";

	return msg.toString();

	__END_CATCH
}


///////////////////////////////////////////////////////////////////////////
// XMAS �̺�Ʈ�� ��ؼ� ���� ������ �̺�Ʈ �� ���� �ڵ��̴�.
// 2002�� ��̳��� �� �ڵ带 �״��� �����ϱ� ��ؼ� 
// �ּ�� ����ϰ� �����Ͽ���. 
// �� ��� �̺�Ʈ�� �����ؼ� �߻��� �� �ֱ� ������,
// EVENT CODE�� �̸�� XMAS�� �ƴ϶� STAR_EVENT_CODE�� �ٲٴ� ��� �����ؾ�
// �� ���̴�.
// 
// 2002.5.2 ��ȫâ(changaya@metrotech.co.kr
//
//////////////////////////////////////////////////////////////////////////
//#ifdef __XMAS_EVENT_CODE__
// �κ��丮�� �˻��ϸ鼭 ���򺰷� �̺�Ʈ �� ���ڸ� ���Ƹ���.
bool Inventory::hasEnoughStar(const XMAS_STAR& star)
	throw (Error)
{
	__BEGIN_TRY

	//cout << "�ʿ��� ���� ���� : " << star.amount << endl;
	
	int amount[STAR_COLOR_MAX];
	memset(amount, 0, sizeof(int)*STAR_COLOR_MAX);

	for (int i=0; i<STAR_COLOR_MAX; i++)
		amount[i] = 0;

	for (int y=0; y<m_Height; y++)
	{
		for (int x=0; x<m_Width; x++)
		{
			InventorySlot& slot  = getInventorySlot(x, y);
			Item*          pItem = slot.getItem();

			if (pItem != NULL && pItem->getItemClass() == Item::ITEM_CLASS_EVENT_STAR)
			{
				int ItemNum =  pItem->getNum();
				//cout << pItem->getItemType() << " " << ItemNum << endl;
				switch (pItem->getItemType())
				{
					case 0: amount[STAR_COLOR_BLACK] += ItemNum; break;
					case 1: amount[STAR_COLOR_RED]   += ItemNum; break;
					case 2: amount[STAR_COLOR_BLUE]  += ItemNum; break;
					case 3: amount[STAR_COLOR_GREEN] += ItemNum; break;
					case 4: amount[STAR_COLOR_CYAN]  += ItemNum; break;
					case 5: amount[STAR_COLOR_WHITE] += ItemNum; break;
					case 6: amount[STAR_COLOR_PINK]  += ItemNum; break;
					default: Assert(false); break;
				}
			}
		}
	}

	//cout << star.color << endl;
	//cout << "������ �ִ� ���� ����: " << amount[star.color] << endl;

	if (amount[star.color] >= star.amount) return true;

	return false;

	__END_CATCH
}
//#endif

//#ifdef __XMAS_EVENT_CODE__
void Inventory::decreaseStar(const XMAS_STAR& star)
	throw (Error)
{
	__BEGIN_TRY

	// �ٿ��� �� ��� ������ �д�.
	int  amount = star.amount;

	for (int y=0; y<m_Height; y++)
	{
		for (int x=0; x<m_Width; x++)
		{
			InventorySlot& slot  = getInventorySlot(x, y);
			Item*          pItem = slot.getItem();

			if (pItem != NULL && pItem->getItemClass() == Item::ITEM_CLASS_EVENT_STAR)
			{
				ItemType_t IType = pItem->getItemType();
				cout << IType << " " << star.color << endl;

				if ((IType == 0 && star.color == STAR_COLOR_BLACK) ||
					(IType == 1 && star.color == STAR_COLOR_RED)   ||
					(IType == 2 && star.color == STAR_COLOR_BLUE)  ||
					(IType == 3 && star.color == STAR_COLOR_GREEN) ||
					(IType == 4 && star.color == STAR_COLOR_CYAN)  ||
					(IType == 5 && star.color == STAR_COLOR_WHITE) ||
					(IType == 6 && star.color == STAR_COLOR_PINK))
				{
					int ItemNum = pItem->getNum();

					// �������� ���� ���ڰ� �ٿ��� �� �纸�� �۰ų� ���ٸ�,
					// ������� ����ؾ� �Ѵ�.
					if (ItemNum <= amount)
					{
						m_TotalWeight -= (pItem->getWeight() * ItemNum);
						m_TotalNum -= ItemNum;

						// �������� ����ȸ�ŭ ������ �� �絵 �ٿ����� �Ѵ�. 
						amount = amount - ItemNum;

						// ������� ������ش�.
						deleteItem(x, y);
						pItem->destroy();
						SAFE_DELETE(pItem);
					}
					else
					{
						m_TotalWeight -= (pItem->getWeight() * amount);
						m_TotalNum -= amount;

						pItem->setNum(ItemNum - amount);
						pItem->save(m_Owner, STORAGE_INVENTORY, 0, x, y);

						// �������� ����ȸ�ŭ ������ �� �絵 �ٿ����� �Ѵ�. 
						amount = 0;
					}

					// �ٿ��� �� ���� 0�� �Ǿ��ٸ� �����Ѵ�.
					if (amount == 0) return;
				}
			}
		}
	}

	// ������� ó�� �������� �� ������ ��� �� �ȴ�.
	Assert(false);

	__END_CATCH
}
//#endif


///*
//#ifdef __XMAS_EVENT_CODE__
bool Inventory::hasRedGiftBox(void) 
	throw (Error)
{
	__BEGIN_TRY

	for (int y=0; y<m_Height; y++)
	{
		for (int x=0; x<m_Width; x++)
		{
			InventorySlot& slot  = getInventorySlot(x, y);
			Item*          pItem = slot.getItem();

			if (pItem != NULL && pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX && pItem->getItemType() == 1)
			{
				return true;

				// ���� ������ ũ�Ⱑ 2x2�̱� ������,
				// x�� �ϳ� �� �����ش�.
				x += 1;
			}
		}
	}

	return false;

	__END_CATCH
}
//#endif
//*/

///*
//#ifdef __XMAS_EVENT_CODE__
bool Inventory::hasGreenGiftBox(void) 
	throw (Error)
{
	__BEGIN_TRY

	for (int y=0; y<m_Height; y++)
	{
		for (int x=0; x<m_Width; x++)
		{
			InventorySlot& slot  = getInventorySlot(x, y);
			Item*          pItem = slot.getItem();

			if (pItem != NULL && pItem->getItemClass() == Item::ITEM_CLASS_EVENT_GIFT_BOX && pItem->getItemType() == 0)
			{
				return true;

				// ���� ������ ũ�Ⱑ 2x2�̱� ������,
				// x�� �ϳ� �� �����ش�.
				x += 1;
			}
		}
	}

	return false;

	__END_CATCH
}
//#endif
//*/

void Inventory::clearQuestItem(list<Item*>& iList) throw(Error)
{
	{
		list<Item*> ItemList;
		int height = getHeight();
		int width  = getWidth();

		for (int j=0; j<height; j++)
		{
			for (int i=0; i<width; i++)
			{
				Item* pItem = getItem(i, j);
				if (pItem != NULL)
				{
					// üũ�� �������� ����Ʈ���� ���� ������� ã�´�.
					list<Item*>::iterator itr = find(ItemList.begin(), ItemList.end(), pItem);

					if (itr == ItemList.end())
					{
						i += pItem->getVolumeWidth() - 1;

						if ( pItem->isQuestItem() )
						{
							deleteItem( pItem->getObjectID() );
							iList.push_back(pItem);
						}
						else
						{
							// ����Ʈ�� �������� �����
							// ��� ������� �ι� üũ���� �ʱ� ��ؼ�
							// ����Ʈ���ٰ� ������� �����ִ´�.
							ItemList.push_back(pItem);
						}
					}
				}
			}
		}
	}
}
