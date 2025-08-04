//! robotkernel module posix timer
/*!
 * author: Robert Burger <robert.burger@dlr.de>
 */

/*
 * This file is part of module_dds.
 *
 * module_dds is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 * 
 * module_dds is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with module_dds; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef MODULE_DDS__DDS_H
#define MODULE_DDS__DDS_H

#include "robotkernel/runnable.h"
#include "robotkernel/module_base.h"
#include "robotkernel/robotkernel.h"
#include "robotkernel/trigger_base.h"

#include "service_provider_process_data_inspection/base.h"

namespace module_dds {

// forward declaration
class dds : 
    public std::enable_shared_from_this<dds>,
    public robotkernel::module_base
{
    private:
        YAML::Node config;

    private:
        dds();                               //!< prevent default cons
        dds(const dds&);             //!< prevent copy-construction
        dds& operator=(const dds&);  //!< prevent assignment

    public:
        //! default construction
        /*!
         * \param node yaml configuration node
         */
        dds(const char *name, const YAML::Node& node);

        //! destrcution
        ~dds() { };

        //! additional module init stuff
        virtual void init() override;
        //! additional module deinit stuff
        virtual void deinit() override {};

        //*********************************************
        // STATE MACHINE FUNCTIONS
        //*********************************************

        //! State transition from PREOP to SAFEOP
        virtual void set_state_safeop_2_preop() override
        { for (const auto& t : timers) { t->stop(); }; }  

        //! State transition from PREOP to SAFEOP
        virtual void set_state_preop_2_init() override
        { for (const auto& t : timers) { t->deinit(); }; }  

        //! State transition from PREOP to SAFEOP
        virtual void set_state_init_2_preop() override
        { for (const auto& t : timers) { t->init(); }; }  

        //! State transition from PREOP to SAFEOP
        virtual void set_state_preop_2_safeop() override
        { for (const auto& t : timers) { t->start(); }; }  
};

};

#endif // MODULE_DDS__DDS_H

