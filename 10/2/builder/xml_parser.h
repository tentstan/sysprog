/*
 * =====================================================================================
 *
 *       Filename:  xml_parser.h
 *
 *    Description:  xml_parser head file 
 *
 *        Version:  1.0
 *        Created:  04/29/2019 02:36:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef XML_PARSER_H
#define XML_PARSER_H 

#include "xml_builder.h"

struct _XmlParser;
typedef struct _XmlParser XmlParser;

XmlParser* xml_parser_create(void);
void xml_parser_set_builder(XmlParser* thiz,XmlBuilder* builder);
void xml_parser_parse(XmlParser* thiz,const char* xml);
void xml_parser_destroy(XmlParser* thiz);

#endif /* XML_PARSER_H */
