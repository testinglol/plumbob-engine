
int * __thiscall FUN_00633760(int *param_1,undefined1 param_2)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = FUN_006322ac();
  if (iVar2 != 0) {
    iVar2 = FUN_0063268c(param_2);
    if (iVar2 == -1) {
      puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
      *puVar1 = *puVar1 | 6;
    }
    FUN_00632320();
  }
  return param_1;
}

