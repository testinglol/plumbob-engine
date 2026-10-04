
undefined4 __fastcall FUN_00457d38(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x1c] == 0) {
    uVar1 = FUN_00456a37(*param_1,0x83);
    param_1[0x1c] = uVar1;
  }
  return param_1[0x1c];
}

