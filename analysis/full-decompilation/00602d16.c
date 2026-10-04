
void __thiscall FUN_00602d16(int *param_1,int param_2,int param_3)

{
  int *extraout_ECX;
  
  if ((param_2 == *(int *)(*param_1 + 8)) && (param_3 == *param_1)) {
    FUN_006029c8();
  }
  else {
    while (param_2 != param_3) {
      FUN_0041674f(param_1);
      FUN_00602dd7(param_2);
      param_1 = extraout_ECX;
    }
  }
  return;
}

