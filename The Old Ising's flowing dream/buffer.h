#ifndef BUFFER_H
#define BUFFER_H
#include <windows.h>

/*
双缓冲核心，两个控制台显示句柄
_std 对应标准输出流,应活动的控制台显示
_buffer 用作缓冲区
*/
struct HUD
{
    HANDLE _std;
    HANDLE _buffer;
};
/*
    获取标准输出流句柄
    创建新的控制台输出句柄
    设置标准输出流句柄为在活动的控制台输出句柄
    在 main() 里先调用这个函数，控制台显示将切换为 _std 中显示的内容
*/
void handle_init(HUD *handle);

/*
    传入 Surface 屏幕，对应标准输出流和在活动的控制台显示
    self 与屏幕显示之间以缓冲区作为媒介
    将 self 的内容显示到控制台
*/
void buffer_show(HUD *handle, char** self, int screen_height, int screen_width);

#endif // BUFFER_H
