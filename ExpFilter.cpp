/*
 * This Arduino library is for filtering data using exponential filter.
 * Copyright (C) 2020  Pierre-Loup Martin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Exponential filter is an easy way to filter data.
// It gives about the same result as a running average, but uses much less memory !


#include "ExpFilter.h"

ExpFilter::ExpFilter(){
	_filterCoef = 255;
}

void ExpFilter::begin(uint16_t value){
	_lastValue = value;
}

void ExpFilter::setCoef(uint8_t value){
	_filterCoef = value;
}

uint16_t ExpFilter::filter(uint16_t value){
	_lastValue = _value;
	_value = value;

	uint32_t filter = (uint32_t)_value * _filterCoef + (uint32_t)_lastValue * (255 - _filterCoef);
	filter /= 0xFF;
	_value = filter;

	return _value;
}

uint16_t ExpFilter::getValue(){
	return _value;
}

