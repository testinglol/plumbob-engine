
undefined4 __fastcall FUN_00457d14(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x1b] == 0) {
    uVar1 = FUN_00456a37(*param_1,0x82);
    param_1[0x1b] = uVar1;
  }
  return param_1[0x1b];
}

