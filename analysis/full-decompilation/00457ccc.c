
undefined4 __fastcall FUN_00457ccc(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x1a] == 0) {
    uVar1 = FUN_00456a37(*param_1,0x81);
    param_1[0x1a] = uVar1;
  }
  return param_1[0x1a];
}

