
LPCRITICAL_SECTION FUN_005b6760(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)DAT_006fd748;
  if (DAT_006fd748 == (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    FUN_005b67a0();
    lpCriticalSection = (LPCRITICAL_SECTION)DAT_006fd748;
    if (DAT_006fd748 == (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
      return (LPCRITICAL_SECTION)0x0;
    }
  }
  DAT_006fd748 = lpCriticalSection[1].DebugInfo;
  FUN_005a9250(lpCriticalSection,0,0x18);
  InitializeCriticalSection(lpCriticalSection);
  return lpCriticalSection;
}

