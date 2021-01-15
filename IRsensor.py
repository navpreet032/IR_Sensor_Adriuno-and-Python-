import serial
import pyautogui
import keyboard
import time
serial_port = 'COM4';
baud_rate = 9600; #In arduino, Serial.begin(baud_rate)
write_to_file_path = "output.txt";

output_file = open(write_to_file_path, "w+");
ser = serial.Serial(serial_port, baud_rate)
while True:
    line = ser.readline();
    L_code ="2"
    R_code ="1"
    line = line.decode("utf-8") #ser.readline returns a binary, convert to string
    string = line.rstrip()

    if string == L_code :
     #  keyboard.release('up')
       keyboard.press('up')
       #pyautogui.press('down')  
       time.sleep(.1)
       output_file.write(line);

    if string == R_code:
    # keyboard.release('down')
     keyboard.press('down')
    # pyautogui.press('up')  
     time.sleep(.1)
     output_file.write(line);
    if (string != R_code) and (string != L_code):
        keyboard.release('up')
        keyboard.release('down')