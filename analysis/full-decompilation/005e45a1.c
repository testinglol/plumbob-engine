
void __thiscall FUN_005e45a1(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  DWORD DVar3;
  bool bVar4;
  undefined4 unaff_retaddr;
  
  (**(code **)(*param_1 + 0x1a0))(1);
  if ((char)param_1[0x5a] != '\0') {
    FUN_005e473b(4);
  }
  piVar2 = (int *)FUN_00492d2c();
  if ((piVar2 == param_1) && (iVar1 = param_1[0x3e], -1 < iVar1)) {
    if (iVar1 < 2) {
      bVar4 = true;
    }
    else {
      if (iVar1 != 2) goto LAB_005e45fa;
      bVar4 = param_1[0x38] == 0;
    }
    FUN_005e46f0(bVar4);
  }
LAB_005e45fa:
  (**(code **)(*param_1 + 0x168))();
  if (((*(byte *)(param_1 + 0x55) & 1) != 0) && ((char)param_1[0x5b] == '\0')) {
    *(undefined1 *)(param_1 + 0x5b) = 1;
    DVar3 = timeGetTime();
    param_1[0x57] = DVar3;
  }
  FUN_005dd8f5(unaff_retaddr,param_2,param_3);
  return;
}

