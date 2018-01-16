// Generated by dia2code
#ifndef SERVER__ABSTRACTSERVICE__H
#define SERVER__ABSTRACTSERVICE__H

#include <string>
#include <json/json.h>

namespace server {
  class ServiceException;
}

#include "HttpStatus.h"
#include "ServiceException.h"

namespace server {

  /// class AbstractService - 
  class AbstractService {
    // Attributes
  protected:
    std::string m_pattern;
    // Operations
  public:
    AbstractService (const std::string& pattern);
    virtual ~AbstractService ();
    const std::string& getPattern () const;
    void setPattern (const std::string& pattern);
    virtual HttpStatus get (Json::Value& out, int id) const;
    virtual HttpStatus post (const Json::Value& in, int id);
    virtual HttpStatus put (Json::Value& out, const Json::Value& in);
    virtual HttpStatus remove (int id);
    // Setters and Getters
  };

};

#endif
