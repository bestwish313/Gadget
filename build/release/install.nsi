; Turn off old selected section
; Nov-20-2015 | sangbom.koh@irco.com | created this file
  
 RequestExecutionLevel admin
  
; -------------------------------
; Start 
 
  !define MUI_PRODUCT "Gadget"
  !define MUI_VERSION "Ver (d)0.0.1"
  !define MUI_BRANDINGTEXT "Ver (d)0.0.1"
  !define MUI_FILE "Gadget"
  CRCCheck On
 
;--------------------------------
;Modern UI Configuration
 
  !define MUI_WELCOMEPAGE  
  !define MUI_LICENSEPAGE
  !define MUI_DIRECTORYPAGE
  !define MUI_ABORTWARNING
  !define MUI_UNINSTALLER
  !define MUI_UNCONFIRMPAGE
  !define MUI_FINISHPAGE 
  !define MUI_FINISHPAGE_TEXT "Thank you for installing Gadget. Now you can close the install window."
;--------------------------------

; The name of the installer
Name "Gadget"

; The file to write
OutFile "Setup.exe"

; The default installation directory
InstallDir C:\RS-SWTools\Gadget

; The text to prompt the user to enter a directory
DirText "This will install Gadget on your computer. Please choose an install directory"

;--------------------------------

; The stuff to install
Section "" ;No components page, name is not important

SetShellVarContext all

; Set output path to the installation directory.
SetOutPath $INSTDIR

; Put file there
File Gadget.exe
File icudt54.dll
File icuin54.dll
File icuuc54.dll
File libgcc_s_dw2-1.dll
File libstdc++-6.dll
File libwinpthread-1.dll
File Qt5Core.dll
File Qt5Gui.dll
File Qt5Network.dll
File Qt5Svg.dll
File Qt5Widgets.dll
File Qt5PrintSupport.dll

CreateDirectory $INSTDIR\iconengines
SetOutPath $INSTDIR\iconengines
File iconengines\qsvgicon.dll

CreateDirectory $INSTDIR\platforms
SetOutPath $INSTDIR\platforms
File platforms\qwindows.dll

CreateDirectory $INSTDIR\QtQuick.2
SetOutPath $INSTDIR\QtQuick.2
File QtQuick.2\plugins.qmltypes
File QtQuick.2\qmldir
File QtQuick.2\qtquick2plugin.dll
File QtQuick.2\qtquick2plugind.dll

SetOutPath $INSTDIR

;create desktop shortcut
  CreateShortCut "$DESKTOP\${MUI_PRODUCT}.lnk" "$INSTDIR\${MUI_FILE}.exe" ""
 
;create start-menu items
  CreateDirectory "$SMPROGRAMS\${MUI_PRODUCT}"
  CreateShortCut "$SMPROGRAMS\${MUI_PRODUCT}\Uninstall.lnk" "$INSTDIR\Uninstall.exe" "" "$INSTDIR\Uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\${MUI_PRODUCT}\${MUI_PRODUCT}.lnk" "$INSTDIR\${MUI_FILE}.exe" "" "$INSTDIR\${MUI_FILE}.exe" 0
 
;write uninstall information to the registry
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${MUI_PRODUCT}" "DisplayName" "${MUI_PRODUCT} (remove only)"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${MUI_PRODUCT}" "UninstallString" "$INSTDIR\Uninstall.exe"
 
  WriteUninstaller "$INSTDIR\Uninstall.exe"
 
SectionEnd
 

 
;--------------------------------    
;Uninstaller Section  
Section "Uninstall"
 SetShellVarContext all
 
;Delete Files 
  RMDir /r "$INSTDIR\*.*"    
 
;Remove the installation directory
  RMDir "$INSTDIR"
 
;Delete Start Menu Shortcuts
  Delete "$DESKTOP\${MUI_PRODUCT}.lnk"
  Delete "$SMPROGRAMS\${MUI_PRODUCT}\*.*"
  RMDir  "$SMPROGRAMS\${MUI_PRODUCT}"
 
;Delete Uninstaller And Unistall Registry Entries
  DeleteRegKey HKEY_LOCAL_MACHINE "SOFTWARE\${MUI_PRODUCT}"
  DeleteRegKey HKEY_LOCAL_MACHINE "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\${MUI_PRODUCT}"  
 
SectionEnd

;Function that calls a messagebox when installation finished correctly
Function .onInstSuccess
  
  
FunctionEnd