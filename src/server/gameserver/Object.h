//////////////////////////////////////////////////////////////////////////////
// Filename    : Object.h
// Written By  : Elca
// Description : ���� Ŭ������ �ֻ�� Ŭ�����̴�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Types.h"
#include "Exception.h"
#include "Assert.h"

//////////////////////////////////////////////////////////////////////////////
// Object Priority
//
// Ÿ���� Object List ���� �� Object ��� Ŭ���� ��ü�鰣�� �켱����� 
// ��Ÿ����. ���� ��� ���� �켱����� �����, Ÿ���� Object List ����
// ���� ���ʿ� ��ġ�Ǿ��� �Ѵ�.
//
// �켱����� ���� Ȱ������, �� ���� �̵����� ��� ��ü���� �켱 �����
// ���� ����Ǿ��� �Ѵ�. �̴� Ÿ���� Object List �� list �� �����Ǹ�,
// list �� ���ʿ��� insert/delete �� �ð��� ª�� �����̴�.
//////////////////////////////////////////////////////////////////////////////
enum ObjectPriority 
{
	OBJECT_PRIORITY_WALKING_CREATURE ,
	OBJECT_PRIORITY_FLYING_CREATURE ,
	OBJECT_PRIORITY_BURROWING_CREATURE ,
	OBJECT_PRIORITY_EFFECT ,
	OBJECT_PRIORITY_ITEM ,
	OBJECT_PRIORITY_PORTAL ,
	OBJECT_PRIORITY_OBSTACLE ,
	OBJECT_PRIORITY_NONE					// Ÿ�Ͽ� ����Ʈ�� �ƴ� ����
};

//////////////////////////////////////////////////////////////////////////////
// class Object
// ���� ���� Ŭ������ �ֻ�� Ŭ�����̴�.
//////////////////////////////////////////////////////////////////////////////

class Object 
{
public:
	// Object Class
	// Object ��� Ŭ�������� �з��� ��Ÿ����. Object �� ��� ���ӹ�� 
	// Ŭ�����鿡 ���ؼ� ObjectClass �� �߰��ϸ� �ǰڴ�.
	enum ObjectClass 
	{
		OBJECT_CLASS_CREATURE,
		OBJECT_CLASS_ITEM,
		OBJECT_CLASS_OBSTACLE,
		OBJECT_CLASS_EFFECT,
		OBJECT_CLASS_PORTAL
	};

public:
	Object(ObjectID_t objectID = 0) throw() : m_ObjectID(objectID) {}
	virtual ~Object() {}
	
public:
	// get/set object id
	//
	// � �������� unique �� ��ü�� ������(identifier)�� �����ȴ�.
	// ���� ���� ���� �������� unique �ص� �Ǳ� ������, ��� �ð�����
	// ���� ������ reboot ���� ��� ���� �ƹ��� 4G �� �������� ��ü��
	// id �� �ߺ��� ����� �־ ����� � ������ ����ߴ�. 
	// �̷��� �ϸ� �ʴ� 1000 ���� ��ü�� ���� �����ٰ� �������� 4M ��,
	// �� 40-50�ϵ��� �����ϴٴ� ���̴�.
	ObjectID_t getObjectID() const throw(Error) { Assert(m_ObjectID != 0); return m_ObjectID; };
	void setObjectID(ObjectID_t objectID) throw(Error) { Assert(objectID != 0); m_ObjectID = objectID; }

	// get object class(virtual)
	// Object* pObject �� ���ؼ� �� ��ü�� ũ��ó����, ����������, �ƴϸ�
	// ���ֹ������� ���캼 �� �����Ѵ�. ��� Ŭ������ �� �޽��带 ������ؾ��Ѵ�.
	//
	// *CAUTION*
	// ���� Object�� m_ObjectClass ����Ÿ ������ �ֵ� ������, �̷��� �ϸ� 
	// �����Ϸ��� ��� ����� ���� ���� Object ��� Ŭ������ ��ü���� �߰�����
	// ����Ʈ�� �Ҹ��ϰ� �ǹǷ�, virtual method �� �ذ��ߴ�.
	virtual ObjectClass getObjectClass() const throw() = 0;

	// get object priority(virtual)
	virtual ObjectPriority getObjectPriority() const throw(Error) = 0;

	// get debug string
	virtual string toString() const throw() = 0;

protected:
	ObjectID_t m_ObjectID; // Object ID

};

//////////////////////////////////////////////////////////////////////////////
// function object
//////////////////////////////////////////////////////////////////////////////
class isSameObjectID 
{
public:
    isSameObjectID(ObjectID_t objectID) : m_ObjectID(objectID) {}
 
    bool operator()(Object* pObject) throw()
    {
        return pObject->getObjectID() == m_ObjectID;
    }
 
private:
    ObjectID_t m_ObjectID;
};

#endif
