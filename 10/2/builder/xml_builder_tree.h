/*
 * =====================================================================================
 *
 *       Filename:  xml_builder_tree.h
 *
 *    Description:  xml_builder_tree head file 
 *
 *        Version:  1.0
 *        Created:  04/29/2019 11:17:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef XML_BUILDER_TREE_H
#define XML_BUILDER_TREE_H 

#include "xml_builder.h"
#include "xml_tree.h"

DECLS_BEGIN

XmlBuilder* xml_builder_tree_create(void);
XmlNode* xml_builder_get_tree(XmlBuilder* thiz);

DECLS_END

#endif /* XML_BUILDER_TREE_H */
