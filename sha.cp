#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#define caus cout
using namespace std;

struct scl
{
  string inh;
  scl(const char buchst[]) {
    inh=buchst;
    cout<<"initialisierte '"<<inh<<"'"<<endl;
  }
  ~scl() {
    cout<<"loesche '"<<inh<<"'"<<endl;
  }
};

struct contcl
{
  string name;
  contcl(const string name):name(name){}
  vector<shared_ptr<scl>> ve;
  contcl& operator<<(shared_ptr<scl> sptr) {
    caus<<"Uebertrage nach "<<name<<" smart_ptr "<<sptr->inh<<endl;
    ve.push_back(sptr);
  }
  contcl& operator<<(scl* sptr) {
    caus<<"Uebertrage nach "<<name<<" Zeiger "<<sptr->inh<<endl;
    shared_ptr<scl> kopie{sptr};
    ve.push_back(kopie);
  }
  void ausgeb() {
    caus<<"ausgeb "<<name<<": "<<endl;
    for(size_t i=0;i<ve.size();i++) {
      caus<<"i: "<<i<<" ";
      if (ve[i]) {
         caus<<ve[i]->inh<<endl;
      } else {
         caus<<"(0)"<<endl;
      }
    }
  }
  ~contcl() {
//    for(size_t i=ve.size();i--;) { ve[i].reset(); }
    ve.clear();
  }
};

main(int argc, char** argv)
{
  vector<shared_ptr<scl>> v1, v2;
  contcl z1("c1"), z2("z2");
  z1<<new scl("1. fuer vector");
  z1<<new scl("2. fuer vector");
  z2<<z1.ve[0];
  z2<<z1.ve[1];
  z2.ausgeb();
  z1.~contcl();
  z2.ausgeb();
  z2.~contcl();
  z2.ausgeb();
	exit(0);
#ifdef var1
  scl *sptr=new scl("fuer 1. vector");
  shared_ptr<scl> ssptr{sptr};
  z1<<ssptr;
  ssptr.reset();
  if (ssptr) caus<<"ssptr gibts noch"<<endl;
  else caus<<"ssptr geloescht"<<endl;
  if (z1.ve[0]) caus<<"z1.ve[0] gibts noch"<<endl;
  else caus<<"z1.ve[0] geloescht"<<endl;
  z1.ve[0].reset();
  if (z1.ve[0]) caus<<"z1.ve[0] gibts noch"<<endl;
  else caus<<"z1.ve[0] geloescht"<<endl;
#endif
  
  /*
  v1.push_back(ssptr);
  v2.push_back(v1[0]);
  caus<<"vor v1.clear()"<<endl;
  v1.clear();
  caus<<"vor v2.clear()"<<endl;
  v2.clear();
  */
  caus<<"vor Ende"<<endl;

  /*
  shared_ptr<scl> p{new scl("Hier bin ich")};
  shared_ptr<scl> p2=p;
  cout<<"p gibts "; if (!p) cout<<"nicht";cout<<endl;
  cout<<"*p : "<<p->inh<<endl;
  cout<<"*p2: "<<p2->inh<<endl;
  cout<<"p : "<<p<<endl;
  cout<<"p2: "<<p2<<endl;
  p.reset();
  cout<<"nach 1. reset"<<endl;
  if (p) cout<<"*p : "<<p->inh<<endl;
  if (p2) cout<<"*p2: "<<p2->inh<<endl;
  cout<<"p : "<<p<<endl;
  cout<<"p2: "<<p2<<endl;
  cout<<"vor 2. reset"<<endl;
  p2.reset();
  cout<<"nach 2. reset"<<endl;
  if (p) cout<<"*p : "<<p->inh<<endl;
  if (p2) cout<<"*p2: "<<p2->inh<<endl;
  cout<<"p : "<<p<<endl;
  cout<<"p2: "<<p2<<endl;
  cout<<"p gibts "; if (!p) cout<<"nicht";cout<<endl;
  */
}

