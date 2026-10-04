
undefined4 __thiscall FUN_005446d1(int *param_1,int param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  if (param_2 == 1) {
    uVar4 = 0;
    if (param_1[0x37] - param_1[0x36] >> 2 != 0) {
      puVar3 = (undefined4 *)param_1[0x36];
      do {
        if ((int *)*puVar3 == param_3) {
          if (uVar4 != 0xffffffff) {
            if (param_1[0x43] != uVar4) {
              if (param_1[0x43] != 0xffffffff) {
                FUN_005e46f0(0);
              }
              param_1[0x43] = uVar4;
            }
          }
          break;
        }
        uVar4 = uVar4 + 1;
        puVar3 = puVar3 + 1;
      } while (uVar4 < (uint)(param_1[0x37] - param_1[0x36] >> 2));
    }
    local_c = param_1[0x43];
    local_14 = 3;
    local_10 = 0x15;
    puVar3 = (undefined4 *)(**(code **)(*param_1 + 0x18))();
    if ((puVar3 != (undefined4 *)0x0) && (cVar1 = FUN_005da398(puVar3), cVar1 != '\0')) {
      (**(code **)*puVar3)(&local_14);
    }
  }
  else {
    if (param_2 != 0xc) {
      uVar2 = FUN_005dd97f(param_2,param_3);
      return uVar2;
    }
    if ((param_3 != (int *)0x0) && (param_3 == (int *)param_1[0x39])) {
      uVar2 = (**(code **)(*param_3 + 0x19c))();
      FUN_005447cb(uVar2);
    }
  }
  return 1;
}

