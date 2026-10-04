
undefined4 __fastcall FUN_0053c286(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = param_1 + 0x16;
  *piVar1 = *piVar1 + -1;
  uVar2 = param_1[0x16];
  if (*piVar1 == 0) {
    if (param_1 != (undefined4 *)0x0) {
      (**(code **)*param_1)(1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

