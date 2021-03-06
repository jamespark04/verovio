/////////////////////////////////////////////////////////////////////////////
// Name:        glyph.h
// Author:      Rodolfo Zitellini
// Created:     30/07/2012
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////


#ifndef __VRV_GLYPH_H__
#define __VRV_GLYPH_H__

#include <algorithm>
#include <string>

namespace vrv {

/**
 * This class is used for storing a music font glyph.
 * All glyph values are integers. However, for keeping precision as high
 * as possible, they are 10 times the original values. Since the unit
 * per em value is also 10 times the original, there is no incident on
 * calculations elsewhere. However, it does increase the precision because
 * units are always multiplied by a point size before being devided by the
 * unit per em. See 
 * Ex: 10.2 become 102, with a unit per em of 20480 (instead of 2048)
 */
class Glyph
{
public:
    /**
     * @name Constructors, destructors, and other standard methods
     */
    ///@{
    Glyph();
    Glyph(std::string path, std::string codeStr);
    Glyph(int unitsPerEm);
    virtual ~Glyph();
    ///@}
    
    /** Get the bounds of the glyph */
    void GetBoundingBox(int *x, int *y, int *w, int *h);
    
    /** 
     * Set the bounds of the glyph
     * These are original values from the font and will be
     * stored as (int)(10.0 * x) in the glyph
     */
    void SetBoundingBox(double x, double y, double w, double h);
    
    /** Get the units per EM */
    int GetUnitsPerEm() { return m_unitsPerEm; };
    
    /** Get the path */
    std::string GetPath() { return m_path; };
    
    /** Get the code string */
    std::string GetCodeStr() { return m_codeStr; };

private:
    
    
public:
    
    
private:
    /** The bounding box values of the glyph */
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    /** Units per EM for the glyph */
    int m_unitsPerEm;
    /** Path to the file */
    std::string m_path;
    /** The Unicode code in hexa as string */
    std::string m_codeStr;
};


} // namespace vrv
    
#endif
