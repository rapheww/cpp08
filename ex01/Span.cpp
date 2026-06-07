/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:25:40 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/07 23:00:39 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0){}
Span::Span(unsigned int n) : _N(n){}
Span::Span(const Span& cpy){*this = cpy;}
Span& Span::operator=(const Span& src){
    if (this != &src){
        _N = src._N;
        _intVector = src._intVector;
    }
    return *this;   
}
Span::~Span(){}

const char* Span::IsFull::what() const throw(){
    return "Span is full, no more storage";
}

void Span::addNumber(int value){
    if (_intVector.size() >= _N)
        throw(Span::IsFull());
    _intVector.insert(_intVector.begin() + _intVector.size(), value);
}

// void Span::addNumber(int value){
//     if (_intVector.size() >= _N)
//         throw(Span::IsFull());
//     _intVector.insert(_intVector.begin() + _intVector.size(), value);
// }

int Span::longestSpan(){
    std::vector<int>::const_iterator itMin = std::min_element(_intVector.begin(), _intVector.end());
    std::vector<int>::const_iterator itMax = std::max_element(_intVector.begin(), _intVector.end());
    return *itMax - *itMin;
}

int Span::shortestSpan() const{
    std::vector<int> tmp = _intVector;
    int distance = std::numeric_limits<int>::max();
    std::vector<int>::const_iterator itEnd = tmp.end() - 1;
    std::vector<int>::const_iterator itStart = tmp.begin();
    std::sort(tmp.begin(), tmp.end());
    for (;itStart < itEnd; itStart++){
        if (*(itStart + 1) - *itStart < distance)
            distance = *(itStart + 1) - *itStart;
    }
    return distance;
}


// AFFICHAGE SPAN A
void displayInt(int i){
    std::cout<<i<<std::endl;
}

void Span::showTab(){
    std::cout<<"---PRINT TAB---"<<std::endl;
    std::cout<<"size of Span is "<<_intVector.size()<<std::endl;
    std::for_each(_intVector.begin(), _intVector.end(), displayInt);
}