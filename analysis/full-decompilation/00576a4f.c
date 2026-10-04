
void __thiscall FUN_00576a4f(int *param_1,int *param_2,uint *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar1 = *param_1;
  bVar5 = true;
  iVar4 = iVar1;
  if (*(int *)(iVar1 + 4) != 0) {
    iVar3 = *(int *)(iVar1 + 4);
    do {
      iVar4 = iVar3;
      bVar5 = *param_3 < *(uint *)(iVar4 + 0x10);
      if (bVar5) {
        iVar3 = *(int *)(iVar4 + 8);
      }
      else {
        iVar3 = *(int *)(iVar4 + 0xc);
      }
    } while (iVar3 != 0);
  }
  if (bVar5) {
    if (iVar4 == *(int *)(iVar1 + 8)) goto LAB_00576ab5;
    FUN_0042a392();
  }
  if (*param_3 <= *(uint *)(iVar4 + 0x10)) {
    *(undefined1 *)(param_2 + 1) = 0;
    *param_2 = iVar4;
    return;
  }
LAB_00576ab5:
  piVar2 = (int *)FUN_00576f49(&param_3,0,iVar4,param_3);
  *param_2 = *piVar2;
  *(undefined1 *)(param_2 + 1) = 1;
  return;
}

