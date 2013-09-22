#The Chubby Tricorder Project

Overview goes here.

#Design Decisions

I cut some corners to accelerate development and minimize risk.  I wanted to work a few weeks of "uh oh" into the timetable as well as be able to focus on the software and presentation.  Namely:

- I used an off-the-shelf microcontroller board: the Arduino.  It's large and a little slow by microcontroller standards, but board bring-up is easy and there are hundreds of premade/pre-tested hardware accessory libraries.
- I used no batteries. The printer eats a ton of power. I didn't want to spend money on hefty batteries, which would tempt prolonged use, which in turn heightens the risk of dead batteries at a critical time.
    - Edit: I used batteries. The puzzle's location changed from indoors to outdoors, so I hacked up a battery pack.
- The case is a simple laser-cut acrylic box of a design similar to the [InfoNinja][] and my [nameplate][] using tabs, slots, and bolted mortise and tension joints. It's entirely right angles, greatly simplifying the design.

[InfoNinja]: http://netninja.com/projects/infoninja/
[nameplate]: http://netninja.com/2012/08/20/a-laser-cut-light-up-nameplate/

#BoM

- Electronics
    - [Arduino](http://www.adafruit.com/products/50)
    - [OLED display](http://www.adafruit.com/products/938)
    - [thermal printer](http://www.adafruit.com/products/597)
    - [thermal paper](http://www.adafruit.com/products/599)
    - [button pad](http://www.adafruit.com/products/419)
    - [illuminated power switch](http://www.adafruit.com/products/482)
    - [panel power connector](http://www.adafruit.com/products/610)
    - RF module
    - [5V 2A AC adapter](http://www.adafruit.com/products/276)
    - assorted bits and bobs
        - hookup wire
        - jumpers, connectors
        - solder
    - tools (soldering iron, wire strippers, diagonal cutters, hot glue gun, etc.)
- laser-cut acrylic parts TODO: public link to files. Materials: $12.00. Cutting: $17.50.
- [black 3M16 screws](http://www.mcmaster.com/#91290a120/=nzdun3)
- [black 3M nuts](http://www.mcmaster.com/#98676a100/=nzdunh)
- [black 2M10 screws](http://www.mcmaster.com/#91290a017/=nzdv42)
- [M2 nuts](http://www.mcmaster.com/#90591a111/=nzdv4x)
- [6mm M3 nylon spacers](http://www.mcmaster.com/#catalog/119/3231/=nze2y8)
- [warranty void stickers](http://www.amazon.com/Silver-Evident-Hologram-Warranty-Stickers/dp/B0049C0MNK/ref=sr_1_3?ie=UTF8&qid=1376015199&sr=8-3&keywords=warranty+void+stickers)

#Software Overview

Makes use of the Arduino IDE plus several 3rd party libraries:
- screen
- printer
- button matrix

#Tasks

- [X] Determine pin connections.
- [X] Wire it up on the bench:
    - [X] Test each device, individually:
        - [X] For each external device, on by one, hook it up to the default pins.
        - [X] Verify the library can communicate with the device.
        - [X] Move the device to your desired final set of pins.
        - [X] Verify the library can communicate on the new set of pins.
    - [X] Test all devices in unison:
        - [X] Start with one device, ensure it works.
        - [X] Add another, ensure they work in tandem.
        - [X] Add the next, etc.
- [X] Preliminary software
    - [X] Boot sequence animation (and also print test output on printer?)
    - [X] Data entry screen
    - [X] "Incorrect" animation (with delay to help discourage brute forcing)
    - [X] Several incorrect answers in a row has longer delay?
    - [X] Each "correct" behavior (screen, printer)
- [X] Wireless
    - [X] Transmitter and receiver Hello World
    - [X] Integrate transmitter into design
    - [X] Test with receiver
- [X] Enclosure (black 3MM acrylic)
    - [X] Determine internal parts placement.
    - [X] Preliminary laser cut pattern.
    - [X] Left/Right sides symmetric/interchangeable?
    - [X] Print on paper, verify parts fit, verify pieces interlock correctly.
    - [X] Send to Ponoko.
    - [X] Hole for reprogramming?  "warranty void if removed" sticker?
    - [X] Reinforce printer edge panel
- [X] Battery power
    - [X] Get battery holder
    - [X] Get batteries
    - [X] Wire up to 2.1mm plug
    - [X] Rewire RF to 5V regulator on Arduino
- [ ] Final software
	- [X] Image rotator with PIN entry
	- [X] RF xmission while rotating images
	- [X] Stages of image rotator
	- [X] Easter egg(s)
	- [ ] Better comments
	- [X] Licensing
	- [ ] Publish LCD assistant code separately?
    - [X] Build the more permanent RF receiver device
    - [X] Verify with RF receiver device
    - [X] Verify that one easter egg that wasn't working at meeting
- [X] "Plan B" webapp
	- [X] Basics
	- [X] All content
	- [X] Preload images - skipped; iPhone times out preloading and aborts JavaScript
- [ ] Final documentation
	- [X] Prepare github
	- [ ] Prepare website
	- [ ] Prepare narrative blog post
	- [ ] Prepare shortened URL
	- [X] Insert shortened URL plus intro text into code as easter egg

#Away Kit

In the event of a problem during the game, I'll need to assemble an "away kit" with various repair tools.

- allen wrench
- needle-nose pliers
- diagonal clippers
- multimeter
- soldering iron, solder
- helping hands

#License

The Chubby Tricorder (https://github.com/BrianEnigma/chubby-tricorder)by Brian 
Enigma (http://netninja.com) is licensed under a Creative Commons Attribution-ShareAlike 
3.0 Unported License: http://creativecommons.org/licenses/by-sa/3.0/deed.en_US 

