from tkinter import *

root =  Tk()
root.title("BLDC Driver")

curLimButton = Button(root, text = "Set")
curLimButton.pack()

#Setting Current Limit
currentLimit = Entry(root, width = 25, borderwidth= 2)
currentLimit.insert( 0, "Set a Current limit between XX to YY Amp")
currentLimit.pack()
#Setting Voltage Limit
voltageLimit = Entry(root, width = 25, borderwidth= 2)
voltageLimit.insert(0, "Set the limit input Voltage")
voltageLimit.pack()
#Setting Power Limit
powerLimit = Entry( root, width = 25, borderwidth= 2)
powerLimit.insert( 0, "Set the Max Power")
powerLimit.pack()

emfVoltage = 0

EMF_WU = Label( root, text = emfVoltage)
EMF_UV = Label( root, text = emfVoltage)
EMF_VW = Label( root, text = emfVoltage)

currents = 0

current_U = Label( root, text = currents)
current_V = Label( root, text = currents)
current_W = Label( root, text = currents)

#current_Total = Label( root, text = ())

torque = Label( root, text = "Torque")
temperature = Label( root, text = "Temp")


#Creating a lablel widget
myLable = Label(root, text = "Hello World!")
myLabel = Label(root, text="Griding!")
#shoving it onto the screen
#myLable.pack()

#using grids to manage the location of texts
#myLabel.grid(row=10, column=2)

root.mainloop()