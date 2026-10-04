
void __thiscall FUN_005e843d(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *param_1;
  bVar2 = true;
  iVar5 = iVar1;
  if (*(int *)(iVar1 + 4) != 0) {
    iVar4 = *(int *)(iVar1 + 4);
    do {
      iVar5 = iVar4;
      bVar2 = *param_3 < *(int *)(iVar5 + 0x10);
      if (bVar2) {
        iVar4 = *(int *)(iVar5 + 8);
      }
      else {
        iVar4 = *(int *)(iVar5 + 0xc);
      }
    } while (iVar4 != 0);
  }
  if (bVar2) {
    if (iVar5 == *(int *)(iVar1 + 8)) goto LAB_005e84a3;
    FUN_0042a392();
  }
  if (*param_3 <= *(int *)(iVar5 + 0x10)) {
    *(undefined1 *)(param_2 + 1) = 0;
    *param_2 = iVar5;
    return;
  }
LAB_005e84a3:
  piVar3 = (int *)FUN_005e8509(&param_3,0,iVar5,param_3);
  *param_2 = *piVar3;
  *(undefined1 *)(param_2 + 1) = 1;
  return;
}

