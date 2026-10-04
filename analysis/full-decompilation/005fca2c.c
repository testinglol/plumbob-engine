
undefined4 __fastcall FUN_005fca2c(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((char)param_1[0x5f] == '\0') {
    return 0;
  }
  piVar1 = (int *)param_1[0x61];
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x1c))(piVar1), iVar2 < 0)) {
    (**(code **)(*param_1 + 0xc))();
    return 0;
  }
  return 1;
}

