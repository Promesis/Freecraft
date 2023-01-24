/**
 * @file list.hpp
 * @author Promesis (m3149154722@outlook.com)
 * @brief defines linked list.
 * @version 0.1
 * @date 2023-01-24
 * 
 * Promesis 2023
 * the Freecraft dev
 * 
 */

#ifndef list_hpp
#define list_hpp

template< typename type >
class fclist
{
    protected:
    struct node
    {
        type item;
        node *next;
    } *head;
    unsigned int length;
    
    public:
    fclist(void) noexcept;
    fclist(unsigned int length,type item);
    fclist(const fclist &ls);
    void clear(void) noexcept;
    type &at(unsigned int pos);
    unsigned int length(void) const;
    type &operator[](int pos);
};

#endif