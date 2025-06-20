# Soldered Anything2MIDI Workshop

<img src="https://raw.githubusercontent.com/SolderedElectronics/Soldered-Generic-Arduino-Library/dev/extras/Soldered-logo-color.png" alt="soldered-logo" width="500"/>

Code files and resources for the Soldered workshop on building a custom MIDI controller using Arduino/Dasduino boards and sensors! This workshop is being done at [TearDown 2025](https://www.crowdsupply.com/teardown/portland-2025)!

### Workshop Requirements

To participate in this workshop, it's mandatory to bring the following
* **Laptop Computer** - To write, compile and upload Arduino code from
* **Headphones** - So that we don't all hear each other's synthesizer playing at the same time :)

  
### Installation Requirements

* **Arduino IDE:**
  Download from [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software). Required for uploading code to your Arduino/Dasduino board.

* **Board Definitions:**
  [Dasduino Board Definitions for Arduino IDE](https://soldered.com/documentation/arduino/quick-start-guide/#2-install-dasduino-board-definitions), install `Dasduino CONNECT` board.

* **Synthesizer (All Platforms):**
  [Surge XT Synthesizer](https://surge-synthesizer.github.io/) (or any other DAW/Synth that accepts MIDI input)
  Surge XT is free, open-source, and works well standalone, no DAW required.

#### 💻 Required Software (Windows):

* [LoopMIDI by Tobias Erichsen](https://www.tobias-erichsen.de/software/loopmidi.html), for creating virtual MIDI ports
* [Hairless MIDI Serial Bridge](https://projectgus.github.io/hairless-midiserial/), for bridging Serial to MIDI

#### 🍎 Required Software (macOS):

* **Hairless MIDI Serial Bridge:** [projectgus.github.io/hairless-midiserial](https://projectgus.github.io/hairless-midiserial/), for Serial-to-MIDI bridging
* **Audio MIDI Setup** (built-in, use **IAC Driver** to create virtual MIDI ports)

#### 🐧 Required Software (Linux):

* [`ttymidi`](https://github.com/ddiakopoulos/ttymidi), for Serial-to-MIDI bridging via ALSA
* ALSA Utilities (`aconnect`), to route MIDI ports
* *(Optional)* `timidity`, for acting as a software synth if DAW support is limited

### Setting Up Serial to MIDI Bridge

#### 💻 Windows

1. Install [LoopMIDI](https://www.tobias-erichsen.de/software/loopmidi.html) and run it.
2. Create a new virtual MIDI port (e.g., `Dasduino MIDI`).
3. Install and launch [Hairless MIDI Serial Bridge](https://projectgus.github.io/hairless-midiserial/).
4. In Hairless:

   * Select your Arduino/Dasduino's serial port (e.g., `COM3`) under **Serial port**.
   * Select your LoopMIDI port (e.g., `Dasduino MIDI`) under **MIDI Out**.
   * Enable **Serial<->MIDI Bridge On**.
5. Open your synthesizer/DAW (e.g., Surge XT), and select `Dasduino MIDI` as MIDI input.

#### 🍎 macOS

1. Download and install [Hairless MIDI Serial Bridge](https://projectgus.github.io/hairless-midiserial/).

   * Note: You may need to allow Hairless under **System Preferences > Security & Privacy** if macOS blocks it.
2. macOS has built-in support for virtual MIDI ports via **Audio MIDI Setup**:

   * Open **Audio MIDI Setup** (Applications > Utilities).
   * Open **MIDI Studio** (from the Window menu).
   * Double-click **IAC Driver** and enable the “Device is online” checkbox.
   * Create a new port (e.g., `Dasduino MIDI`) if one doesn’t already exist.
3. Launch Hairless:

   * Select your Arduino/Dasduino's serial port under **Serial port**.
   * Select the IAC port (e.g., `Dasduino MIDI`) under **MIDI Out**.
   * Enable **Serial<->MIDI Bridge On**.
4. Open your DAW or synth (e.g., Surge XT) and enable the IAC port (`Dasduino MIDI`) as MIDI input.

#### 🐧 Linux

Thanks to **j3d1n4** for the original Linux instructions!

You can use `ttymidi` and ALSA tools instead of LoopMIDI and Hairless:

1. Identify your Arduino/Dasduino serial port (e.g., `/dev/ttyACM0`).

2. Run `ttymidi` with appropriate options:

   ```bash
   ttymidi -s /dev/ttyACM0 -b 115200 -v
   ```

3. This creates a virtual ALSA MIDI port. Check available ports with:

   ```bash
   aconnect -l
   ```

4. Connect the `ttymidi` port to your DAW/synth input:

   ```bash
   aconnect <ttymidi_client>:<port> <synth_client>:<port>
   ```

   Replace client and port numbers with those from `aconnect -l`.

5. Alternatively, pipe into `timidity` to act as a MIDI synth:

   ```bash
   ttymidi -s /dev/ttyACM0 -b 115200 | timidity -iA -B2,8
   ```

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

Here's a neatly formatted set of instructions for setting up the **Serial to MIDI bridge on macOS and Linux**, just like the Windows section, with proper credit for the Linux instructions:



Let me know if you'd like this formatted as Markdown for the actual README.


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