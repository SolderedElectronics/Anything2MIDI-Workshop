# Soldered Anything2MIDI Workshop

<img src="https://raw.githubusercontent.com/SolderedElectronics/Soldered-Generic-Arduino-Library/dev/extras/Soldered-logo-color.png" alt="soldered-logo" width="500"/>

Code files and resources for the Soldered workshop on building a custom MIDI controller using Arduino/Dasduino boards.

### Workshop Requirements

To participate in this workshop, it's mandatory to bring the following
* **Laptop Computer** - To write, compile and upload Arduino code from
* **Headphones** - So that we don't all hear each other's synthesizer playing at the same time :)


### Repository Contents

* **/examples** - Example Arduino sketches for the workshop.
* **/img** - Useful images related to the workshop.

### Workshop Resources

* **Board Definitions:** [Dasduino Board Definitions for Arduino IDE](https://github.com/SolderedElectronics/Dasduino-Board-Definitions-for-Arduino-IDE/raw/master/package_Dasduino_Boards_index.json)
* **Required Software (Windows/Mac/Linux):**
    * [LoopMIDI by Tobias Erichsen](https://www.tobias-erichsen.de/software/loopmidi.html) (for creating virtual MIDI ports)
    * [Hairless MIDI Serial Bridge](https://projectgus.github.io/hairless-midiserial/) (for connecting Serial to MIDI)
    * [Surge XT Synthesizer](https://surge-synthesizer.github.io/) (or any other DAW/Synth that accepts MIDI input, Surge XT is excellent, free and open source and works well standalone, making it perfect for the workshop)

### Tutorial: Sending MIDI Notes with a Button

1.  Connect your Arduino/Dasduino board to your computer via USB.
2.  Open the relevant example sketch from the `/examples` folder in this repository.
3.  Modify the sketch if necessary (e.g., change the button pin number if it's not connected to the default pin specified in the example). Upload the sketch to your board.
4.  **Set up MIDI routing:**
    * Launch LoopMIDI and create a new virtual MIDI port (e.g., "Dasduino MIDI").
    * Launch Hairless MIDI Serial Bridge. Select your Arduino/Dasduino's serial port under "Serial port" and select the LoopMIDI port you created (e.g., "Dasduino MIDI") under "MIDI Out". Ensure the "Serial<->MIDI Bridge On" toggle is enabled.
5.  Open your synthesizer or Digital Audio Workstation (DAW), such as Surge XT. Go to its audio/MIDI settings and enable the virtual MIDI port ("Dasduino MIDI") as a MIDI input device.
6.  Press the button connected to your Arduino/Dasduino. You should now hear sound from your synthesizer, triggered by the MIDI note sent from the board!

### Linux Alternative Setup (via ttymidi)

For Linux users, `ttymidi` can be used as an alternative to LoopMIDI and Hairless MIDI:

1.  Identify your Arduino/Dasduino's serial port (e.g., `/dev/ttyACM0`).
2.  Run `ttymidi` in a terminal, specifying the port and baud rate (matching your Arduino sketch, typically 9600 or 115200):
    ```bash
    ttymidi -s /dev/ttyACM0 -b 115200 -v
    ```
3.  This creates an ALSA MIDI port. You can list available ports with `aconnect -l`.
4.  Connect the `ttymidi` output port to your synthesizer/DAW's input port using `aconnect`:
    ```bash
    aconnect <ttymidi_client>:<port> <synth_client>:<port>
    ```
    *(Replace client and port numbers accordingly)*
5.  Alternatively, you can use a program like `timidity` in ALSA server mode, which some DAWs like Surge XT can connect to directly:
    ```bash
    ttymidi -s /dev/ttyACM0 -b 115200 | timidity -iA -B2,8
    ```

*(Thanks to j3d1n4 for the initial Linux pointers!)*

---

### About Soldered

<img src="https://raw.githubusercontent.com/SolderedElectronics/Soldered-Generic-Arduino-Library/dev/extras/Soldered-logo-color.png" alt="soldered-logo" width="500"/>

At Soldered, we design and manufacture a wide selection of electronic products to help you turn your ideas into acts and bring you one step closer to your final project. Our products are intented for makers and crafted in-house by our experienced team in Osijek, Croatia. We believe that sharing is a crucial element for improvement and innovation, and we work hard to stay connected with all our makers regardless of their skill or experience level. Therefore, all our products are open-source. Finally, we always have your back. If you face any problem concerning either your shopping experience or your electronics project, our team will help you deal with it, offering efficient customer service and cost-free technical support anytime. Some of those might be useful for you:

* [Web Store](https://www.soldered.com/shop)
* [Tutorials & Projects](https://soldered.com/learn)
* [Product Documentation](https://soldered.com/documentation/)

## Have fun!

And thank you from your fellow makers at Soldered Electronics.