
bool FUN_004d26ba(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = param_3;
  piVar1 = param_2;
  if (param_1 != 0) {
    FUN_00436feb(param_2,param_3);
    param_3 = (int *)0x0;
    param_2 = (int *)0x0;
    FUN_00436feb(&param_3,&param_2);
    *piVar1 = *piVar1 - (int)param_3;
    *piVar2 = *piVar2 - (int)param_2;
  }
  return param_1 != 0;
}

