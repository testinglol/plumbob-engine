
void __thiscall FUN_0044582f(int param_1,int param_2,int param_3,char param_4)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(int *)(param_1 + 0x24) + -4 + param_2 * 4);
  *puVar1 = *puVar1 & ~(param_3 << 0x10);
  if (param_4 != '\0') {
    puVar1 = (uint *)(*(int *)(param_1 + 0x24) + -4 + param_2 * 4);
    *puVar1 = *puVar1 | param_3 << 0x10;
  }
  return;
}

