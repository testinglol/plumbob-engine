
void __thiscall FUN_004b463f(int param_1,int param_2,uint param_3,char param_4)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 0x58 + param_2 * 4);
  if (param_4 == '\0') {
    *puVar1 = *puVar1 & ~param_3;
  }
  else {
    *puVar1 = *puVar1 | param_3;
  }
  return;
}

