/*
 * Flare
 * --------------
 * Copyright (C) 2008-2014 GREE, Inc.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
/**
 *	novadbi.h
 *
 *	@author	Masaki Fujimoto <fujimoto@php.net>
 *
 *	$Id$
 */
#ifndef	novadbi_H
#define	novadbi_H

#include "app.h"
#include "handler_alarm.h"
#include "handler_request.h"
#include "handler_controller.h"
#include "ini_option.h"
#include "stats_index.h"
#include "coordinator_factory.h"
#include "status_index.h"

namespace gree {
namespace flare {

/**
 *	novadbi application class
 */
class novadbi : public app {
private:
	server*								_server;
	AtomicCounter*					_thread_index;
	thread_pool*					_req_thread_pool;
	thread_pool*					_other_thread_pool;
	cluster*							_cluster;
	coordinator*					_coordinator;
	coordinator_factory		_coordinator_factory;

public:
	novadbi();
	~novadbi();

	int startup(int argc, char** argv);
	int run();
	int reload();
	int shutdown();

	thread_pool* get_req_thread_pool() { return this->_req_thread_pool; };
	thread_pool* get_other_thread_pool() { return this->_other_thread_pool; };
	cluster* get_cluster() { return this->_cluster; };

protected:
	string _get_pid_path();

private:
	int _set_resource_limit();
	int _set_signal_handler();
};

}	// namespace flare
}	// namespace gree

#endif	// novadbi_H
// vim: foldmethod=marker tabstop=2 shiftwidth=2 autoindent
