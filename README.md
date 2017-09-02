# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

## Description of P, I and D component in the implementation
The P component in this implementation is used to associate the steering angle (the control authority in this case) with respect to the cross track error (CTE). In theory it will gradually reduce the CTE to zero, however due to the effect of vehicle dynamics, the vehicle will tend to cross the center line of the lane under a P controller and result into a undesired oscillation (overshoot) of vehicle trajectory. This effect is demonstrated in this video. 

The D component in this implementation is used to associate the rate of change of CTE with respect to the steering angle. It take consideration of the rate of change of CTE as vehicle corrects its position to counter the tendency of overshoot. The effect of implementing of D component is that as the vehicle graduately approaches to the center of the lane, the rate change of CTE becomes smaller, and then the steering angle becomes smaller or even to be in the opposite direction to counter the tendency of the overshoot of vehicle position. This effect is demonstrated in this video, as the D component is included in the controller, the entire trajectory of vehicle becomes much smoother compared to that of P cotroller. 

The I component in this implementation is used to correct any bias of vehicle position with respect to the center of the lane. It associates the accumulated CTe with respect to the steering angle. The net effect is that the a small (the magnitude depends on the assgined gain) steering angle will be assigned to gradually correct the bias of vehicle position with respect to the center. In this particular cases, since there are many alternative left and right turns occured within the track, the bias of vehicle position is not really accumulated since it is corrected largely by the P and D components during the alternative turning process. That said, one can still observe a slight bias due to the remove of I component in the second video, compared to the demo video taken with PID controller implemented. 

## Description of tuning process of PID controller

The manual tuning process of PID controller is described as below:
Step 1, set Kp, Ki, and Kd to 0. This will disable them for now.
Step 2, gradually increase Kp until the vehicle can track a relatively straight lane. The oscillation might occur eventually but can be much eliminated in the step 3. 
Step 3, gradually increase Kd until any overshoot observed is fairly minimal. But be careful with the increments as too much Kd will result overshoot as well.
Step 4, gradually increase Ki until the bias error that is existing is eliminated. Start with a really small number as 0.0001.
The finale PID controller tuned is P = 0.14, I = 0.00030, D = 3.0;



