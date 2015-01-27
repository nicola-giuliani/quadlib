// ---------------------------------------------------------------------
//
// Copyright (C) 1998 - 2013 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE at
// the top level of the deal.II distribution.
//
// ---------------------------------------------------------------------

#ifndef __point_h
#define __point_h

#include "exceptions.h"
#include <cmath>
#include <ostream>


/**
 * The <tt>Point</tt> class provides for a point or vector in a space with
 * arbitrary dimension <tt>dim</tt>.
 *
 * It is the preferred object to be passed to functions which operate on
 * points in spaces of a priori unknown dimension: rather than using functions
 * like <tt>double f(double x)</tt> and <tt>double f(double x, double y)</tt>,
 * you use <tt>double f(Point<dim> &p)</tt>.
 *
 * <tt>Point</tt> also serves as a starting point for the implementation of
 * the geometrical primitives like cells, edges, or faces.
 *
 * Within deal.II, we use the <tt>Point</tt> class mainly to denote the points
 * that make up geometric objects. As such, they have a small number of
 * additional operations over general tensors of rank 1 for which we use the
 * <tt>Tensor<1,dim></tt> class. In particular, there is a distance() function
 * to compute the Euclidian distance between two points in space.
 *
 * The <tt>Point</tt> class is really only used where the coordinates of an
 * object can be thought to possess the dimension of a length. For all other
 * uses, such as the gradient of a scalar function (which is a tensor of rank
 * 1, or vector, with as many elements as a point object, but with different
 * physical units), we use the <tt>Tensor<1,dim></tt> class.
 *
 * @ingroup geomprimitives
 * @author Wolfgang Bangerth, 1997
 */
template <int dim, typename Number=double>
class Point
{
public:
  /**
   * Standard constructor. Creates
   * an object that corresponds to the origin, i.e., all coordinates
   * are set to zero.
   */
  Point ();


  /**
   *  Constructor for one dimensional
   *  points. This function is only
   *  implemented for <tt>dim==1</tt> since
   *  the usage is considered unsafe for
   *  points with <tt>dim!=1</tt> as it would leave some components
   *  of the point coordinates uninitialized.
   */
  Point (const Number x);

  /**
   *  Constructor for two dimensional
   *  points. This function is only
   *  implemented for <tt>dim==2</tt> since
   *  the usage is considered unsafe for
   *  points with <tt>dim!=2</tt> as it would leave some components
   *  of the point coordinates uninitialized (if dim>2) or would
   *  not use some arguments (if dim<2).
   */
  Point (const Number x,
         const Number y);

  /**
   *  Constructor for three dimensional
   *  points. This function is only
   *  implemented for <tt>dim==3</tt> since
   *  the usage is considered unsafe for
   *  points with <tt>dim!=3</tt> as it would leave some components
   *  of the point coordinates uninitialized (if dim>3) or would
   *  not use some arguments (if dim<3).
   */
  Point (const Number x,
         const Number y,
         const Number z);

  /**
   * Return a unit vector in
   * coordinate direction <tt>i</tt>.
   */
  Point<dim,Number> unit_vector(const unsigned int i);

  /**
   *  Read access to the <tt>index</tt>th
   *  coordinate.
   */
  Number   operator () (const unsigned int index) const;

  /**
   *  Read and write access to the
   *  <tt>index</tt>th coordinate.
   */
  Number &operator () (const unsigned int index);


  /**
   * The opposite vector.
   */
  Point<dim,Number>   operator - () const;


  /**
   * Returns the Euclidian distance of
   * <tt>this</tt> point to the point
   * <tt>p</tt>, i.e. the <tt>l_2</tt> norm
   * of the difference between the vectors
   * representing the two points.
   */
  Number distance (const Point<dim,Number> &p) const;

private:

  Number values[dim];

};

/*------------------------------- Inline functions: Point ---------------------------*/

#ifndef DOXYGEN

template <int dim, typename Number>
inline
Point<dim,Number>::Point ()
{}




template <int dim, typename Number>
inline
Point<dim,Number>::Point (const Number x)
{
  switch (dim)
    {
    case 1:
      this->values[0] = x;
    default:
      Assert (dim==1, StandardExceptions::ExcInvalidConstructorCall());
    }
}



template <int dim, typename Number>
inline
Point<dim,Number>::Point (const Number x, const Number y)
{
  switch (dim)
    {
    case 2:
      this->values[0] = x;
      this->values[1] = y;
    default:
      Assert (dim==2, StandardExceptions::ExcInvalidConstructorCall());
    }
}



template <int dim, typename Number>
inline
Point<dim,Number>::Point (const Number x, const Number y, const Number z)
{
  switch (dim)
    {
    case 3:
      this->values[0] = x;
      this->values[1] = y;
      this->values[2] = z;
    default:
      Assert (dim==3, StandardExceptions::ExcInvalidConstructorCall());
    }
}


template <int dim, typename Number>
inline
Point<dim,Number>
Point<dim,Number>::unit_vector(unsigned int i)
{
  Point<dim,Number> p;
  p(i) = 1.;
  return p;
}


template <int dim, typename Number>
inline
Number
Point<dim,Number>::operator () (const unsigned int index) const
{
  AssertIndexRange((int) index, dim);
  return this->values[index];
}



template <int dim, typename Number>
inline
Number &
Point<dim,Number>::operator () (const unsigned int index)
{
  AssertIndexRange((int) index, dim);
  return this->values[index];
}



template <int dim, typename Number>
inline
Point<dim,Number>
Point<dim,Number>::operator - () const
{
  Point<dim,Number> result;
  for (unsigned int i=0; i<dim; ++i)
    result.values[i] = -this->values[i];
  return result;
}



template <int dim, typename Number>
inline
Number
Point<dim,Number>::distance (const Point<dim,Number> &p) const
{
  Number sum=0;
  for (unsigned int i=0; i<dim; ++i)
    {
      const double diff=this->values[i]-p(i);
      sum += diff*diff;
    }

  return std::sqrt(sum);
}



#endif // DOXYGEN


#endif
