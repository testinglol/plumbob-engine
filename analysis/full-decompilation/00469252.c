
undefined4 __thiscall FUN_00469252(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  
  cVar1 = *param_1;
  cVar2 = *param_2;
  if (((cVar1 < cVar2) || ((cVar1 == cVar2 && (param_1[1] < param_2[1])))) ||
     ((cVar1 == cVar2 && ((param_1[1] == param_2[1] && (param_1[2] < param_2[2])))))) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

