#
#   Makefile.am
#
#   $Id$
#

# forward compatibility
datarootdir = @datarootdir@

# main
bin_PROGRAMS = novadbd
DEFS = -Wall $(FLARE_CXXFLAGS)
LDADD = ../lib/libflare.la

# src
novadbd_CPPFLAGS = -I../lib
novadbd_SOURCES = \
	novadbd.h novadbd.cc \
	ini_option.h ini_option.cc \
	handler_alarm.h handler_alarm.cc \
	handler_mysql_replication.h handler_mysql_replication.cc \
	handler_request.h handler_request.cc \
	op_parser_binary_node.h op_parser_binary_node.cc \
	op_parser_text_node.h op_parser_text_node.cc \
	op_stats_node.h op_stats_node.cc \
	op_show_node.h op_show_node.cc \
	stats_node.h stats_node.cc \
	status_node.h status_node.cc \
	show_node.h show_node.cc
