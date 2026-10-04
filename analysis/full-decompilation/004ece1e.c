
undefined4 __thiscall FUN_004ece1e(int *param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  if (param_2 == 1) {
    uVar5 = 0;
    if (param_1[0x3d] - param_1[0x3c] >> 2 != 0) {
      piVar3 = (int *)param_1[0x3c];
      do {
        if (*piVar3 == param_3) {
          if (uVar5 != 0xffffffff) {
            if (param_1[0x47] != uVar5) {
              if (param_1[0x47] != 0xffffffff) {
                FUN_005e46f0(0);
              }
              param_1[0x47] = uVar5;
            }
          }
          break;
        }
        uVar5 = uVar5 + 1;
        piVar3 = piVar3 + 1;
      } while (uVar5 < (uint)(param_1[0x3d] - param_1[0x3c] >> 2));
    }
    local_c = param_1[0x47];
    local_14 = 3;
    local_10 = 0x15;
    puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x18))();
    if ((puVar4 != (undefined4 *)0x0) && (cVar1 = FUN_005da398(puVar4), cVar1 != '\0')) {
      (**(code **)*puVar4)(&local_14);
    }
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_005dd97f(param_2,param_3);
  }
  return uVar2;
}

