# 银行业务模拟系统的设计与实现

## 基本要求
1. 初始化（OpenForDay），模拟银行开门时各数据结构的状态。
2. 事件驱动（EventDrived），对客户到达和离开事件做相应处理。
3. 下班处理（CloseForDay），模拟银行关门时的动作，统计客户平均逗留时间

## 思路

- 客户结点  
数据域：办理时间、逗留时间    
链域：指向下一客户



- 窗口类    
数据域：排队人数  
链域：指向排队客户队头、队尾

  - 初始化  
  人数归零、指针nullptr
  - 模仿队列操作


- 银行类    
4个窗口

  -  初始化  
  类中自带**构造器**不用再建
  数据域归0，指针域指向nullptr

  - 事件驱动（EventDrived）   
    1. 利用**while**模拟时间流逝，在每个时间点
       1. 处理排队中的客户
          - 队首客户办理时间==0？删除结点：该时间--
          - 所有客户逗留时间++ 
       2. 判断是否有新客户进银行
          1. 随机生成1~10，若<=3则生成客户（30%）
          2. 为新客户随机生成办理时间1~10min，放到人数少的窗口


  - 下班处理（CloseForDay）  
  计算平均逗留时间=总逗留/总人数

  - 随机（random）    
  生成指定范围整数

  - 时钟？  
  用于报时


- 界面类
  - 运行主程序
  - 具体设置（修改随机范围）
  - 结束程序










