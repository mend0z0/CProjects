from tkinter import *
from turtle import bgcolor, left, window_width

root =  Tk()
#changing the title of the GUI
root.title("BLDC Driver")
#adding an icon to the top left 
root.iconbitmap("D:/Projects/SiavashTP/OSSH/C/BLDCDriver/FW/V1_09092022/1- Design Files/App/BLDC_GUI/icon/BLDCDriver_logo.ico")
#adding a window size
root.geometry("400x400")
#changing the background color
#root.configure( background = "#1F1B24")
root.configure( background = "#212121")

rpmLbl = Label( root, text = "Set RPM", font = "TimesNewRoman", background = "#212121", foreground = "#4BB2F9")
rpmLbl.grid(row = 0, column = 0, padx = 10, pady = 5, sticky = "w")
setRPM = Entry( root, width = 15, borderwidth=0.25, font = "Calibri", background = "#1F1B24", foreground = "white", highlightthickness = 0.5, highlightbackground = "#212121", highlightcolor= "#4BB2F9")
setRPM.insert(0, "Between 0 ~ X RPM")
setRPM.grid(row = 1, column = 0, padx = 5, pady = 5)

currentLbl = Label( root, text = "Set Max Current", font = "TimesNewRoman", background = "#212121", foreground = "#4BB2F9")
currentLbl.grid(row = 2, column = 0, padx = 5, pady = 5, sticky = "w")
setCurrent = Entry( root, width = 15, borderwidth = 0.1, font = "Calibri", background = "#1F1B24", foreground = "white")
setCurrent.insert(0, "Between 0 ~ X Amp")
setCurrent.grid(row = 3, column = 0, padx = 5, pady = 5)

voltageLbl = Label( root, text = "Set Max Voltage", font = "TimesNewRoman", background = "#212121", foreground = "#4BB2F9")
voltageLbl.grid(row = 4, column = 0, padx = 5, pady = 5, sticky = "w")
setVoltage = Entry( root, width = 15, borderwidth = 0.1, font = "Calibri", background = "#1F1B24", foreground = "white")
setVoltage.insert(0, "Between 0 ~ X Volts")
setVoltage.grid(row = 5, column = 0, padx = 5, pady = 5)

#here I should add available devices


runButton = Button(root, text = "Run", font = "Calibri", background = "#00316E", foreground = "white", height = 3, width = 10)
runButton.grid(row = 3, column = 3, padx = 25, pady = 25, sticky = "e")



root.mainloop()