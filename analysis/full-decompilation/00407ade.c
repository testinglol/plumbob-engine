
int __thiscall FUN_00407ade(int *param_1,uint param_2)

{
  int iVar1;
  
  if (((int)param_2 < 0) || ((uint)(param_1[1] - *param_1 >> 5) <= param_2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 * 0x20 + *param_1;
  }
  return iVar1;
}

