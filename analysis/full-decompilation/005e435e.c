
undefined4 __thiscall
FUN_005e435e(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  DWORD DVar4;
  bool bVar5;
  
  if ((char)param_1[0x5a] == '\0') {
    FUN_005e473b(8);
    uVar3 = FUN_005dd76b(param_2,param_3,param_4);
    return uVar3;
  }
  FUN_005e473b(1);
  FUN_005d98fc(param_1);
  iVar1 = param_1[0x3e];
  iVar2 = param_1[0x38];
  if (-1 < iVar1) {
    if (iVar1 < 2) {
      bVar5 = true;
    }
    else {
      if (iVar1 != 2) goto LAB_005e43cc;
      bVar5 = iVar2 == 0;
    }
    FUN_005e46f0(bVar5);
  }
LAB_005e43cc:
  *(bool *)(param_1 + 0x5d) = param_1[0x38] != iVar2;
  (**(code **)(*param_1 + 0x1b0))();
  if ((param_1[0x3d] == 1) || (param_1[0x3d] == 2)) {
    DAT_006fe954 = param_1;
    FUN_005e4b04(1);
  }
  (**(code **)(*param_1 + 0x168))();
  if ((param_1[0x55] & 6U) == 0) {
    if ((char)param_1[0x5b] != '\0') {
      *(undefined1 *)(param_1 + 0x5b) = 0;
    }
  }
  else {
    DVar4 = timeGetTime();
    param_1[0x57] = DVar4;
    *(undefined1 *)(param_1 + 0x5b) = 1;
  }
  return 1;
}

