
void FUN_00608704(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  if (0 < DAT_006d95ec) {
    piVar3 = &DAT_006ff2bc;
    do {
      iVar1 = *piVar3;
      if (iVar1 != 0) {
        FUN_006089fb();
        FUN_006321f0(iVar1);
      }
      *piVar3 = 0;
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < DAT_006d95ec);
  }
  DAT_006d95ec = 0;
  return;
}

