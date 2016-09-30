#include "fader.hpp"
#include <iostream>
#include <string>

int main()
{
	FadeAnimator fa = FadeAnimator(255, 150, 12);
	std::cin.get();
	std::cout << "FadeInAnimation";
	fa.FadeInAnimation();
	std::cin.get();
	std::cout << "FadeOutAnimation";
	fa.FadeOutAnimation();
	std::cin.get();
	fa.FadeInOutAnimation(10, true);
	std::string str;
	getline(std::cin, str);

	return 0;
}