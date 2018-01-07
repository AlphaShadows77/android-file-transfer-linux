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

#ifndef AFS_FUSE_FUSEID_H
#define	AFS_FUSE_FUSEID_H

#include <fuse_lowlevel.h>

namespace mtp { namespace fuse
{

	struct FuseId
	{
		static const FuseId Root;

		fuse_ino_t Inode; //generation here?

		explicit FuseId(fuse_ino_t inode): Inode(inode) { }

		bool operator == (const FuseId &o) const
		{ return Inode == o.Inode; }
		bool operator != (const FuseId &o) const
		{ return !((*this) == o); }
		bool operator < (const FuseId &o) const
		{ return Inode < o.Inode; }
	};

	const FuseId FuseId::Root(FUSE_ROOT_ID);


}}

#endif
