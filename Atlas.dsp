# Microsoft Developer Studio Project File - Name="Atlas" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Atlas - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Atlas.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Atlas.mak" CFG="Atlas - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Atlas - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Atlas - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Atlas - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ATLAS_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ATLAS_EXPORTS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386

!ELSEIF  "$(CFG)" == "Atlas - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ATLAS_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ATLAS_EXPORTS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Atlas - Win32 Release"
# Name "Atlas - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\src\Objects\Entity\Account.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Action.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Entity\Admin.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Entity\AdminEntity.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Appearance.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Bridge.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Codec.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Combine.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Communicate.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Create.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Decoder.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Message\DecoderBase.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Delete.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Disappearance.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Divide.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Funky\Encoder.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Message\Encoder.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Error.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Feel.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Entity\Game.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Entity\GameEntity.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Get.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Imaginary.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Info.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Listen.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Login.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Logout.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Look.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Net\Loopback.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Move.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Codecs\Packed.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Perceive.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Perception.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Entity\Player.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Message\QueuedDecoder.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Root.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Entity\RootEntity.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\RootOperation.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Set.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Sight.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Smell.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Sniff.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Sound.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Net\Stream.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Talk.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Touch.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Codecs\XML.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\src\Objects\Entity\Account.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Action.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Entity\Admin.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Entity\AdminEntity.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Appearance.h
# End Source File
# Begin Source File

SOURCE=.\src\Bridge.h
# End Source File
# Begin Source File

SOURCE=.\src\Codec.h
# End Source File
# Begin Source File

SOURCE=.\src\Codec_impl.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Combine.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Communicate.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Create.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Decoder.h
# End Source File
# Begin Source File

SOURCE=.\src\Message\DecoderBase.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Delete.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Disappearance.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Divide.h
# End Source File
# Begin Source File

SOURCE=.\src\Funky\Encoder.h
# End Source File
# Begin Source File

SOURCE=.\src\Message\Encoder.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Encoder.h
# End Source File
# Begin Source File

SOURCE=.\src\EncoderBase.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Error.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Feel.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Entity\Game.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Entity\GameEntity.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Get.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Imaginary.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Info.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Listen.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Login.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Logout.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Look.h
# End Source File
# Begin Source File

SOURCE=.\src\Net\Loopback.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Move.h
# End Source File
# Begin Source File

SOURCE=.\src\Negotiate.h
# End Source File
# Begin Source File

SOURCE=.\src\Message\Object.h
# End Source File
# Begin Source File

SOURCE=.\src\Codecs\Packed.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Perceive.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Perception.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Entity\Player.h
# End Source File
# Begin Source File

SOURCE=.\src\Message\QueuedDecoder.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Root.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Entity\RootEntity.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\RootOperation.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Set.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Sight.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Smell.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Sniff.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Sound.h
# End Source File
# Begin Source File

SOURCE=.\src\Net\Stream.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Talk.h
# End Source File
# Begin Source File

SOURCE=.\src\Task.h
# End Source File
# Begin Source File

SOURCE=.\src\Objects\Operation\Touch.h
# End Source File
# Begin Source File

SOURCE=.\src\Codecs\Utility.h
# End Source File
# Begin Source File

SOURCE=.\src\Codecs\XML.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
