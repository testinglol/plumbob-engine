
int __fastcall FUN_005c184f(int param_1)

{
  undefined4 uStack_8;
  
  uStack_8 = param_1;
  FUN_0057be3a((int)&uStack_8 + 2,(int)&uStack_8 + 3);
  *(undefined4 *)(param_1 + 0xc) = 0;
  return param_1;
}

