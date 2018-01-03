/** 
 * @file ServiceException.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "ServiceException.hpp"

namespace server {

ServiceException::ServiceException (HttpStatus status, string msg) { 
    m_httpStatus=status;
    m_msg=msg;
}

HttpStatus ServiceException::status () const {
    return m_httpStatus;
}

const char* ServiceException::what () const {
    return m_msg.c_str();
}

}