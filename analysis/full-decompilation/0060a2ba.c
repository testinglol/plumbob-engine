
int __thiscall FUN_0060a2ba(int *param_1,byte *param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  int local_14;
  uint local_10;
  bool local_5;
  
  if ((param_3 < 1) || (local_14 = FUN_00609af3(param_2), local_14 == 0)) {
    local_14 = 0;
  }
  else {
    local_10 = 0;
    iVar3 = local_14;
    if (0 < local_14) {
      do {
        local_10 = local_10 << 8 | (uint)*param_2;
        param_2 = param_2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_00608d3f(local_10);
    iVar3 = FUN_00608dcd(local_10);
    bVar1 = 1 < local_14;
    bVar7 = local_10 < 0x20;
    if (local_14 < param_3) {
      while( true ) {
        local_5 = iVar3 == 0;
        iVar4 = FUN_00609af3(param_2);
        if (iVar4 == 0) break;
        uVar6 = 0;
        iVar3 = iVar4;
        if (0 < iVar4) {
          do {
            uVar6 = uVar6 << 8 | (uint)*param_2;
            param_2 = param_2 + 1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        iVar5 = FUN_00608d3f(uVar6);
        iVar3 = FUN_00608dcd(uVar6);
        if ((bVar7) || (uVar6 < 0x20)) break;
        if ((iVar5 == 0) && (local_5)) {
          if ((bVar1) || (1 < iVar4)) break;
          cVar2 = (**(code **)(*param_1 + 0x30))((int)(char)local_10);
          if ((cVar2 != '\0') &&
             (cVar2 = (**(code **)(*param_1 + 0x30))((int)(char)uVar6), cVar2 == '\0')) break;
        }
        local_14 = local_14 + iVar4;
        bVar7 = false;
        local_10 = uVar6;
        bVar1 = 1 < iVar4;
        if (param_3 <= local_14) break;
      }
    }
    if (param_3 < local_14) {
      local_14 = param_3;
    }
  }
  return local_14;
}

