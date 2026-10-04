
void __thiscall FUN_005e4642(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  undefined4 unaff_retaddr;
  
  (**(code **)(*param_1 + 0x1a0))(0);
  if (((char)param_1[0x5b] != '\0') || ((param_1[0x55] & 1U) != 0)) {
    FUN_005e4b04(0x14);
    *(undefined1 *)(param_1 + 0x5b) = 0;
  }
  piVar2 = (int *)FUN_00492d2c();
  if (piVar2 == param_1) {
    iVar1 = param_1[0x3e];
    if (iVar1 == 0) {
      if (param_1[0x3d] == 1) goto LAB_005e46ce;
      bVar3 = false;
    }
    else {
      if (iVar1 == 1) {
        if (((char)param_1[0x5d] == '\0') || (param_1[0x3d] != 0)) goto LAB_005e46ce;
      }
      else if ((iVar1 != 2) || (param_1[0x3d] == 1)) goto LAB_005e46ce;
      bVar3 = param_1[0x38] == 0;
    }
    FUN_005e46f0(bVar3);
  }
LAB_005e46ce:
  (**(code **)(*param_1 + 0x168))();
  FUN_005dd93a(unaff_retaddr,param_2,param_3);
  return;
}

