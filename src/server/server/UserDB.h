// Generated by dia2code
#ifndef SERVER__USERDB__H
#define SERVER__USERDB__H

#include <thread>
#include <memory>
#include <map>

namespace engine {
  class Engine;
};
namespace server {
  class User;
}

#include "engine/Engine.h"
#include "User.h"

namespace server {

  /// class UserDB - 
  class UserDB {
    // Associations
    // Attributes
  private:
    engine::Engine m_engine;
    std::unique_ptr<std::thread> engineThreads;
  protected:
    std::map<int,std::unique_ptr<User>> m_users;
    int m_idseq;
    // Operations
  public:
    UserDB ();
    const User* getUser (int id) const;
    int addUser (std::unique_ptr<User> user);
    void setUser (int id, std::unique_ptr<User> user);
    void removeUser (int id);
    int getSize ();
    engine::Engine& getEngine ();
    void run ();
    // Setters and Getters
  };

};

#endif
