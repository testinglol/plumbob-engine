
undefined4 __fastcall FUN_00485b4c(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = param_1 + 2;
  *piVar1 = *piVar1 + -1;
  uVar2 = param_1[2];
  if (*piVar1 == 0) {
    if (param_1 != (undefined4 *)0x0) {
      (**(code **)*param_1)(1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

