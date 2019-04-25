/*
 * =====================================================================================
 *
 *       Filename:  xml_parser.h
 *
 *    Description:  xml_parser head file 
 *
 *        Version:  1.0
 *        Created:  04/25/2019 12:27:22 PM
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

struct _XmlParser;
typedef _XmlParser XmlParser;

XmlParser* xml_parser_create(void);
void xml_parser_parse(XmlParser* thiz,const char* xml);
void xml_parser_destroy(XmlParser* thiz);

#endif /* XML_PARSER_H */
