# DRONOTECH-Drone-Delivery
“Arduino-based drone payload drop system (SIH project)”
# DRONOTECH – Arduino-Based Payload Drop System

This project is a simple **Arduino-controlled servo mechanism** used for payload dropping in a drone prototype.  
The system was created as part of a **Smart India Hackathon (SIH) hardware project**.

When the button is pressed, the servo motor rotates to **open the payload gate**, drops the object, and then closes automatically.

---

## 🔧 Hardware Used
- Arduino UNO  
- SG90 Servo Motor  
- Push Button  
- Jumper Wires  
- Optional: LED/Buzzer for indication  

---

## ⚙️ Working
1. The push button is connected using **INPUT_PULLUP**.  
2. When the button is pressed:  
   - The servo moves to **open** position  
   - Waits for 1 second  
   - Moves back to **closed** position  
3. An optional LED/Buzzer can be used to indicate a successful drop.

---

## 📁 Project Structure

```
Arduino-Code/
   └── dronotech_button_drop.ino

Media/
   ├── images/      (prototype images)
   └── videos/      (demo footage)

README.md
```

---

## ▶️ Demo Media
Images and videos of the working prototype are available in the **Media/** folder.

---

## 📄 License
This project is open for educational and academic use.
