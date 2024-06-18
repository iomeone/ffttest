#pragma once

#include <JuceHeader.h>
#include <vector>
#include <queue>
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

enum
{
    fftOrder = 9,             // [1]
    fftSize = 1 << fftOrder,  // [2]
    scopeSize = 512             // [3]
};


class MainComponent  : public juce::Component , public juce::Timer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    virtual void timerCallback() ;

private:
    //==============================================================================
    // Your private member variables go here...
    juce::dsp::FFT fft ;
    bool needPaint = 0;


    
    std::list<juce::Point<double>> _points;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
