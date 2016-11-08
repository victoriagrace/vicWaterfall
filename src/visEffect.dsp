import("reverb.lib");
import("delay.lib");
//import("miscoscillator.lib");


n =2; //the max delay length as a power of 2
d = hslider("delayLength",1,0,44100,0.01) :si.smoo; //the delay length as a number of samples (float)
dt1 = hslider("decayTime1",0.5,0,2,0.01) :si.smoo; //the delay length as a number of samples (float)
dt2 = hslider("decayTime2",0.5,0,2,0.01) :si.smoo; //the delay length as a number of samples (float)

rdel = 1; 
f1= 200;
f2= 400;
t60dc= dt1;
t60m = dt2;
fsmax= 44100;

delayMe = _ : delay(n,d) : _;
process = _,_ : zita_rev1_stereo(rdel,f1,f2,t60dc,t60m,fsmax) : delayMe, delayMe: _,_;

