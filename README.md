# Voice-Controlled-Car
A Voice Controlled Car Project using Tiva Tm4c123 Micro-Controller
![Diagram1 (1)](https://user-images.githubusercontent.com/82976709/211874060-1c9e0d4e-0f77-462a-9b49-d85c2913686d.jpg)
## How to run this project?
First of all, you simply need to download the above files and for understanding, I have provided brief expalanation below:

The project have been coded in Keil Microvision 4. You can download it from the website of Keil 4.
For the details of various lines of codes, you are encouraged to go through the datasheet of tiva micro-controller at http://www.ti.com/lit/gpn/tm4c123gh6pm
### Attached Document
This will help you to understand the project and have a overview about what's going on.
### Main File
main.c is the file which is controlling the whole car, in the first few lines, I have included all the header files for UART(Used for Bluetooth Communication), Timer(Used for
Speed Control), GPIO(used for direction control of Car).
Data Sheet for Motor Driver can be found at http://www.handsontec.com/dataspecs/L298N%20Motor%20Driver.pdf

Data Sheet for HC-05 Bluetooth Module at https://components101.com/sites/default/files/component_datasheet/HC-05%20Datasheet.pdf

In the main function, I have written multiple functions, which will be called at the specific instruction. I have aded basic functions, you can improve the code by adding 
operations like slow/fast direction change by writing few lines of code.

## How to Connect with me?
If you are unable to understand anything in the code, you can contact me through my Linkedin @https://www.linkedin.com/in/muhammad-hammad-bashir-5256391b5/
