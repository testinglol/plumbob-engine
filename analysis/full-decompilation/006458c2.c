
undefined4 FUN_006458c2(uint param_1,HANDLE param_2)

{
  undefined4 *puVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_00704100) {
    iVar2 = (param_1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_00704000)[(int)param_1 >> 5] + iVar2) == -1) {
      if (DAT_006daae4 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_0064591b;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_0064591b:
      *(HANDLE *)((&DAT_00704000)[(int)param_1 >> 5] + iVar2) = param_2;
      return 0;
    }
  }
  puVar1 = (undefined4 *)FUN_0063d796();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_0063d79f();
  *puVar1 = 0;
  return 0xffffffff;
}

