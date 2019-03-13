1、从Qt操作得到的字符串都是utf-8，
但如果使用标准C库函数，如果包含中文，如果Qt在windows环境下，则标准C库函数则需要GBK编码

QTextCodec *codec = QTextCodec::codecForName("GBK"); //需要头文件#include <QTextCodec>
//codec->fromUnicode();//把UTF8转化为GBK
char *file = codec->fromUnicode(fileName).data(); //fileName为QString类型
//或者
const char *file = codec->fromUnicode(fileName).toStdString().data();

2、Qt控件显示中文，必须是utf-8才能正常显示
fgets(buf, sizeof(buf), fp); //假如从文件中读取到中文内容为gbk编码
QString str = codec->toUnicode(buf); //把一个GBK编码的字符串转化UTF8

3、QString和char *转换
QString为Qt字符串类型

QString str = "hello world";
const char *p = str.toStdString().data(); //QString -> const char *

char *p = "hello world";
QString str = p; //char * -> QString

4、QString常用操作
1)字符串匹配子串替换
QString str = "mike.c";
str = str.replace(".c", ""); //str中的.c替换为空字符

2)字符串累加
QString str1 = "hello";
char *p = "world";
QString str2 = "mike";
QString txt = str1 + p + str2; //txt = "helloworldmike";

3)格式化字符串
QString cmd = QString("gcc %1 -o %2").arg("mike.c").arg("demo");
//"mike.c"放%1的位置，"demo"放%2的位置
//结果为 cmd = "gcc mike.c -o demo"

4)字符串清空
QString str = "mike.c";
str.clear();
