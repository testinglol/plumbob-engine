
undefined4 __fastcall FUN_00457d80(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x1f] == 0) {
    uVar1 = FUN_00456a37(*param_1,0xa0);
    param_1[0x1f] = uVar1;
  }
  return param_1[0x1f];
}

