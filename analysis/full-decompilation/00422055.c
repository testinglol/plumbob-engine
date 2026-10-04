
void __thiscall FUN_00422055(int *param_1,int param_2,int param_3)

{
  uint *puVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  puVar1 = (uint *)(param_1 + 1);
  *puVar1 = param_1[1] & 0xfU | param_2 << 4;
  *puVar1 = *puVar1 & 0xfffffff0;
  *param_1 = param_3 << 4;
  return;
}

