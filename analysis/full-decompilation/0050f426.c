
void __fastcall FUN_0050f426(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0x19c))(0,4,1);
    FUN_004cff80();
    FUN_004cb1a2(0x7d,0x19);
    param_1[0x3e] = 1;
    param_1[0x3d] = 1;
    FUN_005dd9c8(&DAT_006f3788 + param_1[0x65] * 0xc);
    FUN_005a5631(param_1[0x65] + 0x640,param_1 + 0x68,4);
    if (DAT_006f386c == 0) {
      FUN_005a5631(0x653,&DAT_006f386c,4);
    }
    if (DAT_006f3870 == 0) {
      FUN_005a5631(0x654,&DAT_006f3870,4);
    }
  }
  thunk_FUN_005dbf32();
  return;
}

