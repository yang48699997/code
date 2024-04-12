import Hiwonder
from Hiwonder import LSC
from Hiwonder import PWMServo
import time
import math

# initialize variables
_distance = 0
_angle = 0
_vary = 0
_turning = 0
_small = 0
_left = 0
_right = 0
_gap = 0
_temp = 0
_var_8f6c_52a8_6b21_6570 = 0



def start_main():
  global _distance
  global _angle
  global _vary
  global _turning
  global _small
  global _left
  global _right
  global _gap
  global _temp
  global _var_8f6c_52a8_6b21_6570
  global sonar_2
  global digitalTube_6

  _distance = 9.1
  _angle = 75
  _vary = 10
  _turning = 500
  _small = 3
  _left = 0
  _right = 0
  _gap = 10
  _temp = 0
  _var_8f6c_52a8_6b21_6570 = (90/_vary)
  _temp = _distance
  _distance = int(math.sqrt(_distance*_distance+_gap*_gap+2*_distance*_gap*math.cos(math.fabs(_angle))))
  _angle = int(math.acos((_distance*_distance+_gap*_gap-_temp*_temp)/(2*_distance*_gap))*(1 if _angle >=0 else -1))
  _turning = int(500-(_angle*3.7))
  print(_distance)
  print(_angle)
  print(_turning)