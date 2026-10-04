
void __fastcall FUN_00401634(int *param_1)

{
  int iVar1;
  
  while (iVar1 = *param_1, iVar1 != 0) {
    *param_1 = *(int *)(iVar1 + 4);
    FUN_006321f0(iVar1);
    *(short *)(param_1 + 1) = (short)param_1[1] + -1;
  }
  return;
}

