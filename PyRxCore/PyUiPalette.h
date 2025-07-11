#pragma once

#pragma pack (push, 8)
class PyCAdUiPalette;
class PyCAdUiPaletteSet;

enum class PaletteDockStyle : int
{
    kNone = 0,
    kLeft = CBRS_ALIGN_LEFT,
    kRight = CBRS_ALIGN_RIGHT,
    kTop = CBRS_ALIGN_TOP,
    kBottom = CBRS_ALIGN_BOTTOM,
    kAny = CBRS_ALIGN_ANY,
};

//---------------------------------------------------------------------
//PyCAdUiPaletteSetImpl
class PyCAdUiPaletteSetImpl : public CAdUiPaletteSet
{
public:
    DECLARE_DYNCREATE(PyCAdUiPaletteSetImpl);
    PyCAdUiPaletteSetImpl();
    PyCAdUiPaletteSetImpl(PyCAdUiPaletteSet* bckPtr);
    virtual ~PyCAdUiPaletteSetImpl() override = default;
    DECLARE_MESSAGE_MAP();
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
public:
    PyCAdUiPaletteSet* bckptr(const std::source_location& src = std::source_location::current()) const;
private:
    PyCAdUiPaletteSet* m_bckPtr = nullptr;
};

//---------------------------------------------------------------------
//PyCAdUiPaletteSet
void makePyCAdUiPaletteSetWrapper();
class PyCAdUiPaletteSet : public boost::python::wrapper<PyCAdUiPaletteSet>
{
public:
    PyCAdUiPaletteSet(const std::string& name);
    PyCAdUiPaletteSet(const std::string& name, const std::string& guid);
    virtual ~PyCAdUiPaletteSet() = default;
public: //INTERNAL
    void        createChildren();
    bool        create();

public:
    int         add(const std::string& name, boost::python::object& panel);
    void        setVisible(bool show);

    bool             anchored() const;
    void             enableDocking(PaletteDockStyle dwDockStyle);
    void             setDockState(PaletteDockStyle dwDockStyle) const;
    PaletteDockStyle getDockState() const;

    void        setSize(int x, int y) const;
    void        setLocation(int x, int y) const;
    bool        isFloating() const;
    void        initFloatingPosition(boost::python::tuple& pyrect) const;
    boost::python::tuple getFloatingRect() const;
    void        dockControlBar(PaletteDockStyle dwDockStyle, boost::python::tuple& pyrect) const;
    DWORD       getPaletteSetStyle() const;
    void        setPaletteSetStyle(DWORD dwStyle) const;
    bool        autoRollupStyle() const;
    bool        propertiesMenuStyle() const;
    bool        closeButtonStyle() const;
    bool        singlePaletteTabStyle() const;
    bool        useSinglePaletteTabNameStyle() const;
    bool        editNameStyle() const;
    bool        snapStyle() const;
    bool        showRollupButtonStyle() const;
    bool        showIconStyle() const;
    std::string getName() const;
    bool        setName(const std::string& name) const;
    bool        setToolId(const std::string& guid);
    int         getOpacity() const;
    bool        setOpacity(int nOpacity) const;
    int         getRolloverOpacity() const;
    bool        setRolloverOpacity(int nOpacity) const;
    int         getActivePaletteTabIndex() const;
    bool        setActivePalette(int nPaletteIndex) const;
    bool        setAutoRollup(bool flag) const;
    bool        getAutoRollup() const;
    void        rollOut1() const;
    void        rollOut2(bool bDelay) const;
    void        rollUp() const;
    bool        removePalette(int nPaletteIndex) const;
    void        restoreControlBar1() const;
    void        restoreControlBar2(PaletteDockStyle dwDockStyle, boost::python::tuple& pyrect) const;
    int         getPaletteCount() const;
    PyObject* getFullRect() const;
    bool        rolledUp() const;
    CAdUiPaletteSet::AdUiTitleBarLocation titleBarLocation() const;
    void        setTitleBarLocation(CAdUiPaletteSet::AdUiTitleBarLocation loc) const;
    void        updateTabs() const;
    COLORREF    paletteBackgroundColor() const;
    COLORREF    paletteTabTextColor() const;
    wxTopLevelWindow* getWxWindow();
    PyObject* getPyWxWindow();

    static      bool showPalettes();
    static      bool hidePalettes();

public: //INTERNAL
    PyCAdUiPaletteSetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<PyCAdUiPaletteSetImpl> m_pyImp;
    std::vector<PyCAdUiPalette> m_children;
    CString m_name;
    GUID m_guid = { GUID_NULL };
    PaletteDockStyle m_docStyle = PaletteDockStyle::kAny;
    wxTopLevelWindow* m_thisFrame = nullptr;
    bool m_created = false;
};

//---------------------------------------------------------------------
//PyCAdUiPaletteImpl
class PyCAdUiPaletteImpl : public CAdUiPalette
{
    DECLARE_DYNAMIC(PyCAdUiPaletteImpl);

public:
    PyCAdUiPaletteImpl();
    PyCAdUiPaletteImpl(PyCAdUiPalette* bckPtr, wxPanel* panel);
    virtual ~PyCAdUiPaletteImpl() override = default;
    DECLARE_MESSAGE_MAP();
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    wxWindow* thiswindow(const std::source_location& src = std::source_location::current()) const;
    wxWindow* ownerwin(const std::source_location& src = std::source_location::current()) const;
    wxPanel* panel(const std::source_location& src = std::source_location::current()) const;
    PyCAdUiPalette* bckptr(const std::source_location& src = std::source_location::current()) const;
    void setPyPaletteSet(PyCAdUiPaletteSet* paletteSet);
private:
    friend PyCAdUiPalette;

    wxPanel* m_panel = nullptr;
    wxWindow* m_thiswin = nullptr;
    PyCAdUiPalette* m_bckPtr = nullptr;
    PyCAdUiPaletteSet* m_paletteSet = nullptr;
};

//---------------------------------------------------------------------
//PyCAdUiPalette
void makePyCAdUiPaletteWrapper();
class PyCAdUiPalette
{
public:
    PyCAdUiPalette(const std::string& name, wxPanel* panel);
    virtual ~PyCAdUiPalette() = default;
    void setPyPaletteSet(PyCAdUiPaletteSet* paletteSet) const;
    PyObject* getPyWxWindow() const;
    PyCAdUiPaletteImpl* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<PyCAdUiPaletteImpl> m_pyImp;
};

#pragma pack (pop)
