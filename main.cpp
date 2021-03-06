/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example {
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}

//call Example::main() in main()

struct MixingBoard
{
    unsigned int numberOfChannels, numberOfBusses;
    bool doesItHaveFX, doesItHaveEQ, doesItHaveCompression;

    void processMasterBuss(float);
    void sendToBuss(float, unsigned int);
    float changeGain(float channelData, float gain);

    MixingBoard(bool fx, bool eq, bool comp) : numberOfChannels(16), numberOfBusses(4)
    {
        doesItHaveFX = fx;
        doesItHaveEQ = eq;
        doesItHaveCompression = comp;
    }

    void printStuff()
    {
        std::cout << "Mixer size is: " << numberOfChannels << " x " << numberOfBusses << std::endl;
    }
};

float MixingBoard::changeGain(float channelData, float gain)
{
    return static_cast<float>(channelData) * gain;
}

void sendToBuss(float, unsigned int)
{
    // we haven't touched on arrays, but this is how I'd go about it
    
    /*
    for( int i = 1; i < numberOfBusses; i++ )
    {
        auxBuss[bussSelect].data.push_back(channelData);
        // the member 'data' from member auxBuss would be a vector array
    }
    */

    
}

void MixingBoard::processMasterBuss(float)
{
    // masterBussSignals.push_back(( changeGain(channelData, masterBussLevel) ))
}

struct Oscilloscope
{
    unsigned int numOfBNC = 2;
    bool isThisScopeAnalog = true;
    float maxInputVoltage = 130.5f;
    unsigned int numOfLogicChannels = 0;
    float xAxisTimeConstant = 96.5f;

    float countFrequency(float inputVoltage);
    void displayWaveform(float);
    float maxGain(float inputVoltage, float gain);

    Oscilloscope(unsigned int bnc, bool analog, unsigned int logic = 0)
    {
        numOfBNC = bnc;
        isThisScopeAnalog = analog;
        numOfLogicChannels = logic;
        if ( analog )
        {
            numOfLogicChannels = 0;
        }
    }

    void printStuff()
    {
        std::cout << "A " << numOfBNC << " input " << (isThisScopeAnalog ? "analog" : "digital") << " scope with " << numOfLogicChannels << " logic anaylzer channels." << std::endl;
    }

};

float Oscilloscope::countFrequency(float inputVoltage)
{
    // F(n) = n(n+1)(n+2)/6
    // probably (definitely) need an array to do this properly
    return ( inputVoltage * (inputVoltage + 1) * (inputVoltage + 2) ) / 6.f;
}

void Oscilloscope::displayWaveform(float)
{
    // screen.display(inputVoltage, xAxisTimeConstant, countFrequency(inputVoltage));
}

float Oscilloscope::maxGain(float inputVoltage, float gain)
{
    while ( inputVoltage * gain < maxInputVoltage )
    {
        gain += gain;
    }
    return gain;
}

struct Television
{
    float screenWidth;
    unsigned int aspectRatioSelect;
    unsigned int numOfHDMI = 2;
    unsigned int numOfOptical = 1;
    bool isOn = false, isItSmart = false;

    void powerCycle();
    int readPorts(int portNumber);
    void controlPixel(unsigned int, float);

    Television(float screen = 1920.f, unsigned int ratio = 1)
    {
        screenWidth = screen;
        aspectRatioSelect = ratio;
    }

    void printStuff()
    {
        std::cout << "Resolution is " << screenWidth << " by " << ( ( screenWidth / 16.f ) * 9.f ) << std::endl;
    }
};

void Television::powerCycle()
{
    isOn = !isOn;

    // if ( isOn )
    // {
    //     startup();
    // }
    // else
    // {
    //     shutdown();
    // }
}

int Television::readPorts(int portNumber)
{
    // will come back and implement later when more types are revealed
    return portNumber;

    // vvv Here's a rough sketch vvv

    /*
    std::vector<int> portData;

    for ( int i = 1; i < numberOfPorts; ++i )
    {
        portData.push_back(ports[i].read());
    }

    return portData;
    */
}

void controlPixel(unsigned int, float)
{
    // pixel[pixelNum].changeBrightness(brightness);
    // unimplemented
}

struct Speaker
{
    unsigned int numOfDrivers;
    float minFrequency = 45.4f;
    float maxFrequency = 19500.51f;
    bool isItActive;
    float powerRating = 80.f;
    int volume;
 
    float applyCrossover(float input); 
    void outputSound(float signal);
    void setVolume(int newVolume);

    Speaker(unsigned int drivers = 2, bool active = true)
    {
        numOfDrivers = drivers;
        isItActive = active;
    }

    void printStuff()
    {
        std::cout << numOfDrivers << " woofers with " << (isItActive ? "active " : "passive ") << "inputs." << std::endl;
    }
};

float Speaker::applyCrossover(float signal)
{
    // this would have some complicated DSP stuff but I'm not even gonna pretend I know what's up
    // so I'll just return the signal for now
    return signal;
}

void Speaker::outputSound(float signal)
{
    float sig = applyCrossover(signal);
    // other DSP stuff
    sig *= static_cast<float>(volume);
    // speakers.output(sig);
}

void Speaker::setVolume(int newVolume)
{
    volume = newVolume;
}

struct Oscillator
{
    unsigned int waveform = 0;
    float frequency = 440.f, minFreq = 20.f, maxFreq = 20000.f;
    float amplitude = 1.f;
    bool FMEnable;
    unsigned int numOfVoices;

    float readCV();
    void outputSound();
    float mixVoices(float voiceSignal);
    void sweepFrequency();

    Oscillator(unsigned int voices = 2, bool fm = false)
    {
        FMEnable = fm;
        numOfVoices = voices;
    }

    void printStuff()
    {
        std::cout << "A " << numOfVoices << " voice " << (FMEnable ? "FM " : "") << "oscillator" << std::endl; 
    } 
};

void Oscillator::sweepFrequency()
{
    for ( float i = minFreq; i <= maxFreq; i += 1.f )
    {
        frequency = i;
        outputSound();
    }
}

float Oscillator::readCV()
{
    // returns a stream from the inputs
    return 0.f;

    /*
    std::vector<float> CVInputs;
    for ( int i = 1; i <= numOfCVInputs; ++i )
    {
        CVInputs.push_back( CVInputPorts[i].read() );
    }
    return CVInputs;
    */
}

float Oscillator::mixVoices(float voiceSignal)
{
    return voiceSignal;

    // voiceSignal would be array that holds all the data for each voice
    
    // float mixedSignals = 0;
    
    // for ( int i = 1; i <= numOfVoices; ++i )
    // {
    //     mixedSignals += voiceSignal[i];
    // }

    // return mixedSignals;
}

void Oscillator::outputSound()
{
    /*
    std::vector<float> voiceSignals;

    for ( int i = 1; i <= numOfVoices; ++i )
    {
        voiceSignals.push_back(voice[i]);
    }

    audioOutputPort.output( mixVoices(voiceSignals) )
    */
}

struct LFO
{
    float tempo = 120.f;
    float swingAmount = 50.f;
    unsigned int waveform = 0;
    float minSpeed = 0.0001f;
    float maxSpeed = 255.f;
    float currentValue = 0;

    float readCV(); 
    void outputCV(); 
    void retrigger();
    void cycleWaveform();

    LFO(unsigned int wave)
    {
        waveform = wave;
    }

    void printStuff()
    {
        std::cout << "Currently outputting " << currentValue << std::endl;
    }
};

void LFO::cycleWaveform()
{
    for ( unsigned int i = 0; i < 4; ++i )
    {
        waveform = i;
        retrigger();
    }
}

float LFO::readCV()
{
    // returns a stream from the inputs
    return 0.f;
}

void LFO::outputCV()
{
    // unimplemented 
}

void LFO::retrigger()
{
    currentValue = 0;
    // the value "currentValue" would likely be different than 0 if the LFO was actually running, making this a crude reset, setting it to the value at instantiation, 0. 
}

struct Sequencer
{
    int numOfSteps = 16;
    bool restartSequence = false;
    float tempo = 89.5f;
    float swing = 45.2f;
    float velocity = 90.5f;
    int instruments;

    struct Sequence
    {
        int numOfTracks = 0, steps = 16;

        struct Track
        {
            float data = 0.f, qntData = data;
        } track;

        void quantize(float);
    };

    Sequence current_seq;
    // used playSequence() by default

    float generateRandomSequence();
    Sequence writeRecordSequence(float);
    float playSequence(Sequence);
    void outputCV(Sequence);

    Sequencer(float input)
    {
        current_seq = writeRecordSequence(input);
        outputCV(current_seq);
    }

    void printStuff()
    {
        std::cout << "Playing data: " << current_seq.track.data << std::endl;
    }
};

float Sequencer::generateRandomSequence()
{
    
    float rand = 0.f;
    for ( int i = 1; i <= numOfSteps; ++i )
    {
        rand = numOfSteps % i;
        // I know this is not a proper random function, but I don't want to go outside the scope of this part.
    }
    return rand;
}

void Sequencer::Sequence::quantize(float)
{
    // unimplemented 
}

Sequencer::Sequence Sequencer::writeRecordSequence(float)
{
    Sequencer::Sequence newSequence;
    // does some stuff
    return newSequence;
} 

float Sequencer::playSequence(Sequence)
{
    return 0.f;
    // returns a stream of "CV" to be used by outputCV
}

void Sequencer::outputCV(Sequence)
{
    // unimplemented
}

struct VCA
{
    unsigned int numOfInputs = 2, numOfOutputs = 1;
    float maxGainOut = 100.f, minGainOut = -100.f, clipThresh, currentGain = 50.f, currentSignal = 10.f, amplifiedSignal;


    void applyGain();
    float gainBeforeClipping();
    void saturate(float clipAmount);
    float readCV();

    VCA(float clip = 60.5f)
    {
        clipThresh = clip;
    }

    void printStuff()
    {
        std::cout << "Currently at " << currentGain << " dB of gain" << std::endl;
    }
};

void VCA::saturate(float clipAmount)
{
    amplifiedSignal  = clipThresh + ( (clipAmount * currentGain) / (3.14f * clipAmount) );
}

float VCA::readCV()
{
    return 1.f;
    // not implemented
}

void VCA::applyGain()
{
    amplifiedSignal = currentSignal * ( currentGain - readCV() );
    if ( amplifiedSignal > clipThresh )
    {
        saturate( amplifiedSignal - clipThresh );
    }
}

float VCA::gainBeforeClipping()
{
    float level = currentSignal, gain = 1.f;

    while ( level < clipThresh )
    {
        level *= gain;
        gain += 1.f;
    }
    return gain;
}

struct Filter
{
    bool hasLowPass, hasBandPass, hasHighPass;
    float cutoffFreq = 1000.f, resonance = 0.7f;

    struct LowPass
    {
        float cutoffFreq, resonance;
        unsigned int topology;

        float transferFunction(float input);
    } lowPass;

    float applyFilter(float input);
    void filterSweep(float low, float high);

    Filter(bool lp = true, bool bp = false, bool hp = false)
    {
        hasLowPass = lp;
        hasBandPass = bp;
        hasHighPass = hp;
    }

    void printStuff()
    {
        std::cout << "A filter with a " << (hasLowPass ? "low pass" : "") << (hasBandPass ? " bandpass " : "") << (hasHighPass ? "highpass " : "") << std::endl;
    }
};

float Filter::LowPass::transferFunction(float input)
{
    // DSP stuff; not implemented 
    return input;
}

float Filter::applyFilter(float input)
{
    float filtered = input; // this will be a vector
    if ( hasLowPass )
    {
        filtered = lowPass.transferFunction(input);
    }
    return filtered;
}

void Filter::filterSweep(float low, float high)
{
    for ( float i = low; i <= high; i += 1.f )
    {
        cutoffFreq = i;
    }
}

struct Synthesizer
{
    struct Components
    {
        Filter filter = Filter(true, false, false);
        VCA vca = VCA(60.5f);
        Sequencer sequencer = Sequencer(1.0f);
        LFO lfo = LFO(1);
        Oscillator oscillator = Oscillator(2, false);

        // not sure why, but I get a weird error I'm not instantiating correctly if I don't do it this way?
    }; //components;
    Components components;

    void outputSound();
    float readCV(float); 
    float routeCV(float, unsigned int); 

    Synthesizer()
    {
        std::cout << "Making synth! " << std::endl;

    }

    void printStuff()
    {
        std::cout << "Doing fun synth stuff, bleep bloop" << std::endl;
    }
};

void Synthesizer::outputSound()
{
    // unimplemented
}

float Synthesizer::readCV(float)
{
    return 1.f;
    // unimplemented
}

float Synthesizer::routeCV(float, unsigned int)
{
    return 1.f;
    // unimplemented
}

int main()
{
    Example::main();
    std::cout << "good to go!" << std::endl << std::endl;

    MixingBoard mix(true, true, true);
    mix.printStuff();

    Oscilloscope oscilloscope(2, true, 0);
    oscilloscope.printStuff();
    
    std::cout << "Max gain for a signal at 10dB is: " << oscilloscope.maxGain(10.f, 1.f) << "dB" << std::endl;

    Television tv(1920.f);
    tv.printStuff();

    Speaker speaker(2, true);
    speaker.printStuff();
    
    std::cout << "This speaker's lowest frequency is: " << speaker.minFrequency << ", highest is: " << speaker.maxFrequency << std::endl;

    Oscillator osc(4, true);
    osc.printStuff();

    LFO lfo(1);
    lfo.printStuff();

    Sequencer sequencer(1.f);
    sequencer.printStuff();

    std::cout << "Last random value from sequence is: " << sequencer.generateRandomSequence() << std::endl;

    VCA vca(40.f);
    vca.printStuff();

    std::cout << "Gain before clipping VCA with current signal: " << vca.gainBeforeClipping() << "dB" << std::endl;

    Filter filter(true, false, false);
    filter.printStuff();
    std::cout << "Low pass transfer function outputing: " << filter.lowPass.transferFunction(1.f) << std::endl;

    Synthesizer synth;
    synth.printStuff();
    
    std::cout << "Currently reading " << synth.readCV(0.f) << " from CV port" << std::endl;
}
