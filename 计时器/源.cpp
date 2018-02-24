#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;
// 计时器

class RunTimer
{
protected:
	int second, minute, hour;
public:
	RunTimer operator++();//要求1
	RunTimer()//要求2
	{	
		second = 0;
		minute = 0;
		hour = 0;
	};
	~RunTimer(){};
	void Reset()
	{
		second = 0;
		minute = 0;
		hour = 0;
	}
	void Pause()
	{
		second = second;
		Sleep(1000);
		system("cls");
	}
	void Second()
	{
		second = second + 1;
		Sleep(1000);
		system("cls");
		return;
	}
	void Minute()
	{
		minute = minute + 1;
	}
	void Hour()
	{
		hour = hour + 1;
	}
	 /*int disp_sec(){
		return second;
	}
	 int disp_min(){
		return minute;
	}
	 int disp_hour(){
		return hour;
	}*/
	void Trans(){
		if (second > 59)
		{
			Minute();
			second = 0;
		}	
		if (minute > 59)
		{
			Hour();
			minute = 0;
		}		
		if (hour > 23)
			Reset();
	}
	friend void display(RunTimer&);//要求4
};

void display(RunTimer &pr){
	
	if (pr.second != 0){
		if (pr.second < 10)
			cout << "0" << pr.hour << ":0" << pr.minute << ":0" << pr.second  << endl;
		else
			cout << "0" << pr.hour << ":0" << pr.minute << ":" << pr.second << endl;
	}
}
 int main(){
	 RunTimer pr;
	cout << "1.按空格键开始计时 2.再次按空格键停止计时 3.按退格键（Backspace）复位" << endl;//要求6
	if (_getch() == ' '){
		system("cls");
		cout << "00:00:00" << endl;
		Sleep(1000);
		int flag = 0;
		while (1){
			if (!GetKeyState(VK_SPACE)||flag==0){
				pr.Second();
				pr.Trans();
				display(pr);
				flag = 1;
			}
			if (GetKeyState(VK_SPACE)&&flag==1){//按下空格键触发
				pr.Pause();
				pr.Trans();
				display(pr);
			}
			if (GetKeyState(VK_BACK) && flag == 1){
				keybd_event(VK_BACK, 0, 0, 0);
				keybd_event(VK_BACK, 0, KEYEVENTF_KEYUP, 0);
				pr.Reset();
			}
		}
	}
	return 0;
}