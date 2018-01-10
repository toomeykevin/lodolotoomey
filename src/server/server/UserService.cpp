#include "UserService.hpp"

namespace server {

UserService::UserService (UserDB& userDB) : AbstractService("/user"), m_userDB(userDB){
}

HttpStatus UserService::get (Json::Value& out, int id) const
{
    // on recherche l'utilisateur concerné
    const User* user = m_userDB.getUser(id);
    // si on ne trouve pas l'utilisateur
    if (!user)
    {
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    }
    // si l'id est négatif, on veut la liste des utilisateurs
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
    // si l'id est existant et positif, on veut l'utilisateur concerné
    else
    {
        out["name"] = user->m_name;
        return HttpStatus::OK;
    }
    
}

HttpStatus UserService::post (const Json::Value& in, int id)
{
    // on cherche l'utilisateur lié à l'id donné
    const User* user = m_userDB.getUser(id);
    if (!user)
    {
        // si on ne trouve pas l'utlisateur
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    }
    unique_ptr<User> usermod (new User(*user));
    if (in.isMember("name"))
    {
        usermod->m_name = in["name"].asString();
    }
    m_userDB.setUser(id,std::move(usermod));
    return HttpStatus::NO_CONTENT;
}

HttpStatus UserService::put (Json::Value& out,const Json::Value& in)
{
    std::string name = in["name"].asString();
    // on ajoute l'utilisateur à la liste des utilisateurs
    int id=  m_userDB.addUser(make_unique<User>(name));
    // on renvoie l'id de l'utilisateur
    out["id"]=id;
    if (id>2)
    {
        // si cet id est plus grand que 2
        // alors c'est qu'il y avait déjà suffisamment de joueurs
        throw ServiceException(HttpStatus::OUT_OF_RESSOURCES,"Nous avons déjà 2 joueurs");
        m_userDB.removeUser(id);
    }
    return HttpStatus::CREATED;
}

HttpStatus UserService::remove (int id)
{
    // on cherche l'utilisateur lié à l'id donné
    const User* user = m_userDB.getUser(id);
    if (!user)
    {
        // si on ne trouve pa l'utilisateur
        throw ServiceException(HttpStatus::NOT_FOUND,"User ID invalide");
    }
    // si on trouve l'utilisateur
    m_userDB.removeUser(id);
    return HttpStatus::NO_CONTENT;
}

}