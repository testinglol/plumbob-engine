
undefined1 __fastcall FUN_005dd61d(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x184))();
  if (iVar2 != 0) {
    piVar3 = (int *)(**(code **)(*param_1 + 0x18))();
    param_1[0x23] = param_1[0x1f];
    param_1[0x24] = param_1[0x20];
    param_1[0x25] = param_1[0x21];
    param_1[0x26] = param_1[0x22];
    for (; piVar3 != (int *)0x0; piVar3 = (int *)(**(code **)(*piVar3 + 0x18))()) {
      iVar2 = (**(code **)(*piVar3 + 0x184))();
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = piVar3[0x20];
      iVar1 = piVar3[0x1f];
      param_1[0x23] = param_1[0x23] + iVar1;
      param_1[0x25] = param_1[0x25] + iVar1;
      param_1[0x24] = param_1[0x24] + iVar2;
      param_1[0x26] = param_1[0x26] + iVar2;
    }
  }
  return 0;
}

