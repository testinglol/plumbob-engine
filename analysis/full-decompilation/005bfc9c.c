
int __thiscall FUN_005bfc9c(int *param_1,short param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint local_8;
  
  iVar1 = *param_1;
  iVar2 = param_1[1] - iVar1 >> 1;
  iVar5 = DAT_00672b94;
  if (iVar2 != 0) {
    local_8 = iVar2 - 1;
    puVar3 = &param_3;
    if (local_8 <= param_3) {
      puVar3 = &local_8;
    }
    iVar2 = iVar1 + 2 + *puVar3 * 2;
    do {
      iVar4 = iVar2;
      if (iVar4 == iVar1) break;
      iVar2 = iVar4 + -2;
    } while (*(short *)(iVar4 + -2) != param_2);
    if (iVar4 != iVar1) {
      iVar5 = (iVar4 - iVar1) + -2 >> 1;
    }
  }
  return iVar5;
}

