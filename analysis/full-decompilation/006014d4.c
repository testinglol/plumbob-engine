
void __thiscall FUN_006014d4(int *param_1,int param_2,int param_3)

{
  int *extraout_ECX;
  
  if ((param_2 == *(int *)(*param_1 + 8)) && (param_3 == *param_1)) {
    FUN_00601344();
  }
  else {
    while (param_2 != param_3) {
      FUN_0041674f(param_1);
      FUN_006015af(param_2);
      param_1 = extraout_ECX;
    }
  }
  return;
}

