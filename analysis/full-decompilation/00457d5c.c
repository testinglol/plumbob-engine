
undefined4 __fastcall FUN_00457d5c(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x1d] == 0) {
    uVar1 = FUN_00456a37(*param_1,0x84);
    param_1[0x1d] = uVar1;
  }
  return param_1[0x1d];
}

