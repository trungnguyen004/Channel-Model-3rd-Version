/* -*- c++ -*- */
/* 
 * Copyright 2019 Jason Nguyen.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_CHANNELMODEL3_CHANNELMODEL3_FF_H
#define INCLUDED_CHANNELMODEL3_CHANNELMODEL3_FF_H

#include <ChannelModel3/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace ChannelModel3 {

    /*!
     * \brief <+description of block+>
     * \ingroup ChannelModel3
     *
     */
    class CHANNELMODEL3_API ChannelModel3_ff : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<ChannelModel3_ff> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of ChannelModel3::ChannelModel3_ff.
       *
       * To avoid accidental use of raw pointers, ChannelModel3::ChannelModel3_ff's
       * constructor is in a private implementation
       * class. ChannelModel3::ChannelModel3_ff::make is the public interface for
       * creating new instances.
       */
      static sptr make(float tx, float ty, float tz, float rx, float ry, float rz, float m, float A, float ts, float ga, float ampl); //
	virtual void d_tx(float tx) =0;
	virtual float tx() =0;
	virtual void d_ty(float ty) =0;
	virtual float ty() =0;
	virtual void d_tz(float tz) =0;
	virtual float tz() =0;
	virtual void d_rx(float rx) =0;
	virtual float rx() =0;
	virtual void d_ry(float ry) =0;
	virtual float ry() =0;
	virtual void d_rz(float rz) =0;
	virtual float rz() =0;
	virtual void d_m(float m) =0;
	virtual float m() =0;
	virtual void d_A(float A) =0;
	virtual float A() =0;
	virtual void d_ts(float ts) =0;
	virtual float ts() =0;
	virtual void d_ga(float ga) =0;
	virtual float ga() =0;
	virtual void d_ampl(float ampl) =0;
	virtual float ampl() =0;
	
    };

  } // namespace ChannelModel3
} // namespace gr

#endif /* INCLUDED_CHANNELMODEL3_CHANNELMODEL3_FF_H */

