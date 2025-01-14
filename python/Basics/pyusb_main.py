"""An example program on how to use pyusb library to manipulate a 
string in python program"""
import usb.core as core

dev = core.find(idVendor=0x0951 ,idProduct=0x1666)
print(dev)
