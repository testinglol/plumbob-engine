
int __fastcall FUN_005f8352(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 0x33;
  *piVar1 = *piVar1 + -1;
  iVar2 = param_1[0x33];
  if (*piVar1 == 0) {
    (**(code **)(*param_1 + 0xc))();
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0xcc))(1);
    }
    iVar2 = 0;
  }
  return iVar2;
}

