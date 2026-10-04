
void __fastcall FUN_004ffc30(int *param_1)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = param_1[0x40];
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      FUN_004ffb27(param_1 + 0x1f,param_1[0x42] + 0x7c);
      param_1[0x40] = 2;
    }
    else if (iVar1 == 3) {
      FUN_004ffb27(param_1 + 0x43,param_1 + 0x36);
      param_1[0x40] = 4;
    }
    else if (iVar1 == 5) {
      FUN_004ffb27(param_1 + 0x43,param_1 + 0x36);
      param_1[0x40] = 6;
    }
    iVar1 = param_1[0x40];
    if (iVar1 == 2) {
      DVar2 = timeGetTime();
      if ((uint)param_1[0x4a] <= DVar2) {
        (**(code **)(*param_1 + 0x98))();
        param_1[0x40] = 0;
        if ((int *)param_1[0x42] != (int *)0x0) {
          (**(code **)(*(int *)param_1[0x42] + 0x94))();
        }
        param_1[0x42] = 0;
      }
    }
    else if (iVar1 == 4) {
      DVar2 = timeGetTime();
      if ((uint)param_1[0x4a] <= DVar2) {
        (**(code **)(*param_1 + 0x60))(param_1[0x36],param_1[0x37],param_1[0x38],param_1[0x39]);
        param_1[0x40] = 0;
      }
    }
    else if (iVar1 == 6) {
      DVar2 = timeGetTime();
      if ((uint)param_1[0x4a] <= DVar2) {
        (**(code **)(*param_1 + 0x60))(param_1[0x36],param_1[0x37],param_1[0x38],param_1[0x39]);
        param_1[0x40] = 1;
      }
    }
    if (param_1[0x40] != 0) {
      FUN_004ffbc4(&local_14);
      (**(code **)(*param_1 + 0x60))(local_14,local_10,local_c,local_8);
    }
  }
  return;
}

