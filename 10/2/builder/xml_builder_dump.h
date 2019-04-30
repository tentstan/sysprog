/*
 * =====================================================================================
 *
 *       Filename:  xml_builder_dump.h
 *
 *    Description:  xml_builder_dump head file 
 *
 *        Version:  1.0
 *        Created:  04/29/2019 10:30:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef XML_BUILDER_DUMP_H
#define XML_BUILDER_DUMP_H 

#include "xml_builder.h"

DECLS_BEGIN

XmlBuilder* xml_builder_dump_create(FILE* fp);

DECLS_END

#endif /* XML_BUILDER_DUMP_H */
