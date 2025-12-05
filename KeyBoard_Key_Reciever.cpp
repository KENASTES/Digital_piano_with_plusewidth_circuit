#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

void sendKeyPress(const string& text) {
    INPUT input;
    ZeroMemory(&input, sizeof(INPUT));

    for (char c : text) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = c;

            SendInput(1, &input, sizeof(INPUT));

            input.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &input, sizeof(INPUT));
        }
    }
}

int main() {
    HANDLE hSerial = CreateFile("\\\\.\\COM3", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hSerial == INVALID_HANDLE_VALUE) {
        cerr << "Error: Unable to open serial port." << endl;
        return 1;
    }

    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams)) {
        cerr << "Error: Unable to get serial port parameters." << endl;
        CloseHandle(hSerial);
        return 1;
    }

    dcbSerialParams.BaudRate = CBR_115200;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
    if (!SetCommState(hSerial, &dcbSerialParams)) {
        cerr << "Error: Unable to configure serial port." << endl;
        CloseHandle(hSerial);
        return 1;
    }

    char PortBuffer[256];
    DWORD bytesRead;
    while (true) {
        if (ReadFile(hSerial, PortBuffer, sizeof(PortBuffer), &bytesRead, NULL)) {
            if (bytesRead > 0) {
                PortBuffer[bytesRead] = '\0';
                cout << "Received: " << PortBuffer << endl;

                sendKeyPress(PortBuffer);
            }
        }
        Sleep(100);
    }

    CloseHandle(hSerial);
    return 0;
}
