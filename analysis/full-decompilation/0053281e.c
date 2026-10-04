
undefined4 __thiscall FUN_0053281e(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  if (param_2 == 1) {
    for (piVar3 = *(int **)(param_1 + 0xdc); piVar3 != *(int **)(param_1 + 0xe0);
        piVar3 = piVar3 + 1) {
      if (*piVar3 == param_3) {
        if (piVar3 != *(int **)(param_1 + 0xe0)) {
          param_2 = 0;
          iVar4 = (int)piVar3 - (int)*(int **)(param_1 + 0xdc) >> 2;
          if (0 < (int)(*(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc) & 0xfffffffcU)) {
            do {
              FUN_005e46f0(iVar4 == param_2);
              param_2 = param_2 + 1;
            } while (param_2 < *(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc) >> 2);
          }
          iVar1 = *(int *)(*(int *)(param_1 + 0xe8) + 0x158);
          if ((iVar1 != 0) && (*(int *)(param_1 + 0x110) != 0)) {
            FUN_00503993(s_petskil_006ccd64);
            if (*(char *)(iVar1 + 0xe0) == '\0') {
              *(int *)(*(int *)(param_1 + 0x110) + 0x14) = *piVar3;
              FUN_00510747(*(undefined4 *)(*(int *)(param_1 + 0xf8) + iVar4 * 0xc));
              FUN_00510775(*(undefined4 *)(*(int *)(param_1 + 0x104) + iVar4 * 0xc));
              FUN_00510489(0,0);
              if (*(int *)(&DAT_006f4408 + iVar4 * 8) == 0) {
                uVar2 = 0;
              }
              else {
                uVar2 = FUN_0043acf5(*(int *)(&DAT_006f4408 + iVar4 * 8));
              }
              FUN_005103e6(0,uVar2);
              if (*(int *)(&DAT_006f440c + iVar4 * 8) == 0) {
                uVar2 = 0;
              }
              else {
                uVar2 = FUN_0043acf5(*(int *)(&DAT_006f440c + iVar4 * 8));
              }
              FUN_005103e6(1,uVar2);
              FUN_0050fb20(*(undefined4 *)(param_1 + 0x110),param_1);
            }
            else if (*(int *)(*(int *)(iVar1 + 0x10c) + 0x14) == *piVar3) {
              FUN_0050fc0a(1);
            }
            else {
              FUN_005e46f0(0);
              *(int *)(*(int *)(param_1 + 0x110) + 0x14) = *piVar3;
              FUN_00510747(*(undefined4 *)(*(int *)(param_1 + 0xf8) + iVar4 * 0xc));
              FUN_00510775(*(undefined4 *)(*(int *)(param_1 + 0x104) + iVar4 * 0xc));
              FUN_00510489(0,0);
              if (*(int *)(&DAT_006f4408 + iVar4 * 8) == 0) {
                uVar2 = 0;
              }
              else {
                uVar2 = FUN_0043acf5(*(int *)(&DAT_006f4408 + iVar4 * 8));
              }
              FUN_005103e6(0,uVar2);
              if (*(int *)(&DAT_006f440c + iVar4 * 8) == 0) {
                uVar2 = 0;
              }
              else {
                uVar2 = FUN_0043acf5(*(int *)(&DAT_006f440c + iVar4 * 8));
              }
              FUN_005103e6(1,uVar2);
              FUN_0050fc6a(*(undefined4 *)(param_1 + 0x110));
            }
          }
        }
        break;
      }
    }
    uVar2 = 1;
  }
  else if (param_2 == 0x13) {
    GetKeyState(0x10);
    GetKeyState(0x11);
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_005dd97f(param_2,param_3);
  }
  return uVar2;
}

