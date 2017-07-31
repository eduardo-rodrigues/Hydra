/*----------------------------------------------------------------------------
 *
 *   Copyright (C) 2016 Antonio Augusto Alves Junior
 *
 *   This file is part of Hydra Data Analysis Framework.
 *
 *   Hydra is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Hydra is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Hydra.  If not, see <http://www.gnu.org/licenses/>.
 *
 *---------------------------------------------------------------------------*/

/*
 * multiarray.inl
 *
 *  Created on: 23/07/2017
 *      Author: Antonio Augusto Alves Junior
 */

#ifndef MULTIARRAY_INL_
#define MULTIARRAY_INL_

namespace hydra {



template< size_t N, typename T, hydra::detail::Backend BACKEND>
inline void multiarray<N,T,detail::BackendPolicy<BACKEND>>::pop_back()
{
	for( size_t i=0; i<N; i++)
	this->fData[i].pop_back();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
inline void multiarray<N,T,detail::BackendPolicy<BACKEND>>::push_back(const T (&args)[N])
{

	for( size_t i=0; i<N; i++)
	this->fData[i].push_back(args[i]);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
inline void multiarray<N,T,detail::BackendPolicy<BACKEND>>::push_back(std::initializer_list<T>const& list_args)
{
	if(list_args.size()!=N){
		std::cout << "Warning: std::initializer_list<T>::size() != N " << " >> not push_back failed.";
	}
	for( size_t i=0; i<N; i++)
		this->fData[i].push_back(*(list_args.begin()+i));
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
size_t multiarray<N,T,detail::BackendPolicy<BACKEND>>::size() const
{
	return this->fData[0].size();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
size_t multiarray<N,T,detail::BackendPolicy<BACKEND>>::capacity() const
{
	return this->fData[0].capacity();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
bool multiarray<N,T,detail::BackendPolicy<BACKEND>>::empty() const
{
	return this->fData[0].empty();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
void multiarray<N,T,detail::BackendPolicy<BACKEND>>::resize(size_t size)
{
	for( size_t i=0; i<N; i++)
		this->fData[i].resize( size );
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
void multiarray<N,T,detail::BackendPolicy<BACKEND>>::clear()
{
	for( size_t i=0; i<N; i++)
		this->fData[i].clear();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
void multiarray<N,T,detail::BackendPolicy<BACKEND>>::shrink_to_fit()
{
	for( size_t i=0; i<N; i++)
		this->fData[i].shrink_to_fit();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
void multiarray<N,T,detail::BackendPolicy<BACKEND>>::reserve(size_t size)
{
	for( size_t i=0; i<N; i++)
		this->fData[i].reserve( size );
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::reference_tuple
multiarray<N,T,detail::BackendPolicy<BACKEND>>::front()
{
	return detail::get_front_tuple(this->fData);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_reference_tuple
multiarray<N,T,detail::BackendPolicy<BACKEND>>::front() const
{
	return detail::get_cfront_tuple(this->fData);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::reference_tuple
multiarray<N,T,detail::BackendPolicy<BACKEND>>::back()
{
	return detail::get_back_tuple(this->fData);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_reference_tuple
multiarray<N,T,detail::BackendPolicy<BACKEND>>::back() const
{
	return detail::get_cback_tuple(this->fData);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::pointer_tuple
multiarray<N,T,detail::BackendPolicy<BACKEND>>::data()
{
	return detail::get_data_tuple(this->fData);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_pointer_tuple
multiarray<N,T,detail::BackendPolicy<BACKEND>>::data() const
{
	return detail::get_cdata_tuple(this->fData);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::begin()
{
	typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator_array temp{};

	for(size_t i=0; i< N; i++)
	temp[i]= this->fData[i].begin();

	return detail::get_zip_iterator(temp);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::end()
{
	typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator_array temp{};

	for(size_t i=0; i< N; i++)
	temp[i]= this->fData[i].end();

	return detail::get_zip_iterator(temp);
}


template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::begin() const
{
	typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator_array temp{};

	for(size_t i=0; i< N; i++)
	temp[i]= this->fData[i].cbegin();

	return detail::get_zip_iterator(temp);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::end() const
{
	typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator_array temp{};

	for(size_t i=0; i< N; i++)
	temp[i]= this->fData[i].cend();

	return detail::get_zip_iterator(temp);
}


template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::cbegin() const
{
	typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator_array temp{};

	for(size_t i=0; i< N; i++)
	temp[i]= this->fData[i].cbegin();

	return detail::get_zip_iterator(temp);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::cend() const
{
	typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator_array temp{};

	for(size_t i=0; i< N; i++)
	temp[i]= this->fData[i].cend();

	return detail::get_zip_iterator(temp);
}


template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::reverse_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::rbegin()
{
	typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator_array temp{};

	for(size_t i=0; i< N; i++)
	temp[i]= this->fData[i].rbegin();

	return detail::get_zip_iterator(temp);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::reverse_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::rend()
{
	typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator_array temp{};

	for(size_t i=0; i< N; i++)
	temp[i]= this->fData[i].rend();

	return detail::get_zip_iterator(temp);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_reverse_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::rbegin()  const
{
	typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator_array temp{};

	for(size_t i=0; i< N; i++)
	temp[i]= this->fData[i].crbegin();

	return detail::get_zip_iterator(temp);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_reverse_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::rend()  const
{
	typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator_array temp();

	for(size_t i=0; i< N; i++)
	temp[i]= this->fData[i].crend();

	return detail::get_zip_iterator(temp);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_reverse_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::crbegin()  const
{
	typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator_array temp();

	for(size_t i=0; i< N; i++)
	temp[i]= this->fData[i].crbegin();

	return detail::get_zip_iterator(temp);
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_reverse_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::crend()  const
{
	typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::iterator_array temp();

	for(size_t i=0; i< N; i++)
	temp[i]= this->fData[i].crend();

	return detail::get_zip_iterator(temp);
}

//==============================

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::viterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::begin(size_t i)
{
	return this->fData[i].begin();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::viterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::end(size_t i)
{
	return this->fData[i].end();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::vreverse_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::rbegin(size_t i)
{
	return this->fData[i].rbegin();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::vreverse_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::rend(size_t i)
{
	return this->fData[i].rend();
}

//==============================
template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_viterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::begin(size_t i) const
{
	return this->fData[i].cbegin();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_viterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::end(size_t i) const
{
	return this->fData[i].cend();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_viterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::cbegin(size_t i) const
{
	return this->fData[i].cbegin();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_viterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::cend(size_t i) const
{
	return this->fData[i].cend();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_vreverse_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::rbegin(size_t i) const
{
	return this->fData[i].crbegin();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_vreverse_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::rend(size_t i) const
{
	return this->fData[i].crend();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_vreverse_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::crbegin(size_t i) const
{
	return this->fData[i].crbegin();
}

template< size_t N, typename T, hydra::detail::Backend BACKEND>
typename multiarray<N,T,detail::BackendPolicy<BACKEND>>::const_vreverse_iterator
multiarray<N,T,detail::BackendPolicy<BACKEND>>::crend(size_t i) const
{
	return this->fData[i].crend();
}
}  // namespace hydra

#endif /* MULTIARRAY_INL_ */