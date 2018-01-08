
#include "AbstractService.hpp"
namespace server {
    

AbstractService::AbstractService (const string& pattern) : m_pattern(pattern) {
}

AbstractService::~AbstractService() {
    
}

const string& AbstractService::getPattern () const {
    return m_pattern;
}

void AbstractService::setPattern (const string& pattern) {
    m_pattern = pattern;
}

HttpStatus AbstractService::get (Json::Value& out, int id) const {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

HttpStatus AbstractService::post (const Json::Value& in, int id) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

HttpStatus AbstractService::put (Json::Value& out, const Json::Value& in) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

HttpStatus AbstractService::remove (int id) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

}