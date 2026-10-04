
void __thiscall
FUN_005dfc7e(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 unaff_retaddr;
  
  (**(code **)(*param_1 + 0x74))(param_5);
  (**(code **)(*param_1 + 0xa4))(unaff_retaddr,param_2,param_3);
  return;
}

