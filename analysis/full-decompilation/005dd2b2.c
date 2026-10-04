
void __thiscall FUN_005dd2b2(int *param_1,undefined4 param_2)

{
  char unaff_SI;
  undefined1 unaff_retaddr;
  
  (**(code **)(*param_1 + 0x90))(0x80000,param_2);
  if (unaff_SI != '\0') {
    *(undefined1 *)(param_1 + 0x2c) = unaff_retaddr;
  }
  return;
}

