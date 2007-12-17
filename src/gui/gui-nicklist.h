/*
 * Copyright (c) 2003-2007 by FlashCode <flashcode@flashtux.org>
 * See README for License detail, AUTHORS for developers list.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef __WEECHAT_GUI_NICKLIST_H
#define __WEECHAT_GUI_NICKLIST_H 1

struct t_gui_buffer;

struct t_gui_nick
{
    char *nick;                        /* nickname                          */
    int sort_index;                    /* index to force sort               */
    int color_nick;                    /* color for nick in nicklist        */
    char prefix;                       /* prefix for nick (for admins, ..)  */
    int color_prefix;                  /* color for prefix                  */
    struct t_gui_nick *prev_nick;      /* link to previous nick in nicklist */
    struct t_gui_nick *next_nick;      /* link to next nick in nicklist     */
};

/* nicklist functions */

extern struct t_gui_nick *gui_nicklist_search (struct t_gui_buffer *buffer,
                                               char *nick);
extern struct t_gui_nick *gui_nicklist_add (struct t_gui_buffer *buffer,
                                            char *nick,
                                            int sort_index, char *color_nick,
                                            char prefix, char *color_prefix);
extern void gui_nicklist_update (struct t_gui_buffer *buffer,
                                 struct t_gui_nick *nick,
                                 char *new_nick, int sort_index,
                                 char *color_nick, char prefix,
                                 char *color_prefix);
extern void gui_nicklist_free (struct t_gui_buffer *buffer,
                               struct t_gui_nick *nick);
extern void gui_nicklist_free_all (struct t_gui_buffer *buffer);
extern int gui_nicklist_remove (struct t_gui_buffer *buffer, char *nick);
extern int gui_nicklist_get_max_length (struct t_gui_buffer *buffer);

/* nicklist functions (GUI dependent) */

extern void gui_nicklist_draw (struct t_gui_buffer *buffer, int erase);

#endif /* gui-nicklist.h */
