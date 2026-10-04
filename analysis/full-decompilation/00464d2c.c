
void __thiscall FUN_00464d2c(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)((int)param_1 + 0x12) == '\0') {
    if (*(char *)((int)param_1 + 0x13) != '\0') {
      param_1[8] = 0;
    }
    iVar2 = param_1[3];
    if (iVar2 != 2) {
      if (iVar2 == 0) {
        FUN_0046f8cb(param_1[2] + *param_1);
      }
      else if (iVar2 == 1) {
        FUN_006358b0(param_1[2] + *param_1,param_2[1]);
      }
    }
    iVar2 = (**(code **)*param_2)();
    param_1[2] = param_1[2] + iVar2 + 1;
    if ((param_1[2] & 1U) != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  else {
    param_1[6] = param_1[6] + 1;
    if (param_1[3] != 2) {
      if (param_1[3] == 1) {
        FUN_004704a5(param_1[6],param_2[1],0xffffffff);
      }
      else {
        uVar1 = FUN_004705f2(param_1[6],0xffffffff);
        FUN_0046f8cb(uVar1);
      }
    }
  }
  return;
}

