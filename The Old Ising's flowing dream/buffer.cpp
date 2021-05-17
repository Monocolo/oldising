#include "buffer.h"
#include <stdio.h>
/*
主函数里的句柄结构体
在这里通过外部声明来使用
*/
extern HUD handle;

/*
    获取标准输出流句柄
    创建新的控制台输出句柄
    设置标准输出流句柄为在活动的控制台输出句柄
    在 main() 里先调用这个函数，控制台显示将切换为 _std 中显示的内容
*/
void handle_init(HUD *handle)
{
	// handle._std 为当前标准输出流对应的控制台显示
    handle->_std = GetStdHandle(STD_OUTPUT_HANDLE);
    // 新建一个控制台显示
    handle->_buffer = CreateConsoleScreenBuffer(
                            GENERIC_READ|
                            GENERIC_WRITE,
                            FILE_SHARE_READ|
                            FILE_SHARE_WRITE,
                            NULL,
                            CONSOLE_TEXTMODE_BUFFER,
                            NULL);
    // 将 handle._buffer 置为在活动的控制台显示
    SetConsoleActiveScreenBuffer(handle->_buffer);

//    // 设置光标为不可见
//    CONSOLE_CURSOR_INFO cc_info;
//    cc_info.dwSize = 1;
//    cc_info.bVisible = 0;
//    SetConsoleCursorInfo(handle._buffer, &cc_info);
//    SetConsoleCursorInfo(handle._std, &cc_info);

    return;
}

/*
    传入 Surface 屏幕，对应标准输出流和在活动的控制台显示
    self 与屏幕显示之间以缓冲区作为媒介
    将 self 的内容显示到控制台
*/
void buffer_show(HUD *handle, char** self, int screen_height, int screen_width)
{
    COORD pcoord = {0, 0};

    //幕布的最小单位，表示一个全角字符或两个半角字符
    char pixiv[3];
    pixiv[2] = '\0';
//    printf("%s",q);
    //向标准输出流传入 self 内的信息
    for (int i = 0; i < screen_height; i++) {
        for (int j = 0; j < screen_width; j+=2) {
            SetConsoleCursorPosition(handle->_std, pcoord);
            pixiv[0] = self[i][j];
            pixiv[1] = self[i][j+1];
            printf("%s",pixiv);

            pcoord.X+=2;
//            putchar(self[i][j]);
        }
        pcoord.X=0;
        pcoord.Y++;
        putchar('\n');
    }


    COORD coord = {0, 0};
    DWORD bytes = 0;
    // 这个函数定位 handle._std 中的光标位置
    SetConsoleCursorPosition(handle->_std, coord);


    // 它的作用是向 buffer 中保存的缓冲区域写入显示内容
    // buffer 的内容关联标准输出流
    _CHAR_INFO buffer[screen_height*screen_width];
    COORD buffer_size = {screen_width,screen_height};
    COORD buffer_coord = {0, 0};
    _SMALL_RECT buffet_rect = {0,0,screen_width,screen_height};
    ReadConsoleOutput(handle->_std, buffer, buffer_size, buffer_coord, &buffet_rect);



    //// 将缓冲区中的内容贴到 handle._buffer 中
    WriteConsoleOutput(handle->_buffer, buffer, buffer_size, buffer_coord, &buffet_rect);

    return;
}

