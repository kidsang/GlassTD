#ifndef ParamParser_h__
#define ParamParser_h__

/**
 * �ļ���ParamParser
 * ���ڣ�2012/06/05
 * ���ߣ�kid
 */

#include "Common.h"
#include "tinyxml.h"

/// �����ⲿ����XML�ļ�������������ڼ�ֵ����
class ParamParser
{
typedef std::vector<NameValueList*> EntryList;

private:
	/// Ҫ�������������Ŀ�б�
	/// ���磬�ӵ������кܶ��֣���������кܶ���
	EntryList mEntryList;
	/// Ҫ�������ⲿ�ļ�������
	std::string mFileName;
	///
	EntryList::iterator mIter;


public:
	/// ���캯��
	/// @param fileName �ⲿXML�ļ���·������
	ParamParser(const std::string& fileName);
	~ParamParser();

	/// �����ļ������ʧ���򷵻�false
	bool parse();

	/// ��ָ�������һ��entry
	void moveToFirst()
	{
		mIter = mEntryList.begin();
	}

	/// ����Ƿ���ʣ���entry
	bool hasNext()
	{
		return (mIter != mEntryList.end());
	}

	/// ������һ��entry
	NameValueList* getNext()
	{
		NameValueList* ret = (*mIter);
		++mIter;
		return ret;
	}

	/// ���ؽ�������Ĳ����б�
	const EntryList& getEntryList()
	{
		return mEntryList;
	}

};


#endif // ParamParser_h__

