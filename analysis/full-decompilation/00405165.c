
int __thiscall FUN_00405165(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == -1) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004ea79e(param_2);
    iVar2 = (int)*(short *)(iVar2 + 0xa2);
  }
  iVar1 = FUN_004ea79e(param_2);
  if (((0xb < iVar2) || (iVar2 < 0)) ||
     (iVar2 = *(int *)(*(int *)(param_1 + (param_3 * 3 + 6) * 4) + iVar2 * 4),
     iVar2 * 100 <= (int)*(short *)(iVar1 + (&DAT_00666538)[param_3] * 2))) {
    iVar2 = 0;
  }
  return iVar2;
}

