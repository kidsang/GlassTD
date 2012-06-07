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

	// 根节点
	root = hDoc.FirstChildElement().Element();
	if (!root)
		return false;

	// 每个子节点
	elem = root->FirstChildElement();
	if (!elem)
		return false;

	// 遍历entry
	do 
	{
		// 每个子节点意味着多了一个entry
		NameValueList* nvl = new NameValueList();
		mEntryList.push_back(nvl);

		// 遍历entry的属性
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
