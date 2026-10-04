
void FUN_005d5f13(void)

{
  int iVar1;
  
  if (DAT_006fe8bc != (int *)0x0) {
    (**(code **)(*DAT_006fe8bc + 0x30))();
    if (DAT_006feb18 != (code *)0x0) {
      iVar1 = (**(code **)*DAT_006fe8bc)();
      (*DAT_006feb18)(-(uint)(iVar1 != 0) & iVar1 - 0x48U);
    }
    FUN_0060487e(DAT_006fe8bc);
    DAT_006fe8bc = (int *)0x0;
  }
  return;
}

