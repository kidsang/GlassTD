#ifndef Common_h__
#define Common_h__

#include <string>
#include <map>
#include <hash_map>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

/// ���ļ��ṩ��һЩͨ�õĺ���

/// �������ഫ�ݲ���ʹ��
typedef std::map<std::string, std::string> NameValueList;

///// ���޵�����
//enum ATTRIBUTE{NORMAL = "normal", FIRE = "fire", ICE = "ice"};

/// ���ַ������Ϊ���������ʣ��Կո�Ϊ�ָ�
/// @param ��Ҫ����ֵ��ַ���
/// @return ��ֺ������
/// @note ����һ����stackoverflow�������ĺ������Ҳ�������������������ġ���
std::vector<std::string> mysplit(std::string str);

#endif // Common_h__