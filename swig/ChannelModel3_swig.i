/* -*- c++ -*- */

#define CHANNELMODEL3_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "ChannelModel3_swig_doc.i"

%{
#include "ChannelModel3/ChannelModel3_ff.h"
%}


%include "ChannelModel3/ChannelModel3_ff.h"
GR_SWIG_BLOCK_MAGIC2(ChannelModel3, ChannelModel3_ff);
