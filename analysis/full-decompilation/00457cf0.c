
undefined4 __fastcall FUN_00457cf0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x1e] == 0) {
    uVar1 = FUN_00456a37(*param_1,0x96);
    param_1[0x1e] = uVar1;
  }
  return param_1[0x1e];
}

