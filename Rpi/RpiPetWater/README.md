This is an example project for integrating a Simulink simulation running in (quasi) real-time on a laptop with a controller running on an embedded computer target board, connected via the network. The target board is a Raspberry Pi (RPi).

Pre-requisites:
- MATLAB 
- Simulink Support Package for Raspberry Pi
- MATLAB Support package for Raspberry Pi

MATLAB RPi package information: 
https://www.mathworks.com/hardware-support/raspberry-pi-matlab.html
https://www.mathworks.com/discovery/raspberry-pi-programming-matlab-simulink.html

Recommended RPi version: Pi 4 Model B (it should work with Pi 3 Model B+)

Preparation: Install the RPi support packages listed above on MATLAB using the "Add-Ons/Get Add-ons" command. During the installation an SD card will be created with all the software MATLAB needs, including the operating system and other packages. The SD card should be installed in the RPi device and the device be connected to the laptop via a network connection (direct Ethernet cable or a connection through a router). 

You can use the following commands (in the MATLAB window) to open an ssh terminal to the RPi:
r=raspberry
r.openShell

After the installation, Simulink/Stateflow models - implementing control algorithms, for example - can be downloaded and run on the RPi. The running model can also communicate via the network with another Simulink model, running on the MATLAB host. The example models in this folder show how to do it. 

When the RPi is directly connected to the laptop (via an Ethernet cable) a miniature network is created, where the laptop and the RPi are the two hosts, with their own, distinct IP address. In the example, the IP addresses are:
- RPi:      rpicps.mshome.net
- Laptop:   192.168.137.1
On the RPi you can find the IP address using the 'ifconfig' command, on the (Windows) laptop you can use the 'ipconfig' command. You may need to modify the example models according to the IP addresses you have your system. Verify the connectivity using the 'ping' command in both directions. 
The example uses UDP for network communication, as follows:
- Laptop/plant: receive on port 26000, sending to RPi port 25000
- RPi/controller: receive in port 25000, sending to laptop port 26000

Simulink model: test_plant - runs on the laptop
The model uses a free running counter block to produce a signal with the integer counter values. This signal is converted into a double-precision floating point number that is sent to the RPi. The model also receives a signal from the RPi, and both the received data and the generated counter values are plotted on a 'scope. 
NOTE: The plant model can run in pure simulation mode (steps are clock synchronized) or in desktop-real-time mode (under the real-time kernel) - for higher timing accuracy. In either case, case the UDP port is 'sampled' at a fixed rate (lower than the stepsize of the simulator).  
For 'real-time' execution the plant model requires the 'MATLAB Real-time Kernel'. The instructions here: https://www.mathworks.com/help/sldrt/ug/real-time-windows-target-kernel.html explain how to install that package. 

Simulink model: test_ctrl - runs on the RPi
The model receives a double value, multiplies it with 2, and sends the result out, via the UDP ports. 

Running the models:
(1) start the test_ctrl model on the RPi, using the Monitor & Tune command. Once started, one can disconnect - the model keeps running the target. To stop the model, connect to the RPi, adn stop the model. 
(2) start the test_plant model on the laptop, using the 'Run in real-time' command. The plotter shows the increasing values of the counter, and received data.

PROBLEM: The received data is always zero. WHY???
EXPLANATION: The laptop's firewall blocks the network packets coming from the RPi. 
FIX: The laptop's firewall have to be configured to allow communication with the RPi. This page explains what to do:
https://www.mathworks.com/help/slrealtime/ug/troubleshoot-communication-failure-through-firewall.html
Note that knowledge of the RPi and laptop network interface IP address is required. Once the firewall enables the network traffic, the 'plant' and the 'controller' model can communicate. 
The 'plant' simulation is running under MATLAB on the laptop, so if you allow MATLAB through the firewall on 'Public' network, it should be OK. 
Note: the directly connected RPi sets up a 'Public' network. 
To configure the firewall:
- Find the 'Firewall & network protection' settings (on Windows)
- Select 'Allow an app through firewall'
- Enable MATLAB (of the correct version) on 'Public' network
Note: once you are done, suggest to disable MATLAB on 'Public' networks.

Python code: test_mdl.py and test_ctrl.py
These are two simple Python programs that one can use for testing communication between the laptop and the RPi. If you want to experiment with these, you need to open the firewall for Python (instead of MATLAB). 

