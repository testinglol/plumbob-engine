
uint FUN_00628080(int *param_1,int param_2,int param_3)

{
  uint *puVar1;
  
  param_2 = *(int *)(*param_1 + 0x18) * param_2;
  puVar1 = (uint *)(((int)(param_2 + (param_2 >> 0x1f & 7U)) >> 3) + param_1[2] * param_3 +
                   param_1[1]);
  if (*(int *)(*param_1 + 0x18) == 8) {
    return (uint)(byte)*puVar1;
  }
  return *puVar1;
}

