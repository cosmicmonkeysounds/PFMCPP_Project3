/*
 Project 3 - Part 1 / 5
Video:  Chapter 2 Part 5
 User-Defined Types

 Create a branch named Part1

 Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to reinforce the syntax habits that C++ requires.  What you create in this project will be used as the basis of Project 5 in the course.   
 
 1) write 10 user-defined types in plain-English, 
    in the comments above your UDT, write out, in plain-english, 3 things it can do, and 5 traits.
    Note: Your 10th UDT will use 5 of your UDTs for its properties, so maybe start on UDT #10 first. This goes along with instruction #6.
************************
    Commit after you complete this step so i can review before you proceed with the rest of the projects
    Ping me in Slack to review this step.
    Wait for me to review before proceeding with step 2.
************************
  
 2) define your struct for each of your 10 types. 
    Copy your 3+5 comments into your struct body.
    comment them out.
 
 3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    give the member variables relevant data types
 
 4) make the function parameter list for those member functions use some of your User-Defined Types
    You'll write definitions in part2 for these functions
    you'll call each of these functions in part3
 
 5) make 2 of the 10 user-defined types have a nested class.  
    this nested class also needs member functions.
    this nested class is not considered one of your 10 UDTs.
 
 6) One of your 10 UDTs should only use UDTs for its member variable types.   
    No primitives allowed!
    it still needs member variables.
 
 7) After you finish defining each type, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
 example:  

//1) write out, in plain-english, 5 traits and 3 things it can do.
Car Wash   
5 properties:
    1) has vacuum cleaners
    2) has eco-friendly cleaning supplies
    3) stores the amount of water used per week.
    4) stores amount of profit made per week
    5) number of cars serviced per day

3 things it can do:
    1) wash and wax car
    2) charge customer
    3) detail the car interior
 */
struct CarWash //2)        
{
    //2) has vacuum cleaners
    bool hasVacuumCleaners = true; //3) member variables with relevant data types.
    //2) has eco-friendly cleaning supplies
    bool hasEcoFriendlyCleaningSupplies = true; //3) member variables with relevant data types.
    //2) stores the amount of water used per week.
    float waterUsedPerWeek = 200.f; //3) member variables with relevant data types.
    //2) stores amount of profit made per week
    float profitPerWeek = 495.95f; //3) member variables with relevant data types.
    //2) number of cars serviced per day
    int numberOfCarsServiced = 10; //3) member variables with relevant data types.
    
    //5) make 2 of the 10 user-defined types have a nested class. 
    struct Car   
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);   
    };

    /* 
    member functions with a user-defined type as the parameter.
    The user-defined type parameter happens to be the nested class.
    */

    //2) wash and wax car
    void washAndWaxCar( Car car );
    //2) charge customer
    float chargeCustomer();
    //2) detail the car interior
    void detailInterior( Car car );
    
               
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};

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
    void processMasterBuss(void* channelData);
    // 2. mixes and sends signals to buss
    void sendToBuss(void* channelData, unsigned int bussSelect);
    // 3. changes the gain of signals 
    void changeGain(void* channelData, float gain);
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
    float countFrequency(void* inputVoltage);
    // 2. Display input waveforms 
    void displayWaveform(void* inputVoltage);
    // 3. amplify/attenuate input signals
    void changeGain(void* inputVoltage, float gain);
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
    void powerCycle();
    // 2) receive video from ports
    void readPorts(void* data);
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
    void outputSound(void* signal); FIXME pointers have not been covered yet.  don't use them.
    // 2) filter input through crossover
    void* applyCrossover(void* input); FIXME pointers have not been covered yet.  don't use them.

    // 3) set volume
    void setVolume(float volume);
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
    void* readCV(void* CVSignal); FIXME pointers have not been covered yet.  don't use them.
    // 2) output sound
    void outputSound(void* audioSignal); FIXME pointers have not been covered yet.  don't use them.
    // 3) mix voices together 
    void* mixVoices(void* voiceSignals); FIXME pointers have not been covered yet.  don't use them.
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
    void* readCV(void* CVInput); FIXME pointers have not been covered yet.  don't use them.
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
        void* data; FIXME pointers have not been covered yet.  don't use them.
        void* instruments; FIXME pointers have not been covered yet.  don't use them.

        void* quantize(void* input); FIXME pointers have not been covered yet.  don't use them.
    };

    // 1) write/record sequence
    Sequence writeRecordSequence(void* input); FIXME pointers have not been covered yet.  don't use them.
    // 2) play sequence
    void playSequence(Sequence seq);
    // 3) output CV
    void outputCV(Sequence sequence);
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
    void* changeGain(void* input); FIXME pointers have not been covered yet.  don't use them.
    // 2) read CV
    void* readCV(void* CVInput); FIXME pointers have not been covered yet.  don't use them.
    // 3) mix inputs/outputs together
    void* mixSignals(void* signals); FIXME pointers have not been covered yet.  don't use them.
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

        void* transferFunction(void* input); FIXME pointers have not been covered yet.  don't use them.
    };

    // 1) read CV
    void readCV(void* CVInput); FIXME pointers have not been covered yet.  don't use them.
    // 2) apply filter to input
    void* applyFilter(void* input); FIXME pointers have not been covered yet.  don't use them.
    // 3) mix outputs together
    void* mixOutputs(void* outputs); FIXME pointers have not been covered yet.  don't use them.
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
    void outputSound(void* signal); FIXME pointers have not been covered yet.  don't use them.
    // 2) reads CV
    void* readCV(void* CVInput); FIXME pointers have not been covered yet.  don't use them.
    // 3) routes CV in mod matrix
    void routeCV(void* CVInput, unsigned int modMatrixDestination); FIXME pointers have not been covered yet.  don't use them.
};

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
