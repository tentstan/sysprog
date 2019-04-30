/*
 * =====================================================================================
 *
 *       Filename:  xml_builder_tree.c
 *
 *    Description:  xml_builder_tree c source file 
 *
 *        Version:  1.0
 *        Created:  04/29/2019 11:22:35 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "xml_builder_tree.h"

typedef struct _PrivInfo 
{
    XmlNode* root;
    XmlNode* current;
}PrivInfo;

static void xml_builder_tree_on_start_element(XmlBuilder* thiz,const char* tag,const char** attrs)
{
    XmlNode* new_node = NULL;
    PrivInfo* priv = (PrivInfo*)thiz->priv;

    new_node = xml_node_create_normal(tag,attrs);
    xml_node_append_child(priv->current,new_node);
    priv->current = new_node;

    return;
}

static void xml_builder_tree_on_end_element(XmlBuilder* thiz,const char* tag)
{
    PrivInfo* priv = (PrivInfo*)thiz->priv;
    priv->current = priv->current->parent;
    assert(priv->current != NULL);

    return;
}

static void xml_builder_tree_on_text(XmlBuilder* thiz,const char* text,size_t length)
{
    XmlNode* new_node = NULL;
    PrivInfo* priv = (PrivInfo*)thiz->priv;

    new_node = xml_node_create_text(text);
    xml_node_append_child(priv->current,new_node);

    return;
}

static void xml_builder_tree_on_comment(XmlBuilder* thiz,const char* text,size_t length)
{
    XmlNode* new_node = NULL;
    PrivInfo* priv = (PrivInfo*)thiz->priv;

    new_node = xml_node_create_comment(text);
    xml_node_append_child(priv->current,new_node);

    return;
}

static void xml_builder_tree_on_pi_element(XmlBuilder* thiz,const char* tag,const char** attrs)
{
    XmlNode* new_node = NULL;
    PrivInfo* priv = (PrivInfo*)thiz->priv;

    new_node = xml_node_create_pi(tag,attrs);
    xml_node_append_child(priv->current,new_node);

    return;
}

static void xml_builder_tree_on_error(XmlBuilder* thiz,int line,int row,const char* meaasge)
{
    fprintf(stderr,"(%d,%d) %s\n",line,row,message);

    return;
}

static void xml_builder_tree_destroy(XmlBuilder* thiz)
{
    if(thiz != NULL)
    {
        PrivInfo* priv = (PrivInfo*)thiz->priv;
        xml_node_dextroy(priv->root);

        free(thiz);
    }

    return;
}

XmlBuilder* xml_builder_tree_create(void)
{
    XmlBuilder* thiz = (XmlBuilder*)calloc(1,sizeof(XmlBuilder));

    if(thiz != NULL)
    {
        PrivInfo* priv = (PrivInfo*)thiz->priv;

        thiz->on_start_element = xml_builder_tree_on_start_element;
        thiz->on_end_element = xml_builder_tree_on_end_element;
        thiz->on_text = xml_builder_tree_on_text;
        thiz->on_comment = xml_builder_tree_on_comment;
        thiz->on_pi_element = xml_builder_tree_on_pi_element;
        thiz->on_error = xml_builder_tree_on_error;
        thiz->destroy = xml_builder_tree_destroy;

        priv->root = xml_node_create_nomal("__root__",NULL);
        priv->current = priv->root;
    }

    return thiz;
}

XmlNode* xml_builder_get_tree(XmlBuilder* thiz)
{
    XmlNode* tree = NULL;

    if(thiz != NULL)
    {
        PrivInfo* priv = (PrivInfo*)thiz->priv;
        tree = priv->root->children;
        priv->root->children = NULL;
    }

    return tree;
}

#ifdef XML_BUILDER_TREE_TEST
#include "xml_builder_dump.h"

void dump_tree(XmlNode* tree)
{
    XmlBuilder* dum_builder = xml_builder_dump_create(stdout);
    xml_node_visit(tree,dump_builder);
    xml_builder_destroy(dump_builder);

    return;
}

int main(int argc,int argv[])
{
    const char* pi_attrs[] = {"version","1.0","encoding","utf-8",NULL};
    const char* root_attrs[] = {"name","tentstan","blog","http://www.hai8818.com/blog",NULL};

    XmlBuilder* thiz = xml_builder_tree_create();

    xml_builder_on_pi_element(thiz,"xml",pi_attrs);
    xml_builder_on_comment(thiz,"comment",6);
    xml_builder_on_start_element(thiz,"programmer",root_attrs);
    xml_builder_on_text(thiz,"text",4);
    xml_builder_on_end_element(thiz,"programmer");

    XmlNode* tree = xml_builder_get_tree(thiz);
    xml_builder_destroy(thiz);

    dump_tree(tree);
    xml_node_destroy(tree);

    return 0;
}

#endif /* XML_BUILDER_TREE_TEST */
