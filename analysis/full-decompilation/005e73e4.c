
undefined4 * __fastcall FUN_005e73e4(undefined4 *param_1)

{
  undefined4 uStack_8;
  
  uStack_8 = param_1;
  FUN_005d5fbc((int)&uStack_8 + 2,(int)&uStack_8 + 3);
  *(undefined1 *)(param_1 + 4) = 0;
  *param_1 = &PTR_FUN_0067435c;
  return param_1;
}

