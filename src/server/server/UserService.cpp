/** 
 * @file UserService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "UserService.hpp"

namespace server {

UserService::UserService (UserDB& userDB) : AbstractService("/user"), m_userDB(userDB){
}

HttpStatus UserService::get (Json::Value& out, int id) const {
    const User* user = m_userDB.getUser(id);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    out["name"] = user->m_name;
    out["age"] = user->m_age;
    return HttpStatus::OK;
}

HttpStatus UserService::post (const Json::Value& in, int id) {
    const User* user = m_userDB.getUser(id);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    unique_ptr<User> usermod (new User(*user));
    if (in.isMember("name")) {
        usermod->m_name = in["name"].asString();
    }
    if (in.isMember("age")) {
        usermod->m_age = in["age"].asInt();
    }
    m_userDB.setUser(id,std::move(usermod));
    return HttpStatus::NO_CONTENT;
}

HttpStatus UserService::put (Json::Value& out,const Json::Value& in) {
    string name = in["name"].asString();
    int age = in["age"].asInt();
    out["id"] = m_userDB.addUser(make_unique<User>(name,age));
    return HttpStatus::CREATED;
}

HttpStatus UserService::remove (int id) {
    const User* user = m_userDB.getUser(id);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    m_userDB.removeUser(id);
    return HttpStatus::NO_CONTENT;
}

}