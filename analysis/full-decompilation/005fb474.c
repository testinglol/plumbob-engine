
undefined4 __fastcall FUN_005fb474(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = param_1 + 1;
  *piVar1 = *piVar1 + -1;
  uVar2 = param_1[1];
  if (*piVar1 == 0) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = &PTR_FUN_006765e0;
      FUN_005fb508();
      FUN_006321f0(param_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

