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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "ChannelModel3_ff_impl.h"
#include <stdexcept> //
#include <math.h> //

namespace gr {
  namespace ChannelModel3 {

    ChannelModel3_ff::sptr
    ChannelModel3_ff::make(float tx, float ty, float tz, float rx, float ry, float rz, float m, float A, float ts, float ga, float ampl)//
    {
      return gnuradio::get_initial_sptr
        (new ChannelModel3_ff_impl(tx, ty, tz, rx, ry, rz, m, A, ts, ga,ampl));//
    }

    /*
     * The private constructor
     */
    ChannelModel3_ff_impl::ChannelModel3_ff_impl(float tx, float ty, float tz, float rx, float ry, float rz, float m, float A, float ts, float ga, float ampl) //
      : gr::block("ChannelModel3_ff",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)))
    {		//
	d_tx(tx);
	d_ty(ty);
	d_tz(tz);
	d_rx(rx);
	d_ry(ry);
	d_rz(rz);
	d_m(m);
	d_A(A);
	d_ts(ts);
	d_ga(ga);
	d_ampl(ampl);
	}

    /*
     * Our virtual destructor.
     */
    ChannelModel3_ff_impl::~ChannelModel3_ff_impl()
    {
    }

    

    int
    ChannelModel3_ff_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];
	
	float d;
	float alpha;
	float gt;
	float gr1;
	float prx;
	
	d = sqrt(pow((rx()-tx()),2)+pow((ry()-ty()),2)+pow((rz()-tz()),2));
	alpha = acos((tz()-rz())/d);

	gt = ((m()+1)/(2*M_PI))* pow(cos(alpha),m());
	gr1 = A()*ts()*ga()*cos(alpha);
	
	prx = (gt*gr1)/pow(d,2);

	for(int i = 0; i < noutput_items; i++) {
	  out[i] = ((float)(ampl() * d_rng.gasdev())) + in[i]*prx; //
	}


      // Do <+signal processing+>
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace ChannelModel3 */
} /* namespace gr */

