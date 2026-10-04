
undefined4 * __thiscall FUN_004619d2(char *param_1,undefined4 *param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  
  cVar1 = *param_1;
  if ((cVar1 < param_1[3]) && (cVar2 = param_1[4], param_1[1] < cVar2)) {
    cVar3 = param_1[2];
    *param_2 = param_1;
    *(char *)(param_2 + 1) = cVar1;
    *(char *)((int)param_2 + 5) = cVar2;
    *(char *)((int)param_2 + 6) = cVar3;
  }
  else {
    FUN_004619b0(param_2);
  }
  return param_2;
}

