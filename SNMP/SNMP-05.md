# Net-SNMP Mibs扩展

> [Net-snmp总结(六)-net-snmp源码分析](https://blog.csdn.net/JIANGXIN04211/article/details/78478581)
>
> [快速理解和掌握MIB](https://blog.csdn.net/zhigang0529/article/details/83182011)
>
> [net-snmp的MIBs扩展](https://www.cnblogs.com/oloroso/p/4599501.html)
>
> [Net-snmp总结(三)-net-snmp的MIBs扩展_添加get](https://blog.csdn.net/JIANGXIN04211/article/details/78475155)
>
> [基于Net-SNMP简单网络管理的开发指南](http://chichangjing.github.io/2016/02/03/net-snmp-develop.html)
>
> [net-snmp agent开发（用net-snmp扩展MIB库）](http://www.codexiu.cn/linux/blog/21346/)
>
> [snmp的使用](https://blog.csdn.net/q_l_s/article/details/51721572)
>
> [烂泥：使用snmpwalk采集设备的OID信息](https://www.ilanni.com/?p=8408)
>
> [浅谈 Linux 系统中的 SNMP Trap](https://www.ibm.com/developerworks/cn/linux/l-cn-snmp/index.html)
>
> [用net-snmp开发snmp代理客户端](http://www.voidcn.com/article/p-ovlmmgko-bdh.html)
>
> [用NET-SNMP软件包开发简单客户端代理（上）](http://blog.51cto.com/mandyc/579828)
>
> [用NET-SNMP软件包开发简单客户端代理](https://wenku.baidu.com/view/de51c35077232f60ddcca13f.html)
>
> [SmithSNMP v0.8发布，Lua 轻松定制MIB的SNMP代理](https://www.ctolib.com/topics-107371.html)
>
> [总结：用net-snmp开发snmp代理客户端](https://www.smwenku.com/a/5b902f9b2b7177672217d3b3/zh-cn/)
>
> ### 百度文库
>
> > [SNMP网管协议培训教材](https://wenku.baidu.com/view/7a4e2abdf121dd36a32d8268.html?sxts=1541400068018)
> >
> > [SNMP学习小结](https://wenku.baidu.com/view/1cedbd225901020207409c2a.html?sxts=1541400066280)
> >
> > [简单网络管理协议SNMP](https://wenku.baidu.com/view/dfa1f18fa0116c175f0e4878.html?sxts=1541400069975)
> >
> > [SNMPv1 , SNMPv2 ,SNMPv3 ,RMON网络管理](https://wenku.baidu.com/view/89973f6daf1ffc4ffe47acb0.html?sxts=1541401176402)
> >
> > [SNMP协议基础](https://wenku.baidu.com/view/e65c9c8702d276a200292e70.html?sxts=1541401177761)
> >
> > [SNMP简单网络管理协议](https://wenku.baidu.com/view/35dddab265ce0508763213af.html?from=search)
> >
> > [net-snmp安装配置手册](https://wenku.baidu.com/view/cf0efc335a8102d276a22f6d.html?from=search)
> >
> > [SNMP V3](https://wenku.baidu.com/view/b75ef190aa00b52acfc7caec.html?from=search)
> >
> > [SNMP V3 分析及详解](https://wenku.baidu.com/view/6ecdca651ed9ad51f01df2fa.html?from=search)
> >
> > [SNMP+MIB完整手册](https://wenku.baidu.com/view/3cbbbdcb0508763231121214.html?from=search)
> >
> > [基于NETSNMP开发mib说明](https://wenku.baidu.com/view/c3ebe8c008a1284ac8504346.html?from=search)

## 1. net-snmp 程序逻辑

snmpd 代理完成两个功能：

1. 接收网管发过来的 snmp 包，并对接收到的 snmp 包进行解析，校验后，找到并调用相应的处理函数进行处理。

2. 调用注册了的告警函数，向网管发送告警信息。

Net-snmp 代码流程图如下图所示：

<img src="_asset/SNMP程序逻辑.png">

## 2. NET-SNMP 源码分析

Net-snmp 代码的核心，就是初始化函数时，向代理(snmpd)注册了回调处理函数，当(snmpd)接收到一个 snmp 请求包时，它会先对包进行校验，如果校验不通过，会返回相应的错误。如果通过后，它会解析请求包，并把请求包的内容转换成请求结构（`netsnmp_agent_request_info`【包含请求包的 pdu 信息】，`netsnmp_request_info`【包含请求包的vb信息】）。匹配到相关的 oid 时，就调用相应的注册处理函数并传入请求结构给处理函数，处理函数只需要根据结构中的内容进行相应的业务处理就可以了。

下面用之前添加的 testGet 代码来做简要说明。

```c++
/** Initializes the testGet module */
void
init_testGet(void)
{
    const oid GetTime_oid[] = { 1, 3, 6, 1, 4, 1, 77695, 1 };
    DEBUGMSGTL(("testGet", "Initializing\n"));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("GetTime", handle_GetTime, GetTime_oid,
                             OID_LENGTH(GetTime_oid), HANDLER_CAN_RONLY));
}
 
int
handle_GetTime(netsnmp_mib_handler *handler,
               netsnmp_handler_registration *reginfo,
               netsnmp_agent_request_info *reqinfo,
               netsnmp_request_info *requests)
{
    time_t t;
    switch (reqinfo->mode) {
        case MODE_GET:
        	time(&t);
            char szTime[100];
            snprintf(szTime,100,"%s",ctime(&t));
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                     /*
                                      * XXX: a pointer to the scalar's data
                                      */ szTime,
                                     /*
                                      * XXX: the length of the data in bytes
                                      */ strlen(szTime));

            break;
        default:
            /*
             * we should never get here, so this is a really bad error
             */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_GetTime\n",
                     reqinfo->mode);
            return SNMP_ERR_GENERR;
    }
    return SNMP_ERR_NOERROR;
}
```

初始函数调用 `netsnmp_create_handler_registration` 向 snmpd 注册 `GetTime_oid` 的处理函数为 `handle_GetTime` ，当 snmpd 调用 `handle_GetTime` 时，便会把相应的 snmp 包的信息从这几个参数中传进来。其中 reqinfo  就是 snmp 请求包被 snmpd 解析后得到的结构，包含了请求包的会话和 pdu 信息； requests 主要包含了 VB 信息。每次处理一个 SNMP 请求，就调用一次注册函数。

主要的几个结构体如下

`netsnmp_agent_request_info`

```c++
/** @struct netsnmp_agent_request_info_s  
 * The agent transaction request structure  
 */  
typedef struct netsnmp_agent_request_info_s {  
    int mode;  
    /** pdu contains authinfo, eg */  
    /*  netsnmp_pdu *pdu;    */  
    struct netsnmp_agent_session_s *asp;    /* may not be needed */  
    /*  
	 * can be used to pass information on a per-pdu basis from a  
	 * helper to the later handlers   
	 */  
    netsnmp_data_list *agent_data;  
} netsnmp_agent_request_info;
```

`netsnmp_request_info`

```c++
/** @typedef struct netsnmp_request_info_s netsnmp_request_info  
 * Typedefs the netsnmp_request_info_s struct into  
 * netsnmp_request_info*/ 
 
/** @struct netsnmp_request_info_s  
 * The netsnmp request info structure.  
 */  
 
typedef struct netsnmp_request_info_s {  
    /** variable bindings  */  
    netsnmp_variable_list *requestvb;  
 
    /**  
     * can be used to pass information on a per-request basis from a  
     * helper to the later handlers   
     */  
    netsnmp_data_list *parent_data;  
 
    /*  
     * pointer to the agent_request_info for this request  
     */  
	struct netsnmp_agent_request_info_s *agent_req_info;  
 
	/** don't free, reference to (struct tree)->end */  
    oid            *range_end;  
    size_t          range_end_len;  
 
	/** flags  */  
    int             delegated;  
    int             processed;  
    int             inclusive;  
 
    int             status;  
	/** index in original pdu */  
    int             index;  
 
    /** get-bulk */  
    int             repeat;  
    int             orig_repeat;  
    netsnmp_variable_list *requestvb_start;  
 
   	/* internal use */  
    struct netsnmp_request_info_s *next;  
    struct netsnmp_request_info_s *prev;  
    struct netsnmp_subtree_s      *subtree;  
} netsnmp_request_info; 
```

## 3. Mib 文件

MIB 文件是用 ASN.1 语法来描述的，所以为了精确定义 MIB 中各管理对象，用户不得不参考一些 ASN.1 语法的有关文档如 RFC1155、RFC1212 等等来定义设备自己的 MIB。ASN.1 是抽象句法表示法一 （Abstract SyntaxNotation One） 的简称，对于每个管理对象它都用文本来描述，一般文件的后缀名都用 “.mib”, 在 net-snmp 中后缀名是 “.mib.txt”。

关于 MIB 文件示例，可以见编译安装后的 net-snmp 目录，一般是 `/usr/local/net-snmp/share/snmp/mibs/`。

```shell
$ ls /usr/share/snmp/mibs/
AGENTX-MIB.txt                       OSPF-TRAP-MIB.txt
......
OSPF-MIB.txt                         UDP-MIB.txt
```

这里我们建立一个 mib 文件，命名为 `TEST-GET-MIB.txt`，放在 /usr/local/net-snmp/share/snmp/mibs/ 目录下因为这个目录是 snmpd 的默认目录，只要把 MIB 库放入该目录就可以自动加载 MIB 库，否则需要修改 snmpd.conf 文件，自定义的 MIB 文件如下：

```mib
-- 开始
TEST-GET-MIB DEFINITIONS ::= BEGIN
 
-- 引入部分
IMPORTS
    enterprises
        FROM RFC1155-SMI            
    Integer32,OBJECT-TYPE
        FROM SNMPv2-SMI            
    DisplayString
        FROM SNMPv2-TC
    TEXTUAL-CONVENTION
        FROM SNMPv2-TC; --引用结束，用分号
 
 
-- 定义节点
-- enterprises的OID是1.3.6.1.4
testGet    OBJECT IDENTIFIER ::= { enterprises 77695 }
 
GetTime     OBJECT IDENTIFIER ::= { testGet   1}
 
GetTime OBJECT-TYPE       -- 对象名称
SYNTAX DisplayString      -- 类型
MAX-ACCESS read-only      -- 访问方式
STATUS current            -- 状态
DESCRIPTION               -- 描述
"get current time"   
::= { testGet  1 }       -- 父节点
 
-- 结束定义
END
```

写完后我们测一个 MIB 库有没有问题，在 linux 机器上用 `snmptranslate-Tp -IR TEST-GET-MIB::testGet` 显示结果如下：（这个测试不需要启动 snmpd 进程）

```shell
$ ./snmptranslate -Tp -IR TEST-GET-MIB::testGet
+--testGet(77695)
   |
   +-- -R-- String    GetTime(1)
            Textual Convention: DisplayString
            Size: 0..255
```

OK, snmp 自动发现了这个 MIB 库， 有了自定义的 OID，接下来开始添加处理程序。

## 4. 生成源码

我们可以先来获取一下前面定义的 testGet 节点的值试试。 因为 enterprises 的 OID 是 1.3.6.1.4 ，而 testGet 是 enterprises 的叶子(77695)，而 GetTime 又是 testGet 的叶子节点(1)。所以其 OID 为 1.3.6.1.4.77695.1 。 

下面使用snmpget来测试一下（测试之前要先启动snmpd进程）

```shell
$ ./snmpget -c public -v 2c localhost 1.3.6.1.4.1.77695.1.0
SNMPv2-SMI::enterprises.77695.1= No Such Object available on this agent at this OID  
```

结果是 No Such Object available on this agent at this OID，我们需要用 mib2c 程序生成所需要的 `.c` 和 `.h` 文件。

执行 `envMIBS="+/usr/local/net-snmp/share/snmp/mibs/TEST-GET-MIB.txt" ./mib2ctestGet`，会引导你逐渐生成 `testGet.h` 和 `testGet.c` ,先选 2 再选 1，过程如下：

```shell
$ env MIBS="+/usr/local/net-snmp/share/snmp/mibs/TEST-GET-MIB.txt" ./mib2c testGet
writing to -
mib2c has multiple configuration files depending on the type of
code you need to write.  You must pick one depending on your need.
 
You requested mib2c to be run on the following part of the MIB tree:
  OID:                              testGet
  numeric translation:              .1.3.6.1.4.1.77695
  number of scalars within:         1
  number of tables within:          0
  number of notifications within:   0
 
First, do you want to generate code that is compatible with the
ucd-snmp 4.X line of code, or code for the newer Net-SNMP 5.X code
base (which provides a much greater choice of APIs to pick from):
  1) ucd-snmp style code
  2) Net-SNMP style code
Select your choice : 2
**********************************************************************
                 GENERATING CODE FOR SCALAR OBJECTS:
**********************************************************************
  It looks like you have some scalars in the mib you requested, so I
  will now generate code for them if you wish.  You have two choices
  for scalar API styles currently.  Pick between them, or choose not
  to generate any code for the scalars:
  1) If you're writing code for some generic scalars
     (by hand use: "mib2c -c mib2c.scalar.conf testGet")
  2) If you want to magically "tie" integer variables to integer
     scalars
     (by hand use: "mib2c -c mib2c.int_watch.conf testGet")
  3) Don't generate any code for the scalars
Select your choice: 1
    using the mib2c.scalar.conf configuration file to generate your code.
writing to testGet.h
writing to testGet.c
**********************************************************************
* NOTE WELL: The code generated by mib2c is only a template.  *YOU*  *
* must fill in the code before it'll work most of the time.  In many *
* cases, spots that MUST be edited within the files are marked with  *
* /* XXX */ or /* TODO */ comments.                                  *
**********************************************************************
running indent on testGet.c
running indent on testGet.h
```

mib2c 已经统计出我们的 mib 库包含 1 个 scalar 变量，0 个 table 变量，0 个通知变量，Scalar 就是包含我们常用的整型，字符串，时间等等数据类型。table 就是 scalar 的一种集合，有一个和多个列组成，类似于数据库中的表。它必须具有索引项，用来按一定顺序检索表项，当然我们只写了一个标量的 OID，不是表结构也不是通知结构

生成的 `testGet.h` 如下

```c++
/*
 * Note: this file originally auto-generated by mib2c using
 *        $
 */
#ifndef TESTGET_H
#define TESTGET_H
 
/*
 * function declarations
 */
void            init_testGet(void);
Netsnmp_Node_Handler handle_GetTime;
 
#endif                          /* TESTGET_H */
```

生成的 `testGet.c` 文件如下：

```c++
/*
 * Note: this file originally auto-generated by mib2c using
 *        $
 */
 
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "testGet.h"
 
/** Initializes the testGet module */
void
init_testGet(void)
{
    const oid GetTime_oid[] = { 1, 3, 6, 1, 4, 1, 77695, 1 };
 
    DEBUGMSGTL(("testGet", "Initializing\n"));
 
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("GetTime", handle_GetTime, GetTime_oid,
                             OID_LENGTH(GetTime_oid), HANDLER_CAN_RONLY));
}
 
int
handle_GetTime(netsnmp_mib_handler *handler,
               netsnmp_handler_registration *reginfo,
               netsnmp_agent_request_info *reqinfo,
               netsnmp_request_info *requests)
{
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.
     */
 
    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one.
     */
    time_t t;
    switch (reqinfo->mode) {
		case MODE_GET:
            time(&t);
            char szTime[100];
            snprintf(szTime,100,"%s",ctime(&t));
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                 /*
                                  * XXX: a pointer to the scalar's data
                                  */ ,
                                 /*
                                  * XXX: the length of the data in bytes
                                  */ ;

            break;
        default:
            /*
             * we should never get here, so this is a really bad error
             */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_GetTime\n",
                     reqinfo->mode);
            return SNMP_ERR_GENERR;
    }
    return SNMP_ERR_NOERROR;
}
```

以上的代码都是自动生成的，我们没有写一行代码，到了这一步，我们需要把 `testGet.c` 里面的 `XXX` 改成自己的值，也就两行，修改后 testGet.c 文件代码如下：

```c++
/*
 * Note: this file originally auto-generated by mib2c using
 *        $
 */
 
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "testGet.h"
 
/** Initializes the testGet module */
void
init_testGet(void)
{
    const oid GetTime_oid[] = { 1, 3, 6, 1, 4, 1, 77695, 1 };
 
    DEBUGMSGTL(("testGet", "Initializing\n"));
 
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("GetTime", handle_GetTime, GetTime_oid,
                             OID_LENGTH(GetTime_oid), HANDLER_CAN_RONLY));
}
 
int
handle_GetTime(netsnmp_mib_handler *handler,
               netsnmp_handler_registration *reginfo,
               netsnmp_agent_request_info *reqinfo,
               netsnmp_request_info *requests)
{
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.
     */
 
    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one.
     */
    time_t t;
    switch (reqinfo->mode) {
		case MODE_GET:
            time(&t);
            char szTime[100];
            snprintf(szTime,100,"%s",ctime(&t));
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                 /*
                                  * XXX: a pointer to the scalar's data
                                  */ szTime,
                                 /*
                                  * XXX: the length of the data in bytes
                                  */ strlen(szTime));

            break;
        default:
            /*
             * we should never get here, so this is a really bad error
             */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_GetTime\n",
                     reqinfo->mode);
            return SNMP_ERR_GENERR;
    }
    return SNMP_ERR_NOERROR;
}
```

## 5. 配置编译（静态库方法）

把 `testGet.c` 和 `testGet.h` 复制到 `/net-snmp-5.7.3/agent/mibgroups/` 路径下

设置编译参数

```shell
$ ./configure  --prefix=/usr/local/net-snmp   --with-mib-modules="testGet"
```

查看文件 `net-snmp-5.7.3/agent/mibgroup/mib_module_inits.h`，发现已经添加到初始化中。

```c++
/*This file is automatically generated by configure.  Do not modify by hand. */
  if (should_init("testGet"))init_testGet();
```

编译并安装

```shell
$ make
$ make install
```

## 6. 测试新加的 MIB

启动 snmpd 服务

```shell
$ ./snmpd -f -Le
Turning on AgentXmaster support.
NET-SNMP version5.7.3
No Shmem line in/proc/meminfo
```

我们再调用snmpget来测试结果：

```shell
$ ./snmpget  -v2c -c publiclocalhost  1.3.6.1.4.1.77695.1.0
SNMPv2-SMI::enterprises.77695.1.0= STRING: "Fri Nov  3 14:02:13 2017"
```

显示出了当前的时间，说明我们添加自定义 MIB get 操作成功！



# SNMP 问题

- mib 融合的方式
- snmp代理端和网管连接问题
- trap 和 OAM 融合的问题。
- 



