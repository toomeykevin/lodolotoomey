#include "UserService.hpp"

namespace server {

UserService::UserService (UserDB& userDB) : AbstractService("/user"), m_userDB(userDB){
}

HttpStatus UserService::get (Json::Value& out, int id) const {
    const User* user = m_userDB.getUser(id);
    if (!user)
    {
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    }
    if (id < 0)
    {
        for (int k=0;k<m_userDB.getSize();k++){
            out[k]["name"]=m_userDB.getUser(k);
        }
        // Données sortie :
        // type "array"
        // items
        return HttpStatus::OK;
    }
    else
    {
        out["name"] = user->m_name;
        out["age"] = user->m_age;
        return HttpStatus::OK;
    }
    
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
    std::string name = in["name"].asString();
    int age = in["age"].asInt();
    int id=  m_userDB.addUser(make_unique<User>(name,age));
    out["id"]=id;
    if (id>2){
        throw ServiceException(HttpStatus::OUT_OF_RESSOURCES,"Nous avons déjà 2 joueurs");
        m_userDB.removeUser(id);
    }
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