
uint __thiscall FUN_0048ffea(char *param_1,char *param_2)

{
  uint uVar1;
  
  uVar1 = FUN_0048f12a();
  if ((char)uVar1 == '\0') {
    if ((((*param_2 < *param_1) || (param_1[3] <= *param_2)) || (param_2[1] < param_1[1])) ||
       (param_1[4] <= param_2[1])) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = uVar1 & 0xffffff00;
  }
  return uVar1;
}

