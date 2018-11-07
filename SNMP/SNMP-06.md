# Mib 编写

> [如何编写MIB文件](https://wenku.baidu.com/view/46184f6ef5335a8102d2203a.html)
>
> [如何编写mib文件](https://wenku.baidu.com/view/8ddf9bd5fbb069dc5022aaea998fcc22bcd143b1.html?rec_flag=default&sxts=1541585847009)
>
> [MIB结构和语法](https://wenku.baidu.com/view/3b725c391711cc7931b716a1.html?sxts=1541585713481)
>
> [MIB2所有节点描述](https://wenku.baidu.com/view/c14d8fc24028915f804dc272.html?sxts=1541585714708)
>
> [mib文件的编写](https://blog.csdn.net/u014207606/article/details/71425523)
>
>

```lua
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

