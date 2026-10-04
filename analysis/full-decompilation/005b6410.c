
/* WARNING: Removing unreachable block (ram,0x005b6533) */

int FUN_005b6410(void)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  code *pcVar8;
  int iVar9;
  bool bVar10;
  longlong lVar11;
  int local_4c;
  int local_48;
  int local_44;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  LARGE_INTEGER local_28;
  LARGE_INTEGER local_20;
  LARGE_INTEGER local_18;
  uint local_10;
  int local_c;
  LARGE_INTEGER local_8;
  
  local_48 = 0;
  local_4c = 0;
  QueryPerformanceFrequency(&local_8);
  local_44 = 0;
  local_8.s.HighPart = (int)local_8.s.LowPart >> 0x1f;
  do {
    pcVar8 = QueryPerformanceCounter_exref;
    local_38 = 1000000;
    local_34 = 0;
    local_28.s.LowPart = 0;
    QueryPerformanceCounter(&local_28);
    uVar6 = local_28.s.HighPart;
    uVar5 = local_28.s.LowPart;
    do {
      local_20.s.LowPart = 0;
      QueryPerformanceCounter(&local_20);
      if ((local_20.s.LowPart == uVar5) && (local_20.s.HighPart == uVar6)) {
        bVar10 = local_38 != 0;
        local_38 = local_38 + -1;
        local_34 = local_34 + -1 + (uint)bVar10;
        if (local_38 == 0 && local_34 == 0) break;
      }
      uVar1 = (uint)(local_20.s.LowPart < (uint)uVar5);
      uVar2 = local_20.s.HighPart - uVar6;
    } while (((int)(uVar2 - uVar1) < 0) ||
            ((uVar2 == uVar1 || SBORROW4(local_20.s.HighPart,uVar6) != SBORROW4(uVar2,uVar1) &&
             (local_20.s.LowPart == uVar5))));
    uVar3 = rdtsc();
    local_30 = 1000000;
    local_2c = 0;
    local_18.s.LowPart = 0;
    QueryPerformanceCounter(&local_18);
    uVar6 = local_18.s.HighPart;
    uVar5 = local_18.s.LowPart;
    do {
      local_10 = 0;
      (*pcVar8)(&local_10);
      if ((local_10 == uVar5) && (local_c == uVar6)) {
        bVar10 = local_30 != 0;
        local_30 = local_30 + -1;
        local_2c = local_2c + -1 + (uint)bVar10;
        if (local_30 == 0 && local_2c == 0) break;
      }
      bVar10 = local_10 < (uint)uVar5;
      iVar9 = local_10 - uVar5;
      iVar7 = local_c - uVar6;
      lVar11 = __alldiv(local_8.s.LowPart,local_8.s.HighPart,5,0);
      pcVar8 = QueryPerformanceCounter_exref;
    } while (CONCAT44(iVar7 - (uint)bVar10,iVar9) < lVar11);
    uVar4 = rdtsc();
    iVar7 = (int)uVar4 - (int)uVar3;
    if (local_44 != 0) {
      if ((iVar7 < local_48) || (local_48 == 0)) {
        local_4c = local_48;
        local_48 = iVar7;
      }
      else if ((iVar7 < local_4c) || (local_4c == 0)) {
        local_4c = iVar7;
      }
    }
    local_44 = local_44 + 1;
    if (4 < local_44) {
      if (local_4c == 0) {
        local_4c = local_48;
      }
      iVar7 = local_4c * 5;
      if (SBORROW4(iVar7,local_4c) != local_4c * 4 < 0) {
        iVar7 = -1;
      }
      return iVar7;
    }
  } while( true );
}

