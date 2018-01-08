
#include "VersionService.hpp"

namespace server {

VersionService::VersionService () : AbstractService("/version") {
    
}

HttpStatus VersionService::get (Json::Value& out, int id) const {
    out["major"] = 1;
    out["minor"] = 0;
    return HttpStatus::OK;
}
}