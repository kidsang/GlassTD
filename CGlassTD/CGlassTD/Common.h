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

/// 该文件提供了一些通用的函数

/// 供工厂类传递参数使用
typedef std::map<std::string, std::string> NameValueList;

///// 怪兽的属性
//enum ATTRIBUTE{NORMAL = "normal", FIRE = "fire", ICE = "ice"};

/// 将字符串拆分为单个单个词，以空格为分隔
/// @param 需要被拆分的字符串
/// @return 拆分后的数组
/// @note 这是一个从stackoverflow上拿来的函数，我不懂它到底是如何做到的。。
std::vector<std::string> mysplit(std::string str);

std::string convertToString(double num);

#endif // Common_h__