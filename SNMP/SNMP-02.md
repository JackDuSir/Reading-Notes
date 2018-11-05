# NET-SNMP开发——日志输出

net-snmp 的日志输出功能是很强大的，与日志输出相关函数声明在 `net-snmp-5.7.3\include\net-snmp\library\snmp_logging.h` 文件中，定义在 `net-snmp-5.7.3\snmplib\snmp_logging.c` 文件中。

具体实现就不说了，可以自己看源码。

net-snmp 的日志功能默认将日志写入到 `/var/log/snmpd.log` 文件中

## 1. snmp log 类型

net-snmp 中将日志分为 8 个类型(一个警告 warning，三个信息 information，四个错误 error)，具体的宏定义如下

```c++
/* error types */
#define LOG_EMERG       0       /* system is unusable */
#define LOG_ALERT       1       /* action must be taken immediately */
#define LOG_CRIT        2       /* critical conditions 临界条件*/
#define LOG_ERR         3       /* error conditions 错误条件*/
/* warning type */
#define LOG_WARNING     4       /* warning conditions 预警条件*/
/* information types */
#define LOG_NOTICE      5       /* normal but significant condition 正常但意义重大*/
#define LOG_INFO        6       /* informational 信息*/
#define LOG_DEBUG       7       /* debug-level messages 调试级别的消息*/
```

注意：这些严重等级的分类是与标准的 UNIX/LINUX 中的 syslog 一致的。

- `System is unusable emergencies alerts` 极其紧急的错误 

- `Action must be taken immediately` 需立即纠正的错误 

- `Critical conditions` 关键信息 

- `Error conditions` 需关注但不关键的错误 
- `Warning conditions`警告，可能存在某种差错 
- `Normal but significant condition` 需注意的信息 
- `Informational` 一般提示信息 
- `Debug-level messages`调试信息

## 2. 日志输出函数

### 2.1 snmp_log

```c++
int snmp_log(int priority, const char *format, ...)
```

这个函数实际上调用的是 `snmp_vlog` 函数，这个函数成功返回 0，当不能格式化日志字符串时返回 1，当动态内存不能分配返回 2，如果日志缓冲区的长度大于 1024 字节。这些消息将以 LOG_ERR 类型直接写入日志文件。

调用示例

```c++
snmp_log(LOG_ERR, "%s: Error %d out-of-range\n", s, errno);
```

### 2.2 snmp_log_perror

```C++
void snmp_log_perror(const char *s)
```

实际上是先调用 `char* error = strerror(errno);` 获取 `errno` 的信息，然后使用 `snmp_log` 来输出参数 `s` 和 `error` 字符串。 调用示例

```c++
snmp_log_perror("init error");
```

### 2.3 snmp_log_string

```c++
void snmp_log_string(int priority, const char *str)
```

调用示例

```C++
snmp_log_string(LOG_ERR, "Could not format log-string\n");
```

