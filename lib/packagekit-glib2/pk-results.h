/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2009 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#if !defined (__PACKAGEKIT_H_INSIDE__) && !defined (PK_COMPILATION)
#error "Only <packagekit.h> can be included directly."
#endif

/**
 * SECTION:pk-results
 * @short_description: An abstract results GObject
 */

#ifndef __PK_RESULTS_H
#define __PK_RESULTS_H

#include <glib-object.h>
#include <packagekit-glib2/pk-enum.h>

G_BEGIN_DECLS

#define PK_TYPE_RESULTS		(pk_results_get_type ())
#define PK_RESULTS(o)		(G_TYPE_CHECK_INSTANCE_CAST ((o), PK_TYPE_RESULTS, PkResults))
#define PK_RESULTS_CLASS(k)	(G_TYPE_CHECK_CLASS_CAST((k), PK_TYPE_RESULTS, PkResultsClass))
#define PK_IS_RESULTS(o)	(G_TYPE_CHECK_INSTANCE_TYPE ((o), PK_TYPE_RESULTS))
#define PK_IS_RESULTS_CLASS(k)	(G_TYPE_CHECK_CLASS_TYPE ((k), PK_TYPE_RESULTS))
#define PK_RESULTS_GET_CLASS(o)	(G_TYPE_INSTANCE_GET_CLASS ((o), PK_TYPE_RESULTS, PkResultsClass))
#define PK_RESULTS_ERROR	(pk_results_error_quark ())
#define PK_RESULTS_TYPE_ERROR	(pk_results_error_get_type ())

typedef struct _PkResultsPrivate	PkResultsPrivate;
typedef struct _PkResults		PkResults;
typedef struct _PkResultsClass		PkResultsClass;

struct _PkResults
{
	 GObject		 parent;
	 PkResultsPrivate	*priv;
};

struct _PkResultsClass
{
	GObjectClass	parent_class;
	/* padding for future expansion */
	void (*_pk_reserved1) (void);
	void (*_pk_reserved2) (void);
	void (*_pk_reserved3) (void);
	void (*_pk_reserved4) (void);
	void (*_pk_reserved5) (void);
};

GQuark		 pk_results_error_quark			(void);
GType		 pk_results_get_type		  	(void);
PkResults	*pk_results_new				(void);

/* set */
gboolean	 pk_results_set_exit_code		(PkResults	*results,
							 PkExitEnum	 exit_enum);

/* add */
gboolean	 pk_results_add_package			(PkResults	*results,
							 PkInfoEnum	 info_enum,
							 const gchar	*package_id,
							 const gchar	*summary);

/* get single data */
PkExitEnum	 pk_results_get_exit_code		(PkResults	*results);

/* get array data */
typedef struct {
	PkInfoEnum	 info_enum;
	gchar		*package_id;
	gchar		*summary;	
} PkResultItemPackage;
GPtrArray	*pk_results_get_package_array		(PkResults	*results);

G_END_DECLS

#endif /* __PK_RESULTS_H */

