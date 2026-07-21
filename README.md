# Thruster Control Board - Revision 2

## Progress Notes
- Designed circuit board revision 1 using Altium Designer.
- Wrote firmware for testing circuitry on revision 1.
    - Wasn't able to use revision 1 tests due to faults in circuit design.
- Designed circuit board revision 2 using Altium Designer.

## Todo Things & Priority
### High
- [x] [@AdrianTarantino](https://github.com/AdrianTarantino) | Solder crystal 
oscillator to board.

- [ ] Test device functionality. View [this repository](https://github.com/UWMedTechRobotics/ESC_V1_Firmware_Tests/tree/main).
    - [ ] Validate I2C, GPIO, PWM and ADC.

- [ ] Implement firmware for interfacing with onboard electronics:
    - [ ] [IMU (BNO055)](https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bno055-ds000.pdf).
    Note that this may be controlled by Orange Pi instead.
    - [ ] Leak Sensor (ask Daniel).
    - [ ] Solonoids (ask Daniel).
    - [ ] Serial communication via USB Type-C.
        - Speak with Abdur about what information needs to be communicated and
        how that information needs to be formatted.
        - Use PuTTY to validate that it's working.
    - [ ] [@AdrianTarantino](https://github.com/AdrianTarantino) | 3-Phase BLDC 
    motors.
    - [x] [@AdrianTarantino](https://github.com/AdrianTarantino) | Muxes
    - [x] [@AdrianTarantino](https://github.com/AdrianTarantino) | [LED Driver](https://use.365.altium.com/librarycomponentsapi/api/v1/References/6CBF2630-7D49-4BC0-9B47-311861A12B9A). LED colour should follow this
    priority:
        - Red when failure.
        - Green when motors spinning.
        - Purple when communicating with external device.
        - Blue when idle.

### Medium
- [ ] Conan | Design mounting bracket for board.

- [ ] Source stantions for stacking power board, sonar board and thruster board.

### Low
- [ ] Develop diagnostic app:
    - Desktop app on PC
    - Sends commands via USB to the board.

- [ ] Add release to [GitHub repository](https://github.com/UWMedTechRobotics/uwmtr-thruster-control-board).
    - STEP file.
    - NC Drill, Gerber
    - BOM, Pick & Place

- [ ] Document everything that needs to be changed for revision 3:
    - [ ] Add 3-phase BLDC driver chip.
        - Ideally be able to set speed & direction via I2C or SPI.
    - [ ] Add BNO055 IMU to the board instead of the current IMU on the board.
    - [ ] Replace the debug connector with pin headers.
    - [ ] Add USB to UART chip to simplify USB communications.
    - [ ] Add an additional onboard LED purely for signalling that power is on.
     
# Revision 3 Notes
## Electrical
- Update motor control circuitry to use [the TI MCF8316A](https://www.ti.com/product/MCF8316A#pps).
    - Significantly simplifies electrical system and number of components on the board.
    - Available on JLCPCB parts library.
- Simplify USB communication with [TI TUSB3410](https://www.ti.com/product/TUSB3410).
    - Converts USB data to UART.
 - Add [BNO055](https://www.digikey.ca/short/m2jcv0r0) for IMU related data.
    - Available on JLCPCB parts library.
- Add dedicated LED purely for indicating power-on.
- Use Power MOSFETs
