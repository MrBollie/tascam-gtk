/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OFader.h
 * Author: onkel
 *
 * Created on January 15, 2017, 10:17 AM
 */

#ifndef OFADER_H
#define OFADER_H

#include <iostream>

//#include <lo/lo.h>

#include "OTypes.h"
#include "OMeter.h"
#include "ODial.h"
#include "OAlsa.h"

class OFader : public Gtk::VBox {
public:
    OFader();
    OFader(const OFader& orig);
    virtual ~OFader();

    void init(int index, OAlsa* alsa, Gtk::Window* wnd);
    
    void set_view_type(VIEW_TYPE view_type, CHANNEL_TYPE channel_type);
    
    void reset(OAlsa* alsa, int index);
    void save_values(FILE* file);    
    void load_values(Glib::ustring xml);    
    
    Gtk::ToggleButton* m_MuteEnable;
    Gtk::ToggleButton* m_SoloEnable;
    Gtk::ToggleButton* m_PhaseEnable[2];    
    Gtk::VScale* m_fader;
    ODial* m_Pan[2];
    
    OMeter m_meter[2];
    Gtk::Label m_dB;

    
private:
    VIEW_TYPE m_view_type;
    Gtk::Grid m_grid;
};

#endif /* OFADER_H */
