/*
 * File:   init_dsp.c
 * Author: M91406
 *
 * Created on October 16, 2018, 12:00 PM
 */


#include <xc.h>
#include "xc16_pral.h"

/* === Initialize CPU ===================================================== */
volatile uint16_t Dsp_Initialize(void) {

    volatile uint16_t retval=1;
    volatile struct DSP_CONFIG_s dsp_config;
    
    // This routine initializes the default configuration of the 
    // DSP core for performing SMPS control loop libraries.
    // If any other section of the firmware needs to use the DSP 
    // with different settings, this code module would have to 
    // make sure the core configuration is reset to these defaults
    // when the SMPS control library is executed.
    //
    // Please note: 
    // The configuration of the control library allows to add its own 
    // core configuration save & restore cycle in the control code.
    // Please enable this function in the control loop configuration
    // if conflicts between different DSP configurations cannot be 
    // resolved differently within the firmware.
    
    dsp_config.bits.ACCSAT = CORCON_ACCSAT_931;  // Accumulator Saturation Mode Selection: 9.31 saturation (super saturation)
    dsp_config.bits.IF = CORCON_IF_FRACTIONAL;   // Integer or Fractional Multiplier Mode Selection: Fractional mode is enabled for DSP multiply
    dsp_config.bits.RND = CORCON_RND_UNBIASED;   // Rounding Mode Selection: Unbiased (convergent) rounding is enabled
    dsp_config.bits.SATA = CORCON_SATA_ON;       // ACCA Saturation Enable: Accumulator A saturation is enabled
    dsp_config.bits.SATB = CORCON_SATB_ON;       // ACCB Saturation Enable: Accumulator B saturation is enabled
    dsp_config.bits.SATDW = CORCON_SATDW_OFF;    // Data Space Write from DSP Engine Saturation Enable: Data Space write saturation is disabled
    dsp_config.bits.US = CORCON_US_SIGNED;       // DSP Multiply Unsigned/Signed Control: DSP engine multiplies are signed
    dsp_config.bits.VAR = CORCON_VAR_FIXED;      // Variable Exception Processing Latency Control: Fixed exception processing is enabled

//    dsp_config.bits.DL = CORCON_DL_0;              // (read only)
//    dsp_config.bits.EDT = CORCON_EDT_RUN;          // control bit => do not set during configuration
//    dsp_config.bits.SFA = CORCON_SFA_ACTIVE;       // (read only)
//    dsp_config.bits.IPL3 = CORCON_IPL3_STAT_LT7;   // (read only)
    
    retval &= Dsp_SetConfig(dsp_config);
    
    Nop();
    Nop();
    Nop();
    
    return(retval);
}

