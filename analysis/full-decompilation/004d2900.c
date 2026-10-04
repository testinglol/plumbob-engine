
void __thiscall FUN_004d2900(int *param_1,char param_2)

{
  char cVar1;
  
  if ((param_2 == '\0') && (cVar1 = FUN_004d3d05(), cVar1 == '\0')) {
    return;
  }
  (**(code **)(*param_1 + 0x90))(0x400,0);
  FUN_005d9e18();
  param_1[0x5e] = -10000;
  param_1[0x5f] = -10000;
  return;
}

