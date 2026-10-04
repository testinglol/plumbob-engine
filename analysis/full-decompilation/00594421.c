
int * FUN_00594421(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c;
  int local_8;
  
  piVar1 = param_1;
  local_8 = 0;
  FUN_006326ae(&local_8);
  if (param_1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*param_1 + 4) + (int)param_1;
  }
  if ((((*(byte *)(iVar2 + 8) & 6) == 0) && (iVar2 != 0)) && (param_1 = (int *)0x0, 0 < local_8)) {
    do {
      puVar3 = operator_new(0x10);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        puVar3[3] = 0;
      }
      FUN_006326ae(&local_c);
      FUN_00593f7f(piVar1,puVar3);
      if (piVar1 == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
      }
      if ((*(byte *)(iVar2 + 8) & 6) != 0) {
        return piVar1;
      }
      if (iVar2 == 0) {
        return piVar1;
      }
      FUN_00594713(local_c,puVar3);
      param_1 = (int *)((int)param_1 + 1);
    } while ((int)param_1 < local_8);
  }
  return piVar1;
}

