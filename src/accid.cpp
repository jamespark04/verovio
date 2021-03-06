/////////////////////////////////////////////////////////////////////////////
// Name:        accid.cpp
// Author:      Laurent Pugin
// Created:     2014
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#include "accid.h"

//----------------------------------------------------------------------------

#include <assert.h>

//----------------------------------------------------------------------------

#include "note.h"

namespace vrv {

//----------------------------------------------------------------------------
// Accid
//----------------------------------------------------------------------------

Accid::Accid():
    LayerElement("accid-"), PositionInterface(),
    AttAccidental()
{
    Reset();
}

Accid::~Accid()
{
}
    
void Accid::Reset()
{
    LayerElement::Reset();
    PositionInterface::Reset();
    
    ResetAccidental();
    ResetAccidLog();
}
    
//----------------------------------------------------------------------------
// Functors methods
//----------------------------------------------------------------------------

int Accid::PreparePointersByLayer( ArrayPtrVoid params )
{
    // param 0: the current Note (not used)
    //Note **currentNote = static_cast<Note**>(params[0]);
    
    Note *note = dynamic_cast<Note*>( this->GetFirstParent( &typeid(Note) ) );
    if ( !note ) {
        return FUNCTOR_CONTINUE;
    }
    
    if ( note->m_drawingAccid != NULL ) {
        note->ResetDrawingAccid();
    }
    note->m_drawingAccid = this;
    
    return FUNCTOR_CONTINUE;
}
    

} // namespace vrv
