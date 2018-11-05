# net-snmp 配置: snmp v3 的安全配置

## 1. 增加snmp v3用户

### 1.1 增加 认证且加密只读账号(authPriv)

```shell
$ sudo service snmpd stop   #停止snmpd服务
$ sudo net-snmp-create-v3-user -ro -A auth123456 -X priv123456 -a MD5 -x DES fx     #创建snmpv3用户

adding the following line to /var/net-snmp/snmpd.conf:
   createUser fx MD5 "auth123456" DES priv123456
adding the following line to /usr/local/net-snmp/share/snmp/snmpd.conf:
   rouser fx
```

### 1.2 增加 认证且加密的读写账户

```shell
$ sudo /usr/local/net-snmp/bin/net-snmp-create-v3-user  -A auth123456 -a MD5 -X priv123456 -x DES fxw 
adding the following line to /var/net-snmp/snmpd.conf:
   createUser fxw MD5 "auth123456" DES priv123456
adding the following line to /usr/local/net-snmp/share/snmp/snmpd.conf:
   rwuser fxw

```

### 1.3 增加 认证但不加密只读账户(authNoPriv)

```shell
$ sudo net-snmp-create-v3-user -ro -A auth123456 -a MD5 fxa
adding the following line to /var/net-snmp/snmpd.conf:
   createUser fxa MD5 "auth123456" DES
adding the following line to /usr/local/net-snmp/share/snmp/snmpd.conf:
   rouser fxa
```

注意，这个操作会修改默认的 `snmpd.conf` 文件。

#### 1.3.1 参数说明

- `-ro`: 用户读写权限，表示用户fx为只具有读权限
- `fx`：用户名
- `-a MD5`: 认证方式，MD5散列方式
- `-A auth123456`：设置认证密码，密码必须大于8个字符
- `-x DES`: 加密方式，这边支持AES、DES两种
- `priv123456`：加密口令，必须大于8位

备注：增加用户的时候，snmp 必须关闭，否则有如下报错

```shell
Apparently at least one snmpd demon is already running.
 You must stop them in order to use this command.
Apparently at least one snmpd demon is already running.
 You must stop them in order to use this command.
```

## 2. 重新启动 snmpd

```shell
$ /etc/init.d/snmpd stop
$ /etc/init.d/snmpd start
```

## 3. 测试一下

### 3.1 测试认证且加密只读账户 fx

```shell
$ snmpwalk  -v3  -u fx -a MD5 -A auth123456 -x DES -X priv123456 -l authPriv 127.0.0.1 sysUpTime
DISMAN-EVENT-MIB::sysUpTimeInstance = Timeticks: (93687) 0:15:36.87
```

### 3.2 测试认证且加密读写账户 fxw

注意，下面的节点 `confNewVersion.0` 是一个自定义的读写节点

```shell
#认证且加密方式set
$ snmpset -v3 -u fxw -a MD5 -A auth123456 -x DES -X priv123456 -l authPriv 127.0.0.1 confNewVersion.0 s "12345"
SNMP-VC-MIB::confNewVersion.0 = STRING: "12345"

#认证但不加密方式set
$ snmpset -v3 -u fxw -a MD5 -A auth123456  -l authNoPriv 127.0.0.1 confNewVersion.0 s "12345"
SNMP54-VideoCommand-MIB::confNewVersion.0 = STRING: "12345"
```

### 3.3 测试认证不加密只读账户 fxa

```shell
$ snmpwalk  -v 3 -u fxa -a MD5 -A auth123456 -l authNoPriv 127.0.0.1 sysUpTime
DISMAN-EVENT-MIB::sysUpTimeInstance = Timeticks: (8215) 0:01:22.15
```

### 3.4 注意事项

注意，对于 `snmpget/set` 操作，代理端配置的账户与管理端使用的时候可以不完全一致。但是对于 `set` 操作，不能使用 `noAuthNoPriv` 方式，否则报错。

- 对于认证且加密的账户，`snmpget/walk/get`可以使用三种级别的安全方式，分别为`noAuthNoPriv`（不认证也不加密）、`authNoPriv`（认证但是不加密）、`authPriv`（既认证又加密）
- 对于认证但不加密的账户，`snmpget/walk/get`可以使用两种级别的安全方式，分别为noAuthNoPriv（不认证也不加密）、authNoPriv（认证但是不加密）

#### 3.4.1 snmpwalk 权限设置导致的超时

```shell
$ snmpwalk  -v 3 -u fxa -a MD5 -A auth123456 -x DES -X priv123456 -l authPriv 127.0.0.1 sysUpTime
Timeout: No Response from 127.0.0.1
```

#### 3.4.2 snmpset 安全等级设置与认证和加密设置不对等时候的报错

```shell
$ snmpset -v3 -u fxw -a MD5 -A auth123456  -l authPriv 127.0.0.1 confNewVersion.0 s "12345"snmpset: USM generic error (Sub-id not found: (top) -> confNewVersion)
```

#### 3.4.3 snmpset 使用 noAuthNoPriv 不认证不加密方式报错

```shell
$ snmpset -v3 -u fxw  -l noAuthNoPriv 127.0.0.1 confNewVersion.0 s "12345"
Error in packet.
Reason: authorizationError (access denied to that object)
```

