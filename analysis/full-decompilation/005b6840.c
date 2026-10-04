
/* WARNING: Type propagation algorithm not settling */

void FUN_005b6840(LPCRITICAL_SECTION param_1)

{
  if (param_1 != (LPCRITICAL_SECTION)0x0) {
    DeleteCriticalSection(param_1);
    param_1[1].LockCount = 0x46524545;
    param_1[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)DAT_006fd748;
    DAT_006fd748 = param_1;
  }
  return;
}

