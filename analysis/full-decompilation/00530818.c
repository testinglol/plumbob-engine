
undefined4 __thiscall FUN_00530818(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (param_2 == 1) {
    for (piVar5 = *(int **)(param_1 + 0xdc);
        (piVar5 != *(int **)(param_1 + 0xe0) && (*piVar5 != param_3)); piVar5 = piVar5 + 1) {
    }
    if (piVar5 != *(int **)(param_1 + 0xe0)) {
      param_2 = 0;
      iVar4 = (int)piVar5 - (int)*(int **)(param_1 + 0xdc) >> 2;
      if (0 < (int)(*(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc) & 0xfffffffcU)) {
        do {
          FUN_005e46f0(iVar4 == param_2);
          param_2 = param_2 + 1;
        } while (param_2 < *(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc) >> 2);
      }
      iVar3 = *(int *)(*(int *)(param_1 + 0xf4) + 0x158);
      if (iVar3 == 0) {
        return 1;
      }
      if (*(int *)(param_1 + 0x134) == 0) {
        return 1;
      }
      FUN_00503993(s_skill_006c4de0);
      if (*(char *)(iVar3 + 0xe0) == '\0') {
        *(int *)(*(int *)(param_1 + 0x134) + 0x14) = *piVar5;
        FUN_00510747(*(undefined4 *)(*(int *)(param_1 + 0x104) + iVar4 * 0xc));
        FUN_00510775(*(undefined4 *)(*(int *)(param_1 + 0x110) + iVar4 * 0xc));
        FUN_00510489(0,0);
        if (*(int *)(&DAT_006f4240 + iVar4 * 8) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = FUN_0043acf5(*(int *)(&DAT_006f4240 + iVar4 * 8));
        }
        FUN_005103e6(0,uVar2);
        if (*(int *)(&DAT_006f4244 + iVar4 * 8) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = FUN_0043acf5(*(int *)(&DAT_006f4244 + iVar4 * 8));
        }
        FUN_005103e6(1,uVar2);
        uVar2 = *(undefined4 *)(param_1 + 0x134);
LAB_00530b2d:
        FUN_0050fb20(uVar2,param_1);
        return 1;
      }
      if (*(int *)(*(int *)(iVar3 + 0x10c) + 0x14) == *piVar5) {
LAB_00530adc:
        FUN_0050fc0a(1);
        return 1;
      }
      FUN_005e46f0(0);
      *(int *)(*(int *)(param_1 + 0x134) + 0x14) = *piVar5;
      FUN_00510747(*(undefined4 *)(*(int *)(param_1 + 0x104) + iVar4 * 0xc));
      FUN_00510775(*(undefined4 *)(*(int *)(param_1 + 0x110) + iVar4 * 0xc));
      FUN_00510489(0,0);
      if (*(int *)(&DAT_006f4240 + iVar4 * 8) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_0043acf5(*(int *)(&DAT_006f4240 + iVar4 * 8));
      }
      FUN_005103e6(0,uVar2);
      if (*(int *)(&DAT_006f4244 + iVar4 * 8) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_0043acf5(*(int *)(&DAT_006f4244 + iVar4 * 8));
      }
      FUN_005103e6(1,uVar2);
      uVar2 = *(undefined4 *)(param_1 + 0x134);
LAB_005309c5:
      FUN_0050fc6a(uVar2);
      return 1;
    }
    for (piVar5 = *(int **)(param_1 + 0xe8); piVar5 != *(int **)(param_1 + 0xec);
        piVar5 = piVar5 + 1) {
      if (*piVar5 == param_3) {
        if (piVar5 != *(int **)(param_1 + 0xec)) {
          iVar4 = *(int *)(*(int *)(param_1 + 0xf4) + 0x158);
          iVar3 = (int)piVar5 - (int)*(int **)(param_1 + 0xe8) >> 2;
          if (iVar4 == 0) {
            return 1;
          }
          iVar1 = *(int *)(param_1 + 0x134);
          if (iVar1 == 0) {
            return 1;
          }
          if (*(char *)(iVar4 + 0xe0) == '\0') {
            *(int *)(iVar1 + 0x14) = *piVar5;
            FUN_00530bbd(iVar3);
            uVar2 = *(undefined4 *)(param_1 + 0x134);
            goto LAB_00530b2d;
          }
          if (*(int *)(*(int *)(iVar4 + 0x10c) + 0x14) == *piVar5) goto LAB_00530adc;
          if (*(int *)(iVar1 + 0x14) != 0) {
            FUN_005e46f0(0);
          }
          *(int *)(*(int *)(param_1 + 0x134) + 0x14) = *piVar5;
          FUN_00530bbd(iVar3);
          uVar2 = *(undefined4 *)(param_1 + 0x134);
          goto LAB_005309c5;
        }
        break;
      }
    }
    param_2 = 1;
  }
  else if (param_2 == 0x13) {
    GetKeyState(0x10);
    GetKeyState(0x11);
    return 1;
  }
  uVar2 = FUN_005dd97f(param_2,param_3);
  return uVar2;
}

