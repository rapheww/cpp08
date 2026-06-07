/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:21:54 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/07 22:37:40 by rchaumei         ###   ########.fr       */
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
        void addNumber(int);
        int longestSpan();
        int shortestSpan() const;
        void showTab();
    private:
        unsigned int _N;
        std::vector<int> _intVector;
};