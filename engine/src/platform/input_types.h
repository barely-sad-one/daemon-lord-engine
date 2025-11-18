#pragma once

#include "defines.h"

#include <X11/keysym.h>

#define define_key(key) KEY_##key = XK_##key

namespace Lord::platform {
using Keys = u32;
}

#define  KEY_space           XK_space           //  0x0020  /*  U+0020      SPACE           */                                                                    
#define  KEY_exclam          XK_exclam          //  0x0021  /*  U+0021      EXCLAMATION     MARK         */                                                       
#define  KEY_quotedbl        XK_quotedbl        //  0x0022  /*  U+0022      QUOTATION       MARK         */                                                       
#define  KEY_numbersign      XK_numbersign      //  0x0023  /*  U+0023      NUMBER          SIGN         */                                                       
#define  KEY_dollar          XK_dollar          //  0x0024  /*  U+0024      DOLLAR          SIGN         */                                                       
#define  KEY_percent         XK_percent         //  0x0025  /*  U+0025      PERCENT         SIGN         */                                                       
#define  KEY_ampersand       XK_ampersand       //  0x0026  /*  U+0026      AMPERSAND       */                                                                    
#define  KEY_apostrophe      XK_apostrophe      //  0x0027  /*  U+0027      APOSTROPHE      */                                                                    
#define  KEY_quoteright      XK_quoteright      //  0x0027  /*  deprecated  */                                                                                    
#define  KEY_parenleft       XK_parenleft       //  0x0028  /*  U+0028      LEFT            PARENTHESIS  */                                                       
#define  KEY_parenright      XK_parenright      //  0x0029  /*  U+0029      RIGHT           PARENTHESIS  */                                                       
#define  KEY_asterisk        XK_asterisk        //  0x002a  /*  U+002A      ASTERISK        */                                                                    
#define  KEY_plus            XK_plus            //  0x002b  /*  U+002B      PLUS            SIGN         */                                                       
#define  KEY_comma           XK_comma           //  0x002c  /*  U+002C      COMMA           */                                                                    
#define  KEY_minus           XK_minus           //  0x002d  /*  U+002D      HYPHEN-MINUS    */                                                                    
#define  KEY_period          XK_period          //  0x002e  /*  U+002E      FULL            STOP         */                                                       
#define  KEY_slash           XK_slash           //  0x002f  /*  U+002F      SOLIDUS         */                                                                    
#define  KEY_0               XK_0               //  0x0030  /*  U+0030      DIGIT           ZERO         */                                                       
#define  KEY_1               XK_1               //  0x0031  /*  U+0031      DIGIT           ONE          */                                                       
#define  KEY_2               XK_2               //  0x0032  /*  U+0032      DIGIT           TWO          */                                                       
#define  KEY_3               XK_3               //  0x0033  /*  U+0033      DIGIT           THREE        */                                                       
#define  KEY_4               XK_4               //  0x0034  /*  U+0034      DIGIT           FOUR         */                                                       
#define  KEY_5               XK_5               //  0x0035  /*  U+0035      DIGIT           FIVE         */                                                       
#define  KEY_6               XK_6               //  0x0036  /*  U+0036      DIGIT           SIX          */                                                       
#define  KEY_7               XK_7               //  0x0037  /*  U+0037      DIGIT           SEVEN        */                                                       
#define  KEY_8               XK_8               //  0x0038  /*  U+0038      DIGIT           EIGHT        */                                                       
#define  KEY_9               XK_9               //  0x0039  /*  U+0039      DIGIT           NINE         */                                                       
#define  KEY_colon           XK_colon           //  0x003a  /*  U+003A      COLON           */                                                                    
#define  KEY_semicolon       XK_semicolon       //  0x003b  /*  U+003B      SEMICOLON       */                                                                    
#define  KEY_less            XK_less            //  0x003c  /*  U+003C      LESS-THAN       SIGN         */                                                       
#define  KEY_equal           XK_equal           //  0x003d  /*  U+003D      EQUALS          SIGN         */                                                       
#define  KEY_greater         XK_greater         //  0x003e  /*  U+003E      GREATER-THAN    SIGN         */                                                       
#define  KEY_question        XK_question        //  0x003f  /*  U+003F      QUESTION        MARK         */                                                       
#define  KEY_at              XK_at              //  0x0040  /*  U+0040      COMMERCIAL      AT           */                                                       
#define  KEY_A               XK_A               //  0x0041  /*  U+0041      LATIN           CAPITAL      LETTER          A              */                        
#define  KEY_B               XK_B               //  0x0042  /*  U+0042      LATIN           CAPITAL      LETTER          B              */                        
#define  KEY_C               XK_C               //  0x0043  /*  U+0043      LATIN           CAPITAL      LETTER          C              */                        
#define  KEY_D               XK_D               //  0x0044  /*  U+0044      LATIN           CAPITAL      LETTER          D              */                        
#define  KEY_E               XK_E               //  0x0045  /*  U+0045      LATIN           CAPITAL      LETTER          E              */                        
#define  KEY_F               XK_F               //  0x0046  /*  U+0046      LATIN           CAPITAL      LETTER          F              */                        
#define  KEY_G               XK_G               //  0x0047  /*  U+0047      LATIN           CAPITAL      LETTER          G              */                        
#define  KEY_H               XK_H               //  0x0048  /*  U+0048      LATIN           CAPITAL      LETTER          H              */                        
#define  KEY_I               XK_I               //  0x0049  /*  U+0049      LATIN           CAPITAL      LETTER          I              */                        
#define  KEY_J               XK_J               //  0x004a  /*  U+004A      LATIN           CAPITAL      LETTER          J              */                        
#define  KEY_K               XK_K               //  0x004b  /*  U+004B      LATIN           CAPITAL      LETTER          K              */                        
#define  KEY_L               XK_L               //  0x004c  /*  U+004C      LATIN           CAPITAL      LETTER          L              */                        
#define  KEY_M               XK_M               //  0x004d  /*  U+004D      LATIN           CAPITAL      LETTER          M              */                        
#define  KEY_N               XK_N               //  0x004e  /*  U+004E      LATIN           CAPITAL      LETTER          N              */                        
#define  KEY_O               XK_O               //  0x004f  /*  U+004F      LATIN           CAPITAL      LETTER          O              */                        
#define  KEY_P               XK_P               //  0x0050  /*  U+0050      LATIN           CAPITAL      LETTER          P              */                        
#define  KEY_Q               XK_Q               //  0x0051  /*  U+0051      LATIN           CAPITAL      LETTER          Q              */                        
#define  KEY_R               XK_R               //  0x0052  /*  U+0052      LATIN           CAPITAL      LETTER          R              */                        
#define  KEY_S               XK_S               //  0x0053  /*  U+0053      LATIN           CAPITAL      LETTER          S              */                        
#define  KEY_T               XK_T               //  0x0054  /*  U+0054      LATIN           CAPITAL      LETTER          T              */                        
#define  KEY_U               XK_U               //  0x0055  /*  U+0055      LATIN           CAPITAL      LETTER          U              */                        
#define  KEY_V               XK_V               //  0x0056  /*  U+0056      LATIN           CAPITAL      LETTER          V              */                        
#define  KEY_W               XK_W               //  0x0057  /*  U+0057      LATIN           CAPITAL      LETTER          W              */                        
#define  KEY_X               XK_X               //  0x0058  /*  U+0058      LATIN           CAPITAL      LETTER          X              */                        
#define  KEY_Y               XK_Y               //  0x0059  /*  U+0059      LATIN           CAPITAL      LETTER          Y              */                        
#define  KEY_Z               XK_Z               //  0x005a  /*  U+005A      LATIN           CAPITAL      LETTER          Z              */                        
#define  KEY_bracketleft     XK_bracketleft     //  0x005b  /*  U+005B      LEFT            SQUARE       BRACKET         */                                       
#define  KEY_backslash       XK_backslash       //  0x005c  /*  U+005C      REVERSE         SOLIDUS      */                                                       
#define  KEY_bracketright    XK_bracketright    //  0x005d  /*  U+005D      RIGHT           SQUARE       BRACKET         */                                       
#define  KEY_asciicircum     XK_asciicircum     //  0x005e  /*  U+005E      CIRCUMFLEX      ACCENT       */                                                       
#define  KEY_underscore      XK_underscore      //  0x005f  /*  U+005F      LOW             LINE         */                                                       
#define  KEY_grave           XK_grave           //  0x0060  /*  U+0060      GRAVE           ACCENT       */                                                       
#define  KEY_quoteleft       XK_quoteleft       //  0x0060  /*  deprecated  */                                                                                    
#define  KEY_a               XK_a               //  0x0061  /*  U+0061      LATIN           SMALL        LETTER          A              */                        
#define  KEY_b               XK_b               //  0x0062  /*  U+0062      LATIN           SMALL        LETTER          B              */                        
#define  KEY_c               XK_c               //  0x0063  /*  U+0063      LATIN           SMALL        LETTER          C              */                        
#define  KEY_d               XK_d               //  0x0064  /*  U+0064      LATIN           SMALL        LETTER          D              */                        
#define  KEY_e               XK_e               //  0x0065  /*  U+0065      LATIN           SMALL        LETTER          E              */                        
#define  KEY_f               XK_f               //  0x0066  /*  U+0066      LATIN           SMALL        LETTER          F              */                        
#define  KEY_g               XK_g               //  0x0067  /*  U+0067      LATIN           SMALL        LETTER          G              */                        
#define  KEY_h               XK_h               //  0x0068  /*  U+0068      LATIN           SMALL        LETTER          H              */                        
#define  KEY_i               XK_i               //  0x0069  /*  U+0069      LATIN           SMALL        LETTER          I              */                        
#define  KEY_j               XK_j               //  0x006a  /*  U+006A      LATIN           SMALL        LETTER          J              */                        
#define  KEY_k               XK_k               //  0x006b  /*  U+006B      LATIN           SMALL        LETTER          K              */                        
#define  KEY_l               XK_l               //  0x006c  /*  U+006C      LATIN           SMALL        LETTER          L              */                        
#define  KEY_m               XK_m               //  0x006d  /*  U+006D      LATIN           SMALL        LETTER          M              */                        
#define  KEY_n               XK_n               //  0x006e  /*  U+006E      LATIN           SMALL        LETTER          N              */                        
#define  KEY_o               XK_o               //  0x006f  /*  U+006F      LATIN           SMALL        LETTER          O              */                        
#define  KEY_p               XK_p               //  0x0070  /*  U+0070      LATIN           SMALL        LETTER          P              */                        
#define  KEY_q               XK_q               //  0x0071  /*  U+0071      LATIN           SMALL        LETTER          Q              */                        
#define  KEY_r               XK_r               //  0x0072  /*  U+0072      LATIN           SMALL        LETTER          R              */                        
#define  KEY_s               XK_s               //  0x0073  /*  U+0073      LATIN           SMALL        LETTER          S              */                        
#define  KEY_t               XK_t               //  0x0074  /*  U+0074      LATIN           SMALL        LETTER          T              */                        
#define  KEY_u               XK_u               //  0x0075  /*  U+0075      LATIN           SMALL        LETTER          U              */                        
#define  KEY_v               XK_v               //  0x0076  /*  U+0076      LATIN           SMALL        LETTER          V              */                        
#define  KEY_w               XK_w               //  0x0077  /*  U+0077      LATIN           SMALL        LETTER          W              */                        
#define  KEY_x               XK_x               //  0x0078  /*  U+0078      LATIN           SMALL        LETTER          X              */                        
#define  KEY_y               XK_y               //  0x0079  /*  U+0079      LATIN           SMALL        LETTER          Y              */                        
#define  KEY_z               XK_z               //  0x007a  /*  U+007A      LATIN           SMALL        LETTER          Z              */                        
#define  KEY_braceleft       XK_braceleft       //  0x007b  /*  U+007B      LEFT            CURLY        BRACKET         */                                       
#define  KEY_bar             XK_bar             //  0x007c  /*  U+007C      VERTICAL        LINE         */                                                       
#define  KEY_braceright      XK_braceright      //  0x007d  /*  U+007D      RIGHT           CURLY        BRACKET         */                                       
#define  KEY_asciitilde      XK_asciitilde      //  0x007e  /*  U+007E      TILDE           */                                                                    
#define  KEY_nobreakspace    XK_nobreakspace    //  0x00a0  /*  U+00A0      NO-BREAK        SPACE        */                                                       
#define  KEY_exclamdown      XK_exclamdown      //  0x00a1  /*  U+00A1      INVERTED        EXCLAMATION  MARK            */                                       
#define  KEY_cent            XK_cent            //  0x00a2  /*  U+00A2      CENT            SIGN         */                                                       
#define  KEY_sterling        XK_sterling        //  0x00a3  /*  U+00A3      POUND           SIGN         */                                                       
#define  KEY_currency        XK_currency        //  0x00a4  /*  U+00A4      CURRENCY        SIGN         */                                                       
#define  KEY_yen             XK_yen             //  0x00a5  /*  U+00A5      YEN             SIGN         */                                                       
#define  KEY_brokenbar       XK_brokenbar       //  0x00a6  /*  U+00A6      BROKEN          BAR          */                                                       
#define  KEY_section         XK_section         //  0x00a7  /*  U+00A7      SECTION         SIGN         */                                                       
#define  KEY_diaeresis       XK_diaeresis       //  0x00a8  /*  U+00A8      DIAERESIS       */                                                                    
#define  KEY_copyright       XK_copyright       //  0x00a9  /*  U+00A9      COPYRIGHT       SIGN         */                                                       
#define  KEY_ordfeminine     XK_ordfeminine     //  0x00aa  /*  U+00AA      FEMININE        ORDINAL      INDICATOR       */                                       
#define  KEY_guillemotleft   XK_guillemotleft   //  0x00ab  /*  deprecated  alias           for          guillemetleft   (misspelling)  */                        
#define  KEY_guillemetleft   XK_guillemetleft   //  0x00ab  /*  U+00AB      LEFT-POINTING   DOUBLE       ANGLE           QUOTATION      MARK   */                 
#define  KEY_notsign         XK_notsign         //  0x00ac  /*  U+00AC      NOT             SIGN         */                                                       
#define  KEY_hyphen          XK_hyphen          //  0x00ad  /*  U+00AD      SOFT            HYPHEN       */                                                       
#define  KEY_registered      XK_registered      //  0x00ae  /*  U+00AE      REGISTERED      SIGN         */                                                       
#define  KEY_macron          XK_macron          //  0x00af  /*  U+00AF      MACRON          */                                                                    
#define  KEY_degree          XK_degree          //  0x00b0  /*  U+00B0      DEGREE          SIGN         */                                                       
#define  KEY_plusminus       XK_plusminus       //  0x00b1  /*  U+00B1      PLUS-MINUS      SIGN         */                                                       
#define  KEY_twosuperior     XK_twosuperior     //  0x00b2  /*  U+00B2      SUPERSCRIPT     TWO          */                                                       
#define  KEY_threesuperior   XK_threesuperior   //  0x00b3  /*  U+00B3      SUPERSCRIPT     THREE        */                                                       
#define  KEY_acute           XK_acute           //  0x00b4  /*  U+00B4      ACUTE           ACCENT       */                                                       
#define  KEY_mu              XK_mu              //  0x00b5  /*  U+00B5      MICRO           SIGN         */                                                       
#define  KEY_paragraph       XK_paragraph       //  0x00b6  /*  U+00B6      PILCROW         SIGN         */                                                       
#define  KEY_periodcentered  XK_periodcentered  //  0x00b7  /*  U+00B7      MIDDLE          DOT          */                                                       
#define  KEY_cedilla         XK_cedilla         //  0x00b8  /*  U+00B8      CEDILLA         */                                                                    
#define  KEY_onesuperior     XK_onesuperior     //  0x00b9  /*  U+00B9      SUPERSCRIPT     ONE          */                                                       
#define  KEY_masculine       XK_masculine       //  0x00ba  /*  deprecated  alias           for          ordmasculine    (inconsistent  name)  */                 
#define  KEY_ordmasculine    XK_ordmasculine    //  0x00ba  /*  U+00BA      MASCULINE       ORDINAL      INDICATOR       */                                       
#define  KEY_guillemotright  XK_guillemotright  //  0x00bb  /*  deprecated  alias           for          guillemetright  (misspelling)  */                        
#define  KEY_guillemetright  XK_guillemetright  //  0x00bb  /*  U+00BB      RIGHT-POINTING  DOUBLE       ANGLE           QUOTATION      MARK   */                 
#define  KEY_onequarter      XK_onequarter      //  0x00bc  /*  U+00BC      VULGAR          FRACTION     ONE             QUARTER        */                        
#define  KEY_onehalf         XK_onehalf         //  0x00bd  /*  U+00BD      VULGAR          FRACTION     ONE             HALF           */                        
#define  KEY_threequarters   XK_threequarters   //  0x00be  /*  U+00BE      VULGAR          FRACTION     THREE           QUARTERS       */                        
#define  KEY_questiondown    XK_questiondown    //  0x00bf  /*  U+00BF      INVERTED        QUESTION     MARK            */                                       
#define  KEY_Agrave          XK_Agrave          //  0x00c0  /*  U+00C0      LATIN           CAPITAL      LETTER          A              WITH   GRAVE       */     
#define  KEY_Aacute          XK_Aacute          //  0x00c1  /*  U+00C1      LATIN           CAPITAL      LETTER          A              WITH   ACUTE       */     
#define  KEY_Acircumflex     XK_Acircumflex     //  0x00c2  /*  U+00C2      LATIN           CAPITAL      LETTER          A              WITH   CIRCUMFLEX  */     
#define  KEY_Atilde          XK_Atilde          //  0x00c3  /*  U+00C3      LATIN           CAPITAL      LETTER          A              WITH   TILDE       */     
#define  KEY_Adiaeresis      XK_Adiaeresis      //  0x00c4  /*  U+00C4      LATIN           CAPITAL      LETTER          A              WITH   DIAERESIS   */     
#define  KEY_Aring           XK_Aring           //  0x00c5  /*  U+00C5      LATIN           CAPITAL      LETTER          A              WITH   RING        ABOVE  */
#define  KEY_AE              XK_AE              //  0x00c6  /*  U+00C6      LATIN           CAPITAL      LETTER          AE             */                        
#define  KEY_Ccedilla        XK_Ccedilla        //  0x00c7  /*  U+00C7      LATIN           CAPITAL      LETTER          C              WITH   CEDILLA     */     
#define  KEY_Egrave          XK_Egrave          //  0x00c8  /*  U+00C8      LATIN           CAPITAL      LETTER          E              WITH   GRAVE       */     
#define  KEY_Eacute          XK_Eacute          //  0x00c9  /*  U+00C9      LATIN           CAPITAL      LETTER          E              WITH   ACUTE       */     
#define  KEY_Ecircumflex     XK_Ecircumflex     //  0x00ca  /*  U+00CA      LATIN           CAPITAL      LETTER          E              WITH   CIRCUMFLEX  */     
#define  KEY_Ediaeresis      XK_Ediaeresis      //  0x00cb  /*  U+00CB      LATIN           CAPITAL      LETTER          E              WITH   DIAERESIS   */     
#define  KEY_Igrave          XK_Igrave          //  0x00cc  /*  U+00CC      LATIN           CAPITAL      LETTER          I              WITH   GRAVE       */     
#define  KEY_Iacute          XK_Iacute          //  0x00cd  /*  U+00CD      LATIN           CAPITAL      LETTER          I              WITH   ACUTE       */     
#define  KEY_Icircumflex     XK_Icircumflex     //  0x00ce  /*  U+00CE      LATIN           CAPITAL      LETTER          I              WITH   CIRCUMFLEX  */     
#define  KEY_Idiaeresis      XK_Idiaeresis      //  0x00cf  /*  U+00CF      LATIN           CAPITAL      LETTER          I              WITH   DIAERESIS   */     
#define  KEY_ETH             XK_ETH             //  0x00d0  /*  U+00D0      LATIN           CAPITAL      LETTER          ETH            */                        
#define  KEY_Eth             XK_Eth             //  0x00d0  /*  deprecated  */                                                                                    
#define  KEY_Ntilde          XK_Ntilde          //  0x00d1  /*  U+00D1      LATIN           CAPITAL      LETTER          N              WITH   TILDE       */     
#define  KEY_Ograve          XK_Ograve          //  0x00d2  /*  U+00D2      LATIN           CAPITAL      LETTER          O              WITH   GRAVE       */     
#define  KEY_Oacute          XK_Oacute          //  0x00d3  /*  U+00D3      LATIN           CAPITAL      LETTER          O              WITH   ACUTE       */     
#define  KEY_Ocircumflex     XK_Ocircumflex     //  0x00d4  /*  U+00D4      LATIN           CAPITAL      LETTER          O              WITH   CIRCUMFLEX  */     
#define  KEY_Otilde          XK_Otilde          //  0x00d5  /*  U+00D5      LATIN           CAPITAL      LETTER          O              WITH   TILDE       */     
#define  KEY_Odiaeresis      XK_Odiaeresis      //  0x00d6  /*  U+00D6      LATIN           CAPITAL      LETTER          O              WITH   DIAERESIS   */     
#define  KEY_multiply        XK_multiply        //  0x00d7  /*  U+00D7      MULTIPLICATION  SIGN         */                                                       
#define  KEY_Oslash          XK_Oslash          //  0x00d8  /*  U+00D8      LATIN           CAPITAL      LETTER          O              WITH   STROKE      */     
#define  KEY_Ooblique        XK_Ooblique        //  0x00d8  /*  deprecated  alias           for          Oslash          */                                       
#define  KEY_Ugrave          XK_Ugrave          //  0x00d9  /*  U+00D9      LATIN           CAPITAL      LETTER          U              WITH   GRAVE       */     
#define  KEY_Uacute          XK_Uacute          //  0x00da  /*  U+00DA      LATIN           CAPITAL      LETTER          U              WITH   ACUTE       */     
#define  KEY_Ucircumflex     XK_Ucircumflex     //  0x00db  /*  U+00DB      LATIN           CAPITAL      LETTER          U              WITH   CIRCUMFLEX  */     
#define  KEY_Udiaeresis      XK_Udiaeresis      //  0x00dc  /*  U+00DC      LATIN           CAPITAL      LETTER          U              WITH   DIAERESIS   */     
#define  KEY_Yacute          XK_Yacute          //  0x00dd  /*  U+00DD      LATIN           CAPITAL      LETTER          Y              WITH   ACUTE       */     
#define  KEY_THORN           XK_THORN           //  0x00de  /*  U+00DE      LATIN           CAPITAL      LETTER          THORN          */                        
#define  KEY_Thorn           XK_Thorn           //  0x00de  /*  deprecated  */                                                                                    
#define  KEY_ssharp          XK_ssharp          //  0x00df  /*  U+00DF      LATIN           SMALL        LETTER          SHARP          S      */                 
#define  KEY_agrave          XK_agrave          //  0x00e0  /*  U+00E0      LATIN           SMALL        LETTER          A              WITH   GRAVE       */     
#define  KEY_aacute          XK_aacute          //  0x00e1  /*  U+00E1      LATIN           SMALL        LETTER          A              WITH   ACUTE       */     
#define  KEY_acircumflex     XK_acircumflex     //  0x00e2  /*  U+00E2      LATIN           SMALL        LETTER          A              WITH   CIRCUMFLEX  */     
#define  KEY_atilde          XK_atilde          //  0x00e3  /*  U+00E3      LATIN           SMALL        LETTER          A              WITH   TILDE       */     
#define  KEY_adiaeresis      XK_adiaeresis      //  0x00e4  /*  U+00E4      LATIN           SMALL        LETTER          A              WITH   DIAERESIS   */     
#define  KEY_aring           XK_aring           //  0x00e5  /*  U+00E5      LATIN           SMALL        LETTER          A              WITH   RING        ABOVE  */
#define  KEY_ae              XK_ae              //  0x00e6  /*  U+00E6      LATIN           SMALL        LETTER          AE             */                        
#define  KEY_ccedilla        XK_ccedilla        //  0x00e7  /*  U+00E7      LATIN           SMALL        LETTER          C              WITH   CEDILLA     */     
#define  KEY_egrave          XK_egrave          //  0x00e8  /*  U+00E8      LATIN           SMALL        LETTER          E              WITH   GRAVE       */     
#define  KEY_eacute          XK_eacute          //  0x00e9  /*  U+00E9      LATIN           SMALL        LETTER          E              WITH   ACUTE       */     
#define  KEY_ecircumflex     XK_ecircumflex     //  0x00ea  /*  U+00EA      LATIN           SMALL        LETTER          E              WITH   CIRCUMFLEX  */     
#define  KEY_ediaeresis      XK_ediaeresis      //  0x00eb  /*  U+00EB      LATIN           SMALL        LETTER          E              WITH   DIAERESIS   */     
#define  KEY_igrave          XK_igrave          //  0x00ec  /*  U+00EC      LATIN           SMALL        LETTER          I              WITH   GRAVE       */     
#define  KEY_iacute          XK_iacute          //  0x00ed  /*  U+00ED      LATIN           SMALL        LETTER          I              WITH   ACUTE       */     
#define  KEY_icircumflex     XK_icircumflex     //  0x00ee  /*  U+00EE      LATIN           SMALL        LETTER          I              WITH   CIRCUMFLEX  */     
#define  KEY_idiaeresis      XK_idiaeresis      //  0x00ef  /*  U+00EF      LATIN           SMALL        LETTER          I              WITH   DIAERESIS   */     
#define  KEY_eth             XK_eth             //  0x00f0  /*  U+00F0      LATIN           SMALL        LETTER          ETH            */                        
#define  KEY_ntilde          XK_ntilde          //  0x00f1  /*  U+00F1      LATIN           SMALL        LETTER          N              WITH   TILDE       */     
#define  KEY_ograve          XK_ograve          //  0x00f2  /*  U+00F2      LATIN           SMALL        LETTER          O              WITH   GRAVE       */     
#define  KEY_oacute          XK_oacute          //  0x00f3  /*  U+00F3      LATIN           SMALL        LETTER          O              WITH   ACUTE       */     
#define  KEY_ocircumflex     XK_ocircumflex     //  0x00f4  /*  U+00F4      LATIN           SMALL        LETTER          O              WITH   CIRCUMFLEX  */     
#define  KEY_otilde          XK_otilde          //  0x00f5  /*  U+00F5      LATIN           SMALL        LETTER          O              WITH   TILDE       */     
#define  KEY_odiaeresis      XK_odiaeresis      //  0x00f6  /*  U+00F6      LATIN           SMALL        LETTER          O              WITH   DIAERESIS   */     
#define  KEY_division        XK_division        //  0x00f7  /*  U+00F7      DIVISION        SIGN         */                                                       
#define  KEY_oslash          XK_oslash          //  0x00f8  /*  U+00F8      LATIN           SMALL        LETTER          O              WITH   STROKE      */     
#define  KEY_ooblique        XK_ooblique        //  0x00f8  /*  deprecated  alias           for          oslash          */                                       
#define  KEY_ugrave          XK_ugrave          //  0x00f9  /*  U+00F9      LATIN           SMALL        LETTER          U              WITH   GRAVE       */     
#define  KEY_uacute          XK_uacute          //  0x00fa  /*  U+00FA      LATIN           SMALL        LETTER          U              WITH   ACUTE       */     
#define  KEY_ucircumflex     XK_ucircumflex     //  0x00fb  /*  U+00FB      LATIN           SMALL        LETTER          U              WITH   CIRCUMFLEX  */     
#define  KEY_udiaeresis      XK_udiaeresis      //  0x00fc  /*  U+00FC      LATIN           SMALL        LETTER          U              WITH   DIAERESIS   */     
#define  KEY_yacute          XK_yacute          //  0x00fd  /*  U+00FD      LATIN           SMALL        LETTER          Y              WITH   ACUTE       */     
#define  KEY_thorn           XK_thorn           //  0x00fe  /*  U+00FE      LATIN           SMALL        LETTER          THORN          */                        

