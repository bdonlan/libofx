/***************************************************************************
                          ofx_sgml.h
                             -------------------
    begin                : Tue Mar 19 2002
    copyright            : (C) 2002 by Benoit Gr�goire
    email                : bock@step.polymtl.ca
 ***************************************************************************/
/** @file
 * \brief OFX/SGML parsing functionnality.
*/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef OFX_SGML_H
#define OFX_SGML_H
#include "context.hh"
///Parses a DTD and OFX file(s)
int ofx_proc_sgml(LibofxContext * libofx_context, int argc, char *argv[]);

#endif
