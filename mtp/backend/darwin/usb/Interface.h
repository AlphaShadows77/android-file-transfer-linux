/*
    This file is part of Android File Transfer For Linux.
    Copyright (C) 2015-2018  Vladimir Menshakov

    Android File Transfer For Linux is free software: you can redistribute
    it and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    Android File Transfer For Linux is distributed in the hope that it will
    be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Android File Transfer For Linux.
    If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INTERFACE_H
#define	INTERFACE_H

#include <mtp/types.h>
#include <usb/Device.h>

namespace mtp { namespace usb
{
	class Endpoint
	{
	private:
		IOUSBInterfaceInterface	**	_interface;
		int							_refIndex;
		int							_address;
		int							_maxPacketSize;
		EndpointDirection			_direction;
		EndpointType				_type;

	public:
		Endpoint(IOUSBInterfaceInterface **interface, int idx);

		IOUSBInterfaceInterface	** GetInterfaceHandle()
		{ return _interface; }

		int GetRefIndex()
		{ return _refIndex; }

		u8 GetAddress() const
		{ return _address; }

		int GetMaxPacketSize() const
		{ return _maxPacketSize; }

		EndpointDirection GetDirection() const
		{ return _direction; }

		EndpointType GetType() const
		{ return _type; }
	};
	DECLARE_PTR(Endpoint);

	class Configuration;
	DECLARE_PTR(Configuration);
	class Device;
	DECLARE_PTR(Device);

	class InterfaceToken : public IToken
	{
		IOUSBInterfaceInterface **_interface;

	public:
		InterfaceToken(IOUSBInterfaceInterface **interface);
		~InterfaceToken();
	};
	DECLARE_PTR(InterfaceToken);

	class Interface
	{
		DevicePtr							_device;
		ConfigurationPtr					_config;
		IOUSBInterfaceInterface **			_interface;

	public:
		Interface(DevicePtr device, ConfigurationPtr config, IOUSBInterfaceInterface **interface);
		~Interface();

		IOUSBInterfaceInterface ** GetInterfaceHandle()
		{ return _interface; }

		u8 GetClass() const;
		u8 GetSubclass() const;
		int GetIndex() const;
		int GetEndpointsCount() const;

		InterfaceTokenPtr Claim();

		EndpointPtr GetEndpoint(int idx) const
		{ return std::make_shared<Endpoint>(_interface, idx + 1); }

	};
	DECLARE_PTR(Interface);

}}

#endif
