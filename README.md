# Raster-Graphics

OOP project

Using RasterGraphics.cpp as the main
We have the following hierarchies:
Commands<-Negative/Grayscale/Monochrome/Rotate
Commands has UserSession within
UserSession has PictureTypes** (array of poiters of pictures)
PictureTypes(pure vurtual)<-PGM/PBM/PPM

We use 3 arrays of stacks within our program:
Array of stacks for the session we are going to input during the compilation
Array of stacks for the commands for each session in the program
Array of stacks for the saved commands in the program

The commands: save, saveas, load, undo, add, sessionInfo, switch and collage does not require to be put into own classes, because they do not manipulate the pictures just the stacks or the session itself.
