
void __thiscall FUN_005e84c8(int *param_1,int param_2,int param_3)

{
  int *extraout_ECX;
  
  if ((param_2 == *(int *)(*param_1 + 8)) && (param_3 == *param_1)) {
    FUN_005e81a9();
  }
  else {
    while (param_2 != param_3) {
      FUN_0041674f(param_1);
      FUN_005e858b(param_2);
      param_1 = extraout_ECX;
    }
  }
  return;
}

