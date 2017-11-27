# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Reflection

1. Tried upto 40mph Throttle with manual tuning of parameters.
2. Used init tau values of PID as Kp = 0.2, Ki = 0.005, Kd = 3.0.
3. Used p_error = 0.07, i_error = 0.0, d_error = 0.0 init values.
4. Tuning params:
	- Started with throttle=0.4
	- Reduce the throttle to 0.1 when steering value is out of bounds [-1, 1].
	- Skip doing the above 2 steps if this is the 1st time we see out of bounds value. Did in a very crude way. Definetly needs improvement there.
	- Also, when throttle is reduced to 0.1, clamp the steering value if it is out-of-bound.
	- Works "ok" upto 0.4 throttle. Beyond that, it doesn't.
	- To improve, I tried implementing Twiddle, but failed to match the class algorithm to the simulator.
	- Also, tried playing with tuning tau parameters with other methods, but failed to acheive consistent track completions.

###P Control

Only doing Proportional Control yields expected results, where the car oscillates. The effect is demonstrated below.

<iframe width="560" height="315" src="https://www.youtube.com/embed/Vkt2f7XrGVo" frameborder="0" gesture="media" allowfullscreen></iframe>

###PD Control

Adding Differenetial Control yields good results for most of the track. The Corss track error (CTE) converges nicely. But it fails on hard turn. The effect is demonstrated below.

<iframe width="560" height="315" src="https://www.youtube.com/embed/sXCLhvGfGvY" frameborder="0" gesture="media" allowfullscreen></iframe>

###PID Control

Adding Integral Control to the above PD Control yields good results for all of the track. The Corss track error (CTE) converges nicely. The effect is demonstrated below.

<iframe width="560" height="315" src="https://www.youtube.com/embed/i8qi5n2-TFI" frameborder="0" gesture="media" allowfullscreen></iframe>

## Improvements
Even though the car completes the track without major issues with throttle 0.4, it definetly needs a different way of tuning the parameters for faster speeds and making the car oscillate less. 