#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace	ft
{

template<typename T>
class	random_access_iterator
	: public ft::iterator< random_access_iterator_tag, T >
{
public:

	typedef	typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
	typedef	typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
	typedef	typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
	typedef	typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
	typedef	typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;

	random_access_iterator() : _ptr(my_nullptr) {}
	random_access_iterator(const random_access_iterator& ref) : _ptr(ref._ptr) {}
	random_access_iterator(pointer ptr) : _ptr(ptr) {}
	virtual ~random_access_iterator() {}

	random_access_iterator&	operator=(const random_access_iterator& ref)
	{
		if (this != &ref)
			this->_ptr = ref._ptr;
		return (*this);
	}

	pointer						base() const { return (this->_ptr); }

	random_access_iterator&		operator+=(difference_type	n) { _ptr += n; return (*this); }
	random_access_iterator		operator+(difference_type	n) { random_access_iterator itr = (*this); return (itr += n); }
	random_access_iterator&		operator-=(difference_type	n) { _ptr -= n; return (*this); }
	random_access_iterator		operator-(difference_type	n) { random_access_iterator itr = (*this); return (itr -= n); }
	reference					operator[](difference_type	n) { return (_ptr[n]); }

	template<typename U>
	random_access_iterator&		operator=(random_access_iterator<U>	other) { this->_ptr = other.base(); return (*this); }
	random_access_iterator&		operator--()		{ --_ptr; return (*this); }
	random_access_iterator		operator--(int)		{ random_access_iterator	itr = (*this); --_ptr; return (itr); }
	random_access_iterator&		operator++()		{ ++_ptr; return (*this); }
	random_access_iterator		operator++(int)		{ random_access_iterator	itr = (*this); ++_ptr; return (itr); }
	reference					operator*()	const	{ return (*_ptr); }
	pointer						operator->()		{ return (_ptr); }

	operator random_access_iterator<const T> () const { return (random_access_iterator<const T>(this->_ptr)); }

private:
	pointer	_ptr;

};
template<typename T>
	random_access_iterator<T>
		operator +	(typename random_access_iterator<T>::diffence_type n, const random_access_iterator<T>& iterator)
		{ random_access_iterator<T> itr = iterator; return (itr + n); }

template<typename iter>
	typename ft::random_access_iterator<iter>::difference_type
		operator -	(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (lhs.base() - rhs.base()); }

template<typename iter>
	bool	operator ==	(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (lhs.base() == rhs.base()); }
template<typename iter>
	bool	operator !=	(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (lhs.base() != rhs.base()); }
template<typename iter>
	bool	operator <	(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (lhs.base() < rhs.base()); }
template<typename iter>
	bool	operator >	(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (rhs < lhs); }
template<typename iter>
	bool	operator <=	(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return !(rhs < lhs); }
template<typename iter>
	bool	operator >=	(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return !(lhs < rhs); }

template<typename iter1, typename iter2>
	bool	operator ==	(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (lhs.base() == rhs.base()); }
template<typename iter1, typename iter2>
	bool	operator !=	(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (lhs.base() != rhs.base()); }
template<typename iter1, typename iter2>
	bool	operator <	(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (lhs.base() < rhs.base()); }
template<typename iter1, typename iter2>
	bool	operator >	(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (rhs < lhs); }
template<typename iter1, typename iter2>
	bool	operator <=	(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return !(rhs < lhs); }
template<typename iter1, typename iter2>
	bool	operator >=	(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return !(lhs < rhs); }

}

#endif
