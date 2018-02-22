# Becker-test-version
The purpose of this robot is to test and develop human-robot interaction
applications, also control models for non-linear systems.
## Introduction
R.Becker :smiley_cat: is an inverted pendulum on two wheels, the idea of
this kind of design is the dynamically stable robots are inherently safe 
to work in human environments.

<img src="/Images/basica.jpg" width="250">

*Inverted pendulum on two wheels*

The inverted pendulum is the simplest version of a dynamically stable 
robot.

The operation of Becker consist in an IMU that measure the inclination
angle, a control module and two DC. motors that correct the
disturbances.

<img src="/Images/PSIBecker.png" width="250">


## Structure
The shape of the robot consist in a base with a column in the middle, in 
the base are two axis that connect the wheels with the motors, the axis
are support by two ball bearings each one.

<img src="/Images/Becker.jpg" width="300">

### Characteristics
* Column
is a 20X20 aluminium IPS with one meter length.
* Base
is an aluminium plate of 1/4 inches (6.35mm) with a size of 20cm x 60cm.
* Ball bearing base
is a square print in PLA with a density of 75% and a hexagonal fill 
pattern, it fits a ball bearing 1/4" x 5/8".
* Axis
they are made of stainless steel with a length  of 12cm.

*3d models and planes are in the ![models folder](/models)*
 
## Electronics
Electronic system is composed by three main parts 
* Power Source
* Control Unit
* Power Stage

<img src="/Images/DG.jpg" width="400">

### Power Source   :battery:
Becker is powered by two batteries, one for the control system and the 
other for the motors. this is in order to avoid interference caused by
the motors in the control system.

The control system battery have a charge capacity of 10,000 mAh with
and output of 5V 2A, the battery use an USB port to as terminal.

The motors battery is a 5000mAh LiPo with an output of 11.1v and a 
maximum discharge rate of 50A.

### Control Unit  :computer:
Becker use a Raspberry Pi B2+ as CPU, IMU are communicated using I²C, 
Encoders, PWM and direction pins of the motor drivers are conected to 
GPIOs of the CPU (throught optocouplers).

### Power Stage  :low_brightness:
It's made of two parts, the first is the motor drivers, and the second 
is an optocoupler array.

Motor drivers (VHN5019) function is to provide enough curren to motors,
their logic circuit work at 5V, they are supply by a buck type source.

Optocoupler array function is to isolate the motor circuit and the 
control circuit.

*Electronic diagrams are in the ![diagrams folder](/diagrams)*

## Simulation
Becker dynamic model simulation was made using matlab.

### Dynamic Model
The dynamic model of becker is an inverted pendulum considering that 
it's behavior is linear near vertical stability point.

The model equations and space state analysis are explained in detail in
the thesis "Desarrollo de un robot de dos ruedas dinámicamente estable"
the document is in the ![documents folder](/documents).

Dynamic model diagram in SimuLink is as follows.

<img src="/Images/DinamicModel.png" width="600">


### Control System 
The control system is an modification of ac classic PID controller,
this version only use the integrative part in one of the inputs, is 
called PD+I.

<img src="/Images/pdpi.png" width="600">
  
In simulation the control was robust enough to compensate perturbances 
of 30° in inclination. The experiments in with the prototipe show
an enormous diference, the real robot can compensare only 4° 
disturbances, this fluctuation is because the suposition of a linear
behaivor.

*Control model and dynamic model simulations are in 
 ![simulations folder](/simulations)*
  

## R.O.S.
Becker use R.O.S. Indigo, the node diagram is as follow.

<img src="/Images/g2.jpeg" width="400">


### Encodernode
This node read the signals of motor's encoders and calculate the angle 
of each motor with a sample rate of 10,700 times per second.

### Imunode
Imunode obtains the measurements of the 3 axis accelerometer and 
gyroscope and use a complementary filter to calculate the angle. 

### Controlnode
The contolnode is the main node of Becker, it read the messages of the
encodernode and imunode asynchronously, calculate the derivative and
integrative values and generate the control signal for each wheel.

### Motornode
Motornode generate the PWM and direction signals for the motor drivers.

## Possible Improvements
The next list shows improvements that help the Becker's performance

* An adaptative control system.
* Externar microcontroller to generate PWM signals.
* A new CPU version.

These points are better explained in the ![thesis](/documents).

## Videos
In this links are some videos of Becker working.

[Becker video](https://youtu.be/0lUVMNjOlis)

## Operation
