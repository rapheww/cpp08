/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:27:49 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/06 18:47:30 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <algorithm>
# include <iterator>
# include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T& intContainer, const int value){
    typename T::const_iterator it;

    it = std::find(intContainer.begin(), intContainer.end(), value);
    if (it == intContainer.end())
        throw(std::out_of_range("Value isn't in the container"));
    return (it);
}