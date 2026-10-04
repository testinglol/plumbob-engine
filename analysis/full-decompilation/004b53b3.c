
void __thiscall FUN_004b53b3(char *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_004aeea6();
  if (iVar1 == 1) {
    if ((*param_1 == param_2) && (param_1[1] == param_3)) {
      builtin_strncpy(param_1,"\x7f\x7f\x7f\x7f",4);
    }
  }
  else if (iVar1 == 2) {
    if ((*param_1 == param_2) && (param_1[1] == param_3)) {
      *param_1 = param_1[2];
      param_1[1] = param_1[3];
    }
    else {
      if (param_1[2] != param_2) {
        return;
      }
      if (param_1[3] != param_3) {
        return;
      }
    }
    param_1[3] = '\x7f';
    param_1[2] = '\x7f';
  }
  return;
}

