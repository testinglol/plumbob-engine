
void __fastcall FUN_004ffd9a(int *param_1)

{
  int iVar1;
  int iVar2;
  
  param_1[0x40] = 0;
  param_1[0x43] = -1;
  param_1[0x44] = -1;
  param_1[0x45] = -1;
  param_1[0x46] = -1;
  if (*(int *)(*DAT_006e486c + 0x14) == 0) {
    iVar2 = *param_1;
  }
  else {
    iVar1 = FUN_00444bf6();
    iVar2 = *param_1;
    if (iVar1 != 0) {
      (**(code **)(iVar2 + 0x94))();
      FUN_004ff8c3(**(undefined4 **)(iVar1 + 0x11c),300);
      (**(code **)(*param_1 + 0x60))(param_1[0x36],param_1[0x37],param_1[0x38],param_1[0x39]);
      return;
    }
  }
  (**(code **)(iVar2 + 0x98))();
  return;
}

