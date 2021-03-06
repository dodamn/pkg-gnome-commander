/*
    GNOME Commander - A GNOME based file manager
    Copyright (C) 2001-2006 Marcus Bjurman
    Copyright (C) 2007-2009 Piotr Eljasiak

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
*/
#ifndef __GNOME_CMD_PATH_H__
#define __GNOME_CMD_PATH_H__

#define GNOME_CMD_PATH(obj) \
    GTK_CHECK_CAST (obj, gnome_cmd_path_get_type (), GnomeCmdPath)
#define GNOME_CMD_PATH_CLASS(klass) \
    GTK_CHECK_CLASS_CAST (klass, gnome_cmd_path_get_type (), GnomeCmdPathClass)
#define GNOME_CMD_IS_PATH(obj) \
    GTK_CHECK_TYPE (obj, gnome_cmd_path_get_type ())
#define GNOME_CMD_PATH_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), GNOME_CMD_PATH, GnomeCmdPathClass))


struct GnomeCmdPath
{
    GtkObject parent;
};

struct GnomeCmdPathClass
{
    GtkObjectClass parent_class;

    // virtual functions
    const gchar *(* get_path)          (GnomeCmdPath *path);
    const gchar *(* get_display_path)  (GnomeCmdPath *path);
    GnomeCmdPath *(* get_parent)       (GnomeCmdPath *path);
    GnomeCmdPath *(* get_child)        (GnomeCmdPath *path, const gchar *child);
};


GtkType gnome_cmd_path_get_type ();

const gchar *gnome_cmd_path_get_path (GnomeCmdPath *path);

const gchar *gnome_cmd_path_get_display_path (GnomeCmdPath *path);

GnomeCmdPath *gnome_cmd_path_get_parent (GnomeCmdPath *path);

GnomeCmdPath *gnome_cmd_path_get_child (GnomeCmdPath *path, const gchar *child);

#endif // __GNOME_CMD_PATH_H__
