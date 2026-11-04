#ifndef LIB_STACK_STACK_H
#define LIB_STACK_STACK_H
#include <stdexcept>

template <class T>
class TStackOnMass {
	T* _data;
	size_t _size;
	int _top;

 public:
	 TStackOnMass(size_t);
	 TStackOnMass(const TStackOnMass&);
	 ~TStackOnMass();

	 inline void push(const T&);
	 inline T pop();
	 inline T& top();

	 inline bool is_empty() const noexcept;
	 inline bool is_full() const noexcept;


};
template <class T>
TStackOnMass<T>::TStackOnMass(size_t size) {
	_data = new T[size];
	_size = size;
	_top = -1;
}
template <class T>
TStackOnMass<T>::TStackOnMass(const TStackOnMass& other) {
	_data = new T[other._size];
	_size = other._size;
	_top = other._top;
	if (_top != -1) {
		for (size_t i = 0; i <= _top; ++i) _data = other._data;
	}
}
template <class T>
TStackOnMass<T>::~TStackOnMass() {
	delete[] _data;
}

template <class T>
inline bool TStackOnMass<T>::is_empty() const noexcept {
	return _top == -1;
}

template <class T>
inline bool TStackOnMass<T>::is_full() const noexcept {
	return _top == _size - 1;
}

template <class T>
inline void TStackOnMass<T>::push(const T& value) {
	if (is_full()) throw std::out_of_range("ERROR: Stack overflow");
	_data[++_top] = value;
}

template <class T>
inline T TStackOnMass<T>::pop() {
	if (is_empty()) throw std::out_of_range("ERROR: Stack empty");
	T value = _data[_top]; //берем элемент
	_top--;                //сдвигаем указатель вниз
	return value;
}

template <class T>
inline T& TStackOnMass<T>::top() {
	if(is_empty()) std::out_of_range("ERROR: Stack empty");
	return _data[_top];
}
#endif // LIB_STACK_STACK_H
