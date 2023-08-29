# esp meeting

Prevent your family that you're in meeting !

## Description

I'm working mostly on remote, and when I'm in a meeting, I don't like to be disturbed by my family that couldn't know.
So I build with an esp-8266 microcontroler with an OLED screen, a solution to display something when I'm in meeting.

## How it works

1. A chrome extension that use the Chrome tabs API
2. A web server who stores the information
3. An esp-8266 that ping the web server every X seconds to get the information
