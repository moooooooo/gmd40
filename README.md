# gmd40
Files
---------------------------------------------------------------------------------------------------------------------------------------------
peter1.c, rawmidi.c - These are C programs i've written to initially increment up and down the channel on the Hughes and Kettner GrandMesiter Deluxe 40 amplifier.
That's more about me tinkering with MIDI in C on Linux. It's not the main goal of this repo. See below.

The panel files are in XML format but have Lua functions. These are used in the crtlr.org project.

gmd40.panel - not uploaded yet but is the panel i'm porting to Linux for ctrlr. There will be separate panel files for the 36 and BS200.
peter.panel - full binary panel from the macOS app.
peter2.panel - WORK IN PROGRESS. This will be gmd40.panel in due course.

Plans
---------------------------------------------------------------------------------------------------------------------------------------------
i am also porting the original panel to Linux as the author kindly sent me the source.
i will update this file with full attributions and thanks etc

i'm dealing with a health issue but sitting in front of the computer with a guitar on my lap testing all this stuff is a great way to take my mind away from that ! and noodle on the guitar and test my coding.

The panel is written in Lua so, whilst i'm an experienced programmer ? I've not used Lua before. However, it's quite intuitive so i don't foresee any actual Lua issues. 

What i do see is issues getting it to work on Linux - not because Linux has issues, no, but because of the many Linux "flavours" out there.

My initial focus will be to get the panel working with controller specifically for my Hughes and Kettner Grand Meister Deluxe 40 (GMD40) because i have the GMD40 and that's the only amp i can test this on.

So it's likely i'll comment out specific code that refers to the 36 and/or the BS200.

If i get sh!t working on the GMD40 ? Cool. Then i'll release separate 36 and BS200 versions but obviously i can't test those so it will rely upon input and feedback - party on dude, soz !! - from you guys n gals.

Peter.
