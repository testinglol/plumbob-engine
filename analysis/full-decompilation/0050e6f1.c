
void __fastcall FUN_0050e6f1(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    thunk_FUN_005dbf32();
    return;
  }
  (**(code **)(*param_1 + 0x19c))(0,4,1);
  FUN_004cb1a2(0x2a,0x3c);
  FUN_005e4071(DAT_006f2a90);
  param_1[0x3e] = 1;
  param_1[0x3d] = 1;
  FUN_005dd9c8(param_1 + 0x67);
  thunk_FUN_005dbf32();
  return;
}

