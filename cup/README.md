# Making the Cup
## Solder the PCB


### 1. Solder the 100nF capacitor below the audio jack footprint
Capacitor code 104, not printed on chip, usually brown
![](https://github.com/kimitobo/Timecapsules/blob/master/cup/PCB_solder_guide/20181013_185612.jpg?raw=true)

---

### 2. Solder 2x 22Kohm voltage divider resitors undet the first cap
Resistor code 223
![](https://github.com/kimitobo/Timecapsules/blob/master/cup/PCB_solder_guide/20181013_190016.jpg?raw=true)

---

### 3. Solder 470ohm LED resistor on the opposite side of the center
Resistor code 471
![](https://github.com/kimitobo/Timecapsules/blob/master/cup/PCB_solder_guide/20181013_190758.jpg?raw=true)

---

### 4. Solder the audio jack in place
Start with one solder pad, pay attention to aligning the feet on the pads, solder remaining 5 feet.
![](https://github.com/kimitobo/Timecapsules/blob/master/cup/PCB_solder_guide/20181013_192903.jpg?raw=true)

----

### 5. Solder the chip socket in place
Pads are small, bend pinds 90 degrees to sides, trim to match the footprint, start with one and align.
![](https://github.com/kimitobo/Timecapsules/blob/master/cup/PCB_solder_guide/20181013_194346.jpg?raw=true)

---

### 6. Place the 3mm white LED in the middle, longer leg (anode) pointing to the LED resistor. 
The picture does not yet have the jack or socket in place. Recommended to do these before the LED
![](https://github.com/kimitobo/Timecapsules/blob/master/cup/PCB_solder_guide/20181013_191348.jpg?raw=true)

---

### 7. Bend down the anode and solder on the plate next to the LED resistor
![](https://github.com/kimitobo/Timecapsules/blob/master/cup/PCB_solder_guide/20181013_191907.jpg?raw=true)

---

## Prototyping

![](https://github.com/kimitobo/Timecapsules/blob/master/pics/20181009_013451.jpg?raw=true)

![](https://github.com/kimitobo/Timecapsules/blob/master/pics/20181008_231030.jpg?raw=true)

![](https://github.com/kimitobo/Timecapsules/blob/master/pics/20181008_235518.jpg?raw=true)

![](https://github.com/kimitobo/Timecapsules/blob/master/pics/20181008_235543.jpg?raw=true)

### 8. Bend down the other leg on the opposite side of the center hole.
Cathode leg : can be recognised from the flat side of the LED lense
![](https://github.com/kimitobo/Timecapsules/blob/master/cup/PCB_solder_guide/20181013_192134.jpg?raw=true)

---

### 9. Solder the power wires in place
![](https://github.com/kimitobo/Timecapsules/blob/master/cup/PCB_solder_guide/20181013_195444.jpg?raw=true)

--- 

### 10. Power up the circuit with 3.3-5v and measure:
Between VCC (pin8) and GND full input voltage, between pin2 and GND half input voltage

---

### 11. Insert the pre-programmed chip and test
LED blinks for few seconds waiting for new code to be "played-in" from audio jack
