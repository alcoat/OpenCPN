/***************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  Implement comm_appmsg_bus.h -- Decoded messages bus.
 * Author:   David Register, Alec Leamas
 *
 ***************************************************************************
 *   Copyright (C) 2022 by David Register, Alec Leamas                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 **************************************************************************/

// For compilers that support precompilation, includes "wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif  // precompiled headers

#include "model/comm_appmsg_bus.h"
#include "model/comm_navmsg_bus.h"

void AppMsgBus::Notify(const std::shared_ptr<const AppMsg>& msg) {
  std::string key = "Internal::" + msg->GetKey();
  NavMsgBus::GetInstance().RegisterKey(key);
  Observable(*msg).Notify(msg);
}

AppMsgBus& AppMsgBus::GetInstance() {
  static AppMsgBus instance;
  return instance;
}
