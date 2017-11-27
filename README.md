# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Reflection

1. Tried upto 40mph Throttle with manual tuning of parameters.
2. Used init tau values of PID as Kp = 0.2, Ki = 0.005, Kd = 3.0.
3. Used p\_error = 0.07, i\_error = 0.0, d\_error = 0.0 init values.
4. Tuning params:
	- Started with throttle as 0.4.
	- Reduced the throttle to 0.1 when steering value is out of bounds [-1, 1].
	- Skip doing the above step if this is the 1st time we see out of bounds value. I did in a very crude way. Definetly needs improvement there.
	- Also, when throttle is reduced to 0.1, clamp the steering value if it is out-of-bounds.
	- Works "ok" upto 0.4 throttle. Beyond that, it doesn't.
	- To improve the car movement around the track, I tried implementing Twiddle, but failed to match the lecture algorithm to the simulator.
	- Also, tried playing with tuning tau parameters with other methods, but failed to acheive consistent track completions.
	- So went back to throttle as 0.4 and reducing it to 0.1 when necessary, before bumping back to 0.4 again. This acheived reasonable car movement around the track.

	
[//]: # (Image References)

[image1]: ./Images/p.png "Proportional Control"
[image2]: ./Images/pd.png "Proportional-Differential Control"
[image3]: ./Images/pid.png "Proportional-Integral-Differential Control"


### P Control

Only doing Proportional Control yields expected results, where the car oscillates. The effect is demonstrated below.

[![alt text][image1]](https://youtu.be/Vkt2f7XrGVo "Proportional Control")


### PD Control

Adding Differential Control to P, yields good results for most of the track. The Cross track error (CTE) converges nicely. But it fails on hard turn. The effect is demonstrated below.

[![alt text][image2]](https://youtu.be/sXCLhvGfGvY "Proportional-Differential Control")


### PID Control

Adding Integral Control to the above PD Control yields good results for all of the track. The Cross track error (CTE) converges nicely. The effect is demonstrated below.

[![alt text][image3]](https://youtu.be/i8qi5n2-TFI "Proportional-Integral-Differential Control")


## Improvements
Even though the car completes the track without major issues with throttle 0.4, it definetly needs a different way of tuning the parameters for faster speeds and making the car oscillate less. 