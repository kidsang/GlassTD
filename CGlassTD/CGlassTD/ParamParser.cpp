#include "ParamParser.h"

bool ParamParser::parse()
{
	TiXmlDocument doc(mFileName.c_str());
	if (!doc.LoadFile())
		return false;

	TiXmlHandle hDoc(&doc);
	TiXmlElement* elem = 0;
	TiXmlElement* root = 0;
	TiXmlAttribute* attr = 0;

	// ���ڵ�
	root = hDoc.FirstChildElement().Element();
	if (!root)
		return false;

	// ÿ���ӽڵ�
	elem = root->FirstChildElement();
	if (!elem)
		return false;

	// ����entry
	do 
	{
		// ÿ���ӽڵ���ζ�Ŷ���һ��entry
		NameValueList* nvl = new NameValueList();
		mEntryList.push_back(nvl);

		// ����entry������
		attr = elem->FirstAttribute();
		if (!attr)
			return false;
		do 
		{
			nvl->insert(std::make_pair(attr->Name(), attr->Value()));
		} while (attr = attr->Next());

	} while (elem = elem->NextSiblingElement());

	return true;
}

ParamParser::ParamParser( const std::string& fileName ) : mFileName(fileName)
{
	mIter = mEntryList.begin();
}

ParamParser::~ParamParser()
{
	for (auto iter = mEntryList.begin(); iter != mEntryList.end(); ++iter)
		delete (*iter);
}
