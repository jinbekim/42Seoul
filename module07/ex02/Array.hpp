#ifndef Array_HPP
# define Array_HPP

# include <string>
# include <iostream>

template<typename T>
class Array
{
	private:
		T*	array;
		unsigned int	_size;
		class AccessRangeOverException: public std::exception
		{
			public:
				const char* what() const throw(){ return "this element is out of the limits"; }
		};
	public:
		Array():array(nullptr), _size(0)
		{

		}
		Array(unsigned int n) :array(nullptr), _size(n)
		{
			array = new T[n]();
		}
		Array(const Array<T> &ref):array(nullptr), _size(0)
		{
			*this = ref;
		}
		Array&	operator=(const Array<T>& ref)
		{
			if (_size != 0)
				delete[] array;
			if (ref._size != 0)
			{
				array = new T[ref._size];
				for (unsigned int i = 0; i < ref._size; ++i)
					array[i] = ref.array[i];
			}
			_size = ref._size;
			return (*this);
		}
		const T&	operator[](int idx) const
		{
			if (idx >= (int)_size || idx < 0)
				throw AccessRangeOverException();
			return (array[idx]);
		}
		T&	operator[](int idx)
		{
			if (idx >= (int)_size || idx < 0)
				throw AccessRangeOverException();
			return (array[idx]);
		}
		~Array()
		{
			delete[] array;
		}

		unsigned int	size(void) const
		{
			return (this->_size);
		}
};

#endif

// Write a class template Array that contains elements of type T and that allows the
// following behavior:
// • Construction with no parameter: creates an empty array.
// • Construction with an unsigned int n as a parameter:
//creates an array of n elements, initialized by default. (Tip: try to compile int * a = new int();, then
// display *a.)
// • Construction by copy and assignment operator. In both cases, modifying one of
// the two arrays after copy/assignment won’t affect anything in the other array.

// • You MUST use the operator new[] for your allocation. You must not do preventive
// allocation. Your code must never access non allocated memory.
// • Elements are accessible through the operator[].
// • When accessing an element with the operator[], if this element is out of the limits,
// a std::exception is thrown.
// • A member function _size that returns the number of elements in the array. This
// member function takes no parameter and does not modify the current instance in
// any way
