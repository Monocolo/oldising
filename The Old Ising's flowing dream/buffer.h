#ifndef BUFFER_H
#define BUFFER_H
#include <windows.h>

/*
˫������ģ���������̨��ʾ���
_std ��Ӧ��׼�����,Ӧ��Ŀ���̨��ʾ
_buffer ����������
*/
struct HUD
{
    HANDLE _std;
    HANDLE _buffer;
};
/*
    ��ȡ��׼��������
    �����µĿ���̨������
    ���ñ�׼��������Ϊ�ڻ�Ŀ���̨������
    �� main() ���ȵ����������������̨��ʾ���л�Ϊ _std ����ʾ������
*/
void handle_init(HUD *handle);

/*
    ���� Surface ��Ļ����Ӧ��׼��������ڻ�Ŀ���̨��ʾ
    self ����Ļ��ʾ֮���Ի�������Ϊý��
    �� self ��������ʾ������̨
*/
void buffer_show(HUD *handle, char** self, int screen_height, int screen_width);

#endif // BUFFER_H
