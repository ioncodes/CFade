#pragma once
#include <Windows.h>
#include <thread>

class FadeAnimator
{
	private:
		HWND consoleWnd = NULL;
		int minimum = 0;
		int maximum = 0;
		int speed = 10;
		int amount = 0;
	public:
		FadeAnimator(int maximum, int minimum, int speed);

	static BOOL WindowTransparency(HWND hwnd, BYTE bAlpha)
	{
		SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
		SetLayeredWindowAttributes(hwnd, RGB(255, 255, 255), bAlpha, 2);
		return true;
	}

	VOID SetTransparency(int transparency) const
	{
		WindowTransparency(consoleWnd, transparency);	  // Set the transparency
	}

	VOID FadeInAnimation() const
	{
		for (int i = minimum; i <= maximum; i++)
		{
			SetTransparency(i);
			Sleep(speed);
		}
	}

	VOID FadeOutAnimation() const
	{
		for (int i = maximum; i >= minimum; i--)
		{
			SetTransparency(i);
			Sleep(speed);
		}
	}

	VOID FadeInOutAnimation(int amount, bool threaded) const
	{
		if(threaded)
		{
			std::thread([&] {
				this->IOAnimator(amount);
			}).detach();
		}
		else
		{
			IOAnimator(amount);
		}
	}

	VOID IOAnimator(int amount) const
	{
		for (int j = 0; j < amount; j++)
		{
			for (int i = minimum; i <= maximum; i++)
			{
				SetTransparency(i);
				Sleep(speed);
			}
			for (int i = maximum; i >= minimum; i--)
			{
				SetTransparency(i);
				Sleep(speed);
			}
		}
	}

	VOID SetMaximum(int maximum)
	{
		this->maximum = maximum;
	}

	VOID SetMinimum(int minimum)
	{
		this->minimum = minimum;
	}

	VOID SetSpeed(int speed)
	{
		this->speed = speed;
	}
};

inline FadeAnimator::FadeAnimator(int maximum, int minimum, int speed)
{
	consoleWnd = GetConsoleWindow();
	this->maximum = maximum;
	this->minimum = minimum;
	this->speed = speed;
}