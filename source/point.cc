
#include "include/point.h"


template<int dim, typename Number>
Point<dim, Number>::Point()
{
	for(int i=0; i<dim; i++){
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
