/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On a new branch:

 1) Add a constructor for each User-Defined-Type.
 
 2) amend some of your UDT's member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main function at the bottom of that file,

 4) call some of your UDT's amended member functions in main().
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.

 send me a DM to check your pull request

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT() { a = 0; }             //1) the constructor
    void printThing()            //the member function
    {
        std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
}

//insert Example::main() into main() of user's repo.


struct MixingBoard
{
    unsigned int numberOfChannels = 16;
    unsigned int numberOfBusses = 4;
    bool doesItHaveFX = false;
    bool doesItHaveEQ = true;
    bool doesItHaveCompression = false;

    void processMasterBuss(float channelData);
    void sendToBuss(float channelData, unsigned int bussSelect);
    float changeGain(float channelData, float gain);

    MixingBoard(unsigned int channels, unsigned int busses, bool fx, bool eq, bool comp)
    {
        numberOfChannels = channels;
        numberOfBusses = busses;
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

void sendToBuss(float channelData, unsigned int bussSelect)
{
    // we haven't touched on arrays, but this is how I'd go about it
    
    // auxBuss[bussSelect].data.push_back(channelData)

    // the member 'data' from member auxBuss would be a vector array
}

void MixingBoard::processMasterBuss(float channelData)
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
    void displayWaveform(float inputVoltage);
    float changeGain(float inputVoltage, float gain);

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

void Oscilloscope::displayWaveform(float inputVoltage)
{
    // screen.display(inputVoltage, xAxisTimeConstant, countFrequency(inputVoltage));
}

float Oscilloscope::changeGain(float inputVoltage, float gain)
{
    float saturation = 1.f;
    if ( inputVoltage > maxInputVoltage )
    {
        saturation = 100.f + inputVoltage;
    }
    return inputVoltage * gain * saturation;
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
    void controlPixel(unsigned int pixelNum, float brightness);

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

void controlPixel(unsigned int pixelNum, float brightness)
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
    float frequency = 440.f;
    float amplitude = 1.f;
    bool FMEnable;
    unsigned int numOfVoices;

    float readCV();
    void outputSound();
    float mixVoices(float voiceSignal);

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

    LFO(unsigned int wave)
    {
        waveform = wave;
    }

    void printStuff()
    {
        std::cout << "Currently outputting " << currentValue << std::endl;
    }
};

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
    unsigned int numOfSteps = 16;
    bool restartSequence = false;
    float tempo = 89.5f;
    float swing = 45.2f;
    float velocity = 90.5f;
    int instruments;

    struct Sequence
    {
        int numOfTracks = 0;

        struct Track
        {
            float data = 0.f, qntData = data;
        };

        void quantize(float input);
    };

    Sequence current_seq;
    // used playSequence() by default

    Sequence writeRecordSequence(float input);
    float playSequence(Sequence seq);
    void outputCV(Sequence seq);

    Sequencer(float input)
    {
        current_seq = writeRecordSequence(input);
        outputCV(current_seq);
    }

    void printStuff()
    {
        std::cout << "Playing sequence: " << &current_seq << std::endl;
    }
};

void Sequencer::Sequence::quantize(float input)
{
    // unimplemented 
}

Sequencer::Sequence Sequencer::writeRecordSequence(float input)
{
    Sequencer::Sequence newSequence;
    float inputStream = input; // vector, etc
    // does some stuff
    return newSequence;
} 

float Sequencer::playSequence(Sequence seq)
{
    return 0.f;
    // returns a stream of "CV" to be used by outputCV
}

void Sequencer::outputCV(Sequencer::Sequence seq)
{
    // unimplemented
}

struct VCA
{
    unsigned int numOfInputs = 2, numOfOutputs = 1;
    float maxGainOut = 100.f, minGainOut = -100.f, clipThresh, currentGain = 50.f, currentSignal = 10.f, amplifiedSignal;


    void applyGain();
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
    } components;

    void outputSound();
    float readCV(float CVInput); 
    float routeCV(float CVInput, unsigned int modMatrixDestination); 

    Synthesizer()
    {
        std::cout << "Address of components: " << &components << std::endl;

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

float Synthesizer::readCV(float CVInput)
{
    return 1.f;
    // unimplemented
}

float Synthesizer::routeCV(float CVInput, unsigned int modMatrixDestination)
{
    return 1.f;
    // unimplemented
}

int main()
{
    Example::main();
    std::cout << "good to go!" << std::endl << std::endl;

    MixingBoard mix(16, 4, true, true, true);
    mix.printStuff();

    Oscilloscope oscilloscope(2, true, 0);
    oscilloscope.printStuff();

    Television tv(1920.f);
    tv.printStuff();

    Speaker speaker(2, true);
    speaker.printStuff();

    Oscillator osc(4, true);
    osc.printStuff();

    LFO lfo(1);
    lfo.printStuff();

    Sequencer sequencer(1.f);
    sequencer.printStuff();

    VCA vca(40.f);
    vca.printStuff();

    Synthesizer synth;
    synth.printStuff();
    std::cout << synth.readCV(0.f) << std::endl;

}
