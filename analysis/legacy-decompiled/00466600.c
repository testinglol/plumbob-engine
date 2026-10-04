
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00466600(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  WCHAR WVar1;
  char cVar2;
  int iVar3;
  DWORD DVar4;
  undefined4 uVar5;
  short *psVar6;
  WCHAR *pWVar7;
  uint uVar8;
  uint uVar9;
  char *local_494;
  char *local_490;
  undefined *local_48c;
  char *local_488;
  uint local_484;
  undefined **local_480 [10];
  int local_458 [18];
  WCHAR local_410;
  undefined1 local_40e [512];
  short sStack_20e;
  WCHAR local_20c;
  undefined1 local_20a [514];
  uint local_8;
  
  local_8 = DAT_00dd0b80 ^ (uint)&stack0xfffffffc;
  local_458[4] = 0;
  local_458[5] = 0;
  local_458[0] = 0;
  local_458[1] = 0;
  local_458[2] = 0;
  local_458[3] = 0;
  local_484 = 0x6f;
  iVar3 = FUN_00409c60(local_458,&local_484);
  local_458[4] = 0x6b;
  local_458[5] = local_484;
  local_458[0] = iVar3;
  FUN_00a34330(iVar3,
               "https://submit.backtrace.io/maxis/aebdff839d0b8a4c9d1c9b79e5b58a43e5184a416b4d938f274d5aa58c2ed143/minidump"
               ,0x6b);
  *(undefined1 *)(iVar3 + 0x6b) = 0;
  DVar4 = GetModuleFileNameW((HMODULE)0x0,&local_20c,0x102);
  if ((DVar4 == 0) || (0x101 < DVar4)) {
    local_20c = L'\0';
  }
  else {
    psVar6 = &sStack_20e + DVar4;
    do {
      if ((*psVar6 == 0x2f) || (*psVar6 == 0x5c)) break;
      *psVar6 = 0;
      psVar6 = psVar6 + -1;
      DVar4 = DVar4 - 1;
    } while (DVar4 != 0);
  }
  local_458[10] = 0;
  pWVar7 = &local_20c;
  local_458[0xb] = 0;
  local_458[6] = 0;
  local_458[7] = 0;
  local_458[8] = 0;
  local_458[9] = 0;
  do {
    WVar1 = *pWVar7;
    pWVar7 = pWVar7 + 1;
  } while (WVar1 != L'\0');
  FUN_0044b220(&local_20c,(int)pWVar7 - (int)local_20a >> 1);
  FUN_004653e0(L"crashpad_handler.exe",0x14);
  GetTempPathW(0x102,&local_410);
  local_458[0x10] = 0;
  pWVar7 = &local_410;
  local_458[0x11] = 0;
  local_458[0xc] = 0;
  local_458[0xd] = 0;
  local_458[0xe] = 0;
  local_458[0xf] = 0;
  do {
    WVar1 = *pWVar7;
    pWVar7 = pWVar7 + 1;
  } while (WVar1 != L'\0');
  FUN_0044b220(&local_410,(int)pWVar7 - (int)local_40e >> 1);
  FUN_004653e0(L"TSLegacy",8);
  FUN_004661e0(local_458,local_458 + 6,local_458 + 0xc);
  local_494 = "THE_SIMS_1_PC_CLIENT";
  local_490 = "57358";
  local_48c = &DAT_00c5c89c;
  local_488 = "THE SIMS 1 LEGACY COLLECTION";
  cVar2 = FUN_006b5350(&local_494);
  if (cVar2 == '\0') {
    FUN_006b68d0();
    MessageBoxA((HWND)0x0,"The game failed to successfully launch from EA App.",
                " EA App Initialization Failed.",0);
                    /* WARNING: Subroutine does not return */
    FUN_00a6f270(0);
  }
  LOCK();
  DAT_00e33000 = DAT_00e33000 + 1;
  UNLOCK();
  _atexit((_func_4879 *)&LAB_00450e80);
  DAT_00e1d460 = FUN_00451100;
  DAT_00e1d464 = FUN_004513b0;
  DAT_00e1d37a = 1;
  FUN_0096b2c0(param_3);
  uVar5 = FUN_00961e40(local_480);
  local_480[0] = cTSCmdLine::vftable;
  FUN_009601d0();
  FUN_00448460();
  FUN_006b68d0();
  if (7 < (uint)local_458[0x11]) {
    uVar8 = local_458[0x11] * 2 + 2;
    uVar9 = local_458[0xc];
    if (0xfff < uVar8) {
      uVar9 = *(uint *)(local_458[0xc] - 4);
      uVar8 = local_458[0x11] * 2 + 0x25;
      if (0x1f < (local_458[0xc] - uVar9) - 4) goto LAB_00466992;
    }
    FUN_00a30993(uVar9,uVar8);
  }
  local_458[0x10] = 0;
  local_458[0x11] = 7;
  local_458[0xc] = local_458[0xc] & 0xffff0000;
  if (7 < (uint)local_458[0xb]) {
    uVar8 = local_458[0xb] * 2 + 2;
    uVar9 = local_458[6];
    if (0xfff < uVar8) {
      uVar9 = *(uint *)(local_458[6] - 4);
      uVar8 = local_458[0xb] * 2 + 0x25;
      if (0x1f < (local_458[6] - uVar9) - 4) goto LAB_00466992;
    }
    FUN_00a30993(uVar9,uVar8);
  }
  local_458[10] = 0;
  local_458[0xb] = 7;
  local_458[6] = local_458[6] & 0xffff0000;
  if (0xf < (uint)local_458[5]) {
    uVar8 = local_458[5] + 1;
    iVar3 = local_458[0];
    if (0xfff < uVar8) {
      iVar3 = *(int *)(local_458[0] + -4);
      uVar8 = local_458[5] + 0x24;
      if (0x1f < (local_458[0] - iVar3) - 4U) {
LAB_00466992:
                    /* WARNING: Subroutine does not return */
        FUN_00a4104b();
      }
    }
    FUN_00a30993(iVar3,uVar8);
  }
  return uVar5;
}

