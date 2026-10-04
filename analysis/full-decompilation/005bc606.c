
undefined4 __fastcall FUN_005bc606(uint *param_1)

{
  uint uVar1;
  uint extraout_EDX;
  int extraout_EDX_00;
  uint extraout_EDX_01;
  int extraout_EDX_02;
  
  FUN_0060c6d0(0x7fffffff);
  if ((((param_1[1] != extraout_EDX) || (uVar1 = FUN_0060c6d0(0x7fffffff), *param_1 <= uVar1)) &&
      (FUN_0060c6d0(0x7fffffff), (int)param_1[1] <= extraout_EDX_00)) &&
     (((FUN_0060c6d0(0x80000000), param_1[1] != extraout_EDX_01 ||
       (uVar1 = FUN_0060c6d0(0x80000000), uVar1 <= *param_1)) &&
      (FUN_0060c6d0(0x80000000), extraout_EDX_02 <= (int)param_1[1])))) {
    return 1;
  }
  return 0;
}

