//----------------------------------------------------------
//
// Code generated with Faust 0.9.92 (http://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
#include <math.h>
#ifndef FAUSTPOWER
#define FAUSTPOWER
#include <cmath>
template <int N> inline int faustpower(int x)              { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline int faustpower<0>(int x)            { return 1; }
template <> 	 inline int faustpower<1>(int x)            { return x; }
template <> 	 inline int faustpower<2>(int x)            { return x*x; }
template <int N> inline float faustpower(float x)            { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline float faustpower<0>(float x)          { return 1; }
template <> 	 inline float faustpower<1>(float x)          { return x; }
template <> 	 inline float faustpower<2>(float x)          { return x*x; }
#endif
// Music 256a / CS 476a | fall 2016
// CCRMA, Stanford University
//
// Author: Romain Michon (rmichonATccrmaDOTstanfordDOTedu)
// Description: Simple Faust architecture file to easily integrate a Faust DSP module
// in a JUCE project

// needed by any Faust arch file
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>

/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

inline int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

inline long lopt(char* argv[], const char* name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

inline bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

inline const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


// allows to control a Faust DSP module in a simple manner by using parameter's path
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <vector>
#include <map>
#include <string>

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust User Interface
 * This abstract class contains only the method that the faust compiler can
 * generate to describe a DSP interface.
 ******************************************************************************/

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

//----------------------------------------------------------------
//  Generic decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    protected:
    
        UI* fUI;

    public:
    
        DecoratorUI(UI* ui = 0):fUI(ui)
        {}

        virtual ~DecoratorUI() { delete fUI; }

        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }

        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
            { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 	
            { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 			
            { fUI->addNumEntry(label, zone, init, min, max, step); }

        // -- passive widgets	
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
            { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
            { fUI->addVerticalBargraph(label, zone, min, max); }

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }

};

#endif
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H

/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, float value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        float getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return 0.;
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return fPathZoneMap.size(); }
        
        std::string getParamAdress(int index) 
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
};

#endif // FAUST_MAPUI_H

// needed by any Faust arch file
/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

								FAUST DSP

*******************************************************************************
*******************************************************************************/

#ifndef __dsp__
#define __dsp__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the UI* parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the UI* user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /** Global init, calls the following methods :
         * - static class 'classInit' : static table initialisation
         * - 'instanceInit' : constants and instance table initialisation
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void init(int samplingRate) = 0;
    
        /** Init instance state
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void instanceInit(int samplingRate) = 0;
    
        /** Init instance constant state
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
    
        /**  
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value metadata).
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with sucessive in/out audio buffers.
         *
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation : alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         *
         */
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { return fDSP->metadata(m); }
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
       
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif

#ifndef __visEffect__
#define __visEffect__

// tags used by the Faust compiler to paste the generated c++ code
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  


#ifndef FAUSTCLASS 
#define FAUSTCLASS visEffect
#endif

class visEffect : public dsp {
  private:
	int 	IOTA;
	float 	fVec0[256];
	float 	fConst0;
	int 	iConst1;
	float 	fConst2;
	float 	fConst3;
	float 	fConst4;
	FAUSTFLOAT 	fslider0;
	float 	fRec11[2];
	FAUSTFLOAT 	fslider1;
	float 	fRec12[2];
	float 	fConst5;
	float 	fConst6;
	float 	fConst7;
	float 	fConst8;
	float 	fRec13[2];
	float 	fRec10[2];
	float 	fVec1[8192];
	float 	fConst9;
	int 	iConst10;
	float 	fVec2[1024];
	int 	iConst11;
	float 	fRec8[2];
	float 	fConst12;
	float 	fConst13;
	float 	fRec17[2];
	float 	fRec16[2];
	float 	fVec3[8192];
	float 	fConst14;
	int 	iConst15;
	float 	fVec4[1024];
	int 	iConst16;
	float 	fRec14[2];
	float 	fConst17;
	float 	fConst18;
	float 	fRec21[2];
	float 	fRec20[2];
	float 	fVec5[8192];
	float 	fConst19;
	int 	iConst20;
	float 	fVec6[2048];
	int 	iConst21;
	float 	fRec18[2];
	float 	fConst22;
	float 	fConst23;
	float 	fRec25[2];
	float 	fRec24[2];
	float 	fVec7[8192];
	float 	fConst24;
	int 	iConst25;
	float 	fVec8[1024];
	int 	iConst26;
	float 	fRec22[2];
	float 	fConst27;
	float 	fConst28;
	float 	fRec29[2];
	float 	fRec28[2];
	float 	fVec9[16384];
	float 	fConst29;
	int 	iConst30;
	float 	fVec10[256];
	float 	fVec11[2048];
	int 	iConst31;
	float 	fRec26[2];
	float 	fConst32;
	float 	fConst33;
	float 	fRec33[2];
	float 	fRec32[2];
	float 	fVec12[8192];
	float 	fConst34;
	int 	iConst35;
	float 	fVec13[2048];
	int 	iConst36;
	float 	fRec30[2];
	float 	fConst37;
	float 	fConst38;
	float 	fRec37[2];
	float 	fRec36[2];
	float 	fVec14[16384];
	float 	fConst39;
	int 	iConst40;
	float 	fVec15[2048];
	int 	iConst41;
	float 	fRec34[2];
	float 	fConst42;
	float 	fConst43;
	float 	fRec41[2];
	float 	fRec40[2];
	float 	fVec16[16384];
	float 	fConst44;
	int 	iConst45;
	float 	fVec17[1024];
	int 	iConst46;
	float 	fRec38[2];
	float 	fRec0[3];
	float 	fRec1[3];
	float 	fRec2[3];
	float 	fRec3[3];
	float 	fRec4[3];
	float 	fRec5[3];
	float 	fRec6[3];
	float 	fRec7[3];
	float 	fVec18[2];
	FAUSTFLOAT 	fslider2;
	float 	fRec42[2];
	float 	fVec19[2];
	int fSamplingFreq;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("reverb.lib/name", "Faust Reverb Library");
		m->declare("reverb.lib/version", "0.0");
		m->declare("basic.lib/name", "Faust Basic Element Library");
		m->declare("basic.lib/version", "0.0");
		m->declare("route.lib/name", "Faust Signal Routing Library");
		m->declare("route.lib/version", "0.0");
		m->declare("delay.lib/name", "Faust Delay Library");
		m->declare("delay.lib/version", "0.0");
		m->declare("signal.lib/name", "Faust Signal Routing Library");
		m->declare("signal.lib/version", "0.0");
		m->declare("math.lib/name", "Faust Math Library");
		m->declare("math.lib/version", "2.0");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/version", "2.0");
	}

	virtual int getNumInputs() { return 2; }
	virtual int getNumOutputs() { return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(1.92e+05f, max(1.0f, (float)fSamplingFreq));
		iConst1 = int((int((0.001f * fConst0)) & 8191));
		fConst2 = cosf((2513.2742f / float(fConst0)));
		fConst3 = floorf(((0.153129f * fConst0) + 0.5f));
		fConst4 = ((0 - (6.9077554f * fConst3)) / fConst0);
		fConst5 = (1.0f / tanf((628.31854f / fConst0)));
		fConst6 = (fConst5 + 1);
		fConst7 = (1.0f / fConst6);
		fConst8 = (0 - ((1 - fConst5) / fConst6));
		fConst9 = floorf(((0.020346f * fConst0) + 0.5f));
		iConst10 = int((int((fConst3 - fConst9)) & 8191));
		iConst11 = int((int((fConst9 + -1)) & 1023));
		fConst12 = floorf(((0.174713f * fConst0) + 0.5f));
		fConst13 = ((0 - (6.9077554f * fConst12)) / fConst0);
		fConst14 = floorf(((0.022904f * fConst0) + 0.5f));
		iConst15 = int((int((fConst12 - fConst14)) & 8191));
		iConst16 = int((int((fConst14 + -1)) & 1023));
		fConst17 = floorf(((0.127837f * fConst0) + 0.5f));
		fConst18 = ((0 - (6.9077554f * fConst17)) / fConst0);
		fConst19 = floorf(((0.031604f * fConst0) + 0.5f));
		iConst20 = int((int((fConst17 - fConst19)) & 8191));
		iConst21 = int((int((fConst19 + -1)) & 2047));
		fConst22 = floorf(((0.125f * fConst0) + 0.5f));
		fConst23 = ((0 - (6.9077554f * fConst22)) / fConst0);
		fConst24 = floorf(((0.013458f * fConst0) + 0.5f));
		iConst25 = int((int((fConst22 - fConst24)) & 8191));
		iConst26 = int((int((fConst24 + -1)) & 1023));
		fConst27 = floorf(((0.210389f * fConst0) + 0.5f));
		fConst28 = ((0 - (6.9077554f * fConst27)) / fConst0);
		fConst29 = floorf(((0.024421f * fConst0) + 0.5f));
		iConst30 = int((int((fConst27 - fConst29)) & 16383));
		iConst31 = int((int((fConst29 + -1)) & 2047));
		fConst32 = floorf(((0.192303f * fConst0) + 0.5f));
		fConst33 = ((0 - (6.9077554f * fConst32)) / fConst0);
		fConst34 = floorf(((0.029291f * fConst0) + 0.5f));
		iConst35 = int((int((fConst32 - fConst34)) & 8191));
		iConst36 = int((int((fConst34 + -1)) & 2047));
		fConst37 = floorf(((0.256891f * fConst0) + 0.5f));
		fConst38 = ((0 - (6.9077554f * fConst37)) / fConst0);
		fConst39 = floorf(((0.027333f * fConst0) + 0.5f));
		iConst40 = int((int((fConst37 - fConst39)) & 16383));
		iConst41 = int((int((fConst39 + -1)) & 2047));
		fConst42 = floorf(((0.219991f * fConst0) + 0.5f));
		fConst43 = ((0 - (6.9077554f * fConst42)) / fConst0);
		fConst44 = floorf(((0.019123f * fConst0) + 0.5f));
		iConst45 = int((int((fConst42 - fConst44)) & 16383));
		iConst46 = int((int((fConst44 + -1)) & 1023));
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 0.5f;
		fslider1 = 0.5f;
		fslider2 = 1.0f;
	}
	virtual void instanceClear() {
		IOTA = 0;
		for (int i=0; i<256; i++) fVec0[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<8192; i++) fVec1[i] = 0;
		for (int i=0; i<1024; i++) fVec2[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<8192; i++) fVec3[i] = 0;
		for (int i=0; i<1024; i++) fVec4[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<8192; i++) fVec5[i] = 0;
		for (int i=0; i<2048; i++) fVec6[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<8192; i++) fVec7[i] = 0;
		for (int i=0; i<1024; i++) fVec8[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<16384; i++) fVec9[i] = 0;
		for (int i=0; i<256; i++) fVec10[i] = 0;
		for (int i=0; i<2048; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<8192; i++) fVec12[i] = 0;
		for (int i=0; i<2048; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<16384; i++) fVec14[i] = 0;
		for (int i=0; i<2048; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<16384; i++) fVec16[i] = 0;
		for (int i=0; i<1024; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<3; i++) fRec0[i] = 0;
		for (int i=0; i<3; i++) fRec1[i] = 0;
		for (int i=0; i<3; i++) fRec2[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<3; i++) fRec4[i] = 0;
		for (int i=0; i<3; i++) fRec5[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<3; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) fVec18[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	virtual visEffect* clone() {
		return new visEffect();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
	}
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("0x00");
		ui_interface->addHorizontalSlider("decayTime1", &fslider1, 0.5f, 0.0f, 2.0f, 0.01f);
		ui_interface->addHorizontalSlider("decayTime2", &fslider0, 0.5f, 0.0f, 2.0f, 0.01f);
		ui_interface->addHorizontalSlider("delayLength", &fslider2, 1.0f, 0.0f, 4.41e+04f, 0.01f);
		ui_interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (0.001f * float(fslider0));
		float 	fSlow1 = (0.001f * float(fslider1));
		float 	fSlow2 = (0.001f * float(fslider2));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			fVec0[IOTA&255] = (float)input0[i];
			float fTemp0 = (0.3f * fVec0[(IOTA-iConst1)&255]);
			fRec11[0] = (fSlow0 + (0.999f * fRec11[1]));
			float fTemp1 = expf((fConst4 / fRec11[0]));
			float fTemp2 = faustpower<2>(fTemp1);
			float fTemp3 = (1.0f - (fConst2 * fTemp2));
			float fTemp4 = (1.0f - fTemp2);
			float fTemp5 = (fTemp3 / fTemp4);
			float fTemp6 = sqrtf(max((float)0, ((faustpower<2>(fTemp3) / faustpower<2>(fTemp4)) + -1.0f)));
			fRec12[0] = (fSlow1 + (0.999f * fRec12[1]));
			fRec13[0] = ((fConst7 * (fRec0[1] + fRec0[2])) + (fConst8 * fRec13[1]));
			fRec10[0] = ((fRec10[1] * (fTemp5 - fTemp6)) + ((fTemp1 * (fRec0[1] + (((expf((fConst4 / fRec12[0])) / fTemp1) + -1) * fRec13[0]))) * (fTemp6 + (1.0f - fTemp5))));
			fVec1[IOTA&8191] = ((0.35355338f * fRec10[0]) + 1e-20f);
			float fTemp7 = ((fTemp0 + fVec1[(IOTA-iConst10)&8191]) - (0.6f * fRec8[1]));
			fVec2[IOTA&1023] = fTemp7;
			fRec8[0] = fVec2[(IOTA-iConst11)&1023];
			float 	fRec9 = (0.6f * fVec2[IOTA&1023]);
			float fTemp8 = expf((fConst13 / fRec11[0]));
			float fTemp9 = faustpower<2>(fTemp8);
			float fTemp10 = (1.0f - (fConst2 * fTemp9));
			float fTemp11 = (1.0f - fTemp9);
			float fTemp12 = (fTemp10 / fTemp11);
			float fTemp13 = sqrtf(max((float)0, ((faustpower<2>(fTemp10) / faustpower<2>(fTemp11)) + -1.0f)));
			fRec17[0] = ((fConst7 * (fRec4[1] + fRec4[2])) + (fConst8 * fRec17[1]));
			fRec16[0] = ((fRec16[1] * (fTemp12 - fTemp13)) + ((fTemp8 * (fRec4[1] + (((expf((fConst13 / fRec12[0])) / fTemp8) + -1) * fRec17[0]))) * (fTemp13 + (1.0f - fTemp12))));
			fVec3[IOTA&8191] = ((0.35355338f * fRec16[0]) + 1e-20f);
			float fTemp14 = ((fTemp0 + fVec3[(IOTA-iConst15)&8191]) - (0.6f * fRec14[1]));
			fVec4[IOTA&1023] = fTemp14;
			fRec14[0] = fVec4[(IOTA-iConst16)&1023];
			float 	fRec15 = (0.6f * fVec4[IOTA&1023]);
			float fTemp15 = expf((fConst18 / fRec11[0]));
			float fTemp16 = faustpower<2>(fTemp15);
			float fTemp17 = (1.0f - (fConst2 * fTemp16));
			float fTemp18 = (1.0f - fTemp16);
			float fTemp19 = (fTemp17 / fTemp18);
			float fTemp20 = sqrtf(max((float)0, ((faustpower<2>(fTemp17) / faustpower<2>(fTemp18)) + -1.0f)));
			fRec21[0] = ((fConst7 * (fRec2[1] + fRec2[2])) + (fConst8 * fRec21[1]));
			fRec20[0] = ((fRec20[1] * (fTemp19 - fTemp20)) + ((fTemp15 * (fRec2[1] + (((expf((fConst18 / fRec12[0])) / fTemp15) + -1) * fRec21[0]))) * (fTemp20 + (1.0f - fTemp19))));
			fVec5[IOTA&8191] = ((0.35355338f * fRec20[0]) + 1e-20f);
			float fTemp21 = (fVec5[(IOTA-iConst20)&8191] - (fTemp0 + (0.6f * fRec18[1])));
			fVec6[IOTA&2047] = fTemp21;
			fRec18[0] = fVec6[(IOTA-iConst21)&2047];
			float 	fRec19 = (0.6f * fVec6[IOTA&2047]);
			float fTemp22 = expf((fConst23 / fRec11[0]));
			float fTemp23 = faustpower<2>(fTemp22);
			float fTemp24 = (1.0f - (fConst2 * fTemp23));
			float fTemp25 = (1.0f - fTemp23);
			float fTemp26 = (fTemp24 / fTemp25);
			float fTemp27 = sqrtf(max((float)0, ((faustpower<2>(fTemp24) / faustpower<2>(fTemp25)) + -1.0f)));
			fRec25[0] = ((fConst7 * (fRec6[1] + fRec6[2])) + (fConst8 * fRec25[1]));
			fRec24[0] = ((fRec24[1] * (fTemp26 - fTemp27)) + ((fTemp22 * (fRec6[1] + (((expf((fConst23 / fRec12[0])) / fTemp22) + -1) * fRec25[0]))) * (fTemp27 + (1.0f - fTemp26))));
			fVec7[IOTA&8191] = ((0.35355338f * fRec24[0]) + 1e-20f);
			float fTemp28 = (fVec7[(IOTA-iConst25)&8191] - (fTemp0 + (0.6f * fRec22[1])));
			fVec8[IOTA&1023] = fTemp28;
			fRec22[0] = fVec8[(IOTA-iConst26)&1023];
			float 	fRec23 = (0.6f * fVec8[IOTA&1023]);
			float fTemp29 = expf((fConst28 / fRec11[0]));
			float fTemp30 = faustpower<2>(fTemp29);
			float fTemp31 = (1.0f - (fConst2 * fTemp30));
			float fTemp32 = (1.0f - fTemp30);
			float fTemp33 = (fTemp31 / fTemp32);
			float fTemp34 = sqrtf(max((float)0, ((faustpower<2>(fTemp31) / faustpower<2>(fTemp32)) + -1.0f)));
			fRec29[0] = ((fConst7 * (fRec1[1] + fRec1[2])) + (fConst8 * fRec29[1]));
			fRec28[0] = ((fRec28[1] * (fTemp33 - fTemp34)) + ((fTemp29 * (fRec1[1] + (((expf((fConst28 / fRec12[0])) / fTemp29) + -1) * fRec29[0]))) * (fTemp34 + (1.0f - fTemp33))));
			fVec9[IOTA&16383] = ((0.35355338f * fRec28[0]) + 1e-20f);
			fVec10[IOTA&255] = (float)input1[i];
			float fTemp35 = (0.3f * fVec10[(IOTA-iConst1)&255]);
			float fTemp36 = (fVec9[(IOTA-iConst30)&16383] + (fTemp35 + (0.6f * fRec26[1])));
			fVec11[IOTA&2047] = fTemp36;
			fRec26[0] = fVec11[(IOTA-iConst31)&2047];
			float 	fRec27 = (0 - (0.6f * fVec11[IOTA&2047]));
			float fTemp37 = expf((fConst33 / fRec11[0]));
			float fTemp38 = faustpower<2>(fTemp37);
			float fTemp39 = (1.0f - (fConst2 * fTemp38));
			float fTemp40 = (1.0f - fTemp38);
			float fTemp41 = (fTemp39 / fTemp40);
			float fTemp42 = sqrtf(max((float)0, ((faustpower<2>(fTemp39) / faustpower<2>(fTemp40)) + -1.0f)));
			fRec33[0] = ((fConst7 * (fRec5[1] + fRec5[2])) + (fConst8 * fRec33[1]));
			fRec32[0] = ((fRec32[1] * (fTemp41 - fTemp42)) + ((fTemp37 * (fRec5[1] + (((expf((fConst33 / fRec12[0])) / fTemp37) + -1) * fRec33[0]))) * (fTemp42 + (1.0f - fTemp41))));
			fVec12[IOTA&8191] = ((0.35355338f * fRec32[0]) + 1e-20f);
			float fTemp43 = (fVec12[(IOTA-iConst35)&8191] + (fTemp35 + (0.6f * fRec30[1])));
			fVec13[IOTA&2047] = fTemp43;
			fRec30[0] = fVec13[(IOTA-iConst36)&2047];
			float 	fRec31 = (0 - (0.6f * fVec13[IOTA&2047]));
			float fTemp44 = expf((fConst38 / fRec11[0]));
			float fTemp45 = faustpower<2>(fTemp44);
			float fTemp46 = (1.0f - (fConst2 * fTemp45));
			float fTemp47 = (1.0f - fTemp45);
			float fTemp48 = (fTemp46 / fTemp47);
			float fTemp49 = sqrtf(max((float)0, ((faustpower<2>(fTemp46) / faustpower<2>(fTemp47)) + -1.0f)));
			fRec37[0] = ((fConst7 * (fRec3[1] + fRec3[2])) + (fConst8 * fRec37[1]));
			fRec36[0] = ((fRec36[1] * (fTemp48 - fTemp49)) + ((fTemp44 * (fRec3[1] + (((expf((fConst38 / fRec12[0])) / fTemp44) + -1) * fRec37[0]))) * (fTemp49 + (1.0f - fTemp48))));
			fVec14[IOTA&16383] = ((0.35355338f * fRec36[0]) + 1e-20f);
			float fTemp50 = (((0.6f * fRec34[1]) + fVec14[(IOTA-iConst40)&16383]) - fTemp35);
			fVec15[IOTA&2047] = fTemp50;
			fRec34[0] = fVec15[(IOTA-iConst41)&2047];
			float 	fRec35 = (0 - (0.6f * fVec15[IOTA&2047]));
			float fTemp51 = expf((fConst43 / fRec11[0]));
			float fTemp52 = faustpower<2>(fTemp51);
			float fTemp53 = (1.0f - (fConst2 * fTemp52));
			float fTemp54 = (1.0f - fTemp52);
			float fTemp55 = (fTemp53 / fTemp54);
			float fTemp56 = sqrtf(max((float)0, ((faustpower<2>(fTemp53) / faustpower<2>(fTemp54)) + -1.0f)));
			fRec41[0] = ((fConst7 * (fRec7[1] + fRec7[2])) + (fConst8 * fRec41[1]));
			fRec40[0] = ((fRec40[1] * (fTemp55 - fTemp56)) + ((fTemp51 * (fRec7[1] + (((expf((fConst43 / fRec12[0])) / fTemp51) + -1) * fRec41[0]))) * (fTemp56 + (1.0f - fTemp55))));
			fVec16[IOTA&16383] = ((0.35355338f * fRec40[0]) + 1e-20f);
			float fTemp57 = (((0.6f * fRec38[1]) + fVec16[(IOTA-iConst45)&16383]) - fTemp35);
			fVec17[IOTA&1023] = fTemp57;
			fRec38[0] = fVec17[(IOTA-iConst46)&1023];
			float 	fRec39 = (0 - (0.6f * fVec17[IOTA&1023]));
			float fTemp58 = (fRec38[1] + fRec39);
			float fTemp59 = (fRec35 + (fRec34[1] + fTemp58));
			float fTemp60 = (fRec27 + (fRec26[1] + (fRec31 + (fRec30[1] + fTemp59))));
			fRec0[0] = (fRec9 + (fRec8[1] + (fRec15 + (fRec14[1] + (fRec19 + (fRec18[1] + (fRec23 + (fRec22[1] + fTemp60))))))));
			fRec1[0] = ((fRec9 + (fRec8[1] + (fRec15 + (fRec14[1] + (fRec19 + (fRec18[1] + (fRec22[1] + fRec23))))))) - fTemp60);
			float fTemp61 = (fRec27 + (fRec26[1] + (fRec30[1] + fRec31)));
			fRec2[0] = ((fRec9 + (fRec8[1] + (fRec15 + (fRec14[1] + fTemp61)))) - (fRec19 + (fRec18[1] + (fRec23 + (fRec22[1] + fTemp59)))));
			fRec3[0] = ((fRec9 + (fRec8[1] + (fRec15 + (fRec14[1] + fTemp59)))) - (fRec19 + (fRec18[1] + (fRec23 + (fRec22[1] + fTemp61)))));
			float fTemp62 = (fRec34[1] + fRec35);
			float fTemp63 = (fRec27 + (fRec26[1] + fTemp62));
			float fTemp64 = (fRec31 + (fRec30[1] + fTemp58));
			fRec4[0] = ((fRec9 + (fRec8[1] + (fRec19 + (fRec18[1] + fTemp63)))) - (fRec15 + (fRec14[1] + (fRec23 + (fRec22[1] + fTemp64)))));
			fRec5[0] = ((fRec9 + (fRec8[1] + (fRec19 + (fRec18[1] + fTemp64)))) - (fRec15 + (fRec14[1] + (fRec23 + (fRec22[1] + fTemp63)))));
			float fTemp65 = (fRec27 + (fRec26[1] + fTemp58));
			float fTemp66 = (fRec31 + (fRec30[1] + fTemp62));
			fRec6[0] = ((fRec9 + (fRec8[1] + (fRec23 + (fRec22[1] + fTemp65)))) - (fRec15 + (fRec14[1] + (fRec19 + (fRec18[1] + fTemp66)))));
			fRec7[0] = ((fRec9 + (fRec8[1] + (fRec23 + (fRec22[1] + fTemp66)))) - (fRec15 + (fRec14[1] + (fRec19 + (fRec18[1] + fTemp65)))));
			fVec18[0] = (fRec1[0] + fRec2[0]);
			fRec42[0] = (fSlow2 + (0.999f * fRec42[1]));
			int iTemp67 = int((int(fRec42[0]) & 1));
			output0[i] = (FAUSTFLOAT)(0.37f * fVec18[iTemp67]);
			fVec19[0] = (fRec1[0] - fRec2[0]);
			output1[i] = (FAUSTFLOAT)(0.37f * fVec19[iTemp67]);
			// post processing
			fVec19[1] = fVec19[0];
			fRec42[1] = fRec42[0];
			fVec18[1] = fVec18[0];
			fRec7[2] = fRec7[1]; fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec38[1] = fRec38[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			fRec34[1] = fRec34[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec30[1] = fRec30[0];
			fRec32[1] = fRec32[0];
			fRec33[1] = fRec33[0];
			fRec26[1] = fRec26[0];
			fRec28[1] = fRec28[0];
			fRec29[1] = fRec29[0];
			fRec22[1] = fRec22[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec18[1] = fRec18[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec14[1] = fRec14[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec8[1] = fRec8[0];
			fRec10[1] = fRec10[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			IOTA = IOTA+1;
		}
	}
};


#endif
