
undefined4 __thiscall FUN_005063ab(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 1) {
    iVar3 = 0;
    iVar4 = 0;
    piVar2 = (int *)(param_1 + 0xe4);
    do {
      if (param_3 == *piVar2) {
        if (iVar4 == 0) {
          iVar4 = FUN_005f65c1();
          iVar4 = iVar4 + -1;
        }
        else {
          if (iVar4 != 1) {
            return 1;
          }
          iVar4 = FUN_005f65c1();
          iVar4 = iVar4 + 1;
        }
        FUN_004cf9de(iVar4);
        return 1;
      }
      iVar4 = iVar4 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar4 < 2);
    if (param_3 == *(int *)(param_1 + 0x1cc)) {
      if (*(int *)(*(int *)(param_1 + 0xd4) + 0xa4) == 1) {
        FUN_004cf567(0);
        param_3 = 0;
LAB_00506629:
        FUN_005070f3(param_3);
      }
    }
    else {
      iVar4 = 0;
      piVar2 = (int *)(param_1 + 0x400);
      do {
        if (param_3 == *piVar2) {
          iVar3 = *(int *)(*(int *)(param_1 + 0xd4) + 0xa4);
          if (iVar3 == 0) {
            FUN_004cf567(1);
            iVar3 = *(int *)(*(int *)(param_1 + 0xd4) + 0xa0);
            if (iVar3 == 0) {
              FUN_004cf62b(iVar4);
              FUN_004cf663(0);
            }
            else if (iVar3 == 1) {
              FUN_004cf6ae(iVar4);
              FUN_004cf6e6(0);
            }
            else if (iVar3 == 2) {
              FUN_004cf731(iVar4);
              FUN_004cf849(0);
            }
            else if (iVar3 == 3) {
              FUN_004cf769(iVar4);
              FUN_004cf894(0);
            }
            else if (iVar3 == 4) {
              FUN_004cf7a1(iVar4);
              FUN_004cf8df(0);
            }
            else if (iVar3 == 5) {
              FUN_004cf7d9(iVar4);
              FUN_004cf92a(0);
            }
            else if (iVar3 == 6) {
              FUN_004cf811(iVar4);
              FUN_004cf975(0);
            }
            param_3 = *(int *)(param_1 + 0x400);
          }
          else if (iVar3 == 1) {
            iVar3 = *(int *)(*(int *)(param_1 + 0xd4) + 0xa0);
            if (iVar3 == 0) {
              FUN_004cf663(iVar4);
            }
            else if (iVar3 == 1) {
              FUN_004cf6e6(iVar4);
            }
            else if (iVar3 == 2) {
              FUN_004cf849(iVar4);
            }
            else if (iVar3 == 3) {
              FUN_004cf894(iVar4);
            }
            else if (iVar3 == 4) {
              FUN_004cf8df(iVar4);
            }
            else if (iVar3 == 5) {
              FUN_004cf92a(iVar4);
            }
            else if (iVar3 == 6) {
              FUN_004cf975(iVar4);
            }
          }
          goto LAB_00506629;
        }
        iVar4 = iVar4 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar4 < 8);
      param_2 = 0;
      iVar4 = *(int *)(param_1 + 0x424) - *(int *)(param_1 + 0x420) >> 2;
      if (0 < iVar4) {
        do {
          param_2 = *(undefined4 *)(*(int *)(param_1 + 0x420) + iVar3 * 4);
          iVar1 = FUN_00492d2c();
          if (param_3 == iVar1) break;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar4);
      }
      FUN_00506635(param_2);
    }
  }
  else if ((param_2 == 0x13) && (*(int *)(param_1 + 0x42c) != 0)) {
    param_2 = 0;
    iVar4 = *(int *)(param_1 + 0x424) - *(int *)(param_1 + 0x420) >> 2;
    if (0 < iVar4) {
      do {
        iVar3 = *(int *)(*(int *)(param_1 + 0x420) + param_2 * 4);
        if ((iVar3 != 0) && (iVar1 = FUN_00492d2c(), param_3 == iVar1)) {
          FUN_005083f4(iVar3,param_1);
        }
        param_2 = param_2 + 1;
      } while (param_2 < iVar4);
    }
  }
  return 1;
}

