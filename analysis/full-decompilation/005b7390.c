
void FUN_005b7390(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (DAT_006fd7d8 != 0) {
    FUN_005b6820(DAT_006fd7d8);
    if (((-1 < param_1) && (param_1 < DAT_006fd7d4)) &&
       (puVar1 = (undefined4 *)(DAT_006fd7d0 + param_1 * 0xc),
       *(int *)(DAT_006fd7d0 + param_1 * 0xc) == param_2)) {
      CloseHandle((HANDLE)puVar1[1]);
      *puVar1 = 0;
      puVar1[2] = 0;
      puVar1[1] = 0;
    }
    FUN_005b6830(DAT_006fd7d8);
  }
  return;
}

