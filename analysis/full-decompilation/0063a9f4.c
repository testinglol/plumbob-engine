
uint FUN_0063a9f4(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  
  FUN_0063cedd(param_1);
  piVar1 = param_1 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = FUN_006427ac(param_1);
  }
  else {
    uVar2 = (uint)*(byte *)*param_1;
    *param_1 = (byte *)*param_1 + 1;
  }
  FUN_0063cf2f(param_1);
  return uVar2;
}

