
undefined4 __thiscall FUN_0059ac03(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = param_2;
  cVar2 = FUN_005b9169(*param_1);
  if ((cVar2 != '\0') && (cVar2 = FUN_005b9169(param_1[3]), cVar2 != '\0')) {
    iVar3 = (int)(param_1[8] - param_1[7]) / 0xc;
    cVar2 = FUN_005b90ab(iVar3);
    if (cVar2 != '\0') {
      iVar4 = 0;
      param_2 = 0;
      if (0 < iVar3) {
        do {
          cVar2 = FUN_005b9169(*(undefined4 *)(param_1[7] + iVar4));
          if (cVar2 == '\0') {
            return 0;
          }
          param_2 = param_2 + 1;
          iVar4 = iVar4 + 0xc;
        } while (param_2 < iVar3);
      }
      iVar3 = (int)(param_1[0xe] - param_1[0xd]) / 0xc;
      cVar2 = FUN_005b90ab(iVar3);
      if (cVar2 != '\0') {
        param_2 = 0;
        if (0 < iVar3) {
          do {
            cVar2 = FUN_00599836(uVar1);
            if (cVar2 == '\0') {
              return 0;
            }
            param_2 = param_2 + 1;
          } while (param_2 < iVar3);
        }
        iVar3 = (int)(param_1[0x11] - param_1[0x10]) / 0x18;
        cVar2 = FUN_005b90ab(iVar3);
        if (cVar2 != '\0') {
          param_2 = 0;
          if (0 < iVar3) {
            do {
              cVar2 = FUN_00599915(uVar1);
              if (cVar2 == '\0') {
                return 0;
              }
              param_2 = param_2 + 1;
            } while (param_2 < iVar3);
          }
          iVar3 = (int)(param_1[0x14] - param_1[0x13]) >> 3;
          cVar2 = FUN_005b90ab(iVar3);
          if (cVar2 != '\0') {
            iVar4 = 0;
            if (0 < iVar3) {
              do {
                cVar2 = FUN_0059970d(uVar1);
                if (cVar2 == '\0') {
                  return 0;
                }
                iVar4 = iVar4 + 1;
              } while (iVar4 < iVar3);
            }
            iVar3 = (int)(param_1[0x17] - param_1[0x16]) >> 3;
            cVar2 = FUN_005b90ab(iVar3);
            if (cVar2 != '\0') {
              iVar4 = 0;
              if (0 < iVar3) {
                do {
                  cVar2 = FUN_005996e6(uVar1);
                  if (cVar2 == '\0') {
                    return 0;
                  }
                  iVar4 = iVar4 + 1;
                } while (iVar4 < iVar3);
              }
              iVar3 = (int)(param_1[0x1a] - param_1[0x19]) / 0x18;
              cVar2 = FUN_005b90ab(iVar3);
              if (cVar2 != '\0') {
                param_2 = 0;
                if (0 < iVar3) {
                  do {
                    cVar2 = FUN_005997a8(uVar1);
                    if (cVar2 == '\0') {
                      return 0;
                    }
                    param_2 = param_2 + 1;
                  } while (param_2 < iVar3);
                }
                return 1;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

