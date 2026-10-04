
void __fastcall FUN_005f6fb7(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1[0x35] == 1) {
    iVar1 = (**(code **)(*param_1 + 0x1dc))();
    param_1[0x39] = iVar1;
    iVar1 = (**(code **)(*param_1 + 0x1dc))();
    iVar1 = (param_1[0x21] - param_1[0x1f]) - iVar1;
    iVar2 = (**(code **)(*param_1 + 0x1cc))();
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x1e0))();
    param_1[0x39] = iVar1;
    iVar1 = (**(code **)(*param_1 + 0x1e0))();
    iVar1 = (param_1[0x22] - param_1[0x20]) - iVar1;
    iVar2 = (**(code **)(*param_1 + 0x1d0))();
  }
  param_1[0x3b] = iVar1 - iVar2;
  (**(code **)(*param_1 + 0x1c4))();
  return;
}

