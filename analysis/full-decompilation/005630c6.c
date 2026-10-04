
void __thiscall FUN_005630c6(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1[0x65];
  if (param_2 < 0) {
    param_1[0x65] = 0;
  }
  else if (param_2 < 0xb) {
    param_1[0x65] = param_2;
  }
  else {
    param_1[0x65] = 10;
  }
  if (param_1[0x65] != iVar1) {
    (**(code **)(*param_1 + 0x168))();
  }
  return;
}

