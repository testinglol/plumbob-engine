
undefined4 __thiscall FUN_005f58eb(int param_1,char param_2)

{
  int iVar1;
  char cVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  int local_c;
  uint local_8;
  
  cVar2 = FUN_0063813a((int)param_2);
  local_8 = 0xffffffff;
  uVar5 = 0;
  local_c = 0x7fffffff;
  if (*(int *)(param_1 + 0xd8) - *(int *)(param_1 + 0xd4) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0xd4) + uVar5 * 4);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x50) != *(int *)(iVar1 + 0x4c))) {
        cVar3 = FUN_0063813a((int)**(char **)(iVar1 + 0x4c));
        if (cVar3 == cVar2) goto LAB_005f597d;
        if ((cVar3 < cVar2) && ((int)cVar2 - (int)cVar3 <= local_c)) {
          local_c = (int)cVar2 - (int)cVar3;
          local_8 = uVar5;
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)(*(int *)(param_1 + 0xd8) - *(int *)(param_1 + 0xd4) >> 2));
    uVar5 = local_8;
    if (local_8 != 0xffffffff) {
LAB_005f597d:
      FUN_005f5543(uVar5);
      return 1;
    }
  }
  uVar4 = FUN_005dd715(cVar2);
  return uVar4;
}

