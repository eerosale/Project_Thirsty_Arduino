##Arduino LED matrix UI control
##Ben Katz, June 15, 2011
##www.build-its.blogspot.com


import  time, serial, random
from Tkinter import *

height = 600
width = 800

enabled = [1, 1, 1, 1, 1, 1, 1, 1, 1]   #This list cointains the state of each button: 1 = disabled, -1 = enabled

buttons = []

directions = [NW, N, NE, W, '', E, SW, S, SE]

canvas = Canvas(highlightthickness=0, height=height, width=width)
canvas.master.title("Project Thirsty")
canvas.configure(background='lemonchiffon')
canvas.grid()

class Arduino:
    connection = None
    def __init__(self, path):
        self.connection = serial.Serial(path, 9600)      
        pass
    def __del__(self):
        self.connection.close()
        pass
    def isOpen(self):
        return self.connection.isOpen()
    def writeLine(self, line):
        if self.isOpen():
            self.connection.write(line)
            time.sleep(0.1)


arduino = Arduino(4)       #This sets the arduino to serial port 2.  On PC's this will probably be COM3
                           # On macs this port will be something like  /dev/tty.usbmodem
arduino.writeLine('!')     #The arduino program resets all the led's when it recieves '!' over serial

def ledWrite(i):
   print(i)
   arduino.writeLine(str(i))                    
   if enabled[i] == 1:
      buttons[i].configure(bg = 'dodgerblue')      #Tkinter can take hexidecimal color codes, so you can customize your UI
   else:
      buttons[i].configure(bg = 'orange')
   buttons[i].update()
   enabled[i] = enabled[i] * -1

for i in range(9):         #this creates all the buttons, so you don't need a line to create and grid each button
   x = i
   i = Button(height = 10, width = 20,  bg = 'grey', relief = FLAT, command = lambda arg=x: ledWrite(arg))    #'arg = x' may seem repetitive, but if it is not included,
                                                                                                               #the buttons pass the final value of x to 'ledWrite' , which is 8
   i.grid(column = 0, row = 0, columnspan = 3, rowspan = 3, sticky = directions[x])
   i.number = x
   buttons.append(i)

print '1'
canvas.mainloop()

arduino.writeLine('!')      #when you exit the UI, all the LED's are reset to 'off'
print '!'
arduino.connection.close()    #The serial connection is also closed when you quit, so you can switch between programming in python and the arduino IDE without resetting your arduino

