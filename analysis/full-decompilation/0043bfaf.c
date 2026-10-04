
void __thiscall
FUN_0043bfaf(int param_1,int *param_2,int *param_3,int param_4,undefined4 param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int local_c;
  int iStack_8;
  
  iVar2 = param_4;
  local_c = param_1;
  iStack_8 = param_1;
  if ((param_6 < 0x2f) || ((char)param_5 == '\0')) {
    if ((*(int *)(param_4 + 0xc) == 1) || (*(int *)(param_4 + 0xc) == 2)) {
      param_4 = FUN_0045741b();
    }
    FUN_00464a5e(&param_4,1);
    if (*(int *)(iVar2 + 0xc) == 0) {
      iVar2 = FUN_0043acf5(param_4);
      *param_2 = iVar2;
    }
  }
  else if (*(int *)(param_4 + 0xc) == 0) {
    FUN_00464973(&param_5,1);
    *param_2 = 0;
    if (-1 < (short)param_5) {
      if (((uint)(int)(short)param_5 <
           (uint)(*(int *)(param_1 + 0x1274) - *(int *)(param_1 + 0x1270) >> 2)) &&
         (FUN_00575b11(&local_c,*(int *)(param_1 + 0x1270) + (short)param_5 * 4), local_c != 0)) {
        *param_2 = *(int *)(local_c + 8);
      }
    }
    if ((*param_2 == 0) && (param_3 != (int *)0x0)) {
      *param_3 = 0;
      for (piVar1 = *(int **)(param_1 + 0x1244); piVar1 != *(int **)(param_1 + 0x1248);
          piVar1 = piVar1 + 1) {
        if (*(short *)(*piVar1 + 0x18) == (short)param_5) {
          *param_3 = *piVar1;
          return;
        }
      }
    }
  }
  else {
    param_5 = CONCAT22((short)((uint)*param_2 >> 0x10),*(undefined2 *)(*param_2 + 0xa4));
    FUN_00464973(&param_5,1);
  }
  return;
}

