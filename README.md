# Rotary-Valve-Testing-Jig

CONNECTING THE HALL EFFECT SENSOR TO ARDUINO 
- Orange wire is the ground (TOP)
- Brown wire is the signal (MIDDLE)
- Grey is the VCC (5V) (BOTTOM) 

CONNECTING STEPPER MOTOR TO DRIVER 
-The motor has 6 wires but we only connect 4
- A multimeter can be used to check which two wires make a phase. But these are the observations made in the delvibiss motor:
- BLACK AND GREEN ARE ONE PHASE
- BLUE AND RED ARE ONE PHASE

NUMBER OF STEPS TO MAKE DIFFERENT ROTATIONS 
- The motor moves 1.8 degrees each step which is 200 steps to make a 360 degree rotation
- But when connected to the assembly, it requires 1520 steps to make a 360 degree rotation with the gears and go back to home
  - 380 steps to make a 90 degree step.
