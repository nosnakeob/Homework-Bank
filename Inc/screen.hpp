#ifndef _SCREEN_H_
#define _SCREEN_H_

class Screen
{
private:
    enum Choice
    {
        RUN = 1,
        SETTING,
        EXIT
    };

public:
    void startMenu();  //开始界面
    void option();     //选项栏
    void setting(); //修改参数
    void run();        //运行过程
};
#endif