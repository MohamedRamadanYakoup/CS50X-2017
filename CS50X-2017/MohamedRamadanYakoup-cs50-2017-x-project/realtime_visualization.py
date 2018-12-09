import serial
import matplotlib.pyplot as plt
import numpy as np
from drawnow import *

sonic = []
count = 0
plt.ion()   																# use a live data
data = serial.Serial('/dev/ttyACM0', 9600)   								# read the data from the serial port

def p_Fig():																# polt the data to the graph
	plt.plot(sonic, 'bo-', label = 'Movig_Distance')
	plt.title('Measuring Distance')											# put a title to the graph
	plt.grid(True)															# use a grid on the graph
	plt.ylabel('Distance')													# call distance on y axis
	plt.legend(loc = 'upper left')											# put a legend to help monitring


while True:
	while (data.inWaiting() == 0): 											# wait until you get the data
		pass 																# if there is no data do nothing


	dataString = data.readline().decode('utf-8')[:-1]	   					# get string data from the serial port

	ultra = (map(float, dataString.strip('\n').strip('\t').split(' ')))		# convert data to float
	sonic.append(ultra)														# append the data to the array
	drawnow(p_Fig)															# use drawnow to get data to live

	plt.pause(.000001)														# pause the graph for a short time

	count = count + 1
	if (count > 10):														# use a counter to control plots
		sonic.pop(0)														# pop out the element
