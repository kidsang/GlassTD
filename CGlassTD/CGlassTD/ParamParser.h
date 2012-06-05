#ifndef ParamParser_h__
#define ParamParser_h__

/**
 * 文件：ParamParser
 * 日期：2012/06/05
 * 作者：kid
 */

#include "Common.h"
#include "tinyxml.h"

/// 解析外部参数XML文件，将结果保存在键值对中
class ParamParser
{
typedef std::vector<NameValueList*> EntryList;

private:
	/// 要解析的物体的条目列表。
	/// 例如，子弹可能有很多种，怪物可能有很多种
	EntryList mEntryList;
	/// 要解析的外部文件的名字
	std::string mFileName;
	///
	EntryList::iterator mIter;


public:
	/// 构造函数
	/// @param fileName 外部XML文件的路径名称
	ParamParser(const std::string& fileName);
	~ParamParser();

	/// 解析文件，如果失败则返回false
	bool parse();

	/// 将指针移向第一个entry
	void moveToFirst()
	{
		mIter = mEntryList.begin();
	}

	/// 检查是否还有剩余的entry
	bool hasNext()
	{
		return (mIter != mEntryList.end());
	}

	/// 返回下一个entry
	NameValueList* getNext()
	{
		NameValueList* ret = (*mIter);
		++mIter;
		return ret;
	}

	/// 返回解析过后的参数列表
	const EntryList& getEntryList()
	{
		return mEntryList;
	}

};


#endif // ParamParser_h__

