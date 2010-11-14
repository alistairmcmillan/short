#!/usr/bin/env python2
# (c) Jan Dlabal, 2010
# http://houbysoft.com/
# Provided under the GNU GPL v3 License; feel free to improve.
#
# This script allows you to "cut" a part of your screen interactively with the mouse, and then it shows the part which you cut in a non-resizable (dwm users : that means it will be set to tiling mode!) window so you can copy it somewhere, for example.
# Use the usual key combo to close the application (Alt+F4, etc.)

from os import system,remove
import pygtk
pygtk.require('2.0')
import gtk

class Scut:
    def close(self, widget, event, data=None):
        remove("/tmp/scut.png")
        gtk.main_quit()
        return False

    def __init__(self):
        window = gtk.Window(gtk.WINDOW_TOPLEVEL)
        window.connect("delete_event", self.close)
        window.set_border_width(0)
        window.set_resizable(False)
        window.show()
        image = gtk.Image()
        system("scrot -s /tmp/scut.png")
        image.set_from_file("/tmp/scut.png")
        window.add(image)
        image.show()

    def main(self):
        gtk.main()
        return 0

if __name__ == "__main__":
    scut = Scut()
    scut.main()
