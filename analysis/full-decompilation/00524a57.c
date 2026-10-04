
undefined4 __thiscall FUN_00524a57(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00523bbc(param_2);
  if ((iVar1 == 0) || (param_1[0x49] != 0)) {
    uVar2 = 0;
  }
  else {
    param_1[0x48] = param_2;
    param_1[0x47] = 1;
    (**(code **)(*param_1 + 0x118))();
    uVar2 = 1;
  }
  return uVar2;
}

