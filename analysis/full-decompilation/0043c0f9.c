
void __thiscall FUN_0043c0f9(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int local_c;
  int iStack_8;
  
  local_c = param_1;
  iStack_8 = param_1;
  if (param_4 < 0x2f) {
    FUN_00464a5e(&param_3,1);
    iVar1 = FUN_0043acf5(param_3);
    if (iVar1 == 0) {
      *param_2 = 0;
    }
    else {
      *param_2 = *(int *)(iVar1 + 0xc);
    }
  }
  else if (*(int *)(param_3 + 0xc) == 0) {
    FUN_00464973(&param_3,1);
    *param_2 = 0;
    if (-1 < (short)param_3) {
      if ((uint)(int)(short)param_3 <
          (uint)(*(int *)(param_1 + 0x1274) - *(int *)(param_1 + 0x1270) >> 2)) {
        FUN_00575b11(&local_c,*(int *)(param_1 + 0x1270) + (short)param_3 * 4);
        if (local_c != 0) {
          *param_2 = *(int *)(*(int *)(local_c + 8) + 0xc);
        }
      }
    }
  }
  else {
    iVar2 = 0;
    iVar1 = *(int *)(*param_2 + 0x10);
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 4);
    }
    param_3 = CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar2 + 0xa4));
    FUN_00464973(&param_3,1);
  }
  return;
}

