
void __thiscall FUN_004d28b2(int *param_1,undefined4 param_2)

{
  int unaff_ESI;
  int unaff_retaddr;
  
  (**(code **)(*param_1 + 0x90))(0x400,1);
  param_1[0x5e] = unaff_ESI;
  param_1[0x5f] = unaff_retaddr;
  FUN_005dd9c8(param_2);
  param_1[0x2a] = 0;
  param_1[0x29] = 0;
  FUN_005d9e18();
  return;
}

