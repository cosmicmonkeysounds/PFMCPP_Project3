 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   - you should be left with only your UDTs.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
1)
Mixing board
5 properties:
    1) number of channels 
    2) number of buss'
    3) does it have internal effects? (boolean)
    4) has an EQ (boolean)
    5) has a compressor (boolean)
3 things it can do:
    1) mix channels together on master buss
    2) mix and send signals to buss'
    3) amplify/attenuate inputs
*/

struct MixingBoard
{
    // 1. number of input channels 
    unsigned int numberOfChannels = 16;
    // 2. number of routable mix busses 
    unsigned int numberOfBusses = 4;
    // 3. if it includes internal effects or not 
    bool doesItHaveFX = false;
    // 4. does it include an EQ per channel?
    bool doesItHaveEQ = true;
    // 5. does it have compressors for each channel?
    bool doesItHaveCompression = false;

    // 1. mixes channels together on master buss
    float processMasterBuss(int channelData);
    // 2. mixes and sends signals to buss
    void sendToBuss(int channelData, unsigned int bussSelect);
    // 3. changes the gain of signals 
    float changeGain(int channelData, float gain);
};

/*
2)
Oscilloscope 
5 properties:
    1) number of BNC inputs 
    2) is it analog? 
    3) maximum input voltage 
    4) number of channels in logic analyzer 
    5) time constant of X-axis
3 things it can do:
    1) count frequency of input
    2) display waveform
    3) attenuate/amplify waveform
*/

struct Oscilloscope
{
    // 1. Number of BNC inputs
    unsigned int numOfBNC = 2;
    // 2. Is this an analog scope?
    bool isThisScopeAnalog = true;
    // 3. Maximum input voltage 
    float maxInputVoltage = 130.5f;
    // 4. Number of logic analyzer channels
    unsigned int numOfLogicChannels = 0;
    // 5. Time constant on x-axis
    float xAxisTimeConstant = 96.5f;

    // 1. Count frequency of inputs
    float countFrequency(float inputVoltage);
    // 2. Display input waveforms 
    void displayWaveform(float inputVoltage);
    // 3. amplify/attenuate input signals
    float changeGain(float inputVoltage, float gain);
};

/*
3)
Television
5 properties:
    1) size of screen
    2) aspect ratio (integer that selects the ratio)
    3) number of HDMI ports
    4) number of optical ports
    5) is it smart? (boolean)
3 things it can do:
    1) turn on and off
    2) receive video from ports 
    3) control it's pixels
*/

struct Television
{
    // 1) size of screen
    float screenWidth;
    // 2) aspect ratio (integer that selects the ratio)
    unsigned int aspectRatioSelect;
    // 3) number of HDMI ports
    unsigned int numOfHDMI = 2;
    // 4) number of optical ports
    unsigned int numOfOptical = 1;
    // 5) is it smart?
    bool isItSmart = false;

    // 1) Turn on or off
    float powerCycle();
    // 2) receive video from ports
    int readPorts(int data);
    // 3) control it's pixels
    void controlPixel(unsigned int pixelNum, float brightness);
};

/*
4)
Speakers
5 properties:
    1) how many drivers?
    2) lowest frequency reproducable at -3dB
    3) highest frequency reproducable at -3dB
    4) is it active?
    5) power rating
3 things it can do:
    1) output sound 
    2) filter input through crossover(s)
    3) set volume 
*/

struct Speaker
{
    // 1) How many drivers?
    unsigned int numOfDrivers = 2;
    // 2) Lowest frequency reproducable at -3dB
    float minFrequency = 45.4f;
    // 3) Highest frequency reproducable at -3dB
    float maxFrequency = 19500.51f;
    // 4) is it active?
    bool isItActive = true;
    // 5) Power rating
    float powerRating = 80.f;

    // 1) output sound
    float outputSound(float signal); 
    // 2) filter input through crossover
    float applyCrossover(float input); 
    // 3) set volume
    void setVolume(int volume);
};

/*
5)
Oscillator 
5 properties:
    1) waveform select
    2) frequency
    3) amplitude 
    4) FM enabled
    5) number of voices
3 things it can do:
    1) read and quantize CV
    2) output sound
    3) mix voices together
*/

struct Oscillator
{
    // 1) waveform select
    unsigned int waveform = 0;
    // 2) frequency of oscillation
    float frequency = 440.f;
    // 3) amplitude of signal
    float amplitude = 1.f;
    // 4) FM enable
    bool FMEnable = false;
    // 5) number of voices
    unsigned int numOfVoices = 2;

    // 1) read and quantize CV
    float readCV(float CVSignal);
    // 2) output sound
    float outputSound(float audioSignal);
    // 3) mix voices together 
    float mixVoices(float voiceSignals);
};

/*
6)
LFO
5 properties:
    1) value of tempo
    2) swing amount 
    3) waveform select 
    4) minimum speed
    5) maximum speed
3 things it can do:
    1) read CV
    2) output CV 
    3) retrigger LFO
*/

struct LFO
{
    // 1) value of tempo
    float tempo = 120.f;
    // 2) swing amount 
    float swingAmount = 50.f;
    // 3) waveform select
    unsigned int waveform = 0;
    // 4) minimum speed
    float minSpeed = 0.0001f;
    // 5) maximum speed
    float maxSpeed = 255.f;

    // 1) read CV
    float readCV(float CVInput); 
    // 2) outputCV
    void outputCV(); // this takes no arguments because everything it needs to output is held in the member variables
    // 3) retrigger LFO
    void retrigger();
};

/*
7)
Sequencer
5 properties:
    1) number of steps
    2) restart sequence button (boolean)
    3) value of tempo
    4) swing amount
    5) velocity value
3 things it can do:
    1) write/record sequence 
    2) play sequence 
    3) output CV
*/

struct Sequencer
{
    // 1) Number of steps
    unsigned int numOfSteps = 16;
    // 2) restart sequence button
    bool restartSequence = false;
    // 3) value of tempo
    float tempo = 89.5f;
    // 4) swing amount
    float swing = 45.2f;
    // 5) velocity value
    float velocity = 90.5f;

    // Nested UDT #1
    struct Sequence
    {
        float data;
        float instruments;

        int quantize(float input);
    };

    // 1) write/record sequence
    Sequence writeRecordSequence(float input);
    // 2) play sequence
    float playSequence(Sequence seq);
    // 3) output CV
    float outputCV(Sequence sequence);
};

/*
8)
VCA
5 properties:
    1) number of inputs
    2) number of outputs
    3) input signal strength
    4) output signal strength
    5) distortion threshold
3 things it can do:
    1) attenuate or increase gain
    2) read CV
    3) mix inputs/outputs together
*/

struct VCA
{
    // 1) number of inputs
    unsigned int numOfInputs = 2;
    // 2) number of outputs
    unsigned int numOfOutputs = 1;
    // 3) input signal strength
    float inputStrength = 87.5f;
    // 4) output signal strength
    float outputStrength = 20.5f;
    // 5) distortion threshold
    float clippingThresh = 60.55f;

    // 1) attenuate or increase gain
    float changeGain(float input, float gain);
    // 2) read CV
    float readCV(float CVInput);
    // 3) mix inputs/outputs together
    float mixSignals(float signals);
};

/*
9)
Filter
5 properties:
    1) has low pass output
    2) has band pass output
    3) has hi pass output
    4) cutoff frequency value
    5) resonance value
3 things it can do:
    1) read CV
    2) apply filter to input
    3) mix outputs together
*/

struct Filter
{
    // 1) has low pass output
    bool hasLowPass = true;
    // 2) has band pass output
    bool hasBandPass = true;
    // 3) has high pass output
    bool hasHighPass = true;
    // 4) cutoff frequency value
    float cutoffFreq = 1000.f;
    // 5) resonance value
    float resonance = 0.7f;

    // Nested UDT #2
    struct LowPass
    {
        float cutoffFreq, resonance;
        unsigned int topology;

        float transferFunction(float input);
    };

    // 1) read CV
    float readCV(float CVInput);
    // 2) apply filter to input
    float applyFilter(float input);
    // 3) mix outputs together
    float mixOutputs(float outputs);
};

/*
10)
Synthesizer
5 properties:
 These 5 properties should be UDTs that you defined above.
 this goes along with the instruction:
    One of your 10 UDTs should only use UDTs for its member variable types.
    1) has a filter
    2) has a vca
    3) has a sequencer
    4) has a lfo
    5) has an oscillator 
// all of these would be UDT's that would hold the implementation and specifics of each and NOT booleans

3 things it can do:
    1) output sounds
    2) read CV 
    3) route CV in mod matrix
*/

struct Synthesizer
{
    // 1) has a filter
    Filter filter;
    // 2) has a VCA
    VCA vca;
    // 3) has a sequencer
    Sequencer sequencer;
    // 4) has a LFO
    LFO lfo;
    // 5) has an oscillator
    Oscillator oscillator;

    // 1) outputs sounds
    void outputSound(float signal);
    // 2) reads CV
    float readCV(float CVInput); 
    // 3) routes CV in mod matrix
    float routeCV(float CVInput, unsigned int modMatrixDestination); 
};

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
