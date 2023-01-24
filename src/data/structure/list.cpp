/**
 * @file list.cpp
 * @author Promesis (m3149154722@outlook.com)
 * @brief implements of list.cpp
 * @version 0.1
 * @date 2023-01-24
 * 
 * Promesis 2023
 * the Freecraft dev
 * 
 */

#include "list.hpp"

template< typename type >
fclist<type>::fclist(void) noexcept
{
    head=nullptr;
    length=0;
}

template< typename type >
fclist<type>::fclist(unsigned int length, type item)
{
    head=nullptr;
    node *curr=head;
    for(int i=0; i < length; ++i)
    {
        curr=new node;
        curr->item=item;
        curr->next=nullptr;
        curr=curr->next;
    }
}

template< typename type >
void fclist<type>::clear(void) noexcept
{
    if(!head) return;
    node *rightcurr=head, *prevcurr=nullptr;
    do
    {
        prevcurr=rightcurr;
        rightcurr=rightcurr->next;
        delete prevcurr;
    } while (rightcurr);
    head=nullptr;
}

template< typename type >
fclist<type>::fclist(const fclist &ls)
{
    clear();
    node *lscurr=ls.head, *mycurr=head;
    do
    {
        mycurr = new node;
        mycurr->item = lscurr->item;
        mycurr->next = nullptr;

        mycurr = mycurr->next;
    } while (lscurr = lscurr->next);
}