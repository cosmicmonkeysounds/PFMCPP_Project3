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

#include <iostream>

struct Person
{
    int age, height, distanceTraveled = 0;
    float hairLength, GPA;
    unsigned int SATScore;

    struct Foot
    {
        void stepForward()
        {
            std::cout << "Stepping..." << std::endl;
        }
        int stepSize()
        {
           return 1; 
        }
    };
    
    Foot leftFoot, rightFoot;

    void run(bool startWithLeftFoot);
};

void Person::run(bool startWithLeftFoot)
{
    if( startWithLeftFoot )
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

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
    unsigned int numOfDrivers = 2;
    float minFrequency = 45.4f;
    float maxFrequency = 19500.51f;
    bool isItActive = true;
    float powerRating = 80.f;
    int volume;
 
    float applyCrossover(float input); 
    void outputSound(float signal);
    void setVolume(int newVolume);
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
    bool FMEnable = false;
    unsigned int numOfVoices = 2;

    float readCV();
    void outputSound();
    float mixVoices(float voiceSignal);
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
    float maxGainOut = 100.f, minGainOut = 20.f, clipThresh = 60.55f, currentGain = 50.f, currentSignal = 10.f, amplifiedSignal;


    void applyGain();
    void saturate(float clipAmount);
    float readCV();
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
    bool hasLowPass = true, hasBandPass = true, hasHighPass = true;
    float cutoffFreq = 1000.f, resonance = 0.7f;

    struct LowPass
    {
        float cutoffFreq, resonance;
        unsigned int topology;

        float transferFunction(float input);
    } lowPass;

    float applyFilter(float input);
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
        Filter filter;
        VCA vca;
        Sequencer sequencer;
        LFO lfo;
        Oscillator oscillator;
    } components;

    void outputSound();
    float readCV(float CVInput); 
    float routeCV(float CVInput, unsigned int modMatrixDestination); 
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
    std::cout << "good to go!" << std::endl;
}
