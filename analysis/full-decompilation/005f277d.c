
undefined4 __thiscall FUN_005f277d(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_8;
  
  uVar2 = param_3 >> 1;
  local_8 = param_3 & 1;
  if (param_2 < 0x25) {
    if (param_2 != 0x24) {
      if (param_2 == 8) {
        uVar5 = 0xffffffff;
LAB_005f2926:
        FUN_005f3419(uVar5);
        return 1;
      }
      if (param_2 == 9) {
        iVar4 = *(int *)(param_1 + 0x48);
        if (iVar4 == 0) {
          return 1;
        }
        uVar5 = 0x19;
      }
      else {
        if (param_2 != 0x1b) {
          if (param_2 == 0x21) {
            if ((uVar2 & 1) == 0) {
              uVar5 = 0xffffffff;
LAB_005f285f:
              FUN_005f36c3(uVar5,local_8);
              return 1;
            }
            if ((param_3 & 1) != 0) {
              return 1;
            }
            iVar4 = *(int *)(param_1 + 300) - *(int *)(param_1 + 0x130);
          }
          else {
            if (param_2 != 0x22) {
              if (param_2 != 0x23) goto LAB_005f2914;
              if ((uVar2 & 1) == 0) {
                piVar1 = *(int **)(*(int *)(param_1 + 0xf0) + *(int *)(param_1 + 0xd8) * 4);
                iVar4 = (*piVar1 - *(int *)(param_1 + 0xd4)) + piVar1[1];
                if ((*(char *)((int)piVar1 + 0x21) != '\0') || ((char)piVar1[8] != '\0')) {
                  iVar3 = FUN_005f2b22(*piVar1 + piVar1[1],0xffffffff);
                  iVar4 = iVar4 + iVar3;
                }
                uVar5 = 0;
              }
              else {
                uVar5 = 0;
                iVar4 = ((*(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0xd4)) -
                        *(int *)(param_1 + 0xe4)) + -1;
              }
              goto LAB_005f29b6;
            }
            if ((uVar2 & 1) == 0) {
              uVar5 = 1;
              goto LAB_005f285f;
            }
            if ((param_3 & 1) != 0) {
              return 1;
            }
            iVar4 = *(int *)(param_1 + 0x130) + *(int *)(param_1 + 300);
          }
          goto LAB_005f2994;
        }
        iVar4 = *(int *)(param_1 + 0x48);
        if (iVar4 == 0) {
          return 1;
        }
        uVar5 = 0x18;
      }
      FUN_005da644(iVar4,3,uVar5,param_1,0);
      return 1;
    }
    uVar5 = 0;
    if ((uVar2 & 1) == 0) {
      iVar4 = **(int **)(*(int *)(param_1 + 0xf0) + *(int *)(param_1 + 0xd8) * 4) -
              *(int *)(param_1 + 0xd4);
    }
    else {
      iVar4 = -*(int *)(param_1 + 0xd4);
    }
  }
  else {
    if (param_2 != 0x25) {
      if (param_2 == 0x26) {
        if ((uVar2 & 1) == 0) {
          uVar5 = 0xffffffff;
LAB_005f2964:
          FUN_005f358e(uVar5,local_8);
          return 1;
        }
        if ((param_3 & 1) != 0) {
          return 1;
        }
        iVar4 = *(int *)(param_1 + 300) + -1;
      }
      else {
        if (param_2 == 0x27) {
          if ((uVar2 & 1) != 0) {
            uVar5 = 1;
            goto LAB_005f2975;
          }
          uVar5 = 1;
          iVar4 = 1;
          goto LAB_005f29b6;
        }
        if (param_2 != 0x28) {
          if (param_2 == 0x2d) {
            if (*(int *)(param_1 + 0x13c) == 0) {
              *(undefined4 *)(param_1 + 0x13c) = 1;
              return 1;
            }
            if (*(int *)(param_1 + 0x13c) != 1) {
              return 1;
            }
            *(undefined4 *)(param_1 + 0x13c) = 0;
            return 1;
          }
          if (param_2 != 0x2e) {
LAB_005f2914:
            uVar5 = FUN_005dd72f(param_2,param_3);
            return uVar5;
          }
          uVar5 = 0;
          goto LAB_005f2926;
        }
        if ((uVar2 & 1) == 0) {
          uVar5 = 1;
          goto LAB_005f2964;
        }
        if ((param_3 & 1) != 0) {
          return 1;
        }
        iVar4 = *(int *)(param_1 + 300) + 1;
      }
LAB_005f2994:
      FUN_005f398c(iVar4);
      return 1;
    }
    if ((uVar2 & 1) != 0) {
      uVar5 = 0xffffffff;
LAB_005f2975:
      FUN_005f2f2d(uVar5,local_8);
      return 1;
    }
    uVar5 = 1;
    iVar4 = -1;
  }
LAB_005f29b6:
  FUN_005f2c6c(iVar4,local_8,uVar5);
  return 1;
}

