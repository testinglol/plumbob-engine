
void __thiscall FUN_00436feb(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x18))();
  while (iVar1 != 0) {
    *param_2 = *param_2 + param_1[0x1f];
    *param_3 = *param_3 + param_1[0x20];
    param_1 = (int *)(**(code **)(*param_1 + 0x18))();
    iVar1 = (**(code **)(*param_1 + 0x18))();
  }
  return;
}

