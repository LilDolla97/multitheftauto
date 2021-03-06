/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*               (Shared logic for modifications)
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/shared_logic/CClientVehicleManager.h
*  PURPOSE:     Vehicle entity manager class header
*  DEVELOPERS:  Christian Myhre Lundheim <>
*               Ed Lyons <eai@opencoding.net>
*               Jax <>
*               Kevin Whiteside <kevuwk@gmail.com>
*               Cecill Etheredge <ijsf@gmx.net>
*
*****************************************************************************/

#ifndef __CCLIENTVEHICLEMANAGER_H
#define __CCLIENTVEHICLEMANAGER_H

#include "CClientCommon.h"
#include <list>

class CClientManager;
class CClientVehicle;
enum eClientVehicleType;

extern unsigned char g_ucMaxPassengers [];

class CClientVehicleManager
{
    friend CClientManager;
    friend CClientVehicle;

public:
    void                            DeleteAll               ( void );

    inline unsigned int             Count                   ( void )                        { return static_cast < unsigned int > ( m_List.size () ); };
    static CClientVehicle*          Get                     ( ElementID ID );
    CClientVehicle*                 Get                     ( CVehicle* pVehicle, bool bValidatePointer );
    CClientVehicle*                 GetSafe                 ( CEntity * pEntity );
    CClientVehicle*                 GetClosest              ( CVector& vecPosition, float fRadius );

    void                            DoPulse                 ( void );

    static bool                     IsTrainModel            ( unsigned long ulModel );
    static bool                     IsValidModel            ( unsigned long ulModel );
    static eClientVehicleType       GetVehicleType          ( unsigned long ulModel );
    static unsigned char            GetMaxPassengerCount    ( unsigned long ulModel );
    static unsigned char            ConvertIndexToGameSeat  ( unsigned long ulModel, unsigned char ucIndex );

    static bool                     HasTurret               ( unsigned long ulModel );
    static bool                     HasSirens               ( unsigned long ulModel );
    static bool                     HasLandingGears         ( unsigned long ulModel );
    static bool                     HasAdjustableProperty   ( unsigned long ulModel );
    static bool                     HasSmokeTrail           ( unsigned long ulModel );
    static bool                     HasTaxiLight            ( unsigned long ulModel );
    static bool                     HasSearchLight          ( unsigned long ulModel );
    static bool                     HasDamageModel          ( unsigned long ulModel );
    static bool                     HasDamageModel          ( enum eClientVehicleType Type );

    bool                            Exists                  ( CClientVehicle* pVehicle );

    static bool                     IsVehicleLimitReached   ( void );

    void                            RestreamVehicles        ( unsigned short usModel );

    std::vector < CClientVehicle* > ::iterator            IterGet             ( CClientVehicle* pVehicle );
    std::vector < CClientVehicle* > ::reverse_iterator    IterGetReverse      ( CClientVehicle* pVehicle );
    std::vector < CClientVehicle* > ::iterator            IterBegin           ( void )    { return m_List.begin (); };
    std::vector < CClientVehicle* > ::iterator            IterEnd             ( void )    { return m_List.end (); };
    std::vector < CClientVehicle* > ::reverse_iterator    IterReverseBegin    ( void )    { return m_List.rbegin (); };
    std::vector < CClientVehicle* > ::reverse_iterator    IterReverseEnd      ( void )    { return m_List.rend (); };
    std::vector < CClientVehicle* > ::iterator            StreamedBegin       ( void )    { return m_StreamedIn.begin (); };
    std::vector < CClientVehicle* > ::iterator            StreamedEnd         ( void )    { return m_StreamedIn.end (); };
    
private:
                                    CClientVehicleManager   ( CClientManager* pManager );
                                    ~CClientVehicleManager  ( void );

    inline void                     AddToList               ( CClientVehicle* pVehicle )    { m_List.push_back ( pVehicle ); };
    void                            RemoveFromList          ( CClientVehicle* pVehicle );

    void                            OnCreation              ( CClientVehicle* pVehicle );
    void                            OnDestruction           ( CClientVehicle* pVehicle );

    CClientManager*                 m_pManager;
    bool                            m_bCanRemoveFromList;
    std::vector < CClientVehicle* >   m_List;
    std::vector < CClientVehicle* >   m_StreamedIn;
    std::list < CClientVehicle* >   m_Attached;

};

#endif
