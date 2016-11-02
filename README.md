# `waveformWaterfall` : Reminds me of [sndpeek](http://www.gewang.com/software/sndpeek/)!

This is an OpenFrameworks project that demonstrates how to draw a waterfall depiction of the incoming audio.

## To build

* Extract this directory and place it in your `$OF/apps/myapps/` directory, where `$OF` is the path to your OpenFrameworks directory. For example, this would end up in `/Users/tim/Desktop/of_v0.9.5_osx_release/apps/myApps/ofxWaveformWaterfall/` on my OSX machine.

* Build the program.
    * On OSX, open up `waveformWaterfall.xcodeproj` and build the target for "*waveformWaterfall Release > My Mac (64 bit)*" (or Debug, or 32-bit, etc.)
    * On Linux, you can type `make` from the project directory. Alternately, if you want to use the [QtCreator IDE](https://www.qt.io/ide/), you can open up `planets.creator` and build.
    * Windows is untested, but you should be able to import the project into Visual Studio or QtCreator after you've followed the general OpenFrameworks installation directions.

* The compiled program should now be in your `ofxWaveformWaterfall/bin` directory.

## Further reading

* [OpenFrameworks](http://openframeworks.cc/)
* [OpenFrameworks API / Documentation](http://openframeworks.cc/documentation/)
* [OpenFrameworks getting started with the sound stream](http://openframeworks.cc/ofBook/chapters/sound.html#gettingstartedwiththesoundstream)
* [OpenFrameworks advanced graphics tutorial](http://openframeworks.cc/ofBook/chapters/advanced_graphics.html)
* [OpenFrameworks intro to vectors](http://openframeworks.cc/ofBook/chapters/stl_vector.html)# vicWaterfall
