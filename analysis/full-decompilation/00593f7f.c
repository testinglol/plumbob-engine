
int * FUN_00593f7f(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 local_208 [256];
  char local_108 [256];
  int local_8;
  
  piVar1 = param_1;
  local_8 = 0;
  FUN_006326ae(&local_8);
  param_1 = (int *)0x0;
  if (0 < local_8) {
    do {
      do {
        FUN_00594033(local_108,0x100,10);
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
      } while (local_108[0] == '\0');
      FUN_00594033(local_208,0x100,10);
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
      FUN_00594331(local_108,local_208);
      param_1 = (int *)((int)param_1 + 1);
    } while ((int)param_1 < local_8);
  }
  return piVar1;
}

