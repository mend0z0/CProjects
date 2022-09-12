from telnetlib import COM_PORT_OPTION
from tkinter import *
from turtle import bgcolor, left, window_width
import serial.tools.list_ports


INSERTFONT = ("Sans Pro Code", 10,"italic")
LABLEFONT = ("TimesNewRoman", 10, "bold")
LABELCOLOR_BG = "#212121"
LABELCOLOR_FG = "#4BB2F9"

root =  Tk()
#changing the title of the GUI
root.title("BLDC Driver")
#adding an icon to the top left 
root.iconbitmap("D:/Projects/SiavashTP/OSSH/C/BLDCDriver/FW/V1_09092022/1- Design Files/App/BLDC_GUI/icon/BLDCDriver_logo.ico")
#adding a window size
root.geometry("400x220")
#changing the background color
root.configure( background = "#212121")

#variables
maxCurrent = 0
maxVoltage = 0
maxRPM = 0
inputDevices = serial.tools.list_ports.comports()
selectedDevice = 0
selectedDevice = StringVar()
selectedDevice.set("Choose a Device")


#Frames
lblBox = LabelFrame( root, padx = 10, pady = 10, background = LABELCOLOR_BG, border = 0)
buttonBox = LabelFrame( root, padx = 15, pady = 15, background = LABELCOLOR_BG, border = 0)

#Labels
rpmLbl = Label( lblBox, text = "Set RPM", font = LABLEFONT, background = LABELCOLOR_BG, foreground = LABELCOLOR_FG)
currentLbl = Label( lblBox, text = "Set Max Current", font = LABLEFONT, background = LABELCOLOR_BG, foreground = LABELCOLOR_FG)
voltageLbl = Label( lblBox, text = "Set Max Voltage", font = LABLEFONT, background = LABELCOLOR_BG, foreground = LABELCOLOR_FG)
deviceLbl = Label( lblBox, text = "Input Devices", font = LABLEFONT, background = LABELCOLOR_BG, foreground = LABELCOLOR_FG)


#dropDown menu
selectDevices = OptionMenu( lblBox, selectedDevice, inputDevices)
selectDevices.config(width = 25, 
                        font = INSERTFONT,
                        border = 1,
                        borderwidth = 0.1, 
                        background= LABELCOLOR_BG,
                        foreground= "white",
                        highlightthickness = 0.5, 
                        highlightbackground = "#212121"
)

#Entries
setRPM = Entry( lblBox, 
                width = 25, 
                borderwidth=0.25, 
                font = INSERTFONT, 
                background = LABELCOLOR_BG, 
                foreground = "white", 
                highlightthickness = 0.5, 
                highlightbackground = "#212121", 
                highlightcolor= "#4BB2F9"
)
setRPM.insert(0, "(0 ~ X) RPM")
setCurrent = Entry( lblBox, 
                width = 25, 
                borderwidth=0.25, 
                font = INSERTFONT, 
                background = "#1F1B24", 
                foreground = "white", 
                highlightthickness = 0.5, 
                highlightbackground = "#212121", 
                highlightcolor= "#4BB2F9"
)
setCurrent.insert(0, "(0 ~ X) Amp")
setVoltage = Entry( lblBox, 
                width = 25, 
                borderwidth=0.25, 
                font = INSERTFONT, 
                background = "#1F1B24", 
                foreground = "white", 
                highlightthickness = 0.5, 
                highlightbackground = "#212121", 
                highlightcolor= "#4BB2F9"
)
setVoltage.insert(0, "(0 ~ X) Volts")

#Functions
def RunCmd():
    #Getting the input values
    maxRPM = setRPM.get()
    maxCurrent = setCurrent.get()
    maxVoltage = setVoltage.get()
    #Sending the values to Microcontroller

    #opening the observation panel (Another window)
    root.destroy()
    return

#Buttons
runButton = Button(buttonBox, 
                    text = "Run", 
                    command = RunCmd,
                    font = ("Calibri", 11, "bold"), 
                    background = "#00316E", 
                    foreground = "white", 
                    height = 2, 
                    width = 10,
                    border = 0.3
)

#Griding
lblBox.grid(row = 0, column = 0, padx = 5, pady = 3)
buttonBox.grid(row = 0, column = 1, padx = 5, pady = 3)

rpmLbl.grid(row = 0, column = 0, padx = 5, pady = 1, sticky = "w")
setRPM.grid(row = 1, column = 0, padx = 5, pady = 1)
currentLbl.grid(row = 2, column = 0, padx = 5, pady = 1, sticky = "w")
setCurrent.grid(row = 3, column = 0, padx = 5, pady = 1)
voltageLbl.grid(row = 4, column = 0, padx = 5, pady = 1, sticky = "w")
setVoltage.grid(row = 5, column = 0, padx = 5, pady = 1)
deviceLbl.grid(row = 6, column = 0, padx = 5, pady = 1, sticky = "w")
selectDevices.grid(row = 7, column = 0, padx = 5, pady = 1, sticky = "w")

runButton.grid(row = 0, column = 0, padx = 25, pady = 25)

#here I should add available devices


root.mainloop()