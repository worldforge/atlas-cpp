# Microsoft Developer Studio Generated NMAKE File, Based on Atlas.dsp
!IF "$(CFG)" == ""
CFG=Atlas - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Atlas - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Atlas - Win32 Release" && "$(CFG)" != "Atlas - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Atlas - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Atlas.dll"


CLEAN :
	-@erase "$(INTDIR)\Account.obj"
	-@erase "$(INTDIR)\Action.obj"
	-@erase "$(INTDIR)\Admin.obj"
	-@erase "$(INTDIR)\AdminEntity.obj"
	-@erase "$(INTDIR)\Appearance.obj"
	-@erase "$(INTDIR)\Bridge.obj"
	-@erase "$(INTDIR)\Codec.obj"
	-@erase "$(INTDIR)\Combine.obj"
	-@erase "$(INTDIR)\Communicate.obj"
	-@erase "$(INTDIR)\Create.obj"
	-@erase "$(INTDIR)\Decoder.obj"
	-@erase "$(INTDIR)\DecoderBase.obj"
	-@erase "$(INTDIR)\Delete.obj"
	-@erase "$(INTDIR)\Disappearance.obj"
	-@erase "$(INTDIR)\Divide.obj"
	-@erase "$(INTDIR)\Encoder.obj"
	-@erase "$(INTDIR)\FEncoder.obj"
	-@erase "$(INTDIR)\Error.obj"
	-@erase "$(INTDIR)\Feel.obj"
	-@erase "$(INTDIR)\Game.obj"
	-@erase "$(INTDIR)\GameEntity.obj"
	-@erase "$(INTDIR)\Get.obj"
	-@erase "$(INTDIR)\Imaginary.obj"
	-@erase "$(INTDIR)\Info.obj"
	-@erase "$(INTDIR)\Listen.obj"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\Logout.obj"
	-@erase "$(INTDIR)\Look.obj"
	-@erase "$(INTDIR)\Loopback.obj"
	-@erase "$(INTDIR)\Move.obj"
	-@erase "$(INTDIR)\Packed.obj"
	-@erase "$(INTDIR)\Perceive.obj"
	-@erase "$(INTDIR)\Perception.obj"
	-@erase "$(INTDIR)\Player.obj"
	-@erase "$(INTDIR)\QueuedDecoder.obj"
	-@erase "$(INTDIR)\Root.obj"
	-@erase "$(INTDIR)\RootEntity.obj"
	-@erase "$(INTDIR)\RootOperation.obj"
	-@erase "$(INTDIR)\Set.obj"
	-@erase "$(INTDIR)\Sight.obj"
	-@erase "$(INTDIR)\Smell.obj"
	-@erase "$(INTDIR)\Sniff.obj"
	-@erase "$(INTDIR)\Sound.obj"
	-@erase "$(INTDIR)\Stream.obj"
	-@erase "$(INTDIR)\Talk.obj"
	-@erase "$(INTDIR)\Touch.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XML.obj"
	-@erase "$(OUTDIR)\Atlas.dll"
	-@erase "$(OUTDIR)\Atlas.exp"
	-@erase "$(OUTDIR)\Atlas.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ATLAS_EXPORTS" /Fp"$(INTDIR)\Atlas.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Atlas.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\Atlas.pdb" /machine:I386 /out:"$(OUTDIR)\Atlas.dll" /implib:"$(OUTDIR)\Atlas.lib" 
LINK32_OBJS= \
	"$(INTDIR)\Codec.obj" \
	"$(INTDIR)\Bridge.obj" \
	"$(INTDIR)\XML.obj" \
	"$(INTDIR)\Packed.obj" \
	"$(INTDIR)\Encoder.obj" \
	"$(INTDIR)\FEncoder.obj" \
	"$(INTDIR)\QueuedDecoder.obj" \
	"$(INTDIR)\DecoderBase.obj" \
	"$(INTDIR)\Stream.obj" \
	"$(INTDIR)\Loopback.obj" \
	"$(INTDIR)\Decoder.obj" \
	"$(INTDIR)\Root.obj" \
	"$(INTDIR)\GameEntity.obj" \
	"$(INTDIR)\Admin.obj" \
	"$(INTDIR)\AdminEntity.obj" \
	"$(INTDIR)\Game.obj" \
	"$(INTDIR)\Account.obj" \
	"$(INTDIR)\Player.obj" \
	"$(INTDIR)\RootEntity.obj" \
	"$(INTDIR)\Touch.obj" \
	"$(INTDIR)\Appearance.obj" \
	"$(INTDIR)\Combine.obj" \
	"$(INTDIR)\Communicate.obj" \
	"$(INTDIR)\Create.obj" \
	"$(INTDIR)\Delete.obj" \
	"$(INTDIR)\Disappearance.obj" \
	"$(INTDIR)\Divide.obj" \
	"$(INTDIR)\Error.obj" \
	"$(INTDIR)\Feel.obj" \
	"$(INTDIR)\Get.obj" \
	"$(INTDIR)\Imaginary.obj" \
	"$(INTDIR)\Info.obj" \
	"$(INTDIR)\Listen.obj" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\Logout.obj" \
	"$(INTDIR)\Look.obj" \
	"$(INTDIR)\Move.obj" \
	"$(INTDIR)\Perceive.obj" \
	"$(INTDIR)\Perception.obj" \
	"$(INTDIR)\RootOperation.obj" \
	"$(INTDIR)\Set.obj" \
	"$(INTDIR)\Sight.obj" \
	"$(INTDIR)\Smell.obj" \
	"$(INTDIR)\Sniff.obj" \
	"$(INTDIR)\Sound.obj" \
	"$(INTDIR)\Talk.obj" \
	"$(INTDIR)\Action.obj"

"$(OUTDIR)\Atlas.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Atlas - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Atlas.dll"


CLEAN :
	-@erase "$(INTDIR)\Account.obj"
	-@erase "$(INTDIR)\Action.obj"
	-@erase "$(INTDIR)\Admin.obj"
	-@erase "$(INTDIR)\AdminEntity.obj"
	-@erase "$(INTDIR)\Appearance.obj"
	-@erase "$(INTDIR)\Bridge.obj"
	-@erase "$(INTDIR)\Codec.obj"
	-@erase "$(INTDIR)\Combine.obj"
	-@erase "$(INTDIR)\Communicate.obj"
	-@erase "$(INTDIR)\Create.obj"
	-@erase "$(INTDIR)\Decoder.obj"
	-@erase "$(INTDIR)\DecoderBase.obj"
	-@erase "$(INTDIR)\Delete.obj"
	-@erase "$(INTDIR)\Disappearance.obj"
	-@erase "$(INTDIR)\Divide.obj"
	-@erase "$(INTDIR)\Encoder.obj"
	-@erase "$(INTDIR)\FEncoder.obj"
	-@erase "$(INTDIR)\Error.obj"
	-@erase "$(INTDIR)\Feel.obj"
	-@erase "$(INTDIR)\Game.obj"
	-@erase "$(INTDIR)\GameEntity.obj"
	-@erase "$(INTDIR)\Get.obj"
	-@erase "$(INTDIR)\Imaginary.obj"
	-@erase "$(INTDIR)\Info.obj"
	-@erase "$(INTDIR)\Listen.obj"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\Logout.obj"
	-@erase "$(INTDIR)\Look.obj"
	-@erase "$(INTDIR)\Loopback.obj"
	-@erase "$(INTDIR)\Move.obj"
	-@erase "$(INTDIR)\Packed.obj"
	-@erase "$(INTDIR)\Perceive.obj"
	-@erase "$(INTDIR)\Perception.obj"
	-@erase "$(INTDIR)\Player.obj"
	-@erase "$(INTDIR)\QueuedDecoder.obj"
	-@erase "$(INTDIR)\Root.obj"
	-@erase "$(INTDIR)\RootEntity.obj"
	-@erase "$(INTDIR)\RootOperation.obj"
	-@erase "$(INTDIR)\Set.obj"
	-@erase "$(INTDIR)\Sight.obj"
	-@erase "$(INTDIR)\Smell.obj"
	-@erase "$(INTDIR)\Sniff.obj"
	-@erase "$(INTDIR)\Sound.obj"
	-@erase "$(INTDIR)\Stream.obj"
	-@erase "$(INTDIR)\Talk.obj"
	-@erase "$(INTDIR)\Touch.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XML.obj"
	-@erase "$(OUTDIR)\Atlas.dll"
	-@erase "$(OUTDIR)\Atlas.exp"
	-@erase "$(OUTDIR)\Atlas.ilk"
	-@erase "$(OUTDIR)\Atlas.lib"
	-@erase "$(OUTDIR)\Atlas.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ATLAS_EXPORTS" /Fp"$(INTDIR)\Atlas.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Atlas.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\Atlas.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Atlas.dll" /implib:"$(OUTDIR)\Atlas.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Codec.obj" \
	"$(INTDIR)\Bridge.obj" \
	"$(INTDIR)\XML.obj" \
	"$(INTDIR)\Packed.obj" \
	"$(INTDIR)\Encoder.obj" \
	"$(INTDIR)\FEncoder.obj" \
	"$(INTDIR)\QueuedDecoder.obj" \
	"$(INTDIR)\DecoderBase.obj" \
	"$(INTDIR)\Stream.obj" \
	"$(INTDIR)\Loopback.obj" \
	"$(INTDIR)\Decoder.obj" \
	"$(INTDIR)\Root.obj" \
	"$(INTDIR)\GameEntity.obj" \
	"$(INTDIR)\Admin.obj" \
	"$(INTDIR)\AdminEntity.obj" \
	"$(INTDIR)\Game.obj" \
	"$(INTDIR)\Account.obj" \
	"$(INTDIR)\Player.obj" \
	"$(INTDIR)\RootEntity.obj" \
	"$(INTDIR)\Touch.obj" \
	"$(INTDIR)\Appearance.obj" \
	"$(INTDIR)\Combine.obj" \
	"$(INTDIR)\Communicate.obj" \
	"$(INTDIR)\Create.obj" \
	"$(INTDIR)\Delete.obj" \
	"$(INTDIR)\Disappearance.obj" \
	"$(INTDIR)\Divide.obj" \
	"$(INTDIR)\Error.obj" \
	"$(INTDIR)\Feel.obj" \
	"$(INTDIR)\Get.obj" \
	"$(INTDIR)\Imaginary.obj" \
	"$(INTDIR)\Info.obj" \
	"$(INTDIR)\Listen.obj" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\Logout.obj" \
	"$(INTDIR)\Look.obj" \
	"$(INTDIR)\Move.obj" \
	"$(INTDIR)\Perceive.obj" \
	"$(INTDIR)\Perception.obj" \
	"$(INTDIR)\RootOperation.obj" \
	"$(INTDIR)\Set.obj" \
	"$(INTDIR)\Sight.obj" \
	"$(INTDIR)\Smell.obj" \
	"$(INTDIR)\Sniff.obj" \
	"$(INTDIR)\Sound.obj" \
	"$(INTDIR)\Talk.obj" \
	"$(INTDIR)\Action.obj"

"$(OUTDIR)\Atlas.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Atlas.dep")
!INCLUDE "Atlas.dep"
!ELSE 
!MESSAGE Warning: cannot find "Atlas.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Atlas - Win32 Release" || "$(CFG)" == "Atlas - Win32 Debug"
SOURCE=.\src\Objects\Entity\Account.cpp

"$(INTDIR)\Account.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Action.cpp

"$(INTDIR)\Action.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Entity\Admin.cpp

"$(INTDIR)\Admin.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Entity\AdminEntity.cpp

"$(INTDIR)\AdminEntity.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Appearance.cpp

"$(INTDIR)\Appearance.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Bridge.cpp

"$(INTDIR)\Bridge.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Codec.cpp

"$(INTDIR)\Codec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Combine.cpp

"$(INTDIR)\Combine.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Communicate.cpp

"$(INTDIR)\Communicate.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Create.cpp

"$(INTDIR)\Create.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Decoder.cpp

"$(INTDIR)\Decoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Message\DecoderBase.cpp

"$(INTDIR)\DecoderBase.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Delete.cpp

"$(INTDIR)\Delete.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Disappearance.cpp

"$(INTDIR)\Disappearance.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Divide.cpp

"$(INTDIR)\Divide.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Funky\Encoder.cpp

"$(INTDIR)\FEncoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE) /Fo"$(INTDIR)\\"FEncoder.obj


SOURCE=.\src\Message\Encoder.cpp

"$(INTDIR)\Encoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Error.cpp

"$(INTDIR)\Error.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Feel.cpp

"$(INTDIR)\Feel.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Entity\Game.cpp

"$(INTDIR)\Game.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Entity\GameEntity.cpp

"$(INTDIR)\GameEntity.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Get.cpp

"$(INTDIR)\Get.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Imaginary.cpp

"$(INTDIR)\Imaginary.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Info.cpp

"$(INTDIR)\Info.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Listen.cpp

"$(INTDIR)\Listen.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Login.cpp

"$(INTDIR)\Login.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Logout.cpp

"$(INTDIR)\Logout.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Look.cpp

"$(INTDIR)\Look.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Net\Loopback.cpp

"$(INTDIR)\Loopback.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Move.cpp

"$(INTDIR)\Move.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Codecs\Packed.cpp

"$(INTDIR)\Packed.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Perceive.cpp

"$(INTDIR)\Perceive.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Perception.cpp

"$(INTDIR)\Perception.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Entity\Player.cpp

"$(INTDIR)\Player.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Message\QueuedDecoder.cpp

"$(INTDIR)\QueuedDecoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Root.cpp

"$(INTDIR)\Root.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Entity\RootEntity.cpp

"$(INTDIR)\RootEntity.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\RootOperation.cpp

"$(INTDIR)\RootOperation.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Set.cpp

"$(INTDIR)\Set.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Sight.cpp

"$(INTDIR)\Sight.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Smell.cpp

"$(INTDIR)\Smell.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Sniff.cpp

"$(INTDIR)\Sniff.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Sound.cpp

"$(INTDIR)\Sound.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Net\Stream.cpp

"$(INTDIR)\Stream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Talk.cpp

"$(INTDIR)\Talk.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Objects\Operation\Touch.cpp

"$(INTDIR)\Touch.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\Codecs\XML.cpp

"$(INTDIR)\XML.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

