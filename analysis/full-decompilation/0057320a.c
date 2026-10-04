
undefined4 FUN_0057320a(int param_1,int *param_2,int *param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_1 < 1) {
    *param_2 = 0x400;
    *param_3 = 0x200;
  }
  else {
    FUN_00570d5f();
    cVar1 = FUN_00570f1d(param_1,&local_28);
    if (((cVar1 != '\0') && (local_28 != 0)) && (local_24 != 0)) {
      FUN_00570f5d(&local_28,&local_14);
      FUN_00570d77(&local_1c);
      local_8 = thunk_FUN_004a696f();
      param_1 = 0x14;
      local_c = local_20;
      if (param_4 != (int *)0x0) {
        param_1 = (**(code **)(*param_4 + 0x88))(0x39);
      }
      *param_3 = 0x200;
      if (param_1 != 0) {
        iVar2 = ((local_14 - local_1c / 2) * 0xc00) / ((local_1c * 100) / 2) + 0x200;
        *param_3 = iVar2;
        if (0x3ff < iVar2) {
          iVar2 = 0x400;
        }
        *param_3 = iVar2;
        if (iVar2 < 1) {
          iVar2 = 0;
        }
        *param_3 = iVar2;
      }
      iVar2 = thunk_FUN_004a694e();
      iVar4 = 0;
      if (param_1 == 0x2711) {
        iVar4 = 800;
      }
      param_3 = (int *)((3 - iVar2) * param_1 * -0xe + 0x400);
      *param_2 = (int)param_3;
      if ((int)param_3 < 1) {
        param_3 = (int *)0x0;
      }
      *param_2 = (int)param_3;
      if ((int)param_3 <= iVar4) {
        param_3 = (int *)iVar4;
      }
      *param_2 = (int)param_3;
      iVar2 = (local_1c * 0x14) / 100;
      if (local_14 < iVar2) {
        iVar2 = iVar2 - local_14;
      }
      else {
        iVar2 = (iVar2 - local_1c) + local_14;
      }
      iVar3 = local_10 - local_18;
      if ((iVar3 < 1) && (iVar3 = (local_18 * 0x1e) / 100 - local_10, iVar3 < 1)) {
        iVar3 = 0;
      }
      if (iVar2 <= iVar3) {
        iVar2 = iVar3;
      }
      if ((iVar2 != 0) && (param_1 != 0)) {
        if (iVar2 < 600) {
          iVar2 = (((int)param_3 - iVar4) * (600 - iVar2)) / 600 + iVar4;
          *param_2 = iVar2;
          if (iVar2 < iVar4) {
            iVar2 = iVar4;
          }
          *param_2 = iVar2;
          if (0x400 < iVar2) {
            iVar2 = 0x400;
          }
          *param_2 = iVar2;
        }
        else {
          *param_2 = iVar4;
        }
      }
      if ((local_c != local_8) && (param_1 != 0)) {
        *param_2 = (*param_2 * 3) / 5;
      }
      return 1;
    }
  }
  return 0;
}

