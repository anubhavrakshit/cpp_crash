#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
using namespace std;

int userHash(string username, int hashKey) {
  const int p = hashKey;
  const int n = 360;
  int hashCode = 0;
  long long p_pow = 1;
  for (int i = 0; i < username.length(); i++) {
    char character = username[i];
    hashCode = (hashCode + (character - 'A' + 1) * p_pow) % n;
    p_pow = (p_pow * p) % n;
  }
  return hashCode;
}
struct Server {
  string servername;
  multiset<int> keys;
  Server() : servername{""} {};
  Server(string name) : servername{name} {};
  vector<int> remove_keys(pair<int, int> range, map<int, vector<Server>> &ring);
};
vector<int> Server::remove_keys(pair<int, int> range,
                                map<int, vector<Server>> &ring) {
  vector<int> removed;
  cout << "remove_key request from " << servername << endl;
  for (auto key : keys) {
    if (key >= range.first and key <= range.second) {
      removed.push_back(key);
      cout << "remove_key from " << servername << " " << key << endl;
    }  
  }
  for (auto key : removed) {
    keys.erase(key);
  }
  return removed;
}

int assign(int hash, map<int, vector<Server>> &ring) {
  for (int i = (hash + 1) % 360; i != hash; i = (i + 1) % 360) {
    if (ring.count(i)) {
      auto &servers = ring[i];
      servers.back().keys.insert(hash);
      cout << "assign key " << hash << " " << servers.back().servername << endl;
      return i;
    }
  }

  auto &servers = ring[hash];
  servers.back().keys.insert(hash);
  return hash;
}

int add(int hash, Server srv, map<int, vector<Server>> &ring) {
  // lets find the prev ringLocation
  pair<int, int> range1, range2;
  bool single_range{false};
  for (int i = (hash - 1 + 360) % 360; i != hash; i = (i - 1 + 360) % 360) {
    if (ring.count(i)) {
      if (i < hash) {
        range1 = {i, hash - 1};
        single_range = true;
        cout << "range1 " << range1.first << "-" << range1.second << endl;
      } else {
        range1 = {i, 359};
        cout << "range1 " << range1.first << "-" << range1.second << endl;
        range2 = {0, hash - 1};
        cout << "range2 " << range2.first << "-" << range2.second << endl;
      }
      break;
    }
  }
  vector<int> reassigned;
  for (auto &[pos, servers] : ring) {
    vector<int> removed;
    if (pos == hash) {
        continue;
    }
    for (auto &srv : servers) {
      
      removed = srv.remove_keys(range1, ring);
    }

    for (auto h : removed) {
      reassigned.push_back(h);
    }
    if (!single_range) {
      removed.clear();
      for (auto &srv : servers) {
        removed = srv.remove_keys(range2, ring);
      }
      for (auto h : removed) {
        reassigned.push_back(h);
      }
    }
  }
  ring[hash].push_back(srv);
  for (auto key : reassigned) {
    assign(key, ring);
  }
  cout << "ADD " << srv.servername << " reass " << reassigned.size() << endl;
  return reassigned.size();
}

vector<int> solve(vector<string> &A, vector<string> &B, vector<int> &C) {
  // slots 0 - 359
  // addServer(string serverID, hashFunction) -> ringLoaction
  // removeServer(string serverID)
  // assign(keyname)

  // A[i] -> Type of operation
  // B[i] -> Key/serverID
  // C[i] -> hashKey
  vector<int> ans;
  // hash - server
  map<int, vector<Server>> ring;
  // serverName - hash
  map<string, int> name_to_hash;
  int index{0};

  for (auto cmd : A) {
    if (cmd == "ADD") {
      int hash = userHash(B[index], C[index]);
      name_to_hash[B[index]] = hash;
      Server srv(B[index]);
      cout << index + 1 <<" ADD with hash " << hash << endl;
      auto ret = add(hash, srv, ring);
      ans.push_back(ret);
    } else if (cmd == "ASSIGN") {
      int hash = userHash(B[index], C[index]);
      cout<< index + 1  << "ASSIGN with hash " << hash << endl;
      auto ret = assign(hash, ring);
      ans.push_back(ret);
    } else {
      cout<< index + 1  << "Remove " << B[index] << endl;
      int hash = name_to_hash[B[index]];
      auto &servers = ring[hash];
      Server srv_to_remove;
      auto itr = servers.begin();
      multiset<int> key_to_reassign;
      while (itr != servers.end()) {
        cout << "Try Remove " << itr->servername << endl;
        if (itr->servername == B[index]) {
          srv_to_remove = *itr;
          key_to_reassign = srv_to_remove.keys;
          itr = servers.erase(itr);
            cout << "Removed " << itr->servername << endl;
          break;
        } else {
            ++itr;
        }
      }
      auto it = name_to_hash.find(B[index]);
      name_to_hash.erase(it);
      if (servers.empty()) {
        ring.erase(hash);
      }

      for (auto k : key_to_reassign) {
        assign(k, ring);
      }
      ans.push_back(key_to_reassign.size());
    }
    index++;
  }

  return ans;
}

int main() {
    vector<string> A = {"ADD","ASSIGN","ASSIGN","ASSIGN","ADD","ASSIGN","ASSIGN","ASSIGN","ADD","ASSIGN","ASSIGN","ASSIGN","ADD","ASSIGN","ASSIGN","ASSIGN","REMOVE","ASSIGN","ASSIGN","ASSIGN","REMOVE","ASSIGN","ASSIGN","ASSIGN","REMOVE","ASSIGN","ASSIGN"};
    vector<string> B = {"INDIA","UMWC","JUUW","BGOQ","RUSSIA","MLCZ","MLXT","MKDU","CHINA","XIPF","JNDT","OVUL","GERMANY","BEIZ","GUJU","BAXX","INDIA","UCWG","NOJQ","INLB","RUSSIA","NEGK","BILS","EYMZ","CHINA","MIOV","NPYZ"};
    vector<int> C = {193,521,541,677,83,383,179,487,577,151,967,991,919,277,971,277,-1,103,769,607,-1,397,653,277,-1,79,569};
    auto ret = solve(A, B, C);
    for (auto n : ret) {
        cout << n << " "; 
    }
    return 0;
}