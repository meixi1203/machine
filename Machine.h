template <typename LISTENER>
class NMStateMachine
{
typedef std::map<NCString,int32_t> NMEventMap;
typedef std::map<int32_t,NMEventMap> NMStateMap;
public:
    NMStateMachine(int32_t defaultSts,LISTENER* listener);
    virtual   ~NMStateMachine();

    void addTranscat(int32_t state,const NCString& event,int32_t newState);
    bool eventOccur(const NCString& event);
    int32_t getCurState();
    int32_t getPreState();
    const NCString& getCurEvent();

    /* for debug */
    void outMap();

private:
    void addTranscat(int32_t state,const NMEventMap& row);
    void curStateChanged(int32_t newSts);

    /* for debug */
    void output(NMEventMap& map);

private:
    int32_t    mCurState;  /* current state */
    int32_t    mPreState;
    NMStateMap mTranscatMap;
    LISTENER*  mListener;
    NCString   mCurEvent;
    NCSyncObj  mAuthSync;
};

template <typename LISTENER>
NMStateMachine<LISTENER>::NMStateMachine(int32_t defaultSts,LISTENER* listener)
    : mCurState(defaultSts)
    , mPreState(defaultSts)
    , mTranscatMap()
    , mListener(listener)
{
}

template <typename LISTENER>
NMStateMachine<LISTENER>::~NMStateMachine()
{
}

template <typename LISTENER>
void NMStateMachine<LISTENER>::addTranscat(int32_t state,const NCString& event,int32_t newState)
{
    NMStateMap::iterator stateMap = this->mTranscatMap.find(state);

    if(stateMap == this->mTranscatMap.end()) {
        /* no state transcate */
        NMEventMap transcat;
        transcat[event] = newState;
        this->addTranscat(state,transcat);
    } else {
        /* have state transcate */
        NMEventMap row = (*stateMap).second;
        row[event] = newState;
        this->addTranscat(state,row);
    }
}

template <typename LISTENER>
void NMStateMachine<LISTENER>::addTranscat(int32_t state,const NMEventMap& row)
{
    this->mTranscatMap[state] = row;
}

template <typename LISTENER>
bool NMStateMachine<LISTENER>::eventOccur(const NCString& event)
{
    NCAutoSync autoSync(mAuthSync);
    bool result = false;
    NMStateMap::iterator stateMap = this->mTranscatMap.find(mCurState);

    mCurEvent = event;

    if(stateMap != this->mTranscatMap.end()) {
        NMEventMap row = (*stateMap).second;
        NMEventMap::iterator item = row.find(event);
        if (item != row.end()) {
            this->curStateChanged(item->second);
            result = true;
        }
    }
    return result;
}

template <typename LISTENER>
int32_t NMStateMachine<LISTENER>::getCurState()
{
    NCAutoSync autoSync(mAuthSync);
    return mCurState;
}

template <typename LISTENER>
int32_t NMStateMachine<LISTENER>::getPreState()
{
    NCAutoSync autoSync(mAuthSync);
    return mPreState;
}

template <typename LISTENER>
void NMStateMachine<LISTENER>::curStateChanged(int32_t newSts)
{
    /* notify call back */
    if (NULL != mListener) {
        /* 1.notify current state will change */
        mListener->onStsExit(mCurState);

        /* 2.bakup current status */
        mPreState = mCurState;
        /* 3.update current status */
        mCurState = newSts;

        /* 4.notify current state changed */
        mListener->onStsEnter(mCurState);
    }
}

template <typename LISTENER>
void NMStateMachine<LISTENER>::outMap()
{
    NMStateMap::iterator itr = this->mTranscatMap.begin();

    for (;itr != mTranscatMap.end(); itr++) {
        // TODO
        this->output(itr->second);
    }

    // TODO
}

template <typename LISTENER>
void NMStateMachine<LISTENER>::output(NMEventMap& map)
{
    NMEventMap::iterator itr = map.begin();

    for (;itr != map.end(); itr++) {
        // TODO
    }
}

template <typename LISTENER>
const NCString& NMStateMachine<LISTENER>::getCurEvent()
{
    return mCurEvent;
}
