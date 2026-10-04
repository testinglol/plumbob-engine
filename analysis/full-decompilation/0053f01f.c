
undefined4 __thiscall FUN_0053f01f(char *param_1,char *param_2)

{
  undefined4 uVar1;
  
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) &&
      (*(short *)(param_1 + 2) == *(short *)(param_2 + 2))) &&
     (*(short *)(param_1 + 4) == *(short *)(param_2 + 4))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

