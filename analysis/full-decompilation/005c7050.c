
void FUN_005c7050(int *param_1,int *param_2,int param_3,int param_4)

{
  short in_stack_00000020;
  
  for (; (param_1 != param_2 &&
         (((*param_1 != param_3 || (param_1[1] != param_4)) ||
          ((short)param_1[5] != in_stack_00000020)))); param_1 = param_1 + 6) {
  }
  return;
}

