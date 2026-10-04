
bool __thiscall FUN_00474276(int param_1,uint param_2)

{
  bool bVar1;
  
  if (((int)param_2 < 0) || ((uint)(*(int *)(param_1 + 500) - *(int *)(param_1 + 0x1f0)) <= param_2)
     ) {
    bVar1 = true;
  }
  else {
    bVar1 = *(char *)(*(int *)(param_1 + 0x1f0) + param_2) != '\0';
  }
  return bVar1;
}

