/******************************************************************************\
 *           ___        __                                                    *
 *          /\_ \    __/\ \                                                   *
 *          \//\ \  /\_\ \ \____    ___   _____   _____      __               *
 *            \ \ \ \/\ \ \ '__`\  /'___\/\ '__`\/\ '__`\  /'__`\             *
 *             \_\ \_\ \ \ \ \L\ \/\ \__/\ \ \L\ \ \ \L\ \/\ \L\.\_           *
 *             /\____\\ \_\ \_,__/\ \____\\ \ ,__/\ \ ,__/\ \__/.\_\          *
 *             \/____/ \/_/\/___/  \/____/ \ \ \/  \ \ \/  \/__/\/_/          *
 *                                          \ \_\   \ \_\                     *
 *                                           \/_/    \/_/                     *
 *                                                                            *
 * Copyright (C) 2011, 2012                                                   *
 * Dominik Charousset <dominik.charousset@haw-hamburg.de>                     *
 *                                                                            *
 * This file is part of libcppa.                                              *
 * libcppa is free software: you can redistribute it and/or modify it under   *
 * the terms of the GNU Lesser General Public License as published by the     *
 * Free Software Foundation, either version 3 of the License                  *
 * or (at your option) any later version.                                     *
 *                                                                            *
 * libcppa is distributed in the hope that it will be useful,                 *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                       *
 * See the GNU Lesser General Public License for more details.                *
 *                                                                            *
 * You should have received a copy of the GNU Lesser General Public License   *
 * along with libcppa. If not, see <http://www.gnu.org/licenses/>.            *
\******************************************************************************/


#ifndef DEFAULT_ACTOR_PROXY_HPP
#define DEFAULT_ACTOR_PROXY_HPP

#include "cppa/actor_proxy.hpp"

#include "cppa/network/default_protocol.hpp"

#include "cppa/detail/abstract_actor.hpp"

namespace cppa { namespace network {

class default_actor_proxy : public detail::abstract_actor<actor_proxy> {

    typedef detail::abstract_actor<actor_proxy> super;

 public:

    default_actor_proxy(actor_id mid,
                        const process_information_ptr& pinfo,
                        const default_protocol_ptr& parent);

    void enqueue(actor* sender, any_tuple msg);

    void sync_enqueue(actor* sender, message_id_t id, any_tuple msg);

    void link_to(const intrusive_ptr<actor>& other);

    void unlink_from(const intrusive_ptr<actor>& other);

    bool remove_backlink(const intrusive_ptr<actor>& to);

    bool establish_backlink(const intrusive_ptr<actor>& to);

    void local_link_to(const intrusive_ptr<actor>& other);

    void local_unlink_from(const actor_ptr& other);

    inline const process_information_ptr& process_info() const {
        return m_pinf;
    }

 protected:

    ~default_actor_proxy();

 private:

    void forward_msg(const actor_ptr& sender,
                     any_tuple msg,
                     message_id_t mid = message_id_t());

    default_protocol_ptr    m_proto;
    process_information_ptr m_pinf;

};

} } // namespace cppa::network

#endif // DEFAULT_ACTOR_PROXY_HPP
