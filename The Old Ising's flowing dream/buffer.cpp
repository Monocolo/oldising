#include "buffer.h"
#include <stdio.h>
/*
��������ľ���ṹ��
������ͨ���ⲿ������ʹ��
*/
extern HUD handle;

/*
    ��ȡ��׼��������
    �����µĿ���̨������
    ���ñ�׼��������Ϊ�ڻ�Ŀ���̨������
    �� main() ���ȵ����������������̨��ʾ���л�Ϊ _std ����ʾ������
*/
void handle_init(HUD *handle)
{
	// handle._std Ϊ��ǰ��׼�������Ӧ�Ŀ���̨��ʾ
    handle->_std = GetStdHandle(STD_OUTPUT_HANDLE);
    // �½�һ������̨��ʾ
    handle->_buffer = CreateConsoleScreenBuffer(
                            GENERIC_READ|
                            GENERIC_WRITE,
                            FILE_SHARE_READ|
                            FILE_SHARE_WRITE,
                            NULL,
                            CONSOLE_TEXTMODE_BUFFER,
                            NULL);
    // �� handle._buffer ��Ϊ�ڻ�Ŀ���̨��ʾ
    SetConsoleActiveScreenBuffer(handle->_buffer);

//    // ���ù��Ϊ���ɼ�
//    CONSOLE_CURSOR_INFO cc_info;
//    cc_info.dwSize = 1;
//    cc_info.bVisible = 0;
//    SetConsoleCursorInfo(handle._buffer, &cc_info);
//    SetConsoleCursorInfo(handle._std, &cc_info);

    return;
}

/*
    ���� Surface ��Ļ����Ӧ��׼��������ڻ�Ŀ���̨��ʾ
    self ����Ļ��ʾ֮���Ի�������Ϊý��
    �� self ��������ʾ������̨
*/
void buffer_show(HUD *handle, char** self, int screen_height, int screen_width)
{
    COORD pcoord = {0, 0};

    //Ļ������С��λ����ʾһ��ȫ���ַ�����������ַ�
    char pixiv[3];
    pixiv[2] = '\0';
//    printf("%s",q);
    //���׼��������� self �ڵ���Ϣ
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
    // ���������λ handle._std �еĹ��λ��
    SetConsoleCursorPosition(handle->_std, coord);


    // ������������ buffer �б���Ļ�������д����ʾ����
    // buffer �����ݹ�����׼�����
    _CHAR_INFO buffer[screen_height*screen_width];
    COORD buffer_size = {screen_width,screen_height};
    COORD buffer_coord = {0, 0};
    _SMALL_RECT buffet_rect = {0,0,screen_width,screen_height};
    ReadConsoleOutput(handle->_std, buffer, buffer_size, buffer_coord, &buffet_rect);



    //// ���������е��������� handle._buffer ��
    WriteConsoleOutput(handle->_buffer, buffer, buffer_size, buffer_coord, &buffet_rect);

    return;
}

