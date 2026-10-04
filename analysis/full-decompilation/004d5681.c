
undefined4 __thiscall FUN_004d5681(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1[0x35] != 0) {
    uVar3 = FUN_005dd7f2(param_2,param_3,param_4);
    return uVar3;
  }
  iVar4 = param_1[0x36];
  bVar1 = (param_1[0x21] - param_1[0x1f]) - iVar4 <= param_2;
  param_1[0x35] = 1;
  bVar2 = (param_1[0x22] - param_1[0x20]) - iVar4 <= param_3;
  param_1[0x39] = param_1[0x1f] + param_2;
  param_1[0x37] = param_1[0x1f] + param_2;
  param_1[0x3a] = param_1[0x20] + param_3;
  param_1[0x38] = param_1[0x20] + param_3;
  if ((((param_2 < iVar4) || (bVar1)) || (param_3 < iVar4)) || (bVar2)) {
    *(undefined1 *)((int)param_1 + 0xef) = 0;
    *(undefined1 *)(param_1 + 0x3b) = 0;
    *(undefined1 *)((int)param_1 + 0xee) = 0;
    *(undefined1 *)((int)param_1 + 0xed) = 0;
    if (param_2 < iVar4) {
      *(undefined1 *)((int)param_1 + 0xed) = 1;
    }
    else if (bVar1) {
      *(undefined1 *)((int)param_1 + 0xee) = 1;
    }
    if (param_3 >= iVar4) {
      if (bVar2) {
        *(undefined1 *)((int)param_1 + 0xef) = 1;
      }
      goto LAB_004d578f;
    }
  }
  else {
    *(undefined1 *)((int)param_1 + 0xee) = 1;
    *(undefined1 *)((int)param_1 + 0xed) = 1;
    *(undefined1 *)((int)param_1 + 0xef) = 1;
  }
  *(undefined1 *)(param_1 + 0x3b) = 1;
LAB_004d578f:
  iVar4 = FUN_00492d2c();
  if (iVar4 != 0) {
    FUN_005d9912(iVar4);
  }
  FUN_005d98fc(param_1);
  (**(code **)(*param_1 + 0xfc))(param_2,param_3,param_4);
  return 1;
}

