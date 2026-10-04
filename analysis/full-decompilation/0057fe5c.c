
int __fastcall FUN_0057fe5c(int *param_1)

{
  int *piVar1;
  
  piVar1 = param_1 + 5;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    (**(code **)(*param_1 + 0xa8))();
  }
  return param_1[5];
}

