import serial
import tkinter
import customtkinter

customtkinter.set_appearance_mode("System")  # Modes: system (default), light, dark
customtkinter.set_default_color_theme("blue")  # Themes: blue (default), dark-blue, green

app = customtkinter.CTk()  # create CTk window like you do with the Tk window
app.geometry("400x240")
app.title("Maker Tutor-Python arduino Servo controller")

servo_value = 0
txt = "Servo angle: {}" . format(servo_value)

angles = [0]

arduino_ready = True
arduino = serial.Serial(port = 'COM10', baudrate = 115200, timeout=1)

def write_data():
    global servo_value ,angles
    
    delim = bytes(';', "utf-8")
    angles = ( bytes(str(int(servo_value)), "utf-8"))

    arduino.write(bytes(str(int(servo_value)), "utf-8"))    
    arduino.write(delim)
   
    return 1

def button_function():
    
    print("button pressed")
    
    
    write_data()
    
    

def slider_event(value):
    global txt , servo_value
    servo_value = int(value)
    txt = "Servo angle: {}" . format(servo_value)
    label_width.configure(text = txt)
    print(servo_value)

label_width = customtkinter.CTkLabel(master=app, text=txt)
label_width.place(relx=0.1, rely=0.2, anchor=tkinter.W)

slider = customtkinter.CTkSlider(master=app, from_=0, to=180, command=slider_event)
slider.set(0)
slider.place(relx=0.5, rely=0.3, anchor=tkinter.CENTER) 

# Use CTkButton instead of tkinter Button
button = customtkinter.CTkButton(master=app, text="Action", command=button_function)
button.place(relx=0.5, rely=0.5, anchor=tkinter.CENTER)

app.mainloop()
