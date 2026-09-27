================//// Read Me \\\\================
主文件 main.c 中需添加库：#include "MusicPlayer.h"， #include "MusicScore.h"

在主文件main.c 中的main函数中添加初始化函数和PlayMusic函数即可，即 MusicPlayer_init();， playMusic(SanranBanka,297);

注意：工程中需配置一PWM波，NAME为PWM_0，输出引脚PIN 1 输出至蜂鸣器，并配置一个0中断，由于单片机不同，MusicPlayer.c文件下代码会存在些许差异，但思路一致，可根据情况自行更改。主包使用的是ti的mspm0g3519

PlayMusic函数使用方式：playMusic(音乐名,音符数);

音乐库 MusicScore.h 文件中，MusicNote结构体定义的为音乐名，音符数为对应结构体最后一行后面注释中的数字，如《以恋结缘》名字即为SanranBanka，音符数为 297.

如果想实现音乐的停止/暂停功能，可自行在PlayMusic函数定义中添加if语句。
================\\\\ Read Me ////================