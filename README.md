# windower
command line tool for generating lookup tables



To build...

gcc windower.c windower -lm



To run...

./windower {windowType} {windowSize}



example...

./windower gauss 512 hanning 1024 hamming 128

windower outputs specified lookuptables into ouitput file windows.h



currently supported window types ...

gauss
hanning
hamming
more to come ...
