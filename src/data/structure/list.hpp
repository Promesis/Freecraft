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

#include "../../fcexceptions.hpp"

/**
 * @brief list instead of stl.
 * 
 * @tparam type 
 */
template< typename type >
class fclist
{
    protected:
    struct node
    {
        /**
         * @brief item of the node.
         * 
         */
        type item;
        /**
         * @brief point to next node.
         * 
         */
        node *next;
    } *head;
    /**
     * @brief length of list.
     * 
     */
    unsigned int len;
    
    public:
    /**
     * @brief Construct a new fclist object.
     * 
     */
    fclist(void) noexcept;
    /**
     * @brief Construct a new fclist object
     * 
     * @param length how many elements to be initialized.
     * @param item what to be initialized.
     */
    fclist(unsigned int length,type item);
    /**
     * @brief Construct a new fclist object.
     * 
     * @param ls obj to copy.
     */
    fclist(const fclist &ls);
    /**
     * @brief copy assignment operator overloading.
     * 
     * @param ls obj to copy.
     * @return const fclist& 
     */
    const fclist &operator=(const fclist &ls);
    /**
     * @brief empty the list.
     * 
     */
    void clear(void) noexcept;
    /**
     * @brief item at where pos selected.
     * 
     * @param pos where.
     * @return type& 
     * @throw fcArrayIndexOutOfBoundsException array index is out of bound.
     */
    type &at(unsigned int pos);
    /**
     * @brief length of array.
     * 
     * @return unsigned int 
     */
    unsigned int length(void) const;
    /**
     * @brief item at where pos selected.
     * 
     * @param pos where.
     * @return type& 
     * @throw fcArrayIndexOutOfBoundsException array index is out of bound.
     */
    type &operator[](int pos);
};

#endif