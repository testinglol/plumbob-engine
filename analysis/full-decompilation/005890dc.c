
uint FUN_005890dc(undefined4 param_1,int param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int local_1c;
  int local_c;
  
  uVar4 = 0;
  if ((*(char *)(param_2 + 2) == '\0') && (cVar1 = FUN_004790bc(param_2), cVar1 != '\0')) {
    return 10;
  }
  FUN_0043f371(*DAT_006e486c,param_2,0);
  if (local_c != 0) {
    do {
      FUN_0043270d(local_c);
      if (local_1c == 0) {
        iVar3 = FUN_0045741b();
        if (iVar3 < 100000000) {
          if (iVar3 == 99999999) {
            if (uVar4 < 9) {
              uVar4 = 9;
            }
          }
          else {
            if (iVar3 != -0x691cc673) {
              if (iVar3 == -0x641fcf47) goto LAB_005891b8;
              if (iVar3 != -0x5d255f74) {
                if (iVar3 == -0x409d09ad) goto LAB_0058919d;
                if (iVar3 != -0x3fd4bf96) goto LAB_005891c0;
              }
            }
LAB_005891a6:
            if (uVar4 < 6) {
              uVar4 = 6;
            }
          }
        }
        else if ((iVar3 == 0x3e7470f6) || (iVar3 == 0x5c67fc8f)) {
LAB_005891b8:
          if (uVar4 < 10) {
            uVar4 = 10;
          }
        }
        else if (iVar3 == 0x63416ba1) {
          if (uVar4 < 8) {
            uVar4 = 8;
          }
        }
        else {
          if (iVar3 == 0x65274a4f) goto LAB_005891a6;
          if (iVar3 == 0x7f907075) {
LAB_0058919d:
            if (uVar4 < 7) {
              uVar4 = 7;
            }
          }
        }
      }
LAB_005891c0:
      FUN_0043f3b9();
    } while (local_c != 0);
    if (uVar4 != 0) {
      return uVar4;
    }
  }
  cVar1 = FUN_00479115(param_2);
  cVar2 = FUN_004790e8(param_2);
  if (cVar1 == '\0') {
    if (cVar2 == '\0') {
      iVar3 = FUN_00433166(param_2);
      if (iVar3 == 0) {
        return 0;
      }
      if (iVar3 != 0xff) {
        iVar3 = FUN_004a1609(iVar3);
        if (iVar3 == 0) {
          return 3;
        }
        if (iVar3 != 1) {
          if (iVar3 == 2) {
            return 4;
          }
          if (iVar3 == 3) {
            return 1;
          }
          return 0;
        }
      }
      return 2;
    }
  }
  else if (cVar2 == '\0') {
    return 1;
  }
  return 0xb;
}

