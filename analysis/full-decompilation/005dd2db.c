
void __fastcall FUN_005dd2db(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x184))();
  param_1[0x17] = iVar1;
  if (iVar1 == 0) {
    iVar1 = *param_1;
    while( true ) {
      piVar2 = (int *)(**(code **)(iVar1 + 0x18))();
      if (piVar2 == (int *)0x0) break;
      iVar1 = (**(code **)(*piVar2 + 0x184))();
      if (iVar1 != 0) {
        param_1[0x17] = iVar1;
        break;
      }
      iVar1 = *piVar2;
    }
  }
  (**(code **)(*param_1 + 0x198))();
  return;
}

