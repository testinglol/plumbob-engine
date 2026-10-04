
undefined4 FUN_0060902d(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = DAT_006d98b8 + -1;
  if (-1 < iVar1) {
    piVar2 = &DAT_006ff3f8 + iVar1;
    do {
      if (((int *)*piVar2 != (int *)0x0) && (*(int *)*piVar2 <= param_1)) {
        return (&DAT_006ff3f8)[iVar1];
      }
      iVar1 = iVar1 + -1;
      piVar2 = piVar2 + -1;
    } while (-1 < iVar1);
  }
  return DAT_006ff3f8;
}

