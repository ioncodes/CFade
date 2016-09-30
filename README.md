# CFade
Console Fader Animator class in C++. This is the more advanced version of [FadingConsole](https://github.com/ioncodes/FadingConsole).

# Screenies
[GIF](http://i.imgur.com/xvkhFpQ.gifv)

# Usage

```c++
#include "fader.hpp"
#include <iostream>
#include <string>

int main()
{
	FadeAnimator fa = FadeAnimator(255, 150, 12); // new Animator. int maximum, int minimum, int speed
	std::cin.get();
	std::cout << "FadeInAnimation";
	fa.FadeInAnimation();                         // Fade in animation
	std::cin.get();
	std::cout << "FadeOutAnimation";
	fa.FadeOutAnimation();                        // fade out animation
	std::cin.get();
	fa.FadeInOutAnimation(10, true);              // fade in and out animation. int amount, bool threaded
	std::string str;
	getline(std::cin, str);
	return 0;
}
```

## FadeAnimator
The constructor takes 3 arguments. The first and second one is the maximum transparency and the second is the minim value. 

Both values must be between 0 and 255.

The third one is the speed. Be careful with it, because as of now it uses Sleep() to create the animation. The less the value, 
the faster the animation. Recommended is around 10.

## FadeInAnimation & FadeOutAnimation
These don't take any arguments. 

FadeInAnimation will start with minimum and ends with maximum. (increasing)

FadeOutAnimation will start with maximium and ends with minimum. (decreasing)

Both will block user input.

## FadeInOutAnimation
This one takes 2 arguments. The first one is the amount of times to fade in and out. It uses minimum and maximum.

1 iteration will fade in AND out! Which means, if you set amout to 2 it will: fade in, fade out, fade in, fade out.

The second argument indicates wether it should start the animation as new thread or not. If you start it with false it will block the user input.

## Setters
To manipulate minimum, maximum and speed at runtime you can use these:

```c++
SetMaximum(int)
SetMinimum(int)
SetSpeed(int)
```

To set the transparency to a specific value, you can use this one:

```c++
SetTransparency(int)
```
