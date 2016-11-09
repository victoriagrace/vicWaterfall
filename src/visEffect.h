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
	float 	fConst5;
	float 	fConst6;
	float 	fConst7;
	float 	fConst8;
	float 	fConst9;
	float 	fConst10;
	float 	fConst11;
	float 	fRec11[2];
	float 	fVec1[8192];
	float 	fConst12;
	int 	iConst13;
	float 	fVec2[1024];
	int 	iConst14;
	float 	fRec9[2];
	float 	fConst15;
	float 	fConst16;
	float 	fConst17;
	float 	fConst18;
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	float 	fRec14[2];
	float 	fVec3[8192];
	float 	fConst24;
	int 	iConst25;
	float 	fVec4[1024];
	int 	iConst26;
	float 	fRec12[2];
	float 	fConst27;
	float 	fConst28;
	float 	fConst29;
	float 	fConst30;
	float 	fConst31;
	float 	fConst32;
	float 	fConst33;
	float 	fConst34;
	float 	fConst35;
	float 	fRec17[2];
	float 	fVec5[8192];
	float 	fConst36;
	int 	iConst37;
	float 	fVec6[2048];
	int 	iConst38;
	float 	fRec15[2];
	float 	fConst39;
	float 	fConst40;
	float 	fConst41;
	float 	fConst42;
	float 	fConst43;
	float 	fConst44;
	float 	fConst45;
	float 	fConst46;
	float 	fConst47;
	float 	fRec20[2];
	float 	fVec7[8192];
	float 	fConst48;
	int 	iConst49;
	float 	fVec8[1024];
	int 	iConst50;
	float 	fRec18[2];
	float 	fConst51;
	float 	fConst52;
	float 	fConst53;
	float 	fConst54;
	float 	fConst55;
	float 	fConst56;
	float 	fConst57;
	float 	fConst58;
	float 	fConst59;
	float 	fRec23[2];
	float 	fVec9[16384];
	float 	fConst60;
	int 	iConst61;
	float 	fVec10[256];
	float 	fVec11[2048];
	int 	iConst62;
	float 	fRec21[2];
	float 	fConst63;
	float 	fConst64;
	float 	fConst65;
	float 	fConst66;
	float 	fConst67;
	float 	fConst68;
	float 	fConst69;
	float 	fConst70;
	float 	fConst71;
	float 	fRec26[2];
	float 	fVec12[8192];
	float 	fConst72;
	int 	iConst73;
	float 	fVec13[2048];
	int 	iConst74;
	float 	fRec24[2];
	float 	fConst75;
	float 	fConst76;
	float 	fConst77;
	float 	fConst78;
	float 	fConst79;
	float 	fConst80;
	float 	fConst81;
	float 	fConst82;
	float 	fConst83;
	float 	fRec29[2];
	float 	fVec14[16384];
	float 	fConst84;
	int 	iConst85;
	float 	fVec15[2048];
	int 	iConst86;
	float 	fRec27[2];
	float 	fConst87;
	float 	fConst88;
	float 	fConst89;
	float 	fConst90;
	float 	fConst91;
	float 	fConst92;
	float 	fConst93;
	float 	fConst94;
	float 	fConst95;
	float 	fRec32[2];
	float 	fVec16[16384];
	float 	fConst96;
	int 	iConst97;
	float 	fVec17[1024];
	int 	iConst98;
	float 	fRec30[2];
	float 	fRec1[2];
	float 	fRec2[2];
	float 	fRec3[2];
	float 	fRec4[2];
	float 	fRec5[2];
	float 	fRec6[2];
	float 	fRec7[2];
	float 	fRec8[2];
	float 	fVec18[2];
	float 	fRec0[2];
	float 	fVec19[2];
	float 	fRec33[2];
	int fSamplingFreq;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("reverb.lib/name", "Faust Reverb Library");
		m->declare("reverb.lib/version", "0.0");
		m->declare("math.lib/name", "Faust Math Library");
		m->declare("math.lib/version", "2.0");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("delay.lib/name", "Faust Delay Library");
		m->declare("delay.lib/version", "0.0");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/version", "2.0");
		m->declare("signal.lib/name", "Faust Signal Routing Library");
		m->declare("signal.lib/version", "0.0");
		m->declare("basic.lib/name", "Faust Basic Element Library");
		m->declare("basic.lib/version", "0.0");
		m->declare("route.lib/name", "Faust Signal Routing Library");
		m->declare("route.lib/version", "0.0");
	}

	virtual int getNumInputs() { return 2; }
	virtual int getNumOutputs() { return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(1.92e+05f, max(1.0f, (float)fSamplingFreq));
		iConst1 = int((int((0.001f * fConst0)) & 8191));
		fConst2 = floorf(((0.153129f * fConst0) + 0.5f));
		fConst3 = expf((0.1f * ((0 - (6.9077554f * fConst2)) / fConst0)));
		fConst4 = cosf((37699.113f / float(fConst0)));
		fConst5 = faustpower<2>(fConst3);
		fConst6 = (1.0f - (fConst4 * fConst5));
		fConst7 = (1.0f - fConst5);
		fConst8 = sqrtf(max((float)0, ((faustpower<2>(fConst6) / faustpower<2>(fConst7)) + -1.0f)));
		fConst9 = (fConst6 / fConst7);
		fConst10 = (fConst3 * (fConst8 + (1.0f - fConst9)));
		fConst11 = (fConst9 - fConst8);
		fConst12 = floorf(((0.020346f * fConst0) + 0.5f));
		iConst13 = int((int((fConst2 - fConst12)) & 8191));
		iConst14 = int((int((fConst12 + -1)) & 1023));
		fConst15 = floorf(((0.174713f * fConst0) + 0.5f));
		fConst16 = expf((0.1f * ((0 - (6.9077554f * fConst15)) / fConst0)));
		fConst17 = faustpower<2>(fConst16);
		fConst18 = (1.0f - (fConst4 * fConst17));
		fConst19 = (1.0f - fConst17);
		fConst20 = sqrtf(max((float)0, ((faustpower<2>(fConst18) / faustpower<2>(fConst19)) + -1.0f)));
		fConst21 = (fConst18 / fConst19);
		fConst22 = (fConst16 * (fConst20 + (1.0f - fConst21)));
		fConst23 = (fConst21 - fConst20);
		fConst24 = floorf(((0.022904f * fConst0) + 0.5f));
		iConst25 = int((int((fConst15 - fConst24)) & 8191));
		iConst26 = int((int((fConst24 + -1)) & 1023));
		fConst27 = floorf(((0.127837f * fConst0) + 0.5f));
		fConst28 = expf((0.1f * ((0 - (6.9077554f * fConst27)) / fConst0)));
		fConst29 = faustpower<2>(fConst28);
		fConst30 = (1.0f - (fConst29 * fConst4));
		fConst31 = (1.0f - fConst29);
		fConst32 = sqrtf(max((float)0, ((faustpower<2>(fConst30) / faustpower<2>(fConst31)) + -1.0f)));
		fConst33 = (fConst30 / fConst31);
		fConst34 = (fConst28 * (fConst32 + (1.0f - fConst33)));
		fConst35 = (fConst33 - fConst32);
		fConst36 = floorf(((0.031604f * fConst0) + 0.5f));
		iConst37 = int((int((fConst27 - fConst36)) & 8191));
		iConst38 = int((int((fConst36 + -1)) & 2047));
		fConst39 = floorf(((0.125f * fConst0) + 0.5f));
		fConst40 = expf((0.1f * ((0 - (6.9077554f * fConst39)) / fConst0)));
		fConst41 = faustpower<2>(fConst40);
		fConst42 = (1.0f - (fConst4 * fConst41));
		fConst43 = (1.0f - fConst41);
		fConst44 = sqrtf(max((float)0, ((faustpower<2>(fConst42) / faustpower<2>(fConst43)) + -1.0f)));
		fConst45 = (fConst42 / fConst43);
		fConst46 = (fConst40 * (fConst44 + (1.0f - fConst45)));
		fConst47 = (fConst45 - fConst44);
		fConst48 = floorf(((0.013458f * fConst0) + 0.5f));
		iConst49 = int((int((fConst39 - fConst48)) & 8191));
		iConst50 = int((int((fConst48 + -1)) & 1023));
		fConst51 = floorf(((0.210389f * fConst0) + 0.5f));
		fConst52 = expf((0.1f * ((0 - (6.9077554f * fConst51)) / fConst0)));
		fConst53 = faustpower<2>(fConst52);
		fConst54 = (1.0f - (fConst53 * fConst4));
		fConst55 = (1.0f - fConst53);
		fConst56 = sqrtf(max((float)0, ((faustpower<2>(fConst54) / faustpower<2>(fConst55)) + -1.0f)));
		fConst57 = (fConst54 / fConst55);
		fConst58 = (fConst52 * (fConst56 + (1.0f - fConst57)));
		fConst59 = (fConst57 - fConst56);
		fConst60 = floorf(((0.024421f * fConst0) + 0.5f));
		iConst61 = int((int((fConst51 - fConst60)) & 16383));
		iConst62 = int((int((fConst60 + -1)) & 2047));
		fConst63 = floorf(((0.192303f * fConst0) + 0.5f));
		fConst64 = expf((0.1f * ((0 - (6.9077554f * fConst63)) / fConst0)));
		fConst65 = faustpower<2>(fConst64);
		fConst66 = (1.0f - (fConst4 * fConst65));
		fConst67 = (1.0f - fConst65);
		fConst68 = sqrtf(max((float)0, ((faustpower<2>(fConst66) / faustpower<2>(fConst67)) + -1.0f)));
		fConst69 = (fConst66 / fConst67);
		fConst70 = (fConst64 * (fConst68 + (1.0f - fConst69)));
		fConst71 = (fConst69 - fConst68);
		fConst72 = floorf(((0.029291f * fConst0) + 0.5f));
		iConst73 = int((int((fConst63 - fConst72)) & 8191));
		iConst74 = int((int((fConst72 + -1)) & 2047));
		fConst75 = floorf(((0.256891f * fConst0) + 0.5f));
		fConst76 = expf((0.1f * ((0 - (6.9077554f * fConst75)) / fConst0)));
		fConst77 = faustpower<2>(fConst76);
		fConst78 = (1.0f - (fConst77 * fConst4));
		fConst79 = (1.0f - fConst77);
		fConst80 = sqrtf(max((float)0, ((faustpower<2>(fConst78) / faustpower<2>(fConst79)) + -1.0f)));
		fConst81 = (fConst78 / fConst79);
		fConst82 = (fConst76 * (fConst80 + (1.0f - fConst81)));
		fConst83 = (fConst81 - fConst80);
		fConst84 = floorf(((0.027333f * fConst0) + 0.5f));
		iConst85 = int((int((fConst75 - fConst84)) & 16383));
		iConst86 = int((int((fConst84 + -1)) & 2047));
		fConst87 = floorf(((0.219991f * fConst0) + 0.5f));
		fConst88 = expf((0.1f * ((0 - (6.9077554f * fConst87)) / fConst0)));
		fConst89 = faustpower<2>(fConst88);
		fConst90 = (1.0f - (fConst89 * fConst4));
		fConst91 = (1.0f - fConst89);
		fConst92 = sqrtf(max((float)0, ((faustpower<2>(fConst90) / faustpower<2>(fConst91)) + -1.0f)));
		fConst93 = (fConst90 / fConst91);
		fConst94 = (fConst88 * (fConst92 + (1.0f - fConst93)));
		fConst95 = (fConst93 - fConst92);
		fConst96 = floorf(((0.019123f * fConst0) + 0.5f));
		iConst97 = int((int((fConst87 - fConst96)) & 16383));
		iConst98 = int((int((fConst96 + -1)) & 1023));
	}
	virtual void instanceResetUserInterface() {
	}
	virtual void instanceClear() {
		IOTA = 0;
		for (int i=0; i<256; i++) fVec0[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<8192; i++) fVec1[i] = 0;
		for (int i=0; i<1024; i++) fVec2[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<8192; i++) fVec3[i] = 0;
		for (int i=0; i<1024; i++) fVec4[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<8192; i++) fVec5[i] = 0;
		for (int i=0; i<2048; i++) fVec6[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<8192; i++) fVec7[i] = 0;
		for (int i=0; i<1024; i++) fVec8[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<16384; i++) fVec9[i] = 0;
		for (int i=0; i<256; i++) fVec10[i] = 0;
		for (int i=0; i<2048; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<8192; i++) fVec12[i] = 0;
		for (int i=0; i<2048; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<16384; i++) fVec14[i] = 0;
		for (int i=0; i<2048; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<16384; i++) fVec16[i] = 0;
		for (int i=0; i<1024; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fVec18[i] = 0;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
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
		ui_interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			fVec0[IOTA&255] = (float)input0[i];
			float fTemp0 = (0.3f * fVec0[(IOTA-iConst1)&255]);
			fRec11[0] = ((fConst10 * fRec1[1]) + (fConst11 * fRec11[1]));
			fVec1[IOTA&8191] = ((0.35355338f * fRec11[0]) + 1e-20f);
			float fTemp1 = ((fTemp0 + fVec1[(IOTA-iConst13)&8191]) - (0.6f * fRec9[1]));
			fVec2[IOTA&1023] = fTemp1;
			fRec9[0] = fVec2[(IOTA-iConst14)&1023];
			float 	fRec10 = (0.6f * fVec2[IOTA&1023]);
			fRec14[0] = ((fConst22 * fRec5[1]) + (fConst23 * fRec14[1]));
			fVec3[IOTA&8191] = ((0.35355338f * fRec14[0]) + 1e-20f);
			float fTemp2 = ((fTemp0 + fVec3[(IOTA-iConst25)&8191]) - (0.6f * fRec12[1]));
			fVec4[IOTA&1023] = fTemp2;
			fRec12[0] = fVec4[(IOTA-iConst26)&1023];
			float 	fRec13 = (0.6f * fVec4[IOTA&1023]);
			fRec17[0] = ((fConst34 * fRec3[1]) + (fConst35 * fRec17[1]));
			fVec5[IOTA&8191] = ((0.35355338f * fRec17[0]) + 1e-20f);
			float fTemp3 = (fVec5[(IOTA-iConst37)&8191] - (fTemp0 + (0.6f * fRec15[1])));
			fVec6[IOTA&2047] = fTemp3;
			fRec15[0] = fVec6[(IOTA-iConst38)&2047];
			float 	fRec16 = (0.6f * fVec6[IOTA&2047]);
			fRec20[0] = ((fConst46 * fRec7[1]) + (fConst47 * fRec20[1]));
			fVec7[IOTA&8191] = ((0.35355338f * fRec20[0]) + 1e-20f);
			float fTemp4 = (fVec7[(IOTA-iConst49)&8191] - (fTemp0 + (0.6f * fRec18[1])));
			fVec8[IOTA&1023] = fTemp4;
			fRec18[0] = fVec8[(IOTA-iConst50)&1023];
			float 	fRec19 = (0.6f * fVec8[IOTA&1023]);
			fRec23[0] = ((fConst58 * fRec2[1]) + (fConst59 * fRec23[1]));
			fVec9[IOTA&16383] = ((0.35355338f * fRec23[0]) + 1e-20f);
			fVec10[IOTA&255] = (float)input1[i];
			float fTemp5 = (0.3f * fVec10[(IOTA-iConst1)&255]);
			float fTemp6 = (fVec9[(IOTA-iConst61)&16383] + (fTemp5 + (0.6f * fRec21[1])));
			fVec11[IOTA&2047] = fTemp6;
			fRec21[0] = fVec11[(IOTA-iConst62)&2047];
			float 	fRec22 = (0 - (0.6f * fVec11[IOTA&2047]));
			fRec26[0] = ((fConst70 * fRec6[1]) + (fConst71 * fRec26[1]));
			fVec12[IOTA&8191] = ((0.35355338f * fRec26[0]) + 1e-20f);
			float fTemp7 = (fVec12[(IOTA-iConst73)&8191] + (fTemp5 + (0.6f * fRec24[1])));
			fVec13[IOTA&2047] = fTemp7;
			fRec24[0] = fVec13[(IOTA-iConst74)&2047];
			float 	fRec25 = (0 - (0.6f * fVec13[IOTA&2047]));
			fRec29[0] = ((fConst82 * fRec4[1]) + (fConst83 * fRec29[1]));
			fVec14[IOTA&16383] = ((0.35355338f * fRec29[0]) + 1e-20f);
			float fTemp8 = (((0.6f * fRec27[1]) + fVec14[(IOTA-iConst85)&16383]) - fTemp5);
			fVec15[IOTA&2047] = fTemp8;
			fRec27[0] = fVec15[(IOTA-iConst86)&2047];
			float 	fRec28 = (0 - (0.6f * fVec15[IOTA&2047]));
			fRec32[0] = ((fConst94 * fRec8[1]) + (fConst95 * fRec32[1]));
			fVec16[IOTA&16383] = ((0.35355338f * fRec32[0]) + 1e-20f);
			float fTemp9 = (((0.6f * fRec30[1]) + fVec16[(IOTA-iConst97)&16383]) - fTemp5);
			fVec17[IOTA&1023] = fTemp9;
			fRec30[0] = fVec17[(IOTA-iConst98)&1023];
			float 	fRec31 = (0 - (0.6f * fVec17[IOTA&1023]));
			float fTemp10 = (fRec30[1] + fRec31);
			float fTemp11 = (fRec28 + (fRec27[1] + fTemp10));
			float fTemp12 = (fRec22 + (fRec21[1] + (fRec25 + (fRec24[1] + fTemp11))));
			fRec1[0] = (fRec10 + (fRec9[1] + (fRec13 + (fRec12[1] + (fRec16 + (fRec15[1] + (fRec19 + (fRec18[1] + fTemp12))))))));
			fRec2[0] = ((fRec10 + (fRec9[1] + (fRec13 + (fRec12[1] + (fRec16 + (fRec15[1] + (fRec18[1] + fRec19))))))) - fTemp12);
			float fTemp13 = (fRec22 + (fRec21[1] + (fRec24[1] + fRec25)));
			fRec3[0] = ((fRec10 + (fRec9[1] + (fRec13 + (fRec12[1] + fTemp13)))) - (fRec16 + (fRec15[1] + (fRec19 + (fRec18[1] + fTemp11)))));
			fRec4[0] = ((fRec10 + (fRec9[1] + (fRec13 + (fRec12[1] + fTemp11)))) - (fRec16 + (fRec15[1] + (fRec19 + (fRec18[1] + fTemp13)))));
			float fTemp14 = (fRec27[1] + fRec28);
			float fTemp15 = (fRec22 + (fRec21[1] + fTemp14));
			float fTemp16 = (fRec25 + (fRec24[1] + fTemp10));
			fRec5[0] = ((fRec10 + (fRec9[1] + (fRec16 + (fRec15[1] + fTemp15)))) - (fRec13 + (fRec12[1] + (fRec19 + (fRec18[1] + fTemp16)))));
			fRec6[0] = ((fRec10 + (fRec9[1] + (fRec16 + (fRec15[1] + fTemp16)))) - (fRec13 + (fRec12[1] + (fRec19 + (fRec18[1] + fTemp15)))));
			float fTemp17 = (fRec22 + (fRec21[1] + fTemp10));
			float fTemp18 = (fRec25 + (fRec24[1] + fTemp14));
			fRec7[0] = ((fRec10 + (fRec9[1] + (fRec19 + (fRec18[1] + fTemp17)))) - (fRec13 + (fRec12[1] + (fRec16 + (fRec15[1] + fTemp18)))));
			fRec8[0] = ((fRec10 + (fRec9[1] + (fRec19 + (fRec18[1] + fTemp18)))) - (fRec13 + (fRec12[1] + (fRec16 + (fRec15[1] + fTemp17)))));
			float fTemp19 = (fRec2[0] + fRec3[0]);
			fVec18[0] = fTemp19;
			fRec0[0] = ((0.995f * fRec0[1]) + (0.37f * (fVec18[0] - fVec18[1])));
			output0[i] = (FAUSTFLOAT)fRec0[0];
			fVec19[0] = (fRec2[0] - fRec3[0]);
			fRec33[0] = ((0.995f * fRec33[1]) + (0.37f * (fRec2[0] - (fRec3[0] + fVec19[1]))));
			output1[i] = (FAUSTFLOAT)fRec33[0];
			// post processing
			fRec33[1] = fRec33[0];
			fVec19[1] = fVec19[0];
			fRec0[1] = fRec0[0];
			fVec18[1] = fVec18[0];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec30[1] = fRec30[0];
			fRec32[1] = fRec32[0];
			fRec27[1] = fRec27[0];
			fRec29[1] = fRec29[0];
			fRec24[1] = fRec24[0];
			fRec26[1] = fRec26[0];
			fRec21[1] = fRec21[0];
			fRec23[1] = fRec23[0];
			fRec18[1] = fRec18[0];
			fRec20[1] = fRec20[0];
			fRec15[1] = fRec15[0];
			fRec17[1] = fRec17[0];
			fRec12[1] = fRec12[0];
			fRec14[1] = fRec14[0];
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			IOTA = IOTA+1;
		}
	}
};


#endif
