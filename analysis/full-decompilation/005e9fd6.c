
void __thiscall FUN_005e9fd6(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0xc))(4,param_2);
  if (param_1[-0x1f] != 0) {
    iVar1 = FUN_005dd5e1(0xff,0,0xff);
    param_1[9] = iVar1;
    (**(code **)(*(int *)param_1[-0x1f] + 0x68))(iVar1);
  }
  return;
}

