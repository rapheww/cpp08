/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 21:03:09 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/08 22:35:47 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>{
    public:
        MutantStack() : std::stack<T>(){}
        MutantStack(const MutantStack& cpy): std::stack<T>(cpy){}
        MutantStack& operator=(const MutantStack& src){
            if (this != &src)
                std::stack<T>::operator=(src);
            return *this;
        }
        ~MutantStack(){}
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin(){return this->c.begin();}
        iterator end(){return this->c.end();}
        const_iterator begin() const{return this->c.begin();}
        const_iterator end() const{return this->c.end();}
};