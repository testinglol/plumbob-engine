
void __fastcall FUN_005f6230(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1[0x37] == param_1[0x36]) {
    iVar2 = param_1[0x39];
  }
  else {
    iVar1 = param_1[0x39];
    iVar2 = __ftol();
    iVar2 = iVar2 + iVar1;
  }
  param_1[0x3a] = iVar2;
  if (param_1[0x35] == 1) {
    param_1[0x3d] = iVar2;
    iVar2 = (**(code **)(*param_1 + 0x1cc))();
    param_1[0x3f] = iVar2 + param_1[0x3d];
    iVar2 = (**(code **)(*param_1 + 0x1d0))();
    param_1[0x3e] = (param_1[0x22] - param_1[0x20]) / 2 - iVar2 / 2;
    iVar2 = (**(code **)(*param_1 + 0x1d0))();
    iVar2 = iVar2 + param_1[0x3e];
  }
  else {
    iVar2 = (**(code **)(*param_1 + 0x1cc))();
    param_1[0x3d] = (param_1[0x21] - param_1[0x1f]) / 2 - iVar2 / 2;
    iVar2 = (**(code **)(*param_1 + 0x1cc))();
    param_1[0x3f] = iVar2 + param_1[0x3d];
    param_1[0x3e] = param_1[0x3a];
    iVar2 = (**(code **)(*param_1 + 0x1d0))();
    iVar2 = iVar2 + param_1[0x3e];
  }
  param_1[0x40] = iVar2;
  return;
}

