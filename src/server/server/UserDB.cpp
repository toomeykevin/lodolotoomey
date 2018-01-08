
#include "UserDB.hpp"

namespace server {

UserDB::UserDB() {
    m_idseq=1;
}

const User* UserDB::getUser (int id) const {
    auto ite = m_users.find(id);
    if (ite == m_users.cend())
        return nullptr;
    return ite->second.get();
}

int UserDB::addUser (unique_ptr<User> user) {
    int id = m_idseq++;
    m_users.insert(std::make_pair(id,std::move(user)));
    return id;
}

void UserDB::setUser (int id, unique_ptr<User> user) {
    m_users[id] = std::move(user);
    if (id > m_idseq) {
        m_idseq = id;
    }
}

void UserDB::removeUser (int id) {
    auto ite = m_users.find(id);
    if (ite == m_users.end())
        return;
    m_users.erase(ite);
}

}
