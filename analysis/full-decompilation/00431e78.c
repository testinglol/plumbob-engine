
void __thiscall FUN_00431e78(int param_1,int param_2,uint param_3)

{
  uint *puVar1;
  
  *(undefined2 *)(param_2 * 4 + -4 + *(int *)(param_1 + 0x24)) = 0;
  puVar1 = (uint *)(param_2 * 4 + -4 + *(int *)(param_1 + 0x24));
  *puVar1 = *puVar1 | param_3 & 0xffff;
  return;
}

