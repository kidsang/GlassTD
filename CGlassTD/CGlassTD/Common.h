#ifndef Common_h__
#define Common_h__

#include <string>
#include <map>
#include <hash_map>
#include <vector>
#include <list>
#include <deque>

/// 该文件提供了一些通用的函数

/// 供工厂类传递参数使用
typedef std::map<std::string, std::string> NameValueList;

/// 怪兽的属性
enum ATTRIBUTE{NORMAL = 0, FIRE = 1, ICE = 2};
#endif // Common_h__
