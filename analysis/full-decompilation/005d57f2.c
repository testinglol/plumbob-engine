
int __fastcall FUN_005d57f2(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0xc))();
  if ((iVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)*param_1)(1);
  }
  return iVar1;
}

