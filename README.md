# ExpFilter
## What is it ?
It's a very simple class that filters a value over time, to minimize aleas. It gives about the same result as a running average, but without the problem of using huge amount of memory to store previous values.
## How does it work ?
It simply adds the current value to the previous one, by applying a coefficient to both.
It has been written to filter analog inputs readings.
It uses fixed point math to get lighter and faster computing.
## Class description
`begin()` only affect an initial value to the filter. Pass a uint16_t (or unsigned int on 8 bit atmega).
`setCoef()` give the filtering coefficient. Pass a uint8_t. 255 is no filtering, 0, is no evolution !
`filter()` apply pass the given value (uint16_t) through the filter, and returns the filtered value.
`getValue()` returns the last value returned by the filter. May be usefull if needed several times.
## Misc
This has been written fast, and bare minimum, to suit a project where heavy filtering of analog inputs was needed. It could benefit from a template, so it can handle several object types. One day maybe !