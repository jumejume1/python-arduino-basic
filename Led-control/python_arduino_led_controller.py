import serial
import tkinter
import customtkinter

customtkinter.set_appearance_mode("System")  # Modes: system (default), light, dark
customtkinter.set_default_color_theme("blue")  # Themes: blue (default), dark-blue, green

app = customtkinter.CTk()  # create CTk window like you do with the Tk window
app.geometry("400x240")
app.title("Maker Tutor-Python arduino LED controller")

servo_value = 0
txt = "Arduino LED Controller" 

leds = [0,0,0]

arduino_ready = True
arduino = serial.Serial(port = 'COM10', baudrate = 115200, timeout=1)

def write_data(led1,led2,led3):
    
    
    delim = bytes(';', "utf-8")
     
    arduino.write(bytes(str(led1), "utf-8"))    
    arduino.write(delim)
    arduino.write(bytes(str(led2), "utf-8"))    
    arduino.write(delim)
    arduino.write(bytes(str(led3), "utf-8"))    
    arduino.write(delim)
   
    return 1

def button1_function():
    
    print("button1 pressed --> LED1 ON")
    leds[0] = 1
    write_data(leds[0],leds[1],leds[2])

def button2_function():
    
    print("button2 pressed --> LED1 OFF")
    leds[0] = 0
    write_data(leds[0],leds[1],leds[2])
    
def button3_function():
    
    print("button3 pressed --> LED2 ON")
    leds[1] = 1
    write_data(leds[0],leds[1],leds[2])
    
def button4_function():
    
    print("button4 pressed --> LED2 OFF")
    leds[1] = 0
    write_data(leds[0],leds[1],leds[2])

def button5_function():
    
    print("button5 pressed --> LED3 ON")
    leds[2] = 1
    write_data(leds[0],leds[1],leds[2])

def button6_function():
    
    print("button6 pressed --> LED3 OFF")
    leds[2] = 0
    write_data(leds[0],leds[1],leds[2])
    
    

label_width = customtkinter.CTkLabel(master=app, text=txt)
label_width.place(relx=0.1, rely=0.1, anchor=tkinter.W)



# Use CTkButton instead of tkinter Button
# LED 1
button1 = customtkinter.CTkButton(master=app, text="LED1 - ON", command=button1_function)
button1.place(relx=0.3, rely=0.3, anchor=tkinter.CENTER)

button2 = customtkinter.CTkButton(master=app, text="LED1 - OFF", command=button2_function)
button2.place(relx=0.7, rely=0.3, anchor=tkinter.CENTER)

# LED 2
button3 = customtkinter.CTkButton(master=app, text="LED2 - ON", command=button3_function)
button3.place(relx=0.3, rely=0.5, anchor=tkinter.CENTER)

button4 = customtkinter.CTkButton(master=app, text="LED2 - OFF", command=button4_function)
button4.place(relx=0.7, rely=0.5, anchor=tkinter.CENTER)

# LED 3
button5 = customtkinter.CTkButton(master=app, text="LED3 - ON", command=button5_function)
button5.place(relx=0.3, rely=0.7, anchor=tkinter.CENTER)

button6 = customtkinter.CTkButton(master=app, text="LED3 - OFF", command=button6_function)
button6.place(relx=0.7, rely=0.7, anchor=tkinter.CENTER)

app.mainloop()
