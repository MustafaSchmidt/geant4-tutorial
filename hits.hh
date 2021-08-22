#include "G4VHit.hh"
#include "G4Allocator.hh"
#include "G4THitsCollection.hh"

class MyHit : public G4VHit
{
public:
    MyHit();
    MyHit(const MyHit &right);
    ~MyHit();
    
    const MyHit& operator=(const MyHit &right);
    int operator==(const MyHit &right) const;
    
    inline void *operator new(size_t);
    inline void operator delete(void *aHit);
    
    virtual const std::map<G4String,G4AttDef>* GetAttDefs() const;
    virtual std::vector<G4AttValue>* CreateAttValues() const;
    
    void SetEvent(G4int _event) { event = _event; }
    
    G4int GetEvent() const { return event; }
    
private:
    G4int event;
};

using MyHitsCollection = G4THitsCollection<MyHit>;

extern G4ThreadLocal G4Allocator<MyHit>* MyHitAllocator;

inline void* MyHit::operator new(size_t)
{
  if (!MyHitAllocator) {
       MyHitAllocator = new G4Allocator<MyHit>;
  }
  return (void*)MyHitAllocator->MallocSingle();
}

inline void MyHit::operator delete(void* aHit)
{
  MyHitAllocator->FreeSingle((MyHit*) aHit);
}
