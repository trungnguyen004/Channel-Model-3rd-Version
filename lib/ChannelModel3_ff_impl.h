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

#ifndef INCLUDED_CHANNELMODEL3_CHANNELMODEL3_FF_IMPL_H
#define INCLUDED_CHANNELMODEL3_CHANNELMODEL3_FF_IMPL_H

#include <ChannelModel3/ChannelModel3_ff.h>
#include <gnuradio/random.h> //

namespace gr {
  namespace ChannelModel3 {

    class ChannelModel3_ff_impl : public ChannelModel3_ff
    {
     private:
	float my_tx;
	float my_ty;
	float my_tz;
	float my_rx;
	float my_ry;
	float my_rz;
	float my_m;
	float my_A;
	float my_ts;
	float my_ga;
	float my_ampl;
	gr::random d_rng;

     public:
      ChannelModel3_ff_impl(float tx, float ty, float tz, float rx, float ry, float rz, float m, float A, float ts, float ga, float ampl);
      ~ChannelModel3_ff_impl();

	void d_tx(float tx) {my_tx = tx;}
	float tx() {return my_tx;}
	void d_ty(float ty) {my_ty = ty;}
	float ty() {return my_ty;}
	void d_tz(float tz) {my_tz = tz;}
	float tz() {return my_tz;}
	void d_rx(float rx) {my_rx = rx;}
	float rx() {return my_rx;}
	void d_ry(float ry) {my_ry = ry;}
	float ry() {return my_ry;}
	void d_rz(float rz) {my_rz = rz;}
	float rz() {return my_rz;}
	void d_m(float m) {my_m = m;}
	float m() {return my_m;}
	void d_A(float A) {my_A = A;}
	float A() {return my_A;}
	void d_ts(float ts) {my_ts = ts;}
	float ts() {return my_ts;}
	void d_ga(float ga) {my_ga = ga;}
	float ga() {return my_ga;}
	void d_ampl(float ampl) {my_ampl = ampl;}
	float ampl() {return my_ampl;}
	

     

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace ChannelModel3
} // namespace gr

#endif /* INCLUDED_CHANNELMODEL3_CHANNELMODEL3_FF_IMPL_H */

