
void __thiscall FUN_0044822b(int param_1,int *param_2)

{
  int iVar1;
  int *local_98;
  int *local_60;
  int local_1c;
  int *local_8;
  
  if ((param_2 != (int *)0x0) && (*(char *)(param_1 + 0x11) != '\0')) {
    iVar1 = FUN_0045741b();
    if (*(short *)(param_2[0x46] + 0x12) == 2) {
      if ((param_2[0x4d] - param_2[0x4c]) / 0x24 + -1 < 2) {
        local_1c = 0;
      }
      else {
        local_1c = param_2[0x4c] + 0x48;
      }
      if (local_1c == 0) {
        local_98 = (int *)0x0;
      }
      else {
        local_98 = (int *)FUN_00407498((int)*(short *)(local_1c + 0x10));
      }
      local_8 = local_98;
    }
    else {
      local_8 = param_2;
    }
    if (local_8 != (int *)0x0) {
      if (iVar1 == -0x16cc8fe0) {
        for (local_60 = *(int **)(param_1 + 0xd0);
            (local_60 != *(int **)(param_1 + 0xd4) && ((int *)*local_60 != local_8));
            local_60 = local_60 + 1) {
        }
        if (local_60 != *(int **)(param_1 + 0xd4)) {
          FUN_0044845a(local_60);
          FUN_004486a3(local_60);
        }
      }
      else if ((iVar1 != 0xbaa71c5) && (iVar1 != 0x2f726fff)) {
        return;
      }
      (**(code **)(*local_8 + 0x50))(0);
    }
  }
  return;
}

