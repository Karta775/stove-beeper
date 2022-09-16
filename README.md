# stove-beeper

### The problem
This is a little program I made for the Arduino to solve a problem with student accommodation: the stove turns itself off after some amount of time, usually without giving any indication to the user. Forget about cooking something like a soup, you have to wait by the stove otherwise your food wont cook.

### The solution
A light sensor is stuck onto the control box for the stove, when the light turns off the Arduino makes a beeping noise until it's either muted, or the stove turns back on. I thought about actuating a servo to automatically press the button, but that's a really bad idea for obvious safety reasons.
