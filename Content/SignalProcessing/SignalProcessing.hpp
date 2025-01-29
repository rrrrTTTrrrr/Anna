


                                                                          // ********************************************* //
                                                                          // ********************************************* //
                                                                          // **                                         ** //
                                                                          // **            SIGNAL PROCESSING            ** //
                                                                          // **                                         ** //
                                                                          // ********************************************* //
                                                                          // ********************************************* //








********************************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************************
**                                                                                                                                                                                                    **
**                                                                                             OVERVIEW                                                                                               **
**                                                                                                                                                                                                    **
********************************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************************




A signal is just a sequence of numbers, that represent something. Could by symphony, which means audio, or a picture, which means video. A camera is continuously taking pictures, and this
pictures are cut into tiny pieces of information. Usually the information from the real world is too much too handle or transmit, and therefore it must be compressed in some way. The
question is then how to reduce the data and still maintain the main features of it.

When dealing with real life signals, there is always some level of noise. This noise makes processing the signal very hard. Therefore, usually the first step of working with a signal is to
remove the noise. The question is of course what is the signal itself and what is the noise?

The general idea is that the signal is the main component or the 'strong' component, and the noise in the secondary component or the 'weak'. When looking at a signal, there is no main
component or secondary, there is only the signal, then how can those components be separated to distinguish between them?

The method usually used is called 'transform Fourier'. As the name applies it transform the data in a way that makes it more easy to determine the components of the signal. Transform
Fourier takes data from the 'time' domain and convert it into the 'frequency' domain. In the frequency domain each existing component is associated with 'magnitude' or how dominant
is the component, which when is plotted, makes it more easy to notice the components that build the signal, and furthermore which have large magnitude ( main ) and which don't ( noise ).
Now when the noise components can be better identified, the next step is to choose how to filter them out of the signal.

The most basic filters are 'low pass filter' which allows low frequency to pass, or 'high pass filter' which allows high frequency to pass. The concept is pretty simple, multiple the
signal by a function that contains values close to one for the part that should stay pretty much the same, and values close to 0 for the part that should be filtered. Then if the main
component of the signal is at low frequency, and the noise is in higher frequency, then a low pass filter should be used to let the low frequency part stay as much as possible the same,
while reducing the high frequency parts as much as possible.




********************************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************************
**                                                                                                                                                                                                    **
**                                                                                        IMPULSE RESPONSE                                                                                            **
**                                                                                                                                                                                                    **
********************************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************************




In signal processing, the impulse response, or impulse response function ( IRF ), of a dynamic system is its output when presented with a brief input signal, called an impulse. More
generally, an impulse response is the reaction of any dynamic system in response to some external change. In both cases, the impulse response describes the reaction of the system as
a function of time ( or possibly as a function of some other independent variable that parameterizes the dynamic behavior of the system ).

In all these cases, the dynamic system and its impulse response may be actual physical objects, or may be mathematical systems of equations describing such objects.

Since the impulse function contains all frequencies, the impulse response defines the response of a linear time invariant system for all frequencies.

Mathematically, how the impulse is described depends on whether the system is modeled in discrete or continuous time. The impulse can be modeled as a Dirac delta function for
continuous time systems, or as the Kronecker delta for discrete time systems. The Dirac delta represents the limiting case of a pulse made very short in time while maintaining
its area or integral ( thus giving an infinitely high peak ). While this is impossible in any real system, it is a useful idealisation. In Fourier analysis theory, such an impulse
comprises equal portions of all possible excitation frequencies, which makes it a convenient test probe.

Any system in a large class known as linear time invariant ( LTI ) is completely characterized by its impulse response. That is, for any input, the output can be calculated in
terms of the input and the impulse response. The impulse response of a linear transformation is the image of Dirac's delta function under the transformation, analogous to the
fundamental solution of a partial differential operator.

It is usually easier to analyze systems using transfer functions as opposed to impulse responses. The transfer function is the Laplace transform of the impulse response. The
Laplace tansform of a system's output may be determined by the multiplication of the transfer function with the input's Laplace transform in the complex plane, also known as the
frequency domain. An inverse Laplace transform of this result will yield the output in the time domain.

To determine an output directly in the time domain requires the convolution of the input with the impulse response. When the transfer function and the Laplace transform of the
input are known, this convolution may be more complicated than the alternative of multiplying two functions in the frequency domain.

These impulse response, considered as Green's function, can be thought of as an 'influence function' - how a point of input influences output!




********************************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************************
**                                                                                                                                                                                                    **
**                                                                                            FILTERS                                                                                                 **
**                                                                                                                                                                                                    **
********************************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************************




********************************************************************************************************************************************************************************************************
**                                                                                      BUTTERWORTH FILTER                                                                                            **
********************************************************************************************************************************************************************************************************



The butterworth filter is a type of signal processing filter designed to have a frequency response as flat as possible in the passband. It is also referred to as a maximally flat
magnitude filter. The frequency response of the butterworth filter is maximally flat in the passband and rolls off towards zero in the stopband. When viewed on a logarithmic Bode
plot, the response slopes off lineraly towards negative infinity.
