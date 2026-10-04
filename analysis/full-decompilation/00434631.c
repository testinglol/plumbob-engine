
int __fastcall FUN_00434631(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_18 = 1000;
  local_8 = -0x80000000;
  if (*(char *)(param_1 + 0x188) != '\0') {
    local_8 = 0x7fffffff;
  }
  local_10 = 0;
  iVar3 = (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1;
  if (0 < iVar3) {
    local_c = 0x24;
    do {
      if ((local_c < 0x24) ||
         ((*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1 <= local_10)) {
        iVar1 = 0;
      }
      else {
        iVar1 = local_c + *(int *)(param_1 + 0x130);
      }
      if (iVar1 == 0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)FUN_00407498((int)*(short *)(iVar1 + 0x10));
      }
      if (piVar2 != (int *)0x0) {
        local_14 = (**(code **)(*piVar2 + 0x18))();
        piVar2 = &local_14;
        if (local_14 <= local_8) {
          piVar2 = &local_8;
        }
        local_8 = *piVar2;
      }
      local_10 = local_10 + 1;
      local_c = local_c + 0x24;
    } while (local_10 < iVar3);
  }
  piVar2 = &local_8;
  if (local_8 < 0x3e9) {
    piVar2 = &local_18;
  }
  return *piVar2;
}

