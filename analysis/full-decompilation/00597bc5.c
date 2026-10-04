
void __fastcall FUN_00597bc5(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = (int *)(param_1 + 8);
  iVar3 = (*(int *)(param_1 + 0xc) - *piVar1) / 0xc;
  if (-1 < iVar3 + -1) {
    iVar4 = (iVar3 + -1) * 0xc;
    do {
      iVar2 = *(int *)(iVar4 + 8 + *piVar1);
      if (iVar2 != 0) {
        FUN_006321f0(iVar2);
        *(undefined4 *)(iVar4 + 8 + *piVar1) = 0;
      }
      FUN_00472be0(iVar4 + *piVar1);
      iVar4 = iVar4 + -0xc;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (*(int *)(param_1 + 4) != 0) {
    FUN_0059796c(param_1);
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}

