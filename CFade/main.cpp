#include "fader.hpp"
#include <iostream>
#include <string>

FadeAnimator fa = FadeAnimator(255, 150, 12);

int main()
{
	fa.FadeInAnimation();
	std::cin.get();
	fa.FadeOutAnimation();
	std::cin.get();
	fa.FadeInOutAnimation(10, true);
	std::string str;
	getline(std::cin, str);
	return 0;
}