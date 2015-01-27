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


#include "point.h"
//#include "exception.h"
#include <vector>

/**
 * Base class for quadrature formulæ in arbitrary dimensions. This class
 * stores quadrature points and weights on the unit line [0,1], unit
 * square [0,1]x[0,1], etc.
 *
 * There are a number of derived classes, denoting concrete
 * integration formulæ. Their names names prefixed by
 * <tt>Q</tt>. Refer to the list of derived classes for more details.
 *
 * The schemes for higher dimensions are typically tensor products of the
 * one-dimensional formulæ, but refer to the section on implementation
 * detail below.
 *
 * In order to allow for dimension independent programming, a
 * quadrature formula of dimension zero exists. Since an integral over
 * zero dimensions is the evaluation at a single point, any
 * constructor of such a formula initializes to a single quadrature
 * point with weight one. Access to the weight is possible, while
 * access to the quadrature point is not permitted, since a Point of
 * dimension zero contains no information. The main purpose of these
 * formulæ is their use in QProjector, which will create a useful
 * formula of dimension one out of them.
 *
 * <h3>Mathematical background</h3>
 *
 * For each quadrature formula we denote by <tt>m</tt>, the maximal
 * degree of polynomials integrated exactly. This number is given in
3 * the documentation of each formula. The order of the integration
 * error is <tt>m+1</tt>, that is, the error is the size of the cell
 * to the <tt>m+1</tt> by the Bramble-Hilbert Lemma. The number
 * <tt>m</tt> is to be found in the documentation of each concrete
 * formula. For the optimal formulæ QGauss we have $m = 2N-1$, where
 * N is the constructor parameter to QGauss. The tensor product
 * formulæ are exact on tensor product polynomials of degree
 * <tt>m</tt> in each space direction, but they are still only of
 * <tt>m+1</tt>st order.
 *
 * <h3>Implementation details</h3>
 *
 * Most integration formulæ in more than one space dimension are
 * tensor products of quadrature formulæ in one space dimension, or
 * more generally the tensor product of a formula in <tt>(dim-1)</tt>
 * dimensions and one in one dimension. There is a special constructor
 * to generate a quadrature formula from two others.  For example, the
 * QGauss@<dim@> formulæ include <i>N<sup>dim</sup></i> quadrature
 * points in <tt>dim</tt> dimensions, where N is the constructor
 * parameter of QGauss.
 *
 * @note Instantiations for this template are provided for dimensions
 * 0, 1, 2, and 3 (see the section on @ref Instantiations).
 *
 * @author Wolfgang Bangerth, Guido Kanschat, 1998, 1999, 2000, 2005, 2009
 */
template <int dim>
class Quadrature  
{
public:
  /**
   * Constructor.
   *
   * This constructor is marked as
   * explicit to avoid involuntary
   * accidents like in
   * <code>hp::QCollection@<dim@>
   * q_collection(3)</code> where
   * <code>hp::QCollection@<dim@>
   * q_collection(QGauss@<dim@>(3))</code>
   * was meant.
   */
  explicit Quadrature (const unsigned int n_quadrature_points = 0);

  /**
   * Copy constructor.
   */
  Quadrature (const Quadrature<dim> &q);

  /**
   * Construct a quadrature formula
   * from given vectors of
   * quadrature points (which
   * should really be in the unit
   * cell) and the corresponding
   * weights. You will want to have
   * the weights sum up to one, but
   * this is not checked.
   */
  Quadrature (const std::vector<Point<dim> > &points,
              const std::vector<double>      &weights);


  /**
   * Virtual destructor.
   */
  virtual ~Quadrature ();

  /**
   * Assignment operator. Copies
   * contents of #weights and
   * #quadrature_points as well as
   * size.
   */
  Quadrature &operator = (const Quadrature<dim> &);

  /**
                   *  Test for equality of two quadratures.
                   */
  bool operator == (const Quadrature<dim> &p) const;

  /**
   * Set the quadrature points and
   * weights to the values provided
   * in the arguments.
   */
  void initialize(const std::vector<Point<dim> > &points,
                  const std::vector<double>      &weights);

  /**
   * Number of quadrature points.
   */
  unsigned int size () const;

  /**
   * Return the <tt>i</tt>th quadrature
   * point.
   */
  const Point<dim> &point (const unsigned int i) const;

  /**
   * Return a reference to the
   * whole array of quadrature
   * points.
   */
  const std::vector<Point<dim> > &get_points () const;

  /**
   * Return the weight of the <tt>i</tt>th
   * quadrature point.
   */
  double weight (const unsigned int i) const;

  /**
   * Return a reference to the whole array
   * of weights.
   */
  const std::vector<double> &get_weights () const;

 
protected:
  /**
   * List of quadrature points. To
   * be filled by the constructors
   * of derived classes.
   */
  std::vector<Point<dim> > quadrature_points;

  /**
   * List of weights of the
   * quadrature points.  To be
   * filled by the constructors of
   * derived classes.
   */
  std::vector<double>      weights;
};


#ifndef DOXYGEN

// -------------------  inline and template functions ----------------


template<int dim>
inline
unsigned int
Quadrature<dim>::size () const
{
  return weights.size();
}


template <int dim>
inline
const Point<dim> &
Quadrature<dim>::point (const unsigned int i) const
{
  AssertIndexRange(i, size());
  return quadrature_points[i];
}



template <int dim>
double
Quadrature<dim>::weight (const unsigned int i) const
{
  AssertIndexRange(i, size());
  return weights[i];
}



template <int dim>
inline
const std::vector<Point<dim> > &
Quadrature<dim>::get_points () const
{
  return quadrature_points;
}



template <int dim>
inline
const std::vector<double> &
Quadrature<dim>::get_weights () const
{
  return weights;
}




#endif // DOXYGEN

