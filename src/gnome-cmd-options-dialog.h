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
#ifndef __GNOME_CMD_OPTIONS_DIALOG_H__
#define __GNOME_CMD_OPTIONS_DIALOG_H__

#define GNOME_CMD_OPTIONS_DIALOG(obj)           GTK_CHECK_CAST (obj, gnome_cmd_options_dialog_get_type (), GnomeCmdOptionsDialog)
#define GNOME_CMD_OPTIONS_DIALOG_CLASS(klass)   GTK_CHECK_CLASS_CAST (klass, gnome_cmd_options_dialog_get_type (), GnomeCmdOptionsDialogClass)
#define GNOME_CMD_IS_OPTIONS_DIALOG(obj)        GTK_CHECK_TYPE (obj, gnome_cmd_options_dialog_get_type ())


struct GnomeCmdOptionsDialogClass
{
    GnomeCmdDialogClass parent_class;
};


struct GnomeCmdOptionsDialog
{
    GnomeCmdDialog parent;

    struct Private;

    Private *priv;

    enum Tab
    {
        TAB_GENERAL,
        TAB_FORMAT,
        TAB_LAYOUT,
        TAB_CONFIRMATION,
        TAB_FILTERS,
        TAB_NETWORK,
        TAB_PROGRAMS,
        TAB_DEVICES
    } ;

    GtkWidget *notebook;

    void set_tab (Tab tab)      {  gtk_notebook_set_page (GTK_NOTEBOOK (notebook), tab);  }
};


GtkType gnome_cmd_options_dialog_get_type ();
GtkWidget *gnome_cmd_options_dialog_new ();

#endif // __GNOME_CMD_OPTIONS_DIALOG_H__
