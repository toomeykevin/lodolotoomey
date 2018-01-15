#include "UserService.hpp"
#include <iostream>

using namespace std;

int NbrJoueurs=0;

namespace server {

UserService::UserService (UserDB& userDB) : AbstractService("/user"), m_userDB(userDB){
}


// GET : Obtient un utilisateur à partir de son id
HttpStatus UserService::get (Json::Value& out, int id) const
{
    if (id == -1)
    {
        for (int k=1;k<=2/*m_userDB.getSize()*/;k++)
        {
            out[k-1]["name"]=m_userDB.getUser(k)->m_name;
        }
        return HttpStatus::OK;
    }
    else
    {
        const User* user = m_userDB.getUser(id);
        if (!user)
        {
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
        }
        else
        {
            out["name"] = user->m_name;
            return HttpStatus::OK;
        }
    }  
}

// POST : Modifie un utilisateur à partir de son id et du nouveau profil
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

// PUT : Ajoute un nouvel utilisateur
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
        m_userDB.removeUser(id);
        throw ServiceException(HttpStatus::OUT_OF_RESSOURCES,"Nous avons déjà 2 joueurs");
        
    }
    else if (id == 2)
    {
        throw ServiceException(HttpStatus::CREATED,"Lancement de la partie");
        //NbrJoueurs++;
    }
    else
    {
        return HttpStatus::CREATED;
        //NbrJoueurs++;
    }
    
}

// DELETE : Supprime un utilisateur de la partie à partir de son id
HttpStatus UserService::remove (int id)
{
    // on cherche l'utilisateur lié à l'id donné
    const User* user = m_userDB.getUser(id);
    if (!user)
    {
        // si on ne trouve pas l'utilisateur
        throw ServiceException(HttpStatus::NOT_FOUND,"User ID invalide");
    }
    // si on trouve l'utilisateur
    m_userDB.removeUser(id);
    return HttpStatus::NO_CONTENT;
    
    NbrJoueurs--;
}

}