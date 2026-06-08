/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:21:54 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/08 20:44:56 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span {
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& cpy);
        Span& operator=(const Span& src);
        ~Span();
        
        class IsFull : public std::exception{
            public:
            const char* what() const throw();  
        };
        
        class EnoughSpace : public std::exception{
            public:
            const char* what() const throw();  
        };
        class MissingElement : public std::exception{
            public:
            const char* what() const throw();  
        };
        void addNumber(int);
        void addNumber(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end);
        int longestSpan();
        int shortestSpan() const;
        void showTab();
    private:
        unsigned int _N;
        std::vector<int> _intVector;
};