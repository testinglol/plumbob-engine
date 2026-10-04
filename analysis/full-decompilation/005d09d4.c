
undefined4 __fastcall FUN_005d09d4(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = param_1 + 1;
  *piVar1 = *piVar1 + -1;
  uVar2 = param_1[1];
  if (*piVar1 == 0) {
    piVar1 = (int *)param_1[3];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    if (param_1 != (undefined4 *)0x0) {
      (**(code **)*param_1)(1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

