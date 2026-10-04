
void __fastcall FUN_005f61b3(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1[0x35] == 1) {
    param_1[0x39] = param_1[0x3c];
    iVar1 = (**(code **)(*param_1 + 0x1cc))();
    param_1[0x3b] = ((param_1[0x21] - param_1[0x1f]) - param_1[0x3c]) - iVar1;
  }
  else {
    iVar1 = param_1[0x3c];
    iVar2 = (**(code **)(*param_1 + 0x1d0))();
    param_1[0x3b] = iVar1;
    param_1[0x39] = ((param_1[0x22] - param_1[0x20]) - iVar1) - iVar2;
  }
  (**(code **)(*param_1 + 0x1c4))();
  (**(code **)(*param_1 + 0x168))();
  return;
}

