
void __thiscall FUN_004761b4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_10;
  int local_c;
  short local_8;
  short local_6;
  
  iVar2 = 0;
  if ((short)param_3 == 0) {
    FUN_00464973(param_1 + 2,1);
    FUN_00464973((int)&param_3 + 2,1);
    if (0 < param_3._2_2_) {
      do {
        FUN_00464973(&local_6,1);
        FUN_00464973(&local_8,1);
        iVar1 = *(int *)(param_1 + 8) + local_6 * 6;
        iVar2 = iVar2 + 1;
        *(short *)(iVar1 + 4) = local_8 - *(short *)(iVar1 + 2);
      } while (iVar2 < param_3._2_2_);
    }
  }
  else if ((short)param_3 == 1) {
    FUN_00464973(param_1 + 2,1);
    FUN_00464973(param_1,1);
    FUN_00464973((int)&param_3 + 2,1);
    if (0 < param_3._2_2_) {
      do {
        FUN_00464973(&local_8,1);
        FUN_00464973(&local_6,1);
        iVar1 = *(int *)(param_1 + 8) + local_8 * 6;
        iVar2 = iVar2 + 1;
        *(short *)(iVar1 + 4) = local_6 - *(short *)(iVar1 + 2);
      } while (iVar2 < param_3._2_2_);
    }
  }
  else if ((short)param_3 == 2) {
    FUN_00464973(param_1 + 2,1);
    FUN_00464973(param_1,1);
    FUN_00464973((int)&param_3 + 2,1);
    FUN_00464b48(&local_10,1);
    *(undefined4 *)(param_1 + 0x10) = local_10;
    *(undefined4 *)(param_1 + 0xc) = 0;
    FUN_00464973(&local_6,1);
    if (0 < param_3._2_2_) {
      local_c = 0;
      do {
        FUN_00464973(&local_8,1);
        if (iVar2 < *(int *)(param_1 + 4)) {
          iVar1 = *(int *)(param_1 + 8) + local_c;
          *(short *)(iVar1 + 4) = local_8 - *(short *)(iVar1 + 2);
        }
        local_c = local_c + 6;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_3._2_2_);
    }
  }
  else if ((short)param_3 == 3) {
    FUN_00464973(param_1 + 2,1);
    FUN_00464973(param_1,1);
    FUN_00464973((int)&param_3 + 2,1);
    FUN_00464973(&local_8,1);
    *(int *)(param_1 + 0x14) = (int)local_8;
    FUN_00464b48(&local_10,1);
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = local_10;
    if (0 < param_3._2_2_) {
      local_c = 0;
      do {
        FUN_00464973(&local_6,1);
        if (iVar2 < *(int *)(param_1 + 4)) {
          iVar1 = *(int *)(param_1 + 8) + local_c;
          *(short *)(iVar1 + 4) = local_6 - *(short *)(iVar1 + 2);
        }
        local_c = local_c + 6;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_3._2_2_);
    }
  }
  else if ((short)param_3 == 4) {
    FUN_00464973(param_1 + 2,1);
    FUN_00464973(param_1,1);
    FUN_00464973((int)&param_3 + 2,1);
    FUN_00464a4e(param_1 + 0x14,1);
    FUN_00464a4e(param_1 + 0x18,1);
    FUN_00464b48(&local_10,1);
    *(undefined4 *)(param_1 + 0x10) = local_10;
    *(undefined4 *)(param_1 + 0xc) = 0;
    FUN_00464a4e(param_1 + 0x1c,1);
    if (0 < param_3._2_2_) {
      local_c = 0;
      do {
        FUN_00464973(&local_8,1);
        if (iVar2 < *(int *)(param_1 + 4)) {
          iVar1 = *(int *)(param_1 + 8) + local_c;
          *(short *)(iVar1 + 4) = local_8 - *(short *)(iVar1 + 2);
        }
        local_c = local_c + 6;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_3._2_2_);
    }
  }
  else if ((short)param_3 == 5) {
    FUN_00464973(param_1 + 2,1);
    FUN_00464973(param_1,1);
    FUN_00464973((int)&param_3 + 2,1);
    FUN_00464a4e(param_1 + 0x14,1);
    FUN_00464a4e(param_1 + 0x18,1);
    FUN_00464b48(&local_10,1);
    *(undefined4 *)(param_1 + 0x10) = local_10;
    *(undefined4 *)(param_1 + 0xc) = 0;
    FUN_00464a4e(param_1 + 0x1c,1);
    FUN_00464a4e(param_1 + 0x20,1);
    if (0 < param_3._2_2_) {
      local_c = 0;
      do {
        FUN_00464973(&local_8,1);
        if (iVar2 < *(int *)(param_1 + 4)) {
          iVar1 = *(int *)(param_1 + 8) + local_c;
          *(short *)(iVar1 + 4) = local_8 - *(short *)(iVar1 + 2);
        }
        local_c = local_c + 6;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_3._2_2_);
    }
  }
  return;
}

