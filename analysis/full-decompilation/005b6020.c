
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005b6020(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  LARGE_INTEGER local_c0;
  _SYSTEM_INFO local_b8;
  _OSVERSIONINFOA local_94;
  
  uVar3 = 0;
  if (DAT_006fd640 != 0) {
    return DAT_006fd644;
  }
  DAT_006d21d0 = 0;
  _DAT_006d21bc = 0;
  _DAT_006d21d4 = 0;
  DAT_006d21b8 = 0;
  _DAT_006d21b0 = 0;
  _DAT_006d21ac = 0;
  _DAT_006d21a8 = 0;
  _DAT_006d21a4 = 0;
  DAT_006d21c8 = 0;
  _DAT_006d21c4 = 0;
  DAT_006d21d8 = 0;
  DAT_006d21b4 = 0;
  DAT_006d21cc = 0;
  _DAT_006d21e4 = 0;
  DAT_006d21e0 = 0;
  DAT_006d21dc = 0;
  DAT_006d21c0 = 0;
  _DAT_00703fc0 = _DAT_00703fc0 & 0xffffff00;
  iVar2 = FUN_005b6870();
  if (iVar2 == 0) {
    DAT_006d21dc = FUN_005b68a9();
  }
  else {
    GetSystemInfo(&local_b8);
    _DAT_006d21b0 = local_b8.dwNumberOfProcessors;
    local_c4 = 0;
    FUN_005b688b(&local_d4,0);
    uVar1 = local_d4;
    _DAT_00703fc0 = local_d0;
    _DAT_00703fc4 = local_cc;
    _DAT_00703fc8 = local_c8;
    DAT_00703fcc = 0;
    if (0 < (int)local_d4) {
      iVar2 = 0xd;
      bVar6 = true;
      pcVar4 = &DAT_00703fc0;
      pcVar5 = "GenuineIntel";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        DAT_006d21c0 = 1;
      }
      else {
        iVar2 = 0xd;
        bVar6 = true;
        pcVar4 = &DAT_00703fc0;
        pcVar5 = "AuthenticAMD";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) {
          DAT_006d21e0 = 1;
        }
        else {
          iVar2 = 0xd;
          bVar6 = true;
          pcVar4 = &DAT_00703fc0;
          pcVar5 = "CyrixInstead";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar6 = *pcVar4 == *pcVar5;
            pcVar4 = pcVar4 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (bVar6) {
            DAT_006d21dc = 1;
          }
          else {
            iVar2 = 0xd;
            bVar6 = true;
            pcVar4 = &DAT_00703fc0;
            pcVar5 = "CentaurHauls";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar6 = *pcVar4 == *pcVar5;
              pcVar4 = pcVar4 + 1;
              pcVar5 = pcVar5 + 1;
            } while (bVar6);
            if (bVar6) {
              _DAT_006d21e4 = 1;
            }
          }
        }
      }
      FUN_005b688b(&local_d4,1);
      _DAT_006d21a4 = (int)local_d4 >> 8 & 0xf;
      _DAT_006d21a8 = (int)local_d4 >> 4 & 0xf;
      _DAT_006d21ac = local_d4 & 0xf;
      if (4 < _DAT_006d21a4) {
        DAT_006d21cc = 1;
      }
      if (5 < _DAT_006d21a4) {
        DAT_006d21b4 = 1;
      }
      FUN_005b688b(&local_d4,0x80000000);
      if ((DAT_006d21e0 != 0) && (0x80000000 < local_d4)) {
        FUN_005b688b(&local_d4,0x80000001);
        _DAT_006d21d4 = local_cc >> 0x1f;
      }
      FUN_005b688b(&local_d4,1);
      DAT_006d21b8 = local_cc >> 0x17 & 1;
      DAT_006d21d0 = local_cc >> 0x1a & 1;
      DAT_006d21d8 = local_cc >> 4 & 1;
      _DAT_006d21bc = local_cc >> 0x19 & 1;
      _DAT_006d21c4 = local_cc >> 0xf & 1;
      DAT_006d21c8 = _DAT_006d21bc;
      if (DAT_006d21e0 != 0) {
        DAT_006d21c8 = local_cc >> 0x16 & 1;
      }
      iVar2 = FUN_006384a8("ISMMX");
      if (iVar2 != 0) {
        DAT_006d21b8 = FUN_00635f62(iVar2);
      }
      iVar2 = FUN_006384a8("ISK3D");
      if (iVar2 != 0) {
        _DAT_006d21d4 = FUN_00635f62(iVar2);
      }
      local_94.dwOSVersionInfoSize = 0x94;
      GetVersionExA(&local_94);
      if ((local_94.dwPlatformId == 1) && (local_94.dwMinorVersion == 0)) {
        DAT_006d21d0 = 0;
        _DAT_006d21bc = 0;
      }
      iVar2 = FUN_006384a8("ISSSE");
      if (iVar2 != 0) {
        _DAT_006d21bc = FUN_00635f62(iVar2);
      }
      iVar2 = FUN_006384a8("ISSSE2");
      if (iVar2 != 0) {
        DAT_006d21d0 = FUN_00635f62(iVar2);
      }
      iVar2 = FUN_006384a8("ISMOVNT");
      if (iVar2 != 0) {
        DAT_006d21c8 = FUN_00635f62(iVar2);
      }
      if (1 < (int)uVar1) {
        FUN_005b688b(&local_d4,2);
      }
      if (2 < (int)uVar1) {
        FUN_005b688b(&local_d4,3);
        _DAT_006d2198 = local_c8;
        _DAT_006d219c = local_cc;
        _DAT_006d21a0 = local_d0;
      }
    }
  }
  if (DAT_006fd644 == 0) {
    QueryPerformanceFrequency(&local_c0);
    if (local_c0.s.LowPart != 0 || local_c0.s.HighPart != 0) {
      if (DAT_006d21d8 == 0) {
        uVar3 = FUN_005b65a0();
      }
      else {
        uVar3 = FUN_005b6410();
      }
    }
    DAT_006fd644 = FUN_005b5e40(uVar3);
  }
  DAT_006fd640 = 1;
  return DAT_006fd644;
}

