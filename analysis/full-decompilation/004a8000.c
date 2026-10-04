
void __thiscall FUN_004a8000(int param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x78);
  *param_2 = *param_2 + *(char *)(param_1 + 0x70);
  param_2[1] = param_2[1] + cVar1;
  return;
}

