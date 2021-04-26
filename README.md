# windower
command line tool for generating lookup tables



To build:

cd into directory and type make


To run:

./windower {windowType} {windowSize}



Example:

./windower gauss 512 hanning 1024 hamming 128

windower outputs specified lookuptables into ouitput file windows.h



Currently supported window types:

gauss,
hanning,
hamming,
hann,
blackman,
blackman-harris,
more to come ...



Output Format:

static const float windowName1[windowLength1] =
{
  0,
  0.1,
  0.2,
  0.3,
  0.4,
  0.5,
  //etc
};

static const float windowName2[windowLength2] =
{
  0,
  0.1,
  0.2,
  0.3,
  0.4,
  0.5,
  //etc
};
