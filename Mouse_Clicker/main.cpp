#include <Windows.h>
#include <iostream>

using namespace std;

int main(){
	POINT p;
	
	cout << "Press <INSERT> to begin clicking . . . \n";

	while (true){
		// Check if <INSERT> is pressed
		if (GetAsyncKeyState(VK_INSERT)){
			cout << "Press <DELETE> to stop clicking . . . \n";

			// Check if <DELETE> is pressed
			while (GetCursorPos(&p) && !GetAsyncKeyState(VK_DELETE)){
				mouse_event(MOUSEEVENTF_LEFTDOWN, p.x, p.y, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, p.x, p.y, 0, 0);
				Sleep(1);
			}
		}
	}

	return 0;
}