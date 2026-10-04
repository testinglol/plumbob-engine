
void __thiscall FUN_00434d3d(char *param_1,uint *param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  *param_2 = (int)param_1[1] << 4 | 8;
  param_2[1] = (int)cVar1 << 4 | 8;
  return;
}

