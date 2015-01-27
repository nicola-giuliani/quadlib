
#include "include/point.h"
#include <math.h>


template<int dim, typename Number>
Point<dim, Number>::Point()
{
	for(unsigned int i=0; i<dim; i++){
		this->coords[i]=(Number)0;
	}
}

template<int dim, typename Number>
explicit Point<dim, Number>::Point(const Number x)
{
	assert(("The fuckin' dimension is 1!", dim == 1));
	this->coords[0]=x;
}

template<int dim, typename Number>
Point<dim, Number>::Point(	const Number x,
							const Number y)
{
	assert(("The fuckin' dimension is 2!", dim == 2));
	this->coords[0]=x;
	this->coords[1]=y;
}

template<int dim, typename Number>
Point<dim, Number>::Point(	const Number x,
							const Number y,
							const Number z)
{
	assert(("The fuckin' dimension is 3!", dim == 3));
	this->coords[0]=x;
	this->coords[1]=y;
	this->coords[2]=z;
}

template<int dim, typename Number>
static Point<dim,Number>::unit_vector(const unsigned int i)
{
	AssertIndexRange((int) i, dim);
	for(unsigned int j=0; j<dim; j++){
		this->coords[j]=(Number)0;
	}
	this->coords[i]=(Number)1;
}

template<int dim, typename Number>
Number Point<dim,Number>::operator() (const unsigned int index) const
{
	return this->coords[i];
}

template<int dim, typename Number>
Number Point<dim,Number>::&operator() (const unsigned int index)
{
	return this->coords[i];
}

template<int dim, typename Number>
Point<dim,Number>::operator- () const
{
	for(unsigned int j=0; j<dim; j++){
		this->coords[j]=-this->coords[j];
	}
}

// template<int dim, typename Number>
// Point<dim,Number>::operator* (const Number) const
// {
// 	for(unsigned int j=0; j<dim; j++){
// 		this->coords[j]=-this->coords[j];
// 	}
// }

template<int dim, typename Number>
Number Point<dim,Number>::distance (const Point<dim, Number> &p) const
{
	Number sum = (Number) 0;
	for(unsigned int j=0; j<dim; j++){
		sum += (this->coords[j] - p.coords[j])*(this->coords[j] - p.coords[j]) ;
	}
	return sqrt(sum)
}


