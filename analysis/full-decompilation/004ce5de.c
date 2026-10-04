
void __fastcall FUN_004ce5de(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  undefined2 extraout_var_10;
  undefined2 extraout_var_11;
  undefined2 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  uVar4 = (undefined2)((uint)param_2 >> 0x10);
  if ((*(int *)(DAT_006f2a08 + 0x90) != 0) && (*(char *)(DAT_006f2a08 + 0xf5) == '\0')) {
    return;
  }
  if (*(char *)(DAT_006f2a08 + 0xf8) != '\0') {
    return;
  }
  if ((param_3 & 2) != 0) {
    FUN_004abb9e(*(undefined1 *)(*(int *)(param_1 + 0x1f0) + 0x1f8));
    iVar1 = *(int *)(param_1 + 8);
    uVar4 = extraout_var;
    if (iVar1 != 3) {
      if ((iVar1 == 2) || (iVar1 == 4)) {
        uVar6 = 0;
      }
      else {
        uVar6 = 1;
      }
      FUN_004c440c(uVar6);
      uVar4 = extraout_var_00;
    }
    if (*(int *)(param_1 + 8) == 2) {
      if (*(char *)(param_1 + 0x40) == '\0') {
        FUN_0057ab8e();
        uVar4 = extraout_var_02;
      }
    }
    else {
      FUN_0057aa9d();
      uVar4 = extraout_var_01;
    }
  }
  if ((param_3 & 0x1000) != 0) {
    FUN_004a7da6(*(undefined4 *)(param_1 + 0x34),0,1);
    FUN_0057ac7f();
    uVar4 = extraout_var_03;
  }
  if ((param_3 & 0x800) != 0) {
    FUN_004a8012(*(undefined4 *)(param_1 + 0x38),0,1);
    uVar4 = extraout_var_04;
  }
  if ((param_3 & 0x100) != 0) {
    FUN_004a82db(*(undefined4 *)(param_1 + 0x3c),0);
    uVar4 = extraout_var_05;
  }
  if ((param_3 & 0x42) != 0) {
    iVar1 = *(int *)(DAT_006e486c + 0x1c);
    iVar3 = *(int *)(param_1 + 8);
    if (iVar3 == 0) {
      *(undefined2 *)(iVar1 + 0x36) = 1;
    }
    else if (iVar3 == 1) {
      *(undefined2 *)(iVar1 + 0x36) = 2;
    }
    else if (iVar3 == 2) {
      *(undefined2 *)(iVar1 + 0x36) = 0;
    }
    else if (iVar3 == 3) {
      *(undefined2 *)(iVar1 + 0x36) = 3;
    }
    else if (iVar3 == 4) {
      *(undefined2 *)(iVar1 + 0x36) = 4;
    }
    if ((param_3 & 0x40) != 0) {
      iVar1 = *(int *)(param_1 + 0x44);
      iVar3 = FUN_0046d8a7();
      uVar4 = extraout_var_06;
      if (iVar3 != iVar1) {
        FUN_0046d7b3(iVar1);
        uVar4 = extraout_var_07;
      }
    }
  }
  if (((param_3 & 0x800000) != 0) && (*(int *)(param_1 + 8) == 2)) {
    if (*(char *)(param_1 + 0x40) == '\0') {
      FUN_0046d956();
      FUN_0057ab8e();
      uVar4 = extraout_var_09;
    }
    else {
      FUN_0046d92f();
      FUN_0057aa9d();
      uVar4 = extraout_var_08;
    }
  }
  if ((param_3 & 0x80) == 0) goto LAB_004ce7d6;
  iVar1 = *(int *)(param_1 + 0x48);
  uVar6 = 1;
  if (iVar1 == 1) {
    uVar6 = 0;
LAB_004ce785:
    FUN_004a8361(uVar6);
    uVar6 = 0;
LAB_004ce7b5:
    FUN_004a8392(uVar6);
    uVar6 = 0;
  }
  else {
    if (iVar1 == 2) goto LAB_004ce785;
    if (iVar1 == 4) {
      FUN_004a8361(0);
      uVar6 = 1;
      goto LAB_004ce7b5;
    }
    FUN_004a8361(0);
    FUN_004a8392(0);
    uVar6 = 1;
  }
  FUN_004b1668(uVar6,0);
  uVar4 = extraout_var_10;
LAB_004ce7d6:
  if (((param_3 & 0x630) != 0) && (*(int *)(param_1 + 0x60) == 0)) {
    iVar1 = *(int *)(param_1 + 0x4c);
    if (iVar1 == 0) {
      FUN_00476bac(0);
    }
    else {
      if (DAT_006e54ac != iVar1) {
        FUN_00476bac(iVar1);
        uVar4 = extraout_var_11;
      }
      (**(code **)(**(int **)(param_1 + 0x4c) + 0x30))
                (CONCAT22(uVar4,*(undefined2 *)(param_1 + 0x50)));
    }
  }
  if ((param_3 & 8) != 0) {
    FUN_004e99d7(*(undefined4 *)(param_1 + 0x1ec));
  }
  if ((param_3 & 2) == 0) {
    return;
  }
  if ((*(int *)(DAT_006f2a08 + 0x90) != 0) && (*(char *)(DAT_006f2a08 + 0xf5) == '\0')) {
    return;
  }
  FUN_0057a9a6(0xffffffff);
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 2) {
    pcVar5 = s_bkground_live_006c7ad8;
  }
  else if (iVar1 == 1) {
    if (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 1) {
      cVar2 = FUN_00407525();
      if (cVar2 == '\0') {
        cVar2 = FUN_004ce974();
        if (cVar2 == '\0') {
          cVar2 = FUN_0040750e();
          if (cVar2 == '\0') {
            cVar2 = FUN_0042886f();
            if (cVar2 == '\0') {
              pcVar5 = s_station_dtbuy_006c7a7c;
            }
            else {
              pcVar5 = s_music_magictown_006c7a8c;
            }
          }
          else {
            pcVar5 = s_station_superstar_006c7a9c;
          }
        }
        else {
          pcVar5 = s_station_unleashed_006c7ab0;
        }
      }
      else {
        pcVar5 = s_station_vacation_006c7ac4;
      }
    }
    else {
      cVar2 = FUN_004ce994();
      if (cVar2 == '\0') {
        pcVar5 = s_bkground_buy1_006c7a58;
      }
      else {
        pcVar5 = s_music_magictown_buy_006c7a68;
      }
    }
  }
  else {
    if (iVar1 != 0) {
      if (iVar1 == 4) {
        pcVar5 = s_bkground_camera_006c7a20;
      }
      else {
        if (iVar1 != 3) {
          return;
        }
        pcVar5 = s_bkground_option_006c7a10;
      }
      FUN_0057a7f7(pcVar5,0xffffffff);
      FUN_004d25a5(0);
      return;
    }
    if (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) != 0) {
      return;
    }
    cVar2 = FUN_004ce994();
    if (cVar2 == '\0') {
      pcVar5 = s_bkground_build_006c7a30;
    }
    else {
      pcVar5 = s_music_magictown_build_006c7a40;
    }
  }
  FUN_0057a7f7(pcVar5,0xffffffff);
  return;
}

