#MICO
使用WIFI模块自带MCU开发在工程配置添加ZC_MODULE_DEV宏定义
##1.AC_MICO_v1.0.0_20150910
AbleCloud庆科代码版本入库

##2.AC_MICO_v1.0.1_20150912
 增加看门狗
##3.AC_MICO_v1.0.2_20151018
1.修改定时器
2.修改看门狗喂狗时间由2s增加到3s，解决擦写flash时间过长导致看门狗复位的问题

##3.AC_MICO_v1.0.3_20151020
1.修改定时器错误

##4.AC_MICO_v1.0.4_20151118
1.解决3088压力测试丢包问题，怀疑是3088进入低功耗模式，移除ps_enable压力测试正常39版本
2.增加APP版本，如果版本号不一致进入出厂设置。
##4.AC_MICO_v1.0.5_20151221
1.解决局域网连接不上的问题
2.3088与3165增加RF_LED指示网络连接状态
3.增加产测模式
4.增加了简化协议支持
##4.AC_MICO_v1.0.6_20160111
1.升级3088库版本到043，3165到
2.修改3088flash分区、工程配置、bootloader用于支持生成MVA格式文件
3.将3088编译优化级别调整为00，解决设备接入的问题
4.mfg增加服务器域名与串口协议类型打印
5.增加了微信2.0支持

## 5.AC_MICO_v1.0.7_20160427

1.修复微信2.0局域网发现不了的问题

## 6.AC_MICO_v1.0.8_20160519

1.修改adpter文件，将本地局域网server单独启动线程，支持三种局域网控制方式

## 7.AC_MICO_v1.0.9_20160524

1.修改adpter和MICOEntrance.c文件，修复，先开WIFI，后开路由不能绑定的问题

## 8.AC_MICO_v1.0.10_20160603

1.修改了adpter.c和adpter.h文件，修复，路由器断网，设备长时间检测不到的问题