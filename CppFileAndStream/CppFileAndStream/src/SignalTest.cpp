#include <iostream>
#include <csignal>
#include <windows.h>

using namespace std;

void signalHandler(int signum)
{
    cout << "Interrupt signal (" << signum << ") received.\n";

    // �����ر�
    // ��ֹ����  

    exit(signum);

}

int main()
{
    int i = 0;
    // ע���ź� SIGINT ���źŴ������
    signal(SIGINT, signalHandler);

    while (++i) {
        cout << "Going to sleep...." << endl;

        Sleep(1);
    }

    return 0;
}