
undefined4 __thiscall FUN_005f5687(int *param_1,int param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  if (param_2 == 1) {
    iVar4 = 0;
    if (0 < (int)(param_1[0x36] - param_1[0x35] & 0xfffffffcU)) {
      puVar3 = (undefined4 *)param_1[0x35];
      do {
        if ((int *)*puVar3 == param_3) {
          if (iVar4 != -1) {
            if (param_1[0x3e] != iVar4) {
              if (param_1[0x3e] != -1) {
                FUN_005e46f0(0);
              }
              param_1[0x3e] = iVar4;
              FUN_005e46f0(1);
            }
          }
          break;
        }
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar4 < param_1[0x36] - param_1[0x35] >> 2);
    }
    local_c = param_1[0x3e];
    local_14 = 3;
    local_10 = 0x15;
    puVar3 = (undefined4 *)(**(code **)(*param_1 + 0x18))();
    if (puVar3 == (undefined4 *)0x0) {
      return 1;
    }
    cVar1 = FUN_005da398(puVar3);
    if (cVar1 == '\0') {
      return 1;
    }
    puVar3 = (undefined4 *)*puVar3;
  }
  else {
    if (param_2 == 0xc) {
      if (param_3 == (int *)0x0) {
        return 1;
      }
      if (param_3 != (int *)param_1[0x38]) {
        return 1;
      }
      uVar2 = (**(code **)(*param_3 + 0x19c))();
      FUN_005f57e2(uVar2);
      return 1;
    }
    if (param_2 != 0x1a) {
      uVar2 = FUN_005dd97f(param_2,param_3);
      return uVar2;
    }
    local_c = param_1[0x3e];
    local_14 = 3;
    local_10 = 9;
    puVar3 = (undefined4 *)(**(code **)(*param_1 + 0x18))();
    if (puVar3 == (undefined4 *)0x0) {
      return 1;
    }
    cVar1 = FUN_005da398(puVar3);
    if (cVar1 == '\0') {
      return 1;
    }
    puVar3 = (undefined4 *)*puVar3;
  }
  (*(code *)*puVar3)(&local_14);
  return 1;
}

