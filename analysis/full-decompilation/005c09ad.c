
/* WARNING: Removing unreachable block (ram,0x005c0a9f) */

void FUN_005c09ad(undefined4 *param_1)

{
  undefined8 uVar1;
  int iVar2;
  BOOL BVar3;
  HANDLE pvVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  bool bVar8;
  longlong lVar9;
  undefined4 local_78;
  int local_74 [4];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  int local_48;
  int iStack_44;
  uint local_40;
  int iStack_3c;
  LARGE_INTEGER local_38;
  LARGE_INTEGER local_30;
  undefined8 local_28;
  LARGE_INTEGER local_20;
  LARGE_INTEGER local_18;
  int local_10;
  int local_c;
  int *local_8;
  
  local_78 = 0;
  piVar7 = local_74;
  for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  BVar3 = QueryPerformanceFrequency(&local_30);
  if (BVar3 != 0) {
    local_8 = local_74;
    local_c = 3;
    do {
      pvVar4 = GetCurrentThread();
      local_10 = GetThreadPriority(pvVar4);
      lVar9 = __alldiv(local_30.s.LowPart,local_30.s.HighPart,0x14,0);
      iVar5 = 0xf;
      local_28 = lVar9;
      pvVar4 = GetCurrentThread();
      SetThreadPriority(pvVar4,iVar5);
      Sleep(0);
      QueryPerformanceCounter(&local_38);
      QueryPerformanceCounter(&local_20);
      local_28 = local_28 + CONCAT44(local_20.s.HighPart,local_20.s.LowPart);
      uVar1 = rdtsc();
      iStack_3c = (int)((ulonglong)uVar1 >> 0x20);
      local_40 = (uint)uVar1;
      do {
        BVar3 = QueryPerformanceCounter(&local_18);
        if ((BVar3 == 0) ||
           (bVar8 = (int)((local_18.s.HighPart - local_28._4_4_) -
                         (uint)(local_18.s.LowPart < (uint)local_28)) < 0,
           local_18.s.HighPart - local_28._4_4_ != (uint)(local_18.s.LowPart < (uint)local_28) &&
           !bVar8)) break;
      } while (bVar8);
      uVar1 = rdtsc();
      bVar8 = (uint)uVar1 < local_40;
      local_40 = (uint)uVar1 - local_40;
      iStack_3c = ((int)((ulonglong)uVar1 >> 0x20) - iStack_3c) - (uint)bVar8;
      iVar5 = local_10;
      pvVar4 = GetCurrentThread();
      SetThreadPriority(pvVar4,iVar5);
      uVar6 = local_18.s.LowPart - local_20._0_4_;
      iVar5 = (local_18.s.HighPart - local_20._4_4_) -
              (uint)(local_18.s.LowPart < local_20.s.LowPart);
      lVar9 = __allshr();
      piVar7 = local_8;
      if (CONCAT44(iVar5,uVar6) < lVar9) {
        iVar5 = 0;
        local_48 = 0;
      }
      else {
        local_48 = uVar6 - (uint)lVar9;
        iVar5 = (iVar5 - (int)((ulonglong)lVar9 >> 0x20)) - (uint)(uVar6 < (uint)lVar9);
      }
      iVar2 = local_48;
      iStack_44 = iVar5;
      local_8[-1] = local_40;
      *piVar7 = iVar2;
      if (iVar2 != 0 || iVar5 != 0) {
        iVar5 = __ftol();
        piVar7 = local_8;
        local_8[2] = iVar5;
        piVar7[1] = iVar5;
      }
      local_8 = local_8 + 4;
      local_c = local_c + -1;
    } while (local_c != 0);
    FUN_005c0bdd(&local_78,&local_48,param_1);
  }
  *param_1 = local_74[3];
  param_1[1] = uStack_64;
  param_1[2] = uStack_60;
  param_1[3] = uStack_5c;
  return;
}

