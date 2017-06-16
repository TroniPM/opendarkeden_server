//////////////////////////////////////////////////////////////////////////////
/// \file XML.h
/// \author excel96
/// \date 2003.7.25
///
/// \todo
/// \bug
/// \warning
//////////////////////////////////////////////////////////////////////////////

//#pragma once
#ifndef __SXML_H__
#define __SXML_H__

#include "Types.h"

#include <map>
#include <vector>
#include <string>
#include <fstream>

//////////////////////////////////////////////////////////////////////////////
/// \class XMLAttribute
/// \brief 
//////////////////////////////////////////////////////////////////////////////
class XMLAttribute
{
private:
	string	m_Name;
	string	m_Value;

public:
	XMLAttribute( const string &name, const string &value );
	virtual ~XMLAttribute();

	void	SetValue( string value );

	const char*		GetName() const;
	const char*		ToString() const;
	const int		ToInt() const;
	const DWORD		ToHex() const;
	const bool		ToBool() const;
	const double	ToDouble() const;
	const float		ToFloat() const;
};


//////////////////////////////////////////////////////////////////////////////
/// \class XMLTree
/// \brief 
//////////////////////////////////////////////////////////////////////////////

class XMLTree
{
private:
	typedef map<string, XMLAttribute *> ATTRIBUTES_MAP;
	typedef vector<XMLAttribute *> ATTRIBUTES_VECTOR;
	
	typedef map<string, XMLTree*> CHILDREN_MAP;
	typedef vector<XMLTree *> CHILDREN_VECTOR;

	string     m_Name;        ///< ������ �̸�
	string     m_Text;        ///< ���忡 ���� �ؽ�Ʈ
	XMLTree*   m_pParent;     ///< �θ� ������ ������

	ATTRIBUTES_MAP m_AttributesMap;  ///< ������ �ִ� �Ӽ�����
	ATTRIBUTES_VECTOR m_AttributesVector;  ///< ������ �ִ� �Ӽ�����
	CHILDREN_MAP   m_ChildrenMap;    ///< �ڽ� ������
	CHILDREN_VECTOR   m_ChildrenVector;    ///< �ڽ� ������

public:
	XMLTree();
	XMLTree( const string& name );
	virtual ~XMLTree();

public:
	const string& GetName() const;
	void SetName( const string& name );

	const string& GetText() const;
	void SetText( const string& text );


	const XMLTree* GetParent() const;
	void SetParent( XMLTree* pParent );

	void AddAttribute( const string& name, const string& value );
	void AddAttribute( const string& name, const char * value );
	void AddAttribute( const string& name, const int& value );
	void AddAttribute( const string& name, const unsigned int& value, const bool bHex = false );
	void AddAttribute( const string& name, const DWORD& value, const bool bHex = false );
	void AddAttribute( const string& name, const float& value );
	void AddAttribute( const string& name, const double& value );
	void AddAttribute( const string& name, const bool& value );

	XMLAttribute *GetAttribute( const string& name ) const;

	const bool GetAttribute( const string& name, string &value );
	const bool GetAttribute( const string& name, int &value );
	const bool GetAttribute( const string& name, unsigned int &value, const bool bHex = false );
	const bool GetAttribute( const string& name, DWORD &value, const bool bHex = false );
	const bool GetAttribute( const string& name, float &value );
	const bool GetAttribute( const string& name, double &value );
	const bool GetAttribute( const string& name, bool &value );

	XMLTree* AddChild( const string& name );
	XMLTree* AddChild( XMLTree* pChild );
	XMLTree* GetChild( const string& name ) const;
	XMLTree* GetChild( size_t index ) const;
	const size_t GetChildCount() const;

	void Release();

	void SaveToFile(const char* pFilename);

	void LoadFromFile( const char *pFilename );
	void LoadFromMem( const char *pBuffer );

private:
	void Save(ofstream& file, size_t indent);
};

#endif
