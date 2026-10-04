
int * __thiscall FUN_00633175(int *param_1,undefined1 *param_2)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = FUN_006327fb(1);
  if (iVar2 != 0) {
    iVar2 = FUN_00634046();
    if (iVar2 == -1) {
      puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
      *puVar1 = *puVar1 | 3;
    }
    else {
      param_1[2] = param_1[2] + 1;
    }
    *param_2 = (char)iVar2;
    FUN_00632716();
  }
  return param_1;
}

