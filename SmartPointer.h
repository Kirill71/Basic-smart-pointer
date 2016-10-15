#ifndef SMART_POINTER_H
#define SMART_POINTER_H

template<typename T>
class SmartPointer {
public:
	SmartPointer(T* rhs);
	virtual ~SmartPointer();
	
	inline T& operator* ();
	inline const T& operator* () const;
	inline T* operator-> ();
	inline T* operator-> () const;

	// preincrement
	inline T* operator++ ();
	inline const T* operator++() const;
	//postincrement
	inline T* operator++(int);
	inline const T* operator++(int) const;

	//predecrement
	inline T* operator-- ();
	inline const T* operator-- () const;
	//postdecrement
	inline T* operator-- (int);
	inline const T* operator-- (int) const;

	// pointer indexing
	T& operator[] (int);
	const T& operator[] (int) const;

	// ostream/istream operators
	template<typename T1> 
	friend std::ostream& operator<< (std::ostream& os, const SmartPointer<T1>& rhs);

	SmartPointer(const SmartPointer<T>& rhs) = delete;
	SmartPointer<T>& operator= (const SmartPointer<T>& rhs) = delete;
protected:
	T* mPtr;
};

// Implementation 
template<typename T>
 SmartPointer<T>::SmartPointer(T * rhs): mPtr(rhs){}

template<typename T>
 SmartPointer<T>::~SmartPointer()
{
	 delete mPtr;
}

 template<typename T>
 inline T & SmartPointer<T>::operator*()
 {
	 return (*mPtr);
 }

 template<typename T>
 inline const T & SmartPointer<T>::operator*() const
 {
	 return (*mPtr);
 }

 template<typename T>
 inline T * SmartPointer<T>::operator->()
 {
	 return (mPtr);
 }

 template<typename T>
 inline T* SmartPointer<T>::operator->() const
 {
	 return (mPtr);
 }

 template<typename T>
 inline T* SmartPointer<T>::operator++()
 {
	 return (++mPtr);
 }

 template<typename T>
 inline const T* SmartPointer<T>::operator++() const
 {
	 return (++mPtr);
 }

 template<typename T>
 inline T* SmartPointer<T>::operator++(int)
 {
	 return (mPtr++);
 }

 template<typename T>
 inline const T* SmartPointer<T>::operator++(int) const
 {
	 return (mPtr++);
 }

 template<typename T>
 inline T* SmartPointer<T>::operator--()
 {
	 return (--mPtr);
 }

 template<typename T>
 inline const T*  SmartPointer<T>::operator--() const
 {
	 return (--mPtr);
 }

 template<typename T>
 inline T* SmartPointer<T>::operator--(int)
 {
	 return (mPtr--);
 }

 template<typename T>
 inline const T* SmartPointer<T>::operator--(int) const
 {
	 return (mPtr--);
 }

 template<typename T>
 T& SmartPointer<T>::operator[](int i)
 {
	 return const_cast<T&>(
		 static_cast<const SmartPointer<T>& >(*this)[i]);
 }

 template<typename T>
const T & SmartPointer<T>::operator[](int i) const
 {
	 if (i < 0) throw std::out_of_range("out of range exception");
	 return (mPtr[i]);
 }

 template<typename T>
 std::ostream & operator<<(std::ostream & os, const SmartPointer<T>& rhs)
 {
	 os << rhs[0];
	 return os;
 }

 
#endif // !SMART_POINTER_H